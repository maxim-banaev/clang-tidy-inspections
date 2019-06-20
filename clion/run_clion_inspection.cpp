#include <argument-selection-defects.h>
#include <empty-decl-or-stmt.h>
#include <method-can-be-static.h>
#include <iostream>

int main() {
  clion::argument_selection_defects::check();
  clion::empty_decl_or_stmt::check();
  clion::method_can_be_static::check();
  std::cout << std::endl;

  return 0;
}
