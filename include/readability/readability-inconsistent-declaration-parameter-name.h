#ifndef READABILITY_INCONSISTENT_DECLARATION_PARAMETER_NAME_H
#define READABILITY_INCONSISTENT_DECLARATION_PARAMETER_NAME_H

namespace readability::inconsistent_declaration_parameter_name {
void foo_in_header(int a, int b, int c);

void check();
} // namespace readability::inconsistent_declaration_parameter_name

#endif // READABILITY_INCONSISTENT_DECLARATION_PARAMETER_NAME_H
