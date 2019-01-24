// modernize-pass-by-value
// With move semantics added to the language and the standard library updated
// with move constructors added for many types it is now interesting to take an
// argument directly by value, instead of by const-reference, and then copy.
// This check allows the compiler to take care of choosing the best way to
// construct the copy.
//
// The transformation is usually beneficial when the calling code passes an
// rvalue and assumes the move construction is a cheap operation.
//
// Replaces the uses of const-references constructor parameters that are copied
// into class fields. The parameter is then moved with std::move().
//
// Since std::move() is a library function declared in <utility> it may be
// necessary to add this include. The check will add the include directive when
// necessary.
//
// Options
//
// IncludeStyle
// A string specifying which include-style is used, llvm or google. Default is
// llvm.
//
// ValuesOnly
// When non-zero, the check only warns about copied parameters that are already
// passed by value. Default is 0.

// https://clang.llvm.org/extra/clang-tidy/checks/modernize-pass-by-value.html

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "google-runtime-member-string-references"

#include <iostream>
#include <string>

namespace modernize::pass_by_value {
class Foo {
public:
  Foo(const std::string &Copied, const std::string &ReadOnly) // warn here!
      : Copied(Copied), ReadOnly(ReadOnly) {}

private:
  std::string Copied;
  const std::string &ReadOnly;
};

std::string get_cwd() { return ""; }

void f(const std::string &Path) {
  // The parameter corresponding to 'get_cwd()' is move-constructed. By
  // using pass-by-value in the Foo constructor we managed to avoid a
  // copy-construction.
  Foo foo(get_cwd(), Path);
}

void check() { std::cout << "-- check modernize-pass-by-value" << std::endl; }
} // namespace modernize::pass_by_value
#pragma clang diagnostic pop