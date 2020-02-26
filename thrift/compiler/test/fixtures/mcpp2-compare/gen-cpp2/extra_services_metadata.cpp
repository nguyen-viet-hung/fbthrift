/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include <thrift/lib/cpp2/gen/module_metadata_cpp.h>
#include "thrift/compiler/test/fixtures/mcpp2-compare/gen-cpp2/extra_services_metadata.h"

namespace apache {
namespace thrift {
namespace detail {
namespace md {
using ThriftMetadata = ::apache::thrift::metadata::ThriftMetadata;
using ThriftPrimitiveType = ::apache::thrift::metadata::ThriftPrimitiveType;
using ThriftType = ::apache::thrift::metadata::ThriftType;
using ThriftService = ::apache::thrift::metadata::ThriftService;
using ThriftServiceContext = ::apache::thrift::metadata::ThriftServiceContext;
using ThriftFunctionGenerator = void (*)(ThriftMetadata&, ThriftService&);


void StructMetadata<::extra::svc::containerStruct2>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs.emplace("extra_services.containerStruct2", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftStruct& extra_services_containerStruct2 = res.first->second;
  extra_services_containerStruct2.name = "extra_services.containerStruct2";
  extra_services_containerStruct2.is_union = false;
  static const std::tuple<int32_t, const char*, bool, std::unique_ptr<MetadataTypeInterface>>
  extra_services_containerStruct2_fields[] = {
    std::make_tuple(1, "fieldA", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_BOOL_TYPE)),
    std::make_tuple(101, "req_fieldA", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_BOOL_TYPE)),
    std::make_tuple(201, "opt_fieldA", true, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_BOOL_TYPE)),
    std::make_tuple(2, "fieldB", false, std::make_unique<Map>(std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE), std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_BOOL_TYPE))),
    std::make_tuple(102, "req_fieldB", false, std::make_unique<Map>(std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE), std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_BOOL_TYPE))),
    std::make_tuple(202, "opt_fieldB", true, std::make_unique<Map>(std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE), std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_BOOL_TYPE))),
    std::make_tuple(3, "fieldC", false, std::make_unique<Set>(std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE))),
    std::make_tuple(103, "req_fieldC", false, std::make_unique<Set>(std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE))),
    std::make_tuple(203, "opt_fieldC", true, std::make_unique<Set>(std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE))),
    std::make_tuple(4, "fieldD", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE)),
    std::make_tuple(5, "fieldE", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE)),
    std::make_tuple(105, "req_fieldE", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE)),
    std::make_tuple(205, "opt_fieldE", true, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE)),
  };
  for (const auto& f : extra_services_containerStruct2_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id = std::get<0>(f);
    field.name = std::get<1>(f);
    field.is_optional = std::get<2>(f);
    std::get<3>(f)->writeAndGenType(field.type, metadata);
    extra_services_containerStruct2.fields.push_back(std::move(field));
  }
}

