cmake_minimum_required( VERSION 3.10 )
project( CPP_12784 )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB BUGPRONE_SRC "bugprone/*.cpp")
file(GLOB BUGPRONE_HEADERS "include/bugprone/*.h")

file(GLOB CERT_SRC "cert/*.cpp")
file(GLOB CERT_HEADERS "include/cert/*.h")

file(GLOB GOOGLE_SRC "google/*.cpp")
file(GLOB GOOGLE_HEADERS "include/google/cert/*.h")

file(GLOB MODERNIZE_SRC "modernize/*.cpp")
file(GLOB MODERNIZE_HEADERS "include/modernize/*.h")

file(GLOB CPP_12784_SRC "*.cpp")
file(GLOB CPP_12784_HEADERS "include/*.h")

add_executable( CPP_12784 main.cpp
        ${CPP_12784_SRC} ${CPP_12784_HEADERS}
        ${BUGPRONE_SRC} ${BUGPRONE_HEADERS}
        ${CERT_SRC} ${CERT_HEADERS}
        ${GOOGLE_SRC} ${GOOGLE_HEADERS}
        ${MODERNIZE_SRC} ${MODERNIZE_HEADERS}
        )
