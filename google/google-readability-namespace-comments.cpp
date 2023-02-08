// google-readability-namespace-comments

// Checks that long namespaces have a closing comment.
// http://llvm.org/docs/CodingStandards.html#namespace-indentation
// https://google.github.io/styleguide/cppguide.html#Namespaces

// https://clang.llvm.org/extra/clang-tidy/checks/google/readability-namespace-comments.html

#include <iostream>

namespace google::readability_namespace_comments { // warn here!
void check() { std::cout << "-- check google-readability-namespace-comments" << std::endl; }
} // wrong_comment
