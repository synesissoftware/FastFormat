include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.unit.sink.ostream test.unit.sink.ostream.cpp )
target_link_libraries( test.unit.sink.ostream
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.unit.sink.ostream test.unit.sink.ostream )
add_custom_target( tests DEPENDS test.unit.sink.ostream )

