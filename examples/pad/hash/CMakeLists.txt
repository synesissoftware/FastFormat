
add_executable(example.cpp.pad.hash
	main.cpp
)

target_link_libraries(example.cpp.pad.hash
	fastformat
)

target_compile_options(example.cpp.pad.hash PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

	>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

