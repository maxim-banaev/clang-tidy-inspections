include_directories(../include/analyzer)

file(GLOB SOURCES "*.cpp")
file(GLOB CORE_SOURCES "core/*.cpp")
add_executable(analyzer run_analyzer_inspection.cpp ${SOURCES} ${CORE_SOURCES})