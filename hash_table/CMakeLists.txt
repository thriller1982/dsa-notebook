add_library(hash_table STATIC
    sc_hash_table.c
    sc_hash_table.h
)

target_include_directories(hash_table PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(hash_table PUBLIC
    common
)
