
add_executable(example.ff_101.no_namespace
    example.ff_101.no_namespace.cpp
)

target_link_libraries(example.ff_101.no_namespace
    fastformat
)

target_compile_options(example.ff_101.no_namespace PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-copy-with-user-provided-copy
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

