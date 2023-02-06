// misc-non-copyable-objects
//
// The check flags dereferences and non-pointer declarations of objects that
// are not meant to be passed by value, such as C FILE objects or POSIX
// pthread_mutex_t objects.
// https://clang.llvm.org/extra/clang-tidy/checks/misc/non-copyable-objects.html

#include <iostream>

namespace misc::non_copyable_objects {
void check() {
  [[maybe_unused]] FILE my_stdout = *stdout; // warn here twice! NOLINT(misc-const-correctness)
  std::cout << "-- check misc-non-copyable-objects" << std::endl;
}
} // namespace misc::non_copyable_objects