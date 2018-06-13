// modernize-replace-auto-ptr
// This check replaces the uses of the deprecated class std::auto_ptr by std::unique_ptr (introduced in C++11).
// The transfer of ownership, done by the copy-constructor and the assignment operator, is changed
// to match std::unique_ptr usage by using explicit calls to std::move().
// Since std::move() is a library function declared in <utility> it may be necessary to add this include.
// The check will add the include directive when necessary.

// https://clang.llvm.org/extra/clang-tidy/checks/modernize-replace-auto-ptr.html

#include <iostream>

namespace modernize {
    namespace replace_auto_ptr {
        //void take_ownership_fn(std::auto_ptr<int> int_ptr);

        void check(){
            std::cout << "-- check modernize-replace-auto-ptr" << std::endl;
//            std::auto_ptr<int> a(new int(x));
//            std::auto_ptr<int> b;
//            b = a;
//            take_ownership_fn(b);
        }
    } // namespace replace_auto_ptr
} // namespace modernize
