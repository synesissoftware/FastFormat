
add_executable(example.cpp.inserters.integers.WindowsLargeIntegers
	main.cpp
)

target_link_libraries(example.cpp.inserters.integers.WindowsLargeIntegers
	fastformat
)

target_compile_options(example.cpp.inserters.integers.WindowsLargeIntegers PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

	>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

