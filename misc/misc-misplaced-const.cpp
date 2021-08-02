// misc-misplaced-const
//
// This check diagnoses when a const qualifier is applied to a typedef/ using to
// a pointer type rather than to the
// pointee, because such constructs are often misleading to developers because
// the const applies to the pointer rather
// than the pointee.
//
// For instance, in the following code, the resulting type is int * const rather
// than const int *:

// https://clang.llvm.org/extra/clang-tidy/checks/misc-misplaced-const.html

#include <iostream>

namespace misc::misplaced_const {
typedef int *int_ptr;

void f(const int_ptr ptr) { // should warn here
  *ptr = 0; // potentially quite unexpectedly the int can be modified here
}

void check() { std::cout << "-- check misc-misplaced-const" << std::endl; }
} // namespace misc::misplaced_const
