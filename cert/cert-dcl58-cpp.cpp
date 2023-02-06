// cert-dcl58-cpp
// Modification of the std or posix namespace can result in undefined behavior.
// This check warns for such modifications. This check corresponds to the CERT
// C++ Coding Standard rule DCL58-CPP. Do not modify the standard namespaces.

// https://clang.llvm.org/extra/clang-tidy/checks/cert/dcl58-cpp.html

#include <iostream>

namespace std {
int x; // warn here!
}

namespace cert::dcl58_cpp {
void check() { std::cout << "-- check cert-dcl58-cpp" << std::endl; }
} // namespace cert::dcl58_cpp
