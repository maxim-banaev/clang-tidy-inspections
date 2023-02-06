// misc-new-delete-overloads
//
// The check flags overloaded operator new() and operator delete() functions
// that do not have a corresponding free store function defined within the same
// scope. For instance, the check will flag a class implementation of a
// non-placement operator new() when the class does not also define a
// non-placement operator delete() function as well.
//
// The check does not flag implicitly-defined operators, deleted or private
// operators, or placement operators.

// https://clang.llvm.org/extra/clang-tidy/checks/misc/new-delete-overloads.html

#include <iostream>
#include <new>

namespace misc::new_delete_overloads {

extern "C++" void update_bookkeeping(void *allocated_ptr, std::size_t size,
                                     bool alloc);

struct [[maybe_unused]] S {
  void *operator new(std::size_t size) noexcept(false) { // warn here!
    void *ptr = ::operator new(size);
    update_bookkeeping(ptr, size, true);
    return ptr;
  }
};

void check() { std::cout << "-- check misc-new-delete-overloads" << std::endl; }
} // namespace misc::new_delete_overloads
