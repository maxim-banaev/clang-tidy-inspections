include_directories(../include/cppcoreguidelines)

file(GLOB SOURCES "*.cpp")
add_executable(cppcoreguidelines run_cppcoreguidelines_inspection.cpp ${SOURCES})