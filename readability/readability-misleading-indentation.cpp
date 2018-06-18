// readability-misleading-indentation
// Correct indentation helps to understand code. Mismatch of the syntactical structure and the indentation of the code
// may hide serious problems. Missing braces can also make it significantly harder to read the code, therefore it is
// important to use braces.
//
// The way to avoid dangling else is to always check that an else belongs to the if that begins in the same column.
//
// You can omit braces when your inner part of e.g. an if statement has only one statement in it.
// Although in that case you should begin the next statement in the same column with the if.

// https://clang.llvm.org/extra/clang-tidy/checks/readability-misleading-indentation.html

#include <iostream>
#include <random>
#include <ctime>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc30-c"

namespace readability {
    namespace misleading_indentation {
        void foo1() {}
        void foo2() {}

        void check() {
            std::cout << "-- check misleading_indentation" << std::endl;

            srand(static_cast<unsigned int>(time(nullptr)));

            bool cond1 = rand() % 2 == 0;
            bool cond2 = rand() % 2 == 0;

            // Dangling else:
            if (cond1)
                if (cond2)
                    foo1();
            else
                foo2();  // Wrong indentation: else belongs to if(cond2) statement.

            // Missing braces:
            if (cond1)
                foo1();
                foo2();  // Not guarded by if(cond1).
        }
    } // namespace misleading_indentation
} // namespace readability

#pragma clang diagnostic pop
