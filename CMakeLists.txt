cmake_minimum_required (VERSION 2.8)
project (FastFormat C CXX)
enable_testing()
set(FastFormat_VERSION 0.7.1)

set (BUILD_SHARED_LIBS FALSE)

# Project include directory
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/include")

find_package (xTests 0.18 CONFIG QUIET)
if(NOT xTests_FOUND)
   message(AUTHOR_WARNING "The xTests framework not found. Cannot build tests.")
endif()

find_package( STLSoft 1.9.125 REQUIRED )
find_package( shwild QUIET )

add_subdirectory(src)
if( xTests_FOUND )
   add_subdirectory(test EXCLUDE_FROM_ALL)
endif( xTests_FOUND )

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

include(GenerateExportHeader)
include(CMakePackageConfigHelpers)

include_directories (${STLSoft_INCLUDE_DIRS})
add_library(FastFormat
   src/api.cpp
   src/fmt_cache.cpp
   src/fmt_spec_defect_handlers.cpp
   src/init_code_strings.cpp
   src/memory_pool.cpp
   src/replacements.cpp
   src/snprintf.cpp
)
generate_export_header(FastFormat)
set_property(TARGET FastFormat PROPERTY VERSION ${FastFormat_VERSION})
set_property(TARGET FastFormat PROPERTY SOVERSION 3)
set_property(TARGET FastFormat PROPERTY
  INTERFACE_FastFormat_MAJOR_VERSION 3)
set_property(TARGET FastFormat APPEND PROPERTY
  COMPATIBLE_INTERFACE_STRING FastFormat_MAJOR_VERSION
)

install(TARGETS FastFormat EXPORT FastFormatTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
)
install(
  DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/fastformat"
  DESTINATION include
  COMPONENT Devel
)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/FastFormatConfigVersion.cmake"
  VERSION ${FastFormat_VERSION}
  COMPATIBILITY AnyNewerVersion
)

export(TARGETS FastFormat
  FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/FastFormatTargets.cmake"
  NAMESPACE FastFormat::
)
set(PACKAGE_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
configure_file(cmake/FastFormatConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/FastFormatConfig.cmake"
  @ONLY
)
export(PACKAGE FastFormat)

set(ConfigPackageLocation cmake/FastFormat)
install(EXPORT FastFormatTargets
  FILE FastFormatTargets.cmake
  NAMESPACE FastFormat::
  DESTINATION ${ConfigPackageLocation}
)
install( FILES
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/FastFormatConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/FastFormatConfigVersion.cmake"
  DESTINATION ${ConfigPackageLocation}
  COMPONENT Devel
)

