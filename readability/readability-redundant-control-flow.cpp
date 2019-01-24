// readability-redundant-control-flow
// This check looks for procedures (functions returning no value) with return
// statements at the end of the function. Such return statements are redundant.
//
// Loop statements (for, while, do while) are checked for redundant continue
// statements at the end of the loop body.

// https://clang.llvm.org/extra/clang-tidy/checks/readability-redundant-control-flow.html

#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

namespace readability::redundant_control_flow {
extern void g() {}

void f() {
  g();
  return;
}

void k() {
  for (int i = 0; i < 10; ++i) {
    continue;
  }
}

void check() {
  std::cout << "-- check readability-redundant-control-flow" << std::endl;
}
} // namespace readability::redundant_control_flow

#pragma clang diagnostic pop