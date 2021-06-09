include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.unit.api.parse_format test.unit.api.parse_format.cpp )
target_link_libraries( test.unit.api.parse_format
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.unit.api.parse_format test.unit.api.parse_format )
add_custom_target( tests DEPENDS test.unit.api.parse_format )

