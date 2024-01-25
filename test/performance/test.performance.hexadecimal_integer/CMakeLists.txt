include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.performance.hexadecimal_integer test.performance.hexadecimal_integer.cpp )
target_link_libraries( test.performance.hexadecimal_integer
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.performance.hexadecimal_integer test.performance.hexadecimal_integer )
add_custom_target( tests DEPENDS test.performance.hexadecimal_integer )

