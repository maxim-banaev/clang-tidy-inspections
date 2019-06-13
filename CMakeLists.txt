cmake_minimum_required(VERSION 3.5)
project(clang-tidy-inspection)

if (CMAKE_VERSION VERSION_GREATER "3.10")
    set(CMAKE_CXX_STANDARD 17)
endif ()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (ADD_ABSEIL)
    add_subdirectory(lib/abseil-cpp)
    add_subdirectory(abseil)
endif ()
add_subdirectory(bugprone)
file(GLOB CERT_SRC "cert/*.cpp")
file(GLOB GOOGLE_SRC "google/*.cpp")
file(GLOB MODERNIZE_SRC "modernize/*.cpp")
file(GLOB PERFORMANCE_SRC "performance/*.cpp")
file(GLOB READABILITY_SRC "readability/*.cpp")
file(GLOB PORTABILITY_SRC "portability/*.cpp")
file(GLOB SRC "*.cpp")

add_executable(run_inspections main.cpp
        ${SRC} ${CERT_SRC} ${GOOGLE_SRC}
        ${MODERNIZE_SRC} ${PERFORMANCE_SRC} ${READABILITY_SRC} ${PORTABILITY_SRC}
        )