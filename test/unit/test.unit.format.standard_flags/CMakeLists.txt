include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.unit.format.standard_flags test.unit.format.standard_flags.cpp )
target_link_libraries( test.unit.format.standard_flags
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.unit.format.standard_flags test.unit.format.standard_flags )
add_custom_target( tests DEPENDS test.unit.format.standard_flags )

