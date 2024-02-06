
add_executable(test.unit.format.standard_flags
    test.unit.format.standard_flags.cpp
)

target_link_libraries(test.unit.format.standard_flags
    fastformat
    xTests::xTests.core
)

target_compile_options(test.unit.format.standard_flags PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        # -Wno-deprecated-copy-with-user-provided-copy
        # -Wno-string-plus-int
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

