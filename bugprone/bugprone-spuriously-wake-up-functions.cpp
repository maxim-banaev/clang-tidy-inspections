// bugprone-spuriously-wake-up-functions
//
// Finds cnd_wait, cnd_timedwait, wait, wait_for, or wait_until function calls
// when the function is not invoked from a loop that checks whether a condition
// predicate holds or the function has a condition parameter.
//
// This check corresponds to the CERT C++ Coding Standard rule CON54-CPP. Wrap
// functions that can spuriously wake up in a loop. and CERT C Coding Standard
// rule CON36-C. Wrap functions that can spuriously wake up in a loop.
//
// https://clang.llvm.org/extra/clang-tidy/checks/bugprone-spuriously-wake-up-functions.html
#include <iostream>

namespace bugprone::spuriously_wake_up_functions {

struct Node {
  void *node;
  struct Node *next;
};

static Node list;
static std::mutex m;
static std::condition_variable condition;

void consume_list_element(std::condition_variable &condition) {
  std::unique_lock<std::mutex> lk(m);

  if (list.next == nullptr) {
    condition.wait(lk); // should warn here
  }

  // Proceed when condition holds.
}
void check() {
  std::cout << "-- check spuriously-wake-up-functions" << std::endl;
}
} // namespace bugprone::spuriously_wake_up_functions
