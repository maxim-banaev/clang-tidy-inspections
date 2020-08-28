include_directories(../include/hicpp)

file(GLOB SOURCES "*.cpp")
add_executable(hicpp run_hicpp_inspection.cpp ${SOURCES})