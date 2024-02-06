
add_executable(test.unit.api.fill_replacements
    test.unit.api.fill_replacements.cpp
)

target_link_libraries(test.unit.api.fill_replacements
    fastformat
    xTests::xTests.core
)

target_compile_options(test.unit.api.fill_replacements PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        # -Wno-deprecated-copy-with-user-provided-copy
        -Wno-missing-field-initializers
        # -Wno-string-plus-int
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

