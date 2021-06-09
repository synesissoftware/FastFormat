include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.component.inserter.real test.component.inserter.real.cpp )
target_link_libraries( test.component.inserter.real
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.component.inserter.real test.component.inserter.real )
add_custom_target( tests DEPENDS test.component.inserter.real )

