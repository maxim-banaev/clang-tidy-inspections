include_directories(../include/performance)

file(GLOB SOURCES "*.cpp")
add_executable(performance run_performance_inspection.cpp ${SOURCES} )

target_precompile_headers(performance PUBLIC
        <iostream>
        <string>
        )
