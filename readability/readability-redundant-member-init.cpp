// readability-redundant-member-init
// Finds member initializations that are unnecessary because the same default
// constructor would be called if they were not present.

// https://clang.llvm.org/extra/clang-tidy/checks/readability-redundant-member-init.html

#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedStructInspection"

namespace readability::redundant_member_init {
// Explicitly initializing the member s is unnecessary.
class Foo {
public:
  Foo() : s() {}

private:
  std::string s;
};

void check() {
  std::cout << "-- check readability-redundant-member-init [turn off by default]"
            << std::endl;
}
} // namespace readability

#pragma clang diagnostic pop