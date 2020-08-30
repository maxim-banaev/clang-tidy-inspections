#include <hicpp-exception-baseclass.h>
#include <hicpp-multiway-paths-covered.h>
#include <hicpp-signed-bitwise.h>

int main() {
  using namespace hicpp;

  exception_baseclass::check();
  multiway_paths_covered::check();
  signed_bitwise::check();

  return 0;
}