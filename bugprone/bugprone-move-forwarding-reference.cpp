// bugprone-move-forwarding-reference
// Warns if std::move is called on a forwarding reference.
//
// Forwarding references should typically be passed to std::forward instead of
// std::move, and this is the fix that will be suggested. (A forwarding
// reference is an rvalue reference of a type that is a deduced function
// template argument.)

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone-move-forwarding-reference.html

#include <iostream>

namespace bugprone::move_forwarding_reference {
template <typename T> void bar(T && /*t*/) { /* Do nothing*/ }

template <typename T> void foo(T &&t) { bar(std::move(t)); } // should warn here

void check() {
  std::cout << "-- check bugprone-move-forwarding-reference" << std::endl;
  foo<std::string>("Hello");
}
} // namespace bugprone::move_forwarding_reference
