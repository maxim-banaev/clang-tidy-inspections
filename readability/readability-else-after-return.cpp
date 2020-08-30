// readability-else-after-return
// LLVM Coding Standards advises to reduce indentation where possible and where
// it makes understanding code easier. Early exit is one of the suggested
// enforcements of that. Please do not use else or else if after something that
// interrupts control flow - like return, break, continue, throw.

// https://clang.llvm.org/extra/clang-tidy/checks/readability-else-after-return.html

#include <iostream>

namespace readability::else_after_return {
void foo(int Value) {
  int Local = 0;
  for (int i = 0; i < 42; i++) {
    if (Value == 1) {
      return;
    } else {
      Local++;
    }

    if (Value == 2)
      continue;
    else
      Local++;

    if (Value == 3) {
      throw 42;
    } else {
      Local++;
    }
  }
}

void check() {
  std::cout << "-- check readability-else-after-return [turn off by default]"
            << std::endl;

  foo(0);
}
} // namespace readability::else_after_return
