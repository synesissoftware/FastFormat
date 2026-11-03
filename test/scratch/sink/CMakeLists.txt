
if(_BUILD_AS_WIN32)

	add_subdirectory(WindowsConsole)
	add_subdirectory(WindowsMessageBox)
endif(_BUILD_AS_WIN32)
add_subdirectory(auto_buffer)
add_subdirectory(shim_string)
#[====[
add_subdirectory(vectored_file)
#]====]


# ############################## end of file ############################# #
