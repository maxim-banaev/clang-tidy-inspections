// readability-container-size-empty
// Checks whether a call to the size() method can be replaced with a call to
// empty().
//
// The emptiness of a container should be checked using the empty() method
// instead of the size() method. It is not guaranteed that size() is a
// constant-time function, and it is generally more efficient and also shows
// clearer intent to use empty(). Furthermore, some containers may implement the
// empty() method but not implement the size() method. Using empty() whenever
// possible makes it easier to switch to another container in the future.

// https://clang.llvm.org/extra/clang-tidy/checks/readability/container-size-empty.html

#include <iostream>
#include <vector>

namespace readability::container_size_empty {
void check() { // NOLINT(readability-function-size)
  std::cout << "-- check readability-container-size-empty" << std::endl;

  std::vector<int> v; // NOLINT(readability-identifier-length)
  if (v.size() == 0) { // warn here!
    /**/
  }
}
} // namespace readability::container_size_empty