include_directories(../include/boost)

file(GLOB SOURCES "*.cpp")
add_executable(boost run_boost_inspection.cpp ${SOURCES})