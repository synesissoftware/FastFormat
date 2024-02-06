
add_executable(test.unit.sink.c_string
    test.unit.sink.c_string.cpp
)

target_link_libraries(test.unit.sink.c_string
    fastformat
    xTests::xTests.core
)

target_compile_options(test.unit.sink.c_string PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-copy-with-user-provided-copy
        -Wno-string-plus-int
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

