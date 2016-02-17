include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.scratch.format_defects test.scratch.format_defects.cpp )
target_link_libraries( test.scratch.format_defects
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.scratch.format_defects test.scratch.format_defects )
add_custom_target( tests DEPENDS test.scratch.format_defects )

