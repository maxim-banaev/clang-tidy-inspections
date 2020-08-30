// bugprone-bool-pointer-implicit-conversion
//
// Checks for conditions based on implicit conversion from a bool pointer to
// bool.
//
//  https://clang.llvm.org/extra/clang-tidy/checks/bugprone-bool-pointer-implicit-conversion.html

// Turn off by default!
#include <iostream>

namespace bugprone::bool_pointer_implicit_conversion {
void check() {
  std::cout << "-- check bugprone-bool-pointer-implicit-conversion [turn off by default]"
            << std::endl;

  bool *p;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wuninitialized"
  if (p) { /* Never used in a pointer-specific way. */
  }
#pragma clang diagnostic pop
}
} // namespace bugprone::bool_pointer_implicit_conversion