
if(MSVC)

	add_subdirectory(CString)
endif(MSVC)
if(_BUILD_AS_WIN32)

	add_subdirectory(OutputDebugString)
endif(_BUILD_AS_WIN32)
add_subdirectory(auto_buffer)
add_subdirectory(c_string)
add_subdirectory(char_buffer)
add_subdirectory(null)
add_subdirectory(ostream)
add_subdirectory(stringstream)


# ############################## end of file ############################# #
