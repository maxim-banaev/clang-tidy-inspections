// bugprone-unchecked-optional-access

// Note: This check uses a flow-sensitive static analysis to produce its
// results. Therefore, it may be more resource intensive (RAM, CPU) than the
// average clang-tidy check.
//
// This check identifies unsafe accesses to values contained in
// std::optional<T>, absl::optional<T>, or base::Optional<T> objects. Below we
// will refer to all these types collectively as optional<T>.
//
// Access to the value of an optional<T> occurs when one of its value,
// operator*, or operator-> member functions is invoked. To align with common
// misconceptions, the check considers these member functions as equivalent,
// even though there are subtle differences related to exceptions versus
// undefined behavior. See go/optional-style-recommendations for more
// information on that topic.
//
// Access to the value of an optional<T> is considered safe if and only if code
// in the local scope (for example, a function body) ensures that the
// optional<T> has a value in all possible execution paths that can reach the
// access. That should happen either through an explicit check, using the
// optional<T>::has_value member function, or by constructing the optional<T> in
// a way that shows that it unambiguously holds a value (e.g. using
// std::make_optional which always returns a populated std::optional<T>).
//
// Below we list some examples, starting with unsafe optional access patterns,
// followed by safe access patterns.

// https://clang.llvm.org/extra/clang-tidy/checks/bugprone/unchecked-optional-access.html

#include <iostream>
#include <optional>

namespace bugprone::unchecked_optional_access {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-result"
[[maybe_unused]] void test(const std::optional<int> &opt) { opt.value(); } // warn here!
#pragma clang diagnostic pop

void check() {
  std::cout << "-- check bugprone-unchecked-optional-access" << std::endl;
}
} // namespace bugprone::unchecked_optional_access