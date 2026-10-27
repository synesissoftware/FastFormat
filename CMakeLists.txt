
# ######################################################################## #
# File:     /CMakeLists.txt
#
# Purpose:  Top-level CMake lists file for FastFormat
#
# Created:  6th February 2024
# Updated:  27th October 2026
#
# ######################################################################## #


# ##########################################################
# CMake

cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.31")
	cmake_policy(SET CMP0177 NEW)
endif()

# require out-of-source builds
file(TO_CMAKE_PATH "${CMAKE_CURRENT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")

	message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

# directory for CMake specific extensions and source files.
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})


# ##########################################################
# project

project(FastFormat
    DESCRIPTION "The fastest, most robust C++ formatting library"
    HOMEPAGE_URL "https://github.com/synesissoftware/FastFormat"
    LANGUAGES C CXX
)

string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWER)
string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPER)

# handle version number
set(RX_PROJ_TAG "${PROJECT_NAME_UPPER}")
set(RX_WS "[ \t]")
file(READ "${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/${PROJECT_NAME_LOWER}.h" _header_file)
string(REGEX MATCH "#${RX_WS}*define${RX_WS}+_?${RX_PROJ_TAG}_VER_MAJOR${RX_WS}+([0-9]+)" MAJOR_DUMMY ${_header_file})
set(_VERSION_MAJOR ${CMAKE_MATCH_1})
string(REGEX MATCH "#${RX_WS}*define${RX_WS}+_?${RX_PROJ_TAG}_VER_MINOR${RX_WS}+([0-9]+)" MINOR_DUMMY ${_header_file})
set(_VERSION_MINOR ${CMAKE_MATCH_1})
string(REGEX MATCH "#${RX_WS}*define${RX_WS}+_?${RX_PROJ_TAG}_VER_(PATCH|REVISION)${RX_WS}+([0-9]+)" PATCH_DUMMY ${_header_file})
set(_VERSION_PATCH ${CMAKE_MATCH_2})

# set project version number here
set(PROJECT_VERSION_MAJOR ${_VERSION_MAJOR})
set(PROJECT_VERSION_MINOR ${_VERSION_MINOR})
set(PROJECT_VERSION_PATCH ${_VERSION_PATCH})
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

# adhere strictly to C and C++ standards plus extensions. These are actually
# useless since we do not compile anything; they merely state our intention.
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON) # GNU extensions and POSIX standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

if(MSVC)

	if(MSVC_VERSION LESS 1800)

		add_compile_options("/wd4996")
	endif()

	# MSVC leaves __cplusplus at 199711L unless told otherwise, so
	# STLSoft trim still calls removed std::bind1st / std::ptr_fun.
	add_compile_options("/Zc:__cplusplus")

	# Stock illformed/mismatched handlers throw C++ exceptions from code
	# reached through the extern "C" API (fastformat_parseFormat, etc.).
	# Default /EHsc assumes extern "C" never throws and omits unwind info
	# for those frames, so catch clauses in callers never match (MSVC
	# examples/scratch defect demos escape to the outer handler). Use /EHs
	# so exceptions propagate through the C API correctly.
	foreach(_ff_eh_var
		CMAKE_C_FLAGS
		CMAKE_C_FLAGS_DEBUG
		CMAKE_C_FLAGS_MINSIZEREL
		CMAKE_C_FLAGS_RELEASE
		CMAKE_C_FLAGS_RELWITHDEBINFO
		CMAKE_CXX_FLAGS
		CMAKE_CXX_FLAGS_DEBUG
		CMAKE_CXX_FLAGS_MINSIZEREL
		CMAKE_CXX_FLAGS_RELEASE
		CMAKE_CXX_FLAGS_RELWITHDEBINFO
	)

		if(DEFINED ${_ff_eh_var})

			string(REGEX REPLACE "/EH[asc]+" "/EHs" ${_ff_eh_var} "${${_ff_eh_var}}")
		endif()
	endforeach()
	add_compile_options("/EHs")

	if(MSVC_VERSION LESS 1930)

		set(CMAKE_C_STANDARD 90)
		set(CMAKE_CXX_STANDARD 98)
	endif()

	if(MSVC_USE_MT)

		set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
	endif(MSVC_USE_MT)
else(MSVC)

	if(MSVC_USE_MT)

		# this here just to absorb warning about not using `MSVC_USE_MT` (to
		# enable **prepare_cmake.sh** to be simple)
	endif(MSVC_USE_MT)
