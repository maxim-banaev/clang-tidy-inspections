// hicpp-exception-baseclass
//
// Ensure that every value that in a throw expression is an instance of
// std::exception.
// This enforces rule 15.1 of the High Integrity C++ Coding Standard.

// https://clang.llvm.org/extra/clang-tidy/checks/hicpp/exception-baseclass.html

#include <iostream>

namespace hicpp::exception_baseclass {

class custom_exception {};
[[maybe_unused]] void throwing1() noexcept(false) {
  // Problematic throw expressions.
  throw int(42); // warn here!
}

[[maybe_unused]] void throwing2() noexcept(false) {
  // Problematic throw expressions.
  throw custom_exception(); // warn here!
}
void check() { std::cout << "-- check hicpp-exception-baseclass" << std::endl; }
} // namespace hicpp::exception_baseclass
