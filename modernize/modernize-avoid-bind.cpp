// modernize-avoid-bind
// The check finds uses of std::bind and replaces simple uses with lambdas.
// Lambdas will use value-capture where required.
// Right now it only handles free functions, not member functions.

// https://clang.llvm.org/extra/clang-tidy/checks/modernize-avoid-bind.html

#include <functional>
#include <iostream>

namespace modernize {
    namespace avoid_bind {
        int add(int x, int y) { return x + y; }

        void check() {
            std::cout << "-- check modernize-avoid-bind" << std::endl;

            int x = 2;
            auto clj = [=] { return add(x, 1); };;
        }
    } // avoid_bind
} // modernize
