// bugprone-dangling-handle
// Detect dangling references in value handles like
// std::experimental::string_view. These dangling references can be a result of
// constructing handles from temporary values, where the temporary is destroyed
// soon after the handle is created.

// Options
//
// HandleClasses
// A semicolon-separated list of class names that should be treated as handles.
// By default only std::experimental::basic_string_view is considered.

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone-dangling-handle.html

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedValue"
#pragma clang diagnostic ignored "-Wunused-variable"

#include <iostream>
#include <vector>

namespace bugprone::dangling_handle {
void check() {
  std::string_view View = std::string(); // View will dangle.
  std::string A;
  View = A + "A"; // still dangle.

  std::vector<std::string_view> V;
  V.push_back(std::string()); // V[0] is dangling.
  V.resize(3, std::string()); // V[1] and V[2] will also dangle.

  std::cout << "-- check bugprone-dangling-handle FIXME" << std::endl;
}
} // namespace bugprone::dangling_handle

#pragma clang diagnostic pop