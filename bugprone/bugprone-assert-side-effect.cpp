// bugprone-assert-side-effect
// Finds assert() with side effect.
// The condition of assert() is evaluated only in debug builds so a condition
// with side effect can cause different behavior in debug / release builds.

// Options
//
// AssertMacros
// A comma-separated list of the names of assert macros to be checked.
//
// CheckFunctionCalls
// Whether to treat non-const member and non-member functions as they produce
// side effects. Disabled by default because it can increase the number of false
// positive warnings.

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone-assert-side-effect.html

#include <cassert>
#include <iostream>

namespace bugprone::assert_side_effect {
void check() {
  std::cout << "-- check bugprone-assert-side-effect FIXME" << std::endl;
  assert(
      true); // NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay,cert-dcl03-c,hicpp-static-assert,misc-static-assert,hicpp-no-array-decay)
}
} // namespace bugprone::assert_side_effect
