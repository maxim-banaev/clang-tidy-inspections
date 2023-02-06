// google-explicit-constructor
// Checks that constructors callable with a single argument and conversion
// operators are marked explicit to avoid the risk of unintentional implicit
// conversions.

// https://clang.llvm.org/extra/clang-tidy/checks/google/explicit-constructor.html

#include <iostream>

namespace google::explicit_constructor {
struct S {
  int x;

  S(int x) : x(x) {} // warn here!

  operator bool() const { return true; } // warn here!

  int getX() const { return x; }
};

void check() {
  std::cout << "-- check google-explicit-constructor" << std::endl;

  S a{1};
  S b{2};
  if (a == b) {
    a.getX();
  }
}
} // namespace google::explicit_constructor