// aabseil-duration-comparison
//
// Checks for comparisons which should be in the absl::Duration domain instead
// of the floating point or integer domains.
//
// N.B.: In cases where a Duration was being converted to an integer and then
// compared against a floating-point value, truncation during the Duration
// conversion might yield a different result. In practice this is very rare,
// and still indicates a bug which should be fixed.
//
// https://clang.llvm.org/extra/clang-tidy/checks/abseil-duration-comparison.html

#include <absl/time/time.h>
#include <iostream>

namespace abseil::duration_comparison {
void check() {
  std::cout << "-- check abseil-duration-comparison" << std::endl;

  double x;
  absl::Duration d;
  if (x < absl::ToDoubleSeconds(d)) {} // should warn here

  if (x < absl::ToInt64Microseconds(d)) {} // should warn here
}
} // namespace abseil::duration_comparison
