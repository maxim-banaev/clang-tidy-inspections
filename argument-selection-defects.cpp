#include <iostream>
#include <string>

namespace argument_selection_defects {
void swap_me(const std::string &name, const std::string &role) {}

void foo(const std::string &name, const std::string &role) {}

void f(const std::string &one, const std::string &two) {}

void bar(int x, int y) {}

void check() {
  std::cout << "-- check argument-selection-defects" << std::endl;
  std::string name, role, one, two;

  int x = 1, y = 2;

  swap_me(role, name); // should no warning here
  foo(role, name);     // warn here!
  f(two, one);         // warn here!
  bar(y, x);           // warn here!
}
} // namespace argument_selection_defects
