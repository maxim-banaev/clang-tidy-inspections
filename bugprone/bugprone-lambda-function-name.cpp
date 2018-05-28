// bugprone-lambda-function-name
// Checks for attempts to get the name of a function from within a lambda expression.
// The name of a lambda is always something like operator(), which is almost never what was intended.

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone-lambda-function-name.html

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-pro-bounds-array-to-pointer-decay"

#include <iostream>

namespace bugprone {
    namespace lambda_function_name {
        void check() {

            std::cout << "-- check bugprone-lambda-function-name" << std::endl;

            [] { printf("Called from %s\n", __func__); }(); // NOLINT(cppcoreguidelines-pro-type-vararg)
            [] { printf("Now called from %s\n", __FUNCTION__); }(); // NOLINT(cppcoreguidelines-pro-type-vararg)
        }
    } // namespace lambda_function_name
} // namespace bugprone

#pragma clang diagnostic pop