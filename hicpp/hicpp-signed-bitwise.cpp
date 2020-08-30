// hicpp-signed-bitwise
//
// Finds uses of bitwise operations on signed integer types, which may lead to
// undefined or implementation defined behaviour.
//
// The according rule is defined in the High Integrity C++ Standard,
// Section 5.6.1.
//
// Options
//
// IgnorePositiveIntegerLiterals
// If this option is set to true, the check will not warn on bitwise operations
// with positive integer literals, e.g. ~0, 2 << 1, etc. Default value is false.
//
// https://clang.llvm.org/extra/clang-tidy/checks/hicpp-signed-bitwise.html

#include <iostream>

namespace hicpp::signed_bitwise {
void check() {
  std::cout << "-- check hicpp-signed-bitwise" << std::endl;

  int SValue = 42;
  int SResult;
  SResult = SValue & 1; // should warn here
}
} // namespace hicpp::signed_bitwise