############################################################################
# File:     makefile
#
# Purpose:  Makefile for the FastFormat project, for the GCC 3.4
#           compiler, on Win32
#
# Created:  22nd December 2007
# Updated:  16th August 2016
#
############################################################################


############################################################################
# Environment check
#

ifndef STLSOFT
$(error STLSOFT must be defined)
endif # !STLSOFT

############################################################################
# Symbols

########################################
# Project & compiler version

COMP_TAG            =   gcc34
ARCH_TAG            =   
OS_TAG              =   
PROJ_TAG            =   fastformat
PROJ_VER_MAJOR      =   0
PROJ_TAG_VER        =   $(PROJ_TAG).$(PROJ_VER_MAJOR)
COMP_ARCH_OS_TAG    =   $(COMP_TAG)$(OS_TAG)$(ARCH_TAG)

LOKI_SFMT_VER_MAJOR =   0
LOKI_SFMT_TAG_VER   =   loki.safefmt.$(LOKI_SFMT_VER_MAJOR)

SHWILD_VER_MAJOR    =   0
SHWILD_TAG_VER      =   shwild.$(SHWILD_VER_MAJOR)

XCONTRACT_VER_MAJOR =   0
XCONTRACT_TAG_VER   =   xtests.$(XCONTRACT_VER_MAJOR)

XTESTS_VER_MAJOR    =   0
XTESTS_TAG_VER      =   xtests.$(XTESTS_VER_MAJOR)

PROJ_MAKEFILE_NAME  =   makefile

########################################
# Testing verbosity

ifndef TEST_VERBOSITY
TEST_VERBOSITY      =   2
endif # !TEST_VERBOSITY

########################################
# Directories

PROJ_BASE_DIR				=	..\..
PROJ_BIN_DIR				=	$(PROJ_BASE_DIR)\bin
PROJ_INCLUDE_DIR			=	$(PROJ_BASE_DIR)\include
PROJ_LIB_DIR				=	$(PROJ_BASE_DIR)\lib
PROJ_OBJ_DIR				=	.
PROJ_SRC_DIR				=	$(PROJ_BASE_DIR)\src
PROJ_EXAMPLES_DIR			=	$(PROJ_BASE_DIR)\examples
PROJ_SAMPLES_DIR			=	$(PROJ_BASE_DIR)\samples
PROJ_BUNDLES_DIR			=	$(PROJ_BASE_DIR)\test\data\bundles
PROJ_TEST_ROOT_DIR			=	$(PROJ_BASE_DIR)\test
PROJ_TEST_COMPONENT_DIR		=	$(PROJ_TEST_ROOT_DIR)\component
PROJ_TEST_PERFORMANCE_DIR	=	$(PROJ_TEST_ROOT_DIR)\performance
PROJ_TEST_SCRATCH_DIR		=	$(PROJ_TEST_ROOT_DIR)\scratch
PROJ_TEST_UNIT_DIR			=	$(PROJ_TEST_ROOT_DIR)\unit

BITBUCKET_SRC_DIR			=	$(PROJ_SRC_DIR)\bitbucket

LOKI_SFMT_SRC_DIR			=	$(PROJ_SRC_DIR)\loki.safefmt

SHWILD_PROJ_INCLUDE     =   
ifdef FASTFORMAT_SHWILD_BASE_DIR
SHWILD_INCLUDE_DIR      =   $(FASTFORMAT_SHWILD_BASE_DIR)\include
SHWILD_SRC_DIR          =   $(FASTFORMAT_SHWILD_BASE_DIR)\src
SHWILD_PROJ_INCLUDE     =   -I$(SHWILD_INCLUDE_DIR)
else
SHWILD_INCLUDE_DIR      =   $(PROJ_BASE_DIR)\include
SHWILD_SRC_DIR          =   $(PROJ_SRC_DIR)\shwild
endif # !FASTFORMAT_SHWILD_BASE_DIR

XCONTRACT_PROJ_INCLUDE  =   
ifdef FASTFORMAT_XCONTRACT_BASE_DIR
XCONTRACT_INCLUDE_DIR   =   $(FASTFORMAT_XCONTRACT_BASE_DIR)\include
XCONTRACT_SRC_DIR       =   $(FASTFORMAT_XCONTRACT_BASE_DIR)\src
XCONTRACT_PROJ_INCLUDE  =   -I$(XCONTRACT_INCLUDE_DIR)
else
XCONTRACT_INCLUDE_DIR   =   $(PROJ_BASE_DIR)\include
XCONTRACT_SRC_DIR       =   $(PROJ_SRC_DIR)\xcontract
endif # !FASTFORMAT_XCONTRACT_BASE_DIR

XTESTS_PROJ_INCLUDE     =   
ifdef FASTFORMAT_XTESTS_BASE_DIR
XTESTS_INCLUDE_DIR      =   $(FASTFORMAT_XTESTS_BASE_DIR)\include
XTESTS_SRC_DIR          =   $(FASTFORMAT_XTESTS_BASE_DIR)\src
XTESTS_PROJ_INCLUDE     =   -I$(XTESTS_INCLUDE_DIR)
else
XTESTS_INCLUDE_DIR      =   $(PROJ_BASE_DIR)\include
XTESTS_SRC_DIR          =   $(PROJ_SRC_DIR)\xtests
endif # !FASTFORMAT_XTESTS_BASE_DIR

########################################
# tools

CC                      =   gcc
CPPC                    =   g++
AR                      =   ar
LD                      =   g++
RM                      =   del /f
CP                      =   copy
RC                      =   rc


# Lib

LIBS_LEADER             =   

# lib paths

ENV_LIBPATHS        =
COMMON_LIBPATHS         =


LIBPATHS=\
$(LIBS_LEADER)\
$(COMMON_LIBPATHS)\
$(ENV_LIBPATHS)\
\


# lib names

TARGET_LIB_MT_D = \
 -lkernel32 -luser32 -ladvapi32 -luuid -lwininet -lws2_32 -lole32 -loleaut32 \
 \

TARGET_LIB_MT_R = \
 -lkernel32 -luser32 -ladvapi32 -luuid -lwininet -lws2_32 -lole32 -loleaut32 \
 \

TARGET_LIB_ST_D = \
 -lkernel32 -luser32 -ladvapi32 -luuid -lwininet -lws2_32 -lole32 -loleaut32 \
 \

TARGET_LIB_ST_R = \
 -lkernel32 -luser32 -ladvapi32 -luuid -lwininet -lws2_32 -lole32 -loleaut32 \
 \


# #defines

COMMON_DEFS 		=	-DWIN32

CUSTOM_DEFS			=

# includes

COMMON_INCLUDES		=



# CPPC flags

CPPC_F_NOLOGO			=	
CPPC_F_COMPILE_ONLY 	=	-c
CPPC_F_WARNING_MAX		=	-Wall -pedantic -Wno-long-long -Wno-unused-value -Wno-non-virtual-dtor -Wno-uninitialized
CPPC_F_WARNING_ERR		=	
CPPC_F_EXCEPTIONS_ON	=	
CPPC_F_EXCEPTIONS_OFF	=	
CPPC_F_EXCEPTIONS		=	$(CPPC_F_EXCEPTIONS_ON)
CPPC_F_RTTI_ON 			=	
CPPC_F_RTTI_OFF			=	
CPPC_F_RTTI 			=	$(CPPC_F_RTTI_ON)
CPPC_F_MINIMUM_SIZE 	=	-O1
CPPC_F_MAXIMUM_SPEED	=	-O3

CPPC_FLAGS_BASE =\
 $(CPPC_F_NOLOGO)\
 $(CPPC_F_COMPILE_ONLY)\
 $(CPPC_F_WARNING_MAX)\
 $(CPPC_F_WARNING_ERR)\
 $(CPPC_F_EXCEPTIONS)\
 $(CPPC_F_RTTI)\
 \

CPPC_FLAGS_MT_D =\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_MT_R =\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_ST_D =\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_ST_R =\
 $(CPPC_FLAGS_BASE)\
 \


# CPPC defines

ifdef FASTFORMAT_NO_NAG
NO_NAG_DEFS					=	-DFASTFORMAT_NO_VERSION_NAG=1
else # ? FASTFORMAT_NO_NAG
NO_NAG_DEFS					=
endif # FASTFORMAT_NO_NAG

CPPC_DEFS_BASE =\
 $(COMMON_DEFS)\
 $(CUSTOM_DEFS)\
 $(NO_NAG_DEFS)\
 \
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 \

ifdef BOOST
DEFINE_BOOST_FOR_PERFTEST	=	-DFASTFORMAT_PERFTEST_USE_BOOST
else # BOOST
DEFINE_BOOST_FOR_PERFTEST	=
endif # BOOST

DEFINE_LOKI_FOR_PERFTEST	=


CPPC_DEFS_MT_D =\
 $(CPPC_DEFS_BASE)\
 $(DEFINE_BOOST_FOR_PERFTEST)\
 $(DEFINE_LOKI_FOR_PERFTEST)\
 \

CPPC_DEFS_MT_R =\
 $(CPPC_DEFS_BASE)\
 $(DEFINE_BOOST_FOR_PERFTEST)\
 $(DEFINE_LOKI_FOR_PERFTEST)\
 \

CPPC_DEFS_ST_D =\
 $(CPPC_DEFS_BASE)\
 $(DEFINE_BOOST_FOR_PERFTEST)\
 $(DEFINE_LOKI_FOR_PERFTEST)\
 \

CPPC_DEFS_ST_R =\
 $(CPPC_DEFS_BASE)\
 $(DEFINE_BOOST_FOR_PERFTEST)\
 $(DEFINE_LOKI_FOR_PERFTEST)\
 \



# CPPC includes

ifdef STLSOFT_1_10
STLSOFT_1_10_INCLUDE	=	-I"$(STLSOFT_1_10)/include"
else # STLSOFT_1_10
STLSOFT_1_10_INCLUDE	=
endif # STLSOFT_1_10

CPPC_INCLUDES_BASE=\
 \
 -I$(PROJ_INCLUDE_DIR)\
 $(SHWILD_PROJ_INCLUDE)\
 $(XCONTRACT_PROJ_INCLUDE)\
 $(XTESTS_PROJ_INCLUDE)\
 $(STLSOFT_1_10_INCLUDE)\
 -I$(STLSOFT)\include\
 $(COMMON_INCLUDES)\
 \

CPPC_CORE_INCLUDES_BASE=\
 -I$(PROJ_SRC_DIR)\
 $(CPPC_INCLUDES_BASE)\
 \

ifdef BOOST
INCLUDE_BOOST_FOR_PERFTEST	=	-I"$(BOOST)"
else # BOOST
INCLUDE_BOOST_FOR_PERFTEST	=
endif # BOOST

INCLUDE_LOKI_FOR_PERFTEST	=


CPPC_INCLUDES_MT_D =\
 $(CPPC_INCLUDES_BASE)\
 $(INCLUDE_BOOST_FOR_PERFTEST)\
 $(INCLUDE_LOKI_FOR_PERFTEST)\
 \

CPPC_INCLUDES_MT_R =\
 $(CPPC_INCLUDES_BASE)\
 $(INCLUDE_BOOST_FOR_PERFTEST)\
 $(INCLUDE_LOKI_FOR_PERFTEST)\
 \

CPPC_INCLUDES_ST_D =\
 $(CPPC_INCLUDES_BASE)\
 $(INCLUDE_BOOST_FOR_PERFTEST)\
 $(INCLUDE_LOKI_FOR_PERFTEST)\
 \

CPPC_INCLUDES_ST_R =\
 $(CPPC_INCLUDES_BASE)\
 $(INCLUDE_BOOST_FOR_PERFTEST)\
 $(INCLUDE_LOKI_FOR_PERFTEST)\
 \



CPPC_SHWILD_INCLUDES_BASE =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_MT_D =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_MT_R =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_ST_D =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_ST_R =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \


CPPC_XTESTS_INCLUDES_BASE =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_MT_D =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_MT_R =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_ST_D =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_ST_R =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \



# CPPC args (= flags + defines + includes)

CPPC_ARGS_MT_D=\
 $(CPPC_FLAGS_MT_D)\
 $(CPPC_CUSTOM_DEFS_DEBUG) -D_REENTRANT -D_DEBUG -UNDEBUG\
 $(CPPC_DEFS_MT_D)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_INCLUDES_MT_D)
CPPC_ARGS_MT_R=\
 $(CPPC_FLAGS_MT_R)\
 $(CPPC_CUSTOM_DEFS_RELEASE) -D_REENTRANT -DNDEBUG -U_DEBUG $(CPPC_F_MAXIMUM_SPEED)\
 $(CPPC_DEFS_MT_R)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_INCLUDES_MT_R)
CPPC_ARGS_ST_D=\
 $(CPPC_FLAGS_ST_D)\
 $(CPPC_CUSTOM_DEFS_DEBUG) -D_DEBUG -UNDEBUG\
 $(CPPC_DEFS_ST_D)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_INCLUDES_ST_D)
CPPC_ARGS_ST_R=\
 $(CPPC_FLAGS_ST_R)\
 $(CPPC_CUSTOM_DEFS_RELEASE) -DNDEBUG -U_DEBUG $(CPPC_F_MAXIMUM_SPEED)\
 $(CPPC_DEFS_ST_R)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_INCLUDES_ST_R)

CPPC_CORE_ARGS_MT_D=\
 $(CPPC_FLAGS_MT_D)\
 $(CPPC_CUSTOM_DEFS_DEBUG) -D_REENTRANT -D_DEBUG -UNDEBUG\
 $(CPPC_DEFS_MT_D)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_CORE_INCLUDES_BASE)
CPPC_CORE_ARGS_MT_R=\
 $(CPPC_FLAGS_MT_R)\
 $(CPPC_CUSTOM_DEFS_RELEASE) -D_REENTRANT -DNDEBUG -U_DEBUG $(CPPC_F_MAXIMUM_SPEED)\
 $(CPPC_DEFS_MT_R)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_CORE_INCLUDES_BASE)
CPPC_CORE_ARGS_ST_D=\
 $(CPPC_FLAGS_ST_D)\
 $(CPPC_CUSTOM_DEFS_DEBUG) -D_DEBUG -UNDEBUG\
 $(CPPC_DEFS_ST_D)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_CORE_INCLUDES_BASE)
CPPC_CORE_ARGS_ST_R=\
 $(CPPC_FLAGS_ST_R)\
 $(CPPC_CUSTOM_DEFS_RELEASE) -DNDEBUG -U_DEBUG $(CPPC_F_MAXIMUM_SPEED)\
 $(CPPC_DEFS_ST_R)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_CORE_INCLUDES_BASE)




# AR Args

AR_ARGS             =   


# LD flags

LD_F_NOLOGO				=   

LD_FLAGS_BASE =\
 $(LD_F_NOLOGO)\
 \

LD_FLAGS_MT_D =\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_MT_R =\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_ST_D =\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_ST_R =\
 $(LD_FLAGS_BASE)\
 \


# LD includes

LD_INCLUDES_BASE =\
 $(LIBPATHS)\
 \

LD_INCLUDES_MT_D =\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_MT_R =\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_ST_D =\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_ST_R =\
 $(LD_INCLUDES_BASE)\
 \


LD_ARGS 		=	

LD_F_NOLOGO = 

# LD args

LD_ARGS_MT_D =  $(LD_ARGS) $(LD_F_NOLOGO) $(LIBPATHS) $(COMMON_LIB)
LD_ARGS_MT_R =  $(LD_ARGS) $(LD_F_NOLOGO) $(LIBPATHS) $(COMMON_LIB)
LD_ARGS_ST_D =  $(LD_ARGS) $(LD_F_NOLOGO) $(LIBPATHS) $(COMMON_LIB)
LD_ARGS_ST_R =  $(LD_ARGS) $(LD_F_NOLOGO) $(LIBPATHS) $(COMMON_LIB)

############################################################################
# Headers

CORE_HEADERS=\
 \
 $(PROJ_INCLUDE_DIR)\fastformat\fastformat.h\
 $(PROJ_INCLUDE_DIR)\fastformat\fastformat.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\ff.hpp\
 \
 $(PROJ_INCLUDE_DIR)\fastformat\implicit_link.h\
 $(PROJ_INCLUDE_DIR)\fastformat\init_codes.h\
 $(PROJ_INCLUDE_DIR)\fastformat\exceptions.hpp\
 \
 $(PROJ_INCLUDE_DIR)\fastformat\bundles\openrj_bundle.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\bundles\properties_bundle.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\bundles\winini_bundle.hpp\
 \
 $(PROJ_INCLUDE_DIR)\fastformat\format\standard_flags.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\format\specification_defect_handling\ignore_missing_arguments_scope.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\format\specification_defect_handling\ignore_unreferenced_arguments_scope.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\format\specification_defect_handling\mismatched_arguments_scope_base.hpp\
 \
 $(PROJ_INCLUDE_DIR)\fastformat\inserters\integer.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\inserters\real.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\inserters\to_e.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\inserters\to_f.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\inserters\to_g.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\inserters\to_i.hpp\
 \
 $(PROJ_INCLUDE_DIR)\fastformat\internal\format_element.h\
 $(PROJ_INCLUDE_DIR)\fastformat\internal\stlsoft.h\
 $(PROJ_INCLUDE_DIR)\fastformat\internal\string_encoding.h\
 $(PROJ_INCLUDE_DIR)\fastformat\internal\threading.h\
 $(PROJ_INCLUDE_DIR)\fastformat\internal\initialiser.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\internal\generated\api_functions.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\internal\generated\helper_functions.hpp\
 \
 $(PROJ_INCLUDE_DIR)\fastformat\quality\contract.h\
 $(PROJ_INCLUDE_DIR)\fastformat\quality\cover.h\
 \
 $(PROJ_INCLUDE_DIR)\fastformat\shims\action\fmt_slices\generic_string.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\shims\conversion\filter_type\fast_integers.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\shims\conversion\filter_type\reals.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\shims\conversion\filter_type\void_pointers.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\ACE_CString.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\auto_buffer.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\CComBSTR.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\char_buffer.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\CString.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\c_string.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\FILE.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\null.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\ostream.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\OutputDebugString.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\shim_string.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\speech.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\stringstream.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\string_array.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\vectored_file.hpp\
 \
 $(PROJ_INCLUDE_DIR)\fastformat\test\util\compiler_warnings_suppression.first_include.h\
 $(PROJ_INCLUDE_DIR)\fastformat\test\util\compiler_warnings_suppression.last_include.h\
 \
 $(PROJ_INCLUDE_DIR)\fastformat\util\memory\auto_buffer_selector.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\util\sinks\helpers.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\util\string\snprintf.h\
 \

SHWILD_HEADERS=\
 $(SHWILD_INCLUDE_DIR)\shwild\shwild.h\
 $(SHWILD_INCLUDE_DIR)\shwild\shwild.hpp\
 \

XCONTRACT_HEADERS=\
 $(XCONTRACT_INCLUDE_DIR)\xcontract\xcontract.h\
 \

XTESTS_HEADERS=\
 $(XTESTS_INCLUDE_DIR)\xtests\xtests.h\
 \

############################################################################
# Names

############################################################
# Targets

########################################
# Libraries

# fastformat
LIB_CORE_MT_D				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_CORE_MT_R				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).mt.lib
LIB_CORE_ST_D				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).debug.lib
LIB_CORE_ST_R				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).lib

# Loki.SafeFormat - performance testing only
LIB_LOKI_SFMT_MT_D		=
LIB_LOKI_SFMT_MT_R		=
LIB_LOKI_SFMT_ST_D		=
LIB_LOKI_SFMT_ST_R		=

# shwild - testing only
LIB_SHWILD_MT_D			=	$(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).ff.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_SHWILD_MT_R			=	$(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).ff.$(COMP_ARCH_OS_TAG).mt.lib
LIB_SHWILD_ST_D			=	$(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).ff.$(COMP_ARCH_OS_TAG).debug.lib
LIB_SHWILD_ST_R			=	$(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).ff.$(COMP_ARCH_OS_TAG).lib

# xtests - unit/component testing only
LIB_XTESTS_MT_D			=	$(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).ff.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_XTESTS_MT_R			=	$(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).ff.$(COMP_ARCH_OS_TAG).mt.lib
LIB_XTESTS_ST_D			=	$(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).ff.$(COMP_ARCH_OS_TAG).debug.lib
LIB_XTESTS_ST_R			=	$(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).ff.$(COMP_ARCH_OS_TAG).lib

########################################
# Examples

TARG_BITBUCKET_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_BITBUCKET_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.$(COMP_ARCH_OS_TAG).mt.exe
TARG_BITBUCKET_ST_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.$(COMP_ARCH_OS_TAG).debug.exe
TARG_BITBUCKET_ST_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.$(COMP_ARCH_OS_TAG).exe

TARG_EX_boolean_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.boolean.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_character_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.character.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_reals_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.reals.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_voidptrs_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.void_pointers.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ff_101_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ff_101.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ff_101_nons_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ff_101.no_namespace.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_flush_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.flush.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ins_hex_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.hex.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ins_integers_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.integers.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ins_reals_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.reals.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ins_WLIs_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.WLIs.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_itr_fmt_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.itrs.fmt_itr.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ovld2_filt_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.2.hero.filter.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ovld2_ins_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.2.hero.inserter.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ovld2_sas_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.2.hero.sas.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ovld3_fpcol_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.flpt.cols.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ovld3_tabs_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.tabs.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ovld3_svrlg_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.svr.log.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ovld3_rcins_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.rec.ins.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_pad_hash_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.pad.hash.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_sink_cstr_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.sink.c_string.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_sink_ODS_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.sink.OutputDebugString.$(COMP_ARCH_OS_TAG).mt.debug.exe

TARG_EX_boolean_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.boolean.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_character_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.character.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_reals_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.reals.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_voidptrs_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.void_pointers.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ff_101_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ff_101.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ff_101_nons_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ff_101.no_namespace.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_flush_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.flush.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ins_hex_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.hex.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ins_integers_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.integers.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ins_reals_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.reals.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ins_WLIs_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.WLIs.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_itr_fmt_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.itrs.fmt_itr.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ovld2_filt_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.2.hero.filter.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ovld2_ins_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.2.hero.inserter.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ovld2_sas_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.2.hero.sas.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ovld3_fpcol_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.flpt.cols.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ovld3_tabs_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.tabs.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ovld3_svrlg_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.svr.log.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ovld3_rcins_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.rec.ins.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_pad_hash_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.pad.hash.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_sink_cstr_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.sink.c_string.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_sink_ODS_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.sink.OutputDebugString.$(COMP_ARCH_OS_TAG).mt.exe

TARG_EX_boolean_ST_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.boolean.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_character_ST_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.character.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_reals_ST_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.reals.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_voidptrs_ST_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.void_pointers.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ff_101_ST_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ff_101.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ff_101_nons_ST_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ff_101.no_namespace.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_flush_ST_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.flush.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ins_hex_ST_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.hex.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ins_integers_ST_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.integers.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ins_reals_ST_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.reals.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ins_WLIs_ST_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.WLIs.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_itr_fmt_ST_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.itrs.fmt_itr.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ovld2_filt_ST_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.2.hero.filter.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ovld2_ins_ST_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.2.hero.inserter.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ovld2_sas_ST_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.2.hero.sas.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ovld3_fpcol_ST_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.flpt.cols.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ovld3_tabs_ST_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.tabs.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ovld3_svrlg_ST_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.svr.log.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ovld3_rcins_ST_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.rec.ins.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_pad_hash_ST_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.pad.hash.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_sink_cstr_ST_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.sink.c_string.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_sink_ODS_ST_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.sink.OutputDebugString.$(COMP_ARCH_OS_TAG).debug.exe

TARG_EX_boolean_ST_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.boolean.$(COMP_ARCH_OS_TAG).exe
TARG_EX_character_ST_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.character.$(COMP_ARCH_OS_TAG).exe
TARG_EX_reals_ST_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.reals.$(COMP_ARCH_OS_TAG).exe
TARG_EX_voidptrs_ST_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.void_pointers.$(COMP_ARCH_OS_TAG).exe
TARG_EX_ff_101_ST_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ff_101.$(COMP_ARCH_OS_TAG).exe
TARG_EX_ff_101_nons_ST_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ff_101.no_namespace.$(COMP_ARCH_OS_TAG).exe
TARG_EX_flush_ST_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.flush.$(COMP_ARCH_OS_TAG).exe
TARG_EX_ins_hex_ST_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.hex.$(COMP_ARCH_OS_TAG).exe
TARG_EX_ins_integers_ST_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.integers.$(COMP_ARCH_OS_TAG).exe
TARG_EX_ins_reals_ST_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.reals.$(COMP_ARCH_OS_TAG).exe
TARG_EX_ins_WLIs_ST_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.WLIs.$(COMP_ARCH_OS_TAG).exe
TARG_EX_itr_fmt_ST_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.itrs.fmt_itr.$(COMP_ARCH_OS_TAG).exe
TARG_EX_ovld2_filt_ST_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.2.hero.filter.$(COMP_ARCH_OS_TAG).exe
TARG_EX_ovld2_ins_ST_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.2.hero.inserter.$(COMP_ARCH_OS_TAG).exe
TARG_EX_ovld2_sas_ST_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.2.hero.sas.$(COMP_ARCH_OS_TAG).exe
TARG_EX_ovld3_fpcol_ST_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.flpt.cols.$(COMP_ARCH_OS_TAG).exe
TARG_EX_ovld3_tabs_ST_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.tabs.$(COMP_ARCH_OS_TAG).exe
TARG_EX_ovld3_svrlg_ST_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.svr.log.$(COMP_ARCH_OS_TAG).exe
TARG_EX_ovld3_rcins_ST_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.rec.ins.$(COMP_ARCH_OS_TAG).exe
TARG_EX_pad_hash_ST_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.pad.hash.$(COMP_ARCH_OS_TAG).exe
TARG_EX_sink_cstr_ST_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.sink.c_string.$(COMP_ARCH_OS_TAG).exe
TARG_EX_sink_ODS_ST_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.sink.OutputDebugString.$(COMP_ARCH_OS_TAG).exe


########################################
# Tests

##############################
# Component Tests

TARG_TEST_COMP_file_MT_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.FILE.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_fmt_sink_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.string.fmt.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_ins_hex_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.hex.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_ins_int_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.integer.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_ins_real_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.real.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_itr_fmt_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.itrs.fmt_itr.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_null_sink_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.null.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_snk_a_b_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.auto_buffer.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_write_sink_MT_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.string.write.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_x_1_MT_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.fsde.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_snk_ostm_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.ostream.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_file_MT_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.FILE.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_fmt_sink_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.string.fmt.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_ins_hex_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.hex.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_ins_int_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.integer.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_ins_real_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.real.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_itr_fmt_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.itrs.fmt_itr.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_null_sink_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.null.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_snk_a_b_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.auto_buffer.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_write_sink_MT_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.string.write.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_x_1_MT_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.fsde.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_snk_ostm_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.ostream.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_file_ST_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.FILE.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_COMP_fmt_sink_ST_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.string.fmt.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_COMP_ins_hex_ST_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.hex.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_COMP_ins_int_ST_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.integer.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_COMP_ins_real_ST_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.real.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_COMP_itr_fmt_ST_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.itrs.fmt_itr.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_COMP_null_sink_ST_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.null.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_COMP_snk_a_b_ST_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.auto_buffer.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_COMP_write_sink_ST_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.string.write.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_COMP_x_1_ST_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.fsde.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_COMP_snk_ostm_ST_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.ostream.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_COMP_file_ST_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.FILE.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_COMP_fmt_sink_ST_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.string.fmt.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_COMP_ins_hex_ST_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.hex.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_COMP_ins_int_ST_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.integer.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_COMP_ins_real_ST_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.real.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_COMP_itr_fmt_ST_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.itrs.fmt_itr.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_COMP_null_sink_ST_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.null.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_COMP_snk_a_b_ST_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.auto_buffer.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_COMP_write_sink_ST_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.string.write.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_COMP_x_1_ST_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.fsde.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_COMP_snk_ostm_ST_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.ostream.$(COMP_ARCH_OS_TAG).exe

##############################
# Performance Tests

TARG_TEST_PERF_scen1_MT_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario1.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_PERF_scen2_MT_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario2.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_PERF_scen3_MT_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario3.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_PERF_scen4_MT_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario4.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_PERF_scen5_MT_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario5.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_PERF_scen6_MT_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario6.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_PERF_scen7_MT_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario7.$(COMP_ARCH_OS_TAG).mt.debug.exe
ifdef BOOST
TARG_TEST_PERF_scen8_MT_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario8.$(COMP_ARCH_OS_TAG).mt.debug.exe
endif # BOOST
TARG_TEST_PERF_scen1_MT_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario1.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_PERF_scen2_MT_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario2.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_PERF_scen3_MT_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario3.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_PERF_scen4_MT_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario4.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_PERF_scen5_MT_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario5.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_PERF_scen6_MT_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario6.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_PERF_scen7_MT_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario7.$(COMP_ARCH_OS_TAG).mt.exe
ifdef BOOST
TARG_TEST_PERF_scen8_MT_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario8.$(COMP_ARCH_OS_TAG).mt.exe
endif # BOOST
TARG_TEST_PERF_scen1_ST_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario1.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_PERF_scen2_ST_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario2.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_PERF_scen3_ST_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario3.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_PERF_scen4_ST_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario4.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_PERF_scen5_ST_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario5.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_PERF_scen6_ST_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario6.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_PERF_scen7_ST_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario7.$(COMP_ARCH_OS_TAG).debug.exe
ifdef BOOST
TARG_TEST_PERF_scen8_ST_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario8.$(COMP_ARCH_OS_TAG).debug.exe
endif # BOOST
TARG_TEST_PERF_scen1_ST_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario1.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_PERF_scen2_ST_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario2.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_PERF_scen3_ST_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario3.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_PERF_scen4_ST_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario4.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_PERF_scen5_ST_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario5.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_PERF_scen6_ST_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario6.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_PERF_scen7_ST_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario7.$(COMP_ARCH_OS_TAG).exe
ifdef BOOST
TARG_TEST_PERF_scen8_ST_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario8.$(COMP_ARCH_OS_TAG).exe
endif # BOOST

##############################
# Scratch Tests

TARG_TEST_SCRT_file_MT_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.FILE.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_SCRT_speech_MT_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.speech.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_SCRT_file_MT_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.FILE.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_SCRT_speech_MT_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.speech.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_SCRT_file_ST_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.FILE.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_SCRT_speech_ST_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.speech.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_SCRT_file_ST_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.FILE.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_SCRT_speech_ST_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.speech.$(COMP_ARCH_OS_TAG).exe

##############################
# Unit Tests

TARG_TEST_UNIT_api_acsllen_MT_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.accum_slice_lens.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_api_crlf_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.crlf_for_platform.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_api_flrpl_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.fill_replacements.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_api_illfmdh_MT_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.illformed_handlers.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_api_init_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.initialisation.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_api_lkptrn_MT_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.lookup_pattern.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_api_msmtchh_MT_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.mismatched_handlers.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_api_prsrpl_MT_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.parse_format.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_bndl_winini_MT_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.bundle.winini.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_fmt_stdfl_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.format.standard_flags.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_ins_ch_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.character.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_ins_i_MT_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.integer.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_shim_fi_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.shims.fast_integers.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_snk_a_b_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.auto_buffer.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_snk_c_str_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.c_string.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_snk_chbuf_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.char_buffer.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_snk_null_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.null.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_snk_ods_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ODS.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_snk_ostm_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ostream.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_snk_sstm_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.stringstream.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_api_acsllen_MT_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.accum_slice_lens.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_api_crlf_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.crlf_for_platform.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_api_flrpl_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.fill_replacements.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_api_illfmdh_MT_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.illformed_handlers.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_api_init_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.initialisation.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_api_lkptrn_MT_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.lookup_pattern.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_api_msmtchh_MT_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.mismatched_handlers.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_api_prsrpl_MT_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.parse_format.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_bndl_winini_MT_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.bundle.winini.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_fmt_stdfl_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.format.standard_flags.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_ins_ch_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.character.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_ins_i_MT_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.integer.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_shim_fi_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.shims.fast_integers.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_snk_a_b_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.auto_buffer.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_snk_c_str_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.c_string.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_snk_chbuf_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.char_buffer.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_snk_null_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.null.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_snk_ods_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ODS.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_snk_ostm_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ostream.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_snk_sstm_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.stringstream.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_api_acsllen_ST_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.accum_slice_lens.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_api_crlf_ST_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.crlf_for_platform.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_api_flrpl_ST_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.fill_replacements.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_api_illfmdh_ST_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.illformed_handlers.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_api_init_ST_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.initialisation.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_api_lkptrn_ST_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.lookup_pattern.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_api_msmtchh_ST_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.mismatched_handlers.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_api_prsrpl_ST_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.parse_format.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_bndl_winini_ST_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.bundle.winini.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_fmt_stdfl_ST_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.format.standard_flags.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_ins_ch_ST_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.character.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_ins_i_ST_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.integer.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_shim_fi_ST_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.shims.fast_integers.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_snk_a_b_ST_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.auto_buffer.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_snk_c_str_ST_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.c_string.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_snk_chbuf_ST_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.char_buffer.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_snk_null_ST_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.null.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_snk_ods_ST_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ODS.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_snk_ostm_ST_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ostream.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_snk_sstm_ST_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.stringstream.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_api_acsllen_ST_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.accum_slice_lens.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_api_crlf_ST_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.crlf_for_platform.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_api_flrpl_ST_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.fill_replacements.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_api_illfmdh_ST_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.illformed_handlers.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_api_init_ST_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.initialisation.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_api_lkptrn_ST_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.lookup_pattern.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_api_msmtchh_ST_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.mismatched_handlers.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_api_prsrpl_ST_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.parse_format.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_bndl_winini_ST_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.bundle.winini.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_fmt_stdfl_ST_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.format.standard_flags.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_ins_ch_ST_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.character.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_ins_i_ST_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.integer.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_shim_fi_ST_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.shims.fast_integers.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_snk_a_b_ST_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.auto_buffer.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_snk_c_str_ST_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.c_string.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_snk_chbuf_ST_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.char_buffer.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_snk_null_ST_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.null.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_snk_ods_ST_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ODS.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_snk_ostm_ST_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ostream.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_snk_sstm_ST_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.stringstream.$(COMP_ARCH_OS_TAG).exe

