#include <misc-misplaced-const.h>
#include <misc-new-delete-overloads.h>
#include <misc-no-recursion.h>
#include <misc-non-copyable-objects.h>
#include <misc-throw-by-value-catch-by-reference.h>
#include <misc-unconventional-assign-operator.h>
#include <misc-uniqueptr-reset-release.h>

int main() {
  using namespace misc;

  misplaced_const::check();
  new_delete_overloads::check();
  no_recursion::check();
  non_copyable_objects::check();
  throw_by_value_catch_by_reference::check();
  unconventional_assign_operator::check();
  uniqueptr_reset_release::check();

  return 0;
}