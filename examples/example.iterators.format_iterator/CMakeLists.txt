
add_executable(example.iterators.format_iterator
    example.iterators.format_iterator.cpp
)

target_link_libraries(example.iterators.format_iterator
    fastformat
)

target_compile_options(example.iterators.format_iterator PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-copy-with-user-provided-copy
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

