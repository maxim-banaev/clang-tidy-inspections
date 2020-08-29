// bugprone-integer-division
// Finds cases where integer division in a floating point context is likely to
// cause unintended loss of precision.
//
// No reports are made if divisions are part of the following expressions:
//
// - operands of operators expecting integral or bool types,
// - call expressions of integral or bool types, and
// - explicit cast expressions to integral or bool types,
//
// as these are interpreted as signs of deliberateness from the programmer.

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone-integer-division.html

#include <iostream>

namespace bugprone::integer_division {

float floatFunc(double) { return 0; }

void check() {
  std::cout << "-- check bugprone-integer-division" << std::endl;

  double d;
  int i = 42;

  d = 32 * 8 / (2 + i); // should warn here
  d = 8 * floatFunc(1 + 7 / 2); // should warn here
  d = i / (1 << 4); // should warn here
}
} // namespace bugprone::integer_division