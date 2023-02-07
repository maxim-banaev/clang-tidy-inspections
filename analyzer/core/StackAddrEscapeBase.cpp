#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "LocalValueEscapesScope"
namespace analyzer::core::stack_addr_escape_base {

extern "C" {
[[maybe_unused]] char const *p;

[[maybe_unused]] void test() {
  char const kStr[] = "string";
  p = kStr; // warn here!
}

[[maybe_unused]] void *test1() {
  return __builtin_alloca(12); // warn here!
}

[[maybe_unused]] void test2() {
  static int *x;
  int y;
  x = &y; // warn here!
}
}

void check() {
  std::cout << "-- check clang-analyzer-core.StackAddrEscapeBase FIXME"
            << std::endl;
}
} // namespace analyzer::core::stack_addr_escape_base
#pragma clang diagnostic pop