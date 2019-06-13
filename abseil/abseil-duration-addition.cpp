// abseil-duration-addition
// Check for cases where addition should be performed in the absl::Time domain.
// When adding two values, and one is known to be an absl::Time, we can infer
// that the other should be interpreted as an absl::Duration of a similar scale,
// and make that inference explicit.

// https://clang.llvm.org/extra/clang-tidy/checks/abseil-duration-addition.html

#include <iostream>
#include <string>
#include <absl/time/time.h>

namespace abseil::duration_addition {
void check() {
  std::cout << "-- check abseil-duration-addition" << std::endl;

  int x;
  absl::Time t;
  int result = absl::ToUnixSeconds(t) + x;
  }
} // namespace abseil_duration_addition
