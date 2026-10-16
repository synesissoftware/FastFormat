
add_executable(test.scratch.sinks.shim_string
	test.scratch.sinks.shim_string.cpp
)

target_link_libraries(test.scratch.sinks.shim_string
	fastformat
	$<IF:$<VERSION_LESS:${xTests_VERSION},"0.23">,xTests::xTests.core,xTests::core>
)

if(WIN32)

	target_link_libraries(test.scratch.sinks.shim_string
		UNIXem::UNIXem
	)
endif()

target_compile_options(test.scratch.sinks.shim_string PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-string-plus-int
	>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

