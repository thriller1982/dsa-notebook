add_library(binary_search_tree STATIC
    binary_search_tree.c
    binary_search_tree.h
)

target_link_libraries(binary_search_tree PRIVATE
    common
)

target_include_directories(binary_search_tree PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)