
add_executable(example.overload.3.record_insert
    example.overload.3.record_insert.cpp
)

target_link_libraries(example.overload.3.record_insert
    fastformat
)

target_compile_options(example.overload.3.record_insert PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-copy-with-user-provided-copy
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

