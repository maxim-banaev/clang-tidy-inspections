//
// Created by Maxim.Banaev on 6/13/2019.
//
#include <bugprone-argument-comment.h>
#include <bugprone-assert-side-effect.h>
#include <bugprone-bool-pointer-implicit-conversion.h>
#include <bugprone-copy-constructor-init.h>
#include <bugprone-dangling-handle.h>
#include <bugprone-fold-init-type.h>
#include <bugprone-forward-declaration-namespace.h>
#include <bugprone-forwarding-reference-overload.h>
#include <bugprone-inaccurate-erase.h>
#include <bugprone-incorrect-roundings.h>
#include <bugprone-integer-division.h>
#include <bugprone-lambda-function-name.h>
#include <bugprone-macro-parentheses.h>
#include <bugprone-macro-repeated-side-effects.h>
#include <bugprone-misplaced-widening-cast.h>
#include <bugprone-move-forwarding-reference.h>
#include <bugprone-spuriously-wake-up-functions.h>
#include <bugprone-string-constructor.h>
#include <bugprone-string-integer-assignment.h>
#include <bugprone-too-small-loop-variable.h>

int main() {
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
  bugprone::spuriously_wake_up_functions::check();
  bugprone::string_constructor::check();
  bugprone::string_integer_assignment::check();
  bugprone::too_small_loop_variable::check();

  return 0;
}
