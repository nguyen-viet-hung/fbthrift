#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

import typing as _typing

import folly.iobuf as __iobuf
import thrift.py3.builder

import includes.types as _includes_types
import includes.builders as _includes_builders

import module.types as _module_types


class MyStruct_Builder(thrift.py3.builder.StructBuilder):
    MyIncludedField: _typing.Any
    MyOtherIncludedField: _typing.Any
    MyIncludedInt: _typing.Optional[int]

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...