############################################################################
# Objects

########################################
# Libraries

# fastformat

OBJ_cr_api_MT_D           = $(PROJ_OBJ_DIR)\core.api.mt.debug.obj
OBJ_cr_fsdhndlrs_MT_D     = $(PROJ_OBJ_DIR)\core.fmt_spec_defect_handlers.mt.debug.obj
OBJ_cr_fmtcache_MT_D      = $(PROJ_OBJ_DIR)\core.fmt_cache.mt.debug.obj
OBJ_cr_initstr_MT_D       = $(PROJ_OBJ_DIR)\core.init_code_strings.mt.debug.obj
OBJ_cr_mempool_MT_D       = $(PROJ_OBJ_DIR)\core.mempool.mt.debug.obj
OBJ_cr_replacements_MT_D  = $(PROJ_OBJ_DIR)\core.replacements.mt.debug.obj
OBJ_cr_snprintf_MT_D      = $(PROJ_OBJ_DIR)\core.snprintf.mt.debug.obj

OBJ_CORE_MT_D = \
 $(OBJ_cr_api_MT_D)\
 $(OBJ_cr_fsdhndlrs_MT_D)\
 $(OBJ_cr_fmtcache_MT_D)\
 $(OBJ_cr_initstr_MT_D)\
 $(OBJ_cr_mempool_MT_D)\
 $(OBJ_cr_replacements_MT_D)\
 $(OBJ_cr_snprintf_MT_D)\
 \

OBJ_cr_api_MT_R           = $(PROJ_OBJ_DIR)\core.api.mt.obj
OBJ_cr_fsdhndlrs_MT_R     = $(PROJ_OBJ_DIR)\core.fmt_spec_defect_handlers.mt.obj
OBJ_cr_fmtcache_MT_R      = $(PROJ_OBJ_DIR)\core.fmt_cache.mt.obj
OBJ_cr_initstr_MT_R       = $(PROJ_OBJ_DIR)\core.init_code_strings.mt.obj
OBJ_cr_mempool_MT_R       = $(PROJ_OBJ_DIR)\core.mempool.mt.obj
OBJ_cr_replacements_MT_R  = $(PROJ_OBJ_DIR)\core.replacements.mt.obj
OBJ_cr_snprintf_MT_R      = $(PROJ_OBJ_DIR)\core.snprintf.mt.obj

OBJ_CORE_MT_R = \
 $(OBJ_cr_api_MT_R)\
 $(OBJ_cr_fsdhndlrs_MT_R)\
 $(OBJ_cr_fmtcache_MT_R)\
 $(OBJ_cr_initstr_MT_R)\
 $(OBJ_cr_mempool_MT_R)\
 $(OBJ_cr_replacements_MT_R)\
 $(OBJ_cr_snprintf_MT_R)\
 \

OBJ_cr_api_ST_D           = $(PROJ_OBJ_DIR)\core.api.debug.obj
OBJ_cr_fsdhndlrs_ST_D     = $(PROJ_OBJ_DIR)\core.fmt_spec_defect_handlers.debug.obj
OBJ_cr_fmtcache_ST_D      = $(PROJ_OBJ_DIR)\core.fmt_cache.debug.obj
OBJ_cr_initstr_ST_D       = $(PROJ_OBJ_DIR)\core.init_code_strings.debug.obj
OBJ_cr_mempool_ST_D       = $(PROJ_OBJ_DIR)\core.mempool.debug.obj
OBJ_cr_replacements_ST_D  = $(PROJ_OBJ_DIR)\core.replacements.debug.obj
OBJ_cr_snprintf_ST_D      = $(PROJ_OBJ_DIR)\core.snprintf.debug.obj

OBJ_CORE_ST_D = \
 $(OBJ_cr_api_ST_D)\
 $(OBJ_cr_fsdhndlrs_ST_D)\
 $(OBJ_cr_fmtcache_ST_D)\
 $(OBJ_cr_initstr_ST_D)\
 $(OBJ_cr_mempool_ST_D)\
 $(OBJ_cr_replacements_ST_D)\
 $(OBJ_cr_snprintf_ST_D)\
 \

OBJ_cr_api_ST_R           = $(PROJ_OBJ_DIR)\core.api.obj
OBJ_cr_fsdhndlrs_ST_R     = $(PROJ_OBJ_DIR)\core.fmt_spec_defect_handlers.obj
OBJ_cr_fmtcache_ST_R      = $(PROJ_OBJ_DIR)\core.fmt_cache.obj
OBJ_cr_initstr_ST_R       = $(PROJ_OBJ_DIR)\core.init_code_strings.obj
OBJ_cr_mempool_ST_R       = $(PROJ_OBJ_DIR)\core.mempool.obj
OBJ_cr_replacements_ST_R  = $(PROJ_OBJ_DIR)\core.replacements.obj
OBJ_cr_snprintf_ST_R      = $(PROJ_OBJ_DIR)\core.snprintf.obj

OBJ_CORE_ST_R = \
 $(OBJ_cr_api_ST_R)\
 $(OBJ_cr_fsdhndlrs_ST_R)\
 $(OBJ_cr_fmtcache_ST_R)\
 $(OBJ_cr_initstr_ST_R)\
 $(OBJ_cr_mempool_ST_R)\
 $(OBJ_cr_replacements_ST_R)\
 $(OBJ_cr_snprintf_ST_R)\
 \


# Loki.SafeFormat

OBJ_lok_sfmt_MT_D	=
PDB_lok_sfmt_MT_D	=
OBJ_LOKI_SFMT_MT_D_PM	=
PDB_LOKI_SFMT_MT_D_PM	=
OBJ_lok_sfmt_MT_R	=
PDB_lok_sfmt_MT_R	=
OBJ_LOKI_SFMT_MT_R_PM	=
PDB_LOKI_SFMT_MT_R_PM	=
OBJ_lok_sfmt_ST_D	=
PDB_lok_sfmt_ST_D	=
OBJ_LOKI_SFMT_ST_D_PM	=
PDB_LOKI_SFMT_ST_D_PM	=
OBJ_lok_sfmt_ST_R	=
PDB_lok_sfmt_ST_R	=
OBJ_LOKI_SFMT_ST_R_PM	=
PDB_LOKI_SFMT_ST_R_PM	=

# shwild

OBJ_shw_api_MT_D            = $(PROJ_OBJ_DIR)\shwild.ff.api.mt.debug.obj
OBJ_shw_matches_MT_D        = $(PROJ_OBJ_DIR)\shwild.ff.matches.mt.debug.obj
OBJ_shw_pattern_MT_D        = $(PROJ_OBJ_DIR)\shwild.ff.pattern.mt.debug.obj

OBJ_SHWILD_MT_D = \
 $(OBJ_shw_api_MT_D)\
 $(OBJ_shw_matches_MT_D)\
 $(OBJ_shw_pattern_MT_D)\
 \

OBJ_shw_api_MT_R            = $(PROJ_OBJ_DIR)\shwild.ff.api.mt.obj
OBJ_shw_matches_MT_R        = $(PROJ_OBJ_DIR)\shwild.ff.matches.mt.obj
OBJ_shw_pattern_MT_R        = $(PROJ_OBJ_DIR)\shwild.ff.pattern.mt.obj

OBJ_SHWILD_MT_R = \
 $(OBJ_shw_api_MT_R)\
 $(OBJ_shw_matches_MT_R)\
 $(OBJ_shw_pattern_MT_R)\
 \

OBJ_shw_api_ST_D            = $(PROJ_OBJ_DIR)\shwild.ff.api.debug.obj
OBJ_shw_matches_ST_D        = $(PROJ_OBJ_DIR)\shwild.ff.matches.debug.obj
OBJ_shw_pattern_ST_D        = $(PROJ_OBJ_DIR)\shwild.ff.pattern.debug.obj

OBJ_SHWILD_ST_D = \
 $(OBJ_shw_api_ST_D)\
 $(OBJ_shw_matches_ST_D)\
 $(OBJ_shw_pattern_ST_D)\
 \

OBJ_shw_api_ST_R            = $(PROJ_OBJ_DIR)\shwild.ff.api.obj
OBJ_shw_matches_ST_R        = $(PROJ_OBJ_DIR)\shwild.ff.matches.obj
OBJ_shw_pattern_ST_R        = $(PROJ_OBJ_DIR)\shwild.ff.pattern.obj

OBJ_SHWILD_ST_R = \
 $(OBJ_shw_api_ST_R)\
 $(OBJ_shw_matches_ST_R)\
 $(OBJ_shw_pattern_ST_R)\
 \


# xtests

OBJ_xts_core_MT_D           = $(PROJ_OBJ_DIR)\xtests.ff.core.api.mt.debug.obj

OBJ_XTESTS_MT_D = \
 $(OBJ_xts_core_MT_D)\
 \

OBJ_xts_core_MT_R           = $(PROJ_OBJ_DIR)\xtests.ff.core.api.mt.obj

OBJ_XTESTS_MT_R = \
 $(OBJ_xts_core_MT_R)\
 \

OBJ_xts_core_ST_D           = $(PROJ_OBJ_DIR)\xtests.ff.core.api.debug.obj

OBJ_XTESTS_ST_D = \
 $(OBJ_xts_core_ST_D)\
 \

OBJ_xts_core_ST_R           = $(PROJ_OBJ_DIR)\xtests.ff.core.api.obj

OBJ_XTESTS_ST_R = \
 $(OBJ_xts_core_ST_R)\
 \


########################################
# Examples

OBJ_BITBUCKET_MT_D		=	$(PROJ_OBJ_DIR)\bitbucket.mt.debug.obj
OBJ_BITBUCKET_MT_R		=	$(PROJ_OBJ_DIR)\bitbucket.mt.obj
OBJ_BITBUCKET_ST_D		=	$(PROJ_OBJ_DIR)\bitbucket.debug.obj
OBJ_BITBUCKET_ST_R		=	$(PROJ_OBJ_DIR)\bitbucket.obj

OBJ_EX_boolean_MT_D		=   $(PROJ_OBJ_DIR)\example.arguments.boolean.mt.debug.obj
OBJ_EX_character_MT_D		=   $(PROJ_OBJ_DIR)\example.arguments.character.mt.debug.obj
OBJ_EX_reals_MT_D			=   $(PROJ_OBJ_DIR)\example.arguments.reals.mt.debug.obj
OBJ_EX_voidptrs_MT_D		=   $(PROJ_OBJ_DIR)\example.arguments.void_pointers.mt.debug.obj
OBJ_EX_ff_101_MT_D		=   $(PROJ_OBJ_DIR)\example.ff_101.mt.debug.obj
OBJ_EX_ff_101_nons_MT_D	=   $(PROJ_OBJ_DIR)\example.ff_101.no_namespace.mt.debug.obj
OBJ_EX_flush_MT_D			=	$(PROJ_OBJ_DIR)\example.flush.mt.debug.obj
OBJ_EX_ins_hex_MT_D		=	$(PROJ_OBJ_DIR)\example.inserter.hex.mt.debug.obj
OBJ_EX_ins_integers_MT_D	=	$(PROJ_OBJ_DIR)\example.inserter.integers.mt.debug.obj
OBJ_EX_ins_reals_MT_D		=	$(PROJ_OBJ_DIR)\example.inserter.reals.mt.debug.obj
OBJ_EX_ins_WLIs_MT_D		=	$(PROJ_OBJ_DIR)\example.inserter.WLIs.mt.debug.obj
OBJ_EX_itr_fmt_MT_D		=	$(PROJ_OBJ_DIR)\example.itrs.fmt_itr.mt.debug.obj
OBJ_EX_ovld2_filt_MT_D	=   $(PROJ_OBJ_DIR)\example.ovld.2.hero.filter.mt.debug.obj
OBJ_EX_ovld2_ins_MT_D		=   $(PROJ_OBJ_DIR)\example.ovld.2.hero.inserter.mt.debug.obj
OBJ_EX_ovld2_sas_MT_D		=   $(PROJ_OBJ_DIR)\example.ovld.2.hero.sas.mt.debug.obj
OBJ_EX_ovld3_fpcol_MT_D	=   $(PROJ_OBJ_DIR)\example.ovld.3.flpt.cols.mt.debug.obj
OBJ_EX_ovld3_tabs_MT_D	=   $(PROJ_OBJ_DIR)\example.ovld.3.tabs.mt.debug.obj
OBJ_EX_ovld3_svrlg_MT_D	=   $(PROJ_OBJ_DIR)\example.ovld.3.svr.log.mt.debug.obj
OBJ_EX_ovld3_rcins_MT_D	=   $(PROJ_OBJ_DIR)\example.ovld.3.rec.ins.mt.debug.obj
OBJ_EX_pad_hash_MT_D		=	$(PROJ_OBJ_DIR)\example.pad.hash.mt.debug.obj
OBJ_EX_sink_cstr_MT_D		=	$(PROJ_OBJ_DIR)\example.sink.c_string.mt.debug.obj
OBJ_EX_sink_ODS_MT_D		=   $(PROJ_OBJ_DIR)\example.sink.OutputDebugString.mt.debug.obj

OBJ_EX_boolean_MT_R		=   $(PROJ_OBJ_DIR)\example.arguments.boolean.mt.obj
OBJ_EX_character_MT_R		=   $(PROJ_OBJ_DIR)\example.arguments.character.mt.obj
OBJ_EX_reals_MT_R			=   $(PROJ_OBJ_DIR)\example.arguments.reals.mt.obj
OBJ_EX_voidptrs_MT_R		=   $(PROJ_OBJ_DIR)\example.arguments.void_pointers.mt.obj
OBJ_EX_ff_101_MT_R		=   $(PROJ_OBJ_DIR)\example.ff_101.mt.obj
OBJ_EX_ff_101_nons_MT_R	=   $(PROJ_OBJ_DIR)\example.ff_101.no_namespace.mt.obj
OBJ_EX_flush_MT_R			=	$(PROJ_OBJ_DIR)\example.flush.mt.obj
OBJ_EX_ins_hex_MT_R		=	$(PROJ_OBJ_DIR)\example.inserter.hex.mt.obj
OBJ_EX_ins_integers_MT_R	=	$(PROJ_OBJ_DIR)\example.inserter.integers.mt.obj
OBJ_EX_ins_reals_MT_R		=	$(PROJ_OBJ_DIR)\example.inserter.reals.mt.obj
OBJ_EX_ins_WLIs_MT_R		=	$(PROJ_OBJ_DIR)\example.inserter.WLIs.mt.obj
OBJ_EX_itr_fmt_MT_R		=	$(PROJ_OBJ_DIR)\example.itrs.fmt_itr.mt.obj
OBJ_EX_ovld2_filt_MT_R	=   $(PROJ_OBJ_DIR)\example.ovld.2.hero.filter.mt.obj
OBJ_EX_ovld2_ins_MT_R		=   $(PROJ_OBJ_DIR)\example.ovld.2.hero.inserter.mt.obj
OBJ_EX_ovld2_sas_MT_R		=   $(PROJ_OBJ_DIR)\example.ovld.2.hero.sas.mt.obj
OBJ_EX_ovld3_fpcol_MT_R	=   $(PROJ_OBJ_DIR)\example.ovld.3.flpt.cols.mt.obj
OBJ_EX_ovld3_tabs_MT_R	=   $(PROJ_OBJ_DIR)\example.ovld.3.tabs.mt.obj
OBJ_EX_ovld3_svrlg_MT_R	=   $(PROJ_OBJ_DIR)\example.ovld.3.svr.log.mt.obj
OBJ_EX_ovld3_rcins_MT_R	=   $(PROJ_OBJ_DIR)\example.ovld.3.rec.ins.mt.obj
OBJ_EX_pad_hash_MT_R		=	$(PROJ_OBJ_DIR)\example.pad.hash.mt.obj
OBJ_EX_sink_cstr_MT_R		=	$(PROJ_OBJ_DIR)\example.sink.c_string.mt.obj
OBJ_EX_sink_ODS_MT_R		=   $(PROJ_OBJ_DIR)\example.sink.OutputDebugString.mt.obj

OBJ_EX_boolean_ST_D		=   $(PROJ_OBJ_DIR)\example.arguments.boolean.debug.obj
OBJ_EX_character_ST_D		=   $(PROJ_OBJ_DIR)\example.arguments.character.debug.obj
OBJ_EX_reals_ST_D			=   $(PROJ_OBJ_DIR)\example.arguments.reals.debug.obj
OBJ_EX_voidptrs_ST_D		=   $(PROJ_OBJ_DIR)\example.arguments.void_pointers.debug.obj
OBJ_EX_ff_101_ST_D		=   $(PROJ_OBJ_DIR)\example.ff_101.debug.obj
OBJ_EX_ff_101_nons_ST_D	=   $(PROJ_OBJ_DIR)\example.ff_101.no_namespace.debug.obj
OBJ_EX_flush_ST_D			=	$(PROJ_OBJ_DIR)\example.flush.debug.obj
OBJ_EX_ins_hex_ST_D		=	$(PROJ_OBJ_DIR)\example.inserter.hex.debug.obj
OBJ_EX_ins_integers_ST_D	=	$(PROJ_OBJ_DIR)\example.inserter.integers.debug.obj
OBJ_EX_ins_reals_ST_D		=	$(PROJ_OBJ_DIR)\example.inserter.reals.debug.obj
OBJ_EX_ins_WLIs_ST_D		=	$(PROJ_OBJ_DIR)\example.inserter.WLIs.debug.obj
OBJ_EX_itr_fmt_ST_D		=	$(PROJ_OBJ_DIR)\example.itrs.fmt_itr.debug.obj
OBJ_EX_ovld2_filt_ST_D	=   $(PROJ_OBJ_DIR)\example.ovld.2.hero.filter.debug.obj
OBJ_EX_ovld2_ins_ST_D		=   $(PROJ_OBJ_DIR)\example.ovld.2.hero.inserter.debug.obj
OBJ_EX_ovld2_sas_ST_D		=   $(PROJ_OBJ_DIR)\example.ovld.2.hero.sas.debug.obj
OBJ_EX_ovld3_fpcol_ST_D	=   $(PROJ_OBJ_DIR)\example.ovld.3.flpt.cols.debug.obj
OBJ_EX_ovld3_tabs_ST_D	=   $(PROJ_OBJ_DIR)\example.ovld.3.tabs.debug.obj
OBJ_EX_ovld3_svrlg_ST_D	=   $(PROJ_OBJ_DIR)\example.ovld.3.svr.log.debug.obj
OBJ_EX_ovld3_rcins_ST_D	=   $(PROJ_OBJ_DIR)\example.ovld.3.rec.ins.debug.obj
OBJ_EX_pad_hash_ST_D		=	$(PROJ_OBJ_DIR)\example.pad.hash.debug.obj
OBJ_EX_sink_cstr_ST_D		=	$(PROJ_OBJ_DIR)\example.sink.c_string.debug.obj
OBJ_EX_sink_ODS_ST_D		=   $(PROJ_OBJ_DIR)\example.sink.OutputDebugString.debug.obj

OBJ_EX_boolean_ST_R		=   $(PROJ_OBJ_DIR)\example.arguments.boolean.obj
OBJ_EX_character_ST_R		=   $(PROJ_OBJ_DIR)\example.arguments.character.obj
OBJ_EX_reals_ST_R			=   $(PROJ_OBJ_DIR)\example.arguments.reals.obj
OBJ_EX_voidptrs_ST_R		=   $(PROJ_OBJ_DIR)\example.arguments.void_pointers.obj
OBJ_EX_ff_101_ST_R		=   $(PROJ_OBJ_DIR)\example.ff_101.obj
OBJ_EX_ff_101_nons_ST_R	=   $(PROJ_OBJ_DIR)\example.ff_101.no_namespace.obj
OBJ_EX_flush_ST_R			=	$(PROJ_OBJ_DIR)\example.flush.obj
OBJ_EX_ins_hex_ST_R		=	$(PROJ_OBJ_DIR)\example.inserter.hex.obj
OBJ_EX_ins_integers_ST_R	=	$(PROJ_OBJ_DIR)\example.inserter.integers.obj
OBJ_EX_ins_reals_ST_R		=	$(PROJ_OBJ_DIR)\example.inserter.reals.obj
OBJ_EX_ins_WLIs_ST_R		=	$(PROJ_OBJ_DIR)\example.inserter.WLIs.obj
OBJ_EX_itr_fmt_ST_R		=	$(PROJ_OBJ_DIR)\example.itrs.fmt_itr.obj
OBJ_EX_ovld2_filt_ST_R	=   $(PROJ_OBJ_DIR)\example.ovld.2.hero.filter.obj
OBJ_EX_ovld2_ins_ST_R		=   $(PROJ_OBJ_DIR)\example.ovld.2.hero.inserter.obj
OBJ_EX_ovld2_sas_ST_R		=   $(PROJ_OBJ_DIR)\example.ovld.2.hero.sas.obj
OBJ_EX_ovld3_fpcol_ST_R	=   $(PROJ_OBJ_DIR)\example.ovld.3.flpt.cols.obj
OBJ_EX_ovld3_tabs_ST_R	=   $(PROJ_OBJ_DIR)\example.ovld.3.tabs.obj
OBJ_EX_ovld3_svrlg_ST_R	=   $(PROJ_OBJ_DIR)\example.ovld.3.svr.log.obj
OBJ_EX_ovld3_rcins_ST_R	=   $(PROJ_OBJ_DIR)\example.ovld.3.rec.ins.obj
OBJ_EX_pad_hash_ST_R		=	$(PROJ_OBJ_DIR)\example.pad.hash.obj
OBJ_EX_sink_cstr_ST_R		=	$(PROJ_OBJ_DIR)\example.sink.c_string.obj
OBJ_EX_sink_ODS_ST_R		=   $(PROJ_OBJ_DIR)\example.sink.OutputDebugString.obj


########################################
# Tests

##############################
# Component Tests

OBJ_TEST_COMP_file_MT_D			=   $(PROJ_OBJ_DIR)\test.component.FILE.mt.debug.obj
OBJ_TEST_COMP_fmt_sink_MT_D		=   $(PROJ_OBJ_DIR)\test.component.sink.string.fmt.mt.debug.obj
OBJ_TEST_COMP_ins_hex_MT_D		=   $(PROJ_OBJ_DIR)\test.component.inserter.hex.mt.debug.obj
OBJ_TEST_COMP_ins_int_MT_D		=   $(PROJ_OBJ_DIR)\test.component.inserter.integer.mt.debug.obj
OBJ_TEST_COMP_ins_real_MT_D		=   $(PROJ_OBJ_DIR)\test.component.inserter.real.mt.debug.obj
OBJ_TEST_COMP_itr_fmt_MT_D		=   $(PROJ_OBJ_DIR)\test.component.itrs.fmt_itr.mt.debug.obj
OBJ_TEST_COMP_null_sink_MT_D		=   $(PROJ_OBJ_DIR)\test.component.sink.null.mt.debug.obj
OBJ_TEST_COMP_snk_a_b_MT_D		=   $(PROJ_OBJ_DIR)\test.component.sink.auto_buffer.mt.debug.obj
OBJ_TEST_COMP_write_sink_MT_D		=   $(PROJ_OBJ_DIR)\test.component.sink.string.write.mt.debug.obj
OBJ_TEST_COMP_x_1_MT_D			=   $(PROJ_OBJ_DIR)\test.component.fsde.mt.debug.obj
OBJ_TEST_COMP_snk_ostm_MT_D		=   $(PROJ_OBJ_DIR)\test.component.sink.ostream.mt.debug.obj
OBJ_TEST_COMP_file_MT_R			=   $(PROJ_OBJ_DIR)\test.component.FILE.mt.obj
OBJ_TEST_COMP_fmt_sink_MT_R		=   $(PROJ_OBJ_DIR)\test.component.sink.string.fmt.mt.obj
OBJ_TEST_COMP_ins_hex_MT_R		=   $(PROJ_OBJ_DIR)\test.component.inserter.hex.mt.obj
OBJ_TEST_COMP_ins_int_MT_R		=   $(PROJ_OBJ_DIR)\test.component.inserter.integer.mt.obj
OBJ_TEST_COMP_ins_real_MT_R		=   $(PROJ_OBJ_DIR)\test.component.inserter.real.mt.obj
OBJ_TEST_COMP_itr_fmt_MT_R		=   $(PROJ_OBJ_DIR)\test.component.itrs.fmt_itr.mt.obj
OBJ_TEST_COMP_null_sink_MT_R		=   $(PROJ_OBJ_DIR)\test.component.sink.null.mt.obj
OBJ_TEST_COMP_snk_a_b_MT_R		=   $(PROJ_OBJ_DIR)\test.component.sink.auto_buffer.mt.obj
OBJ_TEST_COMP_write_sink_MT_R		=   $(PROJ_OBJ_DIR)\test.component.sink.string.write.mt.obj
OBJ_TEST_COMP_x_1_MT_R			=   $(PROJ_OBJ_DIR)\test.component.fsde.mt.obj
OBJ_TEST_COMP_snk_ostm_MT_R		=   $(PROJ_OBJ_DIR)\test.component.sink.ostream.mt.obj
OBJ_TEST_COMP_file_ST_D			=   $(PROJ_OBJ_DIR)\test.component.FILE.debug.obj
OBJ_TEST_COMP_fmt_sink_ST_D		=   $(PROJ_OBJ_DIR)\test.component.sink.string.fmt.debug.obj
OBJ_TEST_COMP_ins_hex_ST_D		=   $(PROJ_OBJ_DIR)\test.component.inserter.hex.debug.obj
OBJ_TEST_COMP_ins_int_ST_D		=   $(PROJ_OBJ_DIR)\test.component.inserter.integer.debug.obj
OBJ_TEST_COMP_ins_real_ST_D		=   $(PROJ_OBJ_DIR)\test.component.inserter.real.debug.obj
OBJ_TEST_COMP_itr_fmt_ST_D		=   $(PROJ_OBJ_DIR)\test.component.itrs.fmt_itr.debug.obj
OBJ_TEST_COMP_null_sink_ST_D		=   $(PROJ_OBJ_DIR)\test.component.sink.null.debug.obj
OBJ_TEST_COMP_snk_a_b_ST_D		=   $(PROJ_OBJ_DIR)\test.component.sink.auto_buffer.debug.obj
OBJ_TEST_COMP_write_sink_ST_D		=   $(PROJ_OBJ_DIR)\test.component.sink.string.write.debug.obj
OBJ_TEST_COMP_x_1_ST_D			=   $(PROJ_OBJ_DIR)\test.component.fsde.debug.obj
OBJ_TEST_COMP_snk_ostm_ST_D		=   $(PROJ_OBJ_DIR)\test.component.sink.ostream.debug.obj
OBJ_TEST_COMP_file_ST_R			=   $(PROJ_OBJ_DIR)\test.component.FILE.obj
OBJ_TEST_COMP_fmt_sink_ST_R		=   $(PROJ_OBJ_DIR)\test.component.sink.string.fmt.obj
OBJ_TEST_COMP_ins_hex_ST_R		=   $(PROJ_OBJ_DIR)\test.component.inserter.hex.obj
OBJ_TEST_COMP_ins_int_ST_R		=   $(PROJ_OBJ_DIR)\test.component.inserter.integer.obj
OBJ_TEST_COMP_ins_real_ST_R		=   $(PROJ_OBJ_DIR)\test.component.inserter.real.obj
OBJ_TEST_COMP_itr_fmt_ST_R		=   $(PROJ_OBJ_DIR)\test.component.itrs.fmt_itr.obj
OBJ_TEST_COMP_null_sink_ST_R		=   $(PROJ_OBJ_DIR)\test.component.sink.null.obj
OBJ_TEST_COMP_snk_a_b_ST_R		=   $(PROJ_OBJ_DIR)\test.component.sink.auto_buffer.obj
OBJ_TEST_COMP_write_sink_ST_R		=   $(PROJ_OBJ_DIR)\test.component.sink.string.write.obj
OBJ_TEST_COMP_x_1_ST_R			=   $(PROJ_OBJ_DIR)\test.component.fsde.obj
OBJ_TEST_COMP_snk_ostm_ST_R		=   $(PROJ_OBJ_DIR)\test.component.sink.ostream.obj

##############################
# Performance Tests

OBJ_TEST_PERF_scen1_MT_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario1.mt.debug.obj
OBJ_TEST_PERF_scen2_MT_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario2.mt.debug.obj
OBJ_TEST_PERF_scen3_MT_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario3.mt.debug.obj
OBJ_TEST_PERF_scen4_MT_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario4.mt.debug.obj
OBJ_TEST_PERF_scen5_MT_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario5.mt.debug.obj
OBJ_TEST_PERF_scen6_MT_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario6.mt.debug.obj
OBJ_TEST_PERF_scen7_MT_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario7.mt.debug.obj
ifdef BOOST
OBJ_TEST_PERF_scen8_MT_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario8.mt.debug.obj
endif # BOOST
OBJ_TEST_PERF_scen1_MT_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario1.mt.obj
OBJ_TEST_PERF_scen2_MT_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario2.mt.obj
OBJ_TEST_PERF_scen3_MT_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario3.mt.obj
OBJ_TEST_PERF_scen4_MT_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario4.mt.obj
OBJ_TEST_PERF_scen5_MT_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario5.mt.obj
OBJ_TEST_PERF_scen6_MT_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario6.mt.obj
OBJ_TEST_PERF_scen7_MT_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario7.mt.obj
ifdef BOOST
OBJ_TEST_PERF_scen8_MT_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario8.mt.obj
endif # BOOST
OBJ_TEST_PERF_scen1_ST_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario1.debug.obj
OBJ_TEST_PERF_scen2_ST_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario2.debug.obj
OBJ_TEST_PERF_scen3_ST_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario3.debug.obj
OBJ_TEST_PERF_scen4_ST_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario4.debug.obj
OBJ_TEST_PERF_scen5_ST_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario5.debug.obj
OBJ_TEST_PERF_scen6_ST_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario6.debug.obj
OBJ_TEST_PERF_scen7_ST_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario7.debug.obj
ifdef BOOST
OBJ_TEST_PERF_scen8_ST_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario8.debug.obj
endif # BOOST
OBJ_TEST_PERF_scen1_ST_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario1.obj
OBJ_TEST_PERF_scen2_ST_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario2.obj
OBJ_TEST_PERF_scen3_ST_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario3.obj
OBJ_TEST_PERF_scen4_ST_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario4.obj
OBJ_TEST_PERF_scen5_ST_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario5.obj
OBJ_TEST_PERF_scen6_ST_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario6.obj
OBJ_TEST_PERF_scen7_ST_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario7.obj
ifdef BOOST
OBJ_TEST_PERF_scen8_ST_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario8.obj
endif # BOOST

##############################
# Scratch Tests

OBJ_TEST_SCRT_file_MT_D =   $(PROJ_OBJ_DIR)\test.scratch.FILE.mt.debug.obj
OBJ_TEST_SCRT_file_MT_R =   $(PROJ_OBJ_DIR)\test.scratch.FILE.mt.obj
OBJ_TEST_SCRT_file_ST_D =   $(PROJ_OBJ_DIR)\test.scratch.FILE.debug.obj
OBJ_TEST_SCRT_file_ST_R =   $(PROJ_OBJ_DIR)\test.scratch.FILE.obj

OBJ_TEST_SCRT_speech_MT_D =   $(PROJ_OBJ_DIR)\test.scratch.speech.mt.debug.obj
OBJ_TEST_SCRT_speech_MT_R =   $(PROJ_OBJ_DIR)\test.scratch.speech.mt.obj
OBJ_TEST_SCRT_speech_ST_D =   $(PROJ_OBJ_DIR)\test.scratch.speech.debug.obj
OBJ_TEST_SCRT_speech_ST_R =   $(PROJ_OBJ_DIR)\test.scratch.speech.obj

##############################
# Unit Tests

