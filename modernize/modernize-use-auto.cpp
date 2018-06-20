// modernize-use-auto
// This check is responsible for using the auto type specifier for variable declarations to improve code readability
// and maintainability.
// The auto type specifier will only be introduced in situations where the variable type matches the type of the
// initializer expression. In other words auto should deduce the same type that was originally spelled in the source.
//
// Iterator type specifiers tend to be long and used frequently, especially in loop constructs.
// Since the functions generating iterators have a common format, the type specifier can be replaced without obscuring
// the meaning of code while improving readability and maintainability.
//
// The check will only replace iterator type-specifiers when all of the following conditions are satisfied:
//
// The iterator is for one of the standard container in std namespace:
// - array
// - deque
// - forward_list
// - list
// - vector
// - map
// - multimap
// - set
// - multiset
// - unordered_map
// - unordered_multimap
// - unordered_set
// - unordered_multiset
// - queue
// - priority_queue
// - stack
// The iterator is one of the possible iterator types for standard containers:
// - iterator
// - reverse_iterator
// - const_iterator
// - const_reverse_iterator
// In addition to using iterator types directly, typedefs or other ways of referring to those types are also allowed.
// However, implementation-specific types for which a type like std::vector<int>::iterator is itself a typedef will not
// be transformed.

// https://clang.llvm.org/extra/clang-tidy/checks/modernize-use-auto.html

#include <iostream>
#include <vector>

namespace modernize {
    namespace use_auto {
        void check(){
            std::cout << "-- check modernize-use-auto" << std::endl;
            std::string str("Please split this sentence into tokens");

            char *cstr = new char[str.length() + 1];
        }
    } // namespace use_auto
} // namespace modernize