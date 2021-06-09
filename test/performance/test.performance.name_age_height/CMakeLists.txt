include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.performance.name_age_height test.performance.name_age_height.cpp )
target_link_libraries( test.performance.name_age_height
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.performance.name_age_height test.performance.name_age_height )
add_custom_target( tests DEPENDS test.performance.name_age_height )

