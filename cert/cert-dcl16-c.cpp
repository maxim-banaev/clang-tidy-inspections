// cert-dcl16-c redirects here as an alias for this check. By default, only the
// suffixes that begin with l (l, ll, lu, llu, but not u, ul, ull) are diagnosed
// by that alias.
//
// hicpp-uppercase-literal-suffix redirects here as an alias for this check.
//
// Detects when the integral literal or floating point (decimal or hexadecimal)
// literal has a non-uppercase suffix and provides a fix-it hint with the
// uppercase suffix.
//
// All valid combinations of suffixes are supported.
//
// https://clang.llvm.org/extra/clang-tidy/checks/readability-uppercase-literal-suffix.html

// Turn off by default!

#include <iostream>

namespace cert::dcl16_c {
void check() {
  std::cout << "-- check cert-dcl16-c" << std::endl;

  auto x = 1u; // warning: integer literal suffix 'u' is not upper-case
}
} // namespace cert::dcl16_c