OBJ_TEST_UNIT_api_acsllen_MT_D	=   $(PROJ_OBJ_DIR)\test.unit.api.accum_slice_lens.mt.debug.obj
OBJ_TEST_UNIT_api_crlf_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.api.crlf_for_platform.mt.debug.obj
OBJ_TEST_UNIT_api_flrpl_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.api.fill_replacements.mt.debug.obj
OBJ_TEST_UNIT_api_illfmdh_MT_D	=   $(PROJ_OBJ_DIR)\test.unit.api.illformed_handlers.mt.debug.obj
OBJ_TEST_UNIT_api_init_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.api.initialisation.mt.debug.obj
OBJ_TEST_UNIT_api_lkptrn_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.api.lookup_pattern.mt.debug.obj
OBJ_TEST_UNIT_api_msmtchh_MT_D	=   $(PROJ_OBJ_DIR)\test.unit.api.mismatched_handlers.mt.debug.obj
OBJ_TEST_UNIT_api_prsrpl_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.api.parse_format.mt.debug.obj
OBJ_TEST_UNIT_bndl_winini_MT_D	=   $(PROJ_OBJ_DIR)\test.unit.bundle.winini.mt.debug.obj
OBJ_TEST_UNIT_fmt_stdfl_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.format.standard_flags.mt.debug.obj
OBJ_TEST_UNIT_ins_ch_MT_D			=   $(PROJ_OBJ_DIR)\test.unit.inserters.character.mt.debug.obj
OBJ_TEST_UNIT_ins_i_MT_D			=   $(PROJ_OBJ_DIR)\test.unit.inserters.integer.mt.debug.obj
OBJ_TEST_UNIT_shim_fi_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.shims.fast_integers.mt.debug.obj
OBJ_TEST_UNIT_snk_a_b_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.auto_buffer.mt.debug.obj
OBJ_TEST_UNIT_snk_c_str_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.c_string.mt.debug.obj
OBJ_TEST_UNIT_snk_chbuf_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.char_buffer.mt.debug.obj
OBJ_TEST_UNIT_snk_null_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.null.mt.debug.obj
OBJ_TEST_UNIT_snk_ods_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.ODS.mt.debug.obj
OBJ_TEST_UNIT_snk_ostm_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.ostream.mt.debug.obj
OBJ_TEST_UNIT_snk_sstm_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.stringstream.mt.debug.obj

OBJ_TEST_UNIT_api_acsllen_MT_R	=   $(PROJ_OBJ_DIR)\test.unit.api.accum_slice_lens.mt.obj
OBJ_TEST_UNIT_api_crlf_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.api.crlf_for_platform.mt.obj
OBJ_TEST_UNIT_api_flrpl_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.api.fill_replacements.mt.obj
OBJ_TEST_UNIT_api_illfmdh_MT_R	=   $(PROJ_OBJ_DIR)\test.unit.api.illformed_handlers.mt.obj
OBJ_TEST_UNIT_api_init_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.api.initialisation.mt.obj
OBJ_TEST_UNIT_api_lkptrn_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.api.lookup_pattern.mt.obj
OBJ_TEST_UNIT_api_msmtchh_MT_R	=   $(PROJ_OBJ_DIR)\test.unit.api.mismatched_handlers.mt.obj
OBJ_TEST_UNIT_api_prsrpl_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.api.parse_format.mt.obj
OBJ_TEST_UNIT_bndl_winini_MT_R	=   $(PROJ_OBJ_DIR)\test.unit.bundle.winini.mt.obj
OBJ_TEST_UNIT_fmt_stdfl_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.format.standard_flags.mt.obj
OBJ_TEST_UNIT_ins_ch_MT_R			=   $(PROJ_OBJ_DIR)\test.unit.inserters.character.mt.obj
OBJ_TEST_UNIT_ins_i_MT_R			=   $(PROJ_OBJ_DIR)\test.unit.inserters.integer.mt.obj
OBJ_TEST_UNIT_shim_fi_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.shims.fast_integers.mt.obj
OBJ_TEST_UNIT_snk_a_b_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.auto_buffer.mt.obj
OBJ_TEST_UNIT_snk_c_str_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.c_string.mt.obj
OBJ_TEST_UNIT_snk_chbuf_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.char_buffer.mt.obj
OBJ_TEST_UNIT_snk_null_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.null.mt.obj
OBJ_TEST_UNIT_snk_ods_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.ODS.mt.obj
OBJ_TEST_UNIT_snk_ostm_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.ostream.mt.obj
OBJ_TEST_UNIT_snk_sstm_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.stringstream.mt.obj

OBJ_TEST_UNIT_api_acsllen_ST_D	=   $(PROJ_OBJ_DIR)\test.unit.api.accum_slice_lens.debug.obj
OBJ_TEST_UNIT_api_crlf_ST_D		=   $(PROJ_OBJ_DIR)\test.unit.api.crlf_for_platform.debug.obj
OBJ_TEST_UNIT_api_flrpl_ST_D		=   $(PROJ_OBJ_DIR)\test.unit.api.fill_replacements.debug.obj
OBJ_TEST_UNIT_api_illfmdh_ST_D	=   $(PROJ_OBJ_DIR)\test.unit.api.illformed_handlers.debug.obj
OBJ_TEST_UNIT_api_init_ST_D		=   $(PROJ_OBJ_DIR)\test.unit.api.initialisation.debug.obj
OBJ_TEST_UNIT_api_lkptrn_ST_D		=   $(PROJ_OBJ_DIR)\test.unit.api.lookup_pattern.debug.obj
OBJ_TEST_UNIT_api_msmtchh_ST_D	=   $(PROJ_OBJ_DIR)\test.unit.api.mismatched_handlers.debug.obj
OBJ_TEST_UNIT_api_prsrpl_ST_D		=   $(PROJ_OBJ_DIR)\test.unit.api.parse_format.debug.obj
OBJ_TEST_UNIT_bndl_winini_ST_D	=   $(PROJ_OBJ_DIR)\test.unit.bundle.winini.debug.obj
OBJ_TEST_UNIT_fmt_stdfl_ST_D		=   $(PROJ_OBJ_DIR)\test.unit.format.standard_flags.debug.obj
OBJ_TEST_UNIT_ins_ch_ST_D			=   $(PROJ_OBJ_DIR)\test.unit.inserters.character.debug.obj
OBJ_TEST_UNIT_ins_i_ST_D			=   $(PROJ_OBJ_DIR)\test.unit.inserters.integer.debug.obj
OBJ_TEST_UNIT_shim_fi_ST_D		=   $(PROJ_OBJ_DIR)\test.unit.shims.fast_integers.debug.obj
OBJ_TEST_UNIT_snk_a_b_ST_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.auto_buffer.debug.obj
OBJ_TEST_UNIT_snk_c_str_ST_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.c_string.debug.obj
OBJ_TEST_UNIT_snk_chbuf_ST_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.char_buffer.debug.obj
OBJ_TEST_UNIT_snk_null_ST_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.null.debug.obj
OBJ_TEST_UNIT_snk_ods_ST_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.ODS.debug.obj
OBJ_TEST_UNIT_snk_ostm_ST_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.ostream.debug.obj
OBJ_TEST_UNIT_snk_sstm_ST_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.stringstream.debug.obj

OBJ_TEST_UNIT_api_acsllen_ST_R	=   $(PROJ_OBJ_DIR)\test.unit.api.accum_slice_lens.obj
OBJ_TEST_UNIT_api_crlf_ST_R		=   $(PROJ_OBJ_DIR)\test.unit.api.crlf_for_platform.obj
OBJ_TEST_UNIT_api_flrpl_ST_R		=   $(PROJ_OBJ_DIR)\test.unit.api.fill_replacements.obj
OBJ_TEST_UNIT_api_illfmdh_ST_R	=   $(PROJ_OBJ_DIR)\test.unit.api.illformed_handlers.obj
OBJ_TEST_UNIT_api_init_ST_R		=   $(PROJ_OBJ_DIR)\test.unit.api.initialisation.obj
OBJ_TEST_UNIT_api_lkptrn_ST_R		=   $(PROJ_OBJ_DIR)\test.unit.api.lookup_pattern.obj
OBJ_TEST_UNIT_api_msmtchh_ST_R	=   $(PROJ_OBJ_DIR)\test.unit.api.mismatched_handlers.obj
OBJ_TEST_UNIT_api_prsrpl_ST_R		=   $(PROJ_OBJ_DIR)\test.unit.api.parse_format.obj
OBJ_TEST_UNIT_bndl_winini_ST_R	=   $(PROJ_OBJ_DIR)\test.unit.bundle.winini.obj
OBJ_TEST_UNIT_fmt_stdfl_ST_R		=   $(PROJ_OBJ_DIR)\test.unit.format.standard_flags.obj
OBJ_TEST_UNIT_ins_ch_ST_R			=   $(PROJ_OBJ_DIR)\test.unit.inserters.character.obj
OBJ_TEST_UNIT_ins_i_ST_R			=   $(PROJ_OBJ_DIR)\test.unit.inserters.integer.obj
OBJ_TEST_UNIT_shim_fi_ST_R		=   $(PROJ_OBJ_DIR)\test.unit.shims.fast_integers.obj
OBJ_TEST_UNIT_snk_a_b_ST_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.auto_buffer.obj
OBJ_TEST_UNIT_snk_c_str_ST_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.c_string.obj
OBJ_TEST_UNIT_snk_chbuf_ST_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.char_buffer.obj
OBJ_TEST_UNIT_snk_null_ST_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.null.obj
OBJ_TEST_UNIT_snk_ods_ST_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.ODS.obj
OBJ_TEST_UNIT_snk_ostm_ST_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.ostream.obj
OBJ_TEST_UNIT_snk_sstm_ST_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.stringstream.obj

##################################################
# Target groups

########################################
# Objects

# fastformat
OBJS_CORE = \
 $(OBJ_CORE_MT_D)\
 $(OBJ_CORE_MT_R)\
 $(OBJ_CORE_ST_D)\
 $(OBJ_CORE_ST_R)\
 \

# Loki.SafeFormat
OBJS_LOKI_SFMT = \
 $(OBJ_LOKI_SFMT_MT_D)\
 $(OBJ_LOKI_SFMT_MT_R)\
 $(OBJ_LOKI_SFMT_ST_D)\
 $(OBJ_LOKI_SFMT_ST_R)\
 \

# shwild
OBJS_SHWILD = \
 $(OBJ_SHWILD_MT_D)\
 $(OBJ_SHWILD_MT_R)\
 $(OBJ_SHWILD_ST_D)\
 $(OBJ_SHWILD_ST_R)\
 \

# xtests
OBJS_XTESTS = \
 $(OBJ_XTESTS_MT_D)\
 $(OBJ_XTESTS_MT_R)\
 $(OBJ_XTESTS_ST_D)\
 $(OBJ_XTESTS_ST_R)\
 \

# Examples
OBJS_EXAMPLE=\
 $(OBJ_EX_boolean_MT_D)\
 $(OBJ_EX_character_MT_D)\
 $(OBJ_EX_reals_MT_D)\
 $(OBJ_EX_voidptrs_MT_D)\
 $(OBJ_EX_ff_101_MT_D)\
 $(OBJ_EX_ff_101_nons_MT_D)\
 $(OBJ_EX_flush_MT_D)\
 $(OBJ_EX_ins_hex_MT_D)\
 $(OBJ_EX_ins_integers_MT_D)\
 $(OBJ_EX_ins_reals_MT_D)\
 $(OBJ_EX_ins_WLIs_MT_D)\
 $(OBJ_EX_itr_fmt_MT_D)\
 $(OBJ_EX_ovld2_filt_MT_D)\
 $(OBJ_EX_ovld2_ins_MT_D)\
 $(OBJ_EX_ovld2_sas_MT_D)\
 $(OBJ_EX_ovld3_fpcol_MT_D)\
 $(OBJ_EX_ovld3_tabs_MT_D)\
 $(OBJ_EX_ovld3_svrlg_MT_D)\
 $(OBJ_EX_ovld3_rcins_MT_D)\
 $(OBJ_EX_pad_hash_MT_D)\
 $(OBJ_EX_sink_cstr_MT_D)\
 $(OBJ_EX_sink_ODS_MT_D)\
 $(OBJ_EX_boolean_MT_R)\
 $(OBJ_EX_character_MT_R)\
 $(OBJ_EX_reals_MT_R)\
 $(OBJ_EX_voidptrs_MT_R)\
 $(OBJ_EX_ff_101_MT_R)\
 $(OBJ_EX_ff_101_nons_MT_R)\
 $(OBJ_EX_flush_MT_R)\
 $(OBJ_EX_ins_hex_MT_R)\
 $(OBJ_EX_ins_integers_MT_R)\
 $(OBJ_EX_ins_reals_MT_R)\
 $(OBJ_EX_ins_WLIs_MT_R)\
 $(OBJ_EX_itr_fmt_MT_R)\
 $(OBJ_EX_ovld2_filt_MT_R)\
 $(OBJ_EX_ovld2_ins_MT_R)\
 $(OBJ_EX_ovld2_sas_MT_R)\
 $(OBJ_EX_ovld3_fpcol_MT_R)\
 $(OBJ_EX_ovld3_tabs_MT_R)\
 $(OBJ_EX_ovld3_svrlg_MT_R)\
 $(OBJ_EX_ovld3_rcins_MT_R)\
 $(OBJ_EX_pad_hash_MT_R)\
 $(OBJ_EX_sink_cstr_MT_R)\
 $(OBJ_EX_sink_ODS_MT_R)\
 $(OBJ_EX_boolean_ST_D)\
 $(OBJ_EX_character_ST_D)\
 $(OBJ_EX_reals_ST_D)\
 $(OBJ_EX_voidptrs_ST_D)\
 $(OBJ_EX_ff_101_ST_D)\
 $(OBJ_EX_ff_101_nons_ST_D)\
 $(OBJ_EX_flush_ST_D)\
 $(OBJ_EX_ins_hex_ST_D)\
 $(OBJ_EX_ins_integers_ST_D)\
 $(OBJ_EX_ins_reals_ST_D)\
 $(OBJ_EX_ins_WLIs_ST_D)\
 $(OBJ_EX_itr_fmt_ST_D)\
 $(OBJ_EX_ovld2_filt_ST_D)\
 $(OBJ_EX_ovld2_ins_ST_D)\
 $(OBJ_EX_ovld2_sas_ST_D)\
 $(OBJ_EX_ovld3_fpcol_ST_D)\
 $(OBJ_EX_ovld3_tabs_ST_D)\
 $(OBJ_EX_ovld3_svrlg_ST_D)\
 $(OBJ_EX_ovld3_rcins_ST_D)\
 $(OBJ_EX_pad_hash_ST_D)\
 $(OBJ_EX_sink_cstr_ST_D)\
 $(OBJ_EX_sink_ODS_ST_D)\
 $(OBJ_EX_boolean_ST_R)\
 $(OBJ_EX_character_ST_R)\
 $(OBJ_EX_reals_ST_R)\
 $(OBJ_EX_voidptrs_ST_R)\
 $(OBJ_EX_ff_101_ST_R)\
 $(OBJ_EX_ff_101_nons_ST_R)\
 $(OBJ_EX_flush_ST_R)\
 $(OBJ_EX_ins_hex_ST_R)\
 $(OBJ_EX_ins_integers_ST_R)\
 $(OBJ_EX_ins_reals_ST_R)\
 $(OBJ_EX_ins_WLIs_ST_R)\
 $(OBJ_EX_itr_fmt_ST_R)\
 $(OBJ_EX_ovld2_filt_ST_R)\
 $(OBJ_EX_ovld2_ins_ST_R)\
 $(OBJ_EX_ovld2_sas_ST_R)\
 $(OBJ_EX_ovld3_fpcol_ST_R)\
 $(OBJ_EX_ovld3_tabs_ST_R)\
 $(OBJ_EX_ovld3_svrlg_ST_R)\
 $(OBJ_EX_ovld3_rcins_ST_R)\
 $(OBJ_EX_pad_hash_ST_R)\
 $(OBJ_EX_sink_cstr_ST_R)\
 $(OBJ_EX_sink_ODS_ST_R)\
 \

# Component Tests
OBJS_TEST_COMPONENT=\
 $(OBJ_TEST_COMP_file_MT_D)\
 $(OBJ_TEST_COMP_fmt_sink_MT_D)\
 $(OBJ_TEST_COMP_ins_hex_MT_D)\
 $(OBJ_TEST_COMP_ins_int_MT_D)\
 $(OBJ_TEST_COMP_ins_real_MT_D)\
 $(OBJ_TEST_COMP_itr_fmt_MT_D)\
 $(OBJ_TEST_COMP_null_sink_MT_D)\
 $(OBJ_TEST_COMP_snk_a_b_MT_D)\
 $(OBJ_TEST_COMP_write_sink_MT_D)\
 $(OBJ_TEST_COMP_x_1_MT_D)\
 $(OBJ_TEST_COMP_snk_ostm_MT_D)\
 $(OBJ_TEST_COMP_file_MT_R)\
 $(OBJ_TEST_COMP_fmt_sink_MT_R)\
 $(OBJ_TEST_COMP_ins_hex_MT_R)\
 $(OBJ_TEST_COMP_ins_int_MT_R)\
 $(OBJ_TEST_COMP_ins_real_MT_R)\
 $(OBJ_TEST_COMP_itr_fmt_MT_R)\
 $(OBJ_TEST_COMP_null_sink_MT_R)\
 $(OBJ_TEST_COMP_snk_a_b_MT_R)\
 $(OBJ_TEST_COMP_write_sink_MT_R)\
 $(OBJ_TEST_COMP_x_1_MT_R)\
 $(OBJ_TEST_COMP_snk_ostm_MT_R)\
 $(OBJ_TEST_COMP_file_ST_D)\
 $(OBJ_TEST_COMP_fmt_sink_ST_D)\
 $(OBJ_TEST_COMP_ins_hex_ST_D)\
 $(OBJ_TEST_COMP_ins_int_ST_D)\
 $(OBJ_TEST_COMP_ins_real_ST_D)\
 $(OBJ_TEST_COMP_itr_fmt_ST_D)\
 $(OBJ_TEST_COMP_null_sink_ST_D)\
 $(OBJ_TEST_COMP_snk_a_b_ST_D)\
 $(OBJ_TEST_COMP_write_sink_ST_D)\
 $(OBJ_TEST_COMP_x_1_ST_D)\
 $(OBJ_TEST_COMP_snk_ostm_ST_D)\
 $(OBJ_TEST_COMP_file_ST_R)\
 $(OBJ_TEST_COMP_fmt_sink_ST_R)\
 $(OBJ_TEST_COMP_ins_hex_ST_R)\
 $(OBJ_TEST_COMP_ins_int_ST_R)\
 $(OBJ_TEST_COMP_ins_real_ST_R)\
 $(OBJ_TEST_COMP_itr_fmt_ST_R)\
 $(OBJ_TEST_COMP_null_sink_ST_R)\
 $(OBJ_TEST_COMP_snk_a_b_ST_R)\
 $(OBJ_TEST_COMP_write_sink_ST_R)\
 $(OBJ_TEST_COMP_x_1_ST_R)\
 $(OBJ_TEST_COMP_snk_ostm_ST_R)\
 \

# Performance Tests
OBJS_TEST_PERFORMANCE_BOOST=

ifdef BOOST
OBJS_TEST_PERFORMANCE_BOOST=\
 $(OBJ_TEST_PERF_scen8_MT_D)\
 $(OBJ_TEST_PERF_scen8_MT_R)\
 $(OBJ_TEST_PERF_scen8_ST_D)\
 $(OBJ_TEST_PERF_scen8_ST_R)\
 \

endif # BOOST

OBJS_TEST_PERFORMANCE=\
 $(OBJ_TEST_PERF_scen1_MT_D)\
 $(OBJ_TEST_PERF_scen2_MT_D)\
 $(OBJ_TEST_PERF_scen3_MT_D)\
 $(OBJ_TEST_PERF_scen4_MT_D)\
 $(OBJ_TEST_PERF_scen5_MT_D)\
 $(OBJ_TEST_PERF_scen6_MT_D)\
 $(OBJ_TEST_PERF_scen7_MT_D)\
 $(OBJ_TEST_PERF_scen1_MT_R)\
 $(OBJ_TEST_PERF_scen2_MT_R)\
 $(OBJ_TEST_PERF_scen3_MT_R)\
 $(OBJ_TEST_PERF_scen4_MT_R)\
 $(OBJ_TEST_PERF_scen5_MT_R)\
 $(OBJ_TEST_PERF_scen6_MT_R)\
 $(OBJ_TEST_PERF_scen7_MT_R)\
 $(OBJ_TEST_PERF_scen1_ST_D)\
 $(OBJ_TEST_PERF_scen2_ST_D)\
 $(OBJ_TEST_PERF_scen3_ST_D)\
 $(OBJ_TEST_PERF_scen4_ST_D)\
 $(OBJ_TEST_PERF_scen5_ST_D)\
 $(OBJ_TEST_PERF_scen6_ST_D)\
 $(OBJ_TEST_PERF_scen7_ST_D)\
 $(OBJ_TEST_PERF_scen1_ST_R)\
 $(OBJ_TEST_PERF_scen2_ST_R)\
 $(OBJ_TEST_PERF_scen3_ST_R)\
 $(OBJ_TEST_PERF_scen4_ST_R)\
 $(OBJ_TEST_PERF_scen5_ST_R)\
 $(OBJ_TEST_PERF_scen6_ST_R)\
 $(OBJ_TEST_PERF_scen7_ST_R)\
 $(OBJS_TEST_PERFORMANCE_BOOST)\
 \

# Scratch Tests
OBJS_TEST_SCRATCH=\
 $(OBJ_TEST_SCRT_file_MT_D)\
 $(OBJ_TEST_SCRT_speech_MT_D)\
 $(OBJ_TEST_SCRT_file_MT_R)\
 $(OBJ_TEST_SCRT_speech_MT_R)\
 $(OBJ_TEST_SCRT_file_ST_D)\
 $(OBJ_TEST_SCRT_speech_ST_D)\
 $(OBJ_TEST_SCRT_file_ST_R)\
 $(OBJ_TEST_SCRT_speech_ST_R)\
 \

# Unit Tests
OBJS_TEST_UNIT=\
 $(OBJ_TEST_UNIT_api_acsllen_MT_D)\
 $(OBJ_TEST_UNIT_api_crlf_MT_D)\
 $(OBJ_TEST_UNIT_api_flrpl_MT_D)\
 $(OBJ_TEST_UNIT_api_illfmdh_MT_D)\
 $(OBJ_TEST_UNIT_api_init_MT_D)\
 $(OBJ_TEST_UNIT_api_lkptrn_MT_D)\
 $(OBJ_TEST_UNIT_api_msmtchh_MT_D)\
 $(OBJ_TEST_UNIT_api_prsrpl_MT_D)\
 $(OBJ_TEST_UNIT_bndl_winini_MT_D)\
 $(OBJ_TEST_UNIT_fmt_stdfl_MT_D)\
 $(OBJ_TEST_UNIT_ins_ch_MT_D)\
 $(OBJ_TEST_UNIT_ins_i_MT_D)\
 $(OBJ_TEST_UNIT_shim_fi_MT_D)\
 $(OBJ_TEST_UNIT_snk_a_b_MT_D)\
 $(OBJ_TEST_UNIT_snk_c_str_MT_D)\
 $(OBJ_TEST_UNIT_snk_chbuf_MT_D)\
 $(OBJ_TEST_UNIT_snk_null_MT_D)\
 $(OBJ_TEST_UNIT_snk_ods_MT_D)\
 $(OBJ_TEST_UNIT_snk_ostm_MT_D)\
 $(OBJ_TEST_UNIT_snk_sstm_MT_D)\
 $(OBJ_TEST_UNIT_api_acsllen_MT_R)\
 $(OBJ_TEST_UNIT_api_crlf_MT_R)\
 $(OBJ_TEST_UNIT_api_flrpl_MT_R)\
 $(OBJ_TEST_UNIT_api_illfmdh_MT_R)\
 $(OBJ_TEST_UNIT_api_init_MT_R)\
 $(OBJ_TEST_UNIT_api_lkptrn_MT_R)\
 $(OBJ_TEST_UNIT_api_msmtchh_MT_R)\
 $(OBJ_TEST_UNIT_api_prsrpl_MT_R)\
 $(OBJ_TEST_UNIT_bndl_winini_MT_R)\
 $(OBJ_TEST_UNIT_fmt_stdfl_MT_R)\
 $(OBJ_TEST_UNIT_ins_ch_MT_R)\
 $(OBJ_TEST_UNIT_ins_i_MT_R)\
 $(OBJ_TEST_UNIT_shim_fi_MT_R)\
 $(OBJ_TEST_UNIT_snk_a_b_MT_R)\
 $(OBJ_TEST_UNIT_snk_c_str_MT_R)\
 $(OBJ_TEST_UNIT_snk_chbuf_MT_R)\
 $(OBJ_TEST_UNIT_snk_null_MT_R)\
 $(OBJ_TEST_UNIT_snk_ods_MT_R)\
 $(OBJ_TEST_UNIT_snk_ostm_MT_R)\
 $(OBJ_TEST_UNIT_snk_sstm_MT_R)\
 $(OBJ_TEST_UNIT_api_acsllen_ST_D)\
 $(OBJ_TEST_UNIT_api_crlf_ST_D)\
 $(OBJ_TEST_UNIT_api_flrpl_ST_D)\
 $(OBJ_TEST_UNIT_api_illfmdh_ST_D)\
 $(OBJ_TEST_UNIT_api_init_ST_D)\
 $(OBJ_TEST_UNIT_api_lkptrn_ST_D)\
 $(OBJ_TEST_UNIT_api_msmtchh_ST_D)\
 $(OBJ_TEST_UNIT_api_prsrpl_ST_D)\
 $(OBJ_TEST_UNIT_bndl_winini_ST_D)\
 $(OBJ_TEST_UNIT_fmt_stdfl_ST_D)\
 $(OBJ_TEST_UNIT_ins_ch_ST_D)\
 $(OBJ_TEST_UNIT_ins_i_ST_D)\
 $(OBJ_TEST_UNIT_shim_fi_ST_D)\
 $(OBJ_TEST_UNIT_snk_a_b_ST_D)\
 $(OBJ_TEST_UNIT_snk_c_str_ST_D)\
 $(OBJ_TEST_UNIT_snk_chbuf_ST_D)\
 $(OBJ_TEST_UNIT_snk_null_ST_D)\
 $(OBJ_TEST_UNIT_snk_ods_ST_D)\
 $(OBJ_TEST_UNIT_snk_ostm_ST_D)\
 $(OBJ_TEST_UNIT_snk_sstm_ST_D)\
 $(OBJ_TEST_UNIT_api_acsllen_ST_R)\
 $(OBJ_TEST_UNIT_api_crlf_ST_R)\
 $(OBJ_TEST_UNIT_api_flrpl_ST_R)\
 $(OBJ_TEST_UNIT_api_illfmdh_ST_R)\
 $(OBJ_TEST_UNIT_api_init_ST_R)\
 $(OBJ_TEST_UNIT_api_lkptrn_ST_R)\
 $(OBJ_TEST_UNIT_api_msmtchh_ST_R)\
 $(OBJ_TEST_UNIT_api_prsrpl_ST_R)\
 $(OBJ_TEST_UNIT_bndl_winini_ST_R)\
 $(OBJ_TEST_UNIT_fmt_stdfl_ST_R)\
 $(OBJ_TEST_UNIT_ins_ch_ST_R)\
 $(OBJ_TEST_UNIT_ins_i_ST_R)\
 $(OBJ_TEST_UNIT_shim_fi_ST_R)\
 $(OBJ_TEST_UNIT_snk_a_b_ST_R)\
 $(OBJ_TEST_UNIT_snk_c_str_ST_R)\
 $(OBJ_TEST_UNIT_snk_chbuf_ST_R)\
 $(OBJ_TEST_UNIT_snk_null_ST_R)\
 $(OBJ_TEST_UNIT_snk_ods_ST_R)\
 $(OBJ_TEST_UNIT_snk_ostm_ST_R)\
 $(OBJ_TEST_UNIT_snk_sstm_ST_R)\
 \

########################################
# Libraries

TARGETS_LIB_CORE = \
 $(LIB_CORE_MT_D)\
 $(LIB_CORE_MT_R)\
 $(LIB_CORE_ST_D)\
 $(LIB_CORE_ST_R)\
 \

TARGETS_LIB_LOKI_SFMT = \
 $(LIB_LOKI_SFMT_MT_D)\
 $(LIB_LOKI_SFMT_MT_R)\
 $(LIB_LOKI_SFMT_ST_D)\
 $(LIB_LOKI_SFMT_ST_R)\
 \

TARGETS_LIB_SHWILD = \
 $(LIB_SHWILD_MT_D)\
 $(LIB_SHWILD_MT_R)\
 $(LIB_SHWILD_ST_D)\
 $(LIB_SHWILD_ST_R)\
 \

TARGETS_LIB_XTESTS = \
 $(LIB_XTESTS_MT_D)\
 $(LIB_XTESTS_MT_R)\
 $(LIB_XTESTS_ST_D)\
 $(LIB_XTESTS_ST_R)\
 \

########################################
# Programs

TARGETS_BITBUCKET=\
 $(TARG_BITBUCKET_MT_D)\
 $(TARG_BITBUCKET_MT_R)\
 $(TARG_BITBUCKET_ST_D)\
 $(TARG_BITBUCKET_ST_R)\
 \

TARGETS_EXAMPLE=\
 $(TARG_EX_boolean_MT_D)\
 $(TARG_EX_character_MT_D)\
 $(TARG_EX_reals_MT_D)\
 $(TARG_EX_voidptrs_MT_D)\
 $(TARG_EX_ff_101_MT_D)\
 $(TARG_EX_ff_101_nons_MT_D)\
 $(TARG_EX_flush_MT_D)\
 $(TARG_EX_ins_hex_MT_D)\
 $(TARG_EX_ins_integers_MT_D)\
 $(TARG_EX_ins_reals_MT_D)\
 $(TARG_EX_ins_WLIs_MT_D)\
 $(TARG_EX_itr_fmt_MT_D)\
 $(TARG_EX_ovld2_filt_MT_D)\
 $(TARG_EX_ovld2_ins_MT_D)\
 $(TARG_EX_ovld2_sas_MT_D)\
 $(TARG_EX_ovld3_fpcol_MT_D)\
 $(TARG_EX_ovld3_tabs_MT_D)\
 $(TARG_EX_ovld3_svrlg_MT_D)\
 $(TARG_EX_ovld3_rcins_MT_D)\
 $(TARG_EX_pad_hash_MT_D)\
 $(TARG_EX_sink_cstr_MT_D)\
 $(TARG_EX_sink_ODS_MT_D)\
 $(TARG_EX_boolean_MT_R)\
 $(TARG_EX_character_MT_R)\
 $(TARG_EX_reals_MT_R)\
 $(TARG_EX_voidptrs_MT_R)\
 $(TARG_EX_ff_101_MT_R)\
 $(TARG_EX_ff_101_nons_MT_R)\
 $(TARG_EX_flush_MT_R)\
 $(TARG_EX_ins_hex_MT_R)\
 $(TARG_EX_ins_integers_MT_R)\
 $(TARG_EX_ins_reals_MT_R)\
 $(TARG_EX_ins_WLIs_MT_R)\
 $(TARG_EX_itr_fmt_MT_R)\
 $(TARG_EX_ovld2_filt_MT_R)\
 $(TARG_EX_ovld2_ins_MT_R)\
 $(TARG_EX_ovld2_sas_MT_R)\
 $(TARG_EX_ovld3_fpcol_MT_R)\
 $(TARG_EX_ovld3_tabs_MT_R)\
 $(TARG_EX_ovld3_svrlg_MT_R)\
 $(TARG_EX_ovld3_rcins_MT_R)\
 $(TARG_EX_pad_hash_MT_R)\
 $(TARG_EX_sink_cstr_MT_R)\
 $(TARG_EX_sink_ODS_MT_R)\
 $(TARG_EX_boolean_ST_D)\
 $(TARG_EX_character_ST_D)\
 $(TARG_EX_reals_ST_D)\
 $(TARG_EX_voidptrs_ST_D)\
 $(TARG_EX_ff_101_ST_D)\
 $(TARG_EX_ff_101_nons_ST_D)\
 $(TARG_EX_flush_ST_D)\
 $(TARG_EX_ins_hex_ST_D)\
 $(TARG_EX_ins_integers_ST_D)\
 $(TARG_EX_ins_reals_ST_D)\
 $(TARG_EX_ins_WLIs_ST_D)\
 $(TARG_EX_itr_fmt_ST_D)\
 $(TARG_EX_ovld2_filt_ST_D)\
 $(TARG_EX_ovld2_ins_ST_D)\
 $(TARG_EX_ovld2_sas_ST_D)\
 $(TARG_EX_ovld3_fpcol_ST_D)\
 $(TARG_EX_ovld3_tabs_ST_D)\
 $(TARG_EX_ovld3_svrlg_ST_D)\
 $(TARG_EX_ovld3_rcins_ST_D)\
 $(TARG_EX_pad_hash_ST_D)\
 $(TARG_EX_sink_cstr_ST_D)\
 $(TARG_EX_sink_ODS_ST_D)\
 $(TARG_EX_boolean_ST_R)\
 $(TARG_EX_character_ST_R)\
 $(TARG_EX_reals_ST_R)\
 $(TARG_EX_voidptrs_ST_R)\
 $(TARG_EX_ff_101_ST_R)\
 $(TARG_EX_ff_101_nons_ST_R)\
 $(TARG_EX_flush_ST_R)\
 $(TARG_EX_ins_hex_ST_R)\
 $(TARG_EX_ins_integers_ST_R)\
 $(TARG_EX_ins_reals_ST_R)\
 $(TARG_EX_ins_WLIs_ST_R)\
 $(TARG_EX_itr_fmt_ST_R)\
 $(TARG_EX_ovld2_filt_ST_R)\
 $(TARG_EX_ovld2_ins_ST_R)\
 $(TARG_EX_ovld2_sas_ST_R)\
 $(TARG_EX_ovld3_fpcol_ST_R)\
 $(TARG_EX_ovld3_tabs_ST_R)\
 $(TARG_EX_ovld3_svrlg_ST_R)\
 $(TARG_EX_ovld3_rcins_ST_R)\
 $(TARG_EX_pad_hash_ST_R)\
 $(TARG_EX_sink_cstr_ST_R)\
 $(TARG_EX_sink_ODS_ST_R)\
 \

