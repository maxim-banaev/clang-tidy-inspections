// zircon-temporary-objects
//
// Warns on construction of specific temporary objects in the Zircon kernel.
// If the object should be flagged, If the object should be flagged, the fully
// qualified type name must be explicitly passed to the check.
//
// Options
//
// Names
// A semi-colon-separated list of fully-qualified names of C++ classes that
// should not be constructed as temporaries. Default is empty.
//
// https://clang.llvm.org/extra/clang-tidy/checks/zircon-temporary-objects.html

#include <iostream>

namespace zircon::temporary_objects {

struct X {};
void func(X x) {}

void check() {
  X();
  X F = X();
  func(X());

  std::cout << "-- check zircon-temporary-objects [turn off by default]"
            << std::endl;
  // TODO Fix check
}
} // namespace zircon::temporary_objects