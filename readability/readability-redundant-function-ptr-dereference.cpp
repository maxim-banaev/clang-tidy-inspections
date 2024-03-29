// readability-redundant-function-ptr-dereference
// Finds redundant dereferences of a function pointer.

// https://clang.llvm.org/extra/clang-tidy/checks/readability/redundant-function-ptr-dereference.html

#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "readability-identifier-length"

namespace readability::redundant_function_ptr_dereference {

int f([[maybe_unused]] int i, [[maybe_unused]] int j) { return 0; }
int (*p)(int, int) = &f;
int i = (**p)(10, 50); // warn here! NOLINT(readability-magic-numbers)

void check() {
  std::cout << "-- check readability-redundant-function-ptr-dereference"
            << std::endl;
}
} // namespace readability::redundant_function_ptr_dereference

#pragma clang diagnostic pop
