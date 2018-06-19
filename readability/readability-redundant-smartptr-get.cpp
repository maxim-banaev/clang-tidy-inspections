// readability-redundant-smartptr-get
// google-readability-redundant-smartptr-get redirects here as an alias for this check.
//
// Find and remove redundant calls to smart pointer’s .get() method.
//

#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

namespace readability {
    namespace redundant_smartptr_get {
        class A {
         public:
            void func() {}
        };

        void check() {
            std::shared_ptr <A> s_a;
            s_a.get()->func();
        }
    } // namespace redundant_smartptr_get
} // namespace readability
#pragma clang diagnostic pop