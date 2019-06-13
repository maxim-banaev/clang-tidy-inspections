include_directories(../include/openmp)

file(GLOB SOURCES "*.cpp")
add_executable(openmp run_openmp_inspection.cpp ${SOURCES} )
