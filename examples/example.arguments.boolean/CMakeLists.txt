
add_executable(example.arguments.boolean
	example.arguments.boolean.cpp
)

target_link_libraries(example.arguments.boolean
	fastformat
)

target_compile_options(example.arguments.boolean PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

	>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

