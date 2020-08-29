// bugprone-macro-parentheses
// Finds macros that can have unexpected behaviour due to missing parentheses.
//
// Macros are expanded by the preprocessor as-is. As a result, there can be
// unexpected behaviour; operators may be evaluated in unexpected order and
// unary operators may become binary operators, etc.
//
// When the replacement list has an expression, it is recommended to surround it
// with parentheses. This ensures that the macro result is evaluated completely
// before it is used.
//
// It is also recommended to surround macro arguments in the replacement list
// with parentheses. This ensures that the argument value is calculated
// properly.

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone-macro-parentheses.html

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#pragma ide diagnostic ignored "fuchsia-default-arguments"
#pragma ide diagnostic ignored "bugprone-inaccurate-erase"

#include <iostream>
#include <vector>

#define ERASE(x, y) x.erase(remove(x.begin(), x.end(), y)) // should warn here

namespace bugprone::macro_parentheses {
void check() {
  std::cout << "-- check bugprone-macro-parentheses" << std::endl;

  std::vector<int> v = {10, 20, 30, 30, 20, 10, 10, 20};
  // ERASE(v, 1);
}
} // namespace bugprone::macro_parentheses

#pragma clang diagnostic pop