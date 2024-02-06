
add_executable(test.component.iterators.format_iterator
    test.component.iterators.format_iterator.cpp
)

target_link_libraries(test.component.iterators.format_iterator
    fastformat
    xTests::xTests.core
)

target_compile_options(test.component.iterators.format_iterator PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-copy-with-user-provided-copy
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

