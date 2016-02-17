include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.performance.ten_strings_twice test.performance.ten_strings_twice.cpp )
target_link_libraries( test.performance.ten_strings_twice
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.performance.ten_strings_twice test.performance.ten_strings_twice )
add_custom_target( tests DEPENDS test.performance.ten_strings_twice )

