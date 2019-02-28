// readability-deleted-default
// Checks that constructors and assignment operators marked as = default are not
// actually deleted by the compiler.

// https://clang.llvm.org/extra/clang-tidy/checks/readability-deleted-default.html

#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

namespace readability::deleted_default {

class Example {
public:
  // This constructor is deleted because I is missing a default value.
  Example() = default;

  // This is fine.
  Example(const Example &Other) = default;

  // This operator is deleted because I cannot be assigned (it is const).
  Example &operator=(const Example &Other) = default;

private:
  const int I;
};

void check() {
  std::cout << "-- check readability-deleted-default" << std::endl;
}
} // namespace readability::deleted_default

#pragma clang diagnostic pop