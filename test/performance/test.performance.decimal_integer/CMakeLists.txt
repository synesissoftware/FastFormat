include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.performance.decimal_integer test.performance.decimal_integer.cpp )
target_link_libraries( test.performance.decimal_integer
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.performance.decimal_integer test.performance.decimal_integer )
add_custom_target( tests DEPENDS test.performance.decimal_integer )

