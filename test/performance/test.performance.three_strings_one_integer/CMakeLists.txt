include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.performance.three_strings_one_integer test.performance.three_strings_one_integer.cpp )
target_link_libraries( test.performance.three_strings_one_integer
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.performance.three_strings_one_integer test.performance.three_strings_one_integer )
add_custom_target( tests DEPENDS test.performance.three_strings_one_integer )

