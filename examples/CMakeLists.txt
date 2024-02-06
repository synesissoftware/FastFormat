
include_directories(${CMAKE_SOURCE_DIR}/include)

if (APPLE)

    message("adding '/usr/local/include' to include-directories for 'examples'")

    include_directories("/usr/local/include")
endif()


if(UNIX)

    add_definitions(-DUNIX)
    add_definitions(-Dunix)
endif(UNIX)

if(WIN32)

    message(FATAL_ERROR "Use of CMake on Windows not currently supported")
endif(WIN32)


add_subdirectory(example.arguments.boolean)
add_subdirectory(example.arguments.character)
add_subdirectory(example.arguments.reals)
add_subdirectory(example.arguments.void_pointers)
add_subdirectory(example.ff_101)
add_subdirectory(example.ff_101.no_namespace)
add_subdirectory(example.flush)
add_subdirectory(example.inserter.hex)
add_subdirectory(example.inserter.integers)
if(WIN32)

    add_subdirectory(example.inserter.integers.WindowsLargeIntegers)
endif(WIN32)
add_subdirectory(example.inserter.reals)
add_subdirectory(example.iterators.format_iterator)
#[====[
add_subdirectory(example.memory.1)
#]====]
add_subdirectory(example.overload.2.custom_type.filter_type)
add_subdirectory(example.overload.2.custom_type.inserter)
add_subdirectory(example.overload.2.custom_type.string_access_shims)
add_subdirectory(example.overload.3.floatingpoint_columns)
add_subdirectory(example.overload.3.record_insert)
#[====[
add_subdirectory(example.overload.3.server_log)
#]====]
add_subdirectory(example.overload.3.tabulations)
add_subdirectory(example.pad.hash)
if(WIN32)

    add_subdirectory(example.sink.OutputDebugString)
endif(WIN32)
add_subdirectory(example.sink.c_string)


# ############################## end of file ############################# #

