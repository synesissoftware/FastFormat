
add_executable(example.cpp.arguments.character
	main.cpp
)

target_link_libraries(example.cpp.arguments.character
	fastformat
)

target_compile_options(example.cpp.arguments.character PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

	>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

