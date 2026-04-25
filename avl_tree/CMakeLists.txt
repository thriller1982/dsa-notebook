add_library(avl_tree STATIC
    avl_tree.c
    avl_tree.h
)

target_link_libraries(avl_tree PRIVATE
    common
)

target_include_directories(avl_tree PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)