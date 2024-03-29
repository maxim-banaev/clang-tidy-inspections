// bugprone-forwarding-reference-overload
// The check looks for perfect forwarding constructors that can hide copy or
// move constructors. If a non const lvalue reference is passed to the
// constructor, the forwarding reference parameter will be a better match than
// the const reference parameter of the copy constructor, so the perfect
// forwarding constructor will be called, which can be confusing. For detailed
// description of this issue see: Scott Meyers, Effective Modern C++, Item 26.

// The check warns for constructors C1 and C2, because those can hide copy and
// move constructors. We suppress warnings if the copy and the move constructors
// are both disabled (deleted or private), because there is nothing the perfect
// forwarding constructor could hide in this case. We also suppress warnings for
// constructors like C3 that are guarded with an enable_if, assuming the
// programmer was aware of the possible hiding.
//
// Background
//
// For deciding whether a constructor is guarded with enable_if, we consider the
// default values of the type parameters and the types of the constructor
// parameters. If any part of these types is std::enable_if or std::enable_if_t,
// we assume the constructor is guarded.

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone/forwarding-reference-overload.html

#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#pragma ide diagnostic ignored "fuchsia-default-arguments"
#pragma ide diagnostic ignored "misc-unused-parameters"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "cppcoreguidelines-special-member-functions"
#pragma ide diagnostic ignored "hicpp-special-member-functions"

namespace bugprone::forwarding_reference_overload {
class Person {
public:
  // C1: perfect forwarding ctor
  template <typename T> explicit Person([[maybe_unused]] T &&n) {} // warn here!

  // C2: perfect forwarding ctor with parameter default value
  template <typename T>
  explicit Person([[maybe_unused]] T &&n, [[maybe_unused]] int x = 1) { // warn here!
  }

  // (possibly compiler generated) copy ctor
  Person(const Person &rhs) = default;
};

void check() {
  std::cout << "-- check bugprone-forwarding-reference-overload" << std::endl;
}
} // namespace bugprone::forwarding_reference_overload

#pragma clang diagnostic pop