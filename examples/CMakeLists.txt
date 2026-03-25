add_executable(max_subsequence_sum_demo
    max_subsequence_sum_demo.c
)

add_executable(stack_demo
        stack_demo.c
)

target_link_libraries(stack_demo PRIVATE
        stack
)

target_link_libraries(max_subsequence_sum_demo PRIVATE
        max_subsequence_sum
)
