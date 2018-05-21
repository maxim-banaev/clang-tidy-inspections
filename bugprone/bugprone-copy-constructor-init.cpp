// bugprone-copy-constructor-init
// Finds copy constructors where the constructor doesn’t call the copy constructor of the base class.
// Also finds copy constructors where the constructor of the base class don’t have parameter.
// The check also suggests a fix-its in some cases.

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone-copy-constructor-init.html

#include "../include/bugprone/bugprone-copy-constructor-init.h"
#include <iostream>


#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "cppcoreguidelines-special-member-functions"
#pragma ide diagnostic ignored "hicpp-special-member-functions"

namespace bugprone {
    namespace copy_constructor_init {

        class Copyable {
         public:
            Copyable() = default;
            Copyable(const Copyable &) = default;

            virtual ~Copyable() = default;
        };

        class X2 : public Copyable {
            X2(const X2 &other) { other; } // Copyable(other) is missing
        };

        class X4 : public Copyable {
            X4(const X4 &other) : Copyable() { other; } // other is missing
        };

        void check() {
            std::cout << "-- check bugprone-copy-constructor-init FIXME" << std::endl;
            X2 x2();
            X4 x4();
        }
    } // namespace copy_constructor_init
} // namespace bugprone

#pragma clang diagnostic pop