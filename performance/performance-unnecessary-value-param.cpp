// performance-unnecessary-value-param
// Flags value parameter declarations of expensive to copy types that are copied
// for each invocation, but it would suffice to pass them by const reference.
//
// The check is only applied to parameters of types that are expensive to copy
// which means they are not trivially copyable or have a non-trivial copy
// constructor or destructor.
//
// To ensure that it is safe to replace the value parameter with a const
// reference the following heuristic is employed:
//
// - the parameter is const qualified;
// - the parameter is not const, but only const methods or operators are invoked
// on it, or it is used as const reference or value argument in constructors or
// function calls.

// https://clang.llvm.org/extra/clang-tidy/checks/performance/unnecessary-value-param.html

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma clang diagnostic ignored "-Wunused-parameter"

namespace performance::unnecessary_value_param {

class ExpensiveToCopy {
  int a;

public:
  ExpensiveToCopy();
  ExpensiveToCopy(const ExpensiveToCopy &value);

  static void ConstMethod();
  static void setValue([[maybe_unused]] std::string s);
};

ExpensiveToCopy::ExpensiveToCopy() { a = 0; }

ExpensiveToCopy::ExpensiveToCopy(const ExpensiveToCopy &value) { a = value.a; }

void ExpensiveToCopy::ConstMethod() { /*do nothing*/
}

void ExpensiveToCopy::setValue([[maybe_unused]] std::string s) { // warn here!
  // a = static_cast<int>(s.length());
}

void foo([[maybe_unused]] const std::string value) { // warn here!
  // The warning will suggest making Value a reference.
}

void g(ExpensiveToCopy value) { // warn here!
  // The warning will suggest making Value a const reference.
  value.ConstMethod();
  [[maybe_unused]] ExpensiveToCopy Copy(value);
}

void check() {
  std::cout << "-- check performance-unnecessary-value-param" << std::endl;
}
} // namespace performance::unnecessary_value_param

#pragma clang diagnostic pop