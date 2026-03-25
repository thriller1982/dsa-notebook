add_library( list STATIC
        linked_list.c
        linked_list.h

        cursor_list.c
        cursor_list.h
)

target_link_libraries(list PRIVATE
        common
)

target_include_directories(list PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)