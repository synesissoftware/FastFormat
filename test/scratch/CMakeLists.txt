

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
if(WIN32)

    add_subdirectory(test.scratch.overload.3.BSTR_out_parameter)
    add_subdirectory(test.scratch.sink.WindowsConsole)
    add_subdirectory(test.scratch.sink.WindowsMessageBox)
endif(WIN32)
add_subdirectory(test.scratch.sink.auto_buffer)
#[====[
add_subdirectory(test.scratch.sink.vectored_file)
#]====]
add_subdirectory(test.scratch.sinks.shim_string)
if(WIN32)

    add_subdirectory(test.scratch.speech)
endif(WIN32)


# ############################## end of file ############################# #

