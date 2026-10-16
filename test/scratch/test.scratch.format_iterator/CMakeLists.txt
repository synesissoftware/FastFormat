
add_executable(test.scratch.format_iterator
	test.scratch.format_iterator.cpp
)

target_link_libraries(test.scratch.format_iterator
	fastformat
	$<IF:$<VERSION_LESS:${xTests_VERSION},"0.23">,xTests::xTests.core,xTests::core>
)

if(WIN32)

	target_link_libraries(test.scratch.format_iterator
		UNIXem::UNIXem
	)
endif()

target_compile_options(test.scratch.format_iterator PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-string-plus-int
	>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

