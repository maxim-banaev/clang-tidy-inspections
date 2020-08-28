// mpi-buffer-deref
//
// This check verifies if a buffer passed to an MPI (Message Passing Interface)
// function is sufficiently dereferenced. Buffers should be passed as a single
// pointer or array. As MPI function signatures specify void * for their buffer
// types, insufficiently dereferenced buffers can be passed, like for example
// as double pointers or multidimensional arrays, without a compiler warning
// emitted.
//
// https://clang.llvm.org/extra/clang-tidy/checks/mpi-buffer-deref.html

namespace mpi::buffer_deref {
void check() {
  // A double pointer is passed to the MPI function.
  char *buf;
  MPI_Send(&buf, 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD); // should warn here

  // A multidimensional array is passed to the MPI function.
  short buf1[1][1];
  MPI_Send(buf1, 1, MPI_SHORT, 0, 0, MPI_COMM_WORLD); // should warn here

  // A pointer to an array is passed to the MPI function.
  short *buf2[1];
  MPI_Send(buf2, 1, MPI_SHORT, 0, 0, MPI_COMM_WORLD); // should warn here

  std::cout << "-- check mpi-buffer-deref " << std::endl;
}
} // namespace mpi::buffer_deref