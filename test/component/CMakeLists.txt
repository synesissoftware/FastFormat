
add_subdirectory(test.component.FILE)
add_subdirectory(test.component.FILE_stream)
add_subdirectory(test.component.format_specification_defect_exceptions)
add_subdirectory(test.component.inserter.hex)
add_subdirectory(test.component.inserter.integer)
add_subdirectory(test.component.inserter.real)
add_subdirectory(test.component.iterators.format_iterator)
add_subdirectory(test.component.sink.auto_buffer)
if(MSVC)

	add_subdirectory(test.component.sink.CComBSTR)
endif(MSVC)
add_subdirectory(test.component.sink.null)
add_subdirectory(test.component.sink.ostream)
#[====[
add_subdirectory(test.component.sink.string_array)
#]====]
add_subdirectory(test.component.sink.string.fmt)
add_subdirectory(test.component.sink.string.write)


# ############################## end of file ############################# #

