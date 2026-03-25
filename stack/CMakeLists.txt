add_library(stack STATIC
        linked_stack.c
        linked_stack.h

        array_stack.c
        array_stack.h
)

target_link_libraries(stack PUBLIC
        common
)

target_include_directories(stack PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)