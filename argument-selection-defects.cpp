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
    void swap_me(const std::string &name, const std::string &role) {}

    void foo(const std::string &name, const std::string &role) {}

    void f(const std::string &one, const std::string &two) {}

    void bar(int x, int y) {}

    void check() {
        std::cout << "-- check argument-selection-defects" << std::endl;
        std::string name, role, one, two;

        int x, y;

        swap_me(role, name);    // should no warning here
        foo(role, name);        // warn here!
        f(two, one);            // warn here!
        bar(y, x);              // warn here!

    }
} // namespace abseil_string_find_startswith

