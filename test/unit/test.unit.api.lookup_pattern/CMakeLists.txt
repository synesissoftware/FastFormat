include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.unit.api.lookup_pattern test.unit.api.lookup_pattern.cpp )
target_link_libraries( test.unit.api.lookup_pattern
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.unit.api.lookup_pattern test.unit.api.lookup_pattern )
add_custom_target( tests DEPENDS test.unit.api.lookup_pattern )

