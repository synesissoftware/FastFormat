
add_executable(test.unit.api.initialisation
    test.unit.api.initialisation.cpp
)

target_link_libraries(test.unit.api.initialisation
    fastformat
    xTests::xTests.core
)

target_compile_options(test.unit.api.initialisation PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        # -Wno-deprecated-copy-with-user-provided-copy
        # -Wno-string-plus-int
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

