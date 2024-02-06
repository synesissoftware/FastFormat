
add_executable(test.component.FILE
    test.component.FILE.cpp
)

target_link_libraries(test.component.FILE
    fastformat
    xTests::xTests.core
)

target_compile_options(test.component.FILE PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-copy-with-user-provided-copy
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

