// readability-inconsistent-declaration-parameter-name
// Find function declarations which differ in parameter names.

// IgnoreMacros
// If this option is set to non-zero (default is 1), the check will not warn
// about names declared inside macros.

// https://clang.llvm.org/extra/clang-tidy/checks/readability/inconsistent-declaration-parameter-name.html

#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-identifier-length"
namespace readability::inconsistent_declaration_parameter_name {

int foo(int a); // warning and fix-it hint (replace "a" to "b")
int foo(int b) { return b + 2; }

int foo_in_source(int a, int b, int c); // warn here!
int foo_in_source(int d, int e, int f) { return d + e + f; }

void foo_in_header([[maybe_unused]] int d, [[maybe_unused]] int e,
                   [[maybe_unused]] int f) {} // no warning

template <typename T>
void templateFunctionWithSeparateDeclarationAndDefinition(T a); // warn here!

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-value"
template <typename T>
void templateFunctionWithSeparateDeclarationAndDefinition(T b) {
  b;
}
#pragma clang diagnostic pop

#define DECLARE_FUNCTION_WITH_PARAM_NAME(function_name, param_name)            \
  void function_name(int param_name) // NOLINT(misc-macro-parentheses)

DECLARE_FUNCTION_WITH_PARAM_NAME(macroFunction, a);
DECLARE_FUNCTION_WITH_PARAM_NAME(macroFunction, b);

void check() {
  std::cout << "-- check readability-inconsistent-declaration-parameter-name"
            << std::endl;
  foo_in_header(0, 1, 2);
  foo_in_source(0, 1, 2);
  foo(0);
  templateFunctionWithSeparateDeclarationAndDefinition<int>(0);
}
} // namespace readability::inconsistent_declaration_parameter_name

#pragma clang diagnostic pop