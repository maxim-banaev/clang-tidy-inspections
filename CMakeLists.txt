cmake_minimum_required(VERSION 3.5)
project( CPP_12784 )

if ( CMAKE_VERSION VERSION_GREATER "3.10" )
    set( CMAKE_CXX_STANDARD 17 )
endif()

file(GLOB BUGPRONE_SRC "bugprone/*.cpp")
file(GLOB CERT_SRC "cert/*.cpp")
file(GLOB GOOGLE_SRC "google/*.cpp")
file(GLOB MODERNIZE_SRC "modernize/*.cpp")
file(GLOB PERFORMANCE_SRC "performance/*.cpp")
file(GLOB READABILITY_SRC "readability/*.cpp")
file(GLOB CPP_12784_SRC "*.cpp")

add_executable( CPP_12784 main.cpp
        ${CPP_12784_SRC} ${BUGPRONE_SRC} ${CERT_SRC} ${GOOGLE_SRC}
        ${MODERNIZE_SRC} ${PERFORMANCE_SRC} ${READABILITY_SRC}
        )
