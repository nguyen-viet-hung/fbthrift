#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from cpython.ref cimport PyObject
from libc.stdint cimport int8_t, int16_t, int32_t, int64_t
from libcpp cimport bool as cbool
from libcpp.map cimport map as cmap, pair as cpair
from libcpp.memory cimport shared_ptr, unique_ptr
from libcpp.set cimport set as cset
from libcpp.string cimport string
from libcpp.vector cimport vector

from folly cimport cFollyFuture, cFollyTry, cFollyUnit
cimport folly.iobuf as __iobuf
from thrift.py3.common cimport cRpcOptions

cimport hsmodule.types as _hsmodule_types


cdef extern from "gen-cpp2/HsTestService.h" namespace "cpp2":
  cdef cppclass cHsTestServiceAsyncClient "cpp2::HsTestServiceAsyncClient":
      pass

cdef extern from "<utility>" namespace "std":
  cdef unique_ptr[cHsTestServiceClientWrapper] move(unique_ptr[cHsTestServiceClientWrapper])

cdef extern from "gen-py3/hsmodule/clients_wrapper.h" namespace "cpp2":
  cdef cppclass cHsTestServiceClientWrapper "cpp2::HsTestServiceClientWrapper":
    cFollyFuture[cFollyUnit] disconnect()
    void setPersistentHeader(const string& key, const string& value)

    cFollyFuture[int64_t] init(cRpcOptions, 
      int64_t arg_int1,)

