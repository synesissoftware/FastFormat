
add_executable(example.cpp.overload.2.custom_type.filter_type
	main.cpp
)

target_link_libraries(example.cpp.overload.2.custom_type.filter_type
	fastformat
)

target_compile_options(example.cpp.overload.2.custom_type.filter_type PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

	>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

