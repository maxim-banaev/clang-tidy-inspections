cmake_minimum_required(VERSION 3.5)
project(clang-tidy-inspection)

if (CMAKE_VERSION VERSION_GREATER "3.10")
    set(CMAKE_CXX_STANDARD 17)
endif ()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")


add_subdirectory(analyzer)
if (ADD_ABSEIL)
    add_subdirectory(lib/abseil-cpp)
    add_subdirectory(abseil)
endif ()

find_package(Boost)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    add_subdirectory(boost)
endif ()

add_subdirectory(bugprone)
add_subdirectory(cert)
add_subdirectory(clion)

add_subdirectory(modernize)
add_subdirectory(openmp)

add_subdirectory(cppcoreguidelines)

file(GLOB GOOGLE_SRC "google/*.cpp")
file(GLOB PERFORMANCE_SRC "performance/*.cpp")
file(GLOB READABILITY_SRC "readability/*.cpp")
file(GLOB PORTABILITY_SRC "portability/*.cpp")
file(GLOB SRC "*.cpp")

add_executable(run_inspections main.cpp
        ${SRC} ${GOOGLE_SRC}
        ${PERFORMANCE_SRC} ${READABILITY_SRC} ${PORTABILITY_SRC}
        )