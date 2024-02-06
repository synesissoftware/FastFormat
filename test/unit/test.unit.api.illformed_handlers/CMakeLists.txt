
add_executable(test.unit.api.illformed_handlers
    test.unit.api.illformed_handlers.cpp
)

target_link_libraries(test.unit.api.illformed_handlers
    fastformat
    xTests::xTests.core
)

target_compile_options(test.unit.api.illformed_handlers PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        # -Wno-deprecated-copy-with-user-provided-copy
        # -Wno-string-plus-int
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

