#include <mpi-buffer-deref.h>
#include <mpi-type-mismatch.h>

int main() {
  mpi::buffer_deref::check();
  mpi::type_mismatch::check();

  return 0;
}