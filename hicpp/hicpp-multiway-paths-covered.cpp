// hicpp-multiway-paths-covered
//
// This check discovers situations where code paths are not fully-covered.
// It furthermore suggests using if instead of switch if the code will be more
// clear. The rule 6.1.2 and rule 6.1.4 of the High Integrity C++ Coding
// Standard are enforced.
//
// if-else if chains that miss a final else branch might lead to unexpected
// program execution and be the result of a logical error. If the missing else
// branch is intended you can leave it empty with a clarifying comment. This
// warning can be noisy on some code bases, so it is disabled by default.
//
// Options
//
// WarnOnMissingElse
// Boolean flag that activates a warning for missing else branches. Default is
// 0.
//
// https://clang.llvm.org/extra/clang-tidy/checks/hicpp/multiway-paths-covered.html

#include <iostream>

namespace hicpp::multiway_paths_covered {

void check() {
  std::cout << "-- check hicpp-multiway-paths-covered" << std::endl;

  int i = 42;
  switch (i) { // warn here!
  }
}
} // namespace hicpp::multiway_paths_covered
