// readability-else-after-return
// LLVM Coding Standards advises to reduce indentation where possible and where
// it makes understanding code easier. Early exit is one of the suggested
// enforcements of that. Please do not use else or else if after something that
// interrupts control flow - like return, break, continue, throw.

// https://clang.llvm.org/extra/clang-tidy/checks/readability/else-after-return.html

#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-magic-numbers"
namespace readability::else_after_return {
void foo(int Value) { // NOLINT(readability-function-size)
  int Local = 0;
  for (int i = 0; i < 42; i++) {
    if (Value == 1) {
      return;
    } else { // warn here!
      Local++;
    }

    if (Value == 2) // NOLINT(readability-braces-around-statements)
      continue;
    else // warn here! NOLINT(readability-braces-around-statements)
      Local++;

    if (Value == 3) {
      throw 42;
    } else { // warn here!
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

#pragma clang diagnostic pop