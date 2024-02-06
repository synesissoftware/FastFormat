
add_executable(test.unit.inserters.integer
    test.unit.inserters.integer.cpp
)

target_link_libraries(test.unit.inserters.integer
    fastformat
    xTests::xTests.core
)

target_compile_options(test.unit.inserters.integer PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

