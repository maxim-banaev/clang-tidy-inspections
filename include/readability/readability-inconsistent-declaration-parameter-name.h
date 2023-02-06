#ifndef READABILITY_INCONSISTENT_DECLARATION_PARAMETER_NAME_H
#define READABILITY_INCONSISTENT_DECLARATION_PARAMETER_NAME_H

namespace readability::inconsistent_declaration_parameter_name {
void foo_in_header([[maybe_unused]] int a, [[maybe_unused]] int b,
                   [[maybe_unused]] int c);

void check();
} // namespace readability::inconsistent_declaration_parameter_name

#endif // READABILITY_INCONSISTENT_DECLARATION_PARAMETER_NAME_H
