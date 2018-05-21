// bugprone-string-integer-assignment
// The check finds assignments of an integer to std::basic_string<CharT> (std::string, std::wstring, etc.).
// The source of the problem is the following assignment operator of std::basic_string<CharT>.

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone-string-integer-assignment.html

#include <string>
#include "../include/bugprone/bugprone-string-integer-assignment.h"
#include <iostream>

namespace bugprone {
    namespace string_integer_assignment {
        void check() {
            std::cout << "-- check bugprone-string-integer-assignment" << std::endl;

            std::string s;
            int x = 5965;
            s = 6;
            s = x;
        }
    } // namespace string_integer_assignment
} // namespace bugprone