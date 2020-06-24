/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <thrift/lib/cpp2/transport/rocket/server/RocketSinkClientCallback.h>

#include <functional>
#include <memory>
#include <utility>

#include <glog/logging.h>

#include <folly/ExceptionWrapper.h>
#include <folly/Range.h>
#include <folly/ScopeGuard.h>
#include <folly/io/IOBufQueue.h>
#include <folly/io/async/EventBase.h>

#include <thrift/lib/cpp/TApplicationException.h>
#include <thrift/lib/cpp2/async/StreamCallbacks.h>
#include <thrift/lib/cpp2/protocol/CompactProtocol.h>
#include <thrift/lib/cpp2/protocol/Serializer.h>
#include <thrift/lib/cpp2/transport/rocket/PayloadUtils.h>
#include <thrift/lib/cpp2/transport/rocket/RocketException.h>
#include <thrift/lib/cpp2/transport/rocket/Types.h>
#include <thrift/lib/cpp2/transport/rocket/framing/ErrorCode.h>
#include <thrift/lib/cpp2/transport/rocket/framing/Flags.h>

namespace apache {
namespace thrift {
namespace rocket {

// RocketSinkClientCallback methods
RocketSinkClientCallback::RocketSinkClientCallback(
    StreamId streamId,
    RocketServerConnection& connection)
    : streamId_(streamId), connection_(connection) {}

bool RocketSinkClientCallback::onFirstResponse(
    FirstResponsePayload&& firstResponse,
    folly::EventBase* /* unused */,
    SinkServerCallback* serverCallback) {
  if (UNLIKELY(serverCallbackOrError_ == kErrorFlag)) {
    serverCallback->onSinkError(TApplicationException(
        TApplicationException::TApplicationExceptionType::INTERRUPTION));
    firstResponse.payload.reset();
    connection_.freeStream(streamId_, true);
    return false;
  }

  serverCallbackOrError_ = reinterpret_cast<intptr_t>(serverCallback);

  connection_.sendPayload(
      streamId_, pack(std::move(firstResponse)), Flags::none().next(true));
  return true;
}

void RocketSinkClientCallback::onFirstResponseError(
    folly::exception_wrapper ew) {
  bool isEncodedError = ew.with_exception<RocketException>([&](auto& ex) {
    connection_.sendError(streamId_, std::move(ex));
  }) ||
      ew.with_exception<thrift::detail::EncodedFirstResponseError>(
          [&](auto& encodedError) {
            DCHECK(encodedError.encoded.payload);
            connection_.sendPayload(
                streamId_,
                pack(std::move(encodedError.encoded)),
                Flags::none().next(true).complete(true));
          });
  DCHECK(isEncodedError);

  // In case of a first response error ThriftServerRequestSink is responsible
  // for marking the request as complete (required for task timeout support).
  connection_.freeStream(streamId_, false);
}

void RocketSinkClientCallback::onFinalResponse(StreamPayload&& finalResponse) {
  DCHECK(state_ == State::BothOpen || state_ == State::StreamOpen);

  // apply compression if client has specified compression codec
  if (compressionConfig_) {
    detail::setCompressionCodec(
        *compressionConfig_,
        finalResponse.metadata,
        finalResponse.payload->computeChainDataLength());
  }

  connection_.sendPayload(
      streamId_,
      pack(std::move(finalResponse)),
      Flags::none().next(true).complete(true));
  auto state = state_;
  auto& connection = connection_;
  connection_.freeStream(streamId_, true);
  if (state == State::StreamOpen) {
    connection.decInflightFinalResponse();
  }
}

void RocketSinkClientCallback::onFinalResponseError(
    folly::exception_wrapper ew) {
  DCHECK(state_ == State::BothOpen || state_ == State::StreamOpen);
  if (state_ == State::StreamOpen) {
    connection_.decInflightFinalResponse();
  }
  ew.handle(
      [this](RocketException& rex) {
        connection_.sendError(
            streamId_,
            RocketException(ErrorCode::APPLICATION_ERROR, rex.moveErrorData()));
      },
      [&](...) {
        connection_.sendError(
            streamId_,
            RocketException(ErrorCode::APPLICATION_ERROR, ew.what()));
      });
  connection_.freeStream(streamId_, true);
}

bool RocketSinkClientCallback::onSinkRequestN(uint64_t n) {
  if (timeout_) {
    timeout_->incCredits(n);
  }
  DCHECK(state_ == State::BothOpen);
  connection_.sendRequestN(streamId_, n);
  return true;
}

bool RocketSinkClientCallback::onSinkNext(StreamPayload&& payload) {
  if (state_ != State::BothOpen) {
    cancelTimeout();
    return false;
  }

  if (timeout_) {
    timeout_->decCredits();
  }

  return serverCallback()->onSinkNext(std::move(payload));
}

bool RocketSinkClientCallback::onSinkError(folly::exception_wrapper ew) {
  cancelTimeout();
  if (state_ != State::BothOpen) {
    return false;
  }
  serverCallback()->onSinkError(std::move(ew));
  return true;
}

bool RocketSinkClientCallback::onSinkComplete() {
  cancelTimeout();
  if (state_ != State::BothOpen) {
    return false;
  }
  state_ = State::StreamOpen;
  connection_.incInflightFinalResponse();
  return serverCallback()->onSinkComplete();
}

void RocketSinkClientCallback::onStreamCancel() {
  serverCallback()->onStreamCancel();
}

void RocketSinkClientCallback::setChunkTimeout(
    std::chrono::milliseconds timeout) {
  if (timeout != std::chrono::milliseconds::zero()) {
    timeout_ = std::make_unique<TimeoutCallback>(*this, timeout);
  }
}

void RocketSinkClientCallback::timeoutExpired() noexcept {
  auto ex = TApplicationException(
      TApplicationException::TApplicationExceptionType::TIMEOUT,
      "Sink chunk timeout");
  onSinkError(folly::make_exception_wrapper<TApplicationException>(ex));
  onFinalResponseError(folly::make_exception_wrapper<rocket::RocketException>(
      rocket::ErrorCode::APPLICATION_ERROR,
      serializeErrorStruct(protoId_, ex)));
}

void RocketSinkClientCallback::setProtoId(protocol::PROTOCOL_TYPES protoId) {
  protoId_ = protoId;
}

void RocketSinkClientCallback::setCompressionConfig(
    CompressionConfig compressionConfig) {
  compressionConfig_ = std::make_unique<CompressionConfig>(compressionConfig);
}

void RocketSinkClientCallback::scheduleTimeout(
    std::chrono::milliseconds chunkTimeout) {
  if (timeout_) {
    connection_.scheduleSinkTimeout(timeout_.get(), chunkTimeout);
  }
}

void RocketSinkClientCallback::cancelTimeout() {
  if (timeout_) {
    timeout_->cancelTimeout();
  }
}

void RocketSinkClientCallback::TimeoutCallback::incCredits(uint64_t n) {
  if (credits_ == 0) {
    parent_.scheduleTimeout(chunkTimeout_);
  }
  credits_ += n;
}

void RocketSinkClientCallback::TimeoutCallback::decCredits() {
  DCHECK(credits_ != 0);
  if (--credits_ != 0) {
    parent_.scheduleTimeout(chunkTimeout_);
  } else {
    parent_.cancelTimeout();
  }
}

} // namespace rocket
} // namespace thrift
} // namespace apache
