// bugprone-macro-repeated-side-effects
// Checks for repeated argument with side effects in macros.

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone-macro-repeated-side-effects.html

#include <iostream>

namespace bugprone::macro_repeated_side_effects {

#define badA(x, y) ((x) + ((x) + (y)) + (y))

void bad(int ret, int a, int b) { ret = badA(a++, b); } // should warn here
void check() {
  std::cout << "-- check bugprone-macro-repeated-side-effects" << std::endl;
}
} // namespace bugprone::macro_repeated_side_effects