TARGETS_EXAMPLE_OVERLOAD_3=\
 $(TARG_EX_ovld3_fpcol_MT_R)\
 $(TARG_EX_ovld3_tabs_MT_R)\
 $(TARG_EX_ovld3_svrlg_MT_R)\
 $(TARG_EX_ovld3_rcins_MT_R)\
 $(TARG_EX_ovld3_fpcol_ST_R)\
 $(TARG_EX_ovld3_tabs_ST_R)\
 $(TARG_EX_ovld3_svrlg_ST_R)\
 $(TARG_EX_ovld3_rcins_ST_R)\
 \

TARGETS_SAMPLE=\
 \

TARGETS_TEST_COMPONENT=\
 $(TARG_TEST_COMP_file_MT_D)\
 $(TARG_TEST_COMP_fmt_sink_MT_D)\
 $(TARG_TEST_COMP_ins_hex_MT_D)\
 $(TARG_TEST_COMP_ins_int_MT_D)\
 $(TARG_TEST_COMP_ins_real_MT_D)\
 $(TARG_TEST_COMP_itr_fmt_MT_D)\
 $(TARG_TEST_COMP_null_sink_MT_D)\
 $(TARG_TEST_COMP_snk_a_b_MT_D)\
 $(TARG_TEST_COMP_write_sink_MT_D)\
 $(TARG_TEST_COMP_x_1_MT_D)\
 $(TARG_TEST_COMP_snk_ostm_MT_D)\
 $(TARG_TEST_COMP_file_MT_R)\
 $(TARG_TEST_COMP_fmt_sink_MT_R)\
 $(TARG_TEST_COMP_ins_hex_MT_R)\
 $(TARG_TEST_COMP_ins_int_MT_R)\
 $(TARG_TEST_COMP_ins_real_MT_R)\
 $(TARG_TEST_COMP_itr_fmt_MT_R)\
 $(TARG_TEST_COMP_null_sink_MT_R)\
 $(TARG_TEST_COMP_snk_a_b_MT_R)\
 $(TARG_TEST_COMP_write_sink_MT_R)\
 $(TARG_TEST_COMP_x_1_MT_R)\
 $(TARG_TEST_COMP_snk_ostm_MT_R)\
 $(TARG_TEST_COMP_file_ST_D)\
 $(TARG_TEST_COMP_fmt_sink_ST_D)\
 $(TARG_TEST_COMP_ins_hex_ST_D)\
 $(TARG_TEST_COMP_ins_int_ST_D)\
 $(TARG_TEST_COMP_ins_real_ST_D)\
 $(TARG_TEST_COMP_itr_fmt_ST_D)\
 $(TARG_TEST_COMP_null_sink_ST_D)\
 $(TARG_TEST_COMP_snk_a_b_ST_D)\
 $(TARG_TEST_COMP_write_sink_ST_D)\
 $(TARG_TEST_COMP_x_1_ST_D)\
 $(TARG_TEST_COMP_snk_ostm_ST_D)\
 $(TARG_TEST_COMP_file_ST_R)\
 $(TARG_TEST_COMP_fmt_sink_ST_R)\
 $(TARG_TEST_COMP_ins_hex_ST_R)\
 $(TARG_TEST_COMP_ins_int_ST_R)\
 $(TARG_TEST_COMP_ins_real_ST_R)\
 $(TARG_TEST_COMP_itr_fmt_ST_R)\
 $(TARG_TEST_COMP_null_sink_ST_R)\
 $(TARG_TEST_COMP_snk_a_b_ST_R)\
 $(TARG_TEST_COMP_write_sink_ST_R)\
 $(TARG_TEST_COMP_x_1_ST_R)\
 $(TARG_TEST_COMP_snk_ostm_ST_R)\
 \

TARGETS_TEST_PERFORMANCE_BOOST=

ifdef BOOST
TARGETS_TEST_PERFORMANCE_BOOST=\
 $(TARG_TEST_PERF_scen8_MT_D)\
 $(TARG_TEST_PERF_scen8_MT_R)\
 $(TARG_TEST_PERF_scen8_ST_D)\
 $(TARG_TEST_PERF_scen8_ST_R)\
 \

endif # BOOST

TARGETS_TEST_PERFORMANCE=\
 $(TARG_TEST_PERF_scen1_MT_D)\
 $(TARG_TEST_PERF_scen2_MT_D)\
 $(TARG_TEST_PERF_scen3_MT_D)\
 $(TARG_TEST_PERF_scen4_MT_D)\
 $(TARG_TEST_PERF_scen5_MT_D)\
 $(TARG_TEST_PERF_scen6_MT_D)\
 $(TARG_TEST_PERF_scen7_MT_D)\
 $(TARG_TEST_PERF_scen1_MT_R)\
 $(TARG_TEST_PERF_scen2_MT_R)\
 $(TARG_TEST_PERF_scen3_MT_R)\
 $(TARG_TEST_PERF_scen4_MT_R)\
 $(TARG_TEST_PERF_scen5_MT_R)\
 $(TARG_TEST_PERF_scen6_MT_R)\
 $(TARG_TEST_PERF_scen7_MT_R)\
 $(TARG_TEST_PERF_scen1_ST_D)\
 $(TARG_TEST_PERF_scen2_ST_D)\
 $(TARG_TEST_PERF_scen3_ST_D)\
 $(TARG_TEST_PERF_scen4_ST_D)\
 $(TARG_TEST_PERF_scen5_ST_D)\
 $(TARG_TEST_PERF_scen6_ST_D)\
 $(TARG_TEST_PERF_scen7_ST_D)\
 $(TARG_TEST_PERF_scen1_ST_R)\
 $(TARG_TEST_PERF_scen2_ST_R)\
 $(TARG_TEST_PERF_scen3_ST_R)\
 $(TARG_TEST_PERF_scen4_ST_R)\
 $(TARG_TEST_PERF_scen5_ST_R)\
 $(TARG_TEST_PERF_scen6_ST_R)\
 $(TARG_TEST_PERF_scen7_ST_R)\
 $(TARGETS_TEST_PERFORMANCE_BOOST)\
 \

TARGETS_TEST_SCRATCH=\
 $(TARG_TEST_SCRT_file_MT_D)\
 $(TARG_TEST_SCRT_speech_MT_D)\
 $(TARG_TEST_SCRT_file_MT_R)\
 $(TARG_TEST_SCRT_speech_MT_R)\
 $(TARG_TEST_SCRT_file_ST_D)\
 $(TARG_TEST_SCRT_speech_ST_D)\
 $(TARG_TEST_SCRT_file_ST_R)\
 $(TARG_TEST_SCRT_speech_ST_R)\
 \

TARGETS_TEST_UNIT=\
 $(TARG_TEST_UNIT_api_acsllen_MT_D)\
 $(TARG_TEST_UNIT_api_crlf_MT_D)\
 $(TARG_TEST_UNIT_api_flrpl_MT_D)\
 $(TARG_TEST_UNIT_api_illfmdh_MT_D)\
 $(TARG_TEST_UNIT_api_init_MT_D)\
 $(TARG_TEST_UNIT_api_lkptrn_MT_D)\
 $(TARG_TEST_UNIT_api_msmtchh_MT_D)\
 $(TARG_TEST_UNIT_api_prsrpl_MT_D)\
 $(TARG_TEST_UNIT_bndl_winini_MT_D)\
 $(TARG_TEST_UNIT_fmt_stdfl_MT_D)\
 $(TARG_TEST_UNIT_ins_ch_MT_D)\
 $(TARG_TEST_UNIT_ins_i_MT_D)\
 $(TARG_TEST_UNIT_shim_fi_MT_D)\
 $(TARG_TEST_UNIT_snk_a_b_MT_D)\
 $(TARG_TEST_UNIT_snk_c_str_MT_D)\
 $(TARG_TEST_UNIT_snk_chbuf_MT_D)\
 $(TARG_TEST_UNIT_snk_null_MT_D)\
 $(TARG_TEST_UNIT_snk_ods_MT_D)\
 $(TARG_TEST_UNIT_snk_ostm_MT_D)\
 $(TARG_TEST_UNIT_snk_sstm_MT_D)\
 $(TARG_TEST_UNIT_api_acsllen_MT_R)\
 $(TARG_TEST_UNIT_api_crlf_MT_R)\
 $(TARG_TEST_UNIT_api_flrpl_MT_R)\
 $(TARG_TEST_UNIT_api_illfmdh_MT_R)\
 $(TARG_TEST_UNIT_api_init_MT_R)\
 $(TARG_TEST_UNIT_api_lkptrn_MT_R)\
 $(TARG_TEST_UNIT_api_msmtchh_MT_R)\
 $(TARG_TEST_UNIT_api_prsrpl_MT_R)\
 $(TARG_TEST_UNIT_bndl_winini_MT_R)\
 $(TARG_TEST_UNIT_fmt_stdfl_MT_R)\
 $(TARG_TEST_UNIT_ins_ch_MT_R)\
 $(TARG_TEST_UNIT_ins_i_MT_R)\
 $(TARG_TEST_UNIT_shim_fi_MT_R)\
 $(TARG_TEST_UNIT_snk_a_b_MT_R)\
 $(TARG_TEST_UNIT_snk_c_str_MT_R)\
 $(TARG_TEST_UNIT_snk_chbuf_MT_R)\
 $(TARG_TEST_UNIT_snk_null_MT_R)\
 $(TARG_TEST_UNIT_snk_ods_MT_R)\
 $(TARG_TEST_UNIT_snk_ostm_MT_R)\
 $(TARG_TEST_UNIT_snk_sstm_MT_R)\
 $(TARG_TEST_UNIT_api_acsllen_ST_D)\
 $(TARG_TEST_UNIT_api_crlf_ST_D)\
 $(TARG_TEST_UNIT_api_flrpl_ST_D)\
 $(TARG_TEST_UNIT_api_illfmdh_ST_D)\
 $(TARG_TEST_UNIT_api_init_ST_D)\
 $(TARG_TEST_UNIT_api_lkptrn_ST_D)\
 $(TARG_TEST_UNIT_api_msmtchh_ST_D)\
 $(TARG_TEST_UNIT_api_prsrpl_ST_D)\
 $(TARG_TEST_UNIT_bndl_winini_ST_D)\
 $(TARG_TEST_UNIT_fmt_stdfl_ST_D)\
 $(TARG_TEST_UNIT_ins_ch_ST_D)\
 $(TARG_TEST_UNIT_ins_i_ST_D)\
 $(TARG_TEST_UNIT_shim_fi_ST_D)\
 $(TARG_TEST_UNIT_snk_a_b_ST_D)\
 $(TARG_TEST_UNIT_snk_c_str_ST_D)\
 $(TARG_TEST_UNIT_snk_chbuf_ST_D)\
 $(TARG_TEST_UNIT_snk_null_ST_D)\
 $(TARG_TEST_UNIT_snk_ods_ST_D)\
 $(TARG_TEST_UNIT_snk_ostm_ST_D)\
 $(TARG_TEST_UNIT_snk_sstm_ST_D)\
 $(TARG_TEST_UNIT_api_acsllen_ST_R)\
 $(TARG_TEST_UNIT_api_crlf_ST_R)\
 $(TARG_TEST_UNIT_api_flrpl_ST_R)\
 $(TARG_TEST_UNIT_api_illfmdh_ST_R)\
 $(TARG_TEST_UNIT_api_init_ST_R)\
 $(TARG_TEST_UNIT_api_lkptrn_ST_R)\
 $(TARG_TEST_UNIT_api_msmtchh_ST_R)\
 $(TARG_TEST_UNIT_api_prsrpl_ST_R)\
 $(TARG_TEST_UNIT_bndl_winini_ST_R)\
 $(TARG_TEST_UNIT_fmt_stdfl_ST_R)\
 $(TARG_TEST_UNIT_ins_ch_ST_R)\
 $(TARG_TEST_UNIT_ins_i_ST_R)\
 $(TARG_TEST_UNIT_shim_fi_ST_R)\
 $(TARG_TEST_UNIT_snk_a_b_ST_R)\
 $(TARG_TEST_UNIT_snk_c_str_ST_R)\
 $(TARG_TEST_UNIT_snk_chbuf_ST_R)\
 $(TARG_TEST_UNIT_snk_null_ST_R)\
 $(TARG_TEST_UNIT_snk_ods_ST_R)\
 $(TARG_TEST_UNIT_snk_ostm_ST_R)\
 $(TARG_TEST_UNIT_snk_sstm_ST_R)\
 \

# $(TARG_TEST_UNIT_snk_vecfile [ ` [ MakeSymbolTag ] ` ] )\

############################################################
# Third-party libraries





############################################################################
# External Targets (invokable by make)

# primary

_default:                   build

usage:
	@echo "make [usage | compile | build | test | clean] - default is 'build'"

# infrastructure



prep.files.for.os:	$(PROJ_MAKEFILE_NAME)\
	\

prep:	prep.files.for.os


check.lib.dir:              $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)

check.bin.dir:              $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)


# compile targets

compile.libs.core:          $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_CORE)

compile.libs.loki.safefmt:  $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_LOKI_SFMT)

compile.libs.shwild:        $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_SHWILD)

compile.libs.xtests:        $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_XTESTS)

compile.libs:                                                           compile.libs.core compile.libs.loki.safefmt compile.libs.shwild compile.libs.xtests

compile.bitbucket:          $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_BITBUCKET)

compile.examples:           $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_EXAMPLE)

compile.samples:            $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_SAMPLE)

compile.test.component:     $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_TEST_COMPONENT)

compile.test.performance:   $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_TEST_PERFORMANCE)

compile.test.scratch:       $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_TEST_SCRATCH)

compile.test.unit:          $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_TEST_UNIT)

compile.test:                                                           compile.test.unit compile.test.component

compile.test.all:                                                       compile.test compile.test.scratch compile.test.performance

compile:                                                                compile.libs compile.test compile.examples compile.samples

compile.all:                                                            compile compile.test.all



# build targets

build.libs.core:            check.lib.dir           prep.files.for.os   $(TARGETS_LIB_CORE)

build.libs.loki.safefmt:    check.lib.dir           prep.files.for.os   $(TARGETS_LIB_LOKI_SFMT)

build.libs.shwild:          check.lib.dir           prep.files.for.os   $(TARGETS_LIB_SHWILD)

build.libs.xtests:          check.lib.dir           prep.files.for.os   $(TARGETS_LIB_XTESTS)

build.libs:                                                             build.libs.core build.libs.loki.safefmt build.libs.shwild build.libs.xtests

build.bitbucket:            check.bin.dir           prep.files.for.os   $(TARGETS_BITBUCKET)

build.examples:             check.bin.dir           prep.files.for.os   $(TARGETS_EXAMPLE)

build.examples.overload.3:  check.bin.dir           prep.files.for.os   $(TARGETS_EXAMPLE_OVERLOAD_3)

build.samples:              check.bin.dir           prep.files.for.os   $(TARGETS_SAMPLE)

build.test.component:       check.bin.dir           prep.files.for.os   $(TARGETS_TEST_COMPONENT)

build.test.performance:     check.bin.dir           prep.files.for.os   $(TARGETS_TEST_PERFORMANCE)

build.test.scratch:         check.bin.dir           prep.files.for.os   $(TARGETS_TEST_SCRATCH)

build.test.unit:            check.bin.dir           prep.files.for.os   $(TARGETS_TEST_UNIT)

build.test:                                                             build.test.unit build.test.component build.test.performance

build.test.all:                                                         build.test build.test.scratch

build:                                                                  build.libs build.examples build.samples build.test

build.all:                                                              build build.test.all



# test targets

test.component_:
	@echo Running Test:Component programs ...
	$(TARG_TEST_COMP_file_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_file_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_file_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_file_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_fmt_sink_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_fmt_sink_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_fmt_sink_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_fmt_sink_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_hex_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_hex_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_hex_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_hex_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_int_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_int_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_int_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_int_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_real_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_real_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_real_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_real_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_itr_fmt_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_itr_fmt_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_itr_fmt_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_itr_fmt_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_null_sink_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_null_sink_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_null_sink_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_null_sink_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_a_b_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_a_b_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_a_b_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_a_b_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_write_sink_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_write_sink_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_write_sink_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_write_sink_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_x_1_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_x_1_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_x_1_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_x_1_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_ostm_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_ostm_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_ostm_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_ostm_ST_R) --verbosity=$(TEST_VERBOSITY)

test.performance_:
	@echo Running Test:Performance programs ...
	$(TARG_TEST_PERF_scen1_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen2_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen3_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen4_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen5_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen6_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen7_MT_R) --verbosity=$(TEST_VERBOSITY)
ifdef BOOST
	$(TARG_TEST_PERF_scen8_MT_R) --verbosity=$(TEST_VERBOSITY)
endif # BOOST
	$(TARG_TEST_PERF_scen1_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen2_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen3_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen4_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen5_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen6_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen7_ST_R) --verbosity=$(TEST_VERBOSITY)
ifdef BOOST
	$(TARG_TEST_PERF_scen8_ST_R) --verbosity=$(TEST_VERBOSITY)
endif # BOOST

test.scratch_:
	@echo Running Test:Scratch programs ...
	$(TARG_TEST_SCRT_file_MT_D)
	$(TARG_TEST_SCRT_speech_MT_D)
	$(TARG_TEST_SCRT_file_MT_R)
	$(TARG_TEST_SCRT_speech_MT_R)
	$(TARG_TEST_SCRT_file_ST_D)
	$(TARG_TEST_SCRT_speech_ST_D)
	$(TARG_TEST_SCRT_file_ST_R)
	$(TARG_TEST_SCRT_speech_ST_R)

test.unit_:
	@echo Running Test:Unit programs ...
	$(TARG_TEST_UNIT_api_acsllen_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_acsllen_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_acsllen_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_acsllen_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_crlf_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_crlf_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_crlf_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_crlf_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_flrpl_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_flrpl_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_flrpl_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_flrpl_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_illfmdh_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_illfmdh_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_illfmdh_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_illfmdh_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_init_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_init_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_init_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_init_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_lkptrn_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_lkptrn_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_lkptrn_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_lkptrn_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_msmtchh_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_msmtchh_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_msmtchh_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_msmtchh_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_prsrpl_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_prsrpl_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_prsrpl_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_prsrpl_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_bndl_winini_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_bndl_winini_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_bndl_winini_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_bndl_winini_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_fmt_stdfl_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_fmt_stdfl_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_fmt_stdfl_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_fmt_stdfl_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_ch_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_ch_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_ch_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_ch_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_i_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_i_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_i_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_i_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_fi_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_fi_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_fi_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_fi_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_a_b_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_a_b_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_a_b_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_a_b_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_c_str_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_c_str_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_c_str_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_c_str_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_chbuf_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_chbuf_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_chbuf_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_chbuf_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_null_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_null_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_null_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_null_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ods_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ods_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ods_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ods_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ostm_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ostm_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ostm_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ostm_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_sstm_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_sstm_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_sstm_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_sstm_ST_R) --verbosity=$(TEST_VERBOSITY)

#	$(TARG_TEST_UNIT_snk_vecfile [ ` [ MakeSymbolTag ] ` ] ) --verbosity=$(TEST_VERBOSITY)

test.examples_:
	@echo Running Example programs ...
	$(TARG_EX_boolean_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_character_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_reals_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_voidptrs_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ff_101_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ff_101_nons_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_flush_MT_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_D)
	$(TARG_EX_ins_hex_MT_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_D)
	$(TARG_EX_ins_integers_MT_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_D)
	$(TARG_EX_ins_reals_MT_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_D)
	$(TARG_EX_ins_WLIs_MT_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_D)
	$(TARG_EX_itr_fmt_MT_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_D)
	$(TARG_EX_ovld2_filt_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ovld2_ins_MT_D) $(PROJ_BUNDLES_DIR)\superhero.properties --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ovld2_sas_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ovld3_fpcol_MT_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_D)
	$(TARG_EX_ovld3_tabs_MT_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_D)
	$(TARG_EX_ovld3_svrlg_MT_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_D)
	$(TARG_EX_ovld3_rcins_MT_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_D)
	$(TARG_EX_pad_hash_MT_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_D)
	$(TARG_EX_sink_cstr_MT_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_D)
	$(TARG_EX_sink_ODS_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_boolean_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_character_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_reals_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_voidptrs_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ff_101_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ff_101_nons_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_flush_MT_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_R)
	$(TARG_EX_ins_hex_MT_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_R)
	$(TARG_EX_ins_integers_MT_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_R)
	$(TARG_EX_ins_reals_MT_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_R)
	$(TARG_EX_ins_WLIs_MT_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_R)
	$(TARG_EX_itr_fmt_MT_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_R)
	$(TARG_EX_ovld2_filt_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ovld2_ins_MT_R) $(PROJ_BUNDLES_DIR)\superhero.properties --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ovld2_sas_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ovld3_fpcol_MT_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_R)
	$(TARG_EX_ovld3_tabs_MT_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_R)
	$(TARG_EX_ovld3_svrlg_MT_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_R)
	$(TARG_EX_ovld3_rcins_MT_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_R)
	$(TARG_EX_pad_hash_MT_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_R)
	$(TARG_EX_sink_cstr_MT_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_R)
	$(TARG_EX_sink_ODS_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_boolean_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_character_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_reals_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_voidptrs_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ff_101_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ff_101_nons_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_flush_ST_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_D)
	$(TARG_EX_ins_hex_ST_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_D)
	$(TARG_EX_ins_integers_ST_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_D)
	$(TARG_EX_ins_reals_ST_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_D)
	$(TARG_EX_ins_WLIs_ST_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_D)
	$(TARG_EX_itr_fmt_ST_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_D)
	$(TARG_EX_ovld2_filt_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ovld2_ins_ST_D) $(PROJ_BUNDLES_DIR)\superhero.properties --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ovld2_sas_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ovld3_fpcol_ST_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_D)
	$(TARG_EX_ovld3_tabs_ST_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_D)
	$(TARG_EX_ovld3_svrlg_ST_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_D)
	$(TARG_EX_ovld3_rcins_ST_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_D)
	$(TARG_EX_pad_hash_ST_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_D)
	$(TARG_EX_sink_cstr_ST_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_D)
	$(TARG_EX_sink_ODS_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_boolean_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_character_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_reals_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_voidptrs_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ff_101_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ff_101_nons_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_flush_ST_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_R)
	$(TARG_EX_ins_hex_ST_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_R)
	$(TARG_EX_ins_integers_ST_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_R)
	$(TARG_EX_ins_reals_ST_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_R)
	$(TARG_EX_ins_WLIs_ST_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_R)
	$(TARG_EX_itr_fmt_ST_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_R)
	$(TARG_EX_ovld2_filt_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ovld2_ins_ST_R) $(PROJ_BUNDLES_DIR)\superhero.properties --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ovld2_sas_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ovld3_fpcol_ST_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_R)
	$(TARG_EX_ovld3_tabs_ST_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_R)
	$(TARG_EX_ovld3_svrlg_ST_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_R)
	$(TARG_EX_ovld3_rcins_ST_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_R)
	$(TARG_EX_pad_hash_ST_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_R)
	$(TARG_EX_sink_cstr_ST_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_R)
	$(TARG_EX_sink_ODS_ST_R) --verbosity=$(TEST_VERBOSITY)

test.examples.overload.3_:
	@echo Running Overload 3 Example programs ...
	$(TARG_EX_ovld3_fpcol_MT_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_R)
	$(TARG_EX_ovld3_tabs_MT_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_R)
	$(TARG_EX_ovld3_svrlg_MT_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_R)
	$(TARG_EX_ovld3_rcins_MT_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_R)
	$(TARG_EX_ovld3_fpcol_ST_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_R)
	$(TARG_EX_ovld3_tabs_ST_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_R)
	$(TARG_EX_ovld3_svrlg_ST_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_R)
	$(TARG_EX_ovld3_rcins_ST_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_ST_R)

test.component:             build.test.component test.component_

test.performance:			build.test.performance test.performance_

test.scratch:               build.test.scratch test.scratch_

test.unit:                  build.test.unit test.unit_

test.examples:				build.examples test.examples_

test.examples.overload.3:	build.examples.overload.3 test.examples.overload.3_

test:                       test.unit test.component

test.all:					build.all test test.performance test.scratch test.examples
test-all:                   test.all



# clean targets

clean.libs.core:
	@echo cleaning Core libraries ...
	@-if exist core.*.obj $(RM) core.*.obj
	@-if exist $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG)*.lib $(RM) $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG)*.lib

clean.libs.loki.safefmt:
	@echo cleaning Loki.SafeFormat libraries ...
	@-if exist loki.safefmt.*.obj $(RM) loki.safefmt.*.obj
	@-if exist $(PROJ_LIB_DIR)\$(LOKI_SFMT_TAG_VER).ff.$(COMP_ARCH_OS_TAG)*.lib $(RM) $(PROJ_LIB_DIR)\$(LOKI_SFMT_TAG_VER).ff.$(COMP_ARCH_OS_TAG)*.lib

clean.libs.shwild:
	@echo cleaning shwild libraries ...
	@-if exist shwild.*.obj $(RM) shwild.*.obj
	@-if exist $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).ff.$(COMP_ARCH_OS_TAG)*.lib $(RM) $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).ff.$(COMP_ARCH_OS_TAG)*.lib

clean.libs.xtests:
	@echo cleaning xTests libraries ...
	@-if exist xtests.*.obj $(RM) xtests.*.obj
	@-if exist $(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).ff.$(COMP_ARCH_OS_TAG)*.lib $(RM) $(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).ff.$(COMP_ARCH_OS_TAG)*.lib

clean.libs:                                         clean.libs.core clean.libs.loki.safefmt clean.libs.shwild clean.libs.xtests

clean.bitbucket:
	@echo cleaning Bitbucket programs ...
	@-if exist $(TARG_BITBUCKET_MT_D) $(RM) $(TARG_BITBUCKET_MT_D)
	@-if exist $(OBJ_BITBUCKET_MT_D) $(RM) $(OBJ_BITBUCKET_MT_D)
	@-if exist $(TARG_BITBUCKET_MT_R) $(RM) $(TARG_BITBUCKET_MT_R)
	@-if exist $(OBJ_BITBUCKET_MT_R) $(RM) $(OBJ_BITBUCKET_MT_R)
	@-if exist $(TARG_BITBUCKET_ST_D) $(RM) $(TARG_BITBUCKET_ST_D)
	@-if exist $(OBJ_BITBUCKET_ST_D) $(RM) $(OBJ_BITBUCKET_ST_D)
	@-if exist $(TARG_BITBUCKET_ST_R) $(RM) $(TARG_BITBUCKET_ST_R)
	@-if exist $(OBJ_BITBUCKET_ST_R) $(RM) $(OBJ_BITBUCKET_ST_R)

