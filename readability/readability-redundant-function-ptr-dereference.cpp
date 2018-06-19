// readability-redundant-function-ptr-dereference
// Finds redundant dereferences of a function pointer.

// https://clang.llvm.org/extra/clang-tidy/checks/readability-redundant-function-ptr-dereference.html

#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

namespace readability {
    namespace redundant_function_ptr_dereference {

        int f(int i, int j) {}
        int (*p)(int, int) = &f;
        int i = (**p)(10, 50);

        void check() {
            std::cout << "-- check readability-redundant-function-ptr-dereference" << std::endl;
        }
    } // namespace redundant_function_ptr_dereference
} // namespace readability

#pragma clang diagnostic pop
