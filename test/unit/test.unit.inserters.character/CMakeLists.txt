
add_executable(test.unit.inserters.character
    test.unit.inserters.character.cpp
)

target_link_libraries(test.unit.inserters.character
    fastformat
    xTests::xTests.core
)

target_compile_options(test.unit.inserters.character PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

