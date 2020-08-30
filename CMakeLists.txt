cmake_minimum_required(VERSION 3.5)
project(clang-tidy-inspection)

if (CMAKE_VERSION VERSION_GREATER "3.10")
    set(CMAKE_CXX_STANDARD 17)
endif ()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")


add_subdirectory(analyzer)

if (ADD_ABSEIL_CHECKS)
    set(absl_build_dir ${CMAKE_BINARY_DIR}/abseil-build)
    set(absl_src_dir ${CMAKE_BINARY_DIR}/abseil-src)
    include(thirdparty/DownloadAbseil.cmake)

    add_subdirectory(abseil)
endif ()

find_package(Boost)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    add_subdirectory(boost)
endif ()

add_subdirectory(bugprone)
add_subdirectory(cert)
add_subdirectory(cppcoreguidelines)
add_subdirectory(clion)
add_subdirectory(fuchsia)
add_subdirectory(google)
add_subdirectory(hicpp)
add_subdirectory(misc)
add_subdirectory(modernize)

find_package(MPI)
if (MPI_FOUND)
    add_subdirectory(mpi)
endif()

add_subdirectory(openmp)
add_subdirectory(performance)
add_subdirectory(zircon)

file(GLOB READABILITY_SRC "readability/*.cpp")
file(GLOB PORTABILITY_SRC "portability/*.cpp")
file(GLOB SRC "*.cpp")

add_executable(run_inspections main.cpp
        ${SRC} ${GOOGLE_SRC}
        ${PERFORMANCE_SRC} ${READABILITY_SRC} ${PORTABILITY_SRC}
        )