// readability-braces-around-statements
// google-readability-braces-around-statements redirects here as an alias for
// this check. Checks that bodies of if statements and loops (for, do while, and
// while) are inside braces.
//
// Options
//
// ShortStatementLines
// Defines the minimal number of lines that the statement should have in order
// to trigger this check.
//
// The number of lines is counted from the end of condition or initial keyword
// (do/else) until the last line of the inner statement. Default value 0 means
// that braces will be added to all statements (not having them already).

// https://clang.llvm.org/extra/clang-tidy/checks/readability-braces-around-statements.html

// Turn of by default!

#include <iostream>

namespace readability::brace_around_statements {
void check() {
  std::cout
      << "-- check readability-braces-around-statements [turn off by default]"
      << std::endl;

  srand(static_cast<unsigned int>( // NOLINT(cert-msc32-c,cert-msc51-cpp)
      time(nullptr)));

  if (random() % 2 == 0)
    std::cout << "";
}
} // namespace readability::brace_around_statements
