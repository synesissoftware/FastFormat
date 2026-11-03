
add_executable(example.cpp.iterators.format_iterator
	main.cpp
)

target_link_libraries(example.cpp.iterators.format_iterator
	fastformat
)

target_compile_options(example.cpp.iterators.format_iterator PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

	>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

