// bugprone-dangling-handle
//
// Detect dangling references in value handles like
// std::experimental::string_view. These dangling references can be a result of
// constructing handles from temporary values, where the temporary is destroyed
// soon after the handle is created.
//
// Options
//
// HandleClasses
// A semicolon-separated list of class names that should be treated as handles.
// By default, only std::experimental::basic_string_view is considered.
//
// https://clang.llvm.org/extra/clang-tidy/checks/bugprone/dangling-handle.html

#include <iostream>
#include <vector>

namespace bugprone::dangling_handle {
#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedValue"
#pragma clang diagnostic ignored "-Wdangling-gsl"
void check() {
  [[maybe_unused]] std::string_view View = std::string(); // warn here!
  std::string A;
  View = A + "A"; // warn here!

  std::vector<std::string_view> V;
  V.push_back(std::string()); // warn here!
  V.resize(3, std::string()); // warn here!

  std::cout << "-- check bugprone-dangling-handle [works in msvc]" << std::endl;
}
#pragma clang diagnostic pop
} // namespace bugprone::dangling_handle