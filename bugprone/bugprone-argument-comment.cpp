// bugprone-argument-comment
// Checks that argument comments match parameter names.
// The check understands argument comments in the form /*parameter_name=*/ that
// are placed right before the argument. The check tries to detect typos and
// suggest automated fixes for them.

// Options
//
// StrictMode
// When zero (default value), the check will ignore leading and trailing
// underscores and case when comparing names – otherwise they are taken into
// account.

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone-argument-comment.html

#include <iostream>

namespace bugprone::argument_comment {
void f1(bool foo_) {
  if (foo_) {
    /* do something */
  }
}

void f11(bool foo, bool bar) {
  if (foo || bar) {
    /* do something */
  }
}

void f2(int MeaningOfLife) {
  if (MeaningOfLife) {
    /* do something */
  }
}

void check() {
  std::cout << "-- check bugprone-argument-comment" << std::endl;
  f1(/*bar=*/true);                 // should warn here
  f11(/*foo=*/true, /*bar=*/false); // shouldn't warn here
  f1(/*foo=*/true);                 // shouldn't warn here
  f1(/*FOO=*/true);                 // shouldn't warn here
  f1(/*Foo=*/true);                 // shouldn't warn here
  f1(/*foo=*/true);                 // works only if StrictMode is 1

  f2(/*MeaningOfLife_bad=*/1); // should warn here
  f2(/*MeaningOfLife=*/1);     // shouldn't warn here
}
} // namespace bugprone::argument_comment