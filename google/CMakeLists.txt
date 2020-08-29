include_directories(../include/google)

file(GLOB SOURCES "*.cpp")
add_executable(google run_google_inspection.cpp ${SOURCES})