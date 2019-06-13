include_directories(../include/cert)

file(GLOB SOURCES "*.cpp")
add_executable(cert run_cert_inspection.cpp  ${SOURCES} )

