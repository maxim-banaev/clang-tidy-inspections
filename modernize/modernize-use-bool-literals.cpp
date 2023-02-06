// use-bool-literals
// Finds integer literals which are cast to bool

// https://clang.llvm.org/extra/clang-tidy/checks/modernize/use-bool-literals.html

#include <iostream>

namespace modernize::use_bool_literals {
#pragma clang diagnostic push
#pragma ide diagnostic ignored "ConstantConditionsOC"
#pragma ide diagnostic ignored "UnreachableCode"
void check() {
  bool p = 1;                                     // warn here!
  [[maybe_unused]] bool f = static_cast<bool>(1); // warn here!
  std::ios_base::sync_with_stdio(0);              // warn here!
  [[maybe_unused]] bool x = p ? 1 : 0;            // warn here!
}
#pragma clang diagnostic pop
} // namespace modernize::use_bool_literals
