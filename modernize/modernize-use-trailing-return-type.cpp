// modernize-use-trailing-return-type
// Rewrites function signatures to use a trailing return type (introduced in
// C++11). This transformation is purely stylistic. The return type before the
// function name is replaced by auto and inserted after the function parameter
// list (and qualifiers).

// https://clang.llvm.org/extra/clang-tidy/checks/modernize/use-trailing-return-type.html

#include <iostream>

namespace modernize::use_trailing_return_type {
void check() { std::cout << "-- check modernize-use-auto" << std::endl; }

int f1();                        // warn here!
inline int f2(int arg) noexcept; // warn here!

void b(); // should warn here

} // namespace modernize::use_trailing_return_type