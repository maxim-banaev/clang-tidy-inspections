// readability-convert-member-functions-to-static
//
// Finds non-static member functions that can be made static because the
// functions don’t use this.
//
// After applying modifications as suggested by the check, running the check
// again might find more opportunities to mark member functions static.
//
// After making a member function static, you might want to run the check
// readability-static-accessed-through-instance to replace calls like
// Instance.method() by Class::method().

// https://clang.llvm.org/extra/clang-tidy/checks/readability-convert-member-functions-to-static.html

#include <iostream>

namespace readability::convert_member_functions_to_static {
class Foo {
  int i;
  static char p;

public:
  [[maybe_unused]] char getP() { return p; } // warn here!

  [[maybe_unused]] int getI() const { return i; } // do not warn here!

  int bar() { // warn here!
    return 0;
  }
};

void check() { std::cout << "-- check method-can-be-static" << std::endl; }
} // namespace readability::convert_member_functions_to_static