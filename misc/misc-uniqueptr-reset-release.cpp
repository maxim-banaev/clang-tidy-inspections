// misc-uniqueptr-reset-release
//
// Find and replace unique_ptr::reset(release()) with std::move().
//
// https://clang.llvm.org/extra/clang-tidy/checks/misc-uniqueptr-reset-release.html

#include <iostream>
#include <memory>

namespace misc::uniqueptr_reset_release {

class Foo {};

void check() {
  std::unique_ptr<Foo> x, y;
  x.reset(y.release()); // should warn here
  std::cout << "-- check misc-uniqueptr-reset-release" << std::endl;
}
} // namespace misc::uniqueptr_reset_release