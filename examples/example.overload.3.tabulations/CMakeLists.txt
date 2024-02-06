
add_executable(example.overload.3.tabulations
    example.overload.3.tabulations.cpp
)

target_link_libraries(example.overload.3.tabulations
    fastformat
)

target_compile_options(example.overload.3.tabulations PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-copy-with-user-provided-copy
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

