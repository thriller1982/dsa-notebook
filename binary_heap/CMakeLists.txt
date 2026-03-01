add_library(binary_heap STATIC
    binary_heap.c
)

target_include_directories(binary_heap PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(binary_heap PUBLIC
    common
)
