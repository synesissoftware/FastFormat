
add_executable(test.component.sink.string.fmt
	test.component.sink.string.fmt.cpp
)

target_link_libraries(test.component.sink.string.fmt
	fastformat
	$<IF:$<VERSION_LESS:${xTests_VERSION},"0.23">,xTests::xTests.core,xTests::core>
)

target_compile_options(test.component.sink.string.fmt PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-deprecated-copy-with-user-provided-copy
	>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

