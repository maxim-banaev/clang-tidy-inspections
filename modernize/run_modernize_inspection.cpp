#include <modernize-avoid-bind.h>
#include <modernize-deprecated-headers.h>
#include <modernize-loop-convert.h>
#include <modernize-make-shared.h>
#include <modernize-pass-by-value.h>
#include <modernize-raw-string-literal.h>
#include <modernize-redundant-void-arg.h>
#include <modernize-replace-auto-ptr.h>
#include <modernize-replace-random-shuffle.h>
#include <modernize-use-auto.h>
#include <modernize-use-bool-literals.h>
#include <modernize-avoid-c-arrays.h>

int main() {
  modernize::avoid_bind::check();
  modernize::avoid_c_arrays::check();
  modernize::deprecated_headers::check();
  modernize::loop_convert::check();
  modernize::make_shared::check();
  modernize::pass_by_value::check();
  modernize::raw_string_literal::check();
  modernize::redundant_void_arg::check();
  modernize::replace_auto_ptr::check();
  modernize::replace_random_shuffle::check();
  modernize::use_auto::check();
  modernize::use_bool_literals::check();

  return 0;
}
