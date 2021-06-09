include_directories (
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable (test.component.format_specification_defect_exceptions test.component.format_specification_defect_exceptions.cpp)
target_link_libraries (test.component.format_specification_defect_exceptions
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test (test.component.format_specification_defect_exceptions test.component.format_specification_defect_exceptions)
add_custom_target(tests DEPENDS test.component.format_specification_defect_exceptions)

