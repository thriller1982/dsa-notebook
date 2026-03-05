add_executable(max_subsequence_sum_demo
    max_subsequence_sum_demo.c
)

target_link_libraries(max_subsequence_sum_demo PRIVATE
        max_subsequence_sum
)
