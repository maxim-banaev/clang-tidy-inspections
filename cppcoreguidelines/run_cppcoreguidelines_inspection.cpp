#include <avoid-non-const-global-variables.h>
#include <narrowing-conversions.h>
#include <iostream>

int main() {
    cppcoreguidelines::avoid_non_const_global_variables::check();
    cppcoreguidelines::narrowing_conversions::check();
    std::cout << std::endl;

    return 0;
}