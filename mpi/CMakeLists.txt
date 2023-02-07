include_directories(../include/mpi)

file(GLOB SOURCES "*.cpp")
add_executable(mpi run_mpi_inspection.cpp ${SOURCES} )

target_precompile_headers(mpi PUBLIC
        <iostream>
        #<mpi.h>
        )
