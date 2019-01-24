// modernize-avoid-bind
// The check finds uses of std::bind and replaces simple uses with lambdas.
// Lambdas will use value-capture where required.
// Right now it only handles free functions, not member functions.

// https://clang.llvm.org/extra/clang-tidy/checks/modernize-avoid-bind.html

#include <functional>
#include <iostream>

namespace modernize::avoid_bind {
int add(int x, int y) { return x + y; }

void check() {
  std::cout << "-- check modernize-avoid-bind" << std::endl;

  int x = 2;
#ifdef __clang__
  auto clj = std::bind(add, x);
#endif
}
} // namespace modernize::avoid_bind
