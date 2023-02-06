// modernize-replace-auto-ptr
// This check replaces the uses of the deprecated class std::auto_ptr by
// std::unique_ptr (introduced in C++11). The transfer of ownership, done by the
// copy-constructor and the assignment operator, is changed to match
// std::unique_ptr usage by using explicit calls to std::move(). Since
// std::move() is a library function declared in <utility> it may be necessary
// to add this includes. The check will add the include directive when
// necessary.

// https://clang.llvm.org/extra/clang-tidy/checks/modernize/replace-auto-ptr.html

#include <iostream>
#include <memory>

namespace modernize::replace_auto_ptr {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
void check() {
  std::cout << "-- check modernize-replace-auto-ptr" << std::endl;
#ifndef __clang__
  std::auto_ptr<int> a(new int(1)); // warn here!
  std::auto_ptr<int> b;             // warn here!
#endif
}
#pragma clang diagnostic pop
} // namespace modernize::replace_auto_ptr
