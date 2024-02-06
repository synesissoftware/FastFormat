
add_executable(example.arguments.void_pointers
    example.arguments.void_pointers.cpp
)

target_link_libraries(example.arguments.void_pointers
    fastformat
)

target_compile_options(example.arguments.void_pointers PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-copy-with-user-provided-copy
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

