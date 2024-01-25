include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

add_executable( test.unit.inserters.character test.unit.inserters.character.cpp )
target_link_libraries( test.unit.inserters.character
    api
    fmt_cache
    fmt_spec_defect_handlers
    init_code_strings
    memory_pool
    replacements
    snprintf
    xTests::xTests
)
add_test( test.unit.inserters.character test.unit.inserters.character )
add_custom_target( tests DEPENDS test.unit.inserters.character )

