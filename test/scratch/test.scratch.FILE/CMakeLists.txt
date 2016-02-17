include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.scratch.FILE test.scratch.FILE.cpp )
target_link_libraries( test.scratch.FILE
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.scratch.FILE test.scratch.FILE )
add_custom_target( tests DEPENDS test.scratch.FILE )

