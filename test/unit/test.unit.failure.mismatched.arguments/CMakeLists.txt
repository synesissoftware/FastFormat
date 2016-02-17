include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.unit.failure.mismatched.arguments test.unit.failure.mismatched.arguments.cpp )
target_link_libraries( test.unit.failure.mismatched.arguments
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.unit.failure.mismatched.arguments test.unit.failure.mismatched.arguments )
add_custom_target( tests DEPENDS test.unit.failure.mismatched.arguments )