endif(MSVC)


# ##########################################################
# dependencies, features, includes, and options

option(BUILD_EXAMPLES "Build examples" ON)

option(BUILD_TESTING "Build tests" ON)

option(FASTFORMAT_USE_WIDE_STRINGS "Build with wide string support" OFF)


# ##########################################################
# features

if(FASTFORMAT_USE_WIDE_STRINGS)

    add_definitions(-DFASTFORMAT_USE_WIDE_STRINGS)
    if(WIN32)

        add_definitions(-DUNICODE)
        add_definitions(-D_UNICODE)
    endif(WIN32)
endif(FASTFORMAT_USE_WIDE_STRINGS)


# ##########################################################
# dependencies
#
# required:
# - STLSoft;
#
# required (when BUILD_TESTING):
# - xTests;


# ############################
# STLSoft (required)
#
# We provide flexibility here, as in:
# 1. if a CMake variable STLSOFT is provided then it is used; otherwise
# 2. if an environment variable STLSOFT is provided then it then it is used;
#    otherwise
# 3. if the package STLSoft (via find_package()) is found then it is used;
#    otherwise
# 4. we abort

set(STLSoft_REQUIRED_VERSION_ 1.11)

if(NOT DEFINED STLSOFT AND NOT DEFINED ENV{STLSOFT})

    set(STLSoft_IS_PACKAGE_ TRUE)

    find_package(STLSoft ${STLSoft_REQUIRED_VERSION_} REQUIRED)

    message("-- CMake package STLSoft found (version ${STLSoft_VERSION}; ${STLSoft_REQUIRED_VERSION_} requested)")
else()

    set(STLSoft_IS_PACKAGE_ FALSE)

    if(DEFINED STLSOFT)

        message("-- STLSOFT provided as CMake variable with value '${STLSOFT}'")

        set(STLSOFT_INCLUDE_DIR ${STLSOFT}/include)
    else()

        message("-- STLSOFT provided as environment variable with value '$ENV{STLSOFT}'")

        set(STLSOFT_INCLUDE_DIR $ENV{STLSOFT}/include)
    endif()

    get_filename_component(STLSOFT_INCLUDE_DIR "${STLSOFT_INCLUDE_DIR}" ABSOLUTE)

    include_directories(${STLSOFT_INCLUDE_DIR})
endif()


# ############################
# xTests (testing only)

# ################################################
# includes - 1

include(BuildType)
include(LanguageFullVersion)
include(TargetMacros)


# ################################################
# dependencies, features, and options


# ######################################
# options

option(BUILD_EXAMPLES "Build examples" ON)

option(BUILD_TESTING "Build tests" ON)

option(NO_CSTRING_CPP_API "Disable C++ API (and associated C++ examples/tests)" OFF)


# ######################################
# features


# ######################################
# dependencies
#
# required (when BUILD_TESTING):
# - STLSoft - required for testing (also used by remaining C++ tests/examples);
# - xTests - required for testing;
#
# optional:
# - shwild - for enhanced match constructs in xTests (unless NO_SHWILD);


# ############################
# STLSoft
#
# We provide flexibility here, as in:
# 1. if a CMake variable STLSOFT is provided then it is used; otherwise
# 2. if an environment variable STLSOFT is provided then it then it is used;
#    otherwise
# 3. if the package STLSoft (via find_package()) is found then it is used;
#    otherwise
# 4. we abort

if(BUILD_TESTING)

	if(DEFINED STLSOFT)

		message("-- STLSOFT provided as CMake variable with value '${STLSOFT}'")

		set(STLSOFT_INCLUDE_DIR ${STLSOFT}/include)
	elseif(DEFINED ENV{STLSOFT})

		message("-- STLSOFT provided as environment variable with value '$ENV{STLSOFT}'")

		set(STLSOFT_INCLUDE_DIR $ENV{STLSOFT}/include)
	else()

		set(STLSoft_REQUIRED_VERSION_ 1.11)

		find_package(STLSoft ${STLSoft_REQUIRED_VERSION_} REQUIRED)

		message("-- CMake package STLSoft found (version ${STLSoft_VERSION}; ${STLSoft_REQUIRED_VERSION_} requested)")
	endif()

	if(DEFINED STLSOFT_INCLUDE_DIR OR DEFINED STLSoft_FOUND)

		include_directories(${STLSOFT_INCLUDE_DIR})

		add_compile_definitions(HAS_STLSOFT)
		add_compile_definitions(HAS_STLSoft)
	endif()
