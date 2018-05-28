// modernize-make-shared
// This check finds the creation of std::shared_ptr objects by explicitly calling the constructor and a new expression,
// and replaces it with a call to std::make_shared.
// This check also finds calls to std::shared_ptr::reset() with a new expression, and replaces it with a call to
// std::make_shared.
//
// Options
//
// MakeSmartPtrFunction
// A string specifying the name of make-shared-ptr function. Default is std::make_shared.
//
// MakeSmartPtrFunctionHeader
// A string specifying the corresponding header of make-shared-ptr function. Default is memory.
//
// IncludeStyle
// A string specifying which include-style is used, llvm or google. Default is llvm.
//
// IgnoreMacros
// If set to non-zero, the check will not give warnings inside macros. Default is 1.

// https://clang.llvm.org/extra/clang-tidy/checks/modernize-make-shared.html

#include <iostream>
#include <vector>
#include <memory>

namespace modernize {
    namespace make_shared {
        class MyPair {
            std::vector<int> v;
         public:
            MyPair(int a, int b) {
                v.push_back(a);
                v.push_back(b);
            }
        };

        void check(){
            std::cout << "-- check modernize-make-shared" << std::endl;

            auto my_ptr = std::shared_ptr<MyPair>(new MyPair(1, 2));

            my_ptr.reset(new MyPair(1, 2));
        }
    } // make_shared
} // modernize
