include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.performance.overload.ex.1 test.performance.overload.ex.1.cpp )
target_link_libraries( test.performance.overload.ex.1
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.performance.overload.ex.1 test.performance.overload.ex.1 )
add_custom_target( tests DEPENDS test.performance.overload.ex.1 )

