// bugprone-misplaced-widening-cast
//
// This check will warn when there is a cast of a calculation result to a bigger
// type. If the intention of the cast is to avoid loss of precision then the
// cast is misplaced, and there can be loss of precision. Otherwise the cast is
// ineffective.
//
// Options
//
// CheckImplicitCasts
// If non-zero, enables detection of implicit casts. Default is non-zero.

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone-misplaced-widening-cast.html

#include <iostream>

namespace bugprone::misplaced_widening_cast {

long f(int x) {
  return static_cast<long>(x * 1000); // should warn here
}

void check() {
  std::cout << "-- check bugprone-misplaced-widening-cast" << std::endl;
  f(1);
}
} // namespace bugprone::misplaced_widening_cast
