
# NOTE: this tree does not (yet) provide define_example_program(), so, in
# keeping with its sibling scratch/example/test lists, the reporter is
# declared via add_executable(). The target name must remain
# test.scratch.versions (Phase 4c): do not hide argv0 with OUTPUT_NAME.
add_executable(test.scratch.versions
	main.cpp
)

target_link_libraries(test.scratch.versions
	PRIVATE
		fastformat
)

if(shwild_FOUND)

	target_link_libraries(test.scratch.versions
		PRIVATE
			shwild::core
	)
endif()

if(UNIXem_FOUND)

	target_link_libraries(test.scratch.versions
		PRIVATE
			UNIXem::UNIXem
	)
endif()

if(TARGET xTests::core)

	target_link_libraries(test.scratch.versions
		PRIVATE
			xTests::core
	)
endif()


# ############################## end of file ############################# #
