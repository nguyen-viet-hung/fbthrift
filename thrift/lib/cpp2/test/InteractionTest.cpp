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

#include <memory>

#include <folly/portability/GMock.h>
#include <folly/portability/GTest.h>
#include <thrift/lib/cpp2/async/RocketClientChannel.h>
#include <thrift/lib/cpp2/test/gen-cpp2/HandlerGeneric.h>
#include <thrift/lib/cpp2/util/ScopedServerInterfaceThread.h>

using namespace ::testing;
using namespace apache::thrift;
using namespace apache::thrift::test;

struct Handler : HandlerGenericSvIf {
  void get_string(std::string& out) override {
    if (auto interaction = getConnectionContext()->getInteractionId()) {
      out = std::to_string(interaction);
      if (auto create = getConnectionContext()->getInteractionCreate()) {
        out += *create->interactionName_ref();
      }
    } else {
      out = "";
    }
  }
};

TEST(InteractionTest, NoIDPropagated) {
  ScopedServerInterfaceThread runner{std::make_shared<Handler>()};
  folly::EventBase eb;
  HandlerGenericAsyncClient client(
      RocketClientChannel::newChannel(folly::AsyncSocket::UniquePtr(
          new folly::AsyncSocket(&eb, runner.getAddress()))));

  RpcOptions rpcOpts;
  std::string out;
  client.sync_get_string(rpcOpts, out);
  EXPECT_EQ(out, "");
}

TEST(InteractionTest, IDPropagated) {
  ScopedServerInterfaceThread runner{std::make_shared<Handler>()};
  folly::EventBase eb;
  HandlerGenericAsyncClient client(
      RocketClientChannel::newChannel(folly::AsyncSocket::UniquePtr(
          new folly::AsyncSocket(&eb, runner.getAddress()))));

  RpcOptions rpcOpts;
  rpcOpts.setExistingInteraction(42);
  std::string out;
  client.sync_get_string(rpcOpts, out);
  EXPECT_EQ(out, "42");
}

TEST(InteractionTest, CreatePropagated) {
  ScopedServerInterfaceThread runner{std::make_shared<Handler>()};
  folly::EventBase eb;
  HandlerGenericAsyncClient client(
      RocketClientChannel::newChannel(folly::AsyncSocket::UniquePtr(
          new folly::AsyncSocket(&eb, runner.getAddress()))));

  RpcOptions rpcOpts;
  rpcOpts.setNewInteraction("Transaction", 42);
  std::string out;
  client.sync_get_string(rpcOpts, out);
  EXPECT_EQ(out, "42Transaction");
}

TEST(InteractionTest, Terminate) {
  ScopedServerInterfaceThread runner{std::make_shared<Handler>()};
  folly::EventBase eb;
  HandlerGenericAsyncClient client(
      RocketClientChannel::newChannel(folly::AsyncSocket::UniquePtr(
          new folly::AsyncSocket(&eb, runner.getAddress()))));

  RpcOptions rpcOpts;
  rpcOpts.setNewInteraction("Transaction", 42);
  std::string out;
  client.sync_get_string(rpcOpts, out);

  eb.runInEventBaseThread(
      [channel = client.getChannelShared(), ka = folly::getKeepAliveToken(eb)] {
        channel->terminateInteraction(42);
      });
}

TEST(InteractionTest, TerminatePRC) {
  ScopedServerInterfaceThread runner{std::make_shared<Handler>()};
  auto client =
      runner.newClient<HandlerGenericAsyncClient>(nullptr, [](auto socket) {
        return RocketClientChannel::newChannel(std::move(socket));
      });

  RpcOptions rpcOpts;
  auto id = client->getChannel()->getNextInteractionId();
  rpcOpts.setExistingInteraction(id);
  std::string out;
  client->sync_get_string(rpcOpts, out);
  EXPECT_EQ(out, std::to_string(id));

  client->getChannel()->terminateInteraction(id);
}
