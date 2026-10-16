

#[====[
add_subdirectory(test.scratch.FILE)
#]====]
#[====[
add_subdirectory(test.scratch.ff_test_1)
#]====]
add_subdirectory(test.scratch.format_alignment)
add_subdirectory(test.scratch.format_defects)
#[====[
add_subdirectory(test.scratch.format_iterator)
#]====]
#[====[
add_subdirectory(test.scratch.implicit_integer)
#]====]
add_subdirectory(test.scratch.inserter.integer)
add_subdirectory(test.scratch.inserter.real)
if(MSVC)

	add_subdirectory(test.scratch.overload.3.BSTR_out_parameter)
endif(MSVC)
if(_BUILD_AS_WIN32)

	add_subdirectory(test.scratch.sink.WindowsConsole)
	add_subdirectory(test.scratch.sink.WindowsMessageBox)
endif(_BUILD_AS_WIN32)
add_subdirectory(test.scratch.sink.auto_buffer)
#[====[
add_subdirectory(test.scratch.sink.vectored_file)
#]====]
add_subdirectory(test.scratch.sinks.shim_string)
# STLSoft comstl speech uses std::auto_ptr and an unspecialised
# ISpVoice_, which the current MSVC library does not accept.
#[====[
if(_BUILD_AS_WIN32)

	add_subdirectory(test.scratch.speech)
endif(_BUILD_AS_WIN32)
#]====]
add_subdirectory(versions)


# ############################## end of file ############################# #

