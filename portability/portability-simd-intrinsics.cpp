// portability-simd-intrinsics
// Finds SIMD intrinsics calls and suggests std::experimental::simd (P0214) alternatives.
// If the option Suggest is set to non-zero, the check suggests an alternative: operator+ on std::experimental::simd objects.
//
// Otherwise, it just complains the intrinsics are non-portable (and there are P0214 alternatives).
//
// Many architectures provide SIMD operations (e.g. x86 SSE/AVX, Power AltiVec/VSX, ARM NEON).
// It is common that SIMD code implementing the same algorithm, is written in multiple target-dispatching pieces
// to optimize for different architectures or micro-architectures.
//
// The C++ standard proposal P0214 and its extensions cover many common SIMD operations. By migrating from
// target-dependent intrinsics to P0214 operations, the SIMD code can be simplified and pieces for different targets
// can be unified.
//
// Refer to P0214 for introduction and motivation for the data-parallel standard library.

// Options
//
// Suggest
// If this option is set to non-zero (default is 0), the check will suggest P0214 alternatives,
// otherwise it only points out the intrinsic function is non-portable.
//
// Std
// The namespace used to suggest P0214 alternatives. If not specified, std:: for -std=c++2a and std::experimental:: for -std=c++11.

// https://clang.llvm.org/extra/clang-tidy/checks/portability-simd-intrinsics.html

#include <iostream>
#include <vector>
//#include <altivec.h>

namespace portability {
    namespace portability_simd_intrinsics {
        void check() {
            std::cout << "-- check portability-simd-intrinsics FIXME" << std::endl;

            std::vector<int> a = {1, 2, 3};
            std::vector<int> b = { 4 };
            //vec_add(a, b);
        }
    } // namespace portability_simd_intrinsics
} // namespace portability
