
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


# ############################## end of file ############################# #
