// readability-delete-null-pointer
// Checks the if statements where a pointer’s existence is checked and then
// deletes the pointer. The check is unnecessary as deleting a null pointer has
// no effect.

// https://clang.llvm.org/extra/clang-tidy/checks/readability/delete-null-pointer.html

#include <iostream>

namespace readability::delete_null_pointer {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wuninitialized"
void check() {
  std::cout << "-- check readability-delete-null-pointer" << std::endl;

  int *p; // NOLINT(readability-identifier-length)
  if (p) // NOLINT(readability-implicit-bool-conversion,readability-braces-around-statements)
    delete p;
}
#pragma clang diagnostic pop
} // namespace readability::delete_null_pointer