include_directories(../include/readability)

file(GLOB SOURCES "*.cpp")
add_executable(readability run_readability_inspection.cpp ${SOURCES})