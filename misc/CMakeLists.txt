include_directories(../include/misc)

file(GLOB SOURCES "*.cpp")
add_executable(misc run_misc_inspection.cpp ${SOURCES})