include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.scratch.sink.vectored_file test.scratch.sink.vectored_file.cpp )
target_link_libraries( test.scratch.sink.vectored_file
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.scratch.sink.vectored_file test.scratch.sink.vectored_file )
add_custom_target( tests DEPENDS test.scratch.sink.vectored_file )

