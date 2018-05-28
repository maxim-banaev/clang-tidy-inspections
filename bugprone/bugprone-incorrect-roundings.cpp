// bugprone-incorrect-roundings
// Checks the usage of patterns known to produce incorrect rounding.
// Programmers often round the double expression to an integer.

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone-incorrect-roundings.html

#include <iostream>

namespace  bugprone {
    namespace incorrect_rounding {
        void check() {
            std::cout << "-- check bugprone-incorrect-roundings" << std::endl;
            auto a = static_cast<int>(1.00000000001 + 0.5);
            if ( a < 1.5 ) { /* do nothing*/}
        }
    } // namespace incorrect_rounding
} // namespace bugprone
