// performance-faster-string-find
//
// Optimize calls to std::string::find() and friends when the needle passed is
// a single character string literal. The character literal overload is more
// efficient.
//
// Options
//
// StringLikeClasses
// Semicolon-separated list of names of string-like classes. By default
// only ::std::basic_string and ::std::basic_string_view are considered.
// The check will only consider member functions named find, rfind,
// find_first_of, find_first_not_of, find_last_of, or find_last_not_of within
// these classes.
//
// https://clang.llvm.org/extra/clang-tidy/checks/performance/faster-string-find.html

namespace performance::faster_string_find {
void check() {
  std::cout << "-- check performance-faster-string-find" << std::endl;

  std::string str = "Who am I?";
  str.find("A"); // warn here!
}
} // namespace performance::faster_string_find