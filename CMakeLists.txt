cmake_minimum_required(VERSION 3.16)
project(dsa_notebook C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

option(BUILD_EXAMPLES "Build example executables" ON)
option(BUILD_TESTS "Build tests" OFF)

add_subdirectory(common)
add_subdirectory(list)
add_subdirectory(max_subsequence_sum)
add_subdirectory(stack)
add_subdirectory(queue)
add_subdirectory(few_algorithms)
add_subdirectory(binary_search_tree)
add_subdirectory(avl_tree)

if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
