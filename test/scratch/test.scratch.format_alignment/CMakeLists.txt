include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.scratch.format_alignment test.scratch.format_alignment.cpp )
target_link_libraries( test.scratch.format_alignment
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.scratch.format_alignment test.scratch.format_alignment )
add_custom_target( tests DEPENDS test.scratch.format_alignment )

