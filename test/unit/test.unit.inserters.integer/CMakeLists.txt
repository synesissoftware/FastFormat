include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.unit.inserters.integer test.unit.inserters.integer.cpp )
target_link_libraries( test.unit.inserters.integer
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.unit.inserters.integer test.unit.inserters.integer )
add_custom_target( tests DEPENDS test.unit.inserters.integer )

