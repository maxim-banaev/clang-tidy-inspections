// bugprone-inaccurate-erase
// Checks for inaccurate use of the erase() method.
//
// Algorithms like remove() do not actually remove any element from the container but return an iterator to the
// first redundant element at the end of the container.
// These redundant elements must be removed using the erase() method.
// This check warns when not all of the elements will be removed due to using an inappropriate overload.

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone-inaccurate-erase.html

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#pragma ide diagnostic ignored "fuchsia-default-arguments"

#include "../include/bugprone/bugprone-inaccurate-erase.h"
#include <iostream>
#include <vector>

#define ERASE(x, y) x.erase(remove(x.begin(), x.end(), y))

namespace bugprone {
    namespace inaccurate_erase {
        void check() {
            std::cout << "-- check bugprone-inaccurate-erase FIXME" << std::endl;

            std::vector<int> v = {10, 20, 30, 30, 20, 10, 10, 20};
            //ERASE(v, 15);
        }
    } // namespace inaccurate_erase
} // namespace bugprone

#pragma clang diagnostic pop