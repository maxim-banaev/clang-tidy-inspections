// google-default-arguments
// Checks that default arguments are not given for virtual methods.
// See https://google.github.io/styleguide/cppguide.html#Default_Arguments

// https://clang.llvm.org/extra/clang-tidy/checks/google-default-arguments.html

#include <iostream>

namespace google::default_arguments {
struct X {
  virtual void foo(int x = 1){}; // should warn here
};
void check() { std::cout << "-- check google-default-arguments" << std::endl; }
} // namespace google::default_arguments