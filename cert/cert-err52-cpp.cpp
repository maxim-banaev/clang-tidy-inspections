// cert-err52-cpp
// This check flags all call expressions involving setjmp() and longjmp().
// This check corresponds to the CERT C++ Coding Standard rule ERR52-CPP. Do not
// use setjmp() or longjmp().

// https://clang.llvm.org/extra/clang-tidy/checks/cert/err52-cpp.html

#include <csetjmp>
#include <iostream>

namespace cert::err52_cpp {

static jmp_buf env;

struct Counter {
  static int instances;

  Counter() { ++instances; }
  ~Counter() { --instances; }
};

int Counter::instances = 0;

void f() {
  Counter c;
  std::longjmp(env, 1); // warn here!
}

void check() {
  std::cout << "-- check cert-err52-cpp" << std::endl;
  if (setjmp(env) == 0) { // warn here!
    f();
  }
}
} // namespace cert::err52_cpp