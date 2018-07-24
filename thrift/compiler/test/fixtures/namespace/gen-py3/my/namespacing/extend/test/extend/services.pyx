#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from libcpp.memory cimport shared_ptr, make_shared, unique_ptr, make_unique
from libcpp.string cimport string
from libcpp cimport bool as cbool
from cpython cimport bool as pbool
from libc.stdint cimport int8_t, int16_t, int32_t, int64_t
from libcpp.vector cimport vector
from libcpp.set cimport set as cset
from libcpp.map cimport map as cmap
from cython.operator cimport dereference as deref
from cpython.ref cimport PyObject
from thrift.py3.exceptions cimport (
    cTApplicationException,
    ApplicationError as __ApplicationError,
    cTApplicationExceptionType__UNKNOWN)
from thrift.py3.server cimport ServiceInterface, RequestContext, Cpp2RequestContext
from thrift.py3.server import RequestContext, pass_context
from folly cimport (
  cFollyPromise,
  cFollyUnit,
  c_unit
)

cimport folly.futures
from folly.executor cimport get_executor
cimport folly.iobuf as __iobuf
import folly.iobuf as __iobuf
from folly.iobuf cimport move as move_iobuf

cimport my.namespacing.extend.test.extend.types as _my_namespacing_extend_test_extend_types
import my.namespacing.extend.test.extend.types as _my_namespacing_extend_test_extend_types
cimport hsmodule.services as _hsmodule_services
import hsmodule.services as _hsmodule_services
import hsmodule.types as _hsmodule_types
cimport hsmodule.types as _hsmodule_types

import asyncio
import functools
import sys
import traceback
import types as _py_types

from my.namespacing.extend.test.extend.services_wrapper cimport cExtendTestServiceInterface


cdef extern from "<utility>" namespace "std":
    cdef cFollyPromise[unique_ptr[string]] move(cFollyPromise[unique_ptr[string]])
    cdef cFollyPromise[cbool] move(
        cFollyPromise[cbool])

cdef class Promise_bool:
    cdef cFollyPromise[cbool] cPromise

    @staticmethod
    cdef create(cFollyPromise[cbool] cPromise):
        inst = <Promise_bool>Promise_bool.__new__(Promise_bool)
        inst.cPromise = move(cPromise)
        return inst

cdef object _ExtendTestService_annotations = _py_types.MappingProxyType({
})


cdef class ExtendTestServiceInterface(
    _hsmodule_services.HsTestServiceInterface
):
    annotations = _ExtendTestService_annotations

    def __cinit__(self):
        self.interface_wrapper = cExtendTestServiceInterface(
            <PyObject *> self,
            get_executor()
        )

    @staticmethod
    def pass_context_check(fn):
        return pass_context(fn)

    async def check(
            self,
            struct1):
        raise NotImplementedError("async def check is not implemented")


cdef api void call_cy_ExtendTestService_check(
    object self,
    Cpp2RequestContext* ctx,
    cFollyPromise[cbool] cPromise,
    unique_ptr[_hsmodule_types.cHsFoo] struct1
):
    cdef ExtendTestServiceInterface __iface
    __iface = self
    __promise = Promise_bool.create(move(cPromise))
    arg_struct1 = _hsmodule_types.HsFoo.create(shared_ptr[_hsmodule_types.cHsFoo](struct1.release()))
    __context = None
    if __iface._pass_context_check:
        __context = RequestContext.create(ctx)
    asyncio.get_event_loop().create_task(
        ExtendTestService_check_coro(
            self,
            __context,
            __promise,
            arg_struct1
        )
    )

async def ExtendTestService_check_coro(
    object self,
    object ctx,
    Promise_bool promise,
    struct1
):
    try:
        if ctx is not None:
            result = await self.check(ctx,
                      struct1)
        else:
            result = await self.check(
                      struct1)
    except __ApplicationError as ex:
        # If the handler raised an ApplicationError convert it to a C++ one
        promise.cPromise.setException(cTApplicationException(
            ex.type.value, ex.message.encode('UTF-8')
        ))
    except Exception as ex:
        print(
            "Unexpected error in service handler check:",
            file=sys.stderr)
        traceback.print_exc()
        promise.cPromise.setException(cTApplicationException(
            cTApplicationExceptionType__UNKNOWN, repr(ex).encode('UTF-8')
        ))
    else:
        promise.cPromise.setValue(<cbool> result)

