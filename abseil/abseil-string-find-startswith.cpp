// abseil-string-find-startswith
// Checks whether a std::string::find() result is compared with 0, and suggests
// replacing with absl::StartsWith(). This is both a readability and performance
// issue.

// Options
//
// StringLikeClasses
// Semicolon-separated list of names of string-like classes. By default only
// std::basic_string is considered. The list of methods to considered is fixed.
//
// IncludeStyle
// A string specifying which include-style is used, llvm or google. Default is
// llvm.
//
// AbseilStringsMatchHeader
// The location of Abseil’s strings/match.h. Defaults to absl/strings/match.h.

// https://clang.llvm.org/extra/clang-tidy/checks/abseil-string-find-startswith.html

#include <iostream>
#include <string>

namespace abseil::string_find_startswith {
void check() {
  std::cout << "-- check abseil-string-find-startswith " << std::endl;

  std::string s = "...";
  if (s.find("Hello World") == 0) { // warn here!
    /* do something */
  }
}
} // namespace abseil::string_find_startswith
