// fuchsia-default-arguments-calls
//
// Warns if a function or method is called with default arguments.
//
// https://clang.llvm.org/extra/clang-tidy/checks/fuchsia-default-arguments-calls.html

// Turn off by default!

#include <iostream>

namespace fuchsia::default_arguments_calls {
int foo(int value = 5) { return value; }
void check() {
  std::cout << "-- check fuchsia-default-arguments-calls [turn off by default]"
            << std::endl;

  foo(); // should be warn here
}
} // namespace fuchsia::default_arguments_calls
