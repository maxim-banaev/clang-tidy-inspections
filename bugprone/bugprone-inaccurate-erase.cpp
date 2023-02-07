// bugprone-inaccurate-erase
// Checks for inaccurate use of the erase() method.
//
// Algorithms like remove() do not actually remove any element from the
// container but return an iterator to the first redundant element at the end of
// the container. These redundant elements must be removed using the erase()
// method. This check warns when not all the elements will be removed due to
// using an inappropriate overload.

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone/inaccurate-erase.html

#include <iostream>
#include <memory>
#include <vector>

namespace bugprone::inaccurate_erase {
void check() {
  std::cout << "-- check bugprone-inaccurate-erase" << std::endl;

  std::vector<std::unique_ptr<int>> vupi;
  auto iter = vupi.begin();
  vupi.erase(iter++);
}
} // namespace bugprone::inaccurate_erase