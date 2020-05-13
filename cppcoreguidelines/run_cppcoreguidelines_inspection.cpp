#include <narrowing-conversions.h>
#include <iostream>

int main() {
    cppcoreguidelines::narrowing_conversions::check();
    std::cout << std::endl;

    return 0;
}