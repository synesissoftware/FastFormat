
add_executable(test.scratch.implicit_integer
    test.scratch.implicit_integer.cpp
)

target_link_libraries(test.scratch.implicit_integer
    fastformat
    xTests::xTests.core
)

target_compile_options(test.scratch.implicit_integer PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-copy-with-user-provided-copy
        -Wno-string-plus-int
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

