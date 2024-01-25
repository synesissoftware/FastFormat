include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

if( FALSE ) # File fastformat/sinks/string_array.hpp is not ready!
add_executable( test.component.sink.string_array test.component.sink.string_array.cpp )
target_link_libraries( test.component.sink.string_array
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.component.sink.string_array test.component.sink.string_array )
add_custom_target( tests DEPENDS test.component.sink.string_array )
endif( FALSE)

