include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.scratch.sinks.shim_string test.scratch.sinks.shim_string.cpp )
target_link_libraries( test.scratch.sinks.shim_string
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.scratch.sinks.shim_string test.scratch.sinks.shim_string )
add_custom_target( tests DEPENDS test.scratch.sinks.shim_string )

