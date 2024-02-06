
add_executable(test.performance.boost.karma
    test.performance.boost.karma.cpp
)

target_link_libraries(test.performance.boost.karma
    fastformat
    xTests::xTests.core
)

target_compile_options(test.performance.boost.karma PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-copy-with-user-provided-copy
        -Wno-string-plus-int
        -Wno-unused-value
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

