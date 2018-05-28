// bugprone-string-constructor
// Finds string constructors that are suspicious and probably errors.
//
// - A common mistake is to swap parameters to the ‘fill’ string-constructor.
// - Calling the string-literal constructor with a length bigger than the literal is suspicious and adds extra
// random characters to the string.
// - Creating an empty string from constructors with parameters is considered suspicious.
// The programmer should use the empty constructor instead.

// Options
//
// WarnOnLargeLength
// When non-zero, the check will warn on a string with a length greater than LargeLengthThreshold. Default is 1.
//
// LargeLengthThreshold
// An integer specifying the large length threshold. Default is 0x800000.

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone-string-constructor.html

#include <iostream>

namespace bugprone {
    namespace string_constructor {
        void check() {
            std::cout << "-- check bugprone-string-constructor" << std::endl;

            std::string str('x', 50); // should be str(50, 'x')

            std::string("test", 200);   // Will include random characters after "test".

            std::string("test", 0);   // Creation of an empty string.
        }
    } // namespace string_constructor
} // namespace bugprone