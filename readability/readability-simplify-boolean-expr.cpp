// readability-simplify-boolean-expr
// Looks for boolean expressions involving boolean constants and simplifies them
// to use the appropriate boolean expression directly.
//
// Options
//
// ChainedConditionalReturn
// If non-zero, conditional boolean return statements at the end of an if/else
// if chain will be transformed. Default is 0.
//
// ChainedConditionalAssignment
// If non-zero, conditional boolean assignments at the end of an if/else if
// chain will be transformed. Default is 0.

// https://clang.llvm.org/extra/clang-tidy/checks/readability-simplify-boolean-expr.html

#include <iostream>

namespace readability::simplify_boolean_expr {
void t() {}
void f() {}

struct X {
  explicit operator bool() { return random() % 2 == 0; }
};

bool foo() {
  X x;
  if (x)
    return true;
  return false;
}

void check() {
  std::cout << "-- check readability-simplify-boolean-expr" << std::endl;

  srand(static_cast<unsigned int>(time(nullptr)));
  auto b = random() % 2 == 0;
  if (b == true) {
  }
  if (b == false) {
  }
  if (b && true) {
  }
  if (b && false) {
  }
  if (b || true) {
  }
  if (b || false) {
  }

  auto e = random() % 2 == 0;

  e ? true : false;
  e ? false : true;
  if (true)
    t();
  else
    f();
  if (false)
    t();
  else
    f();

  // if (e) return true; else return false;
  // if (e) return false; else return true;

  if (e)
    b = true;
  else
    b = false;
  if (e)
    b = false;
  else
    b = true;

  // if (e) return true; return false;
  // if (e) return false; return true;

  auto i = random();
  b = (i < 0) ? true : false;

  b = foo();
  // if (i & 1) return true; else return false;
}
} // namespace readability::simplify_boolean_expr
