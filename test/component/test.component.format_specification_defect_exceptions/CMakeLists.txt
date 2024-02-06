
add_executable(test.component.format_specification_defect_exceptions
    test.component.format_specification_defect_exceptions.cpp
)

target_link_libraries(test.component.format_specification_defect_exceptions
    fastformat
    xTests::xTests.core
)

target_compile_options(test.component.format_specification_defect_exceptions PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-copy-with-user-provided-copy
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

