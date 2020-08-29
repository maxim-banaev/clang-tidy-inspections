// bugprone-copy-constructor-init
//
// Finds copy constructors where the constructor doesn’t call the copy
// constructor of the base class. Also finds copy constructors where the
// constructor of the base class don’t have parameter. The check also suggests a
// fix-its in some cases.
//
// https://clang.llvm.org/extra/clang-tidy/checks/bugprone-copy-constructor-init.html

#include <iostream>

namespace bugprone::copy_constructor_init {

class Copyable {
public:
  Copyable() = default;
  Copyable(const Copyable &) = default;

private:
  int a;
};

class X2 : public Copyable {
  X2(const X2 &other) {} // Should warn here! Copyable(other) is missing
};

class X4 : public Copyable {
  X4(const X4 &other) : Copyable() {} // Should warn here! other is missing
};

void check() {
  std::cout << "-- check bugprone-copy-constructor-init" << std::endl;
}
} // namespace bugprone::copy_constructor_init