
add_executable(test.scratch.inserter.real
    test.scratch.inserter.real.cpp
)

target_link_libraries(test.scratch.inserter.real
    fastformat
    xTests::xTests.core
)

target_compile_options(test.scratch.inserter.real PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-copy-with-user-provided-copy
        -Wno-string-plus-int
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

