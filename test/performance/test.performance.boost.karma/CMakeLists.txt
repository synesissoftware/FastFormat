include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.performance.boost.karma test.performance.boost.karma.cpp )
target_link_libraries( test.performance.boost.karma
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.performance.boost.karma test.performance.boost.karma )
add_custom_target( tests DEPENDS test.performance.boost.karma )

