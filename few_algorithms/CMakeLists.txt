add_library(few_algorithms
        few_algorithms.c
        few_algorithms.h
)

target_include_directories(few_algorithms PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)