endif(BUILD_TESTING)


# ############################
# shwild (optional)

if(BUILD_TESTING)

	if(NOT (NO_SHWILD))

		if(BUILD_TESTING)

			find_package(shwild QUIET)

			if(shwild_FOUND)

				message("-- CMake package shwild found (version ${shwild_VERSION})")

				add_compile_definitions(
					HAS_shwild
					HAS_SHWILD
				)

				add_compile_definitions(FASTFORMAT_HAS_SHWILD)
				add_compile_definitions(XTESTS_HAS_SHWILD) # Legacy form, and should be removed later
			endif(shwild_FOUND)
		endif(BUILD_TESTING)
	endif()
endif(BUILD_TESTING)


# ############################
# xTests

if(BUILD_TESTING)

	set(xTests_REQUIRED_VERSION_ 0.28)

	find_package(xTests ${xTests_REQUIRED_VERSION_} REQUIRED)

	message("-- CMake package xTests found (version ${xTests_VERSION}; ${xTests_REQUIRED_VERSION_} requested)")

	add_compile_definitions(
		HAS_xTests
		HAS_XTESTS
	)
endif(BUILD_TESTING)


# ############################
# UNIXem
#
# Windows scratch programs include <unixem/unixem.h>. UNIXem configure
# rejects every other host, so the package is required only on Windows.

if(WIN32 AND BUILD_TESTING)

	set(UNIXem_REQUIRED_VERSION_ 1.14.2)

	find_package(UNIXem ${UNIXem_REQUIRED_VERSION_} REQUIRED)

	message("-- CMake package UNIXem found (version ${UNIXem_VERSION}; ${UNIXem_REQUIRED_VERSION_} requested)")

	add_compile_definitions(
		HAS_UNIXem
		HAS_UNIXEM
	)
endif()


# ################################################
# includes - 2

include(CMakePackageConfigHelpers)
if(BUILD_TESTING)

	include(CTest)
endif(BUILD_TESTING)
include(GNUInstallDirs)


# ##########################################################
# targets

# ################################################
# custom definitions

if(UNIX)

	set(_BUILD_AS_UNIX 1)

	message("-- Operating system Unix")
else(UNIX)

	if(WIN32)

		if(USE_UNIXEM)

			set(_BUILD_AS_UNIX 1)

			message("-- Operating system Unix (synthesised on Windows)")
		else(USE_UNIXEM)

			set(_BUILD_AS_WIN32 1)

			message("-- Operating system Windows")
		endif(USE_UNIXEM)
	else(WIN32)

		message("-- Operating system unknown")
	endif(WIN32)
endif(UNIX)


# ################################################
# main libraries

add_subdirectory(src)


# ################################################
# examples

if(BUILD_EXAMPLES)

	message("-- enabled building of examples ...")

	add_subdirectory(examples)
else(BUILD_EXAMPLES)

	message("-- disabled building of examples - define BUILD_EXAMPLES to enable")
endif(BUILD_EXAMPLES)


# ################################################
# tests

if(BUILD_TESTING)

	message("-- enabled building of tests ...")

	add_subdirectory(test)
else(BUILD_TESTING)

	message("-- disabled building of tests - define BUILD_TESTING to enable")
endif(BUILD_TESTING)


# ##########################################################
# export

set(EXPORT_NAME ${PROJECT_NAME_LOWER})

configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/cmake/${EXPORT_NAME}-config.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config.cmake
	INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/${EXPORT_NAME}/cmake
)

write_basic_package_version_file(
	${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config-version.cmake
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY AnyNewerVersion
)

export(EXPORT project-targets
	FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-targets.cmake"
	NAMESPACE "${PROJECT_NAME}::"
)

install(EXPORT project-targets
	NAMESPACE "${PROJECT_NAME}::"
	FILE "${EXPORT_NAME}-targets.cmake"
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${EXPORT_NAME}
)

install( FILES
	"${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config.cmake"
	"${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config-version.cmake"
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${EXPORT_NAME}
)


# ##########################################################
# completion

message(NOTICE "Generating CMake build scripts for ${PROJECT_NAME} ${PROJECT_VERSION}, for C${CMAKE_C_STANDARD} C++${CMAKE_CXX_STANDARD}, with build type ${CMAKE_BUILD_TYPE}")


# ############################## end of file ############################# #

