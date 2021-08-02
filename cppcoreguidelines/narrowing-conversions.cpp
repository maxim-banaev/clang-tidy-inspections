// Checks for silent narrowing conversions, e.g: int i = 0; i += 0.1;.
// While the issue is obvious in this former example, it might not be so in the
// following: void MyClass::f(double d) { int_member_ += d; }.
//
// This rule is part of the “Expressions and statements” profile of the C++ Core
// Guidelines, corresponding to rule ES.46. See
//
// https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#es46-avoid-lossy-narrowing-truncating-arithmetic-conversions.
//
// We enforce only part of the guideline, more specifically, we flag narrowing
// conversions from: an integer to a narrower integer (e.g. char to unsigned
// char), an integer to a narrower floating-point (e.g. uint64_t to float), a
// floating-point to an integer (e.g. double to int), a floating-point to a
// narrower floating-point (e.g. double to float) if
// WarnOnFloatingPointNarrowingConversion Option is set. This check will flag:
// All narrowing conversions that are not marked by an explicit cast (c-style or
// static_cast). For example: int i = 0; i += 0.1;, void f(int); f(0.1);, All
// applications of binary operators with a narrowing conversions. For example:
// int i; i+= 0.1;.
//
// https://clang.llvm.org/extra/clang-tidy/checks/cppcoreguidelines-narrowing-conversions.html

#include <iostream>

namespace cppcoreguidelines::narrowing_conversions {
void check() {
  std::cout << "-- check narrowing-conversions" << std::endl;

  int i = 0;
  i += 0.1;
}
} // namespace cppcoreguidelines::narrowing_conversions