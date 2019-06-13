#include <iostream>

namespace analyzer::core::stack_addr_escape_base {

extern "C" {
char const *p;

void test() {
  char const kStr[] = "string";
  p = kStr; // warn
}

void *test1() {
  return __builtin_alloca(12); // warn
}

void test2() {
  static int *x;
  int y;
  x = &y; // warn
}
}

void check() {
  std::cout << "-- check clang-analyzer-core.StackAddrEscapeBase"
            << std::endl;
}
}