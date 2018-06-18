// readability-misplaced-array-index
// This check warns for unusual array index syntax.

// https://clang.llvm.org/extra/clang-tidy/checks/readability-misplaced-array-index.html

#include <iostream>

namespace readability {
    namespace misplaced_array_index {

        void f(int *X, int Y) {
            Y[X] = 0;
        }

        void check() {
            std::cout << "-- check readability-misplaced-array-index" << std::endl;

            auto * x = new int[1];
            int y = 0;

            f(x, y);
        }
    } // namespace misplaced_array_index
} // namespace readability