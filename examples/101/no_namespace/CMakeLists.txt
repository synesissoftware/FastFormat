
add_executable(example.cpp.101.no_namespace
	main.cpp
)

target_link_libraries(example.cpp.101.no_namespace
	fastformat
)

target_compile_options(example.cpp.101.no_namespace PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

	>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