clean.examples:
	@echo cleaning Example programs ...
	@-if exist $(TARG_EX_boolean_MT_D) $(RM) $(TARG_EX_boolean_MT_D)
	@-if exist $(OBJ_EX_boolean_MT_D) $(RM) $(OBJ_EX_boolean_MT_D)
	@-if exist $(TARG_EX_character_MT_D) $(RM) $(TARG_EX_character_MT_D)
	@-if exist $(OBJ_EX_character_MT_D) $(RM) $(OBJ_EX_character_MT_D)
	@-if exist $(TARG_EX_reals_MT_D) $(RM) $(TARG_EX_reals_MT_D)
	@-if exist $(OBJ_EX_reals_MT_D) $(RM) $(OBJ_EX_reals_MT_D)
	@-if exist $(TARG_EX_voidptrs_MT_D) $(RM) $(TARG_EX_voidptrs_MT_D)
	@-if exist $(OBJ_EX_voidptrs_MT_D) $(RM) $(OBJ_EX_voidptrs_MT_D)
	@-if exist $(TARG_EX_ff_101_MT_D) $(RM) $(TARG_EX_ff_101_MT_D)
	@-if exist $(OBJ_EX_ff_101_MT_D) $(RM) $(OBJ_EX_ff_101_MT_D)
	@-if exist $(TARG_EX_ff_101_nons_MT_D) $(RM) $(TARG_EX_ff_101_nons_MT_D)
	@-if exist $(OBJ_EX_ff_101_nons_MT_D) $(RM) $(OBJ_EX_ff_101_nons_MT_D)
	@-if exist $(TARG_EX_flush_MT_D) $(RM) $(TARG_EX_flush_MT_D)
	@-if exist $(OBJ_EX_flush_MT_D) $(RM) $(OBJ_EX_flush_MT_D)
	@-if exist $(TARG_EX_ins_hex_MT_D) $(RM) $(TARG_EX_ins_hex_MT_D)
	@-if exist $(OBJ_EX_ins_hex_MT_D) $(RM) $(OBJ_EX_ins_hex_MT_D)
	@-if exist $(TARG_EX_ins_integers_MT_D) $(RM) $(TARG_EX_ins_integers_MT_D)
	@-if exist $(OBJ_EX_ins_integers_MT_D) $(RM) $(OBJ_EX_ins_integers_MT_D)
	@-if exist $(TARG_EX_ins_WLIs_MT_D) $(RM) $(TARG_EX_ins_WLIs_MT_D)
	@-if exist $(OBJ_EX_ins_WLIs_MT_D) $(RM) $(OBJ_EX_ins_WLIs_MT_D)
	@-if exist $(TARG_EX_ins_reals_MT_D) $(RM) $(TARG_EX_ins_reals_MT_D)
	@-if exist $(OBJ_EX_ins_reals_MT_D) $(RM) $(OBJ_EX_ins_reals_MT_D)
	@-if exist $(TARG_EX_itr_fmt_MT_D) $(RM) $(TARG_EX_itr_fmt_MT_D)
	@-if exist $(OBJ_EX_itr_fmt_MT_D) $(RM) $(OBJ_EX_itr_fmt_MT_D)
	@-if exist $(TARG_EX_ovld2_filt_MT_D) $(RM) $(TARG_EX_ovld2_filt_MT_D)
	@-if exist $(OBJ_EX_ovld2_filt_MT_D) $(RM) $(OBJ_EX_ovld2_filt_MT_D)
	@-if exist $(TARG_EX_ovld2_ins_MT_D) $(RM) $(TARG_EX_ovld2_ins_MT_D)
	@-if exist $(OBJ_EX_ovld2_ins_MT_D) $(RM) $(OBJ_EX_ovld2_ins_MT_D)
	@-if exist $(TARG_EX_ovld2_sas_MT_D) $(RM) $(TARG_EX_ovld2_sas_MT_D)
	@-if exist $(OBJ_EX_ovld2_sas_MT_D) $(RM) $(OBJ_EX_ovld2_sas_MT_D)
	@-if exist $(TARG_EX_ovld3_fpcol_MT_D) $(RM) $(TARG_EX_ovld3_fpcol_MT_D)
	@-if exist $(OBJ_EX_ovld3_fpcol_MT_D) $(RM) $(OBJ_EX_ovld3_fpcol_MT_D)
	@-if exist $(TARG_EX_ovld3_tabs_MT_D) $(RM) $(TARG_EX_ovld3_tabs_MT_D)
	@-if exist $(OBJ_EX_ovld3_tabs_MT_D) $(RM) $(OBJ_EX_ovld3_tabs_MT_D)
	@-if exist $(TARG_EX_ovld3_svrlg_MT_D) $(RM) $(TARG_EX_ovld3_svrlg_MT_D)
	@-if exist $(OBJ_EX_ovld3_svrlg_MT_D) $(RM) $(OBJ_EX_ovld3_svrlg_MT_D)
	@-if exist $(TARG_EX_ovld3_rcins_MT_D) $(RM) $(TARG_EX_ovld3_rcins_MT_D)
	@-if exist $(OBJ_EX_ovld3_rcins_MT_D) $(RM) $(OBJ_EX_ovld3_rcins_MT_D)
	@-if exist $(TARG_EX_pad_hash_MT_D) $(RM) $(TARG_EX_pad_hash_MT_D)
	@-if exist $(OBJ_EX_pad_hash_MT_D) $(RM) $(OBJ_EX_pad_hash_MT_D)
	@-if exist $(TARG_EX_sink_cstr_MT_D) $(RM) $(TARG_EX_sink_cstr_MT_D)
	@-if exist $(OBJ_EX_sink_cstr_MT_D) $(RM) $(OBJ_EX_sink_cstr_MT_D)
	@-if exist $(TARG_EX_sink_ODS_MT_D) $(RM) $(TARG_EX_sink_ODS_MT_D)
	@-if exist $(OBJ_EX_sink_ODS_MT_D) $(RM) $(OBJ_EX_sink_ODS_MT_D)
	@-if exist $(TARG_EX_boolean_MT_R) $(RM) $(TARG_EX_boolean_MT_R)
	@-if exist $(OBJ_EX_boolean_MT_R) $(RM) $(OBJ_EX_boolean_MT_R)
	@-if exist $(TARG_EX_character_MT_R) $(RM) $(TARG_EX_character_MT_R)
	@-if exist $(OBJ_EX_character_MT_R) $(RM) $(OBJ_EX_character_MT_R)
	@-if exist $(TARG_EX_reals_MT_R) $(RM) $(TARG_EX_reals_MT_R)
	@-if exist $(OBJ_EX_reals_MT_R) $(RM) $(OBJ_EX_reals_MT_R)
	@-if exist $(TARG_EX_voidptrs_MT_R) $(RM) $(TARG_EX_voidptrs_MT_R)
	@-if exist $(OBJ_EX_voidptrs_MT_R) $(RM) $(OBJ_EX_voidptrs_MT_R)
	@-if exist $(TARG_EX_ff_101_MT_R) $(RM) $(TARG_EX_ff_101_MT_R)
	@-if exist $(OBJ_EX_ff_101_MT_R) $(RM) $(OBJ_EX_ff_101_MT_R)
	@-if exist $(TARG_EX_ff_101_nons_MT_R) $(RM) $(TARG_EX_ff_101_nons_MT_R)
	@-if exist $(OBJ_EX_ff_101_nons_MT_R) $(RM) $(OBJ_EX_ff_101_nons_MT_R)
	@-if exist $(TARG_EX_flush_MT_R) $(RM) $(TARG_EX_flush_MT_R)
	@-if exist $(OBJ_EX_flush_MT_R) $(RM) $(OBJ_EX_flush_MT_R)
	@-if exist $(TARG_EX_ins_hex_MT_R) $(RM) $(TARG_EX_ins_hex_MT_R)
	@-if exist $(OBJ_EX_ins_hex_MT_R) $(RM) $(OBJ_EX_ins_hex_MT_R)
	@-if exist $(TARG_EX_ins_integers_MT_R) $(RM) $(TARG_EX_ins_integers_MT_R)
	@-if exist $(OBJ_EX_ins_integers_MT_R) $(RM) $(OBJ_EX_ins_integers_MT_R)
	@-if exist $(TARG_EX_ins_WLIs_MT_R) $(RM) $(TARG_EX_ins_WLIs_MT_R)
	@-if exist $(OBJ_EX_ins_WLIs_MT_R) $(RM) $(OBJ_EX_ins_WLIs_MT_R)
	@-if exist $(TARG_EX_ins_reals_MT_R) $(RM) $(TARG_EX_ins_reals_MT_R)
	@-if exist $(OBJ_EX_ins_reals_MT_R) $(RM) $(OBJ_EX_ins_reals_MT_R)
	@-if exist $(TARG_EX_itr_fmt_MT_R) $(RM) $(TARG_EX_itr_fmt_MT_R)
	@-if exist $(OBJ_EX_itr_fmt_MT_R) $(RM) $(OBJ_EX_itr_fmt_MT_R)
	@-if exist $(TARG_EX_ovld2_filt_MT_R) $(RM) $(TARG_EX_ovld2_filt_MT_R)
	@-if exist $(OBJ_EX_ovld2_filt_MT_R) $(RM) $(OBJ_EX_ovld2_filt_MT_R)
	@-if exist $(TARG_EX_ovld2_ins_MT_R) $(RM) $(TARG_EX_ovld2_ins_MT_R)
	@-if exist $(OBJ_EX_ovld2_ins_MT_R) $(RM) $(OBJ_EX_ovld2_ins_MT_R)
	@-if exist $(TARG_EX_ovld2_sas_MT_R) $(RM) $(TARG_EX_ovld2_sas_MT_R)
	@-if exist $(OBJ_EX_ovld2_sas_MT_R) $(RM) $(OBJ_EX_ovld2_sas_MT_R)
	@-if exist $(TARG_EX_ovld3_fpcol_MT_R) $(RM) $(TARG_EX_ovld3_fpcol_MT_R)
	@-if exist $(OBJ_EX_ovld3_fpcol_MT_R) $(RM) $(OBJ_EX_ovld3_fpcol_MT_R)
	@-if exist $(TARG_EX_ovld3_tabs_MT_R) $(RM) $(TARG_EX_ovld3_tabs_MT_R)
	@-if exist $(OBJ_EX_ovld3_tabs_MT_R) $(RM) $(OBJ_EX_ovld3_tabs_MT_R)
	@-if exist $(TARG_EX_ovld3_svrlg_MT_R) $(RM) $(TARG_EX_ovld3_svrlg_MT_R)
	@-if exist $(OBJ_EX_ovld3_svrlg_MT_R) $(RM) $(OBJ_EX_ovld3_svrlg_MT_R)
	@-if exist $(TARG_EX_ovld3_rcins_MT_R) $(RM) $(TARG_EX_ovld3_rcins_MT_R)
	@-if exist $(OBJ_EX_ovld3_rcins_MT_R) $(RM) $(OBJ_EX_ovld3_rcins_MT_R)
	@-if exist $(TARG_EX_pad_hash_MT_R) $(RM) $(TARG_EX_pad_hash_MT_R)
	@-if exist $(OBJ_EX_pad_hash_MT_R) $(RM) $(OBJ_EX_pad_hash_MT_R)
	@-if exist $(TARG_EX_sink_cstr_MT_R) $(RM) $(TARG_EX_sink_cstr_MT_R)
	@-if exist $(OBJ_EX_sink_cstr_MT_R) $(RM) $(OBJ_EX_sink_cstr_MT_R)
	@-if exist $(TARG_EX_sink_ODS_MT_R) $(RM) $(TARG_EX_sink_ODS_MT_R)
	@-if exist $(OBJ_EX_sink_ODS_MT_R) $(RM) $(OBJ_EX_sink_ODS_MT_R)
	@-if exist $(TARG_EX_boolean_ST_D) $(RM) $(TARG_EX_boolean_ST_D)
	@-if exist $(OBJ_EX_boolean_ST_D) $(RM) $(OBJ_EX_boolean_ST_D)
	@-if exist $(TARG_EX_character_ST_D) $(RM) $(TARG_EX_character_ST_D)
	@-if exist $(OBJ_EX_character_ST_D) $(RM) $(OBJ_EX_character_ST_D)
	@-if exist $(TARG_EX_reals_ST_D) $(RM) $(TARG_EX_reals_ST_D)
	@-if exist $(OBJ_EX_reals_ST_D) $(RM) $(OBJ_EX_reals_ST_D)
	@-if exist $(TARG_EX_voidptrs_ST_D) $(RM) $(TARG_EX_voidptrs_ST_D)
	@-if exist $(OBJ_EX_voidptrs_ST_D) $(RM) $(OBJ_EX_voidptrs_ST_D)
	@-if exist $(TARG_EX_ff_101_ST_D) $(RM) $(TARG_EX_ff_101_ST_D)
	@-if exist $(OBJ_EX_ff_101_ST_D) $(RM) $(OBJ_EX_ff_101_ST_D)
	@-if exist $(TARG_EX_ff_101_nons_ST_D) $(RM) $(TARG_EX_ff_101_nons_ST_D)
	@-if exist $(OBJ_EX_ff_101_nons_ST_D) $(RM) $(OBJ_EX_ff_101_nons_ST_D)
	@-if exist $(TARG_EX_flush_ST_D) $(RM) $(TARG_EX_flush_ST_D)
	@-if exist $(OBJ_EX_flush_ST_D) $(RM) $(OBJ_EX_flush_ST_D)
	@-if exist $(TARG_EX_ins_hex_ST_D) $(RM) $(TARG_EX_ins_hex_ST_D)
	@-if exist $(OBJ_EX_ins_hex_ST_D) $(RM) $(OBJ_EX_ins_hex_ST_D)
	@-if exist $(TARG_EX_ins_integers_ST_D) $(RM) $(TARG_EX_ins_integers_ST_D)
	@-if exist $(OBJ_EX_ins_integers_ST_D) $(RM) $(OBJ_EX_ins_integers_ST_D)
	@-if exist $(TARG_EX_ins_WLIs_ST_D) $(RM) $(TARG_EX_ins_WLIs_ST_D)
	@-if exist $(OBJ_EX_ins_WLIs_ST_D) $(RM) $(OBJ_EX_ins_WLIs_ST_D)
	@-if exist $(TARG_EX_ins_reals_ST_D) $(RM) $(TARG_EX_ins_reals_ST_D)
	@-if exist $(OBJ_EX_ins_reals_ST_D) $(RM) $(OBJ_EX_ins_reals_ST_D)
	@-if exist $(TARG_EX_itr_fmt_ST_D) $(RM) $(TARG_EX_itr_fmt_ST_D)
	@-if exist $(OBJ_EX_itr_fmt_ST_D) $(RM) $(OBJ_EX_itr_fmt_ST_D)
	@-if exist $(TARG_EX_ovld2_filt_ST_D) $(RM) $(TARG_EX_ovld2_filt_ST_D)
	@-if exist $(OBJ_EX_ovld2_filt_ST_D) $(RM) $(OBJ_EX_ovld2_filt_ST_D)
	@-if exist $(TARG_EX_ovld2_ins_ST_D) $(RM) $(TARG_EX_ovld2_ins_ST_D)
	@-if exist $(OBJ_EX_ovld2_ins_ST_D) $(RM) $(OBJ_EX_ovld2_ins_ST_D)
	@-if exist $(TARG_EX_ovld2_sas_ST_D) $(RM) $(TARG_EX_ovld2_sas_ST_D)
	@-if exist $(OBJ_EX_ovld2_sas_ST_D) $(RM) $(OBJ_EX_ovld2_sas_ST_D)
	@-if exist $(TARG_EX_ovld3_fpcol_ST_D) $(RM) $(TARG_EX_ovld3_fpcol_ST_D)
	@-if exist $(OBJ_EX_ovld3_fpcol_ST_D) $(RM) $(OBJ_EX_ovld3_fpcol_ST_D)
	@-if exist $(TARG_EX_ovld3_tabs_ST_D) $(RM) $(TARG_EX_ovld3_tabs_ST_D)
	@-if exist $(OBJ_EX_ovld3_tabs_ST_D) $(RM) $(OBJ_EX_ovld3_tabs_ST_D)
	@-if exist $(TARG_EX_ovld3_svrlg_ST_D) $(RM) $(TARG_EX_ovld3_svrlg_ST_D)
	@-if exist $(OBJ_EX_ovld3_svrlg_ST_D) $(RM) $(OBJ_EX_ovld3_svrlg_ST_D)
	@-if exist $(TARG_EX_ovld3_rcins_ST_D) $(RM) $(TARG_EX_ovld3_rcins_ST_D)
	@-if exist $(OBJ_EX_ovld3_rcins_ST_D) $(RM) $(OBJ_EX_ovld3_rcins_ST_D)
	@-if exist $(TARG_EX_pad_hash_ST_D) $(RM) $(TARG_EX_pad_hash_ST_D)
	@-if exist $(OBJ_EX_pad_hash_ST_D) $(RM) $(OBJ_EX_pad_hash_ST_D)
	@-if exist $(TARG_EX_sink_cstr_ST_D) $(RM) $(TARG_EX_sink_cstr_ST_D)
	@-if exist $(OBJ_EX_sink_cstr_ST_D) $(RM) $(OBJ_EX_sink_cstr_ST_D)
	@-if exist $(TARG_EX_sink_ODS_ST_D) $(RM) $(TARG_EX_sink_ODS_ST_D)
	@-if exist $(OBJ_EX_sink_ODS_ST_D) $(RM) $(OBJ_EX_sink_ODS_ST_D)
	@-if exist $(TARG_EX_boolean_ST_R) $(RM) $(TARG_EX_boolean_ST_R)
	@-if exist $(OBJ_EX_boolean_ST_R) $(RM) $(OBJ_EX_boolean_ST_R)
	@-if exist $(TARG_EX_character_ST_R) $(RM) $(TARG_EX_character_ST_R)
	@-if exist $(OBJ_EX_character_ST_R) $(RM) $(OBJ_EX_character_ST_R)
	@-if exist $(TARG_EX_reals_ST_R) $(RM) $(TARG_EX_reals_ST_R)
	@-if exist $(OBJ_EX_reals_ST_R) $(RM) $(OBJ_EX_reals_ST_R)
	@-if exist $(TARG_EX_voidptrs_ST_R) $(RM) $(TARG_EX_voidptrs_ST_R)
	@-if exist $(OBJ_EX_voidptrs_ST_R) $(RM) $(OBJ_EX_voidptrs_ST_R)
	@-if exist $(TARG_EX_ff_101_ST_R) $(RM) $(TARG_EX_ff_101_ST_R)
	@-if exist $(OBJ_EX_ff_101_ST_R) $(RM) $(OBJ_EX_ff_101_ST_R)
	@-if exist $(TARG_EX_ff_101_nons_ST_R) $(RM) $(TARG_EX_ff_101_nons_ST_R)
	@-if exist $(OBJ_EX_ff_101_nons_ST_R) $(RM) $(OBJ_EX_ff_101_nons_ST_R)
	@-if exist $(TARG_EX_flush_ST_R) $(RM) $(TARG_EX_flush_ST_R)
	@-if exist $(OBJ_EX_flush_ST_R) $(RM) $(OBJ_EX_flush_ST_R)
	@-if exist $(TARG_EX_ins_hex_ST_R) $(RM) $(TARG_EX_ins_hex_ST_R)
	@-if exist $(OBJ_EX_ins_hex_ST_R) $(RM) $(OBJ_EX_ins_hex_ST_R)
	@-if exist $(TARG_EX_ins_integers_ST_R) $(RM) $(TARG_EX_ins_integers_ST_R)
	@-if exist $(OBJ_EX_ins_integers_ST_R) $(RM) $(OBJ_EX_ins_integers_ST_R)
	@-if exist $(TARG_EX_ins_WLIs_ST_R) $(RM) $(TARG_EX_ins_WLIs_ST_R)
	@-if exist $(OBJ_EX_ins_WLIs_ST_R) $(RM) $(OBJ_EX_ins_WLIs_ST_R)
	@-if exist $(TARG_EX_ins_reals_ST_R) $(RM) $(TARG_EX_ins_reals_ST_R)
	@-if exist $(OBJ_EX_ins_reals_ST_R) $(RM) $(OBJ_EX_ins_reals_ST_R)
	@-if exist $(TARG_EX_itr_fmt_ST_R) $(RM) $(TARG_EX_itr_fmt_ST_R)
	@-if exist $(OBJ_EX_itr_fmt_ST_R) $(RM) $(OBJ_EX_itr_fmt_ST_R)
	@-if exist $(TARG_EX_ovld2_filt_ST_R) $(RM) $(TARG_EX_ovld2_filt_ST_R)
	@-if exist $(OBJ_EX_ovld2_filt_ST_R) $(RM) $(OBJ_EX_ovld2_filt_ST_R)
	@-if exist $(TARG_EX_ovld2_ins_ST_R) $(RM) $(TARG_EX_ovld2_ins_ST_R)
	@-if exist $(OBJ_EX_ovld2_ins_ST_R) $(RM) $(OBJ_EX_ovld2_ins_ST_R)
	@-if exist $(TARG_EX_ovld2_sas_ST_R) $(RM) $(TARG_EX_ovld2_sas_ST_R)
	@-if exist $(OBJ_EX_ovld2_sas_ST_R) $(RM) $(OBJ_EX_ovld2_sas_ST_R)
	@-if exist $(TARG_EX_ovld3_fpcol_ST_R) $(RM) $(TARG_EX_ovld3_fpcol_ST_R)
	@-if exist $(OBJ_EX_ovld3_fpcol_ST_R) $(RM) $(OBJ_EX_ovld3_fpcol_ST_R)
	@-if exist $(TARG_EX_ovld3_tabs_ST_R) $(RM) $(TARG_EX_ovld3_tabs_ST_R)
	@-if exist $(OBJ_EX_ovld3_tabs_ST_R) $(RM) $(OBJ_EX_ovld3_tabs_ST_R)
	@-if exist $(TARG_EX_ovld3_svrlg_ST_R) $(RM) $(TARG_EX_ovld3_svrlg_ST_R)
	@-if exist $(OBJ_EX_ovld3_svrlg_ST_R) $(RM) $(OBJ_EX_ovld3_svrlg_ST_R)
	@-if exist $(TARG_EX_ovld3_rcins_ST_R) $(RM) $(TARG_EX_ovld3_rcins_ST_R)
	@-if exist $(OBJ_EX_ovld3_rcins_ST_R) $(RM) $(OBJ_EX_ovld3_rcins_ST_R)
	@-if exist $(TARG_EX_pad_hash_ST_R) $(RM) $(TARG_EX_pad_hash_ST_R)
	@-if exist $(OBJ_EX_pad_hash_ST_R) $(RM) $(OBJ_EX_pad_hash_ST_R)
	@-if exist $(TARG_EX_sink_cstr_ST_R) $(RM) $(TARG_EX_sink_cstr_ST_R)
	@-if exist $(OBJ_EX_sink_cstr_ST_R) $(RM) $(OBJ_EX_sink_cstr_ST_R)
	@-if exist $(TARG_EX_sink_ODS_ST_R) $(RM) $(TARG_EX_sink_ODS_ST_R)
	@-if exist $(OBJ_EX_sink_ODS_ST_R) $(RM) $(OBJ_EX_sink_ODS_ST_R)

clean.samples:
	@echo cleaning Sample programs ...

clean.test.component:
	@echo cleaning Test::Component files ...
	@-if exist $(TARG_TEST_COMP_file_MT_D) $(RM) $(TARG_TEST_COMP_file_MT_D)
	@-if exist $(OBJ_TEST_COMP_file_MT_D) $(RM) $(OBJ_TEST_COMP_file_MT_D)
	@-if exist $(TARG_TEST_COMP_fmt_sink_MT_D) $(RM) $(TARG_TEST_COMP_fmt_sink_MT_D)
	@-if exist $(OBJ_TEST_COMP_fmt_sink_MT_D) $(RM) $(OBJ_TEST_COMP_fmt_sink_MT_D)
	@-if exist $(TARG_TEST_COMP_ins_hex_MT_D) $(RM) $(TARG_TEST_COMP_ins_hex_MT_D)
	@-if exist $(OBJ_TEST_COMP_ins_hex_MT_D) $(RM) $(OBJ_TEST_COMP_ins_hex_MT_D)
	@-if exist $(TARG_TEST_COMP_ins_int_MT_D) $(RM) $(TARG_TEST_COMP_ins_int_MT_D)
	@-if exist $(OBJ_TEST_COMP_ins_int_MT_D) $(RM) $(OBJ_TEST_COMP_ins_int_MT_D)
	@-if exist $(TARG_TEST_COMP_ins_real_MT_D) $(RM) $(TARG_TEST_COMP_ins_real_MT_D)
	@-if exist $(OBJ_TEST_COMP_ins_real_MT_D) $(RM) $(OBJ_TEST_COMP_ins_real_MT_D)
	@-if exist $(TARG_TEST_COMP_itr_fmt_MT_D) $(RM) $(TARG_TEST_COMP_ins_real_MT_D)
	@-if exist $(OBJ_TEST_COMP_itr_fmt_MT_D) $(RM) $(OBJ_TEST_COMP_ins_real_MT_D)
	@-if exist $(TARG_TEST_COMP_null_sink_MT_D) $(RM) $(TARG_TEST_COMP_null_sink_MT_D)
	@-if exist $(OBJ_TEST_COMP_null_sink_MT_D) $(RM) $(OBJ_TEST_COMP_null_sink_MT_D)
	@-if exist $(TARG_TEST_COMP_snk_a_b_MT_D) $(RM) $(TARG_TEST_COMP_snk_a_b_MT_D)
	@-if exist $(OBJ_TEST_COMP_snk_a_b_MT_D) $(RM) $(OBJ_TEST_COMP_snk_a_b_MT_D)
	@-if exist $(TARG_TEST_COMP_write_sink_MT_D) $(RM) $(TARG_TEST_COMP_write_sink_MT_D)
	@-if exist $(OBJ_TEST_COMP_write_sink_MT_D) $(RM) $(OBJ_TEST_COMP_write_sink_MT_D)
	@-if exist $(TARG_TEST_COMP_x_1_MT_D) $(RM) $(TARG_TEST_COMP_x_1_MT_D)
	@-if exist $(OBJ_TEST_COMP_x_1_MT_D) $(RM) $(OBJ_TEST_COMP_x_1_MT_D)
	@-if exist $(TARG_TEST_COMP_snk_ostm_MT_D) $(RM) $(TARG_TEST_COMP_snk_ostm_MT_D)
	@-if exist $(OBJ_TEST_COMP_snk_ostm_MT_D) $(RM) $(OBJ_TEST_COMP_snk_ostm_MT_D)
	@-if exist $(TARG_TEST_COMP_file_MT_R) $(RM) $(TARG_TEST_COMP_file_MT_R)
	@-if exist $(OBJ_TEST_COMP_file_MT_R) $(RM) $(OBJ_TEST_COMP_file_MT_R)
	@-if exist $(TARG_TEST_COMP_fmt_sink_MT_R) $(RM) $(TARG_TEST_COMP_fmt_sink_MT_R)
	@-if exist $(OBJ_TEST_COMP_fmt_sink_MT_R) $(RM) $(OBJ_TEST_COMP_fmt_sink_MT_R)
	@-if exist $(TARG_TEST_COMP_ins_hex_MT_R) $(RM) $(TARG_TEST_COMP_ins_hex_MT_R)
	@-if exist $(OBJ_TEST_COMP_ins_hex_MT_R) $(RM) $(OBJ_TEST_COMP_ins_hex_MT_R)
	@-if exist $(TARG_TEST_COMP_ins_int_MT_R) $(RM) $(TARG_TEST_COMP_ins_int_MT_R)
	@-if exist $(OBJ_TEST_COMP_ins_int_MT_R) $(RM) $(OBJ_TEST_COMP_ins_int_MT_R)
	@-if exist $(TARG_TEST_COMP_ins_real_MT_R) $(RM) $(TARG_TEST_COMP_ins_real_MT_R)
	@-if exist $(OBJ_TEST_COMP_ins_real_MT_R) $(RM) $(OBJ_TEST_COMP_ins_real_MT_R)
	@-if exist $(TARG_TEST_COMP_itr_fmt_MT_R) $(RM) $(TARG_TEST_COMP_ins_real_MT_R)
	@-if exist $(OBJ_TEST_COMP_itr_fmt_MT_R) $(RM) $(OBJ_TEST_COMP_ins_real_MT_R)
	@-if exist $(TARG_TEST_COMP_null_sink_MT_R) $(RM) $(TARG_TEST_COMP_null_sink_MT_R)
	@-if exist $(OBJ_TEST_COMP_null_sink_MT_R) $(RM) $(OBJ_TEST_COMP_null_sink_MT_R)
	@-if exist $(TARG_TEST_COMP_snk_a_b_MT_R) $(RM) $(TARG_TEST_COMP_snk_a_b_MT_R)
	@-if exist $(OBJ_TEST_COMP_snk_a_b_MT_R) $(RM) $(OBJ_TEST_COMP_snk_a_b_MT_R)
	@-if exist $(TARG_TEST_COMP_write_sink_MT_R) $(RM) $(TARG_TEST_COMP_write_sink_MT_R)
	@-if exist $(OBJ_TEST_COMP_write_sink_MT_R) $(RM) $(OBJ_TEST_COMP_write_sink_MT_R)
	@-if exist $(TARG_TEST_COMP_x_1_MT_R) $(RM) $(TARG_TEST_COMP_x_1_MT_R)
	@-if exist $(OBJ_TEST_COMP_x_1_MT_R) $(RM) $(OBJ_TEST_COMP_x_1_MT_R)
	@-if exist $(TARG_TEST_COMP_snk_ostm_MT_R) $(RM) $(TARG_TEST_COMP_snk_ostm_MT_R)
	@-if exist $(OBJ_TEST_COMP_snk_ostm_MT_R) $(RM) $(OBJ_TEST_COMP_snk_ostm_MT_R)
	@-if exist $(TARG_TEST_COMP_file_ST_D) $(RM) $(TARG_TEST_COMP_file_ST_D)
	@-if exist $(OBJ_TEST_COMP_file_ST_D) $(RM) $(OBJ_TEST_COMP_file_ST_D)
	@-if exist $(TARG_TEST_COMP_fmt_sink_ST_D) $(RM) $(TARG_TEST_COMP_fmt_sink_ST_D)
	@-if exist $(OBJ_TEST_COMP_fmt_sink_ST_D) $(RM) $(OBJ_TEST_COMP_fmt_sink_ST_D)
	@-if exist $(TARG_TEST_COMP_ins_hex_ST_D) $(RM) $(TARG_TEST_COMP_ins_hex_ST_D)
	@-if exist $(OBJ_TEST_COMP_ins_hex_ST_D) $(RM) $(OBJ_TEST_COMP_ins_hex_ST_D)
	@-if exist $(TARG_TEST_COMP_ins_int_ST_D) $(RM) $(TARG_TEST_COMP_ins_int_ST_D)
	@-if exist $(OBJ_TEST_COMP_ins_int_ST_D) $(RM) $(OBJ_TEST_COMP_ins_int_ST_D)
	@-if exist $(TARG_TEST_COMP_ins_real_ST_D) $(RM) $(TARG_TEST_COMP_ins_real_ST_D)
	@-if exist $(OBJ_TEST_COMP_ins_real_ST_D) $(RM) $(OBJ_TEST_COMP_ins_real_ST_D)
	@-if exist $(TARG_TEST_COMP_itr_fmt_ST_D) $(RM) $(TARG_TEST_COMP_ins_real_ST_D)
	@-if exist $(OBJ_TEST_COMP_itr_fmt_ST_D) $(RM) $(OBJ_TEST_COMP_ins_real_ST_D)
	@-if exist $(TARG_TEST_COMP_null_sink_ST_D) $(RM) $(TARG_TEST_COMP_null_sink_ST_D)
	@-if exist $(OBJ_TEST_COMP_null_sink_ST_D) $(RM) $(OBJ_TEST_COMP_null_sink_ST_D)
	@-if exist $(TARG_TEST_COMP_snk_a_b_ST_D) $(RM) $(TARG_TEST_COMP_snk_a_b_ST_D)
	@-if exist $(OBJ_TEST_COMP_snk_a_b_ST_D) $(RM) $(OBJ_TEST_COMP_snk_a_b_ST_D)
	@-if exist $(TARG_TEST_COMP_write_sink_ST_D) $(RM) $(TARG_TEST_COMP_write_sink_ST_D)
	@-if exist $(OBJ_TEST_COMP_write_sink_ST_D) $(RM) $(OBJ_TEST_COMP_write_sink_ST_D)
	@-if exist $(TARG_TEST_COMP_x_1_ST_D) $(RM) $(TARG_TEST_COMP_x_1_ST_D)
	@-if exist $(OBJ_TEST_COMP_x_1_ST_D) $(RM) $(OBJ_TEST_COMP_x_1_ST_D)
	@-if exist $(TARG_TEST_COMP_snk_ostm_ST_D) $(RM) $(TARG_TEST_COMP_snk_ostm_ST_D)
	@-if exist $(OBJ_TEST_COMP_snk_ostm_ST_D) $(RM) $(OBJ_TEST_COMP_snk_ostm_ST_D)
	@-if exist $(TARG_TEST_COMP_file_ST_R) $(RM) $(TARG_TEST_COMP_file_ST_R)
	@-if exist $(OBJ_TEST_COMP_file_ST_R) $(RM) $(OBJ_TEST_COMP_file_ST_R)
	@-if exist $(TARG_TEST_COMP_fmt_sink_ST_R) $(RM) $(TARG_TEST_COMP_fmt_sink_ST_R)
	@-if exist $(OBJ_TEST_COMP_fmt_sink_ST_R) $(RM) $(OBJ_TEST_COMP_fmt_sink_ST_R)
	@-if exist $(TARG_TEST_COMP_ins_hex_ST_R) $(RM) $(TARG_TEST_COMP_ins_hex_ST_R)
	@-if exist $(OBJ_TEST_COMP_ins_hex_ST_R) $(RM) $(OBJ_TEST_COMP_ins_hex_ST_R)
	@-if exist $(TARG_TEST_COMP_ins_int_ST_R) $(RM) $(TARG_TEST_COMP_ins_int_ST_R)
	@-if exist $(OBJ_TEST_COMP_ins_int_ST_R) $(RM) $(OBJ_TEST_COMP_ins_int_ST_R)
	@-if exist $(TARG_TEST_COMP_ins_real_ST_R) $(RM) $(TARG_TEST_COMP_ins_real_ST_R)
	@-if exist $(OBJ_TEST_COMP_ins_real_ST_R) $(RM) $(OBJ_TEST_COMP_ins_real_ST_R)
	@-if exist $(TARG_TEST_COMP_itr_fmt_ST_R) $(RM) $(TARG_TEST_COMP_ins_real_ST_R)
	@-if exist $(OBJ_TEST_COMP_itr_fmt_ST_R) $(RM) $(OBJ_TEST_COMP_ins_real_ST_R)
	@-if exist $(TARG_TEST_COMP_null_sink_ST_R) $(RM) $(TARG_TEST_COMP_null_sink_ST_R)
	@-if exist $(OBJ_TEST_COMP_null_sink_ST_R) $(RM) $(OBJ_TEST_COMP_null_sink_ST_R)
	@-if exist $(TARG_TEST_COMP_snk_a_b_ST_R) $(RM) $(TARG_TEST_COMP_snk_a_b_ST_R)
	@-if exist $(OBJ_TEST_COMP_snk_a_b_ST_R) $(RM) $(OBJ_TEST_COMP_snk_a_b_ST_R)
	@-if exist $(TARG_TEST_COMP_write_sink_ST_R) $(RM) $(TARG_TEST_COMP_write_sink_ST_R)
	@-if exist $(OBJ_TEST_COMP_write_sink_ST_R) $(RM) $(OBJ_TEST_COMP_write_sink_ST_R)
	@-if exist $(TARG_TEST_COMP_x_1_ST_R) $(RM) $(TARG_TEST_COMP_x_1_ST_R)
	@-if exist $(OBJ_TEST_COMP_x_1_ST_R) $(RM) $(OBJ_TEST_COMP_x_1_ST_R)
	@-if exist $(TARG_TEST_COMP_snk_ostm_ST_R) $(RM) $(TARG_TEST_COMP_snk_ostm_ST_R)
	@-if exist $(OBJ_TEST_COMP_snk_ostm_ST_R) $(RM) $(OBJ_TEST_COMP_snk_ostm_ST_R)

clean.test.performance:
	@echo cleaning Test::Performance files ...
	@-if exist $(TARG_TEST_PERF_scen1_MT_D) $(RM) $(TARG_TEST_PERF_scen1_MT_D)
	@-if exist $(OBJ_TEST_PERF_scen1_MT_D) $(RM) $(OBJ_TEST_PERF_scen1_MT_D)
	@-if exist $(TARG_TEST_PERF_scen2_MT_D) $(RM) $(TARG_TEST_PERF_scen2_MT_D)
	@-if exist $(OBJ_TEST_PERF_scen2_MT_D) $(RM) $(OBJ_TEST_PERF_scen2_MT_D)
	@-if exist $(TARG_TEST_PERF_scen3_MT_D) $(RM) $(TARG_TEST_PERF_scen3_MT_D)
	@-if exist $(OBJ_TEST_PERF_scen3_MT_D) $(RM) $(OBJ_TEST_PERF_scen3_MT_D)
	@-if exist $(TARG_TEST_PERF_scen4_MT_D) $(RM) $(TARG_TEST_PERF_scen4_MT_D)
	@-if exist $(OBJ_TEST_PERF_scen4_MT_D) $(RM) $(OBJ_TEST_PERF_scen4_MT_D)
	@-if exist $(TARG_TEST_PERF_scen5_MT_D) $(RM) $(TARG_TEST_PERF_scen5_MT_D)
	@-if exist $(OBJ_TEST_PERF_scen5_MT_D) $(RM) $(OBJ_TEST_PERF_scen5_MT_D)
	@-if exist $(TARG_TEST_PERF_scen6_MT_D) $(RM) $(TARG_TEST_PERF_scen6_MT_D)
	@-if exist $(OBJ_TEST_PERF_scen6_MT_D) $(RM) $(OBJ_TEST_PERF_scen6_MT_D)
	@-if exist $(TARG_TEST_PERF_scen7_MT_D) $(RM) $(TARG_TEST_PERF_scen7_MT_D)
	@-if exist $(OBJ_TEST_PERF_scen7_MT_D) $(RM) $(OBJ_TEST_PERF_scen7_MT_D)
ifdef BOOST
	@-if exist $(TARG_TEST_PERF_scen8_MT_D) $(RM) $(TARG_TEST_PERF_scen8_MT_D)
	@-if exist $(OBJ_TEST_PERF_scen8_MT_D) $(RM) $(OBJ_TEST_PERF_scen8_MT_D)
endif # BOOST
	@-if exist $(TARG_TEST_PERF_scen1_MT_R) $(RM) $(TARG_TEST_PERF_scen1_MT_R)
	@-if exist $(OBJ_TEST_PERF_scen1_MT_R) $(RM) $(OBJ_TEST_PERF_scen1_MT_R)
	@-if exist $(TARG_TEST_PERF_scen2_MT_R) $(RM) $(TARG_TEST_PERF_scen2_MT_R)
	@-if exist $(OBJ_TEST_PERF_scen2_MT_R) $(RM) $(OBJ_TEST_PERF_scen2_MT_R)
	@-if exist $(TARG_TEST_PERF_scen3_MT_R) $(RM) $(TARG_TEST_PERF_scen3_MT_R)
	@-if exist $(OBJ_TEST_PERF_scen3_MT_R) $(RM) $(OBJ_TEST_PERF_scen3_MT_R)
	@-if exist $(TARG_TEST_PERF_scen4_MT_R) $(RM) $(TARG_TEST_PERF_scen4_MT_R)
	@-if exist $(OBJ_TEST_PERF_scen4_MT_R) $(RM) $(OBJ_TEST_PERF_scen4_MT_R)
	@-if exist $(TARG_TEST_PERF_scen5_MT_R) $(RM) $(TARG_TEST_PERF_scen5_MT_R)
	@-if exist $(OBJ_TEST_PERF_scen5_MT_R) $(RM) $(OBJ_TEST_PERF_scen5_MT_R)
	@-if exist $(TARG_TEST_PERF_scen6_MT_R) $(RM) $(TARG_TEST_PERF_scen6_MT_R)
	@-if exist $(OBJ_TEST_PERF_scen6_MT_R) $(RM) $(OBJ_TEST_PERF_scen6_MT_R)
	@-if exist $(TARG_TEST_PERF_scen7_MT_R) $(RM) $(TARG_TEST_PERF_scen7_MT_R)
	@-if exist $(OBJ_TEST_PERF_scen7_MT_R) $(RM) $(OBJ_TEST_PERF_scen7_MT_R)
