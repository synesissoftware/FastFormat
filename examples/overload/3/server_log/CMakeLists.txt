
add_executable(example.cpp.overload.3.server_log
	main.cpp
)

target_link_libraries(example.cpp.overload.3.server_log
	fastformat
)

target_compile_options(example.cpp.overload.3.server_log PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

	>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

