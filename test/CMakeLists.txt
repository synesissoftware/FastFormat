
include_directories(${CMAKE_SOURCE_DIR}/include)

if (APPLE)

	message("adding '/usr/local/include' to include-directories for 'test'")

	include_directories("/usr/local/include")
endif()


if(_BUILD_AS_UNIX)

	add_definitions(-DUNIX)
	add_definitions(-Dunix)
endif(_BUILD_AS_UNIX)


add_subdirectory(component)
add_subdirectory(performance)
add_subdirectory(scratch)
add_subdirectory(unit)


# ############################## end of file ############################# #

