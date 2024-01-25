include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.unit.shims.fast_integers test.unit.shims.fast_integers.cpp )
target_link_libraries( test.unit.shims.fast_integers
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.unit.shims.fast_integers test.unit.shims.fast_integers )
add_custom_target( tests DEPENDS test.unit.shims.fast_integers )

