include_directories(../include/fuchsia)

file(GLOB SOURCES "*.cpp")
add_executable(fuchsia run_fuchsia_inspection.cpp ${SOURCES} )