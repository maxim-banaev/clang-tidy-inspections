// misc-no-recursion
//
// Finds strongly connected functions (by analyzing the call graph for SCC’s
// (Strongly Connected Components) that are loops), diagnoses each function in
// the cycle, and displays one example of a possible call graph loop
// (recursion).
//
// References: * CERT C++ Coding Standard rule DCL56-CPP. Avoid cycles during
// initialization of static objects. * JPL Institutional Coding Standard for
// the C Programming Language (JPL DOCID D-60411) rule 2.4 Do not use direct or
// indirect recursion. * OpenCL Specification, Version 1.2 rule 6.9
// Restrictions: i. Recursion is not supported..
//
// Limitations: * The check does not handle calls done through function
// pointers * The check does not handle C++ destructors

// https://clang.llvm.org/extra/clang-tidy/checks/misc/no-recursion.html

#include <iostream>
#include <stdexcept>
namespace misc::no_recursion {

int fact(int i) noexcept(false) { // warn here!
  if (i < 0) {
    // Negative factorials are undefined.
    throw std::domain_error("i must be >= 0");
  }

  static const int cache[] = {fact(0),  fact(1),  fact(2),  fact(3),  fact(4),
                              fact(5),  fact(6),  fact(7),  fact(8),  fact(9),
                              fact(10), fact(11), fact(12), fact(13), fact(14),
                              fact(15), fact(16)};

  if (i < (sizeof(cache) / sizeof(int))) {
    return cache[i];
  }

  return i > 0 ? i * fact(i - 1) : 1;
}
void check() { std::cout << "-- check misc-no-recursion" << std::endl; }
} // namespace misc::no_recursion