// bugprone-string-integer-assignment
// The check finds assignments of an integer to std::basic_string<CharT>
// (std::string, std::wstring, etc.). The source of the problem is the following
// assignment operator of std::basic_string<CharT>.

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone/string-integer-assignment.html

#include <iostream>
#include <string>

namespace bugprone::string_integer_assignment {
#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedValue"
void check() {
  std::cout << "-- check bugprone-string-integer-assignment" << std::endl;

  std::string s;
  int x = 5965;
  s = 6; // warn here!
  s = x; // warn here! NOLINT(bugprone-narrowing-conversions)
}
#pragma clang diagnostic pop
} // namespace bugprone::string_integer_assignment