include_directories(../include/clion)

file(GLOB SOURCES "*.cpp")
add_executable(clion run_clion_inspection.cpp ${SOURCES})