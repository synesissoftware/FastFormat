include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.performance.scenario1 test.performance.scenario1.cpp )
target_link_libraries( test.performance.scenario1
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.performance.scenario1 test.performance.scenario1 )
add_custom_target( tests DEPENDS test.performance.scenario1 )

