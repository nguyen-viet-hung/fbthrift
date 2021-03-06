<?php
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
 *
 * @package thrift
 */

require_once ($GLOBALS["HACKLIB_ROOT"]);
if (!isset($GLOBALS['THRIFT_ROOT'])) {
  $GLOBALS['THRIFT_ROOT'] = __DIR__;
}
require_once $GLOBALS['THRIFT_ROOT'].'/TException.php';
require_once $GLOBALS['THRIFT_ROOT'].'/TType.php';
class TApplicationException extends TException {
  static
    $_TSPEC = array(
      1 => array("var" => "message", "type" => TType::STRING),
      2 => array("var" => "code", "type" => TType::I32)
    );
  const UNKNOWN = 0;
  const UNKNOWN_METHOD = 1;
  const INVALID_MESSAGE_TYPE = 2;
  const WRONG_METHOD_NAME = 3;
  const BAD_SEQUENCE_ID = 4;
  const MISSING_RESULT = 5;
  const INVALID_TRANSFORM = 6;
  public function __construct($message = null, $code = 0) {
    parent::__construct($message, $code);
  }
  public function read($output) {
    return $this->_read("TApplicationException", self::$_TSPEC, $output);
  }
  public function write($output) {
    $xfer = 0;
    $xfer += $output->writeStructBegin("TApplicationException");
    if (\hacklib_cast_as_boolean($message = $this->getMessage())) {
      $xfer += $output->writeFieldBegin("message", TType::STRING, 1);
      $xfer += $output->writeString($message);
      $xfer += $output->writeFieldEnd();
    }
    if (\hacklib_cast_as_boolean($code = $this->getCode())) {
      $xfer += $output->writeFieldBegin("type", TType::I32, 2);
      $xfer += $output->writeI32($code);
      $xfer += $output->writeFieldEnd();
    }
    $xfer += $output->writeFieldStop();
    $xfer += $output->writeStructEnd();
    return $xfer;
  }
}
