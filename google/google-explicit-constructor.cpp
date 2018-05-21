// google-explicit-constructor
// Checks that constructors callable with a single argument and conversion operators are marked explicit to avoid
// the risk of unintentional implicit conversions.

// https://clang.llvm.org/extra/clang-tidy/checks/google-explicit-constructor.html

#include "../include/google/google-explicit-constructor.h"
#include <iostream>

namespace google {
    namespace explicit_constructor {
        struct S {
            int x;

            S(int x) : x(x) {}

            operator bool() const { return true; }

            int getX() const {
                return x;
            }
        };

        void check() {
            std::cout << "-- check google-explicit-constructor" << std::endl;

            S a{1};
            S b{2};
            if (a == b) {
                a.getX();
            }
        }
    } // namespace explicit_constructor
} // namespace google