#include <iostream>

// Turn off by default!

namespace cppcoreguidelines::avoid_non_const_global_variables {
    int nonConstInt = 0;
    int &nonConstIntReference = nonConstInt;
    int *pointerToNonConstInt = &nonConstInt;
    
    void check() {
        std::cout << "-- check avoid-non-const-global-variables" << std::endl;

    }
} // namespace cppcoreguidelines::avoid_non_const_global_variables