
add_executable(example.sink.OutputDebugString
    example.sink.OutputDebugString.cpp
)

target_link_libraries(example.sink.OutputDebugString
    fastformat
)

target_compile_options(example.sink.OutputDebugString PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-copy-with-user-provided-copy
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

