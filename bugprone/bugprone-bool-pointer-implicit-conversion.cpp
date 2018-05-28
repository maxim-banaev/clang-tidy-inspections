// bugprone-bool-pointer-implicit-conversion
// Checks for conditions based on implicit conversion from a bool pointer to bool.

//  https://clang.llvm.org/extra/clang-tidy/checks/bugprone-bool-pointer-implicit-conversion.html

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wuninitialized"
#pragma ide diagnostic ignored "clang-analyzer-core.uninitialized.Branch"
#pragma ide diagnostic ignored "readability-implicit-bool-conversion"

#include <iostream>

namespace bugprone {
    namespace bool_pointer_implicit_conversion {
        void check() {
            std::cout << "-- check bugprone-bool-pointer-implicit-conversion" << std::endl;

            bool *p;
            if (p) { /* Never used in a pointer-specific way. */ }
        }
    } // namespace bool_pointer_implicit_conversion
} // namespace bugprone

#pragma clang diagnostic pop