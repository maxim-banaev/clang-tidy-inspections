#include <iostream>
#include <string>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
namespace method_can_be_static {
class Foo {
  int i;
  static char p;

public:
  char getP() { return p; }

  int getI() const { return i; }

  void bar() {
    // do something
  }
};

void check() {
  std::cout << "-- check method-can-be-static" << std::endl;

  Foo f{};
}
} // namespace method_can_be_static

#pragma clang diagnostic pop