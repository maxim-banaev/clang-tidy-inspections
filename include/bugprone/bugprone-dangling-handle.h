// NOLINTNEXTLINE(llvm-header-guard)
#ifndef BUGPRONE_DANGLING_HANDLE_H
#define BUGPRONE_DANGLING_HANDLE_H

#include <string_view>

namespace bugprone::dangling_handle {
std::string_view f();
void check();
} // namespace bugprone::dangling_handle

#endif // BUGPRONE_DANGLING_HANDLE_H
