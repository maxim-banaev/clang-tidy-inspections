// misc-throw-by-value-catch-by-reference
//
// Finds violations of the rule “Throw by value, catch by reference” presented
// for example in “C++ Coding Standards” by H. Sutter and A. Alexandrescu,
// as well as the CERT C++ Coding Standard rule ERR61-CPP. Catch exceptions
// by lvalue reference.
//
// https://clang.llvm.org/extra/clang-tidy/checks/misc/throw-by-value-catch-by-reference.html

#include <iostream>

namespace misc::throw_by_value_catch_by_reference {
struct S : std::exception {
  [[nodiscard]] const char *what() const noexcept override {
    return "My custom exception";
  }
};
void check() {

  try {
    throw S();
  } catch (std::exception e) { // warn here!
  }

  std::cout << "-- check misc-throw-by-value-catch-by-reference" << std::endl;
}
} // namespace misc::throw_by_value_catch_by_reference