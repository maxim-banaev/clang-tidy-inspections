// modernize-raw-string-literal
// This check selectively replaces string literals containing escaped characters
// with raw string literals. The presence of the following escapes can
// cause the string to be converted to a raw string literal: \\, \', \", \?, and
// octal or hexadecimal escapes for printable ASCII characters.
//
// A string literal containing only escaped newlines is a common way of writing
// lines of text output. Introducing physical newlines with raw string literals
// in this case is likely to impede readability. These string literals are left
// unchanged.
//
// An escaped horizontal tab, form feed, or vertical tab prevents the string
// literal from being converted. The presence of a horizontal tab, form feed or
// vertical tab in source code is not visually obvious.

// https://clang.llvm.org/extra/clang-tidy/checks/modernize/raw-string-literal.html

#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
namespace modernize::raw_string_literal {

const char *const Quotes{"embedded \"quotes\""};
const char *const Paragraph{"Line one.\nLine two.\nLine three.\n"};
const char *const SingleLine{"Single line.\n"};
const char *const TrailingSpace{"Look here -> \n"};
const char *const Tab{"One\tTwo\n"};
const char *const Bell{"Hello!\a  And welcome!"};
const char *const Path{"C:\\Program Files\\Vendor\\Application.exe"}; // warn here!
const char *const RegEx{"\\w\\([a-z]\\)"}; // warn here!

void check() {
  std::cout << "-- check modernize-raw-string-literal" << std::endl;
}
} // namespace modernize::raw_string_literal

#pragma clang diagnostic pop