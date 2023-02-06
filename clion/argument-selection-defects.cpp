#include <iostream>
#include <string>

namespace clion::argument_selection_defects {
void swap_me([[maybe_unused]] const std::string &name,
             [[maybe_unused]] const std::string &role) {}

void foo([[maybe_unused]] const std::string &name,
         [[maybe_unused]] const std::string &role) {}

void f([[maybe_unused]] const std::string &one,
       [[maybe_unused]] const std::string &two) {}

int bar(int x, int y) { return x + y; }

void check() {
  std::cout << "-- check argument-selection-defects" << std::endl;
  std::string name, role, one, two;

  int x = 1, y = 2;

  swap_me(role, name); // should no warning here
  foo(role, name);     // warn here!
  f(two, one);         // warn here!
  bar(y, x);           // warn here!
}
} // namespace clion::argument_selection_defects
