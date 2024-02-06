
add_subdirectory(test.unit.api.accum_slice_lens)
add_subdirectory(test.unit.api.crlf_for_platform)
add_subdirectory(test.unit.api.fill_replacements)
add_subdirectory(test.unit.api.illformed_handlers)
add_subdirectory(test.unit.api.initialisation)
add_subdirectory(test.unit.api.lookup_pattern)
add_subdirectory(test.unit.api.mismatched_handlers)
add_subdirectory(test.unit.api.parse_format)
add_subdirectory(test.unit.bundle.util)
if(WIN32)

    add_subdirectory(test.unit.bundle.winini)
endif(WIN32)
#[====[
add_subdirectory(test.unit.failure.mismatched.arguments)
#]====]
add_subdirectory(test.unit.format.standard_flags)
add_subdirectory(test.unit.inserters.character)
add_subdirectory(test.unit.inserters.integer)
add_subdirectory(test.unit.shims.fast_integers)
add_subdirectory(test.unit.sink.auto_buffer)
add_subdirectory(test.unit.sink.c_string)
add_subdirectory(test.unit.sink.char_buffer)
if(WIN32)

    add_subdirectory(test.unit.sink.CString)
endif(WIN32)
add_subdirectory(test.unit.sink.null)
add_subdirectory(test.unit.sink.ostream)
if(WIN32)

    add_subdirectory(test.unit.sink.OutputDebugString)
endif(WIN32)
add_subdirectory(test.unit.sink.stringstream)


# ############################## end of file ############################# #