ifdef BOOST
	@-if exist $(TARG_TEST_PERF_scen8_MT_R) $(RM) $(TARG_TEST_PERF_scen8_MT_R)
	@-if exist $(OBJ_TEST_PERF_scen8_MT_R) $(RM) $(OBJ_TEST_PERF_scen8_MT_R)
endif # BOOST
	@-if exist $(TARG_TEST_PERF_scen1_ST_D) $(RM) $(TARG_TEST_PERF_scen1_ST_D)
	@-if exist $(OBJ_TEST_PERF_scen1_ST_D) $(RM) $(OBJ_TEST_PERF_scen1_ST_D)
	@-if exist $(TARG_TEST_PERF_scen2_ST_D) $(RM) $(TARG_TEST_PERF_scen2_ST_D)
	@-if exist $(OBJ_TEST_PERF_scen2_ST_D) $(RM) $(OBJ_TEST_PERF_scen2_ST_D)
	@-if exist $(TARG_TEST_PERF_scen3_ST_D) $(RM) $(TARG_TEST_PERF_scen3_ST_D)
	@-if exist $(OBJ_TEST_PERF_scen3_ST_D) $(RM) $(OBJ_TEST_PERF_scen3_ST_D)
	@-if exist $(TARG_TEST_PERF_scen4_ST_D) $(RM) $(TARG_TEST_PERF_scen4_ST_D)
	@-if exist $(OBJ_TEST_PERF_scen4_ST_D) $(RM) $(OBJ_TEST_PERF_scen4_ST_D)
	@-if exist $(TARG_TEST_PERF_scen5_ST_D) $(RM) $(TARG_TEST_PERF_scen5_ST_D)
	@-if exist $(OBJ_TEST_PERF_scen5_ST_D) $(RM) $(OBJ_TEST_PERF_scen5_ST_D)
	@-if exist $(TARG_TEST_PERF_scen6_ST_D) $(RM) $(TARG_TEST_PERF_scen6_ST_D)
	@-if exist $(OBJ_TEST_PERF_scen6_ST_D) $(RM) $(OBJ_TEST_PERF_scen6_ST_D)
	@-if exist $(TARG_TEST_PERF_scen7_ST_D) $(RM) $(TARG_TEST_PERF_scen7_ST_D)
	@-if exist $(OBJ_TEST_PERF_scen7_ST_D) $(RM) $(OBJ_TEST_PERF_scen7_ST_D)
ifdef BOOST
	@-if exist $(TARG_TEST_PERF_scen8_ST_D) $(RM) $(TARG_TEST_PERF_scen8_ST_D)
	@-if exist $(OBJ_TEST_PERF_scen8_ST_D) $(RM) $(OBJ_TEST_PERF_scen8_ST_D)
endif # BOOST
	@-if exist $(TARG_TEST_PERF_scen1_ST_R) $(RM) $(TARG_TEST_PERF_scen1_ST_R)
	@-if exist $(OBJ_TEST_PERF_scen1_ST_R) $(RM) $(OBJ_TEST_PERF_scen1_ST_R)
	@-if exist $(TARG_TEST_PERF_scen2_ST_R) $(RM) $(TARG_TEST_PERF_scen2_ST_R)
	@-if exist $(OBJ_TEST_PERF_scen2_ST_R) $(RM) $(OBJ_TEST_PERF_scen2_ST_R)
	@-if exist $(TARG_TEST_PERF_scen3_ST_R) $(RM) $(TARG_TEST_PERF_scen3_ST_R)
	@-if exist $(OBJ_TEST_PERF_scen3_ST_R) $(RM) $(OBJ_TEST_PERF_scen3_ST_R)
	@-if exist $(TARG_TEST_PERF_scen4_ST_R) $(RM) $(TARG_TEST_PERF_scen4_ST_R)
	@-if exist $(OBJ_TEST_PERF_scen4_ST_R) $(RM) $(OBJ_TEST_PERF_scen4_ST_R)
	@-if exist $(TARG_TEST_PERF_scen5_ST_R) $(RM) $(TARG_TEST_PERF_scen5_ST_R)
	@-if exist $(OBJ_TEST_PERF_scen5_ST_R) $(RM) $(OBJ_TEST_PERF_scen5_ST_R)
	@-if exist $(TARG_TEST_PERF_scen6_ST_R) $(RM) $(TARG_TEST_PERF_scen6_ST_R)
	@-if exist $(OBJ_TEST_PERF_scen6_ST_R) $(RM) $(OBJ_TEST_PERF_scen6_ST_R)
	@-if exist $(TARG_TEST_PERF_scen7_ST_R) $(RM) $(TARG_TEST_PERF_scen7_ST_R)
	@-if exist $(OBJ_TEST_PERF_scen7_ST_R) $(RM) $(OBJ_TEST_PERF_scen7_ST_R)
ifdef BOOST
	@-if exist $(TARG_TEST_PERF_scen8_ST_R) $(RM) $(TARG_TEST_PERF_scen8_ST_R)
	@-if exist $(OBJ_TEST_PERF_scen8_ST_R) $(RM) $(OBJ_TEST_PERF_scen8_ST_R)
endif # BOOST

clean.test.scratch:
	@echo cleaning Test::Scratch files ...
	@-if exist $(TARG_TEST_SCRT_file_MT_D) $(RM) $(TARG_TEST_SCRT_file_MT_D)
	@-if exist $(OBJ_TEST_SCRT_file_MT_D) $(RM) $(OBJ_TEST_SCRT_file_MT_D)
	@-if exist $(TARG_TEST_SCRT_speech_MT_D) $(RM) $(TARG_TEST_SCRT_speech_MT_D)
	@-if exist $(OBJ_TEST_SCRT_speech_MT_D) $(RM) $(OBJ_TEST_SCRT_speech_MT_D)
	@-if exist $(TARG_TEST_SCRT_file_MT_R) $(RM) $(TARG_TEST_SCRT_file_MT_R)
	@-if exist $(OBJ_TEST_SCRT_file_MT_R) $(RM) $(OBJ_TEST_SCRT_file_MT_R)
	@-if exist $(TARG_TEST_SCRT_speech_MT_R) $(RM) $(TARG_TEST_SCRT_speech_MT_R)
	@-if exist $(OBJ_TEST_SCRT_speech_MT_R) $(RM) $(OBJ_TEST_SCRT_speech_MT_R)
	@-if exist $(TARG_TEST_SCRT_file_ST_D) $(RM) $(TARG_TEST_SCRT_file_ST_D)
	@-if exist $(OBJ_TEST_SCRT_file_ST_D) $(RM) $(OBJ_TEST_SCRT_file_ST_D)
	@-if exist $(TARG_TEST_SCRT_speech_ST_D) $(RM) $(TARG_TEST_SCRT_speech_ST_D)
	@-if exist $(OBJ_TEST_SCRT_speech_ST_D) $(RM) $(OBJ_TEST_SCRT_speech_ST_D)
	@-if exist $(TARG_TEST_SCRT_file_ST_R) $(RM) $(TARG_TEST_SCRT_file_ST_R)
	@-if exist $(OBJ_TEST_SCRT_file_ST_R) $(RM) $(OBJ_TEST_SCRT_file_ST_R)
	@-if exist $(TARG_TEST_SCRT_speech_ST_R) $(RM) $(TARG_TEST_SCRT_speech_ST_R)
	@-if exist $(OBJ_TEST_SCRT_speech_ST_R) $(RM) $(OBJ_TEST_SCRT_speech_ST_R)

clean.test.unit:
	@echo cleaning Test::Unit files ...
	@-if exist $(TARG_TEST_UNIT_api_acsllen_MT_D) $(RM) $(TARG_TEST_UNIT_api_acsllen_MT_D)
	@-if exist $(OBJ_TEST_UNIT_api_acsllen_MT_D) $(RM) $(OBJ_TEST_UNIT_api_acsllen_MT_D)
	@-if exist $(TARG_TEST_UNIT_api_crlf_MT_D) $(RM) $(TARG_TEST_UNIT_api_crlf_MT_D)
	@-if exist $(OBJ_TEST_UNIT_api_crlf_MT_D) $(RM) $(OBJ_TEST_UNIT_api_crlf_MT_D)
	@-if exist $(TARG_TEST_UNIT_api_flrpl_MT_D) $(RM) $(TARG_TEST_UNIT_api_flrpl_MT_D)
	@-if exist $(OBJ_TEST_UNIT_api_flrpl_MT_D) $(RM) $(OBJ_TEST_UNIT_api_flrpl_MT_D)
	@-if exist $(TARG_TEST_UNIT_api_init_MT_D) $(RM) $(TARG_TEST_UNIT_api_init_MT_D)
	@-if exist $(TARG_TEST_UNIT_api_illfmdh_MT_D) $(RM) $(TARG_TEST_UNIT_api_illfmdh_MT_D)
	@-if exist $(OBJ_TEST_UNIT_api_illfmdh_MT_D) $(RM) $(OBJ_TEST_UNIT_api_illfmdh_MT_D)
	@-if exist $(OBJ_TEST_UNIT_api_init_MT_D) $(RM) $(OBJ_TEST_UNIT_api_init_MT_D)
	@-if exist $(TARG_TEST_UNIT_api_lkptrn_MT_D) $(RM) $(TARG_TEST_UNIT_api_lkptrn_MT_D)
	@-if exist $(OBJ_TEST_UNIT_api_lkptrn_MT_D) $(RM) $(OBJ_TEST_UNIT_api_lkptrn_MT_D)
	@-if exist $(TARG_TEST_UNIT_api_msmtchh_MT_D) $(RM) $(TARG_TEST_UNIT_api_msmtchh_MT_D)
	@-if exist $(OBJ_TEST_UNIT_api_msmtchh_MT_D) $(RM) $(OBJ_TEST_UNIT_api_msmtchh_MT_D)
	@-if exist $(TARG_TEST_UNIT_api_prsrpl_MT_D) $(RM) $(TARG_TEST_UNIT_api_prsrpl_MT_D)
	@-if exist $(OBJ_TEST_UNIT_api_prsrpl_MT_D) $(RM) $(OBJ_TEST_UNIT_api_prsrpl_MT_D)
	@-if exist $(TARG_TEST_UNIT_bndl_winini_MT_D) $(RM) $(TARG_TEST_UNIT_bndl_winini_MT_D)
	@-if exist $(OBJ_TEST_UNIT_bndl_winini_MT_D) $(RM) $(OBJ_TEST_UNIT_bndl_winini_MT_D)
	@-if exist $(TARG_TEST_UNIT_fmt_stdfl_MT_D) $(RM) $(TARG_TEST_UNIT_fmt_stdfl_MT_D)
	@-if exist $(OBJ_TEST_UNIT_fmt_stdfl_MT_D) $(RM) $(OBJ_TEST_UNIT_fmt_stdfl_MT_D)
	@-if exist $(TARG_TEST_UNIT_snk_ods_MT_D) $(RM) $(TARG_TEST_UNIT_snk_ods_MT_D)
	@-if exist $(OBJ_TEST_UNIT_snk_ods_MT_D) $(RM) $(OBJ_TEST_UNIT_snk_ods_MT_D)
	@-if exist $(TARG_TEST_UNIT_ins_ch_MT_D) $(RM) $(TARG_TEST_UNIT_ins_ch_MT_D)
	@-if exist $(OBJ_TEST_UNIT_ins_ch_MT_D) $(RM) $(OBJ_TEST_UNIT_ins_ch_MT_D)
	@-if exist $(TARG_TEST_UNIT_ins_i_MT_D) $(RM) $(TARG_TEST_UNIT_ins_i_MT_D)
	@-if exist $(OBJ_TEST_UNIT_ins_i_MT_D) $(RM) $(OBJ_TEST_UNIT_ins_i_MT_D)
	@-if exist $(TARG_TEST_UNIT_shim_fi_MT_D) $(RM) $(TARG_TEST_UNIT_shim_fi_MT_D)
	@-if exist $(OBJ_TEST_UNIT_shim_fi_MT_D) $(RM) $(OBJ_TEST_UNIT_shim_fi_MT_D)
	@-if exist $(TARG_TEST_UNIT_snk_a_b_MT_D) $(RM) $(TARG_TEST_UNIT_snk_a_b_MT_D)
	@-if exist $(OBJ_TEST_UNIT_snk_a_b_MT_D) $(RM) $(OBJ_TEST_UNIT_snk_a_b_MT_D)
	@-if exist $(TARG_TEST_UNIT_snk_c_str_MT_D) $(RM) $(TARG_TEST_UNIT_snk_c_str_MT_D)
	@-if exist $(OBJ_TEST_UNIT_snk_c_str_MT_D) $(RM) $(OBJ_TEST_UNIT_snk_c_str_MT_D)
	@-if exist $(TARG_TEST_UNIT_snk_chbuf_MT_D) $(RM) $(TARG_TEST_UNIT_snk_chbuf_MT_D)
	@-if exist $(OBJ_TEST_UNIT_snk_chbuf_MT_D) $(RM) $(OBJ_TEST_UNIT_snk_chbuf_MT_D)
	@-if exist $(TARG_TEST_UNIT_snk_null_MT_D) $(RM) $(TARG_TEST_UNIT_snk_null_MT_D)
	@-if exist $(OBJ_TEST_UNIT_snk_null_MT_D) $(RM) $(OBJ_TEST_UNIT_snk_null_MT_D)
	@-if exist $(TARG_TEST_UNIT_snk_ostm_MT_D) $(RM) $(TARG_TEST_UNIT_snk_ostm_MT_D)
	@-if exist $(OBJ_TEST_UNIT_snk_ostm_MT_D) $(RM) $(OBJ_TEST_UNIT_snk_ostm_MT_D)
	@-if exist $(TARG_TEST_UNIT_snk_sstm_MT_D) $(RM) $(TARG_TEST_UNIT_snk_sstm_MT_D)
	@-if exist $(OBJ_TEST_UNIT_snk_sstm_MT_D) $(RM) $(OBJ_TEST_UNIT_snk_sstm_MT_D)
	@-if exist $(TARG_TEST_UNIT_api_acsllen_MT_R) $(RM) $(TARG_TEST_UNIT_api_acsllen_MT_R)
	@-if exist $(OBJ_TEST_UNIT_api_acsllen_MT_R) $(RM) $(OBJ_TEST_UNIT_api_acsllen_MT_R)
	@-if exist $(TARG_TEST_UNIT_api_crlf_MT_R) $(RM) $(TARG_TEST_UNIT_api_crlf_MT_R)
	@-if exist $(OBJ_TEST_UNIT_api_crlf_MT_R) $(RM) $(OBJ_TEST_UNIT_api_crlf_MT_R)
	@-if exist $(TARG_TEST_UNIT_api_flrpl_MT_R) $(RM) $(TARG_TEST_UNIT_api_flrpl_MT_R)
	@-if exist $(OBJ_TEST_UNIT_api_flrpl_MT_R) $(RM) $(OBJ_TEST_UNIT_api_flrpl_MT_R)
	@-if exist $(TARG_TEST_UNIT_api_init_MT_R) $(RM) $(TARG_TEST_UNIT_api_init_MT_R)
	@-if exist $(TARG_TEST_UNIT_api_illfmdh_MT_R) $(RM) $(TARG_TEST_UNIT_api_illfmdh_MT_R)
	@-if exist $(OBJ_TEST_UNIT_api_illfmdh_MT_R) $(RM) $(OBJ_TEST_UNIT_api_illfmdh_MT_R)
	@-if exist $(OBJ_TEST_UNIT_api_init_MT_R) $(RM) $(OBJ_TEST_UNIT_api_init_MT_R)
	@-if exist $(TARG_TEST_UNIT_api_lkptrn_MT_R) $(RM) $(TARG_TEST_UNIT_api_lkptrn_MT_R)
	@-if exist $(OBJ_TEST_UNIT_api_lkptrn_MT_R) $(RM) $(OBJ_TEST_UNIT_api_lkptrn_MT_R)
	@-if exist $(TARG_TEST_UNIT_api_msmtchh_MT_R) $(RM) $(TARG_TEST_UNIT_api_msmtchh_MT_R)
	@-if exist $(OBJ_TEST_UNIT_api_msmtchh_MT_R) $(RM) $(OBJ_TEST_UNIT_api_msmtchh_MT_R)
	@-if exist $(TARG_TEST_UNIT_api_prsrpl_MT_R) $(RM) $(TARG_TEST_UNIT_api_prsrpl_MT_R)
	@-if exist $(OBJ_TEST_UNIT_api_prsrpl_MT_R) $(RM) $(OBJ_TEST_UNIT_api_prsrpl_MT_R)
	@-if exist $(TARG_TEST_UNIT_bndl_winini_MT_R) $(RM) $(TARG_TEST_UNIT_bndl_winini_MT_R)
	@-if exist $(OBJ_TEST_UNIT_bndl_winini_MT_R) $(RM) $(OBJ_TEST_UNIT_bndl_winini_MT_R)
	@-if exist $(TARG_TEST_UNIT_fmt_stdfl_MT_R) $(RM) $(TARG_TEST_UNIT_fmt_stdfl_MT_R)
	@-if exist $(OBJ_TEST_UNIT_fmt_stdfl_MT_R) $(RM) $(OBJ_TEST_UNIT_fmt_stdfl_MT_R)
	@-if exist $(TARG_TEST_UNIT_snk_ods_MT_R) $(RM) $(TARG_TEST_UNIT_snk_ods_MT_R)
	@-if exist $(OBJ_TEST_UNIT_snk_ods_MT_R) $(RM) $(OBJ_TEST_UNIT_snk_ods_MT_R)
	@-if exist $(TARG_TEST_UNIT_ins_ch_MT_R) $(RM) $(TARG_TEST_UNIT_ins_ch_MT_R)
	@-if exist $(OBJ_TEST_UNIT_ins_ch_MT_R) $(RM) $(OBJ_TEST_UNIT_ins_ch_MT_R)
	@-if exist $(TARG_TEST_UNIT_ins_i_MT_R) $(RM) $(TARG_TEST_UNIT_ins_i_MT_R)
	@-if exist $(OBJ_TEST_UNIT_ins_i_MT_R) $(RM) $(OBJ_TEST_UNIT_ins_i_MT_R)
	@-if exist $(TARG_TEST_UNIT_shim_fi_MT_R) $(RM) $(TARG_TEST_UNIT_shim_fi_MT_R)
	@-if exist $(OBJ_TEST_UNIT_shim_fi_MT_R) $(RM) $(OBJ_TEST_UNIT_shim_fi_MT_R)
	@-if exist $(TARG_TEST_UNIT_snk_a_b_MT_R) $(RM) $(TARG_TEST_UNIT_snk_a_b_MT_R)
	@-if exist $(OBJ_TEST_UNIT_snk_a_b_MT_R) $(RM) $(OBJ_TEST_UNIT_snk_a_b_MT_R)
	@-if exist $(TARG_TEST_UNIT_snk_c_str_MT_R) $(RM) $(TARG_TEST_UNIT_snk_c_str_MT_R)
	@-if exist $(OBJ_TEST_UNIT_snk_c_str_MT_R) $(RM) $(OBJ_TEST_UNIT_snk_c_str_MT_R)
	@-if exist $(TARG_TEST_UNIT_snk_chbuf_MT_R) $(RM) $(TARG_TEST_UNIT_snk_chbuf_MT_R)
	@-if exist $(OBJ_TEST_UNIT_snk_chbuf_MT_R) $(RM) $(OBJ_TEST_UNIT_snk_chbuf_MT_R)
	@-if exist $(TARG_TEST_UNIT_snk_null_MT_R) $(RM) $(TARG_TEST_UNIT_snk_null_MT_R)
	@-if exist $(OBJ_TEST_UNIT_snk_null_MT_R) $(RM) $(OBJ_TEST_UNIT_snk_null_MT_R)
	@-if exist $(TARG_TEST_UNIT_snk_ostm_MT_R) $(RM) $(TARG_TEST_UNIT_snk_ostm_MT_R)
	@-if exist $(OBJ_TEST_UNIT_snk_ostm_MT_R) $(RM) $(OBJ_TEST_UNIT_snk_ostm_MT_R)
	@-if exist $(TARG_TEST_UNIT_snk_sstm_MT_R) $(RM) $(TARG_TEST_UNIT_snk_sstm_MT_R)
	@-if exist $(OBJ_TEST_UNIT_snk_sstm_MT_R) $(RM) $(OBJ_TEST_UNIT_snk_sstm_MT_R)
	@-if exist $(TARG_TEST_UNIT_api_acsllen_ST_D) $(RM) $(TARG_TEST_UNIT_api_acsllen_ST_D)
	@-if exist $(OBJ_TEST_UNIT_api_acsllen_ST_D) $(RM) $(OBJ_TEST_UNIT_api_acsllen_ST_D)
	@-if exist $(TARG_TEST_UNIT_api_crlf_ST_D) $(RM) $(TARG_TEST_UNIT_api_crlf_ST_D)
	@-if exist $(OBJ_TEST_UNIT_api_crlf_ST_D) $(RM) $(OBJ_TEST_UNIT_api_crlf_ST_D)
	@-if exist $(TARG_TEST_UNIT_api_flrpl_ST_D) $(RM) $(TARG_TEST_UNIT_api_flrpl_ST_D)
	@-if exist $(OBJ_TEST_UNIT_api_flrpl_ST_D) $(RM) $(OBJ_TEST_UNIT_api_flrpl_ST_D)
	@-if exist $(TARG_TEST_UNIT_api_init_ST_D) $(RM) $(TARG_TEST_UNIT_api_init_ST_D)
	@-if exist $(TARG_TEST_UNIT_api_illfmdh_ST_D) $(RM) $(TARG_TEST_UNIT_api_illfmdh_ST_D)
	@-if exist $(OBJ_TEST_UNIT_api_illfmdh_ST_D) $(RM) $(OBJ_TEST_UNIT_api_illfmdh_ST_D)
	@-if exist $(OBJ_TEST_UNIT_api_init_ST_D) $(RM) $(OBJ_TEST_UNIT_api_init_ST_D)
	@-if exist $(TARG_TEST_UNIT_api_lkptrn_ST_D) $(RM) $(TARG_TEST_UNIT_api_lkptrn_ST_D)
	@-if exist $(OBJ_TEST_UNIT_api_lkptrn_ST_D) $(RM) $(OBJ_TEST_UNIT_api_lkptrn_ST_D)
	@-if exist $(TARG_TEST_UNIT_api_msmtchh_ST_D) $(RM) $(TARG_TEST_UNIT_api_msmtchh_ST_D)
	@-if exist $(OBJ_TEST_UNIT_api_msmtchh_ST_D) $(RM) $(OBJ_TEST_UNIT_api_msmtchh_ST_D)
	@-if exist $(TARG_TEST_UNIT_api_prsrpl_ST_D) $(RM) $(TARG_TEST_UNIT_api_prsrpl_ST_D)
	@-if exist $(OBJ_TEST_UNIT_api_prsrpl_ST_D) $(RM) $(OBJ_TEST_UNIT_api_prsrpl_ST_D)
	@-if exist $(TARG_TEST_UNIT_bndl_winini_ST_D) $(RM) $(TARG_TEST_UNIT_bndl_winini_ST_D)
	@-if exist $(OBJ_TEST_UNIT_bndl_winini_ST_D) $(RM) $(OBJ_TEST_UNIT_bndl_winini_ST_D)
	@-if exist $(TARG_TEST_UNIT_fmt_stdfl_ST_D) $(RM) $(TARG_TEST_UNIT_fmt_stdfl_ST_D)
	@-if exist $(OBJ_TEST_UNIT_fmt_stdfl_ST_D) $(RM) $(OBJ_TEST_UNIT_fmt_stdfl_ST_D)
	@-if exist $(TARG_TEST_UNIT_snk_ods_ST_D) $(RM) $(TARG_TEST_UNIT_snk_ods_ST_D)
	@-if exist $(OBJ_TEST_UNIT_snk_ods_ST_D) $(RM) $(OBJ_TEST_UNIT_snk_ods_ST_D)
	@-if exist $(TARG_TEST_UNIT_ins_ch_ST_D) $(RM) $(TARG_TEST_UNIT_ins_ch_ST_D)
	@-if exist $(OBJ_TEST_UNIT_ins_ch_ST_D) $(RM) $(OBJ_TEST_UNIT_ins_ch_ST_D)
	@-if exist $(TARG_TEST_UNIT_ins_i_ST_D) $(RM) $(TARG_TEST_UNIT_ins_i_ST_D)
	@-if exist $(OBJ_TEST_UNIT_ins_i_ST_D) $(RM) $(OBJ_TEST_UNIT_ins_i_ST_D)
	@-if exist $(TARG_TEST_UNIT_shim_fi_ST_D) $(RM) $(TARG_TEST_UNIT_shim_fi_ST_D)
	@-if exist $(OBJ_TEST_UNIT_shim_fi_ST_D) $(RM) $(OBJ_TEST_UNIT_shim_fi_ST_D)
	@-if exist $(TARG_TEST_UNIT_snk_a_b_ST_D) $(RM) $(TARG_TEST_UNIT_snk_a_b_ST_D)
	@-if exist $(OBJ_TEST_UNIT_snk_a_b_ST_D) $(RM) $(OBJ_TEST_UNIT_snk_a_b_ST_D)
	@-if exist $(TARG_TEST_UNIT_snk_c_str_ST_D) $(RM) $(TARG_TEST_UNIT_snk_c_str_ST_D)
	@-if exist $(OBJ_TEST_UNIT_snk_c_str_ST_D) $(RM) $(OBJ_TEST_UNIT_snk_c_str_ST_D)
	@-if exist $(TARG_TEST_UNIT_snk_chbuf_ST_D) $(RM) $(TARG_TEST_UNIT_snk_chbuf_ST_D)
	@-if exist $(OBJ_TEST_UNIT_snk_chbuf_ST_D) $(RM) $(OBJ_TEST_UNIT_snk_chbuf_ST_D)
	@-if exist $(TARG_TEST_UNIT_snk_null_ST_D) $(RM) $(TARG_TEST_UNIT_snk_null_ST_D)
	@-if exist $(OBJ_TEST_UNIT_snk_null_ST_D) $(RM) $(OBJ_TEST_UNIT_snk_null_ST_D)
	@-if exist $(TARG_TEST_UNIT_snk_ostm_ST_D) $(RM) $(TARG_TEST_UNIT_snk_ostm_ST_D)
	@-if exist $(OBJ_TEST_UNIT_snk_ostm_ST_D) $(RM) $(OBJ_TEST_UNIT_snk_ostm_ST_D)
	@-if exist $(TARG_TEST_UNIT_snk_sstm_ST_D) $(RM) $(TARG_TEST_UNIT_snk_sstm_ST_D)
	@-if exist $(OBJ_TEST_UNIT_snk_sstm_ST_D) $(RM) $(OBJ_TEST_UNIT_snk_sstm_ST_D)
	@-if exist $(TARG_TEST_UNIT_api_acsllen_ST_R) $(RM) $(TARG_TEST_UNIT_api_acsllen_ST_R)
	@-if exist $(OBJ_TEST_UNIT_api_acsllen_ST_R) $(RM) $(OBJ_TEST_UNIT_api_acsllen_ST_R)
	@-if exist $(TARG_TEST_UNIT_api_crlf_ST_R) $(RM) $(TARG_TEST_UNIT_api_crlf_ST_R)
	@-if exist $(OBJ_TEST_UNIT_api_crlf_ST_R) $(RM) $(OBJ_TEST_UNIT_api_crlf_ST_R)
	@-if exist $(TARG_TEST_UNIT_api_flrpl_ST_R) $(RM) $(TARG_TEST_UNIT_api_flrpl_ST_R)
	@-if exist $(OBJ_TEST_UNIT_api_flrpl_ST_R) $(RM) $(OBJ_TEST_UNIT_api_flrpl_ST_R)
	@-if exist $(TARG_TEST_UNIT_api_init_ST_R) $(RM) $(TARG_TEST_UNIT_api_init_ST_R)
	@-if exist $(TARG_TEST_UNIT_api_illfmdh_ST_R) $(RM) $(TARG_TEST_UNIT_api_illfmdh_ST_R)
	@-if exist $(OBJ_TEST_UNIT_api_illfmdh_ST_R) $(RM) $(OBJ_TEST_UNIT_api_illfmdh_ST_R)
	@-if exist $(OBJ_TEST_UNIT_api_init_ST_R) $(RM) $(OBJ_TEST_UNIT_api_init_ST_R)
	@-if exist $(TARG_TEST_UNIT_api_lkptrn_ST_R) $(RM) $(TARG_TEST_UNIT_api_lkptrn_ST_R)
	@-if exist $(OBJ_TEST_UNIT_api_lkptrn_ST_R) $(RM) $(OBJ_TEST_UNIT_api_lkptrn_ST_R)
	@-if exist $(TARG_TEST_UNIT_api_msmtchh_ST_R) $(RM) $(TARG_TEST_UNIT_api_msmtchh_ST_R)
	@-if exist $(OBJ_TEST_UNIT_api_msmtchh_ST_R) $(RM) $(OBJ_TEST_UNIT_api_msmtchh_ST_R)
	@-if exist $(TARG_TEST_UNIT_api_prsrpl_ST_R) $(RM) $(TARG_TEST_UNIT_api_prsrpl_ST_R)
	@-if exist $(OBJ_TEST_UNIT_api_prsrpl_ST_R) $(RM) $(OBJ_TEST_UNIT_api_prsrpl_ST_R)
	@-if exist $(TARG_TEST_UNIT_bndl_winini_ST_R) $(RM) $(TARG_TEST_UNIT_bndl_winini_ST_R)
	@-if exist $(OBJ_TEST_UNIT_bndl_winini_ST_R) $(RM) $(OBJ_TEST_UNIT_bndl_winini_ST_R)
	@-if exist $(TARG_TEST_UNIT_fmt_stdfl_ST_R) $(RM) $(TARG_TEST_UNIT_fmt_stdfl_ST_R)
	@-if exist $(OBJ_TEST_UNIT_fmt_stdfl_ST_R) $(RM) $(OBJ_TEST_UNIT_fmt_stdfl_ST_R)
	@-if exist $(TARG_TEST_UNIT_snk_ods_ST_R) $(RM) $(TARG_TEST_UNIT_snk_ods_ST_R)
	@-if exist $(OBJ_TEST_UNIT_snk_ods_ST_R) $(RM) $(OBJ_TEST_UNIT_snk_ods_ST_R)
	@-if exist $(TARG_TEST_UNIT_ins_ch_ST_R) $(RM) $(TARG_TEST_UNIT_ins_ch_ST_R)
	@-if exist $(OBJ_TEST_UNIT_ins_ch_ST_R) $(RM) $(OBJ_TEST_UNIT_ins_ch_ST_R)
	@-if exist $(TARG_TEST_UNIT_ins_i_ST_R) $(RM) $(TARG_TEST_UNIT_ins_i_ST_R)
	@-if exist $(OBJ_TEST_UNIT_ins_i_ST_R) $(RM) $(OBJ_TEST_UNIT_ins_i_ST_R)
	@-if exist $(TARG_TEST_UNIT_shim_fi_ST_R) $(RM) $(TARG_TEST_UNIT_shim_fi_ST_R)
	@-if exist $(OBJ_TEST_UNIT_shim_fi_ST_R) $(RM) $(OBJ_TEST_UNIT_shim_fi_ST_R)
	@-if exist $(TARG_TEST_UNIT_snk_a_b_ST_R) $(RM) $(TARG_TEST_UNIT_snk_a_b_ST_R)
	@-if exist $(OBJ_TEST_UNIT_snk_a_b_ST_R) $(RM) $(OBJ_TEST_UNIT_snk_a_b_ST_R)
	@-if exist $(TARG_TEST_UNIT_snk_c_str_ST_R) $(RM) $(TARG_TEST_UNIT_snk_c_str_ST_R)
	@-if exist $(OBJ_TEST_UNIT_snk_c_str_ST_R) $(RM) $(OBJ_TEST_UNIT_snk_c_str_ST_R)
	@-if exist $(TARG_TEST_UNIT_snk_chbuf_ST_R) $(RM) $(TARG_TEST_UNIT_snk_chbuf_ST_R)
	@-if exist $(OBJ_TEST_UNIT_snk_chbuf_ST_R) $(RM) $(OBJ_TEST_UNIT_snk_chbuf_ST_R)
	@-if exist $(TARG_TEST_UNIT_snk_null_ST_R) $(RM) $(TARG_TEST_UNIT_snk_null_ST_R)
	@-if exist $(OBJ_TEST_UNIT_snk_null_ST_R) $(RM) $(OBJ_TEST_UNIT_snk_null_ST_R)
	@-if exist $(TARG_TEST_UNIT_snk_ostm_ST_R) $(RM) $(TARG_TEST_UNIT_snk_ostm_ST_R)
	@-if exist $(OBJ_TEST_UNIT_snk_ostm_ST_R) $(RM) $(OBJ_TEST_UNIT_snk_ostm_ST_R)
	@-if exist $(TARG_TEST_UNIT_snk_sstm_ST_R) $(RM) $(TARG_TEST_UNIT_snk_sstm_ST_R)
	@-if exist $(OBJ_TEST_UNIT_snk_sstm_ST_R) $(RM) $(OBJ_TEST_UNIT_snk_sstm_ST_R)

