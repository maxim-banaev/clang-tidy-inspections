// modernize-redundant-void-arg
// Find and remove redundant void argument lists.

// https://clang.llvm.org/extra/clang-tidy/checks/modernize-redundant-void-arg.html

#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

namespace modernize {
    namespace redundant_void_arg {
        int f(void);
        int (*fu(void))(void);
        typedef int (*f_t(void))(void);

//        class C {
//
//         public:
//            C(void);
//            ~C(void);
//        };
//
//        void (C::*p)(void);
//        C::C(void) {}
//        C::~C(void) {}

        void check(){
            std::cout << "-- check modernize-redundant-void-arg" << std::endl;
        }
    } // redundant_void_arg
} // modernize

#pragma clang diagnostic pop