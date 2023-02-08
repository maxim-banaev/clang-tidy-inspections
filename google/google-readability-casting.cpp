// google-readability-casting

// Finds usages of C-style casts.
//
// https://google.github.io/styleguide/cppguide.html#Casting
//
// Corresponding cpplint.py check name: readability/casting.
//
// This check is similar to -Wold-style-cast, but it suggests automated fixes
// in some cases. The reported locations should not be different from the ones
// generated by -Wold-style-cast.

// https://clang.llvm.org/extra/clang-tidy/checks/google/readability-casting.html

#include <iostream>
namespace google::readability_casting {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wuninitialized"
#pragma clang diagnostic ignored "-Wunused-value"
[[maybe_unused]] void test(const char *cpc) {
  [[maybe_unused]] const char *cpc2 = (const char *)cpc; // warn here!

  typedef const char *Typedef1;
  typedef const char *Typedef2;
  Typedef1 t1;
  (Typedef2)t1; // warn here!
}
#pragma clang diagnostic pop

void check() {
  std::cout << "-- check google-readability-casting" << std::endl;
}
} // namespace google::readability_casting