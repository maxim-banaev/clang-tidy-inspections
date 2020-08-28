include_directories(../include/boost)

file(GLOB SOURCES "*.cpp")
add_executable(boost boost-use-to-string.cpp ${SOURCES})