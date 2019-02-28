// NOLINTNEXTLINE(llvm-header-guard)
#ifndef CPP_12784_BUGPRONE_DANGLING_HANDLE_H
#define CPP_12784_BUGPRONE_DANGLING_HANDLE_H

#include <string_view>

namespace bugprone::dangling_handle {
std::string_view f();
void check();
} // namespace bugprone::dangling_handle

#endif // CPP_12784_BUGPRONE_DANGLING_HANDLE_H
