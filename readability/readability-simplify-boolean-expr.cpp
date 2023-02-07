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

// https://clang.llvm.org/extra/clang-tidy/checks/readability/simplify-boolean-expr.html

#include <iostream>

#ifdef _MSC_VER
#define random rand
#endif

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-value"
#pragma ide diagnostic ignored "UnusedValue"
#pragma ide diagnostic ignored "UnreachableCode"
#pragma ide diagnostic ignored "readability-identifier-length"
#pragma ide diagnostic ignored "readability-braces-around-statements"
#pragma ide diagnostic ignored "Simplify"

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

void check() { // NOLINT(readability-function-size)
  std::cout << "-- check readability-simplify-boolean-expr" << std::endl;

  srand(static_cast<unsigned int>(time(nullptr)));
  auto b = random() % 2 == 0;
  if (b == true) { // warn here!
  }
  if (b == false) { // warn here!
  }
  if (b && true) { // warn here!
  }
  if (b && false) { // warn here!
  }
  if (b || true) { // warn here!
  }
  if (b || false) { // warn here!
  }

  auto e = random() % 2 == 0;

  e ? true : false; // warn here!
  e ? false : true; // warn here!
  if (true)         // warn here!
    t();
  else
    f();
  if (false) // warn here!
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

#pragma clang diagnostic pop