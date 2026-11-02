
add_executable(example.cpp.overload.2.custom_type.inserter
	main.cpp
)

target_link_libraries(example.cpp.overload.2.custom_type.inserter
	fastformat
)

target_compile_options(example.cpp.overload.2.custom_type.inserter PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-deprecated-declarations
	>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

