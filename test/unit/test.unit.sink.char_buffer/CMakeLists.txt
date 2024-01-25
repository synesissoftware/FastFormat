include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.unit.sink.char_buffer test.unit.sink.char_buffer.cpp )
target_link_libraries( test.unit.sink.char_buffer
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.unit.sink.char_buffer test.unit.sink.char_buffer )
add_custom_target( tests DEPENDS test.unit.sink.char_buffer )

