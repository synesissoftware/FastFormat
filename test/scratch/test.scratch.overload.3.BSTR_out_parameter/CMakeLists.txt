
add_executable(test.scratch.overload.3.BSTR_out_parameter
    test.scratch.overload.3.BSTR_out_parameter.cpp
)

target_link_libraries(test.scratch.overload.3.BSTR_out_parameter
    fastformat
    xTests::xTests.core
)

target_compile_options(test.scratch.overload.3.BSTR_out_parameter PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-copy-with-user-provided-copy
        -Wno-string-plus-int
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

