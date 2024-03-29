// bugprone-fold-init-type
// The check flags type mismatches in folds like std::accumulate that might
// result in loss of precision. std::accumulate folds an input range into an
// initial value using the type of the latter, with operator+ by default. This
// can cause loss of precision through:
//
// Truncation: The following code uses a floating point range and an int initial
// value, so truncation wil happen at every application of operator+ and the
// result will be 0, which might not be what the user expected.

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone/fold-init-type.html

#include <iostream>
#include <numeric>

namespace bugprone::fold_init_type {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-result"
void check() {
  auto a = {0.5f, 0.5f, 0.5f, 0.5f};
  std::accumulate(std::begin(a), std::end(a), 0); // warn here!

  std::cout << "-- check bugprone-fold-init-type" << std::endl;
}
#pragma clang diagnostic pop
} // namespace bugprone::fold_init_type
