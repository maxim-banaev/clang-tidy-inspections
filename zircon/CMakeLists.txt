include_directories(../include/zircon)

file(GLOB SOURCES "*.cpp")
add_executable(zircon run_zircon_inspection.cpp ${SOURCES} )
