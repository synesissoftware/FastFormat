
add_executable(test.component.sink.null
    test.component.sink.null.cpp
)

target_link_libraries(test.component.sink.null
    fastformat
    xTests::xTests.core
)

target_compile_options(test.component.sink.null PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-copy-with-user-provided-copy
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

