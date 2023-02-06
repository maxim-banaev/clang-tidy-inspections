// readability-simplify-subscript-expr
// This check simplifies subscript expressions. Currently, this covers calling
// .data() and immediately doing an array subscript operation to obtain a single
// element, in which case simply calling operator[] suffice. Options
//
// Types
// The list of type(s) that triggers this check.
// Default is
// ::std::basic_string;::std::basic_string_view;::std::vector;::std::array

// https://clang.llvm.org/extra/clang-tidy/checks/readability/simplify-subscript-expr.html

#include <iostream>

#ifdef _MSC_VER
#define random rand
#endif

#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-identifier-length"

namespace readability::simplify_subscript_expr {
void check() {
  std::cout << "-- check readability-simplify-subscript-expr" << std::endl;

  std::string s = "check readability-simplify-subscript-expr";
  int i = random() % s.size();
  char c = s.data()[i]; // char c = s[i]; // warn here!

  if (c == 0) {
  }
}
} // namespace readability::simplify_subscript_expr

#pragma clang diagnostic pop