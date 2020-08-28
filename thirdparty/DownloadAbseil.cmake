configure_file(
        ${CMAKE_CURRENT_LIST_DIR}/CMakeLists.txt.in
        ${CMAKE_BINARY_DIR}/abseil-cpp-external/CMakeLists.txt
)


# Configure and build the abseil source.
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/abseil-cpp-external )
if(result)
    message(FATAL_ERROR "CMake step for abseil-cpp failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/abseil-cpp-external)
if(result)
    message(FATAL_ERROR "Build step for abseil-cpp failed: ${result}")
endif()

add_subdirectory(${absl_src_dir} ${absl_build_dir} EXCLUDE_FROM_ALL)