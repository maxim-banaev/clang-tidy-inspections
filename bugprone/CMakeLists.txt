include_directories(../include/bugprone)

file(GLOB SOURCES "*.cpp")
add_executable(bugprone run_bugprone_inspection.cpp  ${SOURCES} )

