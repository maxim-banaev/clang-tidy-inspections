// readability-redundant-string-init
// Finds unnecessary string initializations.

// https://clang.llvm.org/extra/clang-tidy/checks/readability-redundant-string-init.html

#include <iostream>

namespace readability {
    namespace redundant_string_init {
        void check() {
            std::cout << "-- check readability-redundant-string-init" << std::endl;

            // Initializing string with empty string literal is unnecessary.
            std::string a = "";
            std::string b("");
        }
    } // namespace redundant_string_init
} // namespace readability
