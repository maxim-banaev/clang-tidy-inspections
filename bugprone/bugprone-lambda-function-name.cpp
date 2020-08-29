// bugprone-lambda-function-name
//
// Checks for attempts to get the name of a function from within a lambda
// expression. The name of a lambda is always something like operator(), which
// is almost never what was intended.
//
// https://clang.llvm.org/extra/clang-tidy/checks/bugprone-lambda-function-name.html

#include <iostream>

namespace bugprone::lambda_function_name {
void check() {
  std::cout << "-- check bugprone-lambda-function-name" << std::endl;

  [] {
    printf("Called from %s\n", __func__); // should warn here
  }(); // NOLINT(cppcoreguidelines-pro-type-vararg)
  [] {
    printf("Now called from %s\n", __FUNCTION__); // should warn here
  }(); // NOLINT(cppcoreguidelines-pro-type-vararg)
}
} // namespace bugprone::lambda_function_name