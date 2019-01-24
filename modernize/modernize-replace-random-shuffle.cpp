// modernize-replace-random-shuffle
// This check will find occurrences of std::random_shuffle and replace it with
// std::shuffle. In C++17 std::random_shuffle will no longer be available and
// thus we need to replace it.

// https://clang.llvm.org/extra/clang-tidy/checks/modernize-replace-random-shuffle.html

#include <algorithm>
#include <iostream>
#include <vector>

namespace modernize::replace_random_shuffle {
void check() {
  std::cout << "-- check modernize-replace-random-shuffle" << std::endl;
  std::vector<int> vec;
#ifndef __clang__
  std::random_shuffle(vec.begin(), vec.end()); // warn here!
#endif
}
} // namespace modernize::replace_random_shuffle