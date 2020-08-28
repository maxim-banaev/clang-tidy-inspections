// misc-unconventional-assign-operator
//
// Finds declarations of assign operators with the wrong return and/or argument
// types and definitions with good return type but wrong return statements.
//
// The return type must be Class&.
// Works with move-assign and assign by value.
// Private and deleted operators are ignored.
// The operator must always return *this.
//
// https://clang.llvm.org/extra/clang-tidy/checks/misc-unconventional-assign-operator.html

#include <iostream>

namespace misc::unconventional_assign_operator {

class foo {
  int operator=(foo &f) { return 0; } // should warn here
};
void check() {
  std::cout << "-- check misc-unconventional-assign-operator" << std::endl;
}
} // namespace misc::unconventional_assign_operator