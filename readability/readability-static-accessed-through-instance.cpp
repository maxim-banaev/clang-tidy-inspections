// readability-static-accessed-through-instance
// Checks for member expressions that access static members through instances,
// and replaces them with uses of the appropriate qualified-id.

// https://clang.llvm.org/extra/clang-tidy/checks/readability/static-accessed-through-instance.html

#include <iostream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-value"
#pragma ide diagnostic ignored "readability-identifier-length"

namespace readability::static_accessed_through_instance {
struct C {
  static void foo() {}
  static int x;
};

void check() { // NOLINT(readability-function-size)
  std::cout << "-- check readability-static-accessed-through-instance"
            << std::endl;
  auto *c1 = new C();
  c1->foo(); // warn here!
  c1->x;     // warn here!
}
} // namespace readability::static_accessed_through_instance

#pragma clang diagnostic pop