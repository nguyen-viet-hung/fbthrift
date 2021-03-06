(*
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
 *)

open Thrift

class virtual t
    (pf : Processor.t)
    (st : Transport.server_t)
    (tf : Transport.factory)
    (ipf : Protocol.factory)
    (opf : Protocol.factory)=
object
  method virtual serve : unit
end;;



let run_basic_server proc port =
  Unix.establish_server (fun inp -> fun out ->
                           let trans = new TChannelTransport.t (inp,out) in
                           let proto = new TBinaryProtocol.t (trans :> Transport.t) in
                             try
                               while proc#process proto proto do () done; ()
                             with e -> ()) (Unix.ADDR_INET (Unix.inet_addr_of_string "127.0.0.1",port))


