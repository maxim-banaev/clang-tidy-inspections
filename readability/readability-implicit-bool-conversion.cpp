// readability-implicit-bool-conversion
// This check can be used to find implicit conversions between built-in types
// and booleans. Depending on use case, it may simply help with readability of
// the code, or in some cases, point to potential bugs which remain unnoticed
// due to implicit conversions.

// https://clang.llvm.org/extra/clang-tidy/checks/readability/implicit-bool-conversion.html

#include <iostream>

namespace readability::implicit_bool_conversion {

class Foo {
  int m_foo;

public:
  [[maybe_unused]] void setFoo(bool foo) {
    m_foo = foo; // warning: implicit conversion bool -> int
  }
  int getFoo() const { return m_foo; }
};

void use(Foo &foo) {
  [[maybe_unused]] bool value =
      foo.getFoo(); // warning: implicit conversion int -> bool
}

void check() {
  std::cout
      << "-- check readability-implicit-bool-conversion [turn off by default]"
      << std::endl;
}
} // namespace readability::implicit_bool_conversion