clean.test: 										clean.test.unit clean.test.component clean.test.scratch clean.test.performance

clean:                                              clean.libs clean.bitbucket clean.examples clean.samples clean.test

clean.all:                                          clean


############################################################################
# build targets

##################################################
# Libraries

########################################
# Main library - 'fastformat.X.core.a'

$(LIB_CORE_MT_D): $(OBJ_CORE_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_CORE_MT_D)

$(OBJ_cr_api_MT_D): $(PROJ_SRC_DIR)\api.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D) -o $@ $(PROJ_SRC_DIR)\api.cpp
$(OBJ_cr_fsdhndlrs_MT_D): $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D) -o $@ $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp
$(OBJ_cr_fmtcache_MT_D): $(PROJ_SRC_DIR)\fmt_cache.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D) -o $@ $(PROJ_SRC_DIR)\fmt_cache.cpp
$(OBJ_cr_initstr_MT_D): $(PROJ_SRC_DIR)\init_code_strings.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D) -o $@ $(PROJ_SRC_DIR)\init_code_strings.cpp
$(OBJ_cr_mempool_MT_D): $(PROJ_SRC_DIR)\memory_pool.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D) -o $@ $(PROJ_SRC_DIR)\memory_pool.cpp
$(OBJ_cr_replacements_MT_D): $(PROJ_SRC_DIR)\replacements.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D) -o $@ $(PROJ_SRC_DIR)\replacements.cpp
$(OBJ_cr_snprintf_MT_D): $(PROJ_SRC_DIR)\snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D) -o $@ $(PROJ_SRC_DIR)\snprintf.cpp

$(LIB_CORE_MT_R): $(OBJ_CORE_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_CORE_MT_R)

$(OBJ_cr_api_MT_R): $(PROJ_SRC_DIR)\api.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R) -o $@ $(PROJ_SRC_DIR)\api.cpp
$(OBJ_cr_fsdhndlrs_MT_R): $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R) -o $@ $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp
$(OBJ_cr_fmtcache_MT_R): $(PROJ_SRC_DIR)\fmt_cache.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R) -o $@ $(PROJ_SRC_DIR)\fmt_cache.cpp
$(OBJ_cr_initstr_MT_R): $(PROJ_SRC_DIR)\init_code_strings.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R) -o $@ $(PROJ_SRC_DIR)\init_code_strings.cpp
$(OBJ_cr_mempool_MT_R): $(PROJ_SRC_DIR)\memory_pool.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R) -o $@ $(PROJ_SRC_DIR)\memory_pool.cpp
$(OBJ_cr_replacements_MT_R): $(PROJ_SRC_DIR)\replacements.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R) -o $@ $(PROJ_SRC_DIR)\replacements.cpp
$(OBJ_cr_snprintf_MT_R): $(PROJ_SRC_DIR)\snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R) -o $@ $(PROJ_SRC_DIR)\snprintf.cpp

$(LIB_CORE_ST_D): $(OBJ_CORE_ST_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_CORE_ST_D)

$(OBJ_cr_api_ST_D): $(PROJ_SRC_DIR)\api.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_ST_D) -o $@ $(PROJ_SRC_DIR)\api.cpp
$(OBJ_cr_fsdhndlrs_ST_D): $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_ST_D) -o $@ $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp
$(OBJ_cr_fmtcache_ST_D): $(PROJ_SRC_DIR)\fmt_cache.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_ST_D) -o $@ $(PROJ_SRC_DIR)\fmt_cache.cpp
$(OBJ_cr_initstr_ST_D): $(PROJ_SRC_DIR)\init_code_strings.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_ST_D) -o $@ $(PROJ_SRC_DIR)\init_code_strings.cpp
$(OBJ_cr_mempool_ST_D): $(PROJ_SRC_DIR)\memory_pool.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_ST_D) -o $@ $(PROJ_SRC_DIR)\memory_pool.cpp
$(OBJ_cr_replacements_ST_D): $(PROJ_SRC_DIR)\replacements.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_ST_D) -o $@ $(PROJ_SRC_DIR)\replacements.cpp
$(OBJ_cr_snprintf_ST_D): $(PROJ_SRC_DIR)\snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_ST_D) -o $@ $(PROJ_SRC_DIR)\snprintf.cpp

$(LIB_CORE_ST_R): $(OBJ_CORE_ST_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_CORE_ST_R)

$(OBJ_cr_api_ST_R): $(PROJ_SRC_DIR)\api.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_ST_R) -o $@ $(PROJ_SRC_DIR)\api.cpp
$(OBJ_cr_fsdhndlrs_ST_R): $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_ST_R) -o $@ $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp
$(OBJ_cr_fmtcache_ST_R): $(PROJ_SRC_DIR)\fmt_cache.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_ST_R) -o $@ $(PROJ_SRC_DIR)\fmt_cache.cpp
$(OBJ_cr_initstr_ST_R): $(PROJ_SRC_DIR)\init_code_strings.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_ST_R) -o $@ $(PROJ_SRC_DIR)\init_code_strings.cpp
$(OBJ_cr_mempool_ST_R): $(PROJ_SRC_DIR)\memory_pool.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_ST_R) -o $@ $(PROJ_SRC_DIR)\memory_pool.cpp
$(OBJ_cr_replacements_ST_R): $(PROJ_SRC_DIR)\replacements.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_ST_R) -o $@ $(PROJ_SRC_DIR)\replacements.cpp
$(OBJ_cr_snprintf_ST_R): $(PROJ_SRC_DIR)\snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_ST_R) -o $@ $(PROJ_SRC_DIR)\snprintf.cpp

########################################
# Loki.SafeFormat library - 'loki.safefmt.X.core.a'

########################################
# shwild library - 'shwild.X.core.a'

$(LIB_SHWILD_MT_D): $(OBJ_SHWILD_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_SHWILD_MT_D)

$(OBJ_shw_api_MT_D): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_SHWILD_INCLUDES_MT_D) -o $@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_MT_D): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_SHWILD_INCLUDES_MT_D) -o $@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_MT_D): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_SHWILD_INCLUDES_MT_D) -o $@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_MT_R): $(OBJ_SHWILD_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_SHWILD_MT_R)

$(OBJ_shw_api_MT_R): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_SHWILD_INCLUDES_MT_R) -o $@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_MT_R): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_SHWILD_INCLUDES_MT_R) -o $@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_MT_R): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_SHWILD_INCLUDES_MT_R) -o $@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_ST_D): $(OBJ_SHWILD_ST_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_SHWILD_ST_D)

$(OBJ_shw_api_ST_D): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) $(CPPC_SHWILD_INCLUDES_ST_D) -o $@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_ST_D): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) $(CPPC_SHWILD_INCLUDES_ST_D) -o $@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_ST_D): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) $(CPPC_SHWILD_INCLUDES_ST_D) -o $@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_ST_R): $(OBJ_SHWILD_ST_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_SHWILD_ST_R)

$(OBJ_shw_api_ST_R): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) $(CPPC_SHWILD_INCLUDES_ST_R) -o $@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_ST_R): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) $(CPPC_SHWILD_INCLUDES_ST_R) -o $@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_ST_R): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) $(CPPC_SHWILD_INCLUDES_ST_R) -o $@ $(SHWILD_SRC_DIR)\pattern.cpp

########################################
# xTests library - 'xtests.X.ff.core.a'

$(LIB_XTESTS_MT_D): $(OBJ_XTESTS_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_XTESTS_MT_D)

$(OBJ_xts_core_MT_D): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_XTESTS_INCLUDES_MT_D) -o $@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_MT_R): $(OBJ_XTESTS_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_XTESTS_MT_R)

$(OBJ_xts_core_MT_R): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_XTESTS_INCLUDES_MT_R) -o $@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_ST_D): $(OBJ_XTESTS_ST_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_XTESTS_ST_D)

$(OBJ_xts_core_ST_D): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) $(CPPC_XTESTS_INCLUDES_ST_D) -o $@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_ST_R): $(OBJ_XTESTS_ST_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_XTESTS_ST_R)

$(OBJ_xts_core_ST_R): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) $(CPPC_XTESTS_INCLUDES_ST_R) -o $@ $(XTESTS_SRC_DIR)\xtests.core.cpp

##################################################
# Examples: BitBucket

$(BITBUCKET_SRC_DIR)\bitbucket.cpp:	#$(PROJ_MAKEFILE_NAME)
	@-if not exist $(BITBUCKET_SRC_DIR)\NUL mkdir $(BITBUCKET_SRC_DIR)
	echo #include "stdio.h" > $@
	echo int main(int, char**) { int ch; for(; EOF != (ch = getchar());) { ; } return 0; } >> $@

$(TARG_BITBUCKET_MT_D):	$(OBJ_BITBUCKET_MT_D)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_BITBUCKET_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_BITBUCKET_MT_D):	$(BITBUCKET_SRC_DIR)\bitbucket.cpp $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(BITBUCKET_SRC_DIR)\bitbucket.cpp

$(TARG_BITBUCKET_MT_R):	$(OBJ_BITBUCKET_MT_R)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_BITBUCKET_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_BITBUCKET_MT_R):	$(BITBUCKET_SRC_DIR)\bitbucket.cpp $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(BITBUCKET_SRC_DIR)\bitbucket.cpp

$(TARG_BITBUCKET_ST_D):	$(OBJ_BITBUCKET_ST_D)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_BITBUCKET_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_BITBUCKET_ST_D):	$(BITBUCKET_SRC_DIR)\bitbucket.cpp $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(BITBUCKET_SRC_DIR)\bitbucket.cpp

$(TARG_BITBUCKET_ST_R):	$(OBJ_BITBUCKET_ST_R)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_BITBUCKET_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_BITBUCKET_ST_R):	$(BITBUCKET_SRC_DIR)\bitbucket.cpp $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(BITBUCKET_SRC_DIR)\bitbucket.cpp


##################################################
# Examples

$(TARG_EX_boolean_MT_D):    \
		$(OBJ_EX_boolean_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_boolean_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_boolean_MT_D): $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp

$(TARG_EX_boolean_MT_R):    \
		$(OBJ_EX_boolean_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_boolean_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_boolean_MT_R): $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp

$(TARG_EX_boolean_ST_D):    \
		$(OBJ_EX_boolean_ST_D)\
		$(LIB_CORE_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_boolean_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_boolean_ST_D): $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp

$(TARG_EX_boolean_ST_R):    \
		$(OBJ_EX_boolean_ST_R)\
		$(LIB_CORE_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_boolean_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_boolean_ST_R): $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp

$(TARG_EX_character_MT_D):    \
		$(OBJ_EX_character_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_character_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_character_MT_D): $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp

$(TARG_EX_character_MT_R):    \
		$(OBJ_EX_character_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_character_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_character_MT_R): $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp

$(TARG_EX_character_ST_D):    \
		$(OBJ_EX_character_ST_D)\
		$(LIB_CORE_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_character_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_character_ST_D): $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp

$(TARG_EX_character_ST_R):    \
		$(OBJ_EX_character_ST_R)\
		$(LIB_CORE_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_character_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_character_ST_R): $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp

$(TARG_EX_reals_MT_D):    \
		$(OBJ_EX_reals_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_reals_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_reals_MT_D): $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp

$(TARG_EX_reals_MT_R):    \
		$(OBJ_EX_reals_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_reals_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_reals_MT_R): $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp

$(TARG_EX_reals_ST_D):    \
		$(OBJ_EX_reals_ST_D)\
		$(LIB_CORE_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_reals_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_reals_ST_D): $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp

$(TARG_EX_reals_ST_R):    \
		$(OBJ_EX_reals_ST_R)\
		$(LIB_CORE_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_reals_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_reals_ST_R): $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp

$(TARG_EX_voidptrs_MT_D):    \
		$(OBJ_EX_voidptrs_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_voidptrs_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_voidptrs_MT_D): $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp

$(TARG_EX_voidptrs_MT_R):    \
		$(OBJ_EX_voidptrs_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_voidptrs_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_voidptrs_MT_R): $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp

$(TARG_EX_voidptrs_ST_D):    \
		$(OBJ_EX_voidptrs_ST_D)\
		$(LIB_CORE_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_voidptrs_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_voidptrs_ST_D): $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp

$(TARG_EX_voidptrs_ST_R):    \
		$(OBJ_EX_voidptrs_ST_R)\
		$(LIB_CORE_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_voidptrs_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_voidptrs_ST_R): $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp

$(TARG_EX_ff_101_MT_D):    \
		$(OBJ_EX_ff_101_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ff_101_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ff_101_MT_D): $(PROJ_EXAMPLES_DIR)\example.ff_101\example.ff_101.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.ff_101\example.ff_101.cpp

$(TARG_EX_ff_101_MT_R):    \
		$(OBJ_EX_ff_101_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ff_101_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ff_101_MT_R): $(PROJ_EXAMPLES_DIR)\example.ff_101\example.ff_101.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.ff_101\example.ff_101.cpp

$(TARG_EX_ff_101_ST_D):    \
		$(OBJ_EX_ff_101_ST_D)\
		$(LIB_CORE_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ff_101_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ff_101_ST_D): $(PROJ_EXAMPLES_DIR)\example.ff_101\example.ff_101.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.ff_101\example.ff_101.cpp

$(TARG_EX_ff_101_ST_R):    \
		$(OBJ_EX_ff_101_ST_R)\
		$(LIB_CORE_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ff_101_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ff_101_ST_R): $(PROJ_EXAMPLES_DIR)\example.ff_101\example.ff_101.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.ff_101\example.ff_101.cpp

$(TARG_EX_ff_101_nons_MT_D):    \
		$(OBJ_EX_ff_101_nons_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ff_101_nons_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ff_101_nons_MT_D): $(PROJ_EXAMPLES_DIR)\example.ff_101.no_namespace\example.ff_101.no_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.ff_101.no_namespace\example.ff_101.no_namespace.cpp

$(TARG_EX_ff_101_nons_MT_R):    \
		$(OBJ_EX_ff_101_nons_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ff_101_nons_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ff_101_nons_MT_R): $(PROJ_EXAMPLES_DIR)\example.ff_101.no_namespace\example.ff_101.no_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.ff_101.no_namespace\example.ff_101.no_namespace.cpp

$(TARG_EX_ff_101_nons_ST_D):    \
		$(OBJ_EX_ff_101_nons_ST_D)\
		$(LIB_CORE_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ff_101_nons_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ff_101_nons_ST_D): $(PROJ_EXAMPLES_DIR)\example.ff_101.no_namespace\example.ff_101.no_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.ff_101.no_namespace\example.ff_101.no_namespace.cpp

$(TARG_EX_ff_101_nons_ST_R):    \
		$(OBJ_EX_ff_101_nons_ST_R)\
		$(LIB_CORE_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ff_101_nons_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ff_101_nons_ST_R): $(PROJ_EXAMPLES_DIR)\example.ff_101.no_namespace\example.ff_101.no_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.ff_101.no_namespace\example.ff_101.no_namespace.cpp

$(TARG_EX_flush_MT_D):    \
		$(OBJ_EX_flush_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_flush_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_flush_MT_D): $(PROJ_EXAMPLES_DIR)\example.flush\example.flush.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.flush\example.flush.cpp

$(TARG_EX_flush_MT_R):    \
		$(OBJ_EX_flush_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_flush_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_flush_MT_R): $(PROJ_EXAMPLES_DIR)\example.flush\example.flush.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.flush\example.flush.cpp

$(TARG_EX_flush_ST_D):    \
		$(OBJ_EX_flush_ST_D)\
		$(LIB_CORE_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_flush_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_flush_ST_D): $(PROJ_EXAMPLES_DIR)\example.flush\example.flush.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.flush\example.flush.cpp

$(TARG_EX_flush_ST_R):    \
		$(OBJ_EX_flush_ST_R)\
		$(LIB_CORE_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_flush_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_flush_ST_R): $(PROJ_EXAMPLES_DIR)\example.flush\example.flush.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.flush\example.flush.cpp

$(TARG_EX_ins_hex_MT_D):    \
		$(OBJ_EX_ins_hex_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ins_hex_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ins_hex_MT_D): $(PROJ_EXAMPLES_DIR)\example.inserter.hex\example.inserter.hex.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.inserter.hex\example.inserter.hex.cpp

$(TARG_EX_ins_hex_MT_R):    \
		$(OBJ_EX_ins_hex_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ins_hex_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ins_hex_MT_R): $(PROJ_EXAMPLES_DIR)\example.inserter.hex\example.inserter.hex.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.inserter.hex\example.inserter.hex.cpp

$(TARG_EX_ins_hex_ST_D):    \
		$(OBJ_EX_ins_hex_ST_D)\
		$(LIB_CORE_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ins_hex_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ins_hex_ST_D): $(PROJ_EXAMPLES_DIR)\example.inserter.hex\example.inserter.hex.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.inserter.hex\example.inserter.hex.cpp

$(TARG_EX_ins_hex_ST_R):    \
		$(OBJ_EX_ins_hex_ST_R)\
		$(LIB_CORE_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ins_hex_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ins_hex_ST_R): $(PROJ_EXAMPLES_DIR)\example.inserter.hex\example.inserter.hex.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.inserter.hex\example.inserter.hex.cpp

$(TARG_EX_ins_integers_MT_D):    \
		$(OBJ_EX_ins_integers_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ins_integers_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ins_integers_MT_D): $(PROJ_EXAMPLES_DIR)\example.inserter.integers\example.inserter.integers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.inserter.integers\example.inserter.integers.cpp

$(TARG_EX_ins_integers_MT_R):    \
		$(OBJ_EX_ins_integers_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ins_integers_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ins_integers_MT_R): $(PROJ_EXAMPLES_DIR)\example.inserter.integers\example.inserter.integers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.inserter.integers\example.inserter.integers.cpp

$(TARG_EX_ins_integers_ST_D):    \
		$(OBJ_EX_ins_integers_ST_D)\
		$(LIB_CORE_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ins_integers_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ins_integers_ST_D): $(PROJ_EXAMPLES_DIR)\example.inserter.integers\example.inserter.integers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.inserter.integers\example.inserter.integers.cpp

$(TARG_EX_ins_integers_ST_R):    \
		$(OBJ_EX_ins_integers_ST_R)\
		$(LIB_CORE_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ins_integers_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ins_integers_ST_R): $(PROJ_EXAMPLES_DIR)\example.inserter.integers\example.inserter.integers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.inserter.integers\example.inserter.integers.cpp

$(TARG_EX_ins_reals_MT_D):    \
		$(OBJ_EX_ins_reals_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ins_reals_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ins_reals_MT_D): $(PROJ_EXAMPLES_DIR)\example.inserter.reals\example.inserter.reals.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.inserter.reals\example.inserter.reals.cpp

$(TARG_EX_ins_reals_MT_R):    \
		$(OBJ_EX_ins_reals_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ins_reals_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ins_reals_MT_R): $(PROJ_EXAMPLES_DIR)\example.inserter.reals\example.inserter.reals.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.inserter.reals\example.inserter.reals.cpp

$(TARG_EX_ins_reals_ST_D):    \
		$(OBJ_EX_ins_reals_ST_D)\
		$(LIB_CORE_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ins_reals_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ins_reals_ST_D): $(PROJ_EXAMPLES_DIR)\example.inserter.reals\example.inserter.reals.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.inserter.reals\example.inserter.reals.cpp

$(TARG_EX_ins_reals_ST_R):    \
		$(OBJ_EX_ins_reals_ST_R)\
		$(LIB_CORE_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ins_reals_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ins_reals_ST_R): $(PROJ_EXAMPLES_DIR)\example.inserter.reals\example.inserter.reals.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.inserter.reals\example.inserter.reals.cpp


$(TARG_EX_ins_WLIs_MT_D):    \
		$(OBJ_EX_ins_WLIs_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ins_WLIs_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ins_WLIs_MT_D): $(PROJ_EXAMPLES_DIR)\example.inserter.integers.WindowsLargeIntegers\example.inserter.integers.WindowsLargeIntegers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.inserter.integers.WindowsLargeIntegers\example.inserter.integers.WindowsLargeIntegers.cpp

$(TARG_EX_ins_WLIs_MT_R):    \
		$(OBJ_EX_ins_WLIs_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ins_WLIs_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ins_WLIs_MT_R): $(PROJ_EXAMPLES_DIR)\example.inserter.integers.WindowsLargeIntegers\example.inserter.integers.WindowsLargeIntegers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.inserter.integers.WindowsLargeIntegers\example.inserter.integers.WindowsLargeIntegers.cpp

$(TARG_EX_ins_WLIs_ST_D):    \
		$(OBJ_EX_ins_WLIs_ST_D)\
		$(LIB_CORE_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ins_WLIs_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ins_WLIs_ST_D): $(PROJ_EXAMPLES_DIR)\example.inserter.integers.WindowsLargeIntegers\example.inserter.integers.WindowsLargeIntegers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.inserter.integers.WindowsLargeIntegers\example.inserter.integers.WindowsLargeIntegers.cpp

$(TARG_EX_ins_WLIs_ST_R):    \
		$(OBJ_EX_ins_WLIs_ST_R)\
		$(LIB_CORE_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ins_WLIs_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ins_WLIs_ST_R): $(PROJ_EXAMPLES_DIR)\example.inserter.integers.WindowsLargeIntegers\example.inserter.integers.WindowsLargeIntegers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.inserter.integers.WindowsLargeIntegers\example.inserter.integers.WindowsLargeIntegers.cpp


$(TARG_EX_itr_fmt_MT_D):    \
		$(OBJ_EX_itr_fmt_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARG_BITBUCKET_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_itr_fmt_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_itr_fmt_MT_D): $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp

$(TARG_EX_itr_fmt_MT_R):    \
		$(OBJ_EX_itr_fmt_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARG_BITBUCKET_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_itr_fmt_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_itr_fmt_MT_R): $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp

$(TARG_EX_itr_fmt_ST_D):    \
		$(OBJ_EX_itr_fmt_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARG_BITBUCKET_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_itr_fmt_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_itr_fmt_ST_D): $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp

$(TARG_EX_itr_fmt_ST_R):    \
		$(OBJ_EX_itr_fmt_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARG_BITBUCKET_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_itr_fmt_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_itr_fmt_ST_R): $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp

$(TARG_EX_ovld2_filt_MT_D):    \
		$(OBJ_EX_ovld2_filt_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ovld2_filt_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ovld2_filt_MT_D): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.filter_type\example.overload.2.custom_type.filter_type.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.filter_type\example.overload.2.custom_type.filter_type.cpp

$(TARG_EX_ovld2_filt_MT_R):    \
		$(OBJ_EX_ovld2_filt_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ovld2_filt_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ovld2_filt_MT_R): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.filter_type\example.overload.2.custom_type.filter_type.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.filter_type\example.overload.2.custom_type.filter_type.cpp

$(TARG_EX_ovld2_filt_ST_D):    \
		$(OBJ_EX_ovld2_filt_ST_D)\
		$(LIB_CORE_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ovld2_filt_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ovld2_filt_ST_D): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.filter_type\example.overload.2.custom_type.filter_type.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.filter_type\example.overload.2.custom_type.filter_type.cpp

$(TARG_EX_ovld2_filt_ST_R):    \
		$(OBJ_EX_ovld2_filt_ST_R)\
		$(LIB_CORE_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ovld2_filt_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ovld2_filt_ST_R): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.filter_type\example.overload.2.custom_type.filter_type.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.filter_type\example.overload.2.custom_type.filter_type.cpp


$(TARG_EX_ovld2_ins_MT_D):    \
		$(OBJ_EX_ovld2_ins_MT_D)\
		$(PROJ_BUNDLES_DIR)\superhero.properties\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ovld2_ins_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ovld2_ins_MT_D): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.inserter\example.overload.2.custom_type.inserter.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.inserter\example.overload.2.custom_type.inserter.cpp

$(TARG_EX_ovld2_ins_MT_R):    \
		$(OBJ_EX_ovld2_ins_MT_R)\
		$(PROJ_BUNDLES_DIR)\superhero.properties\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ovld2_ins_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ovld2_ins_MT_R): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.inserter\example.overload.2.custom_type.inserter.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.inserter\example.overload.2.custom_type.inserter.cpp

$(TARG_EX_ovld2_ins_ST_D):    \
		$(OBJ_EX_ovld2_ins_ST_D)\
		$(PROJ_BUNDLES_DIR)\superhero.properties\
		$(LIB_CORE_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ovld2_ins_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ovld2_ins_ST_D): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.inserter\example.overload.2.custom_type.inserter.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.inserter\example.overload.2.custom_type.inserter.cpp

$(TARG_EX_ovld2_ins_ST_R):    \
		$(OBJ_EX_ovld2_ins_ST_R)\
		$(PROJ_BUNDLES_DIR)\superhero.properties\
		$(LIB_CORE_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ovld2_ins_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ovld2_ins_ST_R): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.inserter\example.overload.2.custom_type.inserter.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.inserter\example.overload.2.custom_type.inserter.cpp

$(TARG_EX_ovld2_sas_MT_D):    \
		$(OBJ_EX_ovld2_sas_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ovld2_sas_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ovld2_sas_MT_D): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.string_access_shims\example.overload.2.custom_type.string_access_shims.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.string_access_shims\example.overload.2.custom_type.string_access_shims.cpp

$(TARG_EX_ovld2_sas_MT_R):    \
		$(OBJ_EX_ovld2_sas_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ovld2_sas_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ovld2_sas_MT_R): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.string_access_shims\example.overload.2.custom_type.string_access_shims.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.string_access_shims\example.overload.2.custom_type.string_access_shims.cpp

$(TARG_EX_ovld2_sas_ST_D):    \
		$(OBJ_EX_ovld2_sas_ST_D)\
		$(LIB_CORE_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ovld2_sas_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ovld2_sas_ST_D): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.string_access_shims\example.overload.2.custom_type.string_access_shims.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.string_access_shims\example.overload.2.custom_type.string_access_shims.cpp

$(TARG_EX_ovld2_sas_ST_R):    \
		$(OBJ_EX_ovld2_sas_ST_R)\
		$(LIB_CORE_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ovld2_sas_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ovld2_sas_ST_R): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.string_access_shims\example.overload.2.custom_type.string_access_shims.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.string_access_shims\example.overload.2.custom_type.string_access_shims.cpp

$(TARG_EX_ovld3_fpcol_MT_D):    \
		$(OBJ_EX_ovld3_fpcol_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARG_BITBUCKET_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ovld3_fpcol_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ovld3_fpcol_MT_D): $(PROJ_EXAMPLES_DIR)\example.overload.3.floatingpoint_columns\example.overload.3.floatingpoint_columns.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.3.floatingpoint_columns\example.overload.3.floatingpoint_columns.cpp

$(TARG_EX_ovld3_fpcol_MT_R):    \
		$(OBJ_EX_ovld3_fpcol_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARG_BITBUCKET_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ovld3_fpcol_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ovld3_fpcol_MT_R): $(PROJ_EXAMPLES_DIR)\example.overload.3.floatingpoint_columns\example.overload.3.floatingpoint_columns.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.3.floatingpoint_columns\example.overload.3.floatingpoint_columns.cpp

$(TARG_EX_ovld3_fpcol_ST_D):    \
		$(OBJ_EX_ovld3_fpcol_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARG_BITBUCKET_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ovld3_fpcol_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ovld3_fpcol_ST_D): $(PROJ_EXAMPLES_DIR)\example.overload.3.floatingpoint_columns\example.overload.3.floatingpoint_columns.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.3.floatingpoint_columns\example.overload.3.floatingpoint_columns.cpp

$(TARG_EX_ovld3_fpcol_ST_R):    \
		$(OBJ_EX_ovld3_fpcol_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARG_BITBUCKET_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ovld3_fpcol_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ovld3_fpcol_ST_R): $(PROJ_EXAMPLES_DIR)\example.overload.3.floatingpoint_columns\example.overload.3.floatingpoint_columns.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.3.floatingpoint_columns\example.overload.3.floatingpoint_columns.cpp

$(TARG_EX_ovld3_tabs_MT_D):    \
		$(OBJ_EX_ovld3_tabs_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARG_BITBUCKET_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ovld3_tabs_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ovld3_tabs_MT_D): $(PROJ_EXAMPLES_DIR)\example.overload.3.tabulations\example.overload.3.tabulations.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.3.tabulations\example.overload.3.tabulations.cpp

$(TARG_EX_ovld3_tabs_MT_R):    \
		$(OBJ_EX_ovld3_tabs_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARG_BITBUCKET_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ovld3_tabs_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ovld3_tabs_MT_R): $(PROJ_EXAMPLES_DIR)\example.overload.3.tabulations\example.overload.3.tabulations.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.3.tabulations\example.overload.3.tabulations.cpp

$(TARG_EX_ovld3_tabs_ST_D):    \
		$(OBJ_EX_ovld3_tabs_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARG_BITBUCKET_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ovld3_tabs_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ovld3_tabs_ST_D): $(PROJ_EXAMPLES_DIR)\example.overload.3.tabulations\example.overload.3.tabulations.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.3.tabulations\example.overload.3.tabulations.cpp

$(TARG_EX_ovld3_tabs_ST_R):    \
		$(OBJ_EX_ovld3_tabs_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARG_BITBUCKET_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ovld3_tabs_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ovld3_tabs_ST_R): $(PROJ_EXAMPLES_DIR)\example.overload.3.tabulations\example.overload.3.tabulations.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.3.tabulations\example.overload.3.tabulations.cpp

$(TARG_EX_ovld3_svrlg_MT_D):    \
		$(OBJ_EX_ovld3_svrlg_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARG_BITBUCKET_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ovld3_svrlg_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ovld3_svrlg_MT_D): $(PROJ_EXAMPLES_DIR)\example.overload.3.server_log\example.overload.3.server_log.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.3.server_log\example.overload.3.server_log.cpp

$(TARG_EX_ovld3_svrlg_MT_R):    \
		$(OBJ_EX_ovld3_svrlg_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARG_BITBUCKET_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ovld3_svrlg_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ovld3_svrlg_MT_R): $(PROJ_EXAMPLES_DIR)\example.overload.3.server_log\example.overload.3.server_log.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.3.server_log\example.overload.3.server_log.cpp

$(TARG_EX_ovld3_svrlg_ST_D):    \
		$(OBJ_EX_ovld3_svrlg_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARG_BITBUCKET_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ovld3_svrlg_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ovld3_svrlg_ST_D): $(PROJ_EXAMPLES_DIR)\example.overload.3.server_log\example.overload.3.server_log.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.3.server_log\example.overload.3.server_log.cpp

$(TARG_EX_ovld3_svrlg_ST_R):    \
		$(OBJ_EX_ovld3_svrlg_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARG_BITBUCKET_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ovld3_svrlg_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ovld3_svrlg_ST_R): $(PROJ_EXAMPLES_DIR)\example.overload.3.server_log\example.overload.3.server_log.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.3.server_log\example.overload.3.server_log.cpp

$(TARG_EX_ovld3_rcins_MT_D):    \
		$(OBJ_EX_ovld3_rcins_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARG_BITBUCKET_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ovld3_rcins_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ovld3_rcins_MT_D): $(PROJ_EXAMPLES_DIR)\example.overload.3.record_insert\example.overload.3.record_insert.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.3.record_insert\example.overload.3.record_insert.cpp

$(TARG_EX_ovld3_rcins_MT_R):    \
		$(OBJ_EX_ovld3_rcins_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARG_BITBUCKET_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ovld3_rcins_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ovld3_rcins_MT_R): $(PROJ_EXAMPLES_DIR)\example.overload.3.record_insert\example.overload.3.record_insert.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.3.record_insert\example.overload.3.record_insert.cpp

$(TARG_EX_ovld3_rcins_ST_D):    \
		$(OBJ_EX_ovld3_rcins_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARG_BITBUCKET_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ovld3_rcins_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ovld3_rcins_ST_D): $(PROJ_EXAMPLES_DIR)\example.overload.3.record_insert\example.overload.3.record_insert.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.3.record_insert\example.overload.3.record_insert.cpp

$(TARG_EX_ovld3_rcins_ST_R):    \
		$(OBJ_EX_ovld3_rcins_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARG_BITBUCKET_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ovld3_rcins_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ovld3_rcins_ST_R): $(PROJ_EXAMPLES_DIR)\example.overload.3.record_insert\example.overload.3.record_insert.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.overload.3.record_insert\example.overload.3.record_insert.cpp

$(TARG_EX_pad_hash_MT_D):    \
		$(OBJ_EX_pad_hash_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARG_BITBUCKET_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_pad_hash_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_pad_hash_MT_D): $(PROJ_EXAMPLES_DIR)\example.pad.hash\example.pad.hash.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.pad.hash\example.pad.hash.cpp

$(TARG_EX_pad_hash_MT_R):    \
		$(OBJ_EX_pad_hash_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARG_BITBUCKET_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_pad_hash_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_pad_hash_MT_R): $(PROJ_EXAMPLES_DIR)\example.pad.hash\example.pad.hash.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.pad.hash\example.pad.hash.cpp

