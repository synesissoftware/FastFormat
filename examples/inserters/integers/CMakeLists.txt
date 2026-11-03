
add_executable(example.cpp.inserters.integers
	main.cpp
)

target_link_libraries(example.cpp.inserters.integers
	fastformat
)

target_compile_options(example.cpp.inserters.integers PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

	>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)



if(_BUILD_AS_WIN32)

	add_subdirectory(WindowsLargeIntegers)
endif(_BUILD_AS_WIN32)


# ############################## end of file ############################# #

