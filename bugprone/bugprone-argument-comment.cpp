// bugprone-argument-comment
// Checks that argument comments match parameter names.
// The check understands argument comments in the form /*parameter_name=*/ that are placed right before the argument.
// The check tries to detect typos and suggest automated fixes for them.

// Options
//
// StrictMode
// When zero (default value), the check will ignore leading and trailing underscores and case when comparing names – otherwise they are taken into account.

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone-argument-comment.html

#include "../include/bugprone/bugprone-argument-comment.h"
#include <iostream>

namespace bugprone {
    namespace argument_comment {
        void f(bool foo) {
            if (foo) {
                /* do something */
            }
        }

        void check() {
            std::cout << "-- check bugprone-argument-comment" << std::endl;
            f(/*bar=*/true);
        }
    } // namespace argument_comment
} // namespace bugprone