// cert-dcl50-cpp
// This check flags all function definitions (but not declarations) of C-style variadic functions.
// This check corresponds to the CERT C++ Coding Standard rule DCL50-CPP. Do not define a C-style variadic function.

// https://clang.llvm.org/extra/clang-tidy/checks/cert-dcl50-cpp.html
// https://wiki.sei.cmu.edu/confluence/display/cplusplus/DCL50-CPP.+Do+not+define+a+C-style+variadic+function

// Turn off by default!

#include <cstdarg>
#include <iostream>

namespace cert {
    namespace dcl50_cpp {

        int add(int first, int second, ...) {
            int r = first + second;
            va_list va;
            va_start(va, second);
            while (int v = va_arg(va, int)) {
                r += v;
            }
            va_end(va);
            return r;
        }

        void check() {
            std::cout << "-- check cert-dcl50-cpp" << std::endl;

            add(1, 2);
        }
    } // namespace dcl50_cpp
} // namespace cert
