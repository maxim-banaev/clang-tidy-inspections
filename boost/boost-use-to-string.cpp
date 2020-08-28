// boost-use-to-string
// This check finds conversion from integer type like int to std::string or
// std::wstring using boost::lexical_cast, and replace it with calls to
// std::to_string and std::to_wstring.
//
// It doesn’t replace conversion from floating points despite the to_string
// overloads, because it would change the behaviour.

// https://clang.llvm.org/extra/clang-tidy/checks/boost-use-to-string.html


#include <iostream>
#include <boost/lexical_cast.hpp>

namespace boost::use_to_string {
void check() {
  auto str = boost::lexical_cast<std::string>(42); // should warn here
  auto wstr = boost::lexical_cast<std::wstring>(2137LL); // should warn here

  std::cout << "-- check boost-use-to-string" << std::endl;


}
} // namespace boost::use_to_string
