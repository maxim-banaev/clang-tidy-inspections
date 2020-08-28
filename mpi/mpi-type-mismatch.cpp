// mpi-type-mismatch
//
// This check verifies if buffer type and MPI (Message Passing Interface)
// datatype pairs match for used MPI functions. All MPI datatypes defined by
// the MPI standard (3.1) are verified by this check. User defined typedefs,
// custom MPI datatypes and null pointer constants are skipped, in the course
// of verification.
//
// https://clang.llvm.org/extra/clang-tidy/checks/mpi-type-mismatch.html

namespace mpi::type_mismatch {
void check() {
  // In the following case, the buffer type does not match MPI datatype.
  int buf;
  MPI_Send(&buf, 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);

  std::cout << "-- check mpi-type-mismatch " << std::endl;
}
} // namespace mpi::type_mismatch