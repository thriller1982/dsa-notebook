add_library(array_queue STATIC
        array_queue.c
        array_queue.h
)

target_link_libraries(array_queue PUBLIC
        common
)

target_include_directories(array_queue PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)