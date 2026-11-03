
add_executable(example.cpp.101.normal
	main.cpp
)

target_link_libraries(example.cpp.101.normal
	fastformat
)

target_compile_options(example.cpp.101.normal PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

	>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

