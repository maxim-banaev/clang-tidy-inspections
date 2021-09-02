#include <readability-avoid-const-params-in-decls.h>
#include <readability-braces-around-statements.h>
#include <readability-container-size-empty.h>
#include <readability-convert-member-functions-to-static.h>
#include <readability-delete-null-pointer.h>
#include <readability-deleted-default.h>
#include <readability-else-after-return.h>
#include <readability-function-size.h>
#include <readability-identifier-naming.h>
#include <readability-implicit-bool-conversion.h>
#include <readability-inconsistent-declaration-parameter-name.h>
#include <readability-misleading-indentation.h>
#include <readability-misplaced-array-index.h>
#include <readability-named-parameter.h>
#include <readability-non-const-parameter.h>
#include <readability-redundant-control-flow.h>
#include <readability-redundant-declaration.h>
#include <readability-redundant-function-ptr-dereference.h>
#include <readability-redundant-member-init.h>
#include <readability-redundant-smartptr-get.h>
#include <readability-redundant-string-cstr.h>
#include <readability-redundant-string-init.h>
#include <readability-simplify-boolean-expr.h>
#include <readability-simplify-subscript-expr.h>
#include <readability-static-accessed-through-instance.h>

#include <iostream>

int main() {
  readability::avoid_const_params_in_decls::check();
  readability::brace_around_statements::check();
  readability::container_size_empty::check();
  readability::convert_member_functions_to_static::check();
  readability::delete_null_pointer::check();
  readability::deleted_default::check();
  readability::else_after_return::check();
  readability::function_size::check();
  readability::identifier_naming::check();
  readability::implicit_bool_conversion::check();
  readability::inconsistent_declaration_parameter_name::check();
  readability::misleading_indentation::check();
  readability::misplaced_array_index::check();
  readability::named_parameter::check();
  readability::non_const_parameter::check();
  readability::redundant_control_flow::check();
  readability::redundant_declaration::check();
  readability::redundant_function_ptr_dereference::check();
  readability::redundant_member_init::check();
  readability::redundant_smartptr_get::check();
  readability::redundant_string_cstr::check();
  readability::redundant_string_init::check();
  readability::simplify_boolean_expr::check();

  readability::simplify_subscript_expr::check();

  readability::static_accessed_through_instance::check();

  std::cout << std::endl;
  return 0;
}