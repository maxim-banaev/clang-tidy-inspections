#include <iostream>
#include <string>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
namespace clion::method_can_be_static {
class Foo {
  int i;
  static char p;

public:
  char getP() { return p; } // warn here!

  int getI() const { return i; } // warn here!

  void bar() {
    // do something
  }
};

void check() {
  std::cout << "-- check method-can-be-static" << std::endl;

  Foo f{};
}
} // namespace clion::method_can_be_static

#pragma clang diagnostic pop