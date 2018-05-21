// NOLINTNEXTLINE(llvm-header-guard)
#ifndef CPP_12784_BUGPRONE_DANGLING_HANDLE_H
#define CPP_12784_BUGPRONE_DANGLING_HANDLE_H

#include <string_view>

namespace bugprone {
    namespace dangling_handle {
        std::string_view f();
        void check();
    } // namespace dangling_handle
} // namespace bugprone

#endif //CPP_12784_BUGPRONE_DANGLING_HANDLE_H