void ServiceMetadata<::extra::svc::ExtraServiceSvIf>::gen_simple_function(ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  (void)metadata;
  func.name = "simple_function";
  auto func_ret_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_BOOL_TYPE);
  func_ret_type->writeAndGenType(func.returnType, metadata);
  service.functions.push_back(std::move(func));
}
void ServiceMetadata<::extra::svc::ExtraServiceSvIf>::gen_throws_function(ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  (void)metadata;
  func.name = "throws_function";
  auto func_ret_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_VOID_TYPE);
  func_ret_type->writeAndGenType(func.returnType, metadata);
  ::apache::thrift::metadata::ThriftField extra_services_ExtraService_throws_function_ex_1;
  extra_services_ExtraService_throws_function_ex_1.id = 1;
  extra_services_ExtraService_throws_function_ex_1.name = "ex";
  extra_services_ExtraService_throws_function_ex_1.is_optional = false;
  auto extra_services_ExtraService_throws_function_ex_1_type = std::make_unique<Struct< ::some::valid::ns::AnException>>("module.AnException");
  extra_services_ExtraService_throws_function_ex_1_type->writeAndGenType(extra_services_ExtraService_throws_function_ex_1.type, metadata);
  func.exceptions.push_back(std::move(extra_services_ExtraService_throws_function_ex_1));
  ExceptionMetadata< ::some::valid::ns::AnException>::gen(metadata);
  ::apache::thrift::metadata::ThriftField extra_services_ExtraService_throws_function_aex_2;
  extra_services_ExtraService_throws_function_aex_2.id = 2;
  extra_services_ExtraService_throws_function_aex_2.name = "aex";
  extra_services_ExtraService_throws_function_aex_2.is_optional = false;
  auto extra_services_ExtraService_throws_function_aex_2_type = std::make_unique<Struct< ::some::valid::ns::AnotherException>>("module.AnotherException");
  extra_services_ExtraService_throws_function_aex_2_type->writeAndGenType(extra_services_ExtraService_throws_function_aex_2.type, metadata);
  func.exceptions.push_back(std::move(extra_services_ExtraService_throws_function_aex_2));
  ExceptionMetadata< ::some::valid::ns::AnotherException>::gen(metadata);
  service.functions.push_back(std::move(func));
}
void ServiceMetadata<::extra::svc::ExtraServiceSvIf>::gen_throws_function2(ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  (void)metadata;
  func.name = "throws_function2";
  auto func_ret_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_BOOL_TYPE);
  func_ret_type->writeAndGenType(func.returnType, metadata);
  ::apache::thrift::metadata::ThriftField extra_services_ExtraService_throws_function2_param1_1;
  extra_services_ExtraService_throws_function2_param1_1.id = 1;
  extra_services_ExtraService_throws_function2_param1_1.name = "param1";
  extra_services_ExtraService_throws_function2_param1_1.is_optional = false;
  auto extra_services_ExtraService_throws_function2_param1_1_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_BOOL_TYPE);
  extra_services_ExtraService_throws_function2_param1_1_type->writeAndGenType(extra_services_ExtraService_throws_function2_param1_1.type, metadata);
  func.arguments.push_back(std::move(extra_services_ExtraService_throws_function2_param1_1));
  ::apache::thrift::metadata::ThriftField extra_services_ExtraService_throws_function2_ex_1;
  extra_services_ExtraService_throws_function2_ex_1.id = 1;
  extra_services_ExtraService_throws_function2_ex_1.name = "ex";
  extra_services_ExtraService_throws_function2_ex_1.is_optional = false;
  auto extra_services_ExtraService_throws_function2_ex_1_type = std::make_unique<Struct< ::some::valid::ns::AnException>>("module.AnException");
  extra_services_ExtraService_throws_function2_ex_1_type->writeAndGenType(extra_services_ExtraService_throws_function2_ex_1.type, metadata);
  func.exceptions.push_back(std::move(extra_services_ExtraService_throws_function2_ex_1));
  ExceptionMetadata< ::some::valid::ns::AnException>::gen(metadata);
  ::apache::thrift::metadata::ThriftField extra_services_ExtraService_throws_function2_aex_2;
  extra_services_ExtraService_throws_function2_aex_2.id = 2;
  extra_services_ExtraService_throws_function2_aex_2.name = "aex";
  extra_services_ExtraService_throws_function2_aex_2.is_optional = false;
  auto extra_services_ExtraService_throws_function2_aex_2_type = std::make_unique<Struct< ::some::valid::ns::AnotherException>>("module.AnotherException");
  extra_services_ExtraService_throws_function2_aex_2_type->writeAndGenType(extra_services_ExtraService_throws_function2_aex_2.type, metadata);
  func.exceptions.push_back(std::move(extra_services_ExtraService_throws_function2_aex_2));
  ExceptionMetadata< ::some::valid::ns::AnotherException>::gen(metadata);
  service.functions.push_back(std::move(func));
}
void ServiceMetadata<::extra::svc::ExtraServiceSvIf>::gen_throws_function3(ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  (void)metadata;
  func.name = "throws_function3";
  auto func_ret_type = std::make_unique<Map>(std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE), std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE));
  func_ret_type->writeAndGenType(func.returnType, metadata);
  ::apache::thrift::metadata::ThriftField extra_services_ExtraService_throws_function3_param1_1;
  extra_services_ExtraService_throws_function3_param1_1.id = 1;
  extra_services_ExtraService_throws_function3_param1_1.name = "param1";
  extra_services_ExtraService_throws_function3_param1_1.is_optional = false;
  auto extra_services_ExtraService_throws_function3_param1_1_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_BOOL_TYPE);
  extra_services_ExtraService_throws_function3_param1_1_type->writeAndGenType(extra_services_ExtraService_throws_function3_param1_1.type, metadata);
  func.arguments.push_back(std::move(extra_services_ExtraService_throws_function3_param1_1));
  ::apache::thrift::metadata::ThriftField extra_services_ExtraService_throws_function3_param2_3;
  extra_services_ExtraService_throws_function3_param2_3.id = 3;
  extra_services_ExtraService_throws_function3_param2_3.name = "param2";
  extra_services_ExtraService_throws_function3_param2_3.is_optional = false;
  auto extra_services_ExtraService_throws_function3_param2_3_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE);
  extra_services_ExtraService_throws_function3_param2_3_type->writeAndGenType(extra_services_ExtraService_throws_function3_param2_3.type, metadata);
  func.arguments.push_back(std::move(extra_services_ExtraService_throws_function3_param2_3));
  ::apache::thrift::metadata::ThriftField extra_services_ExtraService_throws_function3_ex_2;
  extra_services_ExtraService_throws_function3_ex_2.id = 2;
  extra_services_ExtraService_throws_function3_ex_2.name = "ex";
  extra_services_ExtraService_throws_function3_ex_2.is_optional = false;
  auto extra_services_ExtraService_throws_function3_ex_2_type = std::make_unique<Struct< ::some::valid::ns::AnException>>("module.AnException");
  extra_services_ExtraService_throws_function3_ex_2_type->writeAndGenType(extra_services_ExtraService_throws_function3_ex_2.type, metadata);
  func.exceptions.push_back(std::move(extra_services_ExtraService_throws_function3_ex_2));
  ExceptionMetadata< ::some::valid::ns::AnException>::gen(metadata);
  ::apache::thrift::metadata::ThriftField extra_services_ExtraService_throws_function3_aex_5;
  extra_services_ExtraService_throws_function3_aex_5.id = 5;
  extra_services_ExtraService_throws_function3_aex_5.name = "aex";
  extra_services_ExtraService_throws_function3_aex_5.is_optional = false;
  auto extra_services_ExtraService_throws_function3_aex_5_type = std::make_unique<Struct< ::some::valid::ns::AnotherException>>("module.AnotherException");
  extra_services_ExtraService_throws_function3_aex_5_type->writeAndGenType(extra_services_ExtraService_throws_function3_aex_5.type, metadata);
  func.exceptions.push_back(std::move(extra_services_ExtraService_throws_function3_aex_5));
  ExceptionMetadata< ::some::valid::ns::AnotherException>::gen(metadata);
  service.functions.push_back(std::move(func));
}
void ServiceMetadata<::extra::svc::ExtraServiceSvIf>::gen_oneway_void_ret(ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  (void)metadata;
  func.name = "oneway_void_ret";
  auto func_ret_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_VOID_TYPE);
  func_ret_type->writeAndGenType(func.returnType, metadata);
  service.functions.push_back(std::move(func));
}
void ServiceMetadata<::extra::svc::ExtraServiceSvIf>::gen_oneway_void_ret_i32_i32_i32_i32_i32_param(ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  (void)metadata;
  func.name = "oneway_void_ret_i32_i32_i32_i32_i32_param";
  auto func_ret_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_VOID_TYPE);
  func_ret_type->writeAndGenType(func.returnType, metadata);
  ::apache::thrift::metadata::ThriftField extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param1_1;
  extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param1_1.id = 1;
  extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param1_1.name = "param1";
  extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param1_1.is_optional = false;
  auto extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param1_1_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE);
  extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param1_1_type->writeAndGenType(extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param1_1.type, metadata);
  func.arguments.push_back(std::move(extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param1_1));
  ::apache::thrift::metadata::ThriftField extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param2_2;
  extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param2_2.id = 2;
  extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param2_2.name = "param2";
  extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param2_2.is_optional = false;
  auto extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param2_2_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE);
  extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param2_2_type->writeAndGenType(extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param2_2.type, metadata);
  func.arguments.push_back(std::move(extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param2_2));
  ::apache::thrift::metadata::ThriftField extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param3_3;
  extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param3_3.id = 3;
  extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param3_3.name = "param3";
  extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param3_3.is_optional = false;
  auto extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param3_3_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE);
  extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param3_3_type->writeAndGenType(extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param3_3.type, metadata);
  func.arguments.push_back(std::move(extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param3_3));
  ::apache::thrift::metadata::ThriftField extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param4_4;
  extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param4_4.id = 4;
  extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param4_4.name = "param4";
  extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param4_4.is_optional = false;
  auto extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param4_4_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE);
  extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param4_4_type->writeAndGenType(extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param4_4.type, metadata);
  func.arguments.push_back(std::move(extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param4_4));
  ::apache::thrift::metadata::ThriftField extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param5_5;
  extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param5_5.id = 5;
  extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param5_5.name = "param5";
  extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param5_5.is_optional = false;
  auto extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param5_5_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE);
  extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param5_5_type->writeAndGenType(extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param5_5.type, metadata);
  func.arguments.push_back(std::move(extra_services_ExtraService_oneway_void_ret_i32_i32_i32_i32_i32_param_param5_5));
  service.functions.push_back(std::move(func));
}
void ServiceMetadata<::extra::svc::ExtraServiceSvIf>::gen_oneway_void_ret_map_setlist_param(ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  (void)metadata;
  func.name = "oneway_void_ret_map_setlist_param";
  auto func_ret_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_VOID_TYPE);
  func_ret_type->writeAndGenType(func.returnType, metadata);
  ::apache::thrift::metadata::ThriftField extra_services_ExtraService_oneway_void_ret_map_setlist_param_param1_1;
  extra_services_ExtraService_oneway_void_ret_map_setlist_param_param1_1.id = 1;
  extra_services_ExtraService_oneway_void_ret_map_setlist_param_param1_1.name = "param1";
  extra_services_ExtraService_oneway_void_ret_map_setlist_param_param1_1.is_optional = false;
  auto extra_services_ExtraService_oneway_void_ret_map_setlist_param_param1_1_type = std::make_unique<Map>(std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE), std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I64_TYPE));
  extra_services_ExtraService_oneway_void_ret_map_setlist_param_param1_1_type->writeAndGenType(extra_services_ExtraService_oneway_void_ret_map_setlist_param_param1_1.type, metadata);
  func.arguments.push_back(std::move(extra_services_ExtraService_oneway_void_ret_map_setlist_param_param1_1));
  ::apache::thrift::metadata::ThriftField extra_services_ExtraService_oneway_void_ret_map_setlist_param_param2_3;
  extra_services_ExtraService_oneway_void_ret_map_setlist_param_param2_3.id = 3;
  extra_services_ExtraService_oneway_void_ret_map_setlist_param_param2_3.name = "param2";
  extra_services_ExtraService_oneway_void_ret_map_setlist_param_param2_3.is_optional = false;
  auto extra_services_ExtraService_oneway_void_ret_map_setlist_param_param2_3_type = std::make_unique<Set>(std::make_unique<List>(std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE)));
  extra_services_ExtraService_oneway_void_ret_map_setlist_param_param2_3_type->writeAndGenType(extra_services_ExtraService_oneway_void_ret_map_setlist_param_param2_3.type, metadata);
  func.arguments.push_back(std::move(extra_services_ExtraService_oneway_void_ret_map_setlist_param_param2_3));
  service.functions.push_back(std::move(func));
}
void ServiceMetadata<::extra::svc::ExtraServiceSvIf>::gen_oneway_void_ret_struct_param(ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  (void)metadata;
  func.name = "oneway_void_ret_struct_param";
  auto func_ret_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_VOID_TYPE);
  func_ret_type->writeAndGenType(func.returnType, metadata);
  ::apache::thrift::metadata::ThriftField extra_services_ExtraService_oneway_void_ret_struct_param_param1_1;
  extra_services_ExtraService_oneway_void_ret_struct_param_param1_1.id = 1;
  extra_services_ExtraService_oneway_void_ret_struct_param_param1_1.name = "param1";
  extra_services_ExtraService_oneway_void_ret_struct_param_param1_1.is_optional = false;
  auto extra_services_ExtraService_oneway_void_ret_struct_param_param1_1_type = std::make_unique<Struct< ::some::valid::ns::MyStruct>>("module.MyStruct");
  extra_services_ExtraService_oneway_void_ret_struct_param_param1_1_type->writeAndGenType(extra_services_ExtraService_oneway_void_ret_struct_param_param1_1.type, metadata);
  func.arguments.push_back(std::move(extra_services_ExtraService_oneway_void_ret_struct_param_param1_1));
  service.functions.push_back(std::move(func));
}
void ServiceMetadata<::extra::svc::ExtraServiceSvIf>::gen_oneway_void_ret_listunion_param(ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  (void)metadata;
  func.name = "oneway_void_ret_listunion_param";
  auto func_ret_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_VOID_TYPE);
  func_ret_type->writeAndGenType(func.returnType, metadata);
  ::apache::thrift::metadata::ThriftField extra_services_ExtraService_oneway_void_ret_listunion_param_param1_1;
  extra_services_ExtraService_oneway_void_ret_listunion_param_param1_1.id = 1;
  extra_services_ExtraService_oneway_void_ret_listunion_param_param1_1.name = "param1";
  extra_services_ExtraService_oneway_void_ret_listunion_param_param1_1.is_optional = false;
  auto extra_services_ExtraService_oneway_void_ret_listunion_param_param1_1_type = std::make_unique<List>(std::make_unique<Union< ::some::valid::ns::ComplexUnion>>("module.ComplexUnion"));
  extra_services_ExtraService_oneway_void_ret_listunion_param_param1_1_type->writeAndGenType(extra_services_ExtraService_oneway_void_ret_listunion_param_param1_1.type, metadata);
  func.arguments.push_back(std::move(extra_services_ExtraService_oneway_void_ret_listunion_param_param1_1));
  service.functions.push_back(std::move(func));
}

