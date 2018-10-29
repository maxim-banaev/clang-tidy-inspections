// abseil-string-find-startswith
// Checks whether a std::string::find() result is compared with 0, and suggests replacing with absl::StartsWith().
// This is both a readability and performance issue.

// Options
//
// StringLikeClasses
// Semicolon-separated list of names of string-like classes. By default only std::basic_string is considered.
// The list of methods to considered is fixed.
//
// IncludeStyle
// A string specifying which include-style is used, llvm or google. Default is llvm.
//
// AbseilStringsMatchHeader
// The location of Abseil’s strings/match.h. Defaults to absl/strings/match.h.

// https://clang.llvm.org/extra/clang-tidy/checks/abseil-string-find-startswith.html

#include <iostream>
#include <string>

namespace argument_selection_defects {
    void swap(const std::string &str1, const std::string &str2) {
        std::cout << "I'm here!";
    }

    void foo(const std::string &str1, const std::string &str2) {}

    void f(const std::string &s1, const std::string &s2) {}

    void bar(int x, int y) {}

    void check() {
        std::cout << "-- check argument-selection-defects" << std::endl;
        std::string str1, str2, s1, s2;

        int x, y;

        swap(str2, str1);   // should no warning here
        foo(str2, str1);    //warn here!
        f(s2, s1);          //warn here!

        bar(y, x);          //warn here!

    }
} // namespace abseil_string_find_startswith

