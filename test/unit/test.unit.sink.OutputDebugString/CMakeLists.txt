
add_executable(test.unit.sink.OutputDebugString
    test.unit.sink.OutputDebugString.cpp
)

target_link_libraries(test.unit.sink.OutputDebugString
    fastformat
    xTests::xTests.core
)

target_compile_options(test.unit.sink.OutputDebugString PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-copy-with-user-provided-copy
        -Wno-string-plus-int
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

