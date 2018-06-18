// readability-function-size
// google-readability-function-size redirects here as an alias for this check.
//
// Checks for large functions based on various metrics.

// Options
//
// LineThreshold
// Flag functions exceeding this number of lines. The default is -1 (ignore the number of lines).
//
// StatementThreshold
// Flag functions exceeding this number of statements. This may differ significantly from the number of lines for
// macro-heavy code. The default is 800.
//
// BranchThreshold
// Flag functions exceeding this number of control statements. The default is -1 (ignore the number of branches).
//
// ParameterThreshold
// Flag functions that exceed a specified number of parameters. The default is -1 (ignore the number of parameters).
//
// NestingThreshold
// Flag compound statements which create next nesting level after NestingThreshold. This may differ significantly
// from the expected value for macro-heavy code. The default is -1 (ignore the nesting level).
//
// VariableThreshold
// Flag functions exceeding this number of variables declared in the body. The default is -1
// (ignore the number of variables). Please note that function parameters and variables declared in lambdas,
// GNU Statement Expressions, and nested class inline functions are not counted.

// https://clang.llvm.org/extra/clang-tidy/checks/readability-function-size.html

#include <iostream>

namespace readability {
    namespace readability_function_size {
        void check() {
            std::cout << "-- check readability-function-size turn off by default" << std::endl;
        }
    } // namespace readability_function_size
} // namespace readability
