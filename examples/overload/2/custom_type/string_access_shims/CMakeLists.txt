
add_executable(example.cpp.overload.2.custom_type.string_access_shims
	main.cpp
)

target_link_libraries(example.cpp.overload.2.custom_type.string_access_shims
	fastformat
)

target_compile_options(example.cpp.overload.2.custom_type.string_access_shims PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

	>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

