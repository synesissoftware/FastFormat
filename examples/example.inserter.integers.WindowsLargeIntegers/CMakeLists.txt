
add_executable(example.inserter.integers.WindowsLargeIntegers
    example.inserter.integers.WindowsLargeIntegers.cpp
)

target_link_libraries(example.inserter.integers.WindowsLargeIntegers
    fastformat
)

target_compile_options(example.inserter.integers.WindowsLargeIntegers PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-copy-with-user-provided-copy
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

