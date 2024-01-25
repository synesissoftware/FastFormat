include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.component.sink.string.write test.component.sink.string.write.cpp )
target_link_libraries( test.component.sink.string.write
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.component.sink.string.write test.component.sink.string.write )
add_custom_target( tests DEPENDS test.component.sink.string.write )

