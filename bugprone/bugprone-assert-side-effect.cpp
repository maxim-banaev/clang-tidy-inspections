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

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone/assert-side-effect.html

#include <iostream>

namespace bugprone::assert_side_effect {

#ifdef NDEBUG
#define assert(x) 1
#else
#define assert(x)                                                              \
  if (!(x))                                                                    \
  (void)abort()
#endif

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedValue"
void check() {
  std::cout << "-- check bugprone-assert-side-effect" << std::endl;

  [[maybe_unused]] int X = 1;
  assert(X = 0); // warn here! NOLINT(bugprone-assignment-in-if-condition)
}
#pragma clang diagnostic pop
} // namespace bugprone::assert_side_effect
