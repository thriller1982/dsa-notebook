add_library(max_subsequence_sum STATIC
        max_subsequence_sum.c
        max_subsequence_sum.h
)

target_include_directories(max_subsequence_sum PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
