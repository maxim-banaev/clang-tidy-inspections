// modernize-avoid-bind
// The check finds uses of std::bind and replaces simple uses with lambdas.
// Lambdas will use value-capture where required.
// Right now it only handles free functions, not member functions.

// https://clang.llvm.org/extra/clang-tidy/checks/modernize/avoid-bind.html

#ifdef __clang__
#include <functional>
#endif
#include <iostream>

namespace modernize::avoid_bind {
int add(int x, int y) { return x + y; } // NOLINT(modernize-use-trailing-return-type)

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedValue"
void check() {
  std::cout << "-- check modernize-avoid-bind" << std::endl;

  [[maybe_unused]] int x = 2;

#ifdef __clang__
  [[maybe_unused]] auto clj = std::bind(add, x); // warn here!
#endif
}
#pragma clang diagnostic pop
} // namespace modernize::avoid_bind
