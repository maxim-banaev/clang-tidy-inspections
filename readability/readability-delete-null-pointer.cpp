// readability-delete-null-pointer
// Checks the if statements where a pointer’s existence is checked and then
// deletes the pointer. The check is unnecessary as deleting a null pointer has
// no effect.

// https://clang.llvm.org/extra/clang-tidy/checks/readability-delete-null-pointer.html

#include <iostream>

namespace readability::delete_null_pointer {
void check() {
  std::cout << "-- check readability-delete-null-pointer" << std::endl;

  int *p;
  if (p) // should warn here!
    delete p;
}
} // namespace readability::delete_null_pointer