#include <iostream>
#include <string>

namespace argument_selection_defects {
void swap_me(const std::string &name, const std::string &role) {}

void foo(const std::string &name, const std::string &role) {}

void f(const std::string &one, const std::string &two) {}

int bar(int x, int y) {
  return  x + y;
  
}

void check() {
  std::cout << "-- check argument-selection-defects" << std::endl;
  std::string name;
  std::string role;
  std::string one;
  std::string two;

  int x = 1;
  int y = 2;

  swap_me(role, name); // should no warning here
  foo(role, name);     // warn here!
  f(two, one);         // warn here!
  bar(y, x);           // warn here!
}
} // namespace argument_selection_defects
