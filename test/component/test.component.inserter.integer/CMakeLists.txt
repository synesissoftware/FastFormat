include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.component.inserter.integer test.component.inserter.integer.cpp )
target_link_libraries( test.component.inserter.integer
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.component.inserter.integer test.component.inserter.integer )
add_custom_target( tests DEPENDS test.component.inserter.integer )

