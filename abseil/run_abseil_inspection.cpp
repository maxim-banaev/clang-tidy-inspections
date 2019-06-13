#include <abseil-duration-addition.h>
#include <abseil-string-find-startswith.h>
#include <iostream>

int main() {
  abseil::duration_addition::check();
  abseil::string_find_startswith::check();
  std::cout << std::endl;

  return 0;
}
