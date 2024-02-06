
add_executable(test.unit.api.crlf_for_platform
    test.unit.api.crlf_for_platform.cpp
)

target_link_libraries(test.unit.api.crlf_for_platform
    fastformat
    xTests::xTests.core
)

target_compile_options(test.unit.api.crlf_for_platform PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        # -Wno-deprecated-copy-with-user-provided-copy
        # -Wno-string-plus-int
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

