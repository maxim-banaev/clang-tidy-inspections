#include <abseil-duration-addition.h>
#include <abseil-duration-comparison.h>
#include <abseil-string-find-startswith.h>
#include <iostream>

int main() {
  using namespace abseil;
  duration_addition::check();
  duration_comparison::check();
  string_find_startswith::check();

  std::cout << std::endl;

  return 0;
}
