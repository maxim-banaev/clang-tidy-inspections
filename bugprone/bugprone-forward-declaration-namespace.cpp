// bugprone-forward-declaration-namespace
// Checks if an unused forward declaration is in a wrong namespace.
//
// The check inspects all unused forward declarations and checks if there is any
// declaration/definition with the same name existing, which could indicate that
// the forward declaration is in a potentially wrong namespace. This check can
// only generate warnings, but it can’t suggest a fix at this point.

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone/forward-declaration-namespace.html

#include <iostream>

namespace bugprone::forward_declaration_namespace {

namespace na {
struct A; // warn here!
}

namespace nb {
struct A {};
} // namespace nb

void check() {
  std::cout << "-- check bugprone-forward-declaration-namespace" << std::endl;
  [[maybe_unused]] nb::A a;
  // warning : no definition found for 'A', but a definition with the same name
  // 'A' found in another namespace 'nb::'
}
} // namespace bugprone::forward_declaration_namespace