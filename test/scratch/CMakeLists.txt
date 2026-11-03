
#[====[
add_subdirectory(FILE)
#]====]
#[====[
add_subdirectory(ff_test_1)
#]====]
add_subdirectory(format_alignment)
add_subdirectory(format_defects)
#[====[
add_subdirectory(implicit_integer)
#]====]
add_subdirectory(inserters)
add_subdirectory(iterators)
add_subdirectory(overload)
add_subdirectory(sink)
# STLSoft comstl speech uses std::auto_ptr and an unspecialised
# ISpVoice_, which the current MSVC library does not accept.
#[====[
add_subdirectory(speech)
#]====]
add_subdirectory(versions)


# ############################## end of file ############################# #
