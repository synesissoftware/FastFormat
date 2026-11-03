
include_directories(${CMAKE_SOURCE_DIR}/include)

if (APPLE)

	message("adding '/usr/local/include' to include-directories for 'examples'")

	include_directories("/usr/local/include")
endif()


if(_BUILD_AS_UNIX)

	add_definitions(-DUNIX)
	add_definitions(-Dunix)
endif(_BUILD_AS_UNIX)

add_subdirectory(101)
add_subdirectory(arguments)
add_subdirectory(flush)
add_subdirectory(inserters)
add_subdirectory(iterators)
#[====[
add_subdirectory(memory)
#]====]
add_subdirectory(overload)
add_subdirectory(pad)
add_subdirectory(sink)


# ############################## end of file ############################# #
