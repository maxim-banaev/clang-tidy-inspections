// readability-redundant-declaration
// Finds redundant variable and function declarations.
// Such redundant declarations can be removed without changing program behaviour.
// They can for instance be unintentional left overs from previous refactorings when code has been moved around.
// Having redundant declarations could in worst case mean that there are typos in the code that cause bugs.
//
// Normally the code can be automatically fixed, clang-tidy can remove the second declaration.
// However there are 2 cases when you need to fix the code manually:
//
// When the declarations are in different header files;
// When multiple variables are declared together.
// Options
//
// IgnoreMacros
// If set to non-zero, the check will not give warnings inside macros. Default is 1.

// https://clang.llvm.org/extra/clang-tidy/checks/readability-redundant-declaration.html

#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

namespace readability {
    namespace redundant_declaration {

        extern int X;
        extern int X;

        #define DECLARE(Y) extern int Y
        #define DEFINE(Y) extern int (Y); int (Y) = 42
        DECLARE(test);
        DEFINE(test);

        void check() {
            std::cout << "-- check readability-redundant-declaration" << std::endl;
        }
    } // namespace redundant_declaration
} // namespace readability

#pragma clang diagnostic pop