$(TARG_EX_pad_hash_ST_D):    \
		$(OBJ_EX_pad_hash_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARG_BITBUCKET_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_pad_hash_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_pad_hash_ST_D): $(PROJ_EXAMPLES_DIR)\example.pad.hash\example.pad.hash.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.pad.hash\example.pad.hash.cpp

$(TARG_EX_pad_hash_ST_R):    \
		$(OBJ_EX_pad_hash_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARG_BITBUCKET_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_pad_hash_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_pad_hash_ST_R): $(PROJ_EXAMPLES_DIR)\example.pad.hash\example.pad.hash.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.pad.hash\example.pad.hash.cpp

$(TARG_EX_sink_cstr_MT_D):    \
		$(OBJ_EX_sink_cstr_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARG_BITBUCKET_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_sink_cstr_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_sink_cstr_MT_D): $(PROJ_EXAMPLES_DIR)\example.sink.c_string\example.sink.c_string.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.sink.c_string\example.sink.c_string.cpp

$(TARG_EX_sink_cstr_MT_R):    \
		$(OBJ_EX_sink_cstr_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARG_BITBUCKET_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_sink_cstr_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_sink_cstr_MT_R): $(PROJ_EXAMPLES_DIR)\example.sink.c_string\example.sink.c_string.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.sink.c_string\example.sink.c_string.cpp

$(TARG_EX_sink_cstr_ST_D):    \
		$(OBJ_EX_sink_cstr_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARG_BITBUCKET_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_sink_cstr_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_sink_cstr_ST_D): $(PROJ_EXAMPLES_DIR)\example.sink.c_string\example.sink.c_string.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.sink.c_string\example.sink.c_string.cpp

$(TARG_EX_sink_cstr_ST_R):    \
		$(OBJ_EX_sink_cstr_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARG_BITBUCKET_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_sink_cstr_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_sink_cstr_ST_R): $(PROJ_EXAMPLES_DIR)\example.sink.c_string\example.sink.c_string.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.sink.c_string\example.sink.c_string.cpp

$(TARG_EX_sink_ODS_MT_D):    \
		$(OBJ_EX_sink_ODS_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_sink_ODS_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_sink_ODS_MT_D): $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp

$(TARG_EX_sink_ODS_MT_R):    \
		$(OBJ_EX_sink_ODS_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_sink_ODS_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_sink_ODS_MT_R): $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp

$(TARG_EX_sink_ODS_ST_D):    \
		$(OBJ_EX_sink_ODS_ST_D)\
		$(LIB_CORE_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_sink_ODS_ST_D)\
		$(LIB_CORE_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_sink_ODS_ST_D): $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp

$(TARG_EX_sink_ODS_ST_R):    \
		$(OBJ_EX_sink_ODS_ST_R)\
		$(LIB_CORE_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_sink_ODS_ST_R)\
		$(LIB_CORE_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_sink_ODS_ST_R): $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp

##################################################
# Tests

##############################
# Component Tests

$(TARG_TEST_COMP_snk_a_b_MT_D):    \
		$(OBJ_TEST_COMP_snk_a_b_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_COMP_snk_a_b_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_snk_a_b_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp

$(TARG_TEST_COMP_snk_a_b_MT_R):    \
		$(OBJ_TEST_COMP_snk_a_b_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_COMP_snk_a_b_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_snk_a_b_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp

$(TARG_TEST_COMP_snk_a_b_ST_D):    \
		$(OBJ_TEST_COMP_snk_a_b_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_COMP_snk_a_b_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_COMP_snk_a_b_ST_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp

$(TARG_TEST_COMP_snk_a_b_ST_R):    \
		$(OBJ_TEST_COMP_snk_a_b_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_COMP_snk_a_b_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_COMP_snk_a_b_ST_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp

$(TARG_TEST_COMP_file_MT_D):    \
		$(OBJ_TEST_COMP_file_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_COMP_file_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_file_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp

$(TARG_TEST_COMP_file_MT_R):    \
		$(OBJ_TEST_COMP_file_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_COMP_file_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_file_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp

$(TARG_TEST_COMP_file_ST_D):    \
		$(OBJ_TEST_COMP_file_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_COMP_file_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_COMP_file_ST_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp

$(TARG_TEST_COMP_file_ST_R):    \
		$(OBJ_TEST_COMP_file_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_COMP_file_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_COMP_file_ST_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp

$(TARG_TEST_COMP_fmt_sink_MT_D):    \
		$(OBJ_TEST_COMP_fmt_sink_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_COMP_fmt_sink_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_fmt_sink_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp

$(TARG_TEST_COMP_fmt_sink_MT_R):    \
		$(OBJ_TEST_COMP_fmt_sink_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_COMP_fmt_sink_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_fmt_sink_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp

$(TARG_TEST_COMP_fmt_sink_ST_D):    \
		$(OBJ_TEST_COMP_fmt_sink_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_COMP_fmt_sink_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_COMP_fmt_sink_ST_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp

$(TARG_TEST_COMP_fmt_sink_ST_R):    \
		$(OBJ_TEST_COMP_fmt_sink_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_COMP_fmt_sink_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_COMP_fmt_sink_ST_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp

$(TARG_TEST_COMP_write_sink_MT_D):    \
		$(OBJ_TEST_COMP_write_sink_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_COMP_write_sink_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_write_sink_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp

$(TARG_TEST_COMP_write_sink_MT_R):    \
		$(OBJ_TEST_COMP_write_sink_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_COMP_write_sink_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_write_sink_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp

$(TARG_TEST_COMP_write_sink_ST_D):    \
		$(OBJ_TEST_COMP_write_sink_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_COMP_write_sink_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_COMP_write_sink_ST_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp

$(TARG_TEST_COMP_write_sink_ST_R):    \
		$(OBJ_TEST_COMP_write_sink_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_COMP_write_sink_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_COMP_write_sink_ST_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp

$(TARG_TEST_COMP_x_1_MT_D):    \
		$(OBJ_TEST_COMP_x_1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_COMP_x_1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_x_1_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp

$(TARG_TEST_COMP_x_1_MT_R):    \
		$(OBJ_TEST_COMP_x_1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_COMP_x_1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_x_1_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp

$(TARG_TEST_COMP_x_1_ST_D):    \
		$(OBJ_TEST_COMP_x_1_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_COMP_x_1_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_COMP_x_1_ST_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp

$(TARG_TEST_COMP_x_1_ST_R):    \
		$(OBJ_TEST_COMP_x_1_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_COMP_x_1_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_COMP_x_1_ST_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp

$(TARG_TEST_COMP_null_sink_MT_D):    \
		$(OBJ_TEST_COMP_null_sink_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_COMP_null_sink_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_null_sink_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp

$(TARG_TEST_COMP_null_sink_MT_R):    \
		$(OBJ_TEST_COMP_null_sink_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_COMP_null_sink_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_null_sink_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp

$(TARG_TEST_COMP_null_sink_ST_D):    \
		$(OBJ_TEST_COMP_null_sink_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_COMP_null_sink_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_COMP_null_sink_ST_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp

$(TARG_TEST_COMP_null_sink_ST_R):    \
		$(OBJ_TEST_COMP_null_sink_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_COMP_null_sink_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_COMP_null_sink_ST_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp

$(TARG_TEST_COMP_ins_hex_MT_D):    \
		$(OBJ_TEST_COMP_ins_hex_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_COMP_ins_hex_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_ins_hex_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp

$(TARG_TEST_COMP_ins_hex_MT_R):    \
		$(OBJ_TEST_COMP_ins_hex_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_COMP_ins_hex_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_ins_hex_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp

$(TARG_TEST_COMP_ins_hex_ST_D):    \
		$(OBJ_TEST_COMP_ins_hex_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_COMP_ins_hex_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_COMP_ins_hex_ST_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp

$(TARG_TEST_COMP_ins_hex_ST_R):    \
		$(OBJ_TEST_COMP_ins_hex_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_COMP_ins_hex_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_COMP_ins_hex_ST_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp

$(TARG_TEST_COMP_ins_int_MT_D):    \
		$(OBJ_TEST_COMP_ins_int_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_COMP_ins_int_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_ins_int_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp

$(TARG_TEST_COMP_ins_int_MT_R):    \
		$(OBJ_TEST_COMP_ins_int_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_COMP_ins_int_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_ins_int_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp

$(TARG_TEST_COMP_ins_int_ST_D):    \
		$(OBJ_TEST_COMP_ins_int_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_COMP_ins_int_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_COMP_ins_int_ST_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp

$(TARG_TEST_COMP_ins_int_ST_R):    \
		$(OBJ_TEST_COMP_ins_int_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_COMP_ins_int_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_COMP_ins_int_ST_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp

$(TARG_TEST_COMP_ins_real_MT_D):    \
		$(OBJ_TEST_COMP_ins_real_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_COMP_ins_real_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_ins_real_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp

$(TARG_TEST_COMP_ins_real_MT_R):    \
		$(OBJ_TEST_COMP_ins_real_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_COMP_ins_real_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_ins_real_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp

$(TARG_TEST_COMP_ins_real_ST_D):    \
		$(OBJ_TEST_COMP_ins_real_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_COMP_ins_real_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_COMP_ins_real_ST_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp

$(TARG_TEST_COMP_ins_real_ST_R):    \
		$(OBJ_TEST_COMP_ins_real_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_COMP_ins_real_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_COMP_ins_real_ST_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp

$(TARG_TEST_COMP_itr_fmt_MT_D):    \
		$(OBJ_TEST_COMP_itr_fmt_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_COMP_itr_fmt_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_itr_fmt_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp

$(TARG_TEST_COMP_itr_fmt_MT_R):    \
		$(OBJ_TEST_COMP_itr_fmt_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_COMP_itr_fmt_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_itr_fmt_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp

$(TARG_TEST_COMP_itr_fmt_ST_D):    \
		$(OBJ_TEST_COMP_itr_fmt_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_COMP_itr_fmt_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_COMP_itr_fmt_ST_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp

$(TARG_TEST_COMP_itr_fmt_ST_R):    \
		$(OBJ_TEST_COMP_itr_fmt_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_COMP_itr_fmt_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_COMP_itr_fmt_ST_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp

$(TARG_TEST_COMP_snk_ostm_MT_D):    \
		$(OBJ_TEST_COMP_snk_ostm_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_COMP_snk_ostm_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_snk_ostm_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp

$(TARG_TEST_COMP_snk_ostm_MT_R):    \
		$(OBJ_TEST_COMP_snk_ostm_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_COMP_snk_ostm_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_snk_ostm_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp

$(TARG_TEST_COMP_snk_ostm_ST_D):    \
		$(OBJ_TEST_COMP_snk_ostm_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_COMP_snk_ostm_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_COMP_snk_ostm_ST_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp

$(TARG_TEST_COMP_snk_ostm_ST_R):    \
		$(OBJ_TEST_COMP_snk_ostm_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_COMP_snk_ostm_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_COMP_snk_ostm_ST_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp

##############################
# Performance Tests

$(TARG_TEST_PERF_scen1_MT_D):    \
		$(OBJ_TEST_PERF_scen1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_PERF_scen1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_PERF_scen1_MT_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp

$(TARG_TEST_PERF_scen1_MT_R):    \
		$(OBJ_TEST_PERF_scen1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_PERF_scen1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_PERF_scen1_MT_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp

$(TARG_TEST_PERF_scen1_ST_D):    \
		$(OBJ_TEST_PERF_scen1_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_LOKI_SFMT_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_PERF_scen1_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_LOKI_SFMT_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_PERF_scen1_ST_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp

$(TARG_TEST_PERF_scen1_ST_R):    \
		$(OBJ_TEST_PERF_scen1_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_LOKI_SFMT_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_PERF_scen1_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_LOKI_SFMT_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_PERF_scen1_ST_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp

$(TARG_TEST_PERF_scen2_MT_D):    \
		$(OBJ_TEST_PERF_scen2_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_PERF_scen2_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_PERF_scen2_MT_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp

$(TARG_TEST_PERF_scen2_MT_R):    \
		$(OBJ_TEST_PERF_scen2_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_PERF_scen2_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_PERF_scen2_MT_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp

$(TARG_TEST_PERF_scen2_ST_D):    \
		$(OBJ_TEST_PERF_scen2_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_LOKI_SFMT_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_PERF_scen2_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_LOKI_SFMT_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_PERF_scen2_ST_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp

$(TARG_TEST_PERF_scen2_ST_R):    \
		$(OBJ_TEST_PERF_scen2_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_LOKI_SFMT_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_PERF_scen2_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_LOKI_SFMT_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_PERF_scen2_ST_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp

$(TARG_TEST_PERF_scen3_MT_D):    \
		$(OBJ_TEST_PERF_scen3_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_PERF_scen3_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_PERF_scen3_MT_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp

$(TARG_TEST_PERF_scen3_MT_R):    \
		$(OBJ_TEST_PERF_scen3_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_PERF_scen3_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_PERF_scen3_MT_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp

$(TARG_TEST_PERF_scen3_ST_D):    \
		$(OBJ_TEST_PERF_scen3_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_LOKI_SFMT_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_PERF_scen3_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_LOKI_SFMT_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_PERF_scen3_ST_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp

$(TARG_TEST_PERF_scen3_ST_R):    \
		$(OBJ_TEST_PERF_scen3_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_LOKI_SFMT_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_PERF_scen3_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_LOKI_SFMT_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_PERF_scen3_ST_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp

$(TARG_TEST_PERF_scen4_MT_D):    \
		$(OBJ_TEST_PERF_scen4_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_PERF_scen4_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_PERF_scen4_MT_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp

$(TARG_TEST_PERF_scen4_MT_R):    \
		$(OBJ_TEST_PERF_scen4_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_PERF_scen4_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_PERF_scen4_MT_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp

$(TARG_TEST_PERF_scen4_ST_D):    \
		$(OBJ_TEST_PERF_scen4_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_LOKI_SFMT_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_PERF_scen4_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_LOKI_SFMT_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_PERF_scen4_ST_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp

$(TARG_TEST_PERF_scen4_ST_R):    \
		$(OBJ_TEST_PERF_scen4_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_LOKI_SFMT_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_PERF_scen4_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_LOKI_SFMT_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_PERF_scen4_ST_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp

$(TARG_TEST_PERF_scen5_MT_D):    \
		$(OBJ_TEST_PERF_scen5_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_PERF_scen5_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_PERF_scen5_MT_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp

$(TARG_TEST_PERF_scen5_MT_R):    \
		$(OBJ_TEST_PERF_scen5_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_PERF_scen5_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_PERF_scen5_MT_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp

$(TARG_TEST_PERF_scen5_ST_D):    \
		$(OBJ_TEST_PERF_scen5_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_LOKI_SFMT_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_PERF_scen5_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_LOKI_SFMT_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_PERF_scen5_ST_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp

$(TARG_TEST_PERF_scen5_ST_R):    \
		$(OBJ_TEST_PERF_scen5_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_LOKI_SFMT_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_PERF_scen5_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_LOKI_SFMT_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_PERF_scen5_ST_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp

$(TARG_TEST_PERF_scen6_MT_D):    \
		$(OBJ_TEST_PERF_scen6_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_PERF_scen6_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_PERF_scen6_MT_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp

$(TARG_TEST_PERF_scen6_MT_R):    \
		$(OBJ_TEST_PERF_scen6_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_PERF_scen6_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_PERF_scen6_MT_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp

$(TARG_TEST_PERF_scen6_ST_D):    \
		$(OBJ_TEST_PERF_scen6_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_LOKI_SFMT_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_PERF_scen6_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_LOKI_SFMT_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_PERF_scen6_ST_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp

$(TARG_TEST_PERF_scen6_ST_R):    \
		$(OBJ_TEST_PERF_scen6_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_LOKI_SFMT_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_PERF_scen6_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_LOKI_SFMT_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_PERF_scen6_ST_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp

$(TARG_TEST_PERF_scen7_MT_D):    \
		$(OBJ_TEST_PERF_scen7_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_PERF_scen7_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_PERF_scen7_MT_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp

$(TARG_TEST_PERF_scen7_MT_R):    \
		$(OBJ_TEST_PERF_scen7_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_PERF_scen7_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_PERF_scen7_MT_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp

$(TARG_TEST_PERF_scen7_ST_D):    \
		$(OBJ_TEST_PERF_scen7_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_LOKI_SFMT_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_PERF_scen7_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_LOKI_SFMT_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_PERF_scen7_ST_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp

$(TARG_TEST_PERF_scen7_ST_R):    \
		$(OBJ_TEST_PERF_scen7_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_LOKI_SFMT_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_PERF_scen7_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_LOKI_SFMT_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_PERF_scen7_ST_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp

ifdef BOOST
$(TARG_TEST_PERF_scen8_MT_D):    \
		$(OBJ_TEST_PERF_scen8_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_PERF_scen8_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_PERF_scen8_MT_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp

$(TARG_TEST_PERF_scen8_MT_R):    \
		$(OBJ_TEST_PERF_scen8_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_PERF_scen8_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_PERF_scen8_MT_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp

$(TARG_TEST_PERF_scen8_ST_D):    \
		$(OBJ_TEST_PERF_scen8_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_LOKI_SFMT_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_PERF_scen8_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_LOKI_SFMT_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_PERF_scen8_ST_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp

$(TARG_TEST_PERF_scen8_ST_R):    \
		$(OBJ_TEST_PERF_scen8_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_LOKI_SFMT_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_PERF_scen8_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_LOKI_SFMT_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_PERF_scen8_ST_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp

endif # BOOST
##############################
# Scratch Tests

$(TARG_TEST_SCRT_file_MT_D):    \
		$(OBJ_TEST_SCRT_file_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_SCRT_file_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_SCRT_file_MT_D): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp

$(TARG_TEST_SCRT_file_MT_R):    \
		$(OBJ_TEST_SCRT_file_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_SCRT_file_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_SCRT_file_MT_R): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp

$(TARG_TEST_SCRT_file_ST_D):    \
		$(OBJ_TEST_SCRT_file_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_SCRT_file_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_SCRT_file_ST_D): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp

$(TARG_TEST_SCRT_file_ST_R):    \
		$(OBJ_TEST_SCRT_file_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_SCRT_file_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_SCRT_file_ST_R): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp

$(TARG_TEST_SCRT_speech_MT_D):    \
		$(OBJ_TEST_SCRT_speech_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_SCRT_speech_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_SCRT_speech_MT_D): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp

$(TARG_TEST_SCRT_speech_MT_R):    \
		$(OBJ_TEST_SCRT_speech_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_SCRT_speech_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_SCRT_speech_MT_R): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp

$(TARG_TEST_SCRT_speech_ST_D):    \
		$(OBJ_TEST_SCRT_speech_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_SCRT_speech_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_SCRT_speech_ST_D): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp

$(TARG_TEST_SCRT_speech_ST_R):    \
		$(OBJ_TEST_SCRT_speech_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_SCRT_speech_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_SCRT_speech_ST_R): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp

##############################
# Unit Tests


$(TARG_TEST_UNIT_api_acsllen_MT_D):    \
		$(OBJ_TEST_UNIT_api_acsllen_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_api_acsllen_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_api_acsllen_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp

$(TARG_TEST_UNIT_api_acsllen_MT_R):    \
		$(OBJ_TEST_UNIT_api_acsllen_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_api_acsllen_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_api_acsllen_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp

$(TARG_TEST_UNIT_api_acsllen_ST_D):    \
		$(OBJ_TEST_UNIT_api_acsllen_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_api_acsllen_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_api_acsllen_ST_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp

$(TARG_TEST_UNIT_api_acsllen_ST_R):    \
		$(OBJ_TEST_UNIT_api_acsllen_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_api_acsllen_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_api_acsllen_ST_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp

$(TARG_TEST_UNIT_api_crlf_MT_D):    \
		$(OBJ_TEST_UNIT_api_crlf_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_api_crlf_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_api_crlf_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp

$(TARG_TEST_UNIT_api_crlf_MT_R):    \
		$(OBJ_TEST_UNIT_api_crlf_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_api_crlf_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_api_crlf_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp

$(TARG_TEST_UNIT_api_crlf_ST_D):    \
		$(OBJ_TEST_UNIT_api_crlf_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_api_crlf_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_api_crlf_ST_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp

$(TARG_TEST_UNIT_api_crlf_ST_R):    \
		$(OBJ_TEST_UNIT_api_crlf_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_api_crlf_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_api_crlf_ST_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp

$(TARG_TEST_UNIT_api_flrpl_MT_D):    \
		$(OBJ_TEST_UNIT_api_flrpl_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_api_flrpl_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_api_flrpl_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp

$(TARG_TEST_UNIT_api_flrpl_MT_R):    \
		$(OBJ_TEST_UNIT_api_flrpl_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_api_flrpl_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_api_flrpl_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp

$(TARG_TEST_UNIT_api_flrpl_ST_D):    \
		$(OBJ_TEST_UNIT_api_flrpl_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_api_flrpl_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_api_flrpl_ST_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp

$(TARG_TEST_UNIT_api_flrpl_ST_R):    \
		$(OBJ_TEST_UNIT_api_flrpl_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_api_flrpl_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_api_flrpl_ST_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp

$(TARG_TEST_UNIT_api_init_MT_D):    \
		$(OBJ_TEST_UNIT_api_init_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_api_init_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_api_init_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp

$(TARG_TEST_UNIT_api_init_MT_R):    \
		$(OBJ_TEST_UNIT_api_init_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_api_init_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_api_init_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp

$(TARG_TEST_UNIT_api_init_ST_D):    \
		$(OBJ_TEST_UNIT_api_init_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_api_init_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_api_init_ST_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp

$(TARG_TEST_UNIT_api_init_ST_R):    \
		$(OBJ_TEST_UNIT_api_init_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_api_init_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_api_init_ST_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp

$(TARG_TEST_UNIT_api_lkptrn_MT_D):    \
		$(OBJ_TEST_UNIT_api_lkptrn_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_api_lkptrn_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_api_lkptrn_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp

$(TARG_TEST_UNIT_api_lkptrn_MT_R):    \
		$(OBJ_TEST_UNIT_api_lkptrn_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_api_lkptrn_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_api_lkptrn_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp

$(TARG_TEST_UNIT_api_lkptrn_ST_D):    \
		$(OBJ_TEST_UNIT_api_lkptrn_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_api_lkptrn_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_api_lkptrn_ST_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp

$(TARG_TEST_UNIT_api_lkptrn_ST_R):    \
		$(OBJ_TEST_UNIT_api_lkptrn_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_api_lkptrn_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_api_lkptrn_ST_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp

$(TARG_TEST_UNIT_api_prsrpl_MT_D):    \
		$(OBJ_TEST_UNIT_api_prsrpl_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_api_prsrpl_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_api_prsrpl_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp

$(TARG_TEST_UNIT_api_prsrpl_MT_R):    \
		$(OBJ_TEST_UNIT_api_prsrpl_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_api_prsrpl_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_api_prsrpl_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp

$(TARG_TEST_UNIT_api_prsrpl_ST_D):    \
		$(OBJ_TEST_UNIT_api_prsrpl_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_api_prsrpl_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_api_prsrpl_ST_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp

$(TARG_TEST_UNIT_api_prsrpl_ST_R):    \
		$(OBJ_TEST_UNIT_api_prsrpl_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_api_prsrpl_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_api_prsrpl_ST_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp

$(TARG_TEST_UNIT_api_illfmdh_MT_D):    \
		$(OBJ_TEST_UNIT_api_illfmdh_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_api_illfmdh_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_api_illfmdh_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp

$(TARG_TEST_UNIT_api_illfmdh_MT_R):    \
		$(OBJ_TEST_UNIT_api_illfmdh_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_api_illfmdh_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_api_illfmdh_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp

$(TARG_TEST_UNIT_api_illfmdh_ST_D):    \
		$(OBJ_TEST_UNIT_api_illfmdh_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_api_illfmdh_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_api_illfmdh_ST_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp

$(TARG_TEST_UNIT_api_illfmdh_ST_R):    \
		$(OBJ_TEST_UNIT_api_illfmdh_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_api_illfmdh_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_api_illfmdh_ST_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp

$(TARG_TEST_UNIT_api_msmtchh_MT_D):    \
		$(OBJ_TEST_UNIT_api_msmtchh_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_api_msmtchh_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_api_msmtchh_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp

$(TARG_TEST_UNIT_api_msmtchh_MT_R):    \
		$(OBJ_TEST_UNIT_api_msmtchh_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_api_msmtchh_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_api_msmtchh_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp

$(TARG_TEST_UNIT_api_msmtchh_ST_D):    \
		$(OBJ_TEST_UNIT_api_msmtchh_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_api_msmtchh_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_api_msmtchh_ST_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp

$(TARG_TEST_UNIT_api_msmtchh_ST_R):    \
		$(OBJ_TEST_UNIT_api_msmtchh_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_api_msmtchh_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_api_msmtchh_ST_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp

$(TARG_TEST_UNIT_bndl_winini_MT_D):    \
		$(OBJ_TEST_UNIT_bndl_winini_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_bndl_winini_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_bndl_winini_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp

$(TARG_TEST_UNIT_bndl_winini_MT_R):    \
		$(OBJ_TEST_UNIT_bndl_winini_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_bndl_winini_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_bndl_winini_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp

$(TARG_TEST_UNIT_bndl_winini_ST_D):    \
		$(OBJ_TEST_UNIT_bndl_winini_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_bndl_winini_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_bndl_winini_ST_D): $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp

$(TARG_TEST_UNIT_bndl_winini_ST_R):    \
		$(OBJ_TEST_UNIT_bndl_winini_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_bndl_winini_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_bndl_winini_ST_R): $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp

$(TARG_TEST_UNIT_snk_ods_MT_D):    \
		$(OBJ_TEST_UNIT_snk_ods_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_snk_ods_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_snk_ods_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp

$(TARG_TEST_UNIT_snk_ods_MT_R):    \
		$(OBJ_TEST_UNIT_snk_ods_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_snk_ods_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_snk_ods_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp

$(TARG_TEST_UNIT_snk_ods_ST_D):    \
		$(OBJ_TEST_UNIT_snk_ods_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_snk_ods_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_snk_ods_ST_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp

$(TARG_TEST_UNIT_snk_ods_ST_R):    \
		$(OBJ_TEST_UNIT_snk_ods_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_snk_ods_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_snk_ods_ST_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp

$(TARG_TEST_UNIT_fmt_stdfl_MT_D):    \
		$(OBJ_TEST_UNIT_fmt_stdfl_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_fmt_stdfl_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_fmt_stdfl_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp

$(TARG_TEST_UNIT_fmt_stdfl_MT_R):    \
		$(OBJ_TEST_UNIT_fmt_stdfl_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_fmt_stdfl_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_fmt_stdfl_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp

$(TARG_TEST_UNIT_fmt_stdfl_ST_D):    \
		$(OBJ_TEST_UNIT_fmt_stdfl_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_fmt_stdfl_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_fmt_stdfl_ST_D): $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp

$(TARG_TEST_UNIT_fmt_stdfl_ST_R):    \
		$(OBJ_TEST_UNIT_fmt_stdfl_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_fmt_stdfl_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_fmt_stdfl_ST_R): $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp

$(TARG_TEST_UNIT_ins_ch_MT_D):    \
		$(OBJ_TEST_UNIT_ins_ch_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_ins_ch_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_ins_ch_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp

$(TARG_TEST_UNIT_ins_ch_MT_R):    \
		$(OBJ_TEST_UNIT_ins_ch_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_ins_ch_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_ins_ch_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp

$(TARG_TEST_UNIT_ins_ch_ST_D):    \
		$(OBJ_TEST_UNIT_ins_ch_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_ins_ch_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_ins_ch_ST_D): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp

$(TARG_TEST_UNIT_ins_ch_ST_R):    \
		$(OBJ_TEST_UNIT_ins_ch_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_ins_ch_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_ins_ch_ST_R): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp

$(TARG_TEST_UNIT_ins_i_MT_D):    \
		$(OBJ_TEST_UNIT_ins_i_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_ins_i_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_ins_i_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp

$(TARG_TEST_UNIT_ins_i_MT_R):    \
		$(OBJ_TEST_UNIT_ins_i_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_ins_i_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_ins_i_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp

$(TARG_TEST_UNIT_ins_i_ST_D):    \
		$(OBJ_TEST_UNIT_ins_i_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_ins_i_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_ins_i_ST_D): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp

$(TARG_TEST_UNIT_ins_i_ST_R):    \
		$(OBJ_TEST_UNIT_ins_i_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_ins_i_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_ins_i_ST_R): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp

$(TARG_TEST_UNIT_shim_fi_MT_D):    \
		$(OBJ_TEST_UNIT_shim_fi_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_shim_fi_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_shim_fi_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp

$(TARG_TEST_UNIT_shim_fi_MT_R):    \
		$(OBJ_TEST_UNIT_shim_fi_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_shim_fi_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_shim_fi_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp

$(TARG_TEST_UNIT_shim_fi_ST_D):    \
		$(OBJ_TEST_UNIT_shim_fi_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_shim_fi_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_shim_fi_ST_D): $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp

$(TARG_TEST_UNIT_shim_fi_ST_R):    \
		$(OBJ_TEST_UNIT_shim_fi_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_shim_fi_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_shim_fi_ST_R): $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp

$(TARG_TEST_UNIT_snk_a_b_MT_D):    \
		$(OBJ_TEST_UNIT_snk_a_b_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_snk_a_b_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_snk_a_b_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp

$(TARG_TEST_UNIT_snk_a_b_MT_R):    \
		$(OBJ_TEST_UNIT_snk_a_b_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_snk_a_b_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_snk_a_b_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp

$(TARG_TEST_UNIT_snk_a_b_ST_D):    \
		$(OBJ_TEST_UNIT_snk_a_b_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_snk_a_b_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_snk_a_b_ST_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp

$(TARG_TEST_UNIT_snk_a_b_ST_R):    \
		$(OBJ_TEST_UNIT_snk_a_b_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_snk_a_b_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_snk_a_b_ST_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp

$(TARG_TEST_UNIT_snk_c_str_MT_D):    \
		$(OBJ_TEST_UNIT_snk_c_str_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_snk_c_str_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_snk_c_str_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp

$(TARG_TEST_UNIT_snk_c_str_MT_R):    \
		$(OBJ_TEST_UNIT_snk_c_str_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_snk_c_str_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_snk_c_str_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp

$(TARG_TEST_UNIT_snk_c_str_ST_D):    \
		$(OBJ_TEST_UNIT_snk_c_str_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_snk_c_str_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_snk_c_str_ST_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp

$(TARG_TEST_UNIT_snk_c_str_ST_R):    \
		$(OBJ_TEST_UNIT_snk_c_str_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_snk_c_str_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_snk_c_str_ST_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp

$(TARG_TEST_UNIT_snk_chbuf_MT_D):    \
		$(OBJ_TEST_UNIT_snk_chbuf_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_snk_chbuf_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_snk_chbuf_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp

$(TARG_TEST_UNIT_snk_chbuf_MT_R):    \
		$(OBJ_TEST_UNIT_snk_chbuf_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_snk_chbuf_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_snk_chbuf_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp

$(TARG_TEST_UNIT_snk_chbuf_ST_D):    \
		$(OBJ_TEST_UNIT_snk_chbuf_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_snk_chbuf_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_snk_chbuf_ST_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp

$(TARG_TEST_UNIT_snk_chbuf_ST_R):    \
		$(OBJ_TEST_UNIT_snk_chbuf_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_snk_chbuf_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_snk_chbuf_ST_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp

$(TARG_TEST_UNIT_snk_null_MT_D):    \
		$(OBJ_TEST_UNIT_snk_null_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_snk_null_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_snk_null_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp

$(TARG_TEST_UNIT_snk_null_MT_R):    \
		$(OBJ_TEST_UNIT_snk_null_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_snk_null_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_snk_null_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp

$(TARG_TEST_UNIT_snk_null_ST_D):    \
		$(OBJ_TEST_UNIT_snk_null_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_snk_null_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_snk_null_ST_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp

$(TARG_TEST_UNIT_snk_null_ST_R):    \
		$(OBJ_TEST_UNIT_snk_null_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_snk_null_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_snk_null_ST_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp

$(TARG_TEST_UNIT_snk_ostm_MT_D):    \
		$(OBJ_TEST_UNIT_snk_ostm_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_snk_ostm_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_snk_ostm_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp

$(TARG_TEST_UNIT_snk_ostm_MT_R):    \
		$(OBJ_TEST_UNIT_snk_ostm_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_snk_ostm_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_snk_ostm_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp

$(TARG_TEST_UNIT_snk_ostm_ST_D):    \
		$(OBJ_TEST_UNIT_snk_ostm_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_snk_ostm_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_snk_ostm_ST_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp

$(TARG_TEST_UNIT_snk_ostm_ST_R):    \
		$(OBJ_TEST_UNIT_snk_ostm_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_snk_ostm_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_snk_ostm_ST_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp

$(TARG_TEST_UNIT_snk_sstm_MT_D):    \
		$(OBJ_TEST_UNIT_snk_sstm_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_snk_sstm_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_snk_sstm_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp

$(TARG_TEST_UNIT_snk_sstm_MT_R):    \
		$(OBJ_TEST_UNIT_snk_sstm_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_snk_sstm_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_snk_sstm_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp

$(TARG_TEST_UNIT_snk_sstm_ST_D):    \
		$(OBJ_TEST_UNIT_snk_sstm_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_snk_sstm_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_snk_sstm_ST_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp

$(TARG_TEST_UNIT_snk_sstm_ST_R):    \
		$(OBJ_TEST_UNIT_snk_sstm_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_snk_sstm_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_snk_sstm_ST_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp

############################### end of file ################################
