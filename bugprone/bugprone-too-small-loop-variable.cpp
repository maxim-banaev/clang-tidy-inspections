// bugprone-too-small-loop-variable
// Detects those for loops that have a loop variable with a “too small” type
// which means this type can’t represent all values which are part of the
// iteration range.
//
// Options
//
// MagnitudeBitsUpperLimit
// Upper limit for the magnitude bits of the loop variable. If it’s set the
// check filters out those catches in which the loop variable’s type has more
// magnitude bits as the specified upper limit. The default value is 16. For
// example, if the user sets this option to 31 (bits), then a 32-bit unsigned
// int is ignored by the check, however a 32-bit int is not (A 32-bit signed int
// has 31 magnitude bits).
//
// https://clang.llvm.org/extra/clang-tidy/checks/bugprone/too-small-loop-variable.html

#include <iostream>

namespace bugprone::too_small_loop_variable {
void check() {
  std::cout << "-- check bugprone-too-small-loop-variable FIXME" << std::endl;

  long size = 294967296L;
  for (unsigned i = 0; i < size; ++i) {
  } // no warning with MagnitudeBitsUpperLimit = 31 on a system where unsigned
    // is 32-bit
  for (int i = 0; i < size; ++i) {
  } // warning with MagnitudeBitsUpperLimit = 31 on a system where int is 32-bit
}
} // namespace bugprone::too_small_loop_variable