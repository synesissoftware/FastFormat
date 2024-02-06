
include_directories(${CMAKE_SOURCE_DIR}/include)

if (APPLE)

    message("adding '/usr/local/include' to include-directories for 'test'")

    include_directories("/usr/local/include")
endif()


if(UNIX)

    add_definitions(-DUNIX)
    add_definitions(-Dunix)
endif(UNIX)

if(WIN32)

    message(FATAL_ERROR "Use of CMake on Windows not currently supported")
endif(WIN32)


add_subdirectory(component)
add_subdirectory(performance)
add_subdirectory(scratch)
add_subdirectory(unit)


# ############################## end of file ############################# #

