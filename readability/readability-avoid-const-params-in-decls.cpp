// readability-avoid-const-params-in-decls
// Checks whether a function declaration has parameters that are top level const.
// const values in declarations do not affect the signature of a function, so they should not be put there.

// https://clang.llvm.org/extra/clang-tidy/checks/readability-avoid-const-params-in-decls.html

#include <iostream>

namespace readability {
    namespace avoid_const_params_in_decls {
        void f(const std::string);   // Bad: const is top level.
        void f(const std::string&);  // Good: const is not top level.

        void check(){
            std::cout << "-- check readability-avoid-const-params-in-decls" << std::endl;
        }
    } // namespace avoid_const_params_in_decls
} // namespace readability