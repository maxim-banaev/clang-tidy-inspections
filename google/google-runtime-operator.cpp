// google-runtime-operator
//
// Finds overloads of unary operator &.
//
// https://google.github.io/styleguide/cppguide.html#Operator_Overloading
//
// Corresponding cpplint.py check name: runtime/operator.
//
// https://clang.llvm.org/extra/clang-tidy/checks/google-runtime-operator.html

#include <iostream>

namespace google::runtime_operator {
struct X {
public:
  void operator&(){} // should warn here
};
void check() {
  std::cout << "-- check google-runtime-operator" << std::endl;
}
} // namespace google::runtime_operator