#include <argument-selection-defects.h>
#include <empty-decl-or-stmt.h>
#include <iostream>

int main() {
  clion::argument_selection_defects::check();
  clion::empty_decl_or_stmt::check();
  std::cout << std::endl;

  return 0;
}
