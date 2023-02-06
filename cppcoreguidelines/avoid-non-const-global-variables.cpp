// cppcoreguidelines-avoid-non-const-global-variables.html

// Finds non-const global variables as described in I.2 of C++ Core Guidelines .
// As R.6 of C++ Core Guidelines is a duplicate of rule I.2 it also covers that
// rule.
// https://clang.llvm.org/extra/clang-tidy/checks/cppcoreguidelines/avoid-non-const-global-variables.html

#include <iostream>

// Turn off by default!

namespace cppcoreguidelines::avoid_non_const_global_variables {
int nonConstInt = 0;                                       // warn here!
[[maybe_unused]] int &nonConstIntReference = nonConstInt;  // warn here!
[[maybe_unused]] int *pointerToNonConstInt = &nonConstInt; // warn here!

void check() {
  std::cout << "-- check avoid-non-const-global-variables [turn off by default]"
            << std::endl;
}
} // namespace cppcoreguidelines::avoid_non_const_global_variables