include (ExternalProject)

### All small libraries, created by Matt Wilson.

# STLSoft library v1.9.121
ExternalProject_Add( STLSoft
   GIT_REPOSITORY https://github.com/synesissoftware/STLSoft-1.9.git
   GIT_TAG master
   TIMEOUT 10
   # Let the files rest where they are! This is header-only library.
   CONFIGURE_COMMAND ""
   BUILD_COMMAND ""
   INSTALL_COMMAND ""
   LOG_DOWNLOAD ON
)
ExternalProject_Get_Property(STLSoft source_dir)
set(STLSoft_INCLUDE_DIRS ${source_dir}/include
   CACHE INTERNAL "Filepath to STLSoft includes")

# # xTests library
# ExternalProject_Add( xTests
#   GIT_REPOSITORY https://github.com/mikkoi/xTests.git
#   GIT_TAG cmake-build
#   TIMEOUT 10
#   # UPDATE_COMMAND ${GIT_EXECUTABLE} reset --hard c64e7dd9e3712f644212378259c63aa059d5b009
#   # Let the files rest where they are!
#   # CONFIGURE_COMMAND ""
#   # SOURCE_DIR /home/mikko/other/own_github/xTests
#   # CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=""
#   # BUILD_COMMAND ""
#   INSTALL_COMMAND ""
#   LOG_DOWNLOAD ON
# )
# ExternalProject_Get_Property(xTests source_dir)
# set (xTests_INCLUDE_DIRS ${source_dir}/include PARENT_SCOPE)
# ExternalProject_Get_Property(xTests binary_dir)
#
# # Create imported target xTests::xTests
# add_library(xTests::xTests STATIC IMPORTED)
#
# # Import target "xTests::xTests" for configuration ""
# set_property(TARGET xTests::xTests APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
# set_target_properties(xTests::xTests PROPERTIES
#    IMPORTED_LOCATION_NOCONFIG "${binary_dir}/libxTests.a"
#    IMPORTED_SONAME_NOCONFIG "libxTests.a"
# )

