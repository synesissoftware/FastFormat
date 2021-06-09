include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.unit.sink.null test.unit.sink.null.cpp )
target_link_libraries( test.unit.sink.null
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.unit.sink.null test.unit.sink.null )
add_custom_target( tests DEPENDS test.unit.sink.null )

