
# ######################################################################## #
# File:     /cmake/BuildType.cmake
#
# Purpose:  CMake module file (for BuildType)
#
# Created:  16th October 2019
# Updated:  12th January 2024
#
# ######################################################################## #


# Including this module sets the `CMAKE_BUILD_TYPE` value as follows:
#
#  1. If user specifies on the command line, then `CMAKE_BUILD_TYPE` already
#     has a valid, so this is accepted;
#  2. If the top-level .git directory is specified, then "Debug" is used;
#     otherwise
#  3. "Release" is used.
#
# Note:
#  - `CMAKE_BUILD_TYPE` is the build (configuration) type;
#  - `CMAKE_CONFIGURATION_TYPES` is, if specified, a list of valid
#    configurations (see
#    https://cmake.org/cmake/help/latest/variable/CMAKE_CONFIGURATION_TYPES.html);
#
# Example usage:
#
#[========[

# CMakeLists.txt

include(BuildType)

]========]


if(EXISTS "${CMAKE_SOURCE_DIR}/.git")

    set(default_build_type "Debug")
else()

    set(default_build_type "Release")
endif()

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)

    message(STATUS "Setting build type to '${default_build_type}' as none was specified.")

    set(CACHE CMAKE_BUILD_TYPE "${default_build_type}"
        STRING "Choose the type of build." FORCE
    )

    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
        "Debug" "Release" "MinSizeRel" "RelWithDebInfo"
    )
endif()


# ############################## end of file ############################# #

