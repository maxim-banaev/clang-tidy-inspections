#include <avoid-non-const-global-variables.h>
#include <iostream>
#include <narrowing-conversions.h>

int main() {
  cppcoreguidelines::avoid_non_const_global_variables::check();
  cppcoreguidelines::narrowing_conversions::check();
  std::cout << std::endl;

  return 0;
}