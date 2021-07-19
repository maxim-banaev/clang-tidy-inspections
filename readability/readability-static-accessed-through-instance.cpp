// readability-static-accessed-through-instance
// Checks for member expressions that access static members through instances,
// and replaces them with uses of the appropriate qualified-id.

// https://clang.llvm.org/extra/clang-tidy/checks/readability-static-accessed-through-instance.html

#include <iostream>

namespace readability::static_accessed_through_instance {
struct C {
  static void foo() {}
  static int x;
};

void check() {
  std::cout << "-- check readability-static-accessed-through-instance"
            << std::endl;
  auto *c1 = new C();
  c1->foo(); // warn here!
  c1->x; // warn here!
}
} // namespace readability::static_accessed_through_instance
