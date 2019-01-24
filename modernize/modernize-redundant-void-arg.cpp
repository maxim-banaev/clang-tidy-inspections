// modernize-redundant-void-arg
// Find and remove redundant void argument lists.

// https://clang.llvm.org/extra/clang-tidy/checks/modernize-redundant-void-arg.html

#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

namespace modernize::redundant_void_arg {
int f(void);                    // warn here!
int (*fu(void))(void);          // warn here!
typedef int (*f_t(void))(void); // warn here!

void check() {
  std::cout << "-- check modernize-redundant-void-arg" << std::endl;
}
} // namespace modernize::redundant_void_arg

#pragma clang diagnostic pop