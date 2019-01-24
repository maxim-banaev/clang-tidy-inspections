// modernize-loop-convert
// This check converts for(...; ...; ...) loops to use the new range-based loops
// in C++11.
//
// Three kinds of loops can be converted:
//
// - Loops over statically allocated arrays.
// - Loops over containers, using iterators.
// - Loops over array-like containers, using operator[] and at().

// MinConfidence option
//
// risky
//
// In loops where the container expression is more complex than just a reference
// to a declared expression (a variable, function, enum, etc.), and some part of
// it appears elsewhere in the loop, we lower our confidence in the
// transformation due to the increased risk of changing semantics.
// Transformations for these loops are marked as risky, and thus will only be
// converted if the minimum required confidence level is set to risky.
//
// int arr[10][20];
// int l = 5;
//
// for (int j = 0; j < 20; ++j)
//   int k = arr[l][j] + l; // using l outside arr[l] is considered risky
//
// for (int i = 0; i < obj.getVector().size(); ++i)
//   obj.foo(10); // using 'obj' is considered risky
//
// See Range-based loops evaluate end() only once for an example of an incorrect
// transformation when the minimum required confidence level is set to risky.
//
// reasonable (Default)
//
// If a loop calls .end() or .size() after each iteration, the transformation
// for that loop is marked as reasonable, and thus will be converted if the
// required confidence level is set to reasonable (default) or lower.
//
// for (int i = 0; i < container.size(); ++i)
//   cout << container[i];
//
// safe
//
// Any other loops that do not match the above criteria to be marked as risky or
// reasonable are marked safe, and thus will be converted if the required
// confidence level is set to safe or lower.
//
// int arr[] = {1,2,3};
//
// for (int i = 0; i < 3; ++i)
//   cout << arr[i];

// https://clang.llvm.org/extra/clang-tidy/checks/modernize-loop-convert.html

#include <iostream>
#include <vector>

namespace modernize::loop_convert {
void check() {
  std::cout << "-- check modernize-loop-convert" << std::endl;

  const int N = 5;
  int arr[] = {1, 2, 3, 4, 5};
  int tmp = 1;

  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  // safe conversion
  for (int i = 0; i < N; ++i) // warn here!
    tmp = arr[i];

  // reasonable conversion
  for (auto it = v.begin(); it != v.end(); ++it) // warn here!
    tmp = *it;

  // reasonable conversion
  for (int i = 0; i < v.size(); ++i) // warn here!
    tmp = v[i];

  if (tmp == 0) {
    // do smthg
  }
}
} // namespace modernize::loop_convert