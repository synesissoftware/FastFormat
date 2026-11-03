
add_executable(example.cpp.arguments.reals
	main.cpp
)

target_link_libraries(example.cpp.arguments.reals
	fastformat
)

target_compile_options(example.cpp.arguments.reals PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

	>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

