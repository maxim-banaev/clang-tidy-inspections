// openmp-use-default-none
// Finds OpenMP directives that are allowed to contain a default clause, but
// either don’t specify it or the clause is specified but with the kind other
// than none, and suggests to use the default(none) clause.
//
// Using default(none) clause forces developers to explicitly specify data
// sharing attributes for the variables referenced in the construct, thus making
// it obvious which variables are referenced, and what is their data sharing
// attribute, thus increasing readability and possibly making errors easier to
// spot.
//
// https://clang.llvm.org/extra/clang-tidy/checks/openmp-use-default-none.html
#include <iostream>
namespace openmp::use_default_none {
// ``for`` directive can not have ``default`` clause, no diagnostics.
void n0(const int a) {
#pragma omp for
  for (int b = 0; b < a; b++)
    ;
}

// ``parallel`` directive.

// ``parallel`` directive can have ``default`` clause, but said clause is not
// specified, diagnosed.
void p0_0() {
#pragma omp parallel
  ;
  // WARNING: OpenMP directive ``parallel`` does not specify ``default``
  //          clause. Consider specifying ``default(none)`` clause.
}

// ``parallel`` directive can have ``default`` clause, and said clause is
// specified, with ``none`` kind, all good.
void p0_1() {
#pragma omp parallel default(none)
  ;
}

// ``parallel`` directive can have ``default`` clause, and said clause is
// specified, but with ``shared`` kind, which is not ``none``, diagnose.
void p0_2() {
#pragma omp parallel default(shared)
  ;
  // WARNING: OpenMP directive ``parallel`` specifies ``default(shared)``
  //          clause. Consider using ``default(none)`` clause instead.
}
void check() { std::cout << "-- check openmp-use-default-none " << std::endl; }
} // namespace openmp::use_default_none
