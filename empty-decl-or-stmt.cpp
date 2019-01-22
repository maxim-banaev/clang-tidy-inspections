#include <iostream>
#include <string>

namespace argument_selection_defects {

    struct foo {
        int x;; // should warn here https://youtrack.jetbrains.com/issue/CPP-14953
    public:
        explicit foo(int x) : x(x) {

        }; // should warn here https://youtrack.jetbrains.com/issue/CPP-14953
    };; // should warn here

    void check() {
        std::cout << "-- check empty-decl-or-stmt" << std::endl;; // should warn here
    }; // should warn here
} // namespace argument_selection_defects

