// readability-named-parameter
// Find functions with unnamed arguments.
//
// The check implements the following rule originating in the Google C++ Style
// Guide:
//
// https://google.github.io/styleguide/cppguide.html#Function_Declarations_and_Definitions
//
// All parameters should be named, with identical names in the declaration and
// implementation.
//
// Corresponding cpplint.py check name: readability/function.

// https://clang.llvm.org/extra/clang-tidy/checks/readability-named-parameter.html

#include <iostream>

namespace readability::named_parameter {
void check() {
  std::cout << "-- check readability-named-parameter [turn off by default]"
            << std::endl;
}
} // namespace readability
