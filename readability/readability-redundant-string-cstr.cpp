// readability-redundant-string-cstr
// Finds unnecessary calls to std::string::c_str() and std::string::data().

// https://clang.llvm.org/extra/clang-tidy/checks/readability-redundant-string-cstr.html

#include <cstring>
#include <string>
#include <iostream>

namespace readability {
    namespace redundant_string_cstr {
        void check() {
            std::cout << "-- check readability-redundant-string-cstr" << std::endl;

            std::string str("Please split this sentence into tokens");

            auto *cstr = new char[str.length() + 1];
            std::strcpy(cstr, str.c_str());

            // cstr now contains a c-string copy of str

            char *p = std::strtok(cstr, " ");
            while (p != nullptr) {
                p = std::strtok(nullptr, " ");
            }

            delete[] cstr;
        }
    } // namespace redundant_string_cstr
} // namespace readability
