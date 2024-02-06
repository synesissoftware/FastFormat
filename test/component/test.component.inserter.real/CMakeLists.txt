
add_executable(test.component.inserter.real
    test.component.inserter.real.cpp
)

target_link_libraries(test.component.inserter.real
    fastformat
    xTests::xTests.core
)

target_compile_options(test.component.inserter.real PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-copy-with-user-provided-copy
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

