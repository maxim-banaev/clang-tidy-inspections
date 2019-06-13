include_directories(../include/modernize)

file(GLOB SOURCES "*.cpp")
add_executable(modernize run_modernize_inspection.cpp  ${SOURCES} )

