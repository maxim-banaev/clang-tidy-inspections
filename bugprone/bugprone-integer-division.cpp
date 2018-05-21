// bugprone-integer-division
// Finds cases where integer division in a floating point context is likely to cause unintended loss of precision.
//
// No reports are made if divisions are part of the following expressions:
//
// - operands of operators expecting integral or bool types,
// - call expressions of integral or bool types, and
// - explicit cast expressions to integral or bool types,
//
// as these are interpreted as signs of deliberateness from the programmer.

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone-integer-division.html

#include "../include/bugprone/bugprone-integer-division.h"
#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "clang-analyzer-deadcode.DeadStores"
#pragma ide diagnostic ignored "UnusedValue"
#pragma clang diagnostic ignored "-Wunused-variable"
namespace bugprone {
    namespace integer_division {

        float floatFunc(double) { return 0; }
        int intFunc(int) { return 0; }

        void check() {

            std::cout << "-- check bugprone-integer-division" << std::endl;

            double d;
            int i = 42;

            // Warn, floating-point values expected.
            d = 32 * 8 / (2 + i);
            d = 8 * floatFunc(1 + 7 / 2);
            d = i / (1 << 4);

            // OK, no integer division.
            d = 32 * 8.0 / (2 + i);
            d = 8 * floatFunc(1 + 7.0 / 2);
            d = static_cast<double>(i) / (1 << 4); // NOLINT(hicpp-signed-bitwise)

            // OK, there are signs of deliberateness.
            d = 1 << (i / 2); // NOLINT(hicpp-signed-bitwise)
            d = 9 + intFunc(6 * i / 32);
        }
    } // namespace integer_division
} // namespace bugprone
#pragma clang diagnostic pop