void ServiceMetadata<::extra::svc::ExtraServiceSvIf>::gen(ThriftMetadata& metadata, ThriftServiceContext& context) {
  (void) metadata;
  ::apache::thrift::metadata::ThriftService extra_services_ExtraService;
  extra_services_ExtraService.name = "extra_services.ExtraService";
  static const ThriftFunctionGenerator functions[] = {
    ServiceMetadata<::extra::svc::ExtraServiceSvIf>::gen_simple_function,
    ServiceMetadata<::extra::svc::ExtraServiceSvIf>::gen_throws_function,
    ServiceMetadata<::extra::svc::ExtraServiceSvIf>::gen_throws_function2,
    ServiceMetadata<::extra::svc::ExtraServiceSvIf>::gen_throws_function3,
    ServiceMetadata<::extra::svc::ExtraServiceSvIf>::gen_oneway_void_ret,
    ServiceMetadata<::extra::svc::ExtraServiceSvIf>::gen_oneway_void_ret_i32_i32_i32_i32_i32_param,
    ServiceMetadata<::extra::svc::ExtraServiceSvIf>::gen_oneway_void_ret_map_setlist_param,
    ServiceMetadata<::extra::svc::ExtraServiceSvIf>::gen_oneway_void_ret_struct_param,
    ServiceMetadata<::extra::svc::ExtraServiceSvIf>::gen_oneway_void_ret_listunion_param,
  };
  for (auto& function_gen : functions) {
    function_gen(metadata, extra_services_ExtraService);
  }
  extra_services_ExtraService.set_parent("module.ParamService");
  ThriftServiceContext module_ParamService_parent_context;
  ServiceMetadata<::some::valid::ns::ParamServiceSvIf>::gen(metadata, module_ParamService_parent_context);
  auto module_ParamService_parent_name = module_ParamService_parent_context.get_service_info().get_name();
  metadata.services.emplace(std::move(module_ParamService_parent_name), std::move(module_ParamService_parent_context.service_info));
  context.set_service_info(std::move(extra_services_ExtraService));
  ::apache::thrift::metadata::ThriftModuleContext module;
  module.set_name("extra_services");
  context.set_module(std::move(module));
}
} // namespace md
} // namespace detail
} // namespace thrift
} // namespace apache
