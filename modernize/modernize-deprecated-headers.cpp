// modernize-deprecated-headers
// Some headers from C library were deprecated in C++ and are no longer welcome in C++ codebases.
// Some have no effect in C++. For more details refer to the C++ 14 Standard [depr.c.headers] section.
//
// This check replaces C standard library headers with their C++ alternatives and removes redundant ones.
//
// Important note: the Standard doesn’t guarantee that the C++ headers declare all the same functions in the global
// namespace. The check in its current form can break the code that uses library symbols from the global namespace.

// https://clang.llvm.org/extra/clang-tidy/checks/modernize-deprecated-headers.html

#include "../include/modernize/modernize-deprecated-headers.h"
#include <iostream>

#include <assert.h>
#include <complex.h>
#include <ctype.h>
#include <errno.h>
#include <fenv.h> // deprecated since C++11
#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h> // deprecated since C++11
#include <time.h>
//#include <uchar.h> // deprecated since C++11
#include <wchar.h>
#include <wctype.h>

namespace modernize {
    namespace deprecated_headers {
        void check(){
            std::cout << "-- check modernize-deprecated-headers" << std::endl;
        }
    } // deprecated_headers
} // modernize