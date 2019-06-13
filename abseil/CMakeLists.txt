include_directories(../include/abseil)

file(GLOB SOURCES "*.cpp")
add_executable(abseil run_abseil_inspection.cpp  ${SOURCES} )

target_link_libraries(abseil absl::time)