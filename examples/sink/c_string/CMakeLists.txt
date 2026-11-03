
add_executable(example.cpp.sink.c_string
	main.cpp
)

target_link_libraries(example.cpp.sink.c_string
	fastformat
)

target_compile_options(example.cpp.sink.c_string PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

	>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

