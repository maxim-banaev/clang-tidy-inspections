// modernize-avoid-c-arrays
// cppcoreguidelines-avoid-c-arrays redirects here as an alias for this check.
//
// hicpp-avoid-c-arrays redirects here as an alias for this check.
//
// Finds C-style array types and recommend to use std::array<> / std::vector<>.
// All types of C arrays are diagnosed.
//
// However, fix-it are potentially dangerous in header files and are therefore
// not emitted right now.

// https://clang.llvm.org/extra/clang-tidy/checks/modernize-avoid-c-arrays.html

#include <iostream>

namespace modernize::avoid_c_arrays {
int a[] = {
    1, 2}; // warning: do not declare C-style arrays, use std::array<> instead

int b[1]; // warning: do not declare C-style arrays, use std::array<> instead

void foo() {
  int c[b[0]]; // warning: do not declare C VLA arrays, use std::vector<>
               // instead
}

template <typename T, int Size> class array {
  T d[Size]; // warning: do not declare C-style arrays, use std::array<> instead

  int e[1]; // warning: do not declare C-style arrays, use std::array<> instead
};

array<int[4], 2>
    d; // warning: do not declare C-style arrays, use std::array<> instead

using k =
    int[4]; // warning: do not declare C-style arrays, use std::array<> instead

void check() { std::cout << "-- check modernize-avoid-c-arrays" << std::endl; }

extern "C" {

int f[] = {1, 2}; // not diagnosed

int j[1]; // not diagnosed

inline void bar() {
  {
    int j[j[0]]; // not diagnosed
  }
}
}
} // namespace modernize::avoid_c_arrays
