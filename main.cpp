#include <iostream>

// Clang-Tidy via clangd
// https://youtrack.jetbrains.com/issue/CPP-12784
// https://clang.llvm.org/extra/clangd.html

// Current Status
//
// Many features could be implemented in Clangd. Here is a list of features that could be useful with the status of
// whether or not they are already implemented in Clangd and specified in the Language Server Protocol.
// Note that for some of the features, it is not clear whether or not they should be part of the Language Server
// Protocol, so those features might be eventually developed outside Clangd or as an extension to the protocol.
//
// C/C++ Editor feature	LSP	Clangd
// Formatting	        Yes	Yes
// Completion	        Yes	Yes
// Diagnostics	        Yes	Yes
// Fix-its	            Yes	Yes
// Go to Definition	    Yes	Yes
// Signature Help	    Yes	Yes
// Document Highlights	Yes	Yes
// Rename	            Yes	Yes
// Source hover	        Yes	Yes
// Find References	    Yes	No
// Code Lens	        Yes	No
// Document Symbols	    Yes	No
// Workspace Symbols	Yes	No
// Syntax and Semantic
// Coloring	            No	No
// Code folding	        No	No
// Call hierarchy	    No	No
// Type hierarchy	    No	No
// Organize Includes	No	No
// Quick Assist	        No	No
// Extract Local
// Variable	            No	No
// Extract
// Function/Method	    No	No
// Hide Method	        No	No
// Implement Method	    No	No
// Gen. Getters/Setters	No	No

// Registry flags:
// 1) Enable clangd - set clion.clang.clangd.on
// 2) Enable errors from clangd - set clion.clang.show.errors
// 3) Enable clangd as clang-tidy provider - set clion.clang.tidy.uses.clangd
// 4) To disable default error annotators - unset clion.default.annotators.enabled

// https://clang.llvm.org/extra/clang-tidy/checks/list.html

#include "include/abseil_string_find_startswith.h"
#include "include/bugprone/bugprone-argument-comment.h"
#include "include/bugprone/bugprone-assert-side-effect.h"
#include "include/bugprone/bugprone-bool-pointer-implicit-conversion.h"
#include "include/bugprone/bugprone-copy-constructor-init.h"
#include "include/bugprone/bugprone-dangling-handle.h"
#include "include/bugprone/bugprone-fold-init-type.h"
#include "include/bugprone/bugprone-forward-declaration-namespace.h"
#include "include/bugprone/bugprone-forwarding-reference-overload.h"
#include "include/bugprone/bugprone-inaccurate-erase.h"
#include "include/bugprone/bugprone-incorrect-roundings.h"
#include "include/bugprone/bugprone-integer-division.h"
#include "include/bugprone/bugprone-lambda-function-name.h"
#include "include/bugprone/bugprone-macro-parentheses.h"
#include "include/bugprone/bugprone-macro-repeated-side-effects.h"
#include "include/bugprone/bugprone-misplaced-widening-cast.h"
#include "include/bugprone/bugprone-move-forwarding-reference.h"
#include "include/bugprone/bugprone-string-constructor.h"
#include "include/bugprone/bugprone-string-integer-assignment.h"

#include "include/cert/cert-dcl50-cpp.h"
#include "include/cert/cert-dcl58-cpp.h"
#include "include/cert/cert-err52-cpp.h"

#include "include/google/google-default-arguments.h"

#include "include/modernize/modernize-avoid-bind.h"
#include "include/modernize/modernize-deprecated-headers.h"
#include "include/modernize/modernize-loop-convert.h"
#include "include/modernize/modernize-make-shared.h"
#include "include/modernize/modernize-pass-by-value.h"
#include "include/modernize/modernize-raw-string-literal.h"
#include "include/modernize/modernize-redundant-void-arg.h"

#include "include/performance/performance-unnecessary-value-param.h"

#include "include/readability/readability-avoid-const-params-in-decls.h"
#include "include/readability/readability-braces-around-statements.h"
#include "include/readability/readability-container-size-empty.h"
#include "include/readability/readability-delete-null-pointer.h"
#include "include/readability/readability-deleted-default.h"
#include "include/readability/readability-else-after-return.h"
#include "include/readability/readability-function-size.h"
#include "include/readability/readability-identifier-naming.h"
#include "include/readability/readability-implicit-bool-conversion.h"
#include "include/readability/readability-inconsistent-declaration-parameter-name.h"
#include "include/readability/readability-misleading-indentation.h"
#include "include/readability/readability-misplaced-array-index.h"
#include "include/readability/readability-named-parameter.h"
#include "include/readability/readability-non-const-parameter.h"
#include "include/readability/readability-redundant-control-flow.h"
#include "include/readability/readability-redundant-declaration.h"
#include "include/readability/readability-redundant-function-ptr-dereference.h"
#include "include/readability/readability-redundant-member-init.h"
#include "include/readability/readability-redundant-smartptr-get.h"
#include "include/readability/readability-redundant-string-cstr.h"
#include "include/readability/readability-redundant-string-init.h"
#include "include/readability/readability-simplify-boolean-expr.h"
#include "include/readability/readability-simplify-subscript-expr.h"
#include "include/readability/readability-static-accessed-through-instance.h"

#include "include/portability/portability-simd-intrinsics.h"

int main() {
    abseil_string_find_startswith::check();

    bugprone::argument_comment::check();
    bugprone::assert_side_effect::check();
    bugprone::bool_pointer_implicit_conversion::check();
    bugprone::copy_constructor_init::check();
    bugprone::dangling_handle::check();
    bugprone::fold_init_type::check();
    bugprone::forward_declaration_namespace::check();
    bugprone::forwarding_reference_overload::check();
    bugprone::inaccurate_erase::check();
    bugprone::incorrect_rounding::check();
    bugprone::integer_division::check();
    bugprone::lambda_function_name::check();
    bugprone::macro_parentheses::check();
    bugprone::macro_repeated_side_effects::check();
    bugprone::misplaced_widening_cast::check();
    bugprone::move_forwarding_reference::check();
    bugprone::string_constructor::check();
    bugprone::string_integer_assignment::check();

    cert::dcl50_cpp::check();
    cert::dcl58_cpp::check();
    cert::err52_cpp::check();

    google::default_arguments::check();

    modernize::avoid_bind::check();
    modernize::deprecated_headers::check();
    modernize::loop_convert::check();
    modernize::make_shared::check();
    modernize::pass_by_value::check();
    modernize::raw_string_literal::check();
    modernize::redundant_void_arg::check();

    performance::unnecessary_value_param::check();

    readability::avoid_const_params_in_decls::check();
    readability::brace_around_statements::check();
    readability::container_size_empty::check();
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

    return 0;
}