// readability-redundant-smartptr-get
// google-readability-redundant-smartptr-get redirects here as an alias for this
// check.
//
// Find and remove redundant calls to smart pointer’s .get() method.

// https://clang.llvm.org/extra/clang-tidy/checks/readability-redundant-smartptr-get.html

#include <iostream>
#include <memory>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

namespace readability::redundant_smartptr_get {
class A {
public:
  void func() {}
};

void check() {
  std::cout << "-- check readability-redundant-smartptr-get" << std::endl;
  std::shared_ptr<A> s_a;
  s_a.get()->func(); // warn here!
}
} // namespace readability::redundant_smartptr_get
#pragma clang diagnostic pop