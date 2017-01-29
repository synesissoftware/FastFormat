############################################################################
# File:     makefile
#
# Purpose:  Makefile for the FastFormat project, for the Visual C++ 10 (x64 64-bit)
#           compiler, on Win64
#
# Created:  22nd December 2007
# Updated:  16th August 2016
#
############################################################################


############################################################################
# Environment check
#

!ifndef STLSOFT
!error STLSOFT must be defined
!endif # !STLSOFT

############################################################################
# Symbols

########################################
# Project & compiler version

COMP_TAG            =   vc10
ARCH_TAG            =   .x64
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

XCOVER_VER_MAJOR    =   0
XCOVER_TAG_VER      =   xtests.$(XCOVER_VER_MAJOR)

XTESTS_VER_MAJOR    =   0
XTESTS_TAG_VER      =   xtests.$(XTESTS_VER_MAJOR)

PROJ_MAKEFILE_NAME  =   makefile

########################################
# Testing verbosity

!ifndef TEST_VERBOSITY
TEST_VERBOSITY      =   2
!endif # !TEST_VERBOSITY

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
!ifdef FASTFORMAT_SHWILD_BASE_DIR
SHWILD_INCLUDE_DIR      =   $(FASTFORMAT_SHWILD_BASE_DIR)\include
SHWILD_SRC_DIR          =   $(FASTFORMAT_SHWILD_BASE_DIR)\src
SHWILD_PROJ_INCLUDE     =   -I$(SHWILD_INCLUDE_DIR)
!else
SHWILD_INCLUDE_DIR      =   $(PROJ_BASE_DIR)\include
SHWILD_SRC_DIR          =   $(PROJ_SRC_DIR)\shwild
!endif # !FASTFORMAT_SHWILD_BASE_DIR

XCONTRACT_PROJ_INCLUDE  =   
!ifdef FASTFORMAT_XCONTRACT_BASE_DIR
XCONTRACT_INCLUDE_DIR   =   $(FASTFORMAT_XCONTRACT_BASE_DIR)\include
XCONTRACT_SRC_DIR       =   $(FASTFORMAT_XCONTRACT_BASE_DIR)\src
XCONTRACT_PROJ_INCLUDE  =   -I$(XCONTRACT_INCLUDE_DIR)
!else
XCONTRACT_INCLUDE_DIR   =   $(PROJ_BASE_DIR)\include
XCONTRACT_SRC_DIR       =   $(PROJ_SRC_DIR)\xcontract
!endif # !FASTFORMAT_XCONTRACT_BASE_DIR

XCOVER_PROJ_INCLUDE     =   
!ifdef FASTFORMAT_XCOVER_BASE_DIR
XCOVER_INCLUDE_DIR      =   $(FASTFORMAT_XCOVER_BASE_DIR)\include
XCOVER_SRC_DIR          =   $(FASTFORMAT_XCOVER_BASE_DIR)\src
XCOVER_PROJ_INCLUDE     =   -I$(XCOVER_INCLUDE_DIR)
!else
XCOVER_INCLUDE_DIR      =   $(PROJ_BASE_DIR)\include
XCOVER_SRC_DIR          =   $(PROJ_SRC_DIR)\xcover
!endif # !FASTFORMAT_XCOVER_BASE_DIR

XTESTS_PROJ_INCLUDE     =   
!ifdef FASTFORMAT_XTESTS_BASE_DIR
XTESTS_INCLUDE_DIR      =   $(FASTFORMAT_XTESTS_BASE_DIR)\include
XTESTS_SRC_DIR          =   $(FASTFORMAT_XTESTS_BASE_DIR)\src
XTESTS_PROJ_INCLUDE     =   -I$(XTESTS_INCLUDE_DIR)
!else
XTESTS_INCLUDE_DIR      =   $(PROJ_BASE_DIR)\include
XTESTS_SRC_DIR          =   $(PROJ_SRC_DIR)\xtests
!endif # !FASTFORMAT_XTESTS_BASE_DIR

########################################
# tools

CC                      =   cl
CPPC                    =   cl
AR                      =   lib
LD                      =   link
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
 advapi32.lib kernel32.lib ole32.lib oleaut32.lib shlwapi.lib user32.lib uuid.lib wininet.lib ws2_32.lib \
 \

TARGET_LIB_MT_D_W = \
 advapi32.lib kernel32.lib ole32.lib oleaut32.lib shlwapi.lib user32.lib uuid.lib wininet.lib ws2_32.lib \
 \

TARGET_LIB_DLL_D = \
 advapi32.lib kernel32.lib ole32.lib oleaut32.lib shlwapi.lib user32.lib uuid.lib wininet.lib ws2_32.lib \
 \

TARGET_LIB_DLL_D_W = \
 advapi32.lib kernel32.lib ole32.lib oleaut32.lib shlwapi.lib user32.lib uuid.lib wininet.lib ws2_32.lib \
 \

TARGET_LIB_DLL_R = \
 advapi32.lib kernel32.lib ole32.lib oleaut32.lib shlwapi.lib user32.lib uuid.lib wininet.lib ws2_32.lib \
 \

TARGET_LIB_DLL_R_W = \
 advapi32.lib kernel32.lib ole32.lib oleaut32.lib shlwapi.lib user32.lib uuid.lib wininet.lib ws2_32.lib \
 \

TARGET_LIB_MT_R = \
 advapi32.lib kernel32.lib ole32.lib oleaut32.lib shlwapi.lib user32.lib uuid.lib wininet.lib ws2_32.lib \
 \

TARGET_LIB_MT_R_W = \
 advapi32.lib kernel32.lib ole32.lib oleaut32.lib shlwapi.lib user32.lib uuid.lib wininet.lib ws2_32.lib \
 \


# #defines

COMMON_DEFS 		=	-DWIN64

CUSTOM_DEFS			=	

# includes

COMMON_INCLUDES		=



# CPPC flags

CPPC_F_NOLOGO			=	-nologo
CPPC_F_COMPILE_ONLY 	=	-c
CPPC_F_WARNING_MAX		=	-W4 -wd4800
CPPC_F_WARNING_ERR		=	-WX
CPPC_F_EXCEPTIONS_ON	=	-EHsc
CPPC_F_EXCEPTIONS_OFF	=	-wd4530
CPPC_F_EXCEPTIONS		=	$(CPPC_F_EXCEPTIONS_ON)
CPPC_F_RTTI_ON 			=	-GR
CPPC_F_RTTI_OFF			=	-GR-
CPPC_F_RTTI 			=	$(CPPC_F_RTTI_ON)
CPPC_F_MINIMUM_SIZE 	=	-O1
CPPC_F_MAXIMUM_SPEED	=	-O2 -Ox

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

CPPC_FLAGS_MT_D_W =\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_DLL_D =\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_DLL_D_W =\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_DLL_R =\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_DLL_R_W =\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_MT_R =\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_MT_R_W =\
 $(CPPC_FLAGS_BASE)\
 \


# CPPC defines

!ifdef FASTFORMAT_NO_NAG
NO_NAG_DEFS					=	-DFASTFORMAT_NO_VERSION_NAG=1
!else # ? FASTFORMAT_NO_NAG
NO_NAG_DEFS					=
!endif # FASTFORMAT_NO_NAG

CPPC_DEFS_BASE =\
 $(COMMON_DEFS)\
 $(CUSTOM_DEFS)\
 $(NO_NAG_DEFS)\
 \
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 \

!ifdef BOOST
DEFINE_BOOST_FOR_PERFTEST	=	-DFASTFORMAT_PERFTEST_USE_BOOST
!else # BOOST
DEFINE_BOOST_FOR_PERFTEST	=
!endif # BOOST

!ifdef LOKI
DEFINE_LOKI_FOR_PERFTEST	=	-DFASTFORMAT_PERFTEST_USE_LOKI
!else # LOKI
DEFINE_LOKI_FOR_PERFTEST	=
!endif # LOKI


CPPC_DEFS_MT_D =\
 $(CPPC_DEFS_BASE)\
 $(DEFINE_BOOST_FOR_PERFTEST)\
 $(DEFINE_LOKI_FOR_PERFTEST)\
 \

CPPC_DEFS_MT_D_W =\
 $(CPPC_DEFS_BASE)\
 $(DEFINE_BOOST_FOR_PERFTEST)\
 $(DEFINE_LOKI_FOR_PERFTEST)\
 \

CPPC_DEFS_DLL_D =\
 $(CPPC_DEFS_BASE)\
 $(DEFINE_BOOST_FOR_PERFTEST)\
 $(DEFINE_LOKI_FOR_PERFTEST)\
 \

CPPC_DEFS_DLL_D_W =\
 $(CPPC_DEFS_BASE)\
 $(DEFINE_BOOST_FOR_PERFTEST)\
 $(DEFINE_LOKI_FOR_PERFTEST)\
 \

CPPC_DEFS_DLL_R =\
 $(CPPC_DEFS_BASE)\
 $(DEFINE_BOOST_FOR_PERFTEST)\
 $(DEFINE_LOKI_FOR_PERFTEST)\
 \

CPPC_DEFS_DLL_R_W =\
 $(CPPC_DEFS_BASE)\
 $(DEFINE_BOOST_FOR_PERFTEST)\
 $(DEFINE_LOKI_FOR_PERFTEST)\
 \

CPPC_DEFS_MT_R =\
 $(CPPC_DEFS_BASE)\
 $(DEFINE_BOOST_FOR_PERFTEST)\
 $(DEFINE_LOKI_FOR_PERFTEST)\
 \

CPPC_DEFS_MT_R_W =\
 $(CPPC_DEFS_BASE)\
 $(DEFINE_BOOST_FOR_PERFTEST)\
 $(DEFINE_LOKI_FOR_PERFTEST)\
 \



# CPPC includes

!ifdef STLSOFT_1_10
STLSOFT_1_10_INCLUDE	=	-I"$(STLSOFT_1_10)/include"
!else # STLSOFT_1_10
STLSOFT_1_10_INCLUDE	=
!endif # STLSOFT_1_10

CPPC_INCLUDES_BASE=\
 \
 -I$(PROJ_INCLUDE_DIR)\
 $(SHWILD_PROJ_INCLUDE)\
 $(XCONTRACT_PROJ_INCLUDE)\
 $(XCOVER_PROJ_INCLUDE)\
 $(XTESTS_PROJ_INCLUDE)\
 $(STLSOFT_1_10_INCLUDE)\
 -I$(STLSOFT)\include\
 $(COMMON_INCLUDES)\
 \

CPPC_CORE_INCLUDES_BASE=\
 -I$(PROJ_SRC_DIR)\
 $(CPPC_INCLUDES_BASE)\
 \

!ifdef BOOST
INCLUDE_BOOST_FOR_PERFTEST	=	-I"$(BOOST)"
!else # BOOST
INCLUDE_BOOST_FOR_PERFTEST	=
!endif # BOOST

!ifdef LOKI
INCLUDE_LOKI_FOR_PERFTEST	=	-I"$(LOKI)/include"
!else # LOKI
INCLUDE_LOKI_FOR_PERFTEST	=
!endif # LOKI


CPPC_INCLUDES_MT_D =\
 $(CPPC_INCLUDES_BASE)\
 $(INCLUDE_BOOST_FOR_PERFTEST)\
 $(INCLUDE_LOKI_FOR_PERFTEST)\
 \

CPPC_INCLUDES_MT_D_W =\
 $(CPPC_INCLUDES_BASE)\
 $(INCLUDE_BOOST_FOR_PERFTEST)\
 $(INCLUDE_LOKI_FOR_PERFTEST)\
 \

CPPC_INCLUDES_DLL_D =\
 $(CPPC_INCLUDES_BASE)\
 $(INCLUDE_BOOST_FOR_PERFTEST)\
 $(INCLUDE_LOKI_FOR_PERFTEST)\
 \

CPPC_INCLUDES_DLL_D_W =\
 $(CPPC_INCLUDES_BASE)\
 $(INCLUDE_BOOST_FOR_PERFTEST)\
 $(INCLUDE_LOKI_FOR_PERFTEST)\
 \

CPPC_INCLUDES_DLL_R =\
 $(CPPC_INCLUDES_BASE)\
 $(INCLUDE_BOOST_FOR_PERFTEST)\
 $(INCLUDE_LOKI_FOR_PERFTEST)\
 \

CPPC_INCLUDES_DLL_R_W =\
 $(CPPC_INCLUDES_BASE)\
 $(INCLUDE_BOOST_FOR_PERFTEST)\
 $(INCLUDE_LOKI_FOR_PERFTEST)\
 \

CPPC_INCLUDES_MT_R =\
 $(CPPC_INCLUDES_BASE)\
 $(INCLUDE_BOOST_FOR_PERFTEST)\
 $(INCLUDE_LOKI_FOR_PERFTEST)\
 \

CPPC_INCLUDES_MT_R_W =\
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

CPPC_SHWILD_INCLUDES_MT_D_W =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_DLL_D =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_DLL_D_W =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_DLL_R =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_DLL_R_W =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_MT_R =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_MT_R_W =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \


CPPC_XTESTS_INCLUDES_BASE =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_MT_D =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_MT_D_W =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_DLL_D =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_DLL_D_W =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_DLL_R =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_DLL_R_W =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_MT_R =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_MT_R_W =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \



# CPPC args (= flags + defines + includes)

CPPC_ARGS_MT_D=\
 $(CPPC_FLAGS_MT_D)\
 $(CPPC_CUSTOM_DEFS_DEBUG) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -D_DEBUG -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb\
 $(CPPC_DEFS_MT_D)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_INCLUDES_MT_D)
CPPC_ARGS_MT_D_W=\
 $(CPPC_FLAGS_MT_D_W)\
 $(CPPC_CUSTOM_DEFS_DEBUG) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -DUNICODE -D_UNICODE -D_DEBUG -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb\
 $(CPPC_DEFS_MT_D_W)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_INCLUDES_MT_D_W)
CPPC_ARGS_DLL_D=\
 $(CPPC_FLAGS_DLL_D)\
 $(CPPC_CUSTOM_DEFS_DEBUG) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MDd -D_DEBUG -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb $(CPPC_F_MAXIMUM_SPEED) -D_AFXDLL\
 $(CPPC_DEFS_DLL_D)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_INCLUDES_DLL_D)
CPPC_ARGS_DLL_D_W=\
 $(CPPC_FLAGS_DLL_D_W)\
 $(CPPC_CUSTOM_DEFS_DEBUG) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MDd -DUNICODE -D_UNICODE -D_DEBUG -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb $(CPPC_F_MAXIMUM_SPEED) -D_AFXDLL\
 $(CPPC_DEFS_DLL_D_W)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_INCLUDES_DLL_D_W)
CPPC_ARGS_DLL_R=\
 $(CPPC_FLAGS_DLL_R)\
 $(CPPC_CUSTOM_DEFS_RELEASE) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MD -DNDEBUG $(CPPC_F_MAXIMUM_SPEED) -D_AFXDLL\
 $(CPPC_DEFS_DLL_R)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_INCLUDES_DLL_R)
CPPC_ARGS_DLL_R_W=\
 $(CPPC_FLAGS_DLL_R_W)\
 $(CPPC_CUSTOM_DEFS_RELEASE) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MD -DUNICODE -D_UNICODE -DNDEBUG $(CPPC_F_MAXIMUM_SPEED) -D_AFXDLL\
 $(CPPC_DEFS_DLL_R_W)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_INCLUDES_DLL_R_W)
CPPC_ARGS_MT_R=\
 $(CPPC_FLAGS_MT_R)\
 $(CPPC_CUSTOM_DEFS_RELEASE) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MT -DNDEBUG $(CPPC_F_MAXIMUM_SPEED)\
 $(CPPC_DEFS_MT_R)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_INCLUDES_MT_R)
CPPC_ARGS_MT_R_W=\
 $(CPPC_FLAGS_MT_R_W)\
 $(CPPC_CUSTOM_DEFS_RELEASE) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MT -DUNICODE -D_UNICODE -DNDEBUG $(CPPC_F_MAXIMUM_SPEED)\
 $(CPPC_DEFS_MT_R_W)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_INCLUDES_MT_R_W)

CPPC_CORE_ARGS_MT_D=\
 $(CPPC_FLAGS_MT_D)\
 $(CPPC_CUSTOM_DEFS_DEBUG) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -D_DEBUG -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb\
 $(CPPC_DEFS_MT_D)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_CORE_INCLUDES_BASE)
CPPC_CORE_ARGS_MT_D_W=\
 $(CPPC_FLAGS_MT_D_W)\
 $(CPPC_CUSTOM_DEFS_DEBUG) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -DUNICODE -D_UNICODE -D_DEBUG -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb\
 $(CPPC_DEFS_MT_D_W)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_CORE_INCLUDES_BASE)
CPPC_CORE_ARGS_DLL_D=\
 $(CPPC_FLAGS_DLL_D)\
 $(CPPC_CUSTOM_DEFS_DEBUG) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MDd -D_DEBUG -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb $(CPPC_F_MAXIMUM_SPEED) -D_AFXDLL\
 $(CPPC_DEFS_DLL_D)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_CORE_INCLUDES_BASE)
CPPC_CORE_ARGS_DLL_D_W=\
 $(CPPC_FLAGS_DLL_D_W)\
 $(CPPC_CUSTOM_DEFS_DEBUG) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MDd -DUNICODE -D_UNICODE -D_DEBUG -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb $(CPPC_F_MAXIMUM_SPEED) -D_AFXDLL\
 $(CPPC_DEFS_DLL_D_W)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_CORE_INCLUDES_BASE)
CPPC_CORE_ARGS_DLL_R=\
 $(CPPC_FLAGS_DLL_R)\
 $(CPPC_CUSTOM_DEFS_RELEASE) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MD -DNDEBUG $(CPPC_F_MAXIMUM_SPEED) -D_AFXDLL\
 $(CPPC_DEFS_DLL_R)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_CORE_INCLUDES_BASE)
CPPC_CORE_ARGS_DLL_R_W=\
 $(CPPC_FLAGS_DLL_R_W)\
 $(CPPC_CUSTOM_DEFS_RELEASE) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MD -DUNICODE -D_UNICODE -DNDEBUG $(CPPC_F_MAXIMUM_SPEED) -D_AFXDLL\
 $(CPPC_DEFS_DLL_R_W)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_CORE_INCLUDES_BASE)
CPPC_CORE_ARGS_MT_R=\
 $(CPPC_FLAGS_MT_R)\
 $(CPPC_CUSTOM_DEFS_RELEASE) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MT -DNDEBUG $(CPPC_F_MAXIMUM_SPEED)\
 $(CPPC_DEFS_MT_R)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_CORE_INCLUDES_BASE)
CPPC_CORE_ARGS_MT_R_W=\
 $(CPPC_FLAGS_MT_R_W)\
 $(CPPC_CUSTOM_DEFS_RELEASE) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MT -DUNICODE -D_UNICODE -DNDEBUG $(CPPC_F_MAXIMUM_SPEED)\
 $(CPPC_DEFS_MT_R_W)\
 -DFASTFORMAT_NO_IMPLICIT_LINK\
 $(CPPC_CORE_INCLUDES_BASE)




# AR Args

AR_ARGS             =   -nologo


# LD flags

LD_F_NOLOGO				=   -nologo

LD_FLAGS_BASE =\
 $(LD_F_NOLOGO)\
 \

LD_FLAGS_MT_D =\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_MT_D_W =\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_DLL_D =\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_DLL_D_W =\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_DLL_R =\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_DLL_R_W =\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_MT_R =\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_MT_R_W =\
 $(LD_FLAGS_BASE)\
 \


# LD includes

LD_INCLUDES_BASE =\
 $(LIBPATHS)\
 \

LD_INCLUDES_MT_D =\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_MT_D_W =\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_DLL_D =\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_DLL_D_W =\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_DLL_R =\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_DLL_R_W =\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_MT_R =\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_MT_R_W =\
 $(LD_INCLUDES_BASE)\
 \


LD_ARGS 		=	-machine:x64

LD_F_NOLOGO = -nologo

# LD args

LD_ARGS_MT_D =  $(LD_ARGS) $(LD_F_NOLOGO) $(LIBPATHS) $(COMMON_LIB)
LD_ARGS_MT_D_W =  $(LD_ARGS) $(LD_F_NOLOGO) $(LIBPATHS) $(COMMON_LIB)
LD_ARGS_DLL_D =  $(LD_ARGS) $(LD_F_NOLOGO) $(LIBPATHS) $(COMMON_LIB)
LD_ARGS_DLL_D_W =  $(LD_ARGS) $(LD_F_NOLOGO) $(LIBPATHS) $(COMMON_LIB)
LD_ARGS_DLL_R =  $(LD_ARGS) $(LD_F_NOLOGO) $(LIBPATHS) $(COMMON_LIB)
LD_ARGS_DLL_R_W =  $(LD_ARGS) $(LD_F_NOLOGO) $(LIBPATHS) $(COMMON_LIB)
LD_ARGS_MT_R =  $(LD_ARGS) $(LD_F_NOLOGO) $(LIBPATHS) $(COMMON_LIB)
LD_ARGS_MT_R_W =  $(LD_ARGS) $(LD_F_NOLOGO) $(LIBPATHS) $(COMMON_LIB)

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
 $(PROJ_INCLUDE_DIR)\fastformat\bundles\windows_resource_bundle.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\bundles\winini_bundle.hpp\
 \
 $(PROJ_INCLUDE_DIR)\fastformat\format\standard_flags.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\format\specification_defect_handling\ignore_missing_arguments_scope.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\format\specification_defect_handling\ignore_unreferenced_arguments_scope.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\format\specification_defect_handling\mismatched_arguments_scope_base.hpp\
 \
 $(PROJ_INCLUDE_DIR)\fastformat\inserters\ch.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\inserters\character.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\inserters\integer.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\inserters\real.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\inserters\storage_size.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\inserters\to_e.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\inserters\to_f.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\inserters\to_g.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\inserters\to_i.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\inserters\to_i_null_if_not.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\inserters\to_i_null_if_zero.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\inserters\to_x.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\inserters\ULARGE_INTEGER.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\inserters\WindowsLargeIntegers.hpp\
 \
 $(PROJ_INCLUDE_DIR)\fastformat\internal\fastformat.c++.h\
 $(PROJ_INCLUDE_DIR)\fastformat\internal\format_element.h\
 $(PROJ_INCLUDE_DIR)\fastformat\internal\shim_macros.h\
 $(PROJ_INCLUDE_DIR)\fastformat\internal\stlsoft.h\
 $(PROJ_INCLUDE_DIR)\fastformat\internal\string_encoding.h\
 $(PROJ_INCLUDE_DIR)\fastformat\internal\threading.h\
 $(PROJ_INCLUDE_DIR)\fastformat\internal\initialiser.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\internal\generated\api_functions.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\internal\generated\helper_functions.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\internal\inserters\int_typedefs.hpp\
 \
 $(PROJ_INCLUDE_DIR)\fastformat\iterators\format_iterator.hpp\
 \
 $(PROJ_INCLUDE_DIR)\fastformat\quality\contract.h\
 $(PROJ_INCLUDE_DIR)\fastformat\quality\cover.h\
 \
 $(PROJ_INCLUDE_DIR)\fastformat\shims\access\string\parse_code.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\shims\access\string\replacement_code.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\shims\access\string\string_slice.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\shims\action\fmt_slices\generic_string.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\shims\conversion\filter_type\bool.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\shims\conversion\filter_type\fast_integers.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\shims\conversion\filter_type\reals.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\shims\conversion\filter_type\void_pointers.hpp\
 \
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\ACE_CString.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\auto_buffer.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\CComBSTR.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\char_buffer.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\CString.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\c_string.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\FILE.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\iostream.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\null.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\ostream.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\OutputDebugString.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\shim_string.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\speech.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\stringstream.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\string_array.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\vectored_file.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\WindowsConsole.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\WindowsMessageBox.hpp\
 $(PROJ_INCLUDE_DIR)\fastformat\sinks\stlsoft\FILE_stream.hpp\
 \
 $(PROJ_INCLUDE_DIR)\fastformat\test\util\compiler_warnings_suppression.first_include.h\
 $(PROJ_INCLUDE_DIR)\fastformat\test\util\compiler_warnings_suppression.last_include.h\
 \
 $(PROJ_INCLUDE_DIR)\fastformat\util\bundle\windows_replacement_translation_functions.hpp\
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

XCOVER_HEADERS=\
 $(PROJ_INCLUDE_DIR)\xcover\xcover.h\
 $(PROJ_INCLUDE_DIR)\xcover\internal\reporter.h\
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
LIB_CORE_MT_D_W				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).widestring.mt.debug.lib
LIB_CORE_DLL_D				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).dll.debug.lib
LIB_CORE_DLL_D_W				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).widestring.dll.debug.lib
LIB_CORE_DLL_R				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).dll.lib
LIB_CORE_DLL_R_W				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).widestring.dll.lib
LIB_CORE_MT_R				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).mt.lib
LIB_CORE_MT_R_W				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).widestring.mt.lib

# Loki.SafeFormat - performance testing only
!ifdef LOKI
LIB_LOKI_SFMT_MT_D		=	$(PROJ_LIB_DIR)\$(LOKI_SFMT_TAG_VER).ff.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_LOKI_SFMT_MT_D_W		=	$(PROJ_LIB_DIR)\$(LOKI_SFMT_TAG_VER).ff.$(COMP_ARCH_OS_TAG).widestring.mt.debug.lib
LIB_LOKI_SFMT_DLL_D		=	$(PROJ_LIB_DIR)\$(LOKI_SFMT_TAG_VER).ff.$(COMP_ARCH_OS_TAG).dll.debug.lib
LIB_LOKI_SFMT_DLL_D_W		=	$(PROJ_LIB_DIR)\$(LOKI_SFMT_TAG_VER).ff.$(COMP_ARCH_OS_TAG).widestring.dll.debug.lib
LIB_LOKI_SFMT_DLL_R		=	$(PROJ_LIB_DIR)\$(LOKI_SFMT_TAG_VER).ff.$(COMP_ARCH_OS_TAG).dll.lib
LIB_LOKI_SFMT_DLL_R_W		=	$(PROJ_LIB_DIR)\$(LOKI_SFMT_TAG_VER).ff.$(COMP_ARCH_OS_TAG).widestring.dll.lib
LIB_LOKI_SFMT_MT_R		=	$(PROJ_LIB_DIR)\$(LOKI_SFMT_TAG_VER).ff.$(COMP_ARCH_OS_TAG).mt.lib
LIB_LOKI_SFMT_MT_R_W		=	$(PROJ_LIB_DIR)\$(LOKI_SFMT_TAG_VER).ff.$(COMP_ARCH_OS_TAG).widestring.mt.lib
!else # LOKI
LIB_LOKI_SFMT_MT_D		=
LIB_LOKI_SFMT_MT_D_W		=
LIB_LOKI_SFMT_DLL_D		=
LIB_LOKI_SFMT_DLL_D_W		=
LIB_LOKI_SFMT_DLL_R		=
LIB_LOKI_SFMT_DLL_R_W		=
LIB_LOKI_SFMT_MT_R		=
LIB_LOKI_SFMT_MT_R_W		=
!endif # LOKI

# shwild - testing only
LIB_SHWILD_MT_D			=	$(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).ff.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_SHWILD_MT_D_W			=	$(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).ff.$(COMP_ARCH_OS_TAG).widestring.mt.debug.lib
LIB_SHWILD_DLL_D			=	$(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).ff.$(COMP_ARCH_OS_TAG).dll.debug.lib
LIB_SHWILD_DLL_D_W			=	$(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).ff.$(COMP_ARCH_OS_TAG).widestring.dll.debug.lib
LIB_SHWILD_DLL_R			=	$(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).ff.$(COMP_ARCH_OS_TAG).dll.lib
LIB_SHWILD_DLL_R_W			=	$(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).ff.$(COMP_ARCH_OS_TAG).widestring.dll.lib
LIB_SHWILD_MT_R			=	$(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).ff.$(COMP_ARCH_OS_TAG).mt.lib
LIB_SHWILD_MT_R_W			=	$(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).ff.$(COMP_ARCH_OS_TAG).widestring.mt.lib

# xtests - unit/component testing only
LIB_XTESTS_MT_D			=	$(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).ff.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_XTESTS_MT_D_W			=	$(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).ff.$(COMP_ARCH_OS_TAG).widestring.mt.debug.lib
LIB_XTESTS_DLL_D			=	$(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).ff.$(COMP_ARCH_OS_TAG).dll.debug.lib
LIB_XTESTS_DLL_D_W			=	$(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).ff.$(COMP_ARCH_OS_TAG).widestring.dll.debug.lib
LIB_XTESTS_DLL_R			=	$(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).ff.$(COMP_ARCH_OS_TAG).dll.lib
LIB_XTESTS_DLL_R_W			=	$(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).ff.$(COMP_ARCH_OS_TAG).widestring.dll.lib
LIB_XTESTS_MT_R			=	$(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).ff.$(COMP_ARCH_OS_TAG).mt.lib
LIB_XTESTS_MT_R_W			=	$(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).ff.$(COMP_ARCH_OS_TAG).widestring.mt.lib

########################################
# Examples

TARG_BITBUCKET_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_BITBUCKET_MT_D_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_BITBUCKET_DLL_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_BITBUCKET_DLL_D_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_BITBUCKET_DLL_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.$(COMP_ARCH_OS_TAG).dll.exe
TARG_BITBUCKET_DLL_R_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_BITBUCKET_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.$(COMP_ARCH_OS_TAG).mt.exe
TARG_BITBUCKET_MT_R_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.$(COMP_ARCH_OS_TAG).widestring.mt.exe

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

TARG_EX_boolean_MT_D_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.boolean.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_EX_character_MT_D_W	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.character.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_EX_reals_MT_D_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.reals.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_EX_voidptrs_MT_D_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.void_pointers.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_EX_itr_fmt_MT_D_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.itrs.fmt_itr.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_EX_sink_ODS_MT_D_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.sink.OutputDebugString.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe

TARG_EX_boolean_DLL_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.boolean.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_character_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.character.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_reals_DLL_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.reals.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_voidptrs_DLL_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.void_pointers.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ff_101_DLL_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ff_101.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ff_101_nons_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ff_101.no_namespace.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_flush_DLL_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.flush.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ins_hex_DLL_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.hex.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ins_integers_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.integers.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ins_reals_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.reals.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ins_WLIs_DLL_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.WLIs.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_itr_fmt_DLL_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.itrs.fmt_itr.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ovld2_filt_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.2.hero.filter.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ovld2_ins_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.2.hero.inserter.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ovld2_sas_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.2.hero.sas.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ovld3_fpcol_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.flpt.cols.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ovld3_tabs_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.tabs.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ovld3_svrlg_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.svr.log.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ovld3_rcins_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.rec.ins.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_pad_hash_DLL_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.pad.hash.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_sink_cstr_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.sink.c_string.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_sink_ODS_DLL_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.sink.OutputDebugString.$(COMP_ARCH_OS_TAG).dll.debug.exe

TARG_EX_boolean_DLL_D_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.boolean.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_EX_character_DLL_D_W	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.character.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_EX_reals_DLL_D_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.reals.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_EX_voidptrs_DLL_D_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.void_pointers.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_EX_itr_fmt_DLL_D_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.itrs.fmt_itr.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_EX_sink_ODS_DLL_D_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.sink.OutputDebugString.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe

TARG_EX_boolean_DLL_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.boolean.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_character_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.character.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_reals_DLL_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.reals.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_voidptrs_DLL_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.void_pointers.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ff_101_DLL_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ff_101.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ff_101_nons_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ff_101.no_namespace.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_flush_DLL_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.flush.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ins_hex_DLL_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.hex.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ins_integers_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.integers.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ins_reals_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.reals.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ins_WLIs_DLL_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.inserter.WLIs.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_itr_fmt_DLL_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.itrs.fmt_itr.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ovld2_filt_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.2.hero.filter.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ovld2_ins_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.2.hero.inserter.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ovld2_sas_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.2.hero.sas.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ovld3_fpcol_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.flpt.cols.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ovld3_tabs_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.tabs.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ovld3_svrlg_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.svr.log.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ovld3_rcins_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.ovld.3.rec.ins.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_pad_hash_DLL_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.pad.hash.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_sink_cstr_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.sink.c_string.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_sink_ODS_DLL_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.sink.OutputDebugString.$(COMP_ARCH_OS_TAG).dll.exe

TARG_EX_boolean_DLL_R_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.boolean.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_EX_character_DLL_R_W	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.character.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_EX_reals_DLL_R_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.reals.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_EX_voidptrs_DLL_R_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.void_pointers.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_EX_itr_fmt_DLL_R_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.itrs.fmt_itr.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_EX_sink_ODS_DLL_R_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.sink.OutputDebugString.$(COMP_ARCH_OS_TAG).widestring.dll.exe

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

TARG_EX_boolean_MT_R_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.boolean.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_EX_character_MT_R_W	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.character.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_EX_reals_MT_R_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.reals.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_EX_voidptrs_MT_R_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.arguments.void_pointers.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_EX_itr_fmt_MT_R_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.itrs.fmt_itr.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_EX_sink_ODS_MT_R_W		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.sink.OutputDebugString.$(COMP_ARCH_OS_TAG).widestring.mt.exe


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
TARG_TEST_COMP_file_MT_D_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.FILE.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_COMP_fmt_sink_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.string.fmt.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_COMP_ins_hex_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.hex.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_COMP_ins_int_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.integer.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_COMP_ins_real_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.real.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_COMP_itr_fmt_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.itrs.fmt_itr.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_COMP_null_sink_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.null.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_COMP_snk_a_b_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.auto_buffer.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_COMP_write_sink_MT_D_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.string.write.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_COMP_x_1_MT_D_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.fsde.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_COMP_snk_ostm_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.ostream.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_COMP_file_DLL_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.FILE.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_COMP_fmt_sink_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.string.fmt.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_COMP_ins_hex_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.hex.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_COMP_ins_int_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.integer.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_COMP_ins_real_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.real.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_COMP_itr_fmt_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.itrs.fmt_itr.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_COMP_null_sink_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.null.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_COMP_snk_a_b_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.auto_buffer.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_COMP_write_sink_DLL_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.string.write.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_COMP_x_1_DLL_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.fsde.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_COMP_snk_ostm_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.ostream.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_COMP_file_DLL_D_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.FILE.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_COMP_fmt_sink_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.string.fmt.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_COMP_ins_hex_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.hex.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_COMP_ins_int_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.integer.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_COMP_ins_real_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.real.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_COMP_itr_fmt_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.itrs.fmt_itr.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_COMP_null_sink_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.null.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_COMP_snk_a_b_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.auto_buffer.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_COMP_write_sink_DLL_D_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.string.write.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_COMP_x_1_DLL_D_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.fsde.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_COMP_snk_ostm_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.ostream.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_COMP_file_DLL_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.FILE.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_COMP_fmt_sink_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.string.fmt.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_COMP_ins_hex_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.hex.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_COMP_ins_int_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.integer.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_COMP_ins_real_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.real.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_COMP_itr_fmt_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.itrs.fmt_itr.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_COMP_null_sink_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.null.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_COMP_snk_a_b_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.auto_buffer.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_COMP_write_sink_DLL_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.string.write.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_COMP_x_1_DLL_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.fsde.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_COMP_snk_ostm_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.ostream.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_COMP_file_DLL_R_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.FILE.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_COMP_fmt_sink_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.string.fmt.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_COMP_ins_hex_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.hex.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_COMP_ins_int_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.integer.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_COMP_ins_real_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.real.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_COMP_itr_fmt_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.itrs.fmt_itr.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_COMP_null_sink_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.null.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_COMP_snk_a_b_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.auto_buffer.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_COMP_write_sink_DLL_R_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.string.write.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_COMP_x_1_DLL_R_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.fsde.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_COMP_snk_ostm_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.ostream.$(COMP_ARCH_OS_TAG).widestring.dll.exe
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
TARG_TEST_COMP_file_MT_R_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.FILE.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_COMP_fmt_sink_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.string.fmt.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_COMP_ins_hex_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.hex.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_COMP_ins_int_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.integer.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_COMP_ins_real_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.real.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_COMP_itr_fmt_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.itrs.fmt_itr.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_COMP_null_sink_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.null.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_COMP_snk_a_b_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.auto_buffer.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_COMP_write_sink_MT_R_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.string.write.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_COMP_x_1_MT_R_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.fsde.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_COMP_snk_ostm_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.sink.ostream.$(COMP_ARCH_OS_TAG).widestring.mt.exe

##############################
# Performance Tests

TARG_TEST_PERF_scen1_MT_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario1.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_PERF_scen2_MT_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario2.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_PERF_scen3_MT_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario3.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_PERF_scen4_MT_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario4.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_PERF_scen5_MT_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario5.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_PERF_scen6_MT_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario6.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_PERF_scen7_MT_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario7.$(COMP_ARCH_OS_TAG).mt.debug.exe
!ifdef BOOST
TARG_TEST_PERF_scen8_MT_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario8.$(COMP_ARCH_OS_TAG).mt.debug.exe
!endif # BOOST
TARG_TEST_PERF_scen1_MT_D_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario1.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_PERF_scen2_MT_D_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario2.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_PERF_scen3_MT_D_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario3.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_PERF_scen4_MT_D_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario4.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_PERF_scen5_MT_D_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario5.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_PERF_scen6_MT_D_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario6.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_PERF_scen7_MT_D_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario7.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
!ifdef BOOST
TARG_TEST_PERF_scen8_MT_D_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario8.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
!endif # BOOST
TARG_TEST_PERF_scen1_DLL_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario1.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_PERF_scen2_DLL_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario2.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_PERF_scen3_DLL_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario3.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_PERF_scen4_DLL_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario4.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_PERF_scen5_DLL_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario5.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_PERF_scen6_DLL_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario6.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_PERF_scen7_DLL_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario7.$(COMP_ARCH_OS_TAG).dll.debug.exe
!ifdef BOOST
TARG_TEST_PERF_scen8_DLL_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario8.$(COMP_ARCH_OS_TAG).dll.debug.exe
!endif # BOOST
TARG_TEST_PERF_scen1_DLL_D_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario1.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_PERF_scen2_DLL_D_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario2.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_PERF_scen3_DLL_D_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario3.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_PERF_scen4_DLL_D_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario4.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_PERF_scen5_DLL_D_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario5.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_PERF_scen6_DLL_D_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario6.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_PERF_scen7_DLL_D_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario7.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
!ifdef BOOST
TARG_TEST_PERF_scen8_DLL_D_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario8.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
!endif # BOOST
TARG_TEST_PERF_scen1_DLL_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario1.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_PERF_scen2_DLL_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario2.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_PERF_scen3_DLL_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario3.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_PERF_scen4_DLL_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario4.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_PERF_scen5_DLL_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario5.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_PERF_scen6_DLL_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario6.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_PERF_scen7_DLL_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario7.$(COMP_ARCH_OS_TAG).dll.exe
!ifdef BOOST
TARG_TEST_PERF_scen8_DLL_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario8.$(COMP_ARCH_OS_TAG).dll.exe
!endif # BOOST
TARG_TEST_PERF_scen1_DLL_R_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario1.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_PERF_scen2_DLL_R_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario2.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_PERF_scen3_DLL_R_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario3.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_PERF_scen4_DLL_R_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario4.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_PERF_scen5_DLL_R_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario5.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_PERF_scen6_DLL_R_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario6.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_PERF_scen7_DLL_R_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario7.$(COMP_ARCH_OS_TAG).widestring.dll.exe
!ifdef BOOST
TARG_TEST_PERF_scen8_DLL_R_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario8.$(COMP_ARCH_OS_TAG).widestring.dll.exe
!endif # BOOST
TARG_TEST_PERF_scen1_MT_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario1.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_PERF_scen2_MT_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario2.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_PERF_scen3_MT_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario3.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_PERF_scen4_MT_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario4.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_PERF_scen5_MT_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario5.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_PERF_scen6_MT_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario6.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_PERF_scen7_MT_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario7.$(COMP_ARCH_OS_TAG).mt.exe
!ifdef BOOST
TARG_TEST_PERF_scen8_MT_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario8.$(COMP_ARCH_OS_TAG).mt.exe
!endif # BOOST
TARG_TEST_PERF_scen1_MT_R_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario1.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_PERF_scen2_MT_R_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario2.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_PERF_scen3_MT_R_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario3.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_PERF_scen4_MT_R_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario4.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_PERF_scen5_MT_R_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario5.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_PERF_scen6_MT_R_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario6.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_PERF_scen7_MT_R_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario7.$(COMP_ARCH_OS_TAG).widestring.mt.exe
!ifdef BOOST
TARG_TEST_PERF_scen8_MT_R_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.scenario8.$(COMP_ARCH_OS_TAG).widestring.mt.exe
!endif # BOOST

##############################
# Scratch Tests

TARG_TEST_SCRT_file_MT_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.FILE.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_SCRT_speech_MT_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.speech.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_SCRT_file_MT_D_W    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.FILE.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_SCRT_speech_MT_D_W    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.speech.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_SCRT_file_DLL_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.FILE.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_SCRT_speech_DLL_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.speech.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_SCRT_file_DLL_D_W    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.FILE.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_SCRT_speech_DLL_D_W    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.speech.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_SCRT_file_DLL_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.FILE.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_SCRT_speech_DLL_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.speech.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_SCRT_file_DLL_R_W    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.FILE.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_SCRT_speech_DLL_R_W    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.speech.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_SCRT_file_MT_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.FILE.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_SCRT_speech_MT_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.speech.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_SCRT_file_MT_R_W    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.FILE.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_SCRT_speech_MT_R_W    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.speech.$(COMP_ARCH_OS_TAG).widestring.mt.exe

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
TARG_TEST_UNIT_ins_ss_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.storage_size.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_shim_fi_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.shims.fast_integers.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_shim_ns_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.shims_and_namespaces.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_snk_a_b_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.auto_buffer.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_snk_c_str_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.c_string.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_snk_chbuf_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.char_buffer.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_snk_null_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.null.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_snk_ods_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ODS.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_snk_ostm_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ostream.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_snk_sstm_MT_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.stringstream.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_api_acsllen_MT_D_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.accum_slice_lens.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_api_crlf_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.crlf_for_platform.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_api_flrpl_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.fill_replacements.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_api_illfmdh_MT_D_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.illformed_handlers.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_api_init_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.initialisation.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_api_lkptrn_MT_D_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.lookup_pattern.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_api_msmtchh_MT_D_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.mismatched_handlers.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_api_prsrpl_MT_D_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.parse_format.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_bndl_winini_MT_D_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.bundle.winini.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_fmt_stdfl_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.format.standard_flags.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_ins_ch_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.character.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_ins_i_MT_D_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.integer.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_ins_ss_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.storage_size.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_shim_fi_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.shims.fast_integers.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_shim_ns_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.shims_and_namespaces.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_snk_a_b_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.auto_buffer.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_snk_c_str_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.c_string.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_snk_chbuf_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.char_buffer.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_snk_null_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.null.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_snk_ods_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ODS.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_snk_ostm_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ostream.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_snk_sstm_MT_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.stringstream.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_api_acsllen_DLL_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.accum_slice_lens.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_api_crlf_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.crlf_for_platform.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_api_flrpl_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.fill_replacements.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_api_illfmdh_DLL_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.illformed_handlers.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_api_init_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.initialisation.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_api_lkptrn_DLL_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.lookup_pattern.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_api_msmtchh_DLL_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.mismatched_handlers.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_api_prsrpl_DLL_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.parse_format.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_bndl_winini_DLL_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.bundle.winini.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_fmt_stdfl_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.format.standard_flags.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_ins_ch_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.character.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_ins_i_DLL_D			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.integer.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_ins_ss_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.storage_size.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_shim_fi_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.shims.fast_integers.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_shim_ns_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.shims_and_namespaces.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_snk_a_b_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.auto_buffer.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_snk_c_str_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.c_string.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_snk_chbuf_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.char_buffer.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_snk_mfccstr_DLL_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.CString.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_snk_null_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.null.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_snk_ods_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ODS.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_snk_ostm_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ostream.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_snk_sstm_DLL_D		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.stringstream.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_api_acsllen_DLL_D_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.accum_slice_lens.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_api_crlf_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.crlf_for_platform.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_api_flrpl_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.fill_replacements.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_api_illfmdh_DLL_D_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.illformed_handlers.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_api_init_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.initialisation.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_api_lkptrn_DLL_D_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.lookup_pattern.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_api_msmtchh_DLL_D_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.mismatched_handlers.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_api_prsrpl_DLL_D_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.parse_format.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_bndl_winini_DLL_D_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.bundle.winini.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_fmt_stdfl_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.format.standard_flags.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_ins_ch_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.character.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_ins_i_DLL_D_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.integer.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_ins_ss_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.storage_size.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_shim_fi_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.shims.fast_integers.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_shim_ns_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.shims_and_namespaces.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_snk_a_b_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.auto_buffer.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_snk_c_str_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.c_string.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_snk_chbuf_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.char_buffer.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_snk_mfccstr_DLL_D_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.CString.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_snk_null_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.null.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_snk_ods_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ODS.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_snk_ostm_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ostream.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_snk_sstm_DLL_D_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.stringstream.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_api_acsllen_DLL_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.accum_slice_lens.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_api_crlf_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.crlf_for_platform.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_api_flrpl_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.fill_replacements.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_api_illfmdh_DLL_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.illformed_handlers.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_api_init_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.initialisation.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_api_lkptrn_DLL_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.lookup_pattern.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_api_msmtchh_DLL_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.mismatched_handlers.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_api_prsrpl_DLL_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.parse_format.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_bndl_winini_DLL_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.bundle.winini.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_fmt_stdfl_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.format.standard_flags.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_ins_ch_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.character.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_ins_i_DLL_R			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.integer.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_ins_ss_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.storage_size.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_shim_fi_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.shims.fast_integers.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_shim_ns_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.shims_and_namespaces.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_snk_a_b_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.auto_buffer.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_snk_c_str_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.c_string.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_snk_chbuf_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.char_buffer.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_snk_mfccstr_DLL_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.CString.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_snk_null_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.null.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_snk_ods_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ODS.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_snk_ostm_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ostream.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_snk_sstm_DLL_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.stringstream.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_api_acsllen_DLL_R_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.accum_slice_lens.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_api_crlf_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.crlf_for_platform.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_api_flrpl_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.fill_replacements.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_api_illfmdh_DLL_R_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.illformed_handlers.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_api_init_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.initialisation.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_api_lkptrn_DLL_R_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.lookup_pattern.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_api_msmtchh_DLL_R_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.mismatched_handlers.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_api_prsrpl_DLL_R_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.parse_format.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_bndl_winini_DLL_R_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.bundle.winini.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_fmt_stdfl_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.format.standard_flags.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_ins_ch_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.character.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_ins_i_DLL_R_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.integer.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_ins_ss_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.storage_size.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_shim_fi_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.shims.fast_integers.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_shim_ns_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.shims_and_namespaces.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_snk_a_b_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.auto_buffer.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_snk_c_str_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.c_string.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_snk_chbuf_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.char_buffer.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_snk_mfccstr_DLL_R_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.CString.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_snk_null_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.null.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_snk_ods_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ODS.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_snk_ostm_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ostream.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_snk_sstm_DLL_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.stringstream.$(COMP_ARCH_OS_TAG).widestring.dll.exe
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
TARG_TEST_UNIT_ins_ss_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.storage_size.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_shim_fi_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.shims.fast_integers.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_shim_ns_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.shims_and_namespaces.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_snk_a_b_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.auto_buffer.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_snk_c_str_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.c_string.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_snk_chbuf_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.char_buffer.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_snk_null_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.null.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_snk_ods_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ODS.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_snk_ostm_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ostream.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_snk_sstm_MT_R		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.stringstream.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_api_acsllen_MT_R_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.accum_slice_lens.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_api_crlf_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.crlf_for_platform.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_api_flrpl_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.fill_replacements.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_api_illfmdh_MT_R_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.illformed_handlers.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_api_init_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.initialisation.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_api_lkptrn_MT_R_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.lookup_pattern.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_api_msmtchh_MT_R_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.mismatched_handlers.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_api_prsrpl_MT_R_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.parse_format.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_bndl_winini_MT_R_W	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.bundle.winini.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_fmt_stdfl_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.format.standard_flags.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_ins_ch_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.character.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_ins_i_MT_R_W			=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.integer.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_ins_ss_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserters.storage_size.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_shim_fi_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.shims.fast_integers.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_shim_ns_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.shims_and_namespaces.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_snk_a_b_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.auto_buffer.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_snk_c_str_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.c_string.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_snk_chbuf_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.char_buffer.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_snk_null_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.null.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_snk_ods_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ODS.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_snk_ostm_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.ostream.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_snk_sstm_MT_R_W		=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.sink.stringstream.$(COMP_ARCH_OS_TAG).widestring.mt.exe

############################################################################
# Objects

########################################
# Libraries

# fastformat

OBJ_cr_api_MT_D           = $(PROJ_OBJ_DIR)\core.api.mt.debug.obj
OBJ_cr_enumstr_MT_D       = $(PROJ_OBJ_DIR)\core.enum_strings.mt.debug.obj
OBJ_cr_fsdhndlrs_MT_D     = $(PROJ_OBJ_DIR)\core.fmt_spec_defect_handlers.mt.debug.obj
OBJ_cr_fmtcache_MT_D      = $(PROJ_OBJ_DIR)\core.fmt_cache.mt.debug.obj
OBJ_cr_initstr_MT_D       = $(PROJ_OBJ_DIR)\core.init_code_strings.mt.debug.obj
OBJ_cr_mempool_MT_D       = $(PROJ_OBJ_DIR)\core.mempool.mt.debug.obj
OBJ_cr_replacements_MT_D  = $(PROJ_OBJ_DIR)\core.replacements.mt.debug.obj
OBJ_cr_snprintf_MT_D      = $(PROJ_OBJ_DIR)\core.snprintf.mt.debug.obj
PDB_cr_api_MT_D           = $(PROJ_OBJ_DIR)\core.api.mt.debug.pdb
PDB_cr_fsdhndlrs_MT_D     = $(PROJ_OBJ_DIR)\core.fmt_spec_defect_handlers.mt.debug.pdb
PDB_cr_fmtcache_MT_D      = $(PROJ_OBJ_DIR)\core.fmt_cache.mt.debug.pdb
PDB_cr_initstr_MT_D       = $(PROJ_OBJ_DIR)\core.init_code_strings.mt.debug.pdb
PDB_cr_mempool_MT_D       = $(PROJ_OBJ_DIR)\core.mempool.mt.debug.pdb
PDB_cr_replacements_MT_D  = $(PROJ_OBJ_DIR)\core.replacements.mt.debug.pdb
PDB_cr_snprintf_MT_D      = $(PROJ_OBJ_DIR)\core.snprintf.mt.debug.pdb

OBJ_CORE_MT_D = \
 $(OBJ_cr_api_MT_D)\
 $(OBJ_cr_enumstr_MT_D)\
 $(OBJ_cr_fsdhndlrs_MT_D)\
 $(OBJ_cr_fmtcache_MT_D)\
 $(OBJ_cr_initstr_MT_D)\
 $(OBJ_cr_mempool_MT_D)\
 $(OBJ_cr_replacements_MT_D)\
 $(OBJ_cr_snprintf_MT_D)\
 \

PDB_CORE_MT_D = \
 $(PDB_cr_api_MT_D)\
 $(PDB_cr_fsdhndlrs_MT_D)\
 $(PDB_cr_fmtcache_MT_D)\
 $(PDB_cr_initstr_MT_D)\
 $(PDB_cr_mempool_MT_D)\
 $(PDB_cr_replacements_MT_D)\
 $(PDB_cr_snprintf_MT_D)\
 \

OBJ_cr_api_MT_D_W           = $(PROJ_OBJ_DIR)\core.api.widestring.mt.debug.obj
OBJ_cr_enumstr_MT_D_W       = $(PROJ_OBJ_DIR)\core.enum_strings.widestring.mt.debug.obj
OBJ_cr_fsdhndlrs_MT_D_W     = $(PROJ_OBJ_DIR)\core.fmt_spec_defect_handlers.widestring.mt.debug.obj
OBJ_cr_fmtcache_MT_D_W      = $(PROJ_OBJ_DIR)\core.fmt_cache.widestring.mt.debug.obj
OBJ_cr_initstr_MT_D_W       = $(PROJ_OBJ_DIR)\core.init_code_strings.widestring.mt.debug.obj
OBJ_cr_mempool_MT_D_W       = $(PROJ_OBJ_DIR)\core.mempool.widestring.mt.debug.obj
OBJ_cr_replacements_MT_D_W  = $(PROJ_OBJ_DIR)\core.replacements.widestring.mt.debug.obj
OBJ_cr_snprintf_MT_D_W      = $(PROJ_OBJ_DIR)\core.snprintf.widestring.mt.debug.obj
PDB_cr_api_MT_D_W           = $(PROJ_OBJ_DIR)\core.api.widestring.mt.debug.pdb
PDB_cr_fsdhndlrs_MT_D_W     = $(PROJ_OBJ_DIR)\core.fmt_spec_defect_handlers.widestring.mt.debug.pdb
PDB_cr_fmtcache_MT_D_W      = $(PROJ_OBJ_DIR)\core.fmt_cache.widestring.mt.debug.pdb
PDB_cr_initstr_MT_D_W       = $(PROJ_OBJ_DIR)\core.init_code_strings.widestring.mt.debug.pdb
PDB_cr_mempool_MT_D_W       = $(PROJ_OBJ_DIR)\core.mempool.widestring.mt.debug.pdb
PDB_cr_replacements_MT_D_W  = $(PROJ_OBJ_DIR)\core.replacements.widestring.mt.debug.pdb
PDB_cr_snprintf_MT_D_W      = $(PROJ_OBJ_DIR)\core.snprintf.widestring.mt.debug.pdb

OBJ_CORE_MT_D_W = \
 $(OBJ_cr_api_MT_D_W)\
 $(OBJ_cr_enumstr_MT_D_W)\
 $(OBJ_cr_fsdhndlrs_MT_D_W)\
 $(OBJ_cr_fmtcache_MT_D_W)\
 $(OBJ_cr_initstr_MT_D_W)\
 $(OBJ_cr_mempool_MT_D_W)\
 $(OBJ_cr_replacements_MT_D_W)\
 $(OBJ_cr_snprintf_MT_D_W)\
 \

PDB_CORE_MT_D_W = \
 $(PDB_cr_api_MT_D_W)\
 $(PDB_cr_fsdhndlrs_MT_D_W)\
 $(PDB_cr_fmtcache_MT_D_W)\
 $(PDB_cr_initstr_MT_D_W)\
 $(PDB_cr_mempool_MT_D_W)\
 $(PDB_cr_replacements_MT_D_W)\
 $(PDB_cr_snprintf_MT_D_W)\
 \

OBJ_cr_api_DLL_D           = $(PROJ_OBJ_DIR)\core.api.dll.debug.obj
OBJ_cr_enumstr_DLL_D       = $(PROJ_OBJ_DIR)\core.enum_strings.dll.debug.obj
OBJ_cr_fsdhndlrs_DLL_D     = $(PROJ_OBJ_DIR)\core.fmt_spec_defect_handlers.dll.debug.obj
OBJ_cr_fmtcache_DLL_D      = $(PROJ_OBJ_DIR)\core.fmt_cache.dll.debug.obj
OBJ_cr_initstr_DLL_D       = $(PROJ_OBJ_DIR)\core.init_code_strings.dll.debug.obj
OBJ_cr_mempool_DLL_D       = $(PROJ_OBJ_DIR)\core.mempool.dll.debug.obj
OBJ_cr_replacements_DLL_D  = $(PROJ_OBJ_DIR)\core.replacements.dll.debug.obj
OBJ_cr_snprintf_DLL_D      = $(PROJ_OBJ_DIR)\core.snprintf.dll.debug.obj
PDB_cr_api_DLL_D           = $(PROJ_OBJ_DIR)\core.api.dll.debug.pdb
PDB_cr_fsdhndlrs_DLL_D     = $(PROJ_OBJ_DIR)\core.fmt_spec_defect_handlers.dll.debug.pdb
PDB_cr_fmtcache_DLL_D      = $(PROJ_OBJ_DIR)\core.fmt_cache.dll.debug.pdb
PDB_cr_initstr_DLL_D       = $(PROJ_OBJ_DIR)\core.init_code_strings.dll.debug.pdb
PDB_cr_mempool_DLL_D       = $(PROJ_OBJ_DIR)\core.mempool.dll.debug.pdb
PDB_cr_replacements_DLL_D  = $(PROJ_OBJ_DIR)\core.replacements.dll.debug.pdb
PDB_cr_snprintf_DLL_D      = $(PROJ_OBJ_DIR)\core.snprintf.dll.debug.pdb

OBJ_CORE_DLL_D = \
 $(OBJ_cr_api_DLL_D)\
 $(OBJ_cr_enumstr_DLL_D)\
 $(OBJ_cr_fsdhndlrs_DLL_D)\
 $(OBJ_cr_fmtcache_DLL_D)\
 $(OBJ_cr_initstr_DLL_D)\
 $(OBJ_cr_mempool_DLL_D)\
 $(OBJ_cr_replacements_DLL_D)\
 $(OBJ_cr_snprintf_DLL_D)\
 \

PDB_CORE_DLL_D = \
 $(PDB_cr_api_DLL_D)\
 $(PDB_cr_fsdhndlrs_DLL_D)\
 $(PDB_cr_fmtcache_DLL_D)\
 $(PDB_cr_initstr_DLL_D)\
 $(PDB_cr_mempool_DLL_D)\
 $(PDB_cr_replacements_DLL_D)\
 $(PDB_cr_snprintf_DLL_D)\
 \

OBJ_cr_api_DLL_D_W           = $(PROJ_OBJ_DIR)\core.api.widestring.dll.debug.obj
OBJ_cr_enumstr_DLL_D_W       = $(PROJ_OBJ_DIR)\core.enum_strings.widestring.dll.debug.obj
OBJ_cr_fsdhndlrs_DLL_D_W     = $(PROJ_OBJ_DIR)\core.fmt_spec_defect_handlers.widestring.dll.debug.obj
OBJ_cr_fmtcache_DLL_D_W      = $(PROJ_OBJ_DIR)\core.fmt_cache.widestring.dll.debug.obj
OBJ_cr_initstr_DLL_D_W       = $(PROJ_OBJ_DIR)\core.init_code_strings.widestring.dll.debug.obj
OBJ_cr_mempool_DLL_D_W       = $(PROJ_OBJ_DIR)\core.mempool.widestring.dll.debug.obj
OBJ_cr_replacements_DLL_D_W  = $(PROJ_OBJ_DIR)\core.replacements.widestring.dll.debug.obj
OBJ_cr_snprintf_DLL_D_W      = $(PROJ_OBJ_DIR)\core.snprintf.widestring.dll.debug.obj
PDB_cr_api_DLL_D_W           = $(PROJ_OBJ_DIR)\core.api.widestring.dll.debug.pdb
PDB_cr_fsdhndlrs_DLL_D_W     = $(PROJ_OBJ_DIR)\core.fmt_spec_defect_handlers.widestring.dll.debug.pdb
PDB_cr_fmtcache_DLL_D_W      = $(PROJ_OBJ_DIR)\core.fmt_cache.widestring.dll.debug.pdb
PDB_cr_initstr_DLL_D_W       = $(PROJ_OBJ_DIR)\core.init_code_strings.widestring.dll.debug.pdb
PDB_cr_mempool_DLL_D_W       = $(PROJ_OBJ_DIR)\core.mempool.widestring.dll.debug.pdb
PDB_cr_replacements_DLL_D_W  = $(PROJ_OBJ_DIR)\core.replacements.widestring.dll.debug.pdb
PDB_cr_snprintf_DLL_D_W      = $(PROJ_OBJ_DIR)\core.snprintf.widestring.dll.debug.pdb

OBJ_CORE_DLL_D_W = \
 $(OBJ_cr_api_DLL_D_W)\
 $(OBJ_cr_enumstr_DLL_D_W)\
 $(OBJ_cr_fsdhndlrs_DLL_D_W)\
 $(OBJ_cr_fmtcache_DLL_D_W)\
 $(OBJ_cr_initstr_DLL_D_W)\
 $(OBJ_cr_mempool_DLL_D_W)\
 $(OBJ_cr_replacements_DLL_D_W)\
 $(OBJ_cr_snprintf_DLL_D_W)\
 \

PDB_CORE_DLL_D_W = \
 $(PDB_cr_api_DLL_D_W)\
 $(PDB_cr_fsdhndlrs_DLL_D_W)\
 $(PDB_cr_fmtcache_DLL_D_W)\
 $(PDB_cr_initstr_DLL_D_W)\
 $(PDB_cr_mempool_DLL_D_W)\
 $(PDB_cr_replacements_DLL_D_W)\
 $(PDB_cr_snprintf_DLL_D_W)\
 \

OBJ_cr_api_DLL_R           = $(PROJ_OBJ_DIR)\core.api.dll.obj
OBJ_cr_enumstr_DLL_R       = $(PROJ_OBJ_DIR)\core.enum_strings.dll.obj
OBJ_cr_fsdhndlrs_DLL_R     = $(PROJ_OBJ_DIR)\core.fmt_spec_defect_handlers.dll.obj
OBJ_cr_fmtcache_DLL_R      = $(PROJ_OBJ_DIR)\core.fmt_cache.dll.obj
OBJ_cr_initstr_DLL_R       = $(PROJ_OBJ_DIR)\core.init_code_strings.dll.obj
OBJ_cr_mempool_DLL_R       = $(PROJ_OBJ_DIR)\core.mempool.dll.obj
OBJ_cr_replacements_DLL_R  = $(PROJ_OBJ_DIR)\core.replacements.dll.obj
OBJ_cr_snprintf_DLL_R      = $(PROJ_OBJ_DIR)\core.snprintf.dll.obj

OBJ_CORE_DLL_R = \
 $(OBJ_cr_api_DLL_R)\
 $(OBJ_cr_enumstr_DLL_R)\
 $(OBJ_cr_fsdhndlrs_DLL_R)\
 $(OBJ_cr_fmtcache_DLL_R)\
 $(OBJ_cr_initstr_DLL_R)\
 $(OBJ_cr_mempool_DLL_R)\
 $(OBJ_cr_replacements_DLL_R)\
 $(OBJ_cr_snprintf_DLL_R)\
 \

OBJ_cr_api_DLL_R_W           = $(PROJ_OBJ_DIR)\core.api.widestring.dll.obj
OBJ_cr_enumstr_DLL_R_W       = $(PROJ_OBJ_DIR)\core.enum_strings.widestring.dll.obj
OBJ_cr_fsdhndlrs_DLL_R_W     = $(PROJ_OBJ_DIR)\core.fmt_spec_defect_handlers.widestring.dll.obj
OBJ_cr_fmtcache_DLL_R_W      = $(PROJ_OBJ_DIR)\core.fmt_cache.widestring.dll.obj
OBJ_cr_initstr_DLL_R_W       = $(PROJ_OBJ_DIR)\core.init_code_strings.widestring.dll.obj
OBJ_cr_mempool_DLL_R_W       = $(PROJ_OBJ_DIR)\core.mempool.widestring.dll.obj
OBJ_cr_replacements_DLL_R_W  = $(PROJ_OBJ_DIR)\core.replacements.widestring.dll.obj
OBJ_cr_snprintf_DLL_R_W      = $(PROJ_OBJ_DIR)\core.snprintf.widestring.dll.obj

OBJ_CORE_DLL_R_W = \
 $(OBJ_cr_api_DLL_R_W)\
 $(OBJ_cr_enumstr_DLL_R_W)\
 $(OBJ_cr_fsdhndlrs_DLL_R_W)\
 $(OBJ_cr_fmtcache_DLL_R_W)\
 $(OBJ_cr_initstr_DLL_R_W)\
 $(OBJ_cr_mempool_DLL_R_W)\
 $(OBJ_cr_replacements_DLL_R_W)\
 $(OBJ_cr_snprintf_DLL_R_W)\
 \

OBJ_cr_api_MT_R           = $(PROJ_OBJ_DIR)\core.api.mt.obj
OBJ_cr_enumstr_MT_R       = $(PROJ_OBJ_DIR)\core.enum_strings.mt.obj
OBJ_cr_fsdhndlrs_MT_R     = $(PROJ_OBJ_DIR)\core.fmt_spec_defect_handlers.mt.obj
OBJ_cr_fmtcache_MT_R      = $(PROJ_OBJ_DIR)\core.fmt_cache.mt.obj
OBJ_cr_initstr_MT_R       = $(PROJ_OBJ_DIR)\core.init_code_strings.mt.obj
OBJ_cr_mempool_MT_R       = $(PROJ_OBJ_DIR)\core.mempool.mt.obj
OBJ_cr_replacements_MT_R  = $(PROJ_OBJ_DIR)\core.replacements.mt.obj
OBJ_cr_snprintf_MT_R      = $(PROJ_OBJ_DIR)\core.snprintf.mt.obj

OBJ_CORE_MT_R = \
 $(OBJ_cr_api_MT_R)\
 $(OBJ_cr_enumstr_MT_R)\
 $(OBJ_cr_fsdhndlrs_MT_R)\
 $(OBJ_cr_fmtcache_MT_R)\
 $(OBJ_cr_initstr_MT_R)\
 $(OBJ_cr_mempool_MT_R)\
 $(OBJ_cr_replacements_MT_R)\
 $(OBJ_cr_snprintf_MT_R)\
 \

OBJ_cr_api_MT_R_W           = $(PROJ_OBJ_DIR)\core.api.widestring.mt.obj
OBJ_cr_enumstr_MT_R_W       = $(PROJ_OBJ_DIR)\core.enum_strings.widestring.mt.obj
OBJ_cr_fsdhndlrs_MT_R_W     = $(PROJ_OBJ_DIR)\core.fmt_spec_defect_handlers.widestring.mt.obj
OBJ_cr_fmtcache_MT_R_W      = $(PROJ_OBJ_DIR)\core.fmt_cache.widestring.mt.obj
OBJ_cr_initstr_MT_R_W       = $(PROJ_OBJ_DIR)\core.init_code_strings.widestring.mt.obj
OBJ_cr_mempool_MT_R_W       = $(PROJ_OBJ_DIR)\core.mempool.widestring.mt.obj
OBJ_cr_replacements_MT_R_W  = $(PROJ_OBJ_DIR)\core.replacements.widestring.mt.obj
OBJ_cr_snprintf_MT_R_W      = $(PROJ_OBJ_DIR)\core.snprintf.widestring.mt.obj

OBJ_CORE_MT_R_W = \
 $(OBJ_cr_api_MT_R_W)\
 $(OBJ_cr_enumstr_MT_R_W)\
 $(OBJ_cr_fsdhndlrs_MT_R_W)\
 $(OBJ_cr_fmtcache_MT_R_W)\
 $(OBJ_cr_initstr_MT_R_W)\
 $(OBJ_cr_mempool_MT_R_W)\
 $(OBJ_cr_replacements_MT_R_W)\
 $(OBJ_cr_snprintf_MT_R_W)\
 \


# Loki.SafeFormat

!ifdef LOKI
OBJ_lok_sfmt_MT_D		= $(PROJ_OBJ_DIR)\$(LOKI_SFMT_TAG_VER).ff.api.mt.debug.obj
PDB_lok_sfmt_MT_D		= $(PROJ_OBJ_DIR)\$(LOKI_SFMT_TAG_VER).ff.api.mt.debug.pdb

OBJ_LOKI_SFMT_MT_D = \
 $(OBJ_lok_sfmt_MT_D)\
 \

PDB_LOKI_SFMT_MT_D = \
 $(PDB_lok_sfmt_MT_D)\
 \

OBJ_lok_sfmt_MT_D_W		= $(PROJ_OBJ_DIR)\$(LOKI_SFMT_TAG_VER).ff.api.widestring.mt.debug.obj
PDB_lok_sfmt_MT_D_W		= $(PROJ_OBJ_DIR)\$(LOKI_SFMT_TAG_VER).ff.api.widestring.mt.debug.pdb

OBJ_LOKI_SFMT_MT_D_W = \
 $(OBJ_lok_sfmt_MT_D_W)\
 \

PDB_LOKI_SFMT_MT_D_W = \
 $(PDB_lok_sfmt_MT_D_W)\
 \

OBJ_lok_sfmt_DLL_D		= $(PROJ_OBJ_DIR)\$(LOKI_SFMT_TAG_VER).ff.api.dll.debug.obj
PDB_lok_sfmt_DLL_D		= $(PROJ_OBJ_DIR)\$(LOKI_SFMT_TAG_VER).ff.api.dll.debug.pdb

OBJ_LOKI_SFMT_DLL_D = \
 $(OBJ_lok_sfmt_DLL_D)\
 \

PDB_LOKI_SFMT_DLL_D = \
 $(PDB_lok_sfmt_DLL_D)\
 \

OBJ_lok_sfmt_DLL_D_W		= $(PROJ_OBJ_DIR)\$(LOKI_SFMT_TAG_VER).ff.api.widestring.dll.debug.obj
PDB_lok_sfmt_DLL_D_W		= $(PROJ_OBJ_DIR)\$(LOKI_SFMT_TAG_VER).ff.api.widestring.dll.debug.pdb

OBJ_LOKI_SFMT_DLL_D_W = \
 $(OBJ_lok_sfmt_DLL_D_W)\
 \

PDB_LOKI_SFMT_DLL_D_W = \
 $(PDB_lok_sfmt_DLL_D_W)\
 \

OBJ_lok_sfmt_DLL_R		= $(PROJ_OBJ_DIR)\$(LOKI_SFMT_TAG_VER).ff.api.dll.obj

OBJ_LOKI_SFMT_DLL_R = \
 $(OBJ_lok_sfmt_DLL_R)\
 \

OBJ_lok_sfmt_DLL_R_W		= $(PROJ_OBJ_DIR)\$(LOKI_SFMT_TAG_VER).ff.api.widestring.dll.obj

OBJ_LOKI_SFMT_DLL_R_W = \
 $(OBJ_lok_sfmt_DLL_R_W)\
 \

OBJ_lok_sfmt_MT_R		= $(PROJ_OBJ_DIR)\$(LOKI_SFMT_TAG_VER).ff.api.mt.obj

OBJ_LOKI_SFMT_MT_R = \
 $(OBJ_lok_sfmt_MT_R)\
 \

OBJ_lok_sfmt_MT_R_W		= $(PROJ_OBJ_DIR)\$(LOKI_SFMT_TAG_VER).ff.api.widestring.mt.obj

OBJ_LOKI_SFMT_MT_R_W = \
 $(OBJ_lok_sfmt_MT_R_W)\
 \

!else # LOKI
OBJ_lok_sfmt_MT_D	=
PDB_lok_sfmt_MT_D	=
OBJ_LOKI_SFMT_MT_D_PM	=
PDB_LOKI_SFMT_MT_D_PM	=
OBJ_lok_sfmt_MT_D_W	=
PDB_lok_sfmt_MT_D_W	=
OBJ_LOKI_SFMT_MT_D_W_PM	=
PDB_LOKI_SFMT_MT_D_W_PM	=
OBJ_lok_sfmt_DLL_D	=
PDB_lok_sfmt_DLL_D	=
OBJ_LOKI_SFMT_DLL_D_PM	=
PDB_LOKI_SFMT_DLL_D_PM	=
OBJ_lok_sfmt_DLL_D_W	=
PDB_lok_sfmt_DLL_D_W	=
OBJ_LOKI_SFMT_DLL_D_W_PM	=
PDB_LOKI_SFMT_DLL_D_W_PM	=
OBJ_lok_sfmt_DLL_R	=
PDB_lok_sfmt_DLL_R	=
OBJ_LOKI_SFMT_DLL_R_PM	=
PDB_LOKI_SFMT_DLL_R_PM	=
OBJ_lok_sfmt_DLL_R_W	=
PDB_lok_sfmt_DLL_R_W	=
OBJ_LOKI_SFMT_DLL_R_W_PM	=
PDB_LOKI_SFMT_DLL_R_W_PM	=
OBJ_lok_sfmt_MT_R	=
PDB_lok_sfmt_MT_R	=
OBJ_LOKI_SFMT_MT_R_PM	=
PDB_LOKI_SFMT_MT_R_PM	=
OBJ_lok_sfmt_MT_R_W	=
PDB_lok_sfmt_MT_R_W	=
OBJ_LOKI_SFMT_MT_R_W_PM	=
PDB_LOKI_SFMT_MT_R_W_PM	=
!endif # LOKI

# shwild

OBJ_shw_api_MT_D            = $(PROJ_OBJ_DIR)\shwild.ff.api.mt.debug.obj
OBJ_shw_matches_MT_D        = $(PROJ_OBJ_DIR)\shwild.ff.matches.mt.debug.obj
OBJ_shw_pattern_MT_D        = $(PROJ_OBJ_DIR)\shwild.ff.pattern.mt.debug.obj
PDB_shw_api_MT_D            = $(PROJ_OBJ_DIR)\shwild.ff.api.mt.debug.pdb
PDB_shw_matches_MT_D        = $(PROJ_OBJ_DIR)\shwild.ff.matches.mt.debug.pdb
PDB_shw_pattern_MT_D        = $(PROJ_OBJ_DIR)\shwild.ff.pattern.mt.debug.pdb

OBJ_SHWILD_MT_D = \
 $(OBJ_shw_api_MT_D)\
 $(OBJ_shw_matches_MT_D)\
 $(OBJ_shw_pattern_MT_D)\
 \

PDB_SHWILD_MT_D = \
 $(PDB_shw_api_MT_D)\
 $(PDB_shw_matches_MT_D)\
 $(PDB_shw_pattern_MT_D)\
 \

OBJ_shw_api_MT_D_W            = $(PROJ_OBJ_DIR)\shwild.ff.api.widestring.mt.debug.obj
OBJ_shw_matches_MT_D_W        = $(PROJ_OBJ_DIR)\shwild.ff.matches.widestring.mt.debug.obj
OBJ_shw_pattern_MT_D_W        = $(PROJ_OBJ_DIR)\shwild.ff.pattern.widestring.mt.debug.obj
PDB_shw_api_MT_D_W            = $(PROJ_OBJ_DIR)\shwild.ff.api.widestring.mt.debug.pdb
PDB_shw_matches_MT_D_W        = $(PROJ_OBJ_DIR)\shwild.ff.matches.widestring.mt.debug.pdb
PDB_shw_pattern_MT_D_W        = $(PROJ_OBJ_DIR)\shwild.ff.pattern.widestring.mt.debug.pdb

OBJ_SHWILD_MT_D_W = \
 $(OBJ_shw_api_MT_D_W)\
 $(OBJ_shw_matches_MT_D_W)\
 $(OBJ_shw_pattern_MT_D_W)\
 \

PDB_SHWILD_MT_D_W = \
 $(PDB_shw_api_MT_D_W)\
 $(PDB_shw_matches_MT_D_W)\
 $(PDB_shw_pattern_MT_D_W)\
 \

OBJ_shw_api_DLL_D            = $(PROJ_OBJ_DIR)\shwild.ff.api.dll.debug.obj
OBJ_shw_matches_DLL_D        = $(PROJ_OBJ_DIR)\shwild.ff.matches.dll.debug.obj
OBJ_shw_pattern_DLL_D        = $(PROJ_OBJ_DIR)\shwild.ff.pattern.dll.debug.obj
PDB_shw_api_DLL_D            = $(PROJ_OBJ_DIR)\shwild.ff.api.dll.debug.pdb
PDB_shw_matches_DLL_D        = $(PROJ_OBJ_DIR)\shwild.ff.matches.dll.debug.pdb
PDB_shw_pattern_DLL_D        = $(PROJ_OBJ_DIR)\shwild.ff.pattern.dll.debug.pdb

OBJ_SHWILD_DLL_D = \
 $(OBJ_shw_api_DLL_D)\
 $(OBJ_shw_matches_DLL_D)\
 $(OBJ_shw_pattern_DLL_D)\
 \

PDB_SHWILD_DLL_D = \
 $(PDB_shw_api_DLL_D)\
 $(PDB_shw_matches_DLL_D)\
 $(PDB_shw_pattern_DLL_D)\
 \

OBJ_shw_api_DLL_D_W            = $(PROJ_OBJ_DIR)\shwild.ff.api.widestring.dll.debug.obj
OBJ_shw_matches_DLL_D_W        = $(PROJ_OBJ_DIR)\shwild.ff.matches.widestring.dll.debug.obj
OBJ_shw_pattern_DLL_D_W        = $(PROJ_OBJ_DIR)\shwild.ff.pattern.widestring.dll.debug.obj
PDB_shw_api_DLL_D_W            = $(PROJ_OBJ_DIR)\shwild.ff.api.widestring.dll.debug.pdb
PDB_shw_matches_DLL_D_W        = $(PROJ_OBJ_DIR)\shwild.ff.matches.widestring.dll.debug.pdb
PDB_shw_pattern_DLL_D_W        = $(PROJ_OBJ_DIR)\shwild.ff.pattern.widestring.dll.debug.pdb

OBJ_SHWILD_DLL_D_W = \
 $(OBJ_shw_api_DLL_D_W)\
 $(OBJ_shw_matches_DLL_D_W)\
 $(OBJ_shw_pattern_DLL_D_W)\
 \

PDB_SHWILD_DLL_D_W = \
 $(PDB_shw_api_DLL_D_W)\
 $(PDB_shw_matches_DLL_D_W)\
 $(PDB_shw_pattern_DLL_D_W)\
 \

OBJ_shw_api_DLL_R            = $(PROJ_OBJ_DIR)\shwild.ff.api.dll.obj
OBJ_shw_matches_DLL_R        = $(PROJ_OBJ_DIR)\shwild.ff.matches.dll.obj
OBJ_shw_pattern_DLL_R        = $(PROJ_OBJ_DIR)\shwild.ff.pattern.dll.obj

OBJ_SHWILD_DLL_R = \
 $(OBJ_shw_api_DLL_R)\
 $(OBJ_shw_matches_DLL_R)\
 $(OBJ_shw_pattern_DLL_R)\
 \

OBJ_shw_api_DLL_R_W            = $(PROJ_OBJ_DIR)\shwild.ff.api.widestring.dll.obj
OBJ_shw_matches_DLL_R_W        = $(PROJ_OBJ_DIR)\shwild.ff.matches.widestring.dll.obj
OBJ_shw_pattern_DLL_R_W        = $(PROJ_OBJ_DIR)\shwild.ff.pattern.widestring.dll.obj

OBJ_SHWILD_DLL_R_W = \
 $(OBJ_shw_api_DLL_R_W)\
 $(OBJ_shw_matches_DLL_R_W)\
 $(OBJ_shw_pattern_DLL_R_W)\
 \

OBJ_shw_api_MT_R            = $(PROJ_OBJ_DIR)\shwild.ff.api.mt.obj
OBJ_shw_matches_MT_R        = $(PROJ_OBJ_DIR)\shwild.ff.matches.mt.obj
OBJ_shw_pattern_MT_R        = $(PROJ_OBJ_DIR)\shwild.ff.pattern.mt.obj

OBJ_SHWILD_MT_R = \
 $(OBJ_shw_api_MT_R)\
 $(OBJ_shw_matches_MT_R)\
 $(OBJ_shw_pattern_MT_R)\
 \

OBJ_shw_api_MT_R_W            = $(PROJ_OBJ_DIR)\shwild.ff.api.widestring.mt.obj
OBJ_shw_matches_MT_R_W        = $(PROJ_OBJ_DIR)\shwild.ff.matches.widestring.mt.obj
OBJ_shw_pattern_MT_R_W        = $(PROJ_OBJ_DIR)\shwild.ff.pattern.widestring.mt.obj

OBJ_SHWILD_MT_R_W = \
 $(OBJ_shw_api_MT_R_W)\
 $(OBJ_shw_matches_MT_R_W)\
 $(OBJ_shw_pattern_MT_R_W)\
 \


# xtests

OBJ_xts_core_MT_D           = $(PROJ_OBJ_DIR)\xtests.ff.core.api.mt.debug.obj
PDB_xts_core_MT_D           = $(PROJ_OBJ_DIR)\xtests.ff.core.api.mt.debug.pdb

OBJ_XTESTS_MT_D = \
 $(OBJ_xts_core_MT_D)\
 \

PDB_CORE_MT_D = \
 $(PDB_xts_core_MT_D)\
 \

OBJ_xts_core_MT_D_W           = $(PROJ_OBJ_DIR)\xtests.ff.core.api.widestring.mt.debug.obj
PDB_xts_core_MT_D_W           = $(PROJ_OBJ_DIR)\xtests.ff.core.api.widestring.mt.debug.pdb

OBJ_XTESTS_MT_D_W = \
 $(OBJ_xts_core_MT_D_W)\
 \

PDB_CORE_MT_D_W = \
 $(PDB_xts_core_MT_D_W)\
 \

OBJ_xts_core_DLL_D           = $(PROJ_OBJ_DIR)\xtests.ff.core.api.dll.debug.obj
PDB_xts_core_DLL_D           = $(PROJ_OBJ_DIR)\xtests.ff.core.api.dll.debug.pdb

OBJ_XTESTS_DLL_D = \
 $(OBJ_xts_core_DLL_D)\
 \

PDB_CORE_DLL_D = \
 $(PDB_xts_core_DLL_D)\
 \

OBJ_xts_core_DLL_D_W           = $(PROJ_OBJ_DIR)\xtests.ff.core.api.widestring.dll.debug.obj
PDB_xts_core_DLL_D_W           = $(PROJ_OBJ_DIR)\xtests.ff.core.api.widestring.dll.debug.pdb

OBJ_XTESTS_DLL_D_W = \
 $(OBJ_xts_core_DLL_D_W)\
 \

PDB_CORE_DLL_D_W = \
 $(PDB_xts_core_DLL_D_W)\
 \

OBJ_xts_core_DLL_R           = $(PROJ_OBJ_DIR)\xtests.ff.core.api.dll.obj

OBJ_XTESTS_DLL_R = \
 $(OBJ_xts_core_DLL_R)\
 \

OBJ_xts_core_DLL_R_W           = $(PROJ_OBJ_DIR)\xtests.ff.core.api.widestring.dll.obj

OBJ_XTESTS_DLL_R_W = \
 $(OBJ_xts_core_DLL_R_W)\
 \

OBJ_xts_core_MT_R           = $(PROJ_OBJ_DIR)\xtests.ff.core.api.mt.obj

OBJ_XTESTS_MT_R = \
 $(OBJ_xts_core_MT_R)\
 \

OBJ_xts_core_MT_R_W           = $(PROJ_OBJ_DIR)\xtests.ff.core.api.widestring.mt.obj

OBJ_XTESTS_MT_R_W = \
 $(OBJ_xts_core_MT_R_W)\
 \


########################################
# Examples

OBJ_BITBUCKET_MT_D		=	$(PROJ_OBJ_DIR)\bitbucket.mt.debug.obj
OBJ_BITBUCKET_MT_D_W		=	$(PROJ_OBJ_DIR)\bitbucket.widestring.mt.debug.obj
OBJ_BITBUCKET_DLL_D		=	$(PROJ_OBJ_DIR)\bitbucket.dll.debug.obj
OBJ_BITBUCKET_DLL_D_W		=	$(PROJ_OBJ_DIR)\bitbucket.widestring.dll.debug.obj
OBJ_BITBUCKET_DLL_R		=	$(PROJ_OBJ_DIR)\bitbucket.dll.obj
OBJ_BITBUCKET_DLL_R_W		=	$(PROJ_OBJ_DIR)\bitbucket.widestring.dll.obj
OBJ_BITBUCKET_MT_R		=	$(PROJ_OBJ_DIR)\bitbucket.mt.obj
OBJ_BITBUCKET_MT_R_W		=	$(PROJ_OBJ_DIR)\bitbucket.widestring.mt.obj

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

OBJ_EX_boolean_MT_D_W		=   $(PROJ_OBJ_DIR)\example.arguments.boolean.widestring.mt.debug.obj
OBJ_EX_character_MT_D_W		=   $(PROJ_OBJ_DIR)\example.arguments.character.widestring.mt.debug.obj
OBJ_EX_reals_MT_D_W			=   $(PROJ_OBJ_DIR)\example.arguments.reals.widestring.mt.debug.obj
OBJ_EX_voidptrs_MT_D_W		=   $(PROJ_OBJ_DIR)\example.arguments.void_pointers.widestring.mt.debug.obj
OBJ_EX_itr_fmt_MT_D_W		=	$(PROJ_OBJ_DIR)\example.itrs.fmt_itr.widestring.mt.debug.obj
OBJ_EX_sink_ODS_MT_D_W		=   $(PROJ_OBJ_DIR)\example.sink.OutputDebugString.widestring.mt.debug.obj

OBJ_EX_boolean_DLL_D		=   $(PROJ_OBJ_DIR)\example.arguments.boolean.dll.debug.obj
OBJ_EX_character_DLL_D		=   $(PROJ_OBJ_DIR)\example.arguments.character.dll.debug.obj
OBJ_EX_reals_DLL_D			=   $(PROJ_OBJ_DIR)\example.arguments.reals.dll.debug.obj
OBJ_EX_voidptrs_DLL_D		=   $(PROJ_OBJ_DIR)\example.arguments.void_pointers.dll.debug.obj
OBJ_EX_ff_101_DLL_D		=   $(PROJ_OBJ_DIR)\example.ff_101.dll.debug.obj
OBJ_EX_ff_101_nons_DLL_D	=   $(PROJ_OBJ_DIR)\example.ff_101.no_namespace.dll.debug.obj
OBJ_EX_flush_DLL_D			=	$(PROJ_OBJ_DIR)\example.flush.dll.debug.obj
OBJ_EX_ins_hex_DLL_D		=	$(PROJ_OBJ_DIR)\example.inserter.hex.dll.debug.obj
OBJ_EX_ins_integers_DLL_D	=	$(PROJ_OBJ_DIR)\example.inserter.integers.dll.debug.obj
OBJ_EX_ins_reals_DLL_D		=	$(PROJ_OBJ_DIR)\example.inserter.reals.dll.debug.obj
OBJ_EX_ins_WLIs_DLL_D		=	$(PROJ_OBJ_DIR)\example.inserter.WLIs.dll.debug.obj
OBJ_EX_itr_fmt_DLL_D		=	$(PROJ_OBJ_DIR)\example.itrs.fmt_itr.dll.debug.obj
OBJ_EX_ovld2_filt_DLL_D	=   $(PROJ_OBJ_DIR)\example.ovld.2.hero.filter.dll.debug.obj
OBJ_EX_ovld2_ins_DLL_D		=   $(PROJ_OBJ_DIR)\example.ovld.2.hero.inserter.dll.debug.obj
OBJ_EX_ovld2_sas_DLL_D		=   $(PROJ_OBJ_DIR)\example.ovld.2.hero.sas.dll.debug.obj
OBJ_EX_ovld3_fpcol_DLL_D	=   $(PROJ_OBJ_DIR)\example.ovld.3.flpt.cols.dll.debug.obj
OBJ_EX_ovld3_tabs_DLL_D	=   $(PROJ_OBJ_DIR)\example.ovld.3.tabs.dll.debug.obj
OBJ_EX_ovld3_svrlg_DLL_D	=   $(PROJ_OBJ_DIR)\example.ovld.3.svr.log.dll.debug.obj
OBJ_EX_ovld3_rcins_DLL_D	=   $(PROJ_OBJ_DIR)\example.ovld.3.rec.ins.dll.debug.obj
OBJ_EX_pad_hash_DLL_D		=	$(PROJ_OBJ_DIR)\example.pad.hash.dll.debug.obj
OBJ_EX_sink_cstr_DLL_D		=	$(PROJ_OBJ_DIR)\example.sink.c_string.dll.debug.obj
OBJ_EX_sink_ODS_DLL_D		=   $(PROJ_OBJ_DIR)\example.sink.OutputDebugString.dll.debug.obj

OBJ_EX_boolean_DLL_D_W		=   $(PROJ_OBJ_DIR)\example.arguments.boolean.widestring.dll.debug.obj
OBJ_EX_character_DLL_D_W		=   $(PROJ_OBJ_DIR)\example.arguments.character.widestring.dll.debug.obj
OBJ_EX_reals_DLL_D_W			=   $(PROJ_OBJ_DIR)\example.arguments.reals.widestring.dll.debug.obj
OBJ_EX_voidptrs_DLL_D_W		=   $(PROJ_OBJ_DIR)\example.arguments.void_pointers.widestring.dll.debug.obj
OBJ_EX_itr_fmt_DLL_D_W		=	$(PROJ_OBJ_DIR)\example.itrs.fmt_itr.widestring.dll.debug.obj
OBJ_EX_sink_ODS_DLL_D_W		=   $(PROJ_OBJ_DIR)\example.sink.OutputDebugString.widestring.dll.debug.obj

OBJ_EX_boolean_DLL_R		=   $(PROJ_OBJ_DIR)\example.arguments.boolean.dll.obj
OBJ_EX_character_DLL_R		=   $(PROJ_OBJ_DIR)\example.arguments.character.dll.obj
OBJ_EX_reals_DLL_R			=   $(PROJ_OBJ_DIR)\example.arguments.reals.dll.obj
OBJ_EX_voidptrs_DLL_R		=   $(PROJ_OBJ_DIR)\example.arguments.void_pointers.dll.obj
OBJ_EX_ff_101_DLL_R		=   $(PROJ_OBJ_DIR)\example.ff_101.dll.obj
OBJ_EX_ff_101_nons_DLL_R	=   $(PROJ_OBJ_DIR)\example.ff_101.no_namespace.dll.obj
OBJ_EX_flush_DLL_R			=	$(PROJ_OBJ_DIR)\example.flush.dll.obj
OBJ_EX_ins_hex_DLL_R		=	$(PROJ_OBJ_DIR)\example.inserter.hex.dll.obj
OBJ_EX_ins_integers_DLL_R	=	$(PROJ_OBJ_DIR)\example.inserter.integers.dll.obj
OBJ_EX_ins_reals_DLL_R		=	$(PROJ_OBJ_DIR)\example.inserter.reals.dll.obj
OBJ_EX_ins_WLIs_DLL_R		=	$(PROJ_OBJ_DIR)\example.inserter.WLIs.dll.obj
OBJ_EX_itr_fmt_DLL_R		=	$(PROJ_OBJ_DIR)\example.itrs.fmt_itr.dll.obj
OBJ_EX_ovld2_filt_DLL_R	=   $(PROJ_OBJ_DIR)\example.ovld.2.hero.filter.dll.obj
OBJ_EX_ovld2_ins_DLL_R		=   $(PROJ_OBJ_DIR)\example.ovld.2.hero.inserter.dll.obj
OBJ_EX_ovld2_sas_DLL_R		=   $(PROJ_OBJ_DIR)\example.ovld.2.hero.sas.dll.obj
OBJ_EX_ovld3_fpcol_DLL_R	=   $(PROJ_OBJ_DIR)\example.ovld.3.flpt.cols.dll.obj
OBJ_EX_ovld3_tabs_DLL_R	=   $(PROJ_OBJ_DIR)\example.ovld.3.tabs.dll.obj
OBJ_EX_ovld3_svrlg_DLL_R	=   $(PROJ_OBJ_DIR)\example.ovld.3.svr.log.dll.obj
OBJ_EX_ovld3_rcins_DLL_R	=   $(PROJ_OBJ_DIR)\example.ovld.3.rec.ins.dll.obj
OBJ_EX_pad_hash_DLL_R		=	$(PROJ_OBJ_DIR)\example.pad.hash.dll.obj
OBJ_EX_sink_cstr_DLL_R		=	$(PROJ_OBJ_DIR)\example.sink.c_string.dll.obj
OBJ_EX_sink_ODS_DLL_R		=   $(PROJ_OBJ_DIR)\example.sink.OutputDebugString.dll.obj

OBJ_EX_boolean_DLL_R_W		=   $(PROJ_OBJ_DIR)\example.arguments.boolean.widestring.dll.obj
OBJ_EX_character_DLL_R_W		=   $(PROJ_OBJ_DIR)\example.arguments.character.widestring.dll.obj
OBJ_EX_reals_DLL_R_W			=   $(PROJ_OBJ_DIR)\example.arguments.reals.widestring.dll.obj
OBJ_EX_voidptrs_DLL_R_W		=   $(PROJ_OBJ_DIR)\example.arguments.void_pointers.widestring.dll.obj
OBJ_EX_itr_fmt_DLL_R_W		=	$(PROJ_OBJ_DIR)\example.itrs.fmt_itr.widestring.dll.obj
OBJ_EX_sink_ODS_DLL_R_W		=   $(PROJ_OBJ_DIR)\example.sink.OutputDebugString.widestring.dll.obj

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

OBJ_EX_boolean_MT_R_W		=   $(PROJ_OBJ_DIR)\example.arguments.boolean.widestring.mt.obj
OBJ_EX_character_MT_R_W		=   $(PROJ_OBJ_DIR)\example.arguments.character.widestring.mt.obj
OBJ_EX_reals_MT_R_W			=   $(PROJ_OBJ_DIR)\example.arguments.reals.widestring.mt.obj
OBJ_EX_voidptrs_MT_R_W		=   $(PROJ_OBJ_DIR)\example.arguments.void_pointers.widestring.mt.obj
OBJ_EX_itr_fmt_MT_R_W		=	$(PROJ_OBJ_DIR)\example.itrs.fmt_itr.widestring.mt.obj
OBJ_EX_sink_ODS_MT_R_W		=   $(PROJ_OBJ_DIR)\example.sink.OutputDebugString.widestring.mt.obj


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
OBJ_TEST_COMP_file_MT_D_W			=   $(PROJ_OBJ_DIR)\test.component.FILE.widestring.mt.debug.obj
OBJ_TEST_COMP_fmt_sink_MT_D_W		=   $(PROJ_OBJ_DIR)\test.component.sink.string.fmt.widestring.mt.debug.obj
OBJ_TEST_COMP_ins_hex_MT_D_W		=   $(PROJ_OBJ_DIR)\test.component.inserter.hex.widestring.mt.debug.obj
OBJ_TEST_COMP_ins_int_MT_D_W		=   $(PROJ_OBJ_DIR)\test.component.inserter.integer.widestring.mt.debug.obj
OBJ_TEST_COMP_ins_real_MT_D_W		=   $(PROJ_OBJ_DIR)\test.component.inserter.real.widestring.mt.debug.obj
OBJ_TEST_COMP_itr_fmt_MT_D_W		=   $(PROJ_OBJ_DIR)\test.component.itrs.fmt_itr.widestring.mt.debug.obj
OBJ_TEST_COMP_null_sink_MT_D_W		=   $(PROJ_OBJ_DIR)\test.component.sink.null.widestring.mt.debug.obj
OBJ_TEST_COMP_snk_a_b_MT_D_W		=   $(PROJ_OBJ_DIR)\test.component.sink.auto_buffer.widestring.mt.debug.obj
OBJ_TEST_COMP_write_sink_MT_D_W		=   $(PROJ_OBJ_DIR)\test.component.sink.string.write.widestring.mt.debug.obj
OBJ_TEST_COMP_x_1_MT_D_W			=   $(PROJ_OBJ_DIR)\test.component.fsde.widestring.mt.debug.obj
OBJ_TEST_COMP_snk_ostm_MT_D_W		=   $(PROJ_OBJ_DIR)\test.component.sink.ostream.widestring.mt.debug.obj
OBJ_TEST_COMP_file_DLL_D			=   $(PROJ_OBJ_DIR)\test.component.FILE.dll.debug.obj
OBJ_TEST_COMP_fmt_sink_DLL_D		=   $(PROJ_OBJ_DIR)\test.component.sink.string.fmt.dll.debug.obj
OBJ_TEST_COMP_ins_hex_DLL_D		=   $(PROJ_OBJ_DIR)\test.component.inserter.hex.dll.debug.obj
OBJ_TEST_COMP_ins_int_DLL_D		=   $(PROJ_OBJ_DIR)\test.component.inserter.integer.dll.debug.obj
OBJ_TEST_COMP_ins_real_DLL_D		=   $(PROJ_OBJ_DIR)\test.component.inserter.real.dll.debug.obj
OBJ_TEST_COMP_itr_fmt_DLL_D		=   $(PROJ_OBJ_DIR)\test.component.itrs.fmt_itr.dll.debug.obj
OBJ_TEST_COMP_null_sink_DLL_D		=   $(PROJ_OBJ_DIR)\test.component.sink.null.dll.debug.obj
OBJ_TEST_COMP_snk_a_b_DLL_D		=   $(PROJ_OBJ_DIR)\test.component.sink.auto_buffer.dll.debug.obj
OBJ_TEST_COMP_write_sink_DLL_D		=   $(PROJ_OBJ_DIR)\test.component.sink.string.write.dll.debug.obj
OBJ_TEST_COMP_x_1_DLL_D			=   $(PROJ_OBJ_DIR)\test.component.fsde.dll.debug.obj
OBJ_TEST_COMP_snk_ostm_DLL_D		=   $(PROJ_OBJ_DIR)\test.component.sink.ostream.dll.debug.obj
OBJ_TEST_COMP_file_DLL_D_W			=   $(PROJ_OBJ_DIR)\test.component.FILE.widestring.dll.debug.obj
OBJ_TEST_COMP_fmt_sink_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.component.sink.string.fmt.widestring.dll.debug.obj
OBJ_TEST_COMP_ins_hex_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.component.inserter.hex.widestring.dll.debug.obj
OBJ_TEST_COMP_ins_int_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.component.inserter.integer.widestring.dll.debug.obj
OBJ_TEST_COMP_ins_real_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.component.inserter.real.widestring.dll.debug.obj
OBJ_TEST_COMP_itr_fmt_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.component.itrs.fmt_itr.widestring.dll.debug.obj
OBJ_TEST_COMP_null_sink_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.component.sink.null.widestring.dll.debug.obj
OBJ_TEST_COMP_snk_a_b_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.component.sink.auto_buffer.widestring.dll.debug.obj
OBJ_TEST_COMP_write_sink_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.component.sink.string.write.widestring.dll.debug.obj
OBJ_TEST_COMP_x_1_DLL_D_W			=   $(PROJ_OBJ_DIR)\test.component.fsde.widestring.dll.debug.obj
OBJ_TEST_COMP_snk_ostm_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.component.sink.ostream.widestring.dll.debug.obj
OBJ_TEST_COMP_file_DLL_R			=   $(PROJ_OBJ_DIR)\test.component.FILE.dll.obj
OBJ_TEST_COMP_fmt_sink_DLL_R		=   $(PROJ_OBJ_DIR)\test.component.sink.string.fmt.dll.obj
OBJ_TEST_COMP_ins_hex_DLL_R		=   $(PROJ_OBJ_DIR)\test.component.inserter.hex.dll.obj
OBJ_TEST_COMP_ins_int_DLL_R		=   $(PROJ_OBJ_DIR)\test.component.inserter.integer.dll.obj
OBJ_TEST_COMP_ins_real_DLL_R		=   $(PROJ_OBJ_DIR)\test.component.inserter.real.dll.obj
OBJ_TEST_COMP_itr_fmt_DLL_R		=   $(PROJ_OBJ_DIR)\test.component.itrs.fmt_itr.dll.obj
OBJ_TEST_COMP_null_sink_DLL_R		=   $(PROJ_OBJ_DIR)\test.component.sink.null.dll.obj
OBJ_TEST_COMP_snk_a_b_DLL_R		=   $(PROJ_OBJ_DIR)\test.component.sink.auto_buffer.dll.obj
OBJ_TEST_COMP_write_sink_DLL_R		=   $(PROJ_OBJ_DIR)\test.component.sink.string.write.dll.obj
OBJ_TEST_COMP_x_1_DLL_R			=   $(PROJ_OBJ_DIR)\test.component.fsde.dll.obj
OBJ_TEST_COMP_snk_ostm_DLL_R		=   $(PROJ_OBJ_DIR)\test.component.sink.ostream.dll.obj
OBJ_TEST_COMP_file_DLL_R_W			=   $(PROJ_OBJ_DIR)\test.component.FILE.widestring.dll.obj
OBJ_TEST_COMP_fmt_sink_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.component.sink.string.fmt.widestring.dll.obj
OBJ_TEST_COMP_ins_hex_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.component.inserter.hex.widestring.dll.obj
OBJ_TEST_COMP_ins_int_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.component.inserter.integer.widestring.dll.obj
OBJ_TEST_COMP_ins_real_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.component.inserter.real.widestring.dll.obj
OBJ_TEST_COMP_itr_fmt_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.component.itrs.fmt_itr.widestring.dll.obj
OBJ_TEST_COMP_null_sink_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.component.sink.null.widestring.dll.obj
OBJ_TEST_COMP_snk_a_b_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.component.sink.auto_buffer.widestring.dll.obj
OBJ_TEST_COMP_write_sink_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.component.sink.string.write.widestring.dll.obj
OBJ_TEST_COMP_x_1_DLL_R_W			=   $(PROJ_OBJ_DIR)\test.component.fsde.widestring.dll.obj
OBJ_TEST_COMP_snk_ostm_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.component.sink.ostream.widestring.dll.obj
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
OBJ_TEST_COMP_file_MT_R_W			=   $(PROJ_OBJ_DIR)\test.component.FILE.widestring.mt.obj
OBJ_TEST_COMP_fmt_sink_MT_R_W		=   $(PROJ_OBJ_DIR)\test.component.sink.string.fmt.widestring.mt.obj
OBJ_TEST_COMP_ins_hex_MT_R_W		=   $(PROJ_OBJ_DIR)\test.component.inserter.hex.widestring.mt.obj
OBJ_TEST_COMP_ins_int_MT_R_W		=   $(PROJ_OBJ_DIR)\test.component.inserter.integer.widestring.mt.obj
OBJ_TEST_COMP_ins_real_MT_R_W		=   $(PROJ_OBJ_DIR)\test.component.inserter.real.widestring.mt.obj
OBJ_TEST_COMP_itr_fmt_MT_R_W		=   $(PROJ_OBJ_DIR)\test.component.itrs.fmt_itr.widestring.mt.obj
OBJ_TEST_COMP_null_sink_MT_R_W		=   $(PROJ_OBJ_DIR)\test.component.sink.null.widestring.mt.obj
OBJ_TEST_COMP_snk_a_b_MT_R_W		=   $(PROJ_OBJ_DIR)\test.component.sink.auto_buffer.widestring.mt.obj
OBJ_TEST_COMP_write_sink_MT_R_W		=   $(PROJ_OBJ_DIR)\test.component.sink.string.write.widestring.mt.obj
OBJ_TEST_COMP_x_1_MT_R_W			=   $(PROJ_OBJ_DIR)\test.component.fsde.widestring.mt.obj
OBJ_TEST_COMP_snk_ostm_MT_R_W		=   $(PROJ_OBJ_DIR)\test.component.sink.ostream.widestring.mt.obj

##############################
# Performance Tests

OBJ_TEST_PERF_scen1_MT_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario1.mt.debug.obj
OBJ_TEST_PERF_scen2_MT_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario2.mt.debug.obj
OBJ_TEST_PERF_scen3_MT_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario3.mt.debug.obj
OBJ_TEST_PERF_scen4_MT_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario4.mt.debug.obj
OBJ_TEST_PERF_scen5_MT_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario5.mt.debug.obj
OBJ_TEST_PERF_scen6_MT_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario6.mt.debug.obj
OBJ_TEST_PERF_scen7_MT_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario7.mt.debug.obj
!ifdef BOOST
OBJ_TEST_PERF_scen8_MT_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario8.mt.debug.obj
!endif # BOOST
OBJ_TEST_PERF_scen1_MT_D_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario1.widestring.mt.debug.obj
OBJ_TEST_PERF_scen2_MT_D_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario2.widestring.mt.debug.obj
OBJ_TEST_PERF_scen3_MT_D_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario3.widestring.mt.debug.obj
OBJ_TEST_PERF_scen4_MT_D_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario4.widestring.mt.debug.obj
OBJ_TEST_PERF_scen5_MT_D_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario5.widestring.mt.debug.obj
OBJ_TEST_PERF_scen6_MT_D_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario6.widestring.mt.debug.obj
OBJ_TEST_PERF_scen7_MT_D_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario7.widestring.mt.debug.obj
!ifdef BOOST
OBJ_TEST_PERF_scen8_MT_D_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario8.widestring.mt.debug.obj
!endif # BOOST
OBJ_TEST_PERF_scen1_DLL_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario1.dll.debug.obj
OBJ_TEST_PERF_scen2_DLL_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario2.dll.debug.obj
OBJ_TEST_PERF_scen3_DLL_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario3.dll.debug.obj
OBJ_TEST_PERF_scen4_DLL_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario4.dll.debug.obj
OBJ_TEST_PERF_scen5_DLL_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario5.dll.debug.obj
OBJ_TEST_PERF_scen6_DLL_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario6.dll.debug.obj
OBJ_TEST_PERF_scen7_DLL_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario7.dll.debug.obj
!ifdef BOOST
OBJ_TEST_PERF_scen8_DLL_D			=   $(PROJ_OBJ_DIR)\test.performance.scenario8.dll.debug.obj
!endif # BOOST
OBJ_TEST_PERF_scen1_DLL_D_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario1.widestring.dll.debug.obj
OBJ_TEST_PERF_scen2_DLL_D_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario2.widestring.dll.debug.obj
OBJ_TEST_PERF_scen3_DLL_D_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario3.widestring.dll.debug.obj
OBJ_TEST_PERF_scen4_DLL_D_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario4.widestring.dll.debug.obj
OBJ_TEST_PERF_scen5_DLL_D_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario5.widestring.dll.debug.obj
OBJ_TEST_PERF_scen6_DLL_D_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario6.widestring.dll.debug.obj
OBJ_TEST_PERF_scen7_DLL_D_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario7.widestring.dll.debug.obj
!ifdef BOOST
OBJ_TEST_PERF_scen8_DLL_D_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario8.widestring.dll.debug.obj
!endif # BOOST
OBJ_TEST_PERF_scen1_DLL_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario1.dll.obj
OBJ_TEST_PERF_scen2_DLL_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario2.dll.obj
OBJ_TEST_PERF_scen3_DLL_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario3.dll.obj
OBJ_TEST_PERF_scen4_DLL_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario4.dll.obj
OBJ_TEST_PERF_scen5_DLL_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario5.dll.obj
OBJ_TEST_PERF_scen6_DLL_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario6.dll.obj
OBJ_TEST_PERF_scen7_DLL_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario7.dll.obj
!ifdef BOOST
OBJ_TEST_PERF_scen8_DLL_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario8.dll.obj
!endif # BOOST
OBJ_TEST_PERF_scen1_DLL_R_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario1.widestring.dll.obj
OBJ_TEST_PERF_scen2_DLL_R_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario2.widestring.dll.obj
OBJ_TEST_PERF_scen3_DLL_R_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario3.widestring.dll.obj
OBJ_TEST_PERF_scen4_DLL_R_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario4.widestring.dll.obj
OBJ_TEST_PERF_scen5_DLL_R_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario5.widestring.dll.obj
OBJ_TEST_PERF_scen6_DLL_R_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario6.widestring.dll.obj
OBJ_TEST_PERF_scen7_DLL_R_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario7.widestring.dll.obj
!ifdef BOOST
OBJ_TEST_PERF_scen8_DLL_R_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario8.widestring.dll.obj
!endif # BOOST
OBJ_TEST_PERF_scen1_MT_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario1.mt.obj
OBJ_TEST_PERF_scen2_MT_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario2.mt.obj
OBJ_TEST_PERF_scen3_MT_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario3.mt.obj
OBJ_TEST_PERF_scen4_MT_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario4.mt.obj
OBJ_TEST_PERF_scen5_MT_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario5.mt.obj
OBJ_TEST_PERF_scen6_MT_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario6.mt.obj
OBJ_TEST_PERF_scen7_MT_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario7.mt.obj
!ifdef BOOST
OBJ_TEST_PERF_scen8_MT_R			=   $(PROJ_OBJ_DIR)\test.performance.scenario8.mt.obj
!endif # BOOST
OBJ_TEST_PERF_scen1_MT_R_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario1.widestring.mt.obj
OBJ_TEST_PERF_scen2_MT_R_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario2.widestring.mt.obj
OBJ_TEST_PERF_scen3_MT_R_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario3.widestring.mt.obj
OBJ_TEST_PERF_scen4_MT_R_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario4.widestring.mt.obj
OBJ_TEST_PERF_scen5_MT_R_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario5.widestring.mt.obj
OBJ_TEST_PERF_scen6_MT_R_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario6.widestring.mt.obj
OBJ_TEST_PERF_scen7_MT_R_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario7.widestring.mt.obj
!ifdef BOOST
OBJ_TEST_PERF_scen8_MT_R_W			=   $(PROJ_OBJ_DIR)\test.performance.scenario8.widestring.mt.obj
!endif # BOOST

##############################
# Scratch Tests

OBJ_TEST_SCRT_file_MT_D =   $(PROJ_OBJ_DIR)\test.scratch.FILE.mt.debug.obj
OBJ_TEST_SCRT_file_MT_D_W =   $(PROJ_OBJ_DIR)\test.scratch.FILE.widestring.mt.debug.obj
OBJ_TEST_SCRT_file_DLL_D =   $(PROJ_OBJ_DIR)\test.scratch.FILE.dll.debug.obj
OBJ_TEST_SCRT_file_DLL_D_W =   $(PROJ_OBJ_DIR)\test.scratch.FILE.widestring.dll.debug.obj
OBJ_TEST_SCRT_file_DLL_R =   $(PROJ_OBJ_DIR)\test.scratch.FILE.dll.obj
OBJ_TEST_SCRT_file_DLL_R_W =   $(PROJ_OBJ_DIR)\test.scratch.FILE.widestring.dll.obj
OBJ_TEST_SCRT_file_MT_R =   $(PROJ_OBJ_DIR)\test.scratch.FILE.mt.obj
OBJ_TEST_SCRT_file_MT_R_W =   $(PROJ_OBJ_DIR)\test.scratch.FILE.widestring.mt.obj

OBJ_TEST_SCRT_speech_MT_D =   $(PROJ_OBJ_DIR)\test.scratch.speech.mt.debug.obj
OBJ_TEST_SCRT_speech_MT_D_W =   $(PROJ_OBJ_DIR)\test.scratch.speech.widestring.mt.debug.obj
OBJ_TEST_SCRT_speech_DLL_D =   $(PROJ_OBJ_DIR)\test.scratch.speech.dll.debug.obj
OBJ_TEST_SCRT_speech_DLL_D_W =   $(PROJ_OBJ_DIR)\test.scratch.speech.widestring.dll.debug.obj
OBJ_TEST_SCRT_speech_DLL_R =   $(PROJ_OBJ_DIR)\test.scratch.speech.dll.obj
OBJ_TEST_SCRT_speech_DLL_R_W =   $(PROJ_OBJ_DIR)\test.scratch.speech.widestring.dll.obj
OBJ_TEST_SCRT_speech_MT_R =   $(PROJ_OBJ_DIR)\test.scratch.speech.mt.obj
OBJ_TEST_SCRT_speech_MT_R_W =   $(PROJ_OBJ_DIR)\test.scratch.speech.widestring.mt.obj

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
OBJ_TEST_UNIT_ins_ss_MT_D			=   $(PROJ_OBJ_DIR)\test.unit.inserters.storage_size.mt.debug.obj
OBJ_TEST_UNIT_shim_fi_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.shims.fast_integers.mt.debug.obj
OBJ_TEST_UNIT_shim_ns_1_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.main.mt.debug.obj
OBJ_TEST_UNIT_shim_ns_2_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.with.mt.debug.obj
OBJ_TEST_UNIT_shim_ns_3_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.no_ff.mt.debug.obj
OBJ_TEST_UNIT_shim_ns_4_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.no_ss.mt.debug.obj
OBJ_TEST_UNIT_shim_ns_5_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.none.mt.debug.obj
OBJ_TEST_UNIT_snk_a_b_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.auto_buffer.mt.debug.obj
OBJ_TEST_UNIT_snk_c_str_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.c_string.mt.debug.obj
OBJ_TEST_UNIT_snk_chbuf_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.char_buffer.mt.debug.obj
OBJ_TEST_UNIT_snk_null_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.null.mt.debug.obj
OBJ_TEST_UNIT_snk_ods_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.ODS.mt.debug.obj
OBJ_TEST_UNIT_snk_ostm_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.ostream.mt.debug.obj
OBJ_TEST_UNIT_snk_sstm_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.stringstream.mt.debug.obj

OBJ_TEST_UNIT_api_acsllen_MT_D_W	=   $(PROJ_OBJ_DIR)\test.unit.api.accum_slice_lens.widestring.mt.debug.obj
OBJ_TEST_UNIT_api_crlf_MT_D_W		=   $(PROJ_OBJ_DIR)\test.unit.api.crlf_for_platform.widestring.mt.debug.obj
OBJ_TEST_UNIT_api_flrpl_MT_D_W		=   $(PROJ_OBJ_DIR)\test.unit.api.fill_replacements.widestring.mt.debug.obj
OBJ_TEST_UNIT_api_illfmdh_MT_D_W	=   $(PROJ_OBJ_DIR)\test.unit.api.illformed_handlers.widestring.mt.debug.obj
OBJ_TEST_UNIT_api_init_MT_D_W		=   $(PROJ_OBJ_DIR)\test.unit.api.initialisation.widestring.mt.debug.obj
OBJ_TEST_UNIT_api_lkptrn_MT_D_W		=   $(PROJ_OBJ_DIR)\test.unit.api.lookup_pattern.widestring.mt.debug.obj
OBJ_TEST_UNIT_api_msmtchh_MT_D_W	=   $(PROJ_OBJ_DIR)\test.unit.api.mismatched_handlers.widestring.mt.debug.obj
OBJ_TEST_UNIT_api_prsrpl_MT_D_W		=   $(PROJ_OBJ_DIR)\test.unit.api.parse_format.widestring.mt.debug.obj
OBJ_TEST_UNIT_bndl_winini_MT_D_W	=   $(PROJ_OBJ_DIR)\test.unit.bundle.winini.widestring.mt.debug.obj
OBJ_TEST_UNIT_fmt_stdfl_MT_D_W		=   $(PROJ_OBJ_DIR)\test.unit.format.standard_flags.widestring.mt.debug.obj
OBJ_TEST_UNIT_ins_ch_MT_D_W			=   $(PROJ_OBJ_DIR)\test.unit.inserters.character.widestring.mt.debug.obj
OBJ_TEST_UNIT_ins_i_MT_D_W			=   $(PROJ_OBJ_DIR)\test.unit.inserters.integer.widestring.mt.debug.obj
OBJ_TEST_UNIT_ins_ss_MT_D_W			=   $(PROJ_OBJ_DIR)\test.unit.inserters.storage_size.widestring.mt.debug.obj
OBJ_TEST_UNIT_shim_fi_MT_D_W		=   $(PROJ_OBJ_DIR)\test.unit.shims.fast_integers.widestring.mt.debug.obj
OBJ_TEST_UNIT_shim_ns_1_MT_D_W		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.main.widestring.mt.debug.obj
OBJ_TEST_UNIT_shim_ns_2_MT_D_W		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.with.widestring.mt.debug.obj
OBJ_TEST_UNIT_shim_ns_3_MT_D_W		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.no_ff.widestring.mt.debug.obj
OBJ_TEST_UNIT_shim_ns_4_MT_D_W		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.no_ss.widestring.mt.debug.obj
OBJ_TEST_UNIT_shim_ns_5_MT_D_W		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.none.widestring.mt.debug.obj
OBJ_TEST_UNIT_snk_a_b_MT_D_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.auto_buffer.widestring.mt.debug.obj
OBJ_TEST_UNIT_snk_c_str_MT_D_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.c_string.widestring.mt.debug.obj
OBJ_TEST_UNIT_snk_chbuf_MT_D_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.char_buffer.widestring.mt.debug.obj
OBJ_TEST_UNIT_snk_null_MT_D_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.null.widestring.mt.debug.obj
OBJ_TEST_UNIT_snk_ods_MT_D_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.ODS.widestring.mt.debug.obj
OBJ_TEST_UNIT_snk_ostm_MT_D_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.ostream.widestring.mt.debug.obj
OBJ_TEST_UNIT_snk_sstm_MT_D_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.stringstream.widestring.mt.debug.obj

OBJ_TEST_UNIT_api_acsllen_DLL_D	=   $(PROJ_OBJ_DIR)\test.unit.api.accum_slice_lens.dll.debug.obj
OBJ_TEST_UNIT_api_crlf_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.api.crlf_for_platform.dll.debug.obj
OBJ_TEST_UNIT_api_flrpl_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.api.fill_replacements.dll.debug.obj
OBJ_TEST_UNIT_api_illfmdh_DLL_D	=   $(PROJ_OBJ_DIR)\test.unit.api.illformed_handlers.dll.debug.obj
OBJ_TEST_UNIT_api_init_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.api.initialisation.dll.debug.obj
OBJ_TEST_UNIT_api_lkptrn_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.api.lookup_pattern.dll.debug.obj
OBJ_TEST_UNIT_api_msmtchh_DLL_D	=   $(PROJ_OBJ_DIR)\test.unit.api.mismatched_handlers.dll.debug.obj
OBJ_TEST_UNIT_api_prsrpl_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.api.parse_format.dll.debug.obj
OBJ_TEST_UNIT_bndl_winini_DLL_D	=   $(PROJ_OBJ_DIR)\test.unit.bundle.winini.dll.debug.obj
OBJ_TEST_UNIT_fmt_stdfl_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.format.standard_flags.dll.debug.obj
OBJ_TEST_UNIT_ins_ch_DLL_D			=   $(PROJ_OBJ_DIR)\test.unit.inserters.character.dll.debug.obj
OBJ_TEST_UNIT_ins_i_DLL_D			=   $(PROJ_OBJ_DIR)\test.unit.inserters.integer.dll.debug.obj
OBJ_TEST_UNIT_ins_ss_DLL_D			=   $(PROJ_OBJ_DIR)\test.unit.inserters.storage_size.dll.debug.obj
OBJ_TEST_UNIT_shim_fi_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.shims.fast_integers.dll.debug.obj
OBJ_TEST_UNIT_shim_ns_1_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.main.dll.debug.obj
OBJ_TEST_UNIT_shim_ns_2_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.with.dll.debug.obj
OBJ_TEST_UNIT_shim_ns_3_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.no_ff.dll.debug.obj
OBJ_TEST_UNIT_shim_ns_4_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.no_ss.dll.debug.obj
OBJ_TEST_UNIT_shim_ns_5_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.none.dll.debug.obj
OBJ_TEST_UNIT_snk_a_b_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.auto_buffer.dll.debug.obj
OBJ_TEST_UNIT_snk_c_str_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.c_string.dll.debug.obj
OBJ_TEST_UNIT_snk_chbuf_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.char_buffer.dll.debug.obj
OBJ_TEST_UNIT_snk_mfccstr_DLL_D	=   $(PROJ_OBJ_DIR)\test.unit.sink.CString.dll.debug.obj
OBJ_TEST_UNIT_snk_null_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.null.dll.debug.obj
OBJ_TEST_UNIT_snk_ods_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.ODS.dll.debug.obj
OBJ_TEST_UNIT_snk_ostm_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.ostream.dll.debug.obj
OBJ_TEST_UNIT_snk_sstm_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.sink.stringstream.dll.debug.obj

OBJ_TEST_UNIT_api_acsllen_DLL_D_W	=   $(PROJ_OBJ_DIR)\test.unit.api.accum_slice_lens.widestring.dll.debug.obj
OBJ_TEST_UNIT_api_crlf_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.unit.api.crlf_for_platform.widestring.dll.debug.obj
OBJ_TEST_UNIT_api_flrpl_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.unit.api.fill_replacements.widestring.dll.debug.obj
OBJ_TEST_UNIT_api_illfmdh_DLL_D_W	=   $(PROJ_OBJ_DIR)\test.unit.api.illformed_handlers.widestring.dll.debug.obj
OBJ_TEST_UNIT_api_init_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.unit.api.initialisation.widestring.dll.debug.obj
OBJ_TEST_UNIT_api_lkptrn_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.unit.api.lookup_pattern.widestring.dll.debug.obj
OBJ_TEST_UNIT_api_msmtchh_DLL_D_W	=   $(PROJ_OBJ_DIR)\test.unit.api.mismatched_handlers.widestring.dll.debug.obj
OBJ_TEST_UNIT_api_prsrpl_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.unit.api.parse_format.widestring.dll.debug.obj
OBJ_TEST_UNIT_bndl_winini_DLL_D_W	=   $(PROJ_OBJ_DIR)\test.unit.bundle.winini.widestring.dll.debug.obj
OBJ_TEST_UNIT_fmt_stdfl_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.unit.format.standard_flags.widestring.dll.debug.obj
OBJ_TEST_UNIT_ins_ch_DLL_D_W			=   $(PROJ_OBJ_DIR)\test.unit.inserters.character.widestring.dll.debug.obj
OBJ_TEST_UNIT_ins_i_DLL_D_W			=   $(PROJ_OBJ_DIR)\test.unit.inserters.integer.widestring.dll.debug.obj
OBJ_TEST_UNIT_ins_ss_DLL_D_W			=   $(PROJ_OBJ_DIR)\test.unit.inserters.storage_size.widestring.dll.debug.obj
OBJ_TEST_UNIT_shim_fi_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.unit.shims.fast_integers.widestring.dll.debug.obj
OBJ_TEST_UNIT_shim_ns_1_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.main.widestring.dll.debug.obj
OBJ_TEST_UNIT_shim_ns_2_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.with.widestring.dll.debug.obj
OBJ_TEST_UNIT_shim_ns_3_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.no_ff.widestring.dll.debug.obj
OBJ_TEST_UNIT_shim_ns_4_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.no_ss.widestring.dll.debug.obj
OBJ_TEST_UNIT_shim_ns_5_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.none.widestring.dll.debug.obj
OBJ_TEST_UNIT_snk_a_b_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.auto_buffer.widestring.dll.debug.obj
OBJ_TEST_UNIT_snk_c_str_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.c_string.widestring.dll.debug.obj
OBJ_TEST_UNIT_snk_chbuf_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.char_buffer.widestring.dll.debug.obj
OBJ_TEST_UNIT_snk_mfccstr_DLL_D_W	=   $(PROJ_OBJ_DIR)\test.unit.sink.CString.widestring.dll.debug.obj
OBJ_TEST_UNIT_snk_null_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.null.widestring.dll.debug.obj
OBJ_TEST_UNIT_snk_ods_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.ODS.widestring.dll.debug.obj
OBJ_TEST_UNIT_snk_ostm_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.ostream.widestring.dll.debug.obj
OBJ_TEST_UNIT_snk_sstm_DLL_D_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.stringstream.widestring.dll.debug.obj

OBJ_TEST_UNIT_api_acsllen_DLL_R	=   $(PROJ_OBJ_DIR)\test.unit.api.accum_slice_lens.dll.obj
OBJ_TEST_UNIT_api_crlf_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.api.crlf_for_platform.dll.obj
OBJ_TEST_UNIT_api_flrpl_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.api.fill_replacements.dll.obj
OBJ_TEST_UNIT_api_illfmdh_DLL_R	=   $(PROJ_OBJ_DIR)\test.unit.api.illformed_handlers.dll.obj
OBJ_TEST_UNIT_api_init_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.api.initialisation.dll.obj
OBJ_TEST_UNIT_api_lkptrn_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.api.lookup_pattern.dll.obj
OBJ_TEST_UNIT_api_msmtchh_DLL_R	=   $(PROJ_OBJ_DIR)\test.unit.api.mismatched_handlers.dll.obj
OBJ_TEST_UNIT_api_prsrpl_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.api.parse_format.dll.obj
OBJ_TEST_UNIT_bndl_winini_DLL_R	=   $(PROJ_OBJ_DIR)\test.unit.bundle.winini.dll.obj
OBJ_TEST_UNIT_fmt_stdfl_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.format.standard_flags.dll.obj
OBJ_TEST_UNIT_ins_ch_DLL_R			=   $(PROJ_OBJ_DIR)\test.unit.inserters.character.dll.obj
OBJ_TEST_UNIT_ins_i_DLL_R			=   $(PROJ_OBJ_DIR)\test.unit.inserters.integer.dll.obj
OBJ_TEST_UNIT_ins_ss_DLL_R			=   $(PROJ_OBJ_DIR)\test.unit.inserters.storage_size.dll.obj
OBJ_TEST_UNIT_shim_fi_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.shims.fast_integers.dll.obj
OBJ_TEST_UNIT_shim_ns_1_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.main.dll.obj
OBJ_TEST_UNIT_shim_ns_2_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.with.dll.obj
OBJ_TEST_UNIT_shim_ns_3_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.no_ff.dll.obj
OBJ_TEST_UNIT_shim_ns_4_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.no_ss.dll.obj
OBJ_TEST_UNIT_shim_ns_5_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.none.dll.obj
OBJ_TEST_UNIT_snk_a_b_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.auto_buffer.dll.obj
OBJ_TEST_UNIT_snk_c_str_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.c_string.dll.obj
OBJ_TEST_UNIT_snk_chbuf_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.char_buffer.dll.obj
OBJ_TEST_UNIT_snk_mfccstr_DLL_R	=   $(PROJ_OBJ_DIR)\test.unit.sink.CString.dll.obj
OBJ_TEST_UNIT_snk_null_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.null.dll.obj
OBJ_TEST_UNIT_snk_ods_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.ODS.dll.obj
OBJ_TEST_UNIT_snk_ostm_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.ostream.dll.obj
OBJ_TEST_UNIT_snk_sstm_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.stringstream.dll.obj

OBJ_TEST_UNIT_api_acsllen_DLL_R_W	=   $(PROJ_OBJ_DIR)\test.unit.api.accum_slice_lens.widestring.dll.obj
OBJ_TEST_UNIT_api_crlf_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.unit.api.crlf_for_platform.widestring.dll.obj
OBJ_TEST_UNIT_api_flrpl_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.unit.api.fill_replacements.widestring.dll.obj
OBJ_TEST_UNIT_api_illfmdh_DLL_R_W	=   $(PROJ_OBJ_DIR)\test.unit.api.illformed_handlers.widestring.dll.obj
OBJ_TEST_UNIT_api_init_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.unit.api.initialisation.widestring.dll.obj
OBJ_TEST_UNIT_api_lkptrn_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.unit.api.lookup_pattern.widestring.dll.obj
OBJ_TEST_UNIT_api_msmtchh_DLL_R_W	=   $(PROJ_OBJ_DIR)\test.unit.api.mismatched_handlers.widestring.dll.obj
OBJ_TEST_UNIT_api_prsrpl_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.unit.api.parse_format.widestring.dll.obj
OBJ_TEST_UNIT_bndl_winini_DLL_R_W	=   $(PROJ_OBJ_DIR)\test.unit.bundle.winini.widestring.dll.obj
OBJ_TEST_UNIT_fmt_stdfl_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.unit.format.standard_flags.widestring.dll.obj
OBJ_TEST_UNIT_ins_ch_DLL_R_W			=   $(PROJ_OBJ_DIR)\test.unit.inserters.character.widestring.dll.obj
OBJ_TEST_UNIT_ins_i_DLL_R_W			=   $(PROJ_OBJ_DIR)\test.unit.inserters.integer.widestring.dll.obj
OBJ_TEST_UNIT_ins_ss_DLL_R_W			=   $(PROJ_OBJ_DIR)\test.unit.inserters.storage_size.widestring.dll.obj
OBJ_TEST_UNIT_shim_fi_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.unit.shims.fast_integers.widestring.dll.obj
OBJ_TEST_UNIT_shim_ns_1_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.main.widestring.dll.obj
OBJ_TEST_UNIT_shim_ns_2_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.with.widestring.dll.obj
OBJ_TEST_UNIT_shim_ns_3_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.no_ff.widestring.dll.obj
OBJ_TEST_UNIT_shim_ns_4_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.no_ss.widestring.dll.obj
OBJ_TEST_UNIT_shim_ns_5_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.none.widestring.dll.obj
OBJ_TEST_UNIT_snk_a_b_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.auto_buffer.widestring.dll.obj
OBJ_TEST_UNIT_snk_c_str_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.c_string.widestring.dll.obj
OBJ_TEST_UNIT_snk_chbuf_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.char_buffer.widestring.dll.obj
OBJ_TEST_UNIT_snk_mfccstr_DLL_R_W	=   $(PROJ_OBJ_DIR)\test.unit.sink.CString.widestring.dll.obj
OBJ_TEST_UNIT_snk_null_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.null.widestring.dll.obj
OBJ_TEST_UNIT_snk_ods_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.ODS.widestring.dll.obj
OBJ_TEST_UNIT_snk_ostm_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.ostream.widestring.dll.obj
OBJ_TEST_UNIT_snk_sstm_DLL_R_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.stringstream.widestring.dll.obj

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
OBJ_TEST_UNIT_ins_ss_MT_R			=   $(PROJ_OBJ_DIR)\test.unit.inserters.storage_size.mt.obj
OBJ_TEST_UNIT_shim_fi_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.shims.fast_integers.mt.obj
OBJ_TEST_UNIT_shim_ns_1_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.main.mt.obj
OBJ_TEST_UNIT_shim_ns_2_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.with.mt.obj
OBJ_TEST_UNIT_shim_ns_3_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.no_ff.mt.obj
OBJ_TEST_UNIT_shim_ns_4_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.no_ss.mt.obj
OBJ_TEST_UNIT_shim_ns_5_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.none.mt.obj
OBJ_TEST_UNIT_snk_a_b_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.auto_buffer.mt.obj
OBJ_TEST_UNIT_snk_c_str_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.c_string.mt.obj
OBJ_TEST_UNIT_snk_chbuf_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.char_buffer.mt.obj
OBJ_TEST_UNIT_snk_null_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.null.mt.obj
OBJ_TEST_UNIT_snk_ods_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.ODS.mt.obj
OBJ_TEST_UNIT_snk_ostm_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.ostream.mt.obj
OBJ_TEST_UNIT_snk_sstm_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.sink.stringstream.mt.obj

OBJ_TEST_UNIT_api_acsllen_MT_R_W	=   $(PROJ_OBJ_DIR)\test.unit.api.accum_slice_lens.widestring.mt.obj
OBJ_TEST_UNIT_api_crlf_MT_R_W		=   $(PROJ_OBJ_DIR)\test.unit.api.crlf_for_platform.widestring.mt.obj
OBJ_TEST_UNIT_api_flrpl_MT_R_W		=   $(PROJ_OBJ_DIR)\test.unit.api.fill_replacements.widestring.mt.obj
OBJ_TEST_UNIT_api_illfmdh_MT_R_W	=   $(PROJ_OBJ_DIR)\test.unit.api.illformed_handlers.widestring.mt.obj
OBJ_TEST_UNIT_api_init_MT_R_W		=   $(PROJ_OBJ_DIR)\test.unit.api.initialisation.widestring.mt.obj
OBJ_TEST_UNIT_api_lkptrn_MT_R_W		=   $(PROJ_OBJ_DIR)\test.unit.api.lookup_pattern.widestring.mt.obj
OBJ_TEST_UNIT_api_msmtchh_MT_R_W	=   $(PROJ_OBJ_DIR)\test.unit.api.mismatched_handlers.widestring.mt.obj
OBJ_TEST_UNIT_api_prsrpl_MT_R_W		=   $(PROJ_OBJ_DIR)\test.unit.api.parse_format.widestring.mt.obj
OBJ_TEST_UNIT_bndl_winini_MT_R_W	=   $(PROJ_OBJ_DIR)\test.unit.bundle.winini.widestring.mt.obj
OBJ_TEST_UNIT_fmt_stdfl_MT_R_W		=   $(PROJ_OBJ_DIR)\test.unit.format.standard_flags.widestring.mt.obj
OBJ_TEST_UNIT_ins_ch_MT_R_W			=   $(PROJ_OBJ_DIR)\test.unit.inserters.character.widestring.mt.obj
OBJ_TEST_UNIT_ins_i_MT_R_W			=   $(PROJ_OBJ_DIR)\test.unit.inserters.integer.widestring.mt.obj
OBJ_TEST_UNIT_ins_ss_MT_R_W			=   $(PROJ_OBJ_DIR)\test.unit.inserters.storage_size.widestring.mt.obj
OBJ_TEST_UNIT_shim_fi_MT_R_W		=   $(PROJ_OBJ_DIR)\test.unit.shims.fast_integers.widestring.mt.obj
OBJ_TEST_UNIT_shim_ns_1_MT_R_W		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.main.widestring.mt.obj
OBJ_TEST_UNIT_shim_ns_2_MT_R_W		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.with.widestring.mt.obj
OBJ_TEST_UNIT_shim_ns_3_MT_R_W		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.no_ff.widestring.mt.obj
OBJ_TEST_UNIT_shim_ns_4_MT_R_W		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.no_ss.widestring.mt.obj
OBJ_TEST_UNIT_shim_ns_5_MT_R_W		=   $(PROJ_OBJ_DIR)\test.unit.shims_and_namespaces.none.widestring.mt.obj
OBJ_TEST_UNIT_snk_a_b_MT_R_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.auto_buffer.widestring.mt.obj
OBJ_TEST_UNIT_snk_c_str_MT_R_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.c_string.widestring.mt.obj
OBJ_TEST_UNIT_snk_chbuf_MT_R_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.char_buffer.widestring.mt.obj
OBJ_TEST_UNIT_snk_null_MT_R_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.null.widestring.mt.obj
OBJ_TEST_UNIT_snk_ods_MT_R_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.ODS.widestring.mt.obj
OBJ_TEST_UNIT_snk_ostm_MT_R_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.ostream.widestring.mt.obj
OBJ_TEST_UNIT_snk_sstm_MT_R_W		=   $(PROJ_OBJ_DIR)\test.unit.sink.stringstream.widestring.mt.obj

##################################################
# Target groups

########################################
# Objects

# fastformat
OBJS_CORE = \
 $(OBJ_CORE_MT_D)\
 $(OBJ_CORE_MT_D_W)\
 $(OBJ_CORE_DLL_D)\
 $(OBJ_CORE_DLL_D_W)\
 $(OBJ_CORE_DLL_R)\
 $(OBJ_CORE_DLL_R_W)\
 $(OBJ_CORE_MT_R)\
 $(OBJ_CORE_MT_R_W)\
 \

# Loki.SafeFormat
OBJS_LOKI_SFMT = \
 $(OBJ_LOKI_SFMT_MT_D)\
 $(OBJ_LOKI_SFMT_MT_D_W)\
 $(OBJ_LOKI_SFMT_DLL_D)\
 $(OBJ_LOKI_SFMT_DLL_D_W)\
 $(OBJ_LOKI_SFMT_DLL_R)\
 $(OBJ_LOKI_SFMT_DLL_R_W)\
 $(OBJ_LOKI_SFMT_MT_R)\
 $(OBJ_LOKI_SFMT_MT_R_W)\
 \

# shwild
OBJS_SHWILD = \
 $(OBJ_SHWILD_MT_D)\
 $(OBJ_SHWILD_MT_D_W)\
 $(OBJ_SHWILD_DLL_D)\
 $(OBJ_SHWILD_DLL_D_W)\
 $(OBJ_SHWILD_DLL_R)\
 $(OBJ_SHWILD_DLL_R_W)\
 $(OBJ_SHWILD_MT_R)\
 $(OBJ_SHWILD_MT_R_W)\
 \

# xtests
OBJS_XTESTS = \
 $(OBJ_XTESTS_MT_D)\
 $(OBJ_XTESTS_MT_D_W)\
 $(OBJ_XTESTS_DLL_D)\
 $(OBJ_XTESTS_DLL_D_W)\
 $(OBJ_XTESTS_DLL_R)\
 $(OBJ_XTESTS_DLL_R_W)\
 $(OBJ_XTESTS_MT_R)\
 $(OBJ_XTESTS_MT_R_W)\
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
 $(OBJ_EX_boolean_MT_D_W)\
 $(OBJ_EX_character_MT_D_W)\
 $(OBJ_EX_reals_MT_D_W)\
 $(OBJ_EX_voidptrs_MT_D_W)\
 $(OBJ_EX_itr_fmt_MT_D_W)\
 $(OBJ_EX_sink_ODS_MT_D_W)\
 $(OBJ_EX_boolean_DLL_D)\
 $(OBJ_EX_character_DLL_D)\
 $(OBJ_EX_reals_DLL_D)\
 $(OBJ_EX_voidptrs_DLL_D)\
 $(OBJ_EX_ff_101_DLL_D)\
 $(OBJ_EX_ff_101_nons_DLL_D)\
 $(OBJ_EX_flush_DLL_D)\
 $(OBJ_EX_ins_hex_DLL_D)\
 $(OBJ_EX_ins_integers_DLL_D)\
 $(OBJ_EX_ins_reals_DLL_D)\
 $(OBJ_EX_ins_WLIs_DLL_D)\
 $(OBJ_EX_itr_fmt_DLL_D)\
 $(OBJ_EX_ovld2_filt_DLL_D)\
 $(OBJ_EX_ovld2_ins_DLL_D)\
 $(OBJ_EX_ovld2_sas_DLL_D)\
 $(OBJ_EX_ovld3_fpcol_DLL_D)\
 $(OBJ_EX_ovld3_tabs_DLL_D)\
 $(OBJ_EX_ovld3_svrlg_DLL_D)\
 $(OBJ_EX_ovld3_rcins_DLL_D)\
 $(OBJ_EX_pad_hash_DLL_D)\
 $(OBJ_EX_sink_cstr_DLL_D)\
 $(OBJ_EX_sink_ODS_DLL_D)\
 $(OBJ_EX_boolean_DLL_D_W)\
 $(OBJ_EX_character_DLL_D_W)\
 $(OBJ_EX_reals_DLL_D_W)\
 $(OBJ_EX_voidptrs_DLL_D_W)\
 $(OBJ_EX_itr_fmt_DLL_D_W)\
 $(OBJ_EX_sink_ODS_DLL_D_W)\
 $(OBJ_EX_boolean_DLL_R)\
 $(OBJ_EX_character_DLL_R)\
 $(OBJ_EX_reals_DLL_R)\
 $(OBJ_EX_voidptrs_DLL_R)\
 $(OBJ_EX_ff_101_DLL_R)\
 $(OBJ_EX_ff_101_nons_DLL_R)\
 $(OBJ_EX_flush_DLL_R)\
 $(OBJ_EX_ins_hex_DLL_R)\
 $(OBJ_EX_ins_integers_DLL_R)\
 $(OBJ_EX_ins_reals_DLL_R)\
 $(OBJ_EX_ins_WLIs_DLL_R)\
 $(OBJ_EX_itr_fmt_DLL_R)\
 $(OBJ_EX_ovld2_filt_DLL_R)\
 $(OBJ_EX_ovld2_ins_DLL_R)\
 $(OBJ_EX_ovld2_sas_DLL_R)\
 $(OBJ_EX_ovld3_fpcol_DLL_R)\
 $(OBJ_EX_ovld3_tabs_DLL_R)\
 $(OBJ_EX_ovld3_svrlg_DLL_R)\
 $(OBJ_EX_ovld3_rcins_DLL_R)\
 $(OBJ_EX_pad_hash_DLL_R)\
 $(OBJ_EX_sink_cstr_DLL_R)\
 $(OBJ_EX_sink_ODS_DLL_R)\
 $(OBJ_EX_boolean_DLL_R_W)\
 $(OBJ_EX_character_DLL_R_W)\
 $(OBJ_EX_reals_DLL_R_W)\
 $(OBJ_EX_voidptrs_DLL_R_W)\
 $(OBJ_EX_itr_fmt_DLL_R_W)\
 $(OBJ_EX_sink_ODS_DLL_R_W)\
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
 $(OBJ_EX_boolean_MT_R_W)\
 $(OBJ_EX_character_MT_R_W)\
 $(OBJ_EX_reals_MT_R_W)\
 $(OBJ_EX_voidptrs_MT_R_W)\
 $(OBJ_EX_itr_fmt_MT_R_W)\
 $(OBJ_EX_sink_ODS_MT_R_W)\
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
 $(OBJ_TEST_COMP_file_MT_D_W)\
 $(OBJ_TEST_COMP_fmt_sink_MT_D_W)\
 $(OBJ_TEST_COMP_ins_hex_MT_D_W)\
 $(OBJ_TEST_COMP_ins_int_MT_D_W)\
 $(OBJ_TEST_COMP_ins_real_MT_D_W)\
 $(OBJ_TEST_COMP_itr_fmt_MT_D_W)\
 $(OBJ_TEST_COMP_null_sink_MT_D_W)\
 $(OBJ_TEST_COMP_snk_a_b_MT_D_W)\
 $(OBJ_TEST_COMP_write_sink_MT_D_W)\
 $(OBJ_TEST_COMP_x_1_MT_D_W)\
 $(OBJ_TEST_COMP_snk_ostm_MT_D_W)\
 $(OBJ_TEST_COMP_file_DLL_D)\
 $(OBJ_TEST_COMP_fmt_sink_DLL_D)\
 $(OBJ_TEST_COMP_ins_hex_DLL_D)\
 $(OBJ_TEST_COMP_ins_int_DLL_D)\
 $(OBJ_TEST_COMP_ins_real_DLL_D)\
 $(OBJ_TEST_COMP_itr_fmt_DLL_D)\
 $(OBJ_TEST_COMP_null_sink_DLL_D)\
 $(OBJ_TEST_COMP_snk_a_b_DLL_D)\
 $(OBJ_TEST_COMP_write_sink_DLL_D)\
 $(OBJ_TEST_COMP_x_1_DLL_D)\
 $(OBJ_TEST_COMP_snk_ostm_DLL_D)\
 $(OBJ_TEST_COMP_file_DLL_D_W)\
 $(OBJ_TEST_COMP_fmt_sink_DLL_D_W)\
 $(OBJ_TEST_COMP_ins_hex_DLL_D_W)\
 $(OBJ_TEST_COMP_ins_int_DLL_D_W)\
 $(OBJ_TEST_COMP_ins_real_DLL_D_W)\
 $(OBJ_TEST_COMP_itr_fmt_DLL_D_W)\
 $(OBJ_TEST_COMP_null_sink_DLL_D_W)\
 $(OBJ_TEST_COMP_snk_a_b_DLL_D_W)\
 $(OBJ_TEST_COMP_write_sink_DLL_D_W)\
 $(OBJ_TEST_COMP_x_1_DLL_D_W)\
 $(OBJ_TEST_COMP_snk_ostm_DLL_D_W)\
 $(OBJ_TEST_COMP_file_DLL_R)\
 $(OBJ_TEST_COMP_fmt_sink_DLL_R)\
 $(OBJ_TEST_COMP_ins_hex_DLL_R)\
 $(OBJ_TEST_COMP_ins_int_DLL_R)\
 $(OBJ_TEST_COMP_ins_real_DLL_R)\
 $(OBJ_TEST_COMP_itr_fmt_DLL_R)\
 $(OBJ_TEST_COMP_null_sink_DLL_R)\
 $(OBJ_TEST_COMP_snk_a_b_DLL_R)\
 $(OBJ_TEST_COMP_write_sink_DLL_R)\
 $(OBJ_TEST_COMP_x_1_DLL_R)\
 $(OBJ_TEST_COMP_snk_ostm_DLL_R)\
 $(OBJ_TEST_COMP_file_DLL_R_W)\
 $(OBJ_TEST_COMP_fmt_sink_DLL_R_W)\
 $(OBJ_TEST_COMP_ins_hex_DLL_R_W)\
 $(OBJ_TEST_COMP_ins_int_DLL_R_W)\
 $(OBJ_TEST_COMP_ins_real_DLL_R_W)\
 $(OBJ_TEST_COMP_itr_fmt_DLL_R_W)\
 $(OBJ_TEST_COMP_null_sink_DLL_R_W)\
 $(OBJ_TEST_COMP_snk_a_b_DLL_R_W)\
 $(OBJ_TEST_COMP_write_sink_DLL_R_W)\
 $(OBJ_TEST_COMP_x_1_DLL_R_W)\
 $(OBJ_TEST_COMP_snk_ostm_DLL_R_W)\
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
 $(OBJ_TEST_COMP_file_MT_R_W)\
 $(OBJ_TEST_COMP_fmt_sink_MT_R_W)\
 $(OBJ_TEST_COMP_ins_hex_MT_R_W)\
 $(OBJ_TEST_COMP_ins_int_MT_R_W)\
 $(OBJ_TEST_COMP_ins_real_MT_R_W)\
 $(OBJ_TEST_COMP_itr_fmt_MT_R_W)\
 $(OBJ_TEST_COMP_null_sink_MT_R_W)\
 $(OBJ_TEST_COMP_snk_a_b_MT_R_W)\
 $(OBJ_TEST_COMP_write_sink_MT_R_W)\
 $(OBJ_TEST_COMP_x_1_MT_R_W)\
 $(OBJ_TEST_COMP_snk_ostm_MT_R_W)\
 \

# Performance Tests
OBJS_TEST_PERFORMANCE_BOOST=

!ifdef BOOST
OBJS_TEST_PERFORMANCE_BOOST=\
 $(OBJ_TEST_PERF_scen8_MT_D)\
 $(OBJ_TEST_PERF_scen8_DLL_D)\
 $(OBJ_TEST_PERF_scen8_DLL_R)\
 $(OBJ_TEST_PERF_scen8_MT_R)\
 \

!endif # BOOST

OBJS_TEST_PERFORMANCE=\
 $(OBJ_TEST_PERF_scen1_MT_D)\
 $(OBJ_TEST_PERF_scen2_MT_D)\
 $(OBJ_TEST_PERF_scen3_MT_D)\
 $(OBJ_TEST_PERF_scen4_MT_D)\
 $(OBJ_TEST_PERF_scen5_MT_D)\
 $(OBJ_TEST_PERF_scen6_MT_D)\
 $(OBJ_TEST_PERF_scen7_MT_D)\
 $(OBJ_TEST_PERF_scen1_DLL_D)\
 $(OBJ_TEST_PERF_scen2_DLL_D)\
 $(OBJ_TEST_PERF_scen3_DLL_D)\
 $(OBJ_TEST_PERF_scen4_DLL_D)\
 $(OBJ_TEST_PERF_scen5_DLL_D)\
 $(OBJ_TEST_PERF_scen6_DLL_D)\
 $(OBJ_TEST_PERF_scen7_DLL_D)\
 $(OBJ_TEST_PERF_scen1_DLL_R)\
 $(OBJ_TEST_PERF_scen2_DLL_R)\
 $(OBJ_TEST_PERF_scen3_DLL_R)\
 $(OBJ_TEST_PERF_scen4_DLL_R)\
 $(OBJ_TEST_PERF_scen5_DLL_R)\
 $(OBJ_TEST_PERF_scen6_DLL_R)\
 $(OBJ_TEST_PERF_scen7_DLL_R)\
 $(OBJ_TEST_PERF_scen1_MT_R)\
 $(OBJ_TEST_PERF_scen2_MT_R)\
 $(OBJ_TEST_PERF_scen3_MT_R)\
 $(OBJ_TEST_PERF_scen4_MT_R)\
 $(OBJ_TEST_PERF_scen5_MT_R)\
 $(OBJ_TEST_PERF_scen6_MT_R)\
 $(OBJ_TEST_PERF_scen7_MT_R)\
 $(OBJS_TEST_PERFORMANCE_BOOST)\
 \

# Scratch Tests
OBJS_TEST_SCRATCH=\
 $(OBJ_TEST_SCRT_file_MT_D)\
 $(OBJ_TEST_SCRT_speech_MT_D)\
 $(OBJ_TEST_SCRT_file_MT_D_W)\
 $(OBJ_TEST_SCRT_speech_MT_D_W)\
 $(OBJ_TEST_SCRT_file_DLL_D)\
 $(OBJ_TEST_SCRT_speech_DLL_D)\
 $(OBJ_TEST_SCRT_file_DLL_D_W)\
 $(OBJ_TEST_SCRT_speech_DLL_D_W)\
 $(OBJ_TEST_SCRT_file_DLL_R)\
 $(OBJ_TEST_SCRT_speech_DLL_R)\
 $(OBJ_TEST_SCRT_file_DLL_R_W)\
 $(OBJ_TEST_SCRT_speech_DLL_R_W)\
 $(OBJ_TEST_SCRT_file_MT_R)\
 $(OBJ_TEST_SCRT_speech_MT_R)\
 $(OBJ_TEST_SCRT_file_MT_R_W)\
 $(OBJ_TEST_SCRT_speech_MT_R_W)\
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
 $(OBJ_TEST_UNIT_ins_ss_MT_D)\
 $(OBJ_TEST_UNIT_shim_fi_MT_D)\
 $(OBJ_TEST_UNIT_shim_ns_1_MT_D)\
 $(OBJ_TEST_UNIT_shim_ns_2_MT_D)\
 $(OBJ_TEST_UNIT_shim_ns_3_MT_D)\
 $(OBJ_TEST_UNIT_shim_ns_4_MT_D)\
 $(OBJ_TEST_UNIT_shim_ns_5_MT_D)\
 $(OBJ_TEST_UNIT_snk_a_b_MT_D)\
 $(OBJ_TEST_UNIT_snk_c_str_MT_D)\
 $(OBJ_TEST_UNIT_snk_chbuf_MT_D)\
 $(OBJ_TEST_UNIT_snk_null_MT_D)\
 $(OBJ_TEST_UNIT_snk_ods_MT_D)\
 $(OBJ_TEST_UNIT_snk_ostm_MT_D)\
 $(OBJ_TEST_UNIT_snk_sstm_MT_D)\
 $(OBJ_TEST_UNIT_api_acsllen_MT_D_W)\
 $(OBJ_TEST_UNIT_api_crlf_MT_D_W)\
 $(OBJ_TEST_UNIT_api_flrpl_MT_D_W)\
 $(OBJ_TEST_UNIT_api_illfmdh_MT_D_W)\
 $(OBJ_TEST_UNIT_api_init_MT_D_W)\
 $(OBJ_TEST_UNIT_api_lkptrn_MT_D_W)\
 $(OBJ_TEST_UNIT_api_msmtchh_MT_D_W)\
 $(OBJ_TEST_UNIT_api_prsrpl_MT_D_W)\
 $(OBJ_TEST_UNIT_bndl_winini_MT_D_W)\
 $(OBJ_TEST_UNIT_fmt_stdfl_MT_D_W)\
 $(OBJ_TEST_UNIT_ins_ch_MT_D_W)\
 $(OBJ_TEST_UNIT_ins_i_MT_D_W)\
 $(OBJ_TEST_UNIT_ins_ss_MT_D_W)\
 $(OBJ_TEST_UNIT_shim_fi_MT_D_W)\
 $(OBJ_TEST_UNIT_shim_ns_1_MT_D_W)\
 $(OBJ_TEST_UNIT_shim_ns_2_MT_D_W)\
 $(OBJ_TEST_UNIT_shim_ns_3_MT_D_W)\
 $(OBJ_TEST_UNIT_shim_ns_4_MT_D_W)\
 $(OBJ_TEST_UNIT_shim_ns_5_MT_D_W)\
 $(OBJ_TEST_UNIT_snk_a_b_MT_D_W)\
 $(OBJ_TEST_UNIT_snk_c_str_MT_D_W)\
 $(OBJ_TEST_UNIT_snk_chbuf_MT_D_W)\
 $(OBJ_TEST_UNIT_snk_null_MT_D_W)\
 $(OBJ_TEST_UNIT_snk_ods_MT_D_W)\
 $(OBJ_TEST_UNIT_snk_ostm_MT_D_W)\
 $(OBJ_TEST_UNIT_snk_sstm_MT_D_W)\
 $(OBJ_TEST_UNIT_api_acsllen_DLL_D)\
 $(OBJ_TEST_UNIT_api_crlf_DLL_D)\
 $(OBJ_TEST_UNIT_api_flrpl_DLL_D)\
 $(OBJ_TEST_UNIT_api_illfmdh_DLL_D)\
 $(OBJ_TEST_UNIT_api_init_DLL_D)\
 $(OBJ_TEST_UNIT_api_lkptrn_DLL_D)\
 $(OBJ_TEST_UNIT_api_msmtchh_DLL_D)\
 $(OBJ_TEST_UNIT_api_prsrpl_DLL_D)\
 $(OBJ_TEST_UNIT_bndl_winini_DLL_D)\
 $(OBJ_TEST_UNIT_fmt_stdfl_DLL_D)\
 $(OBJ_TEST_UNIT_ins_ch_DLL_D)\
 $(OBJ_TEST_UNIT_ins_i_DLL_D)\
 $(OBJ_TEST_UNIT_ins_ss_DLL_D)\
 $(OBJ_TEST_UNIT_shim_fi_DLL_D)\
 $(OBJ_TEST_UNIT_shim_ns_1_DLL_D)\
 $(OBJ_TEST_UNIT_shim_ns_2_DLL_D)\
 $(OBJ_TEST_UNIT_shim_ns_3_DLL_D)\
 $(OBJ_TEST_UNIT_shim_ns_4_DLL_D)\
 $(OBJ_TEST_UNIT_shim_ns_5_DLL_D)\
 $(OBJ_TEST_UNIT_snk_a_b_DLL_D)\
 $(OBJ_TEST_UNIT_snk_c_str_DLL_D)\
 $(OBJ_TEST_UNIT_snk_chbuf_DLL_D)\
 $(OBJ_TEST_UNIT_snk_null_DLL_D)\
 $(OBJ_TEST_UNIT_snk_ods_DLL_D)\
 $(OBJ_TEST_UNIT_snk_ostm_DLL_D)\
 $(OBJ_TEST_UNIT_snk_sstm_DLL_D)\
 $(OBJ_TEST_UNIT_api_acsllen_DLL_D_W)\
 $(OBJ_TEST_UNIT_api_crlf_DLL_D_W)\
 $(OBJ_TEST_UNIT_api_flrpl_DLL_D_W)\
 $(OBJ_TEST_UNIT_api_illfmdh_DLL_D_W)\
 $(OBJ_TEST_UNIT_api_init_DLL_D_W)\
 $(OBJ_TEST_UNIT_api_lkptrn_DLL_D_W)\
 $(OBJ_TEST_UNIT_api_msmtchh_DLL_D_W)\
 $(OBJ_TEST_UNIT_api_prsrpl_DLL_D_W)\
 $(OBJ_TEST_UNIT_bndl_winini_DLL_D_W)\
 $(OBJ_TEST_UNIT_fmt_stdfl_DLL_D_W)\
 $(OBJ_TEST_UNIT_ins_ch_DLL_D_W)\
 $(OBJ_TEST_UNIT_ins_i_DLL_D_W)\
 $(OBJ_TEST_UNIT_ins_ss_DLL_D_W)\
 $(OBJ_TEST_UNIT_shim_fi_DLL_D_W)\
 $(OBJ_TEST_UNIT_shim_ns_1_DLL_D_W)\
 $(OBJ_TEST_UNIT_shim_ns_2_DLL_D_W)\
 $(OBJ_TEST_UNIT_shim_ns_3_DLL_D_W)\
 $(OBJ_TEST_UNIT_shim_ns_4_DLL_D_W)\
 $(OBJ_TEST_UNIT_shim_ns_5_DLL_D_W)\
 $(OBJ_TEST_UNIT_snk_a_b_DLL_D_W)\
 $(OBJ_TEST_UNIT_snk_c_str_DLL_D_W)\
 $(OBJ_TEST_UNIT_snk_chbuf_DLL_D_W)\
 $(OBJ_TEST_UNIT_snk_null_DLL_D_W)\
 $(OBJ_TEST_UNIT_snk_ods_DLL_D_W)\
 $(OBJ_TEST_UNIT_snk_ostm_DLL_D_W)\
 $(OBJ_TEST_UNIT_snk_sstm_DLL_D_W)\
 $(OBJ_TEST_UNIT_api_acsllen_DLL_R)\
 $(OBJ_TEST_UNIT_api_crlf_DLL_R)\
 $(OBJ_TEST_UNIT_api_flrpl_DLL_R)\
 $(OBJ_TEST_UNIT_api_illfmdh_DLL_R)\
 $(OBJ_TEST_UNIT_api_init_DLL_R)\
 $(OBJ_TEST_UNIT_api_lkptrn_DLL_R)\
 $(OBJ_TEST_UNIT_api_msmtchh_DLL_R)\
 $(OBJ_TEST_UNIT_api_prsrpl_DLL_R)\
 $(OBJ_TEST_UNIT_bndl_winini_DLL_R)\
 $(OBJ_TEST_UNIT_fmt_stdfl_DLL_R)\
 $(OBJ_TEST_UNIT_ins_ch_DLL_R)\
 $(OBJ_TEST_UNIT_ins_i_DLL_R)\
 $(OBJ_TEST_UNIT_ins_ss_DLL_R)\
 $(OBJ_TEST_UNIT_shim_fi_DLL_R)\
 $(OBJ_TEST_UNIT_shim_ns_1_DLL_R)\
 $(OBJ_TEST_UNIT_shim_ns_2_DLL_R)\
 $(OBJ_TEST_UNIT_shim_ns_3_DLL_R)\
 $(OBJ_TEST_UNIT_shim_ns_4_DLL_R)\
 $(OBJ_TEST_UNIT_shim_ns_5_DLL_R)\
 $(OBJ_TEST_UNIT_snk_a_b_DLL_R)\
 $(OBJ_TEST_UNIT_snk_c_str_DLL_R)\
 $(OBJ_TEST_UNIT_snk_chbuf_DLL_R)\
 $(OBJ_TEST_UNIT_snk_null_DLL_R)\
 $(OBJ_TEST_UNIT_snk_ods_DLL_R)\
 $(OBJ_TEST_UNIT_snk_ostm_DLL_R)\
 $(OBJ_TEST_UNIT_snk_sstm_DLL_R)\
 $(OBJ_TEST_UNIT_api_acsllen_DLL_R_W)\
 $(OBJ_TEST_UNIT_api_crlf_DLL_R_W)\
 $(OBJ_TEST_UNIT_api_flrpl_DLL_R_W)\
 $(OBJ_TEST_UNIT_api_illfmdh_DLL_R_W)\
 $(OBJ_TEST_UNIT_api_init_DLL_R_W)\
 $(OBJ_TEST_UNIT_api_lkptrn_DLL_R_W)\
 $(OBJ_TEST_UNIT_api_msmtchh_DLL_R_W)\
 $(OBJ_TEST_UNIT_api_prsrpl_DLL_R_W)\
 $(OBJ_TEST_UNIT_bndl_winini_DLL_R_W)\
 $(OBJ_TEST_UNIT_fmt_stdfl_DLL_R_W)\
 $(OBJ_TEST_UNIT_ins_ch_DLL_R_W)\
 $(OBJ_TEST_UNIT_ins_i_DLL_R_W)\
 $(OBJ_TEST_UNIT_ins_ss_DLL_R_W)\
 $(OBJ_TEST_UNIT_shim_fi_DLL_R_W)\
 $(OBJ_TEST_UNIT_shim_ns_1_DLL_R_W)\
 $(OBJ_TEST_UNIT_shim_ns_2_DLL_R_W)\
 $(OBJ_TEST_UNIT_shim_ns_3_DLL_R_W)\
 $(OBJ_TEST_UNIT_shim_ns_4_DLL_R_W)\
 $(OBJ_TEST_UNIT_shim_ns_5_DLL_R_W)\
 $(OBJ_TEST_UNIT_snk_a_b_DLL_R_W)\
 $(OBJ_TEST_UNIT_snk_c_str_DLL_R_W)\
 $(OBJ_TEST_UNIT_snk_chbuf_DLL_R_W)\
 $(OBJ_TEST_UNIT_snk_null_DLL_R_W)\
 $(OBJ_TEST_UNIT_snk_ods_DLL_R_W)\
 $(OBJ_TEST_UNIT_snk_ostm_DLL_R_W)\
 $(OBJ_TEST_UNIT_snk_sstm_DLL_R_W)\
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
 $(OBJ_TEST_UNIT_ins_ss_MT_R)\
 $(OBJ_TEST_UNIT_shim_fi_MT_R)\
 $(OBJ_TEST_UNIT_shim_ns_1_MT_R)\
 $(OBJ_TEST_UNIT_shim_ns_2_MT_R)\
 $(OBJ_TEST_UNIT_shim_ns_3_MT_R)\
 $(OBJ_TEST_UNIT_shim_ns_4_MT_R)\
 $(OBJ_TEST_UNIT_shim_ns_5_MT_R)\
 $(OBJ_TEST_UNIT_snk_a_b_MT_R)\
 $(OBJ_TEST_UNIT_snk_c_str_MT_R)\
 $(OBJ_TEST_UNIT_snk_chbuf_MT_R)\
 $(OBJ_TEST_UNIT_snk_null_MT_R)\
 $(OBJ_TEST_UNIT_snk_ods_MT_R)\
 $(OBJ_TEST_UNIT_snk_ostm_MT_R)\
 $(OBJ_TEST_UNIT_snk_sstm_MT_R)\
 $(OBJ_TEST_UNIT_api_acsllen_MT_R_W)\
 $(OBJ_TEST_UNIT_api_crlf_MT_R_W)\
 $(OBJ_TEST_UNIT_api_flrpl_MT_R_W)\
 $(OBJ_TEST_UNIT_api_illfmdh_MT_R_W)\
 $(OBJ_TEST_UNIT_api_init_MT_R_W)\
 $(OBJ_TEST_UNIT_api_lkptrn_MT_R_W)\
 $(OBJ_TEST_UNIT_api_msmtchh_MT_R_W)\
 $(OBJ_TEST_UNIT_api_prsrpl_MT_R_W)\
 $(OBJ_TEST_UNIT_bndl_winini_MT_R_W)\
 $(OBJ_TEST_UNIT_fmt_stdfl_MT_R_W)\
 $(OBJ_TEST_UNIT_ins_ch_MT_R_W)\
 $(OBJ_TEST_UNIT_ins_i_MT_R_W)\
 $(OBJ_TEST_UNIT_ins_ss_MT_R_W)\
 $(OBJ_TEST_UNIT_shim_fi_MT_R_W)\
 $(OBJ_TEST_UNIT_shim_ns_1_MT_R_W)\
 $(OBJ_TEST_UNIT_shim_ns_2_MT_R_W)\
 $(OBJ_TEST_UNIT_shim_ns_3_MT_R_W)\
 $(OBJ_TEST_UNIT_shim_ns_4_MT_R_W)\
 $(OBJ_TEST_UNIT_shim_ns_5_MT_R_W)\
 $(OBJ_TEST_UNIT_snk_a_b_MT_R_W)\
 $(OBJ_TEST_UNIT_snk_c_str_MT_R_W)\
 $(OBJ_TEST_UNIT_snk_chbuf_MT_R_W)\
 $(OBJ_TEST_UNIT_snk_null_MT_R_W)\
 $(OBJ_TEST_UNIT_snk_ods_MT_R_W)\
 $(OBJ_TEST_UNIT_snk_ostm_MT_R_W)\
 $(OBJ_TEST_UNIT_snk_sstm_MT_R_W)\
 \

########################################
# Libraries

TARGETS_LIB_CORE = \
 $(LIB_CORE_MT_D)\
 $(LIB_CORE_MT_D_W)\
 $(LIB_CORE_DLL_D)\
 $(LIB_CORE_DLL_D_W)\
 $(LIB_CORE_DLL_R)\
 $(LIB_CORE_DLL_R_W)\
 $(LIB_CORE_MT_R)\
 $(LIB_CORE_MT_R_W)\
 \

TARGETS_LIB_LOKI_SFMT = \
 $(LIB_LOKI_SFMT_MT_D)\
 $(LIB_LOKI_SFMT_MT_D_W)\
 $(LIB_LOKI_SFMT_DLL_D)\
 $(LIB_LOKI_SFMT_DLL_D_W)\
 $(LIB_LOKI_SFMT_DLL_R)\
 $(LIB_LOKI_SFMT_DLL_R_W)\
 $(LIB_LOKI_SFMT_MT_R)\
 $(LIB_LOKI_SFMT_MT_R_W)\
 \

TARGETS_LIB_SHWILD = \
 $(LIB_SHWILD_MT_D)\
 $(LIB_SHWILD_MT_D_W)\
 $(LIB_SHWILD_DLL_D)\
 $(LIB_SHWILD_DLL_D_W)\
 $(LIB_SHWILD_DLL_R)\
 $(LIB_SHWILD_DLL_R_W)\
 $(LIB_SHWILD_MT_R)\
 $(LIB_SHWILD_MT_R_W)\
 \

TARGETS_LIB_XTESTS = \
 $(LIB_XTESTS_MT_D)\
 $(LIB_XTESTS_MT_D_W)\
 $(LIB_XTESTS_DLL_D)\
 $(LIB_XTESTS_DLL_D_W)\
 $(LIB_XTESTS_DLL_R)\
 $(LIB_XTESTS_DLL_R_W)\
 $(LIB_XTESTS_MT_R)\
 $(LIB_XTESTS_MT_R_W)\
 \

########################################
# Programs

TARGETS_BITBUCKET=\
 $(TARG_BITBUCKET_MT_D)\
 $(TARG_BITBUCKET_MT_D_W)\
 $(TARG_BITBUCKET_DLL_D)\
 $(TARG_BITBUCKET_DLL_D_W)\
 $(TARG_BITBUCKET_DLL_R)\
 $(TARG_BITBUCKET_DLL_R_W)\
 $(TARG_BITBUCKET_MT_R)\
 $(TARG_BITBUCKET_MT_R_W)\
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
 $(TARG_EX_boolean_MT_D_W)\
 $(TARG_EX_character_MT_D_W)\
 $(TARG_EX_reals_MT_D_W)\
 $(TARG_EX_voidptrs_MT_D_W)\
 $(TARG_EX_itr_fmt_MT_D_W)\
 $(TARG_EX_sink_ODS_MT_D_W)\
 $(TARG_EX_boolean_DLL_D)\
 $(TARG_EX_character_DLL_D)\
 $(TARG_EX_reals_DLL_D)\
 $(TARG_EX_voidptrs_DLL_D)\
 $(TARG_EX_ff_101_DLL_D)\
 $(TARG_EX_ff_101_nons_DLL_D)\
 $(TARG_EX_flush_DLL_D)\
 $(TARG_EX_ins_hex_DLL_D)\
 $(TARG_EX_ins_integers_DLL_D)\
 $(TARG_EX_ins_reals_DLL_D)\
 $(TARG_EX_ins_WLIs_DLL_D)\
 $(TARG_EX_itr_fmt_DLL_D)\
 $(TARG_EX_ovld2_filt_DLL_D)\
 $(TARG_EX_ovld2_ins_DLL_D)\
 $(TARG_EX_ovld2_sas_DLL_D)\
 $(TARG_EX_ovld3_fpcol_DLL_D)\
 $(TARG_EX_ovld3_tabs_DLL_D)\
 $(TARG_EX_ovld3_svrlg_DLL_D)\
 $(TARG_EX_ovld3_rcins_DLL_D)\
 $(TARG_EX_pad_hash_DLL_D)\
 $(TARG_EX_sink_cstr_DLL_D)\
 $(TARG_EX_sink_ODS_DLL_D)\
 $(TARG_EX_boolean_DLL_D_W)\
 $(TARG_EX_character_DLL_D_W)\
 $(TARG_EX_reals_DLL_D_W)\
 $(TARG_EX_voidptrs_DLL_D_W)\
 $(TARG_EX_itr_fmt_DLL_D_W)\
 $(TARG_EX_sink_ODS_DLL_D_W)\
 $(TARG_EX_boolean_DLL_R)\
 $(TARG_EX_character_DLL_R)\
 $(TARG_EX_reals_DLL_R)\
 $(TARG_EX_voidptrs_DLL_R)\
 $(TARG_EX_ff_101_DLL_R)\
 $(TARG_EX_ff_101_nons_DLL_R)\
 $(TARG_EX_flush_DLL_R)\
 $(TARG_EX_ins_hex_DLL_R)\
 $(TARG_EX_ins_integers_DLL_R)\
 $(TARG_EX_ins_reals_DLL_R)\
 $(TARG_EX_ins_WLIs_DLL_R)\
 $(TARG_EX_itr_fmt_DLL_R)\
 $(TARG_EX_ovld2_filt_DLL_R)\
 $(TARG_EX_ovld2_ins_DLL_R)\
 $(TARG_EX_ovld2_sas_DLL_R)\
 $(TARG_EX_ovld3_fpcol_DLL_R)\
 $(TARG_EX_ovld3_tabs_DLL_R)\
 $(TARG_EX_ovld3_svrlg_DLL_R)\
 $(TARG_EX_ovld3_rcins_DLL_R)\
 $(TARG_EX_pad_hash_DLL_R)\
 $(TARG_EX_sink_cstr_DLL_R)\
 $(TARG_EX_sink_ODS_DLL_R)\
 $(TARG_EX_boolean_DLL_R_W)\
 $(TARG_EX_character_DLL_R_W)\
 $(TARG_EX_reals_DLL_R_W)\
 $(TARG_EX_voidptrs_DLL_R_W)\
 $(TARG_EX_itr_fmt_DLL_R_W)\
 $(TARG_EX_sink_ODS_DLL_R_W)\
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
 $(TARG_EX_boolean_MT_R_W)\
 $(TARG_EX_character_MT_R_W)\
 $(TARG_EX_reals_MT_R_W)\
 $(TARG_EX_voidptrs_MT_R_W)\
 $(TARG_EX_itr_fmt_MT_R_W)\
 $(TARG_EX_sink_ODS_MT_R_W)\
 \

TARGETS_EXAMPLE_OVERLOAD_3=\
 $(TARG_EX_ovld3_fpcol_DLL_R)\
 $(TARG_EX_ovld3_tabs_DLL_R)\
 $(TARG_EX_ovld3_svrlg_DLL_R)\
 $(TARG_EX_ovld3_rcins_DLL_R)\
 $(TARG_EX_ovld3_fpcol_MT_R)\
 $(TARG_EX_ovld3_tabs_MT_R)\
 $(TARG_EX_ovld3_svrlg_MT_R)\
 $(TARG_EX_ovld3_rcins_MT_R)\
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
 $(TARG_TEST_COMP_file_MT_D_W)\
 $(TARG_TEST_COMP_fmt_sink_MT_D_W)\
 $(TARG_TEST_COMP_ins_hex_MT_D_W)\
 $(TARG_TEST_COMP_ins_int_MT_D_W)\
 $(TARG_TEST_COMP_ins_real_MT_D_W)\
 $(TARG_TEST_COMP_itr_fmt_MT_D_W)\
 $(TARG_TEST_COMP_null_sink_MT_D_W)\
 $(TARG_TEST_COMP_snk_a_b_MT_D_W)\
 $(TARG_TEST_COMP_write_sink_MT_D_W)\
 $(TARG_TEST_COMP_x_1_MT_D_W)\
 $(TARG_TEST_COMP_snk_ostm_MT_D_W)\
 $(TARG_TEST_COMP_file_DLL_D)\
 $(TARG_TEST_COMP_fmt_sink_DLL_D)\
 $(TARG_TEST_COMP_ins_hex_DLL_D)\
 $(TARG_TEST_COMP_ins_int_DLL_D)\
 $(TARG_TEST_COMP_ins_real_DLL_D)\
 $(TARG_TEST_COMP_itr_fmt_DLL_D)\
 $(TARG_TEST_COMP_null_sink_DLL_D)\
 $(TARG_TEST_COMP_snk_a_b_DLL_D)\
 $(TARG_TEST_COMP_write_sink_DLL_D)\
 $(TARG_TEST_COMP_x_1_DLL_D)\
 $(TARG_TEST_COMP_snk_ostm_DLL_D)\
 $(TARG_TEST_COMP_file_DLL_D_W)\
 $(TARG_TEST_COMP_fmt_sink_DLL_D_W)\
 $(TARG_TEST_COMP_ins_hex_DLL_D_W)\
 $(TARG_TEST_COMP_ins_int_DLL_D_W)\
 $(TARG_TEST_COMP_ins_real_DLL_D_W)\
 $(TARG_TEST_COMP_itr_fmt_DLL_D_W)\
 $(TARG_TEST_COMP_null_sink_DLL_D_W)\
 $(TARG_TEST_COMP_snk_a_b_DLL_D_W)\
 $(TARG_TEST_COMP_write_sink_DLL_D_W)\
 $(TARG_TEST_COMP_x_1_DLL_D_W)\
 $(TARG_TEST_COMP_snk_ostm_DLL_D_W)\
 $(TARG_TEST_COMP_file_DLL_R)\
 $(TARG_TEST_COMP_fmt_sink_DLL_R)\
 $(TARG_TEST_COMP_ins_hex_DLL_R)\
 $(TARG_TEST_COMP_ins_int_DLL_R)\
 $(TARG_TEST_COMP_ins_real_DLL_R)\
 $(TARG_TEST_COMP_itr_fmt_DLL_R)\
 $(TARG_TEST_COMP_null_sink_DLL_R)\
 $(TARG_TEST_COMP_snk_a_b_DLL_R)\
 $(TARG_TEST_COMP_write_sink_DLL_R)\
 $(TARG_TEST_COMP_x_1_DLL_R)\
 $(TARG_TEST_COMP_snk_ostm_DLL_R)\
 $(TARG_TEST_COMP_file_DLL_R_W)\
 $(TARG_TEST_COMP_fmt_sink_DLL_R_W)\
 $(TARG_TEST_COMP_ins_hex_DLL_R_W)\
 $(TARG_TEST_COMP_ins_int_DLL_R_W)\
 $(TARG_TEST_COMP_ins_real_DLL_R_W)\
 $(TARG_TEST_COMP_itr_fmt_DLL_R_W)\
 $(TARG_TEST_COMP_null_sink_DLL_R_W)\
 $(TARG_TEST_COMP_snk_a_b_DLL_R_W)\
 $(TARG_TEST_COMP_write_sink_DLL_R_W)\
 $(TARG_TEST_COMP_x_1_DLL_R_W)\
 $(TARG_TEST_COMP_snk_ostm_DLL_R_W)\
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
 $(TARG_TEST_COMP_file_MT_R_W)\
 $(TARG_TEST_COMP_fmt_sink_MT_R_W)\
 $(TARG_TEST_COMP_ins_hex_MT_R_W)\
 $(TARG_TEST_COMP_ins_int_MT_R_W)\
 $(TARG_TEST_COMP_ins_real_MT_R_W)\
 $(TARG_TEST_COMP_itr_fmt_MT_R_W)\
 $(TARG_TEST_COMP_null_sink_MT_R_W)\
 $(TARG_TEST_COMP_snk_a_b_MT_R_W)\
 $(TARG_TEST_COMP_write_sink_MT_R_W)\
 $(TARG_TEST_COMP_x_1_MT_R_W)\
 $(TARG_TEST_COMP_snk_ostm_MT_R_W)\
 \

TARGETS_TEST_PERFORMANCE_BOOST=

!ifdef BOOST
TARGETS_TEST_PERFORMANCE_BOOST=\
 $(TARG_TEST_PERF_scen8_MT_D)\
 $(TARG_TEST_PERF_scen8_DLL_D)\
 $(TARG_TEST_PERF_scen8_DLL_R)\
 $(TARG_TEST_PERF_scen8_MT_R)\
 \

!endif # BOOST

TARGETS_TEST_PERFORMANCE=\
 $(TARG_TEST_PERF_scen1_MT_D)\
 $(TARG_TEST_PERF_scen2_MT_D)\
 $(TARG_TEST_PERF_scen3_MT_D)\
 $(TARG_TEST_PERF_scen4_MT_D)\
 $(TARG_TEST_PERF_scen5_MT_D)\
 $(TARG_TEST_PERF_scen6_MT_D)\
 $(TARG_TEST_PERF_scen7_MT_D)\
 $(TARG_TEST_PERF_scen1_DLL_D)\
 $(TARG_TEST_PERF_scen2_DLL_D)\
 $(TARG_TEST_PERF_scen3_DLL_D)\
 $(TARG_TEST_PERF_scen4_DLL_D)\
 $(TARG_TEST_PERF_scen5_DLL_D)\
 $(TARG_TEST_PERF_scen6_DLL_D)\
 $(TARG_TEST_PERF_scen7_DLL_D)\
 $(TARG_TEST_PERF_scen1_DLL_R)\
 $(TARG_TEST_PERF_scen2_DLL_R)\
 $(TARG_TEST_PERF_scen3_DLL_R)\
 $(TARG_TEST_PERF_scen4_DLL_R)\
 $(TARG_TEST_PERF_scen5_DLL_R)\
 $(TARG_TEST_PERF_scen6_DLL_R)\
 $(TARG_TEST_PERF_scen7_DLL_R)\
 $(TARG_TEST_PERF_scen1_MT_R)\
 $(TARG_TEST_PERF_scen2_MT_R)\
 $(TARG_TEST_PERF_scen3_MT_R)\
 $(TARG_TEST_PERF_scen4_MT_R)\
 $(TARG_TEST_PERF_scen5_MT_R)\
 $(TARG_TEST_PERF_scen6_MT_R)\
 $(TARG_TEST_PERF_scen7_MT_R)\
 $(TARGETS_TEST_PERFORMANCE_BOOST)\
 \

TARGETS_TEST_SCRATCH=\
 $(TARG_TEST_SCRT_file_MT_D)\
 $(TARG_TEST_SCRT_speech_MT_D)\
 $(TARG_TEST_SCRT_file_MT_D_W)\
 $(TARG_TEST_SCRT_speech_MT_D_W)\
 $(TARG_TEST_SCRT_file_DLL_D)\
 $(TARG_TEST_SCRT_speech_DLL_D)\
 $(TARG_TEST_SCRT_file_DLL_D_W)\
 $(TARG_TEST_SCRT_speech_DLL_D_W)\
 $(TARG_TEST_SCRT_file_DLL_R)\
 $(TARG_TEST_SCRT_speech_DLL_R)\
 $(TARG_TEST_SCRT_file_DLL_R_W)\
 $(TARG_TEST_SCRT_speech_DLL_R_W)\
 $(TARG_TEST_SCRT_file_MT_R)\
 $(TARG_TEST_SCRT_speech_MT_R)\
 $(TARG_TEST_SCRT_file_MT_R_W)\
 $(TARG_TEST_SCRT_speech_MT_R_W)\
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
 $(TARG_TEST_UNIT_ins_ss_MT_D)\
 $(TARG_TEST_UNIT_shim_fi_MT_D)\
 $(TARG_TEST_UNIT_shim_ns_MT_D)\
 $(TARG_TEST_UNIT_snk_a_b_MT_D)\
 $(TARG_TEST_UNIT_snk_c_str_MT_D)\
 $(TARG_TEST_UNIT_snk_chbuf_MT_D)\
 $(TARG_TEST_UNIT_snk_null_MT_D)\
 $(TARG_TEST_UNIT_snk_ods_MT_D)\
 $(TARG_TEST_UNIT_snk_ostm_MT_D)\
 $(TARG_TEST_UNIT_snk_sstm_MT_D)\
 $(TARG_TEST_UNIT_api_acsllen_MT_D_W)\
 $(TARG_TEST_UNIT_api_crlf_MT_D_W)\
 $(TARG_TEST_UNIT_api_flrpl_MT_D_W)\
 $(TARG_TEST_UNIT_api_illfmdh_MT_D_W)\
 $(TARG_TEST_UNIT_api_init_MT_D_W)\
 $(TARG_TEST_UNIT_api_lkptrn_MT_D_W)\
 $(TARG_TEST_UNIT_api_msmtchh_MT_D_W)\
 $(TARG_TEST_UNIT_api_prsrpl_MT_D_W)\
 $(TARG_TEST_UNIT_bndl_winini_MT_D_W)\
 $(TARG_TEST_UNIT_fmt_stdfl_MT_D_W)\
 $(TARG_TEST_UNIT_ins_ch_MT_D_W)\
 $(TARG_TEST_UNIT_ins_i_MT_D_W)\
 $(TARG_TEST_UNIT_ins_ss_MT_D_W)\
 $(TARG_TEST_UNIT_shim_fi_MT_D_W)\
 $(TARG_TEST_UNIT_shim_ns_MT_D_W)\
 $(TARG_TEST_UNIT_snk_a_b_MT_D_W)\
 $(TARG_TEST_UNIT_snk_c_str_MT_D_W)\
 $(TARG_TEST_UNIT_snk_chbuf_MT_D_W)\
 $(TARG_TEST_UNIT_snk_null_MT_D_W)\
 $(TARG_TEST_UNIT_snk_ods_MT_D_W)\
 $(TARG_TEST_UNIT_snk_ostm_MT_D_W)\
 $(TARG_TEST_UNIT_snk_sstm_MT_D_W)\
 $(TARG_TEST_UNIT_api_acsllen_DLL_D)\
 $(TARG_TEST_UNIT_api_crlf_DLL_D)\
 $(TARG_TEST_UNIT_api_flrpl_DLL_D)\
 $(TARG_TEST_UNIT_api_illfmdh_DLL_D)\
 $(TARG_TEST_UNIT_api_init_DLL_D)\
 $(TARG_TEST_UNIT_api_lkptrn_DLL_D)\
 $(TARG_TEST_UNIT_api_msmtchh_DLL_D)\
 $(TARG_TEST_UNIT_api_prsrpl_DLL_D)\
 $(TARG_TEST_UNIT_bndl_winini_DLL_D)\
 $(TARG_TEST_UNIT_fmt_stdfl_DLL_D)\
 $(TARG_TEST_UNIT_ins_ch_DLL_D)\
 $(TARG_TEST_UNIT_ins_i_DLL_D)\
 $(TARG_TEST_UNIT_ins_ss_DLL_D)\
 $(TARG_TEST_UNIT_shim_fi_DLL_D)\
 $(TARG_TEST_UNIT_shim_ns_DLL_D)\
 $(TARG_TEST_UNIT_snk_a_b_DLL_D)\
 $(TARG_TEST_UNIT_snk_c_str_DLL_D)\
 $(TARG_TEST_UNIT_snk_chbuf_DLL_D)\
 $(TARG_TEST_UNIT_snk_mfccstr_DLL_D)\
 $(TARG_TEST_UNIT_snk_null_DLL_D)\
 $(TARG_TEST_UNIT_snk_ods_DLL_D)\
 $(TARG_TEST_UNIT_snk_ostm_DLL_D)\
 $(TARG_TEST_UNIT_snk_sstm_DLL_D)\
 $(TARG_TEST_UNIT_api_acsllen_DLL_D_W)\
 $(TARG_TEST_UNIT_api_crlf_DLL_D_W)\
 $(TARG_TEST_UNIT_api_flrpl_DLL_D_W)\
 $(TARG_TEST_UNIT_api_illfmdh_DLL_D_W)\
 $(TARG_TEST_UNIT_api_init_DLL_D_W)\
 $(TARG_TEST_UNIT_api_lkptrn_DLL_D_W)\
 $(TARG_TEST_UNIT_api_msmtchh_DLL_D_W)\
 $(TARG_TEST_UNIT_api_prsrpl_DLL_D_W)\
 $(TARG_TEST_UNIT_bndl_winini_DLL_D_W)\
 $(TARG_TEST_UNIT_fmt_stdfl_DLL_D_W)\
 $(TARG_TEST_UNIT_ins_ch_DLL_D_W)\
 $(TARG_TEST_UNIT_ins_i_DLL_D_W)\
 $(TARG_TEST_UNIT_ins_ss_DLL_D_W)\
 $(TARG_TEST_UNIT_shim_fi_DLL_D_W)\
 $(TARG_TEST_UNIT_shim_ns_DLL_D_W)\
 $(TARG_TEST_UNIT_snk_a_b_DLL_D_W)\
 $(TARG_TEST_UNIT_snk_c_str_DLL_D_W)\
 $(TARG_TEST_UNIT_snk_chbuf_DLL_D_W)\
 $(TARG_TEST_UNIT_snk_mfccstr_DLL_D_W)\
 $(TARG_TEST_UNIT_snk_null_DLL_D_W)\
 $(TARG_TEST_UNIT_snk_ods_DLL_D_W)\
 $(TARG_TEST_UNIT_snk_ostm_DLL_D_W)\
 $(TARG_TEST_UNIT_snk_sstm_DLL_D_W)\
 $(TARG_TEST_UNIT_api_acsllen_DLL_R)\
 $(TARG_TEST_UNIT_api_crlf_DLL_R)\
 $(TARG_TEST_UNIT_api_flrpl_DLL_R)\
 $(TARG_TEST_UNIT_api_illfmdh_DLL_R)\
 $(TARG_TEST_UNIT_api_init_DLL_R)\
 $(TARG_TEST_UNIT_api_lkptrn_DLL_R)\
 $(TARG_TEST_UNIT_api_msmtchh_DLL_R)\
 $(TARG_TEST_UNIT_api_prsrpl_DLL_R)\
 $(TARG_TEST_UNIT_bndl_winini_DLL_R)\
 $(TARG_TEST_UNIT_fmt_stdfl_DLL_R)\
 $(TARG_TEST_UNIT_ins_ch_DLL_R)\
 $(TARG_TEST_UNIT_ins_i_DLL_R)\
 $(TARG_TEST_UNIT_ins_ss_DLL_R)\
 $(TARG_TEST_UNIT_shim_fi_DLL_R)\
 $(TARG_TEST_UNIT_shim_ns_DLL_R)\
 $(TARG_TEST_UNIT_snk_a_b_DLL_R)\
 $(TARG_TEST_UNIT_snk_c_str_DLL_R)\
 $(TARG_TEST_UNIT_snk_chbuf_DLL_R)\
 $(TARG_TEST_UNIT_snk_mfccstr_DLL_R)\
 $(TARG_TEST_UNIT_snk_null_DLL_R)\
 $(TARG_TEST_UNIT_snk_ods_DLL_R)\
 $(TARG_TEST_UNIT_snk_ostm_DLL_R)\
 $(TARG_TEST_UNIT_snk_sstm_DLL_R)\
 $(TARG_TEST_UNIT_api_acsllen_DLL_R_W)\
 $(TARG_TEST_UNIT_api_crlf_DLL_R_W)\
 $(TARG_TEST_UNIT_api_flrpl_DLL_R_W)\
 $(TARG_TEST_UNIT_api_illfmdh_DLL_R_W)\
 $(TARG_TEST_UNIT_api_init_DLL_R_W)\
 $(TARG_TEST_UNIT_api_lkptrn_DLL_R_W)\
 $(TARG_TEST_UNIT_api_msmtchh_DLL_R_W)\
 $(TARG_TEST_UNIT_api_prsrpl_DLL_R_W)\
 $(TARG_TEST_UNIT_bndl_winini_DLL_R_W)\
 $(TARG_TEST_UNIT_fmt_stdfl_DLL_R_W)\
 $(TARG_TEST_UNIT_ins_ch_DLL_R_W)\
 $(TARG_TEST_UNIT_ins_i_DLL_R_W)\
 $(TARG_TEST_UNIT_ins_ss_DLL_R_W)\
 $(TARG_TEST_UNIT_shim_fi_DLL_R_W)\
 $(TARG_TEST_UNIT_shim_ns_DLL_R_W)\
 $(TARG_TEST_UNIT_snk_a_b_DLL_R_W)\
 $(TARG_TEST_UNIT_snk_c_str_DLL_R_W)\
 $(TARG_TEST_UNIT_snk_chbuf_DLL_R_W)\
 $(TARG_TEST_UNIT_snk_mfccstr_DLL_R_W)\
 $(TARG_TEST_UNIT_snk_null_DLL_R_W)\
 $(TARG_TEST_UNIT_snk_ods_DLL_R_W)\
 $(TARG_TEST_UNIT_snk_ostm_DLL_R_W)\
 $(TARG_TEST_UNIT_snk_sstm_DLL_R_W)\
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
 $(TARG_TEST_UNIT_ins_ss_MT_R)\
 $(TARG_TEST_UNIT_shim_fi_MT_R)\
 $(TARG_TEST_UNIT_shim_ns_MT_R)\
 $(TARG_TEST_UNIT_snk_a_b_MT_R)\
 $(TARG_TEST_UNIT_snk_c_str_MT_R)\
 $(TARG_TEST_UNIT_snk_chbuf_MT_R)\
 $(TARG_TEST_UNIT_snk_null_MT_R)\
 $(TARG_TEST_UNIT_snk_ods_MT_R)\
 $(TARG_TEST_UNIT_snk_ostm_MT_R)\
 $(TARG_TEST_UNIT_snk_sstm_MT_R)\
 $(TARG_TEST_UNIT_api_acsllen_MT_R_W)\
 $(TARG_TEST_UNIT_api_crlf_MT_R_W)\
 $(TARG_TEST_UNIT_api_flrpl_MT_R_W)\
 $(TARG_TEST_UNIT_api_illfmdh_MT_R_W)\
 $(TARG_TEST_UNIT_api_init_MT_R_W)\
 $(TARG_TEST_UNIT_api_lkptrn_MT_R_W)\
 $(TARG_TEST_UNIT_api_msmtchh_MT_R_W)\
 $(TARG_TEST_UNIT_api_prsrpl_MT_R_W)\
 $(TARG_TEST_UNIT_bndl_winini_MT_R_W)\
 $(TARG_TEST_UNIT_fmt_stdfl_MT_R_W)\
 $(TARG_TEST_UNIT_ins_ch_MT_R_W)\
 $(TARG_TEST_UNIT_ins_i_MT_R_W)\
 $(TARG_TEST_UNIT_ins_ss_MT_R_W)\
 $(TARG_TEST_UNIT_shim_fi_MT_R_W)\
 $(TARG_TEST_UNIT_shim_ns_MT_R_W)\
 $(TARG_TEST_UNIT_snk_a_b_MT_R_W)\
 $(TARG_TEST_UNIT_snk_c_str_MT_R_W)\
 $(TARG_TEST_UNIT_snk_chbuf_MT_R_W)\
 $(TARG_TEST_UNIT_snk_null_MT_R_W)\
 $(TARG_TEST_UNIT_snk_ods_MT_R_W)\
 $(TARG_TEST_UNIT_snk_ostm_MT_R_W)\
 $(TARG_TEST_UNIT_snk_sstm_MT_R_W)\
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
	$(TARG_TEST_COMP_file_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_file_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_file_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_file_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_file_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_file_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_file_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_fmt_sink_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_fmt_sink_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_fmt_sink_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_fmt_sink_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_fmt_sink_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_fmt_sink_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_fmt_sink_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_fmt_sink_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_hex_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_hex_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_hex_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_hex_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_hex_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_hex_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_hex_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_hex_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_int_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_int_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_int_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_int_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_int_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_int_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_int_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_int_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_real_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_real_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_real_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_real_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_real_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_real_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_real_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_real_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_itr_fmt_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_itr_fmt_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_itr_fmt_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_itr_fmt_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_itr_fmt_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_itr_fmt_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_itr_fmt_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_itr_fmt_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_null_sink_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_null_sink_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_null_sink_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_null_sink_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_null_sink_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_null_sink_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_null_sink_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_null_sink_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_a_b_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_a_b_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_a_b_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_a_b_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_a_b_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_a_b_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_a_b_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_a_b_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_write_sink_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_write_sink_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_write_sink_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_write_sink_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_write_sink_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_write_sink_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_write_sink_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_write_sink_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_x_1_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_x_1_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_x_1_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_x_1_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_x_1_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_x_1_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_x_1_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_x_1_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_ostm_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_ostm_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_ostm_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_ostm_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_ostm_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_ostm_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_ostm_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_snk_ostm_MT_R_W) --verbosity=$(TEST_VERBOSITY)

test.performance_:
	@echo Running Test:Performance programs ...
	$(TARG_TEST_PERF_scen1_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen2_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen3_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen4_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen5_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen6_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen7_DLL_R) --verbosity=$(TEST_VERBOSITY)
!ifdef BOOST
	$(TARG_TEST_PERF_scen8_DLL_R) --verbosity=$(TEST_VERBOSITY)
!endif # BOOST
	$(TARG_TEST_PERF_scen1_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen2_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen3_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen4_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen5_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen6_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_PERF_scen7_MT_R) --verbosity=$(TEST_VERBOSITY)
!ifdef BOOST
	$(TARG_TEST_PERF_scen8_MT_R) --verbosity=$(TEST_VERBOSITY)
!endif # BOOST

test.scratch_:
	@echo Running Test:Scratch programs ...
	$(TARG_TEST_SCRT_file_MT_D)
	$(TARG_TEST_SCRT_speech_MT_D)
	$(TARG_TEST_SCRT_file_MT_D_W)
	$(TARG_TEST_SCRT_speech_MT_D_W)
	$(TARG_TEST_SCRT_file_DLL_D)
	$(TARG_TEST_SCRT_speech_DLL_D)
	$(TARG_TEST_SCRT_file_DLL_D_W)
	$(TARG_TEST_SCRT_speech_DLL_D_W)
	$(TARG_TEST_SCRT_file_DLL_R)
	$(TARG_TEST_SCRT_speech_DLL_R)
	$(TARG_TEST_SCRT_file_DLL_R_W)
	$(TARG_TEST_SCRT_speech_DLL_R_W)
	$(TARG_TEST_SCRT_file_MT_R)
	$(TARG_TEST_SCRT_speech_MT_R)
	$(TARG_TEST_SCRT_file_MT_R_W)
	$(TARG_TEST_SCRT_speech_MT_R_W)

test.unit_:
	@echo Running Test:Unit programs ...
	$(TARG_TEST_UNIT_api_acsllen_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_acsllen_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_acsllen_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_acsllen_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_acsllen_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_acsllen_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_acsllen_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_acsllen_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_crlf_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_crlf_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_crlf_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_crlf_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_crlf_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_crlf_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_crlf_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_crlf_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_flrpl_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_flrpl_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_flrpl_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_flrpl_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_flrpl_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_flrpl_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_flrpl_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_flrpl_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_illfmdh_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_illfmdh_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_illfmdh_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_illfmdh_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_illfmdh_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_illfmdh_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_illfmdh_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_illfmdh_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_init_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_init_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_init_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_init_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_init_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_init_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_init_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_init_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_lkptrn_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_lkptrn_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_lkptrn_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_lkptrn_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_lkptrn_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_lkptrn_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_lkptrn_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_lkptrn_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_msmtchh_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_msmtchh_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_msmtchh_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_msmtchh_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_msmtchh_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_msmtchh_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_msmtchh_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_msmtchh_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_prsrpl_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_prsrpl_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_prsrpl_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_prsrpl_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_prsrpl_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_prsrpl_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_prsrpl_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_prsrpl_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_bndl_winini_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_bndl_winini_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_bndl_winini_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_bndl_winini_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_bndl_winini_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_bndl_winini_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_bndl_winini_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_bndl_winini_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_fmt_stdfl_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_fmt_stdfl_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_fmt_stdfl_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_fmt_stdfl_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_fmt_stdfl_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_fmt_stdfl_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_fmt_stdfl_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_fmt_stdfl_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_ch_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_ch_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_ch_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_ch_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_ch_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_ch_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_ch_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_ch_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_i_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_i_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_i_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_i_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_i_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_i_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_i_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_i_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_ss_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_ss_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_ss_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_ss_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_ss_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_ss_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_ss_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_ss_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_fi_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_fi_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_fi_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_fi_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_fi_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_fi_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_fi_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_fi_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_fi_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_fi_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_fi_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_fi_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_fi_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_fi_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_fi_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_fi_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_ns_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_ns_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_ns_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_ns_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_ns_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_ns_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_ns_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_shim_ns_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_a_b_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_a_b_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_a_b_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_a_b_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_a_b_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_a_b_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_a_b_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_a_b_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_c_str_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_c_str_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_c_str_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_c_str_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_c_str_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_c_str_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_c_str_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_c_str_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_chbuf_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_chbuf_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_chbuf_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_chbuf_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_chbuf_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_chbuf_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_chbuf_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_chbuf_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_mfccstr_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_mfccstr_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_mfccstr_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_mfccstr_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_null_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_null_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_null_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_null_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_null_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_null_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_null_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_null_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ods_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ods_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ods_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ods_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ods_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ods_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ods_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ods_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ostm_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ostm_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ostm_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ostm_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ostm_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ostm_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ostm_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_ostm_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_sstm_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_sstm_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_sstm_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_sstm_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_sstm_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_sstm_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_sstm_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snk_sstm_MT_R_W) --verbosity=$(TEST_VERBOSITY)

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
	$(TARG_EX_boolean_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_character_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_reals_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_voidptrs_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_itr_fmt_MT_D_W) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_D_W)
	$(TARG_EX_sink_ODS_MT_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_boolean_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_character_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_reals_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_voidptrs_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ff_101_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ff_101_nons_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_flush_DLL_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_D)
	$(TARG_EX_ins_hex_DLL_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_D)
	$(TARG_EX_ins_integers_DLL_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_D)
	$(TARG_EX_ins_reals_DLL_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_D)
	$(TARG_EX_ins_WLIs_DLL_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_D)
	$(TARG_EX_itr_fmt_DLL_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_D)
	$(TARG_EX_ovld2_filt_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ovld2_ins_DLL_D) $(PROJ_BUNDLES_DIR)\superhero.properties --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ovld2_sas_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ovld3_fpcol_DLL_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_D)
	$(TARG_EX_ovld3_tabs_DLL_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_D)
	$(TARG_EX_ovld3_svrlg_DLL_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_D)
	$(TARG_EX_ovld3_rcins_DLL_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_D)
	$(TARG_EX_pad_hash_DLL_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_D)
	$(TARG_EX_sink_cstr_DLL_D) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_D)
	$(TARG_EX_sink_ODS_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_boolean_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_character_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_reals_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_voidptrs_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_itr_fmt_DLL_D_W) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_D_W)
	$(TARG_EX_sink_ODS_DLL_D_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_boolean_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_character_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_reals_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_voidptrs_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ff_101_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ff_101_nons_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_flush_DLL_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_R)
	$(TARG_EX_ins_hex_DLL_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_R)
	$(TARG_EX_ins_integers_DLL_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_R)
	$(TARG_EX_ins_reals_DLL_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_R)
	$(TARG_EX_ins_WLIs_DLL_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_R)
	$(TARG_EX_itr_fmt_DLL_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_R)
	$(TARG_EX_ovld2_filt_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ovld2_ins_DLL_R) $(PROJ_BUNDLES_DIR)\superhero.properties --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ovld2_sas_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_ovld3_fpcol_DLL_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_R)
	$(TARG_EX_ovld3_tabs_DLL_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_R)
	$(TARG_EX_ovld3_svrlg_DLL_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_R)
	$(TARG_EX_ovld3_rcins_DLL_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_R)
	$(TARG_EX_pad_hash_DLL_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_R)
	$(TARG_EX_sink_cstr_DLL_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_R)
	$(TARG_EX_sink_ODS_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_boolean_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_character_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_reals_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_voidptrs_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_itr_fmt_DLL_R_W) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_R_W)
	$(TARG_EX_sink_ODS_DLL_R_W) --verbosity=$(TEST_VERBOSITY)
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
	$(TARG_EX_boolean_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_character_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_reals_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_voidptrs_MT_R_W) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_itr_fmt_MT_R_W) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_R_W)
	$(TARG_EX_sink_ODS_MT_R_W) --verbosity=$(TEST_VERBOSITY)

test.examples.overload.3_:
	@echo Running Overload 3 Example programs ...
	$(TARG_EX_ovld3_fpcol_DLL_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_R)
	$(TARG_EX_ovld3_tabs_DLL_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_R)
	$(TARG_EX_ovld3_svrlg_DLL_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_R)
	$(TARG_EX_ovld3_rcins_DLL_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_DLL_R)
	$(TARG_EX_ovld3_fpcol_MT_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_R)
	$(TARG_EX_ovld3_tabs_MT_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_R)
	$(TARG_EX_ovld3_svrlg_MT_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_R)
	$(TARG_EX_ovld3_rcins_MT_R) --verbosity=$(TEST_VERBOSITY) | $(TARG_BITBUCKET_MT_R)

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
	@-if exist core.*.pdb $(RM) core.*.pdb
	@-if exist core.*.manifest $(RM) core.*.manifest
	@-if exist $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG)*.lib $(RM) $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG)*.lib

clean.libs.loki.safefmt:
	@echo cleaning Loki.SafeFormat libraries ...
	@-if exist loki.safefmt.*.obj $(RM) loki.safefmt.*.obj
	@-if exist loki.safefmt.*.pdb $(RM) loki.safefmt.*.pdb
	@-if exist loki.safefmt.*.manifest $(RM) loki.safefmt.*.manifest
	@-if exist $(PROJ_LIB_DIR)\$(LOKI_SFMT_TAG_VER).ff.$(COMP_ARCH_OS_TAG)*.lib $(RM) $(PROJ_LIB_DIR)\$(LOKI_SFMT_TAG_VER).ff.$(COMP_ARCH_OS_TAG)*.lib

clean.libs.shwild:
	@echo cleaning shwild libraries ...
	@-if exist shwild.*.obj $(RM) shwild.*.obj
	@-if exist shwild.*.pdb $(RM) shwild.*.pdb
	@-if exist shwild.*.manifest $(RM) shwild.*.manifest
	@-if exist $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).ff.$(COMP_ARCH_OS_TAG)*.lib $(RM) $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).ff.$(COMP_ARCH_OS_TAG)*.lib

clean.libs.xtests:
	@echo cleaning xTests libraries ...
	@-if exist xtests.*.obj $(RM) xtests.*.obj
	@-if exist xtests.*.pdb $(RM) xtests.*.pdb
	@-if exist xtests.*.manifest $(RM) xtests.*.manifest
	@-if exist $(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).ff.$(COMP_ARCH_OS_TAG)*.lib $(RM) $(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).ff.$(COMP_ARCH_OS_TAG)*.lib

clean.libs:                                         clean.libs.core clean.libs.loki.safefmt clean.libs.shwild clean.libs.xtests

clean.bitbucket:
	@echo cleaning Bitbucket programs ...
	@-if exist $(TARG_BITBUCKET_MT_D) $(RM) $(TARG_BITBUCKET_MT_D)
	@-if exist $(OBJ_BITBUCKET_MT_D) $(RM) $(OBJ_BITBUCKET_MT_D)
	@-if exist bitbucket.*.pdb $(RM) bitbucket.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.*.manifest
	@-if exist $(TARG_BITBUCKET_MT_D_W) $(RM) $(TARG_BITBUCKET_MT_D_W)
	@-if exist $(OBJ_BITBUCKET_MT_D_W) $(RM) $(OBJ_BITBUCKET_MT_D_W)
	@-if exist bitbucket.*.pdb $(RM) bitbucket.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.*.manifest
	@-if exist $(TARG_BITBUCKET_DLL_D) $(RM) $(TARG_BITBUCKET_DLL_D)
	@-if exist $(OBJ_BITBUCKET_DLL_D) $(RM) $(OBJ_BITBUCKET_DLL_D)
	@-if exist bitbucket.*.pdb $(RM) bitbucket.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.*.manifest
	@-if exist $(TARG_BITBUCKET_DLL_D_W) $(RM) $(TARG_BITBUCKET_DLL_D_W)
	@-if exist $(OBJ_BITBUCKET_DLL_D_W) $(RM) $(OBJ_BITBUCKET_DLL_D_W)
	@-if exist bitbucket.*.pdb $(RM) bitbucket.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.*.manifest
	@-if exist $(TARG_BITBUCKET_DLL_R) $(RM) $(TARG_BITBUCKET_DLL_R)
	@-if exist $(OBJ_BITBUCKET_DLL_R) $(RM) $(OBJ_BITBUCKET_DLL_R)
	@-if exist bitbucket.*.pdb $(RM) bitbucket.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.*.manifest
	@-if exist $(TARG_BITBUCKET_DLL_R_W) $(RM) $(TARG_BITBUCKET_DLL_R_W)
	@-if exist $(OBJ_BITBUCKET_DLL_R_W) $(RM) $(OBJ_BITBUCKET_DLL_R_W)
	@-if exist bitbucket.*.pdb $(RM) bitbucket.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.*.manifest
	@-if exist $(TARG_BITBUCKET_MT_R) $(RM) $(TARG_BITBUCKET_MT_R)
	@-if exist $(OBJ_BITBUCKET_MT_R) $(RM) $(OBJ_BITBUCKET_MT_R)
	@-if exist bitbucket.*.pdb $(RM) bitbucket.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.*.manifest
	@-if exist $(TARG_BITBUCKET_MT_R_W) $(RM) $(TARG_BITBUCKET_MT_R_W)
	@-if exist $(OBJ_BITBUCKET_MT_R_W) $(RM) $(OBJ_BITBUCKET_MT_R_W)
	@-if exist bitbucket.*.pdb $(RM) bitbucket.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).bitbucket.*.manifest

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
	@-if exist example.*.pdb $(RM) example.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.*.manifest
	@-if exist $(TARG_EX_boolean_MT_D_W) $(RM) $(TARG_EX_boolean_MT_D_W)
	@-if exist $(OBJ_EX_boolean_MT_D_W) $(RM) $(OBJ_EX_boolean_MT_D_W)
	@-if exist $(TARG_EX_character_MT_D_W) $(RM) $(TARG_EX_character_MT_D_W)
	@-if exist $(OBJ_EX_character_MT_D_W) $(RM) $(OBJ_EX_character_MT_D_W)
	@-if exist $(TARG_EX_reals_MT_D_W) $(RM) $(TARG_EX_reals_MT_D_W)
	@-if exist $(OBJ_EX_reals_MT_D_W) $(RM) $(OBJ_EX_reals_MT_D_W)
	@-if exist $(TARG_EX_voidptrs_MT_D_W) $(RM) $(TARG_EX_voidptrs_MT_D_W)
	@-if exist $(OBJ_EX_voidptrs_MT_D_W) $(RM) $(OBJ_EX_voidptrs_MT_D_W)
	@-if exist $(TARG_EX_ff_101_MT_D_W) $(RM) $(TARG_EX_ff_101_MT_D_W)
	@-if exist $(OBJ_EX_ff_101_MT_D_W) $(RM) $(OBJ_EX_ff_101_MT_D_W)
	@-if exist $(TARG_EX_ff_101_nons_MT_D_W) $(RM) $(TARG_EX_ff_101_nons_MT_D_W)
	@-if exist $(OBJ_EX_ff_101_nons_MT_D_W) $(RM) $(OBJ_EX_ff_101_nons_MT_D_W)
	@-if exist $(TARG_EX_flush_MT_D_W) $(RM) $(TARG_EX_flush_MT_D_W)
	@-if exist $(OBJ_EX_flush_MT_D_W) $(RM) $(OBJ_EX_flush_MT_D_W)
	@-if exist $(TARG_EX_ins_hex_MT_D_W) $(RM) $(TARG_EX_ins_hex_MT_D_W)
	@-if exist $(OBJ_EX_ins_hex_MT_D_W) $(RM) $(OBJ_EX_ins_hex_MT_D_W)
	@-if exist $(TARG_EX_ins_integers_MT_D_W) $(RM) $(TARG_EX_ins_integers_MT_D_W)
	@-if exist $(OBJ_EX_ins_integers_MT_D_W) $(RM) $(OBJ_EX_ins_integers_MT_D_W)
	@-if exist $(TARG_EX_ins_WLIs_MT_D_W) $(RM) $(TARG_EX_ins_WLIs_MT_D_W)
	@-if exist $(OBJ_EX_ins_WLIs_MT_D_W) $(RM) $(OBJ_EX_ins_WLIs_MT_D_W)
	@-if exist $(TARG_EX_ins_reals_MT_D_W) $(RM) $(TARG_EX_ins_reals_MT_D_W)
	@-if exist $(OBJ_EX_ins_reals_MT_D_W) $(RM) $(OBJ_EX_ins_reals_MT_D_W)
	@-if exist $(TARG_EX_itr_fmt_MT_D_W) $(RM) $(TARG_EX_itr_fmt_MT_D_W)
	@-if exist $(OBJ_EX_itr_fmt_MT_D_W) $(RM) $(OBJ_EX_itr_fmt_MT_D_W)
	@-if exist $(TARG_EX_ovld2_filt_MT_D_W) $(RM) $(TARG_EX_ovld2_filt_MT_D_W)
	@-if exist $(OBJ_EX_ovld2_filt_MT_D_W) $(RM) $(OBJ_EX_ovld2_filt_MT_D_W)
	@-if exist $(TARG_EX_ovld2_ins_MT_D_W) $(RM) $(TARG_EX_ovld2_ins_MT_D_W)
	@-if exist $(OBJ_EX_ovld2_ins_MT_D_W) $(RM) $(OBJ_EX_ovld2_ins_MT_D_W)
	@-if exist $(TARG_EX_ovld2_sas_MT_D_W) $(RM) $(TARG_EX_ovld2_sas_MT_D_W)
	@-if exist $(OBJ_EX_ovld2_sas_MT_D_W) $(RM) $(OBJ_EX_ovld2_sas_MT_D_W)
	@-if exist $(TARG_EX_ovld3_fpcol_MT_D_W) $(RM) $(TARG_EX_ovld3_fpcol_MT_D_W)
	@-if exist $(OBJ_EX_ovld3_fpcol_MT_D_W) $(RM) $(OBJ_EX_ovld3_fpcol_MT_D_W)
	@-if exist $(TARG_EX_ovld3_tabs_MT_D_W) $(RM) $(TARG_EX_ovld3_tabs_MT_D_W)
	@-if exist $(OBJ_EX_ovld3_tabs_MT_D_W) $(RM) $(OBJ_EX_ovld3_tabs_MT_D_W)
	@-if exist $(TARG_EX_ovld3_svrlg_MT_D_W) $(RM) $(TARG_EX_ovld3_svrlg_MT_D_W)
	@-if exist $(OBJ_EX_ovld3_svrlg_MT_D_W) $(RM) $(OBJ_EX_ovld3_svrlg_MT_D_W)
	@-if exist $(TARG_EX_ovld3_rcins_MT_D_W) $(RM) $(TARG_EX_ovld3_rcins_MT_D_W)
	@-if exist $(OBJ_EX_ovld3_rcins_MT_D_W) $(RM) $(OBJ_EX_ovld3_rcins_MT_D_W)
	@-if exist $(TARG_EX_pad_hash_MT_D_W) $(RM) $(TARG_EX_pad_hash_MT_D_W)
	@-if exist $(OBJ_EX_pad_hash_MT_D_W) $(RM) $(OBJ_EX_pad_hash_MT_D_W)
	@-if exist $(TARG_EX_sink_cstr_MT_D_W) $(RM) $(TARG_EX_sink_cstr_MT_D_W)
	@-if exist $(OBJ_EX_sink_cstr_MT_D_W) $(RM) $(OBJ_EX_sink_cstr_MT_D_W)
	@-if exist $(TARG_EX_sink_ODS_MT_D_W) $(RM) $(TARG_EX_sink_ODS_MT_D_W)
	@-if exist $(OBJ_EX_sink_ODS_MT_D_W) $(RM) $(OBJ_EX_sink_ODS_MT_D_W)
	@-if exist example.*.pdb $(RM) example.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.*.manifest
	@-if exist $(TARG_EX_boolean_DLL_D) $(RM) $(TARG_EX_boolean_DLL_D)
	@-if exist $(OBJ_EX_boolean_DLL_D) $(RM) $(OBJ_EX_boolean_DLL_D)
	@-if exist $(TARG_EX_character_DLL_D) $(RM) $(TARG_EX_character_DLL_D)
	@-if exist $(OBJ_EX_character_DLL_D) $(RM) $(OBJ_EX_character_DLL_D)
	@-if exist $(TARG_EX_reals_DLL_D) $(RM) $(TARG_EX_reals_DLL_D)
	@-if exist $(OBJ_EX_reals_DLL_D) $(RM) $(OBJ_EX_reals_DLL_D)
	@-if exist $(TARG_EX_voidptrs_DLL_D) $(RM) $(TARG_EX_voidptrs_DLL_D)
	@-if exist $(OBJ_EX_voidptrs_DLL_D) $(RM) $(OBJ_EX_voidptrs_DLL_D)
	@-if exist $(TARG_EX_ff_101_DLL_D) $(RM) $(TARG_EX_ff_101_DLL_D)
	@-if exist $(OBJ_EX_ff_101_DLL_D) $(RM) $(OBJ_EX_ff_101_DLL_D)
	@-if exist $(TARG_EX_ff_101_nons_DLL_D) $(RM) $(TARG_EX_ff_101_nons_DLL_D)
	@-if exist $(OBJ_EX_ff_101_nons_DLL_D) $(RM) $(OBJ_EX_ff_101_nons_DLL_D)
	@-if exist $(TARG_EX_flush_DLL_D) $(RM) $(TARG_EX_flush_DLL_D)
	@-if exist $(OBJ_EX_flush_DLL_D) $(RM) $(OBJ_EX_flush_DLL_D)
	@-if exist $(TARG_EX_ins_hex_DLL_D) $(RM) $(TARG_EX_ins_hex_DLL_D)
	@-if exist $(OBJ_EX_ins_hex_DLL_D) $(RM) $(OBJ_EX_ins_hex_DLL_D)
	@-if exist $(TARG_EX_ins_integers_DLL_D) $(RM) $(TARG_EX_ins_integers_DLL_D)
	@-if exist $(OBJ_EX_ins_integers_DLL_D) $(RM) $(OBJ_EX_ins_integers_DLL_D)
	@-if exist $(TARG_EX_ins_WLIs_DLL_D) $(RM) $(TARG_EX_ins_WLIs_DLL_D)
	@-if exist $(OBJ_EX_ins_WLIs_DLL_D) $(RM) $(OBJ_EX_ins_WLIs_DLL_D)
	@-if exist $(TARG_EX_ins_reals_DLL_D) $(RM) $(TARG_EX_ins_reals_DLL_D)
	@-if exist $(OBJ_EX_ins_reals_DLL_D) $(RM) $(OBJ_EX_ins_reals_DLL_D)
	@-if exist $(TARG_EX_itr_fmt_DLL_D) $(RM) $(TARG_EX_itr_fmt_DLL_D)
	@-if exist $(OBJ_EX_itr_fmt_DLL_D) $(RM) $(OBJ_EX_itr_fmt_DLL_D)
	@-if exist $(TARG_EX_ovld2_filt_DLL_D) $(RM) $(TARG_EX_ovld2_filt_DLL_D)
	@-if exist $(OBJ_EX_ovld2_filt_DLL_D) $(RM) $(OBJ_EX_ovld2_filt_DLL_D)
	@-if exist $(TARG_EX_ovld2_ins_DLL_D) $(RM) $(TARG_EX_ovld2_ins_DLL_D)
	@-if exist $(OBJ_EX_ovld2_ins_DLL_D) $(RM) $(OBJ_EX_ovld2_ins_DLL_D)
	@-if exist $(TARG_EX_ovld2_sas_DLL_D) $(RM) $(TARG_EX_ovld2_sas_DLL_D)
	@-if exist $(OBJ_EX_ovld2_sas_DLL_D) $(RM) $(OBJ_EX_ovld2_sas_DLL_D)
	@-if exist $(TARG_EX_ovld3_fpcol_DLL_D) $(RM) $(TARG_EX_ovld3_fpcol_DLL_D)
	@-if exist $(OBJ_EX_ovld3_fpcol_DLL_D) $(RM) $(OBJ_EX_ovld3_fpcol_DLL_D)
	@-if exist $(TARG_EX_ovld3_tabs_DLL_D) $(RM) $(TARG_EX_ovld3_tabs_DLL_D)
	@-if exist $(OBJ_EX_ovld3_tabs_DLL_D) $(RM) $(OBJ_EX_ovld3_tabs_DLL_D)
	@-if exist $(TARG_EX_ovld3_svrlg_DLL_D) $(RM) $(TARG_EX_ovld3_svrlg_DLL_D)
	@-if exist $(OBJ_EX_ovld3_svrlg_DLL_D) $(RM) $(OBJ_EX_ovld3_svrlg_DLL_D)
	@-if exist $(TARG_EX_ovld3_rcins_DLL_D) $(RM) $(TARG_EX_ovld3_rcins_DLL_D)
	@-if exist $(OBJ_EX_ovld3_rcins_DLL_D) $(RM) $(OBJ_EX_ovld3_rcins_DLL_D)
	@-if exist $(TARG_EX_pad_hash_DLL_D) $(RM) $(TARG_EX_pad_hash_DLL_D)
	@-if exist $(OBJ_EX_pad_hash_DLL_D) $(RM) $(OBJ_EX_pad_hash_DLL_D)
	@-if exist $(TARG_EX_sink_cstr_DLL_D) $(RM) $(TARG_EX_sink_cstr_DLL_D)
	@-if exist $(OBJ_EX_sink_cstr_DLL_D) $(RM) $(OBJ_EX_sink_cstr_DLL_D)
	@-if exist $(TARG_EX_sink_ODS_DLL_D) $(RM) $(TARG_EX_sink_ODS_DLL_D)
	@-if exist $(OBJ_EX_sink_ODS_DLL_D) $(RM) $(OBJ_EX_sink_ODS_DLL_D)
	@-if exist example.*.pdb $(RM) example.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.*.manifest
	@-if exist $(TARG_EX_boolean_DLL_D_W) $(RM) $(TARG_EX_boolean_DLL_D_W)
	@-if exist $(OBJ_EX_boolean_DLL_D_W) $(RM) $(OBJ_EX_boolean_DLL_D_W)
	@-if exist $(TARG_EX_character_DLL_D_W) $(RM) $(TARG_EX_character_DLL_D_W)
	@-if exist $(OBJ_EX_character_DLL_D_W) $(RM) $(OBJ_EX_character_DLL_D_W)
	@-if exist $(TARG_EX_reals_DLL_D_W) $(RM) $(TARG_EX_reals_DLL_D_W)
	@-if exist $(OBJ_EX_reals_DLL_D_W) $(RM) $(OBJ_EX_reals_DLL_D_W)
	@-if exist $(TARG_EX_voidptrs_DLL_D_W) $(RM) $(TARG_EX_voidptrs_DLL_D_W)
	@-if exist $(OBJ_EX_voidptrs_DLL_D_W) $(RM) $(OBJ_EX_voidptrs_DLL_D_W)
	@-if exist $(TARG_EX_ff_101_DLL_D_W) $(RM) $(TARG_EX_ff_101_DLL_D_W)
	@-if exist $(OBJ_EX_ff_101_DLL_D_W) $(RM) $(OBJ_EX_ff_101_DLL_D_W)
	@-if exist $(TARG_EX_ff_101_nons_DLL_D_W) $(RM) $(TARG_EX_ff_101_nons_DLL_D_W)
	@-if exist $(OBJ_EX_ff_101_nons_DLL_D_W) $(RM) $(OBJ_EX_ff_101_nons_DLL_D_W)
	@-if exist $(TARG_EX_flush_DLL_D_W) $(RM) $(TARG_EX_flush_DLL_D_W)
	@-if exist $(OBJ_EX_flush_DLL_D_W) $(RM) $(OBJ_EX_flush_DLL_D_W)
	@-if exist $(TARG_EX_ins_hex_DLL_D_W) $(RM) $(TARG_EX_ins_hex_DLL_D_W)
	@-if exist $(OBJ_EX_ins_hex_DLL_D_W) $(RM) $(OBJ_EX_ins_hex_DLL_D_W)
	@-if exist $(TARG_EX_ins_integers_DLL_D_W) $(RM) $(TARG_EX_ins_integers_DLL_D_W)
	@-if exist $(OBJ_EX_ins_integers_DLL_D_W) $(RM) $(OBJ_EX_ins_integers_DLL_D_W)
	@-if exist $(TARG_EX_ins_WLIs_DLL_D_W) $(RM) $(TARG_EX_ins_WLIs_DLL_D_W)
	@-if exist $(OBJ_EX_ins_WLIs_DLL_D_W) $(RM) $(OBJ_EX_ins_WLIs_DLL_D_W)
	@-if exist $(TARG_EX_ins_reals_DLL_D_W) $(RM) $(TARG_EX_ins_reals_DLL_D_W)
	@-if exist $(OBJ_EX_ins_reals_DLL_D_W) $(RM) $(OBJ_EX_ins_reals_DLL_D_W)
	@-if exist $(TARG_EX_itr_fmt_DLL_D_W) $(RM) $(TARG_EX_itr_fmt_DLL_D_W)
	@-if exist $(OBJ_EX_itr_fmt_DLL_D_W) $(RM) $(OBJ_EX_itr_fmt_DLL_D_W)
	@-if exist $(TARG_EX_ovld2_filt_DLL_D_W) $(RM) $(TARG_EX_ovld2_filt_DLL_D_W)
	@-if exist $(OBJ_EX_ovld2_filt_DLL_D_W) $(RM) $(OBJ_EX_ovld2_filt_DLL_D_W)
	@-if exist $(TARG_EX_ovld2_ins_DLL_D_W) $(RM) $(TARG_EX_ovld2_ins_DLL_D_W)
	@-if exist $(OBJ_EX_ovld2_ins_DLL_D_W) $(RM) $(OBJ_EX_ovld2_ins_DLL_D_W)
	@-if exist $(TARG_EX_ovld2_sas_DLL_D_W) $(RM) $(TARG_EX_ovld2_sas_DLL_D_W)
	@-if exist $(OBJ_EX_ovld2_sas_DLL_D_W) $(RM) $(OBJ_EX_ovld2_sas_DLL_D_W)
	@-if exist $(TARG_EX_ovld3_fpcol_DLL_D_W) $(RM) $(TARG_EX_ovld3_fpcol_DLL_D_W)
	@-if exist $(OBJ_EX_ovld3_fpcol_DLL_D_W) $(RM) $(OBJ_EX_ovld3_fpcol_DLL_D_W)
	@-if exist $(TARG_EX_ovld3_tabs_DLL_D_W) $(RM) $(TARG_EX_ovld3_tabs_DLL_D_W)
	@-if exist $(OBJ_EX_ovld3_tabs_DLL_D_W) $(RM) $(OBJ_EX_ovld3_tabs_DLL_D_W)
	@-if exist $(TARG_EX_ovld3_svrlg_DLL_D_W) $(RM) $(TARG_EX_ovld3_svrlg_DLL_D_W)
	@-if exist $(OBJ_EX_ovld3_svrlg_DLL_D_W) $(RM) $(OBJ_EX_ovld3_svrlg_DLL_D_W)
	@-if exist $(TARG_EX_ovld3_rcins_DLL_D_W) $(RM) $(TARG_EX_ovld3_rcins_DLL_D_W)
	@-if exist $(OBJ_EX_ovld3_rcins_DLL_D_W) $(RM) $(OBJ_EX_ovld3_rcins_DLL_D_W)
	@-if exist $(TARG_EX_pad_hash_DLL_D_W) $(RM) $(TARG_EX_pad_hash_DLL_D_W)
	@-if exist $(OBJ_EX_pad_hash_DLL_D_W) $(RM) $(OBJ_EX_pad_hash_DLL_D_W)
	@-if exist $(TARG_EX_sink_cstr_DLL_D_W) $(RM) $(TARG_EX_sink_cstr_DLL_D_W)
	@-if exist $(OBJ_EX_sink_cstr_DLL_D_W) $(RM) $(OBJ_EX_sink_cstr_DLL_D_W)
	@-if exist $(TARG_EX_sink_ODS_DLL_D_W) $(RM) $(TARG_EX_sink_ODS_DLL_D_W)
	@-if exist $(OBJ_EX_sink_ODS_DLL_D_W) $(RM) $(OBJ_EX_sink_ODS_DLL_D_W)
	@-if exist example.*.pdb $(RM) example.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.*.manifest
	@-if exist $(TARG_EX_boolean_DLL_R) $(RM) $(TARG_EX_boolean_DLL_R)
	@-if exist $(OBJ_EX_boolean_DLL_R) $(RM) $(OBJ_EX_boolean_DLL_R)
	@-if exist $(TARG_EX_character_DLL_R) $(RM) $(TARG_EX_character_DLL_R)
	@-if exist $(OBJ_EX_character_DLL_R) $(RM) $(OBJ_EX_character_DLL_R)
	@-if exist $(TARG_EX_reals_DLL_R) $(RM) $(TARG_EX_reals_DLL_R)
	@-if exist $(OBJ_EX_reals_DLL_R) $(RM) $(OBJ_EX_reals_DLL_R)
	@-if exist $(TARG_EX_voidptrs_DLL_R) $(RM) $(TARG_EX_voidptrs_DLL_R)
	@-if exist $(OBJ_EX_voidptrs_DLL_R) $(RM) $(OBJ_EX_voidptrs_DLL_R)
	@-if exist $(TARG_EX_ff_101_DLL_R) $(RM) $(TARG_EX_ff_101_DLL_R)
	@-if exist $(OBJ_EX_ff_101_DLL_R) $(RM) $(OBJ_EX_ff_101_DLL_R)
	@-if exist $(TARG_EX_ff_101_nons_DLL_R) $(RM) $(TARG_EX_ff_101_nons_DLL_R)
	@-if exist $(OBJ_EX_ff_101_nons_DLL_R) $(RM) $(OBJ_EX_ff_101_nons_DLL_R)
	@-if exist $(TARG_EX_flush_DLL_R) $(RM) $(TARG_EX_flush_DLL_R)
	@-if exist $(OBJ_EX_flush_DLL_R) $(RM) $(OBJ_EX_flush_DLL_R)
	@-if exist $(TARG_EX_ins_hex_DLL_R) $(RM) $(TARG_EX_ins_hex_DLL_R)
	@-if exist $(OBJ_EX_ins_hex_DLL_R) $(RM) $(OBJ_EX_ins_hex_DLL_R)
	@-if exist $(TARG_EX_ins_integers_DLL_R) $(RM) $(TARG_EX_ins_integers_DLL_R)
	@-if exist $(OBJ_EX_ins_integers_DLL_R) $(RM) $(OBJ_EX_ins_integers_DLL_R)
	@-if exist $(TARG_EX_ins_WLIs_DLL_R) $(RM) $(TARG_EX_ins_WLIs_DLL_R)
	@-if exist $(OBJ_EX_ins_WLIs_DLL_R) $(RM) $(OBJ_EX_ins_WLIs_DLL_R)
	@-if exist $(TARG_EX_ins_reals_DLL_R) $(RM) $(TARG_EX_ins_reals_DLL_R)
	@-if exist $(OBJ_EX_ins_reals_DLL_R) $(RM) $(OBJ_EX_ins_reals_DLL_R)
	@-if exist $(TARG_EX_itr_fmt_DLL_R) $(RM) $(TARG_EX_itr_fmt_DLL_R)
	@-if exist $(OBJ_EX_itr_fmt_DLL_R) $(RM) $(OBJ_EX_itr_fmt_DLL_R)
	@-if exist $(TARG_EX_ovld2_filt_DLL_R) $(RM) $(TARG_EX_ovld2_filt_DLL_R)
	@-if exist $(OBJ_EX_ovld2_filt_DLL_R) $(RM) $(OBJ_EX_ovld2_filt_DLL_R)
	@-if exist $(TARG_EX_ovld2_ins_DLL_R) $(RM) $(TARG_EX_ovld2_ins_DLL_R)
	@-if exist $(OBJ_EX_ovld2_ins_DLL_R) $(RM) $(OBJ_EX_ovld2_ins_DLL_R)
	@-if exist $(TARG_EX_ovld2_sas_DLL_R) $(RM) $(TARG_EX_ovld2_sas_DLL_R)
	@-if exist $(OBJ_EX_ovld2_sas_DLL_R) $(RM) $(OBJ_EX_ovld2_sas_DLL_R)
	@-if exist $(TARG_EX_ovld3_fpcol_DLL_R) $(RM) $(TARG_EX_ovld3_fpcol_DLL_R)
	@-if exist $(OBJ_EX_ovld3_fpcol_DLL_R) $(RM) $(OBJ_EX_ovld3_fpcol_DLL_R)
	@-if exist $(TARG_EX_ovld3_tabs_DLL_R) $(RM) $(TARG_EX_ovld3_tabs_DLL_R)
	@-if exist $(OBJ_EX_ovld3_tabs_DLL_R) $(RM) $(OBJ_EX_ovld3_tabs_DLL_R)
	@-if exist $(TARG_EX_ovld3_svrlg_DLL_R) $(RM) $(TARG_EX_ovld3_svrlg_DLL_R)
	@-if exist $(OBJ_EX_ovld3_svrlg_DLL_R) $(RM) $(OBJ_EX_ovld3_svrlg_DLL_R)
	@-if exist $(TARG_EX_ovld3_rcins_DLL_R) $(RM) $(TARG_EX_ovld3_rcins_DLL_R)
	@-if exist $(OBJ_EX_ovld3_rcins_DLL_R) $(RM) $(OBJ_EX_ovld3_rcins_DLL_R)
	@-if exist $(TARG_EX_pad_hash_DLL_R) $(RM) $(TARG_EX_pad_hash_DLL_R)
	@-if exist $(OBJ_EX_pad_hash_DLL_R) $(RM) $(OBJ_EX_pad_hash_DLL_R)
	@-if exist $(TARG_EX_sink_cstr_DLL_R) $(RM) $(TARG_EX_sink_cstr_DLL_R)
	@-if exist $(OBJ_EX_sink_cstr_DLL_R) $(RM) $(OBJ_EX_sink_cstr_DLL_R)
	@-if exist $(TARG_EX_sink_ODS_DLL_R) $(RM) $(TARG_EX_sink_ODS_DLL_R)
	@-if exist $(OBJ_EX_sink_ODS_DLL_R) $(RM) $(OBJ_EX_sink_ODS_DLL_R)
	@-if exist example.*.pdb $(RM) example.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.*.manifest
	@-if exist $(TARG_EX_boolean_DLL_R_W) $(RM) $(TARG_EX_boolean_DLL_R_W)
	@-if exist $(OBJ_EX_boolean_DLL_R_W) $(RM) $(OBJ_EX_boolean_DLL_R_W)
	@-if exist $(TARG_EX_character_DLL_R_W) $(RM) $(TARG_EX_character_DLL_R_W)
	@-if exist $(OBJ_EX_character_DLL_R_W) $(RM) $(OBJ_EX_character_DLL_R_W)
	@-if exist $(TARG_EX_reals_DLL_R_W) $(RM) $(TARG_EX_reals_DLL_R_W)
	@-if exist $(OBJ_EX_reals_DLL_R_W) $(RM) $(OBJ_EX_reals_DLL_R_W)
	@-if exist $(TARG_EX_voidptrs_DLL_R_W) $(RM) $(TARG_EX_voidptrs_DLL_R_W)
	@-if exist $(OBJ_EX_voidptrs_DLL_R_W) $(RM) $(OBJ_EX_voidptrs_DLL_R_W)
	@-if exist $(TARG_EX_ff_101_DLL_R_W) $(RM) $(TARG_EX_ff_101_DLL_R_W)
	@-if exist $(OBJ_EX_ff_101_DLL_R_W) $(RM) $(OBJ_EX_ff_101_DLL_R_W)
	@-if exist $(TARG_EX_ff_101_nons_DLL_R_W) $(RM) $(TARG_EX_ff_101_nons_DLL_R_W)
	@-if exist $(OBJ_EX_ff_101_nons_DLL_R_W) $(RM) $(OBJ_EX_ff_101_nons_DLL_R_W)
	@-if exist $(TARG_EX_flush_DLL_R_W) $(RM) $(TARG_EX_flush_DLL_R_W)
	@-if exist $(OBJ_EX_flush_DLL_R_W) $(RM) $(OBJ_EX_flush_DLL_R_W)
	@-if exist $(TARG_EX_ins_hex_DLL_R_W) $(RM) $(TARG_EX_ins_hex_DLL_R_W)
	@-if exist $(OBJ_EX_ins_hex_DLL_R_W) $(RM) $(OBJ_EX_ins_hex_DLL_R_W)
	@-if exist $(TARG_EX_ins_integers_DLL_R_W) $(RM) $(TARG_EX_ins_integers_DLL_R_W)
	@-if exist $(OBJ_EX_ins_integers_DLL_R_W) $(RM) $(OBJ_EX_ins_integers_DLL_R_W)
	@-if exist $(TARG_EX_ins_WLIs_DLL_R_W) $(RM) $(TARG_EX_ins_WLIs_DLL_R_W)
	@-if exist $(OBJ_EX_ins_WLIs_DLL_R_W) $(RM) $(OBJ_EX_ins_WLIs_DLL_R_W)
	@-if exist $(TARG_EX_ins_reals_DLL_R_W) $(RM) $(TARG_EX_ins_reals_DLL_R_W)
	@-if exist $(OBJ_EX_ins_reals_DLL_R_W) $(RM) $(OBJ_EX_ins_reals_DLL_R_W)
	@-if exist $(TARG_EX_itr_fmt_DLL_R_W) $(RM) $(TARG_EX_itr_fmt_DLL_R_W)
	@-if exist $(OBJ_EX_itr_fmt_DLL_R_W) $(RM) $(OBJ_EX_itr_fmt_DLL_R_W)
	@-if exist $(TARG_EX_ovld2_filt_DLL_R_W) $(RM) $(TARG_EX_ovld2_filt_DLL_R_W)
	@-if exist $(OBJ_EX_ovld2_filt_DLL_R_W) $(RM) $(OBJ_EX_ovld2_filt_DLL_R_W)
	@-if exist $(TARG_EX_ovld2_ins_DLL_R_W) $(RM) $(TARG_EX_ovld2_ins_DLL_R_W)
	@-if exist $(OBJ_EX_ovld2_ins_DLL_R_W) $(RM) $(OBJ_EX_ovld2_ins_DLL_R_W)
	@-if exist $(TARG_EX_ovld2_sas_DLL_R_W) $(RM) $(TARG_EX_ovld2_sas_DLL_R_W)
	@-if exist $(OBJ_EX_ovld2_sas_DLL_R_W) $(RM) $(OBJ_EX_ovld2_sas_DLL_R_W)
	@-if exist $(TARG_EX_ovld3_fpcol_DLL_R_W) $(RM) $(TARG_EX_ovld3_fpcol_DLL_R_W)
	@-if exist $(OBJ_EX_ovld3_fpcol_DLL_R_W) $(RM) $(OBJ_EX_ovld3_fpcol_DLL_R_W)
	@-if exist $(TARG_EX_ovld3_tabs_DLL_R_W) $(RM) $(TARG_EX_ovld3_tabs_DLL_R_W)
	@-if exist $(OBJ_EX_ovld3_tabs_DLL_R_W) $(RM) $(OBJ_EX_ovld3_tabs_DLL_R_W)
	@-if exist $(TARG_EX_ovld3_svrlg_DLL_R_W) $(RM) $(TARG_EX_ovld3_svrlg_DLL_R_W)
	@-if exist $(OBJ_EX_ovld3_svrlg_DLL_R_W) $(RM) $(OBJ_EX_ovld3_svrlg_DLL_R_W)
	@-if exist $(TARG_EX_ovld3_rcins_DLL_R_W) $(RM) $(TARG_EX_ovld3_rcins_DLL_R_W)
	@-if exist $(OBJ_EX_ovld3_rcins_DLL_R_W) $(RM) $(OBJ_EX_ovld3_rcins_DLL_R_W)
	@-if exist $(TARG_EX_pad_hash_DLL_R_W) $(RM) $(TARG_EX_pad_hash_DLL_R_W)
	@-if exist $(OBJ_EX_pad_hash_DLL_R_W) $(RM) $(OBJ_EX_pad_hash_DLL_R_W)
	@-if exist $(TARG_EX_sink_cstr_DLL_R_W) $(RM) $(TARG_EX_sink_cstr_DLL_R_W)
	@-if exist $(OBJ_EX_sink_cstr_DLL_R_W) $(RM) $(OBJ_EX_sink_cstr_DLL_R_W)
	@-if exist $(TARG_EX_sink_ODS_DLL_R_W) $(RM) $(TARG_EX_sink_ODS_DLL_R_W)
	@-if exist $(OBJ_EX_sink_ODS_DLL_R_W) $(RM) $(OBJ_EX_sink_ODS_DLL_R_W)
	@-if exist example.*.pdb $(RM) example.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.*.manifest
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
	@-if exist example.*.pdb $(RM) example.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.*.manifest
	@-if exist $(TARG_EX_boolean_MT_R_W) $(RM) $(TARG_EX_boolean_MT_R_W)
	@-if exist $(OBJ_EX_boolean_MT_R_W) $(RM) $(OBJ_EX_boolean_MT_R_W)
	@-if exist $(TARG_EX_character_MT_R_W) $(RM) $(TARG_EX_character_MT_R_W)
	@-if exist $(OBJ_EX_character_MT_R_W) $(RM) $(OBJ_EX_character_MT_R_W)
	@-if exist $(TARG_EX_reals_MT_R_W) $(RM) $(TARG_EX_reals_MT_R_W)
	@-if exist $(OBJ_EX_reals_MT_R_W) $(RM) $(OBJ_EX_reals_MT_R_W)
	@-if exist $(TARG_EX_voidptrs_MT_R_W) $(RM) $(TARG_EX_voidptrs_MT_R_W)
	@-if exist $(OBJ_EX_voidptrs_MT_R_W) $(RM) $(OBJ_EX_voidptrs_MT_R_W)
	@-if exist $(TARG_EX_ff_101_MT_R_W) $(RM) $(TARG_EX_ff_101_MT_R_W)
	@-if exist $(OBJ_EX_ff_101_MT_R_W) $(RM) $(OBJ_EX_ff_101_MT_R_W)
	@-if exist $(TARG_EX_ff_101_nons_MT_R_W) $(RM) $(TARG_EX_ff_101_nons_MT_R_W)
	@-if exist $(OBJ_EX_ff_101_nons_MT_R_W) $(RM) $(OBJ_EX_ff_101_nons_MT_R_W)
	@-if exist $(TARG_EX_flush_MT_R_W) $(RM) $(TARG_EX_flush_MT_R_W)
	@-if exist $(OBJ_EX_flush_MT_R_W) $(RM) $(OBJ_EX_flush_MT_R_W)
	@-if exist $(TARG_EX_ins_hex_MT_R_W) $(RM) $(TARG_EX_ins_hex_MT_R_W)
	@-if exist $(OBJ_EX_ins_hex_MT_R_W) $(RM) $(OBJ_EX_ins_hex_MT_R_W)
	@-if exist $(TARG_EX_ins_integers_MT_R_W) $(RM) $(TARG_EX_ins_integers_MT_R_W)
	@-if exist $(OBJ_EX_ins_integers_MT_R_W) $(RM) $(OBJ_EX_ins_integers_MT_R_W)
	@-if exist $(TARG_EX_ins_WLIs_MT_R_W) $(RM) $(TARG_EX_ins_WLIs_MT_R_W)
	@-if exist $(OBJ_EX_ins_WLIs_MT_R_W) $(RM) $(OBJ_EX_ins_WLIs_MT_R_W)
	@-if exist $(TARG_EX_ins_reals_MT_R_W) $(RM) $(TARG_EX_ins_reals_MT_R_W)
	@-if exist $(OBJ_EX_ins_reals_MT_R_W) $(RM) $(OBJ_EX_ins_reals_MT_R_W)
	@-if exist $(TARG_EX_itr_fmt_MT_R_W) $(RM) $(TARG_EX_itr_fmt_MT_R_W)
	@-if exist $(OBJ_EX_itr_fmt_MT_R_W) $(RM) $(OBJ_EX_itr_fmt_MT_R_W)
	@-if exist $(TARG_EX_ovld2_filt_MT_R_W) $(RM) $(TARG_EX_ovld2_filt_MT_R_W)
	@-if exist $(OBJ_EX_ovld2_filt_MT_R_W) $(RM) $(OBJ_EX_ovld2_filt_MT_R_W)
	@-if exist $(TARG_EX_ovld2_ins_MT_R_W) $(RM) $(TARG_EX_ovld2_ins_MT_R_W)
	@-if exist $(OBJ_EX_ovld2_ins_MT_R_W) $(RM) $(OBJ_EX_ovld2_ins_MT_R_W)
	@-if exist $(TARG_EX_ovld2_sas_MT_R_W) $(RM) $(TARG_EX_ovld2_sas_MT_R_W)
	@-if exist $(OBJ_EX_ovld2_sas_MT_R_W) $(RM) $(OBJ_EX_ovld2_sas_MT_R_W)
	@-if exist $(TARG_EX_ovld3_fpcol_MT_R_W) $(RM) $(TARG_EX_ovld3_fpcol_MT_R_W)
	@-if exist $(OBJ_EX_ovld3_fpcol_MT_R_W) $(RM) $(OBJ_EX_ovld3_fpcol_MT_R_W)
	@-if exist $(TARG_EX_ovld3_tabs_MT_R_W) $(RM) $(TARG_EX_ovld3_tabs_MT_R_W)
	@-if exist $(OBJ_EX_ovld3_tabs_MT_R_W) $(RM) $(OBJ_EX_ovld3_tabs_MT_R_W)
	@-if exist $(TARG_EX_ovld3_svrlg_MT_R_W) $(RM) $(TARG_EX_ovld3_svrlg_MT_R_W)
	@-if exist $(OBJ_EX_ovld3_svrlg_MT_R_W) $(RM) $(OBJ_EX_ovld3_svrlg_MT_R_W)
	@-if exist $(TARG_EX_ovld3_rcins_MT_R_W) $(RM) $(TARG_EX_ovld3_rcins_MT_R_W)
	@-if exist $(OBJ_EX_ovld3_rcins_MT_R_W) $(RM) $(OBJ_EX_ovld3_rcins_MT_R_W)
	@-if exist $(TARG_EX_pad_hash_MT_R_W) $(RM) $(TARG_EX_pad_hash_MT_R_W)
	@-if exist $(OBJ_EX_pad_hash_MT_R_W) $(RM) $(OBJ_EX_pad_hash_MT_R_W)
	@-if exist $(TARG_EX_sink_cstr_MT_R_W) $(RM) $(TARG_EX_sink_cstr_MT_R_W)
	@-if exist $(OBJ_EX_sink_cstr_MT_R_W) $(RM) $(OBJ_EX_sink_cstr_MT_R_W)
	@-if exist $(TARG_EX_sink_ODS_MT_R_W) $(RM) $(TARG_EX_sink_ODS_MT_R_W)
	@-if exist $(OBJ_EX_sink_ODS_MT_R_W) $(RM) $(OBJ_EX_sink_ODS_MT_R_W)
	@-if exist example.*.pdb $(RM) example.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.*.manifest

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
	@-if exist test.component.*.pdb $(RM) test.component.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest
	@-if exist $(TARG_TEST_COMP_file_MT_D_W) $(RM) $(TARG_TEST_COMP_file_MT_D_W)
	@-if exist $(OBJ_TEST_COMP_file_MT_D_W) $(RM) $(OBJ_TEST_COMP_file_MT_D_W)
	@-if exist $(TARG_TEST_COMP_fmt_sink_MT_D_W) $(RM) $(TARG_TEST_COMP_fmt_sink_MT_D_W)
	@-if exist $(OBJ_TEST_COMP_fmt_sink_MT_D_W) $(RM) $(OBJ_TEST_COMP_fmt_sink_MT_D_W)
	@-if exist $(TARG_TEST_COMP_ins_hex_MT_D_W) $(RM) $(TARG_TEST_COMP_ins_hex_MT_D_W)
	@-if exist $(OBJ_TEST_COMP_ins_hex_MT_D_W) $(RM) $(OBJ_TEST_COMP_ins_hex_MT_D_W)
	@-if exist $(TARG_TEST_COMP_ins_int_MT_D_W) $(RM) $(TARG_TEST_COMP_ins_int_MT_D_W)
	@-if exist $(OBJ_TEST_COMP_ins_int_MT_D_W) $(RM) $(OBJ_TEST_COMP_ins_int_MT_D_W)
	@-if exist $(TARG_TEST_COMP_ins_real_MT_D_W) $(RM) $(TARG_TEST_COMP_ins_real_MT_D_W)
	@-if exist $(OBJ_TEST_COMP_ins_real_MT_D_W) $(RM) $(OBJ_TEST_COMP_ins_real_MT_D_W)
	@-if exist $(TARG_TEST_COMP_itr_fmt_MT_D_W) $(RM) $(TARG_TEST_COMP_ins_real_MT_D_W)
	@-if exist $(OBJ_TEST_COMP_itr_fmt_MT_D_W) $(RM) $(OBJ_TEST_COMP_ins_real_MT_D_W)
	@-if exist $(TARG_TEST_COMP_null_sink_MT_D_W) $(RM) $(TARG_TEST_COMP_null_sink_MT_D_W)
	@-if exist $(OBJ_TEST_COMP_null_sink_MT_D_W) $(RM) $(OBJ_TEST_COMP_null_sink_MT_D_W)
	@-if exist $(TARG_TEST_COMP_snk_a_b_MT_D_W) $(RM) $(TARG_TEST_COMP_snk_a_b_MT_D_W)
	@-if exist $(OBJ_TEST_COMP_snk_a_b_MT_D_W) $(RM) $(OBJ_TEST_COMP_snk_a_b_MT_D_W)
	@-if exist $(TARG_TEST_COMP_write_sink_MT_D_W) $(RM) $(TARG_TEST_COMP_write_sink_MT_D_W)
	@-if exist $(OBJ_TEST_COMP_write_sink_MT_D_W) $(RM) $(OBJ_TEST_COMP_write_sink_MT_D_W)
	@-if exist $(TARG_TEST_COMP_x_1_MT_D_W) $(RM) $(TARG_TEST_COMP_x_1_MT_D_W)
	@-if exist $(OBJ_TEST_COMP_x_1_MT_D_W) $(RM) $(OBJ_TEST_COMP_x_1_MT_D_W)
	@-if exist $(TARG_TEST_COMP_snk_ostm_MT_D_W) $(RM) $(TARG_TEST_COMP_snk_ostm_MT_D_W)
	@-if exist $(OBJ_TEST_COMP_snk_ostm_MT_D_W) $(RM) $(OBJ_TEST_COMP_snk_ostm_MT_D_W)
	@-if exist test.component.*.pdb $(RM) test.component.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest
	@-if exist $(TARG_TEST_COMP_file_DLL_D) $(RM) $(TARG_TEST_COMP_file_DLL_D)
	@-if exist $(OBJ_TEST_COMP_file_DLL_D) $(RM) $(OBJ_TEST_COMP_file_DLL_D)
	@-if exist $(TARG_TEST_COMP_fmt_sink_DLL_D) $(RM) $(TARG_TEST_COMP_fmt_sink_DLL_D)
	@-if exist $(OBJ_TEST_COMP_fmt_sink_DLL_D) $(RM) $(OBJ_TEST_COMP_fmt_sink_DLL_D)
	@-if exist $(TARG_TEST_COMP_ins_hex_DLL_D) $(RM) $(TARG_TEST_COMP_ins_hex_DLL_D)
	@-if exist $(OBJ_TEST_COMP_ins_hex_DLL_D) $(RM) $(OBJ_TEST_COMP_ins_hex_DLL_D)
	@-if exist $(TARG_TEST_COMP_ins_int_DLL_D) $(RM) $(TARG_TEST_COMP_ins_int_DLL_D)
	@-if exist $(OBJ_TEST_COMP_ins_int_DLL_D) $(RM) $(OBJ_TEST_COMP_ins_int_DLL_D)
	@-if exist $(TARG_TEST_COMP_ins_real_DLL_D) $(RM) $(TARG_TEST_COMP_ins_real_DLL_D)
	@-if exist $(OBJ_TEST_COMP_ins_real_DLL_D) $(RM) $(OBJ_TEST_COMP_ins_real_DLL_D)
	@-if exist $(TARG_TEST_COMP_itr_fmt_DLL_D) $(RM) $(TARG_TEST_COMP_ins_real_DLL_D)
	@-if exist $(OBJ_TEST_COMP_itr_fmt_DLL_D) $(RM) $(OBJ_TEST_COMP_ins_real_DLL_D)
	@-if exist $(TARG_TEST_COMP_null_sink_DLL_D) $(RM) $(TARG_TEST_COMP_null_sink_DLL_D)
	@-if exist $(OBJ_TEST_COMP_null_sink_DLL_D) $(RM) $(OBJ_TEST_COMP_null_sink_DLL_D)
	@-if exist $(TARG_TEST_COMP_snk_a_b_DLL_D) $(RM) $(TARG_TEST_COMP_snk_a_b_DLL_D)
	@-if exist $(OBJ_TEST_COMP_snk_a_b_DLL_D) $(RM) $(OBJ_TEST_COMP_snk_a_b_DLL_D)
	@-if exist $(TARG_TEST_COMP_write_sink_DLL_D) $(RM) $(TARG_TEST_COMP_write_sink_DLL_D)
	@-if exist $(OBJ_TEST_COMP_write_sink_DLL_D) $(RM) $(OBJ_TEST_COMP_write_sink_DLL_D)
	@-if exist $(TARG_TEST_COMP_x_1_DLL_D) $(RM) $(TARG_TEST_COMP_x_1_DLL_D)
	@-if exist $(OBJ_TEST_COMP_x_1_DLL_D) $(RM) $(OBJ_TEST_COMP_x_1_DLL_D)
	@-if exist $(TARG_TEST_COMP_snk_ostm_DLL_D) $(RM) $(TARG_TEST_COMP_snk_ostm_DLL_D)
	@-if exist $(OBJ_TEST_COMP_snk_ostm_DLL_D) $(RM) $(OBJ_TEST_COMP_snk_ostm_DLL_D)
	@-if exist test.component.*.pdb $(RM) test.component.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest
	@-if exist $(TARG_TEST_COMP_file_DLL_D_W) $(RM) $(TARG_TEST_COMP_file_DLL_D_W)
	@-if exist $(OBJ_TEST_COMP_file_DLL_D_W) $(RM) $(OBJ_TEST_COMP_file_DLL_D_W)
	@-if exist $(TARG_TEST_COMP_fmt_sink_DLL_D_W) $(RM) $(TARG_TEST_COMP_fmt_sink_DLL_D_W)
	@-if exist $(OBJ_TEST_COMP_fmt_sink_DLL_D_W) $(RM) $(OBJ_TEST_COMP_fmt_sink_DLL_D_W)
	@-if exist $(TARG_TEST_COMP_ins_hex_DLL_D_W) $(RM) $(TARG_TEST_COMP_ins_hex_DLL_D_W)
	@-if exist $(OBJ_TEST_COMP_ins_hex_DLL_D_W) $(RM) $(OBJ_TEST_COMP_ins_hex_DLL_D_W)
	@-if exist $(TARG_TEST_COMP_ins_int_DLL_D_W) $(RM) $(TARG_TEST_COMP_ins_int_DLL_D_W)
	@-if exist $(OBJ_TEST_COMP_ins_int_DLL_D_W) $(RM) $(OBJ_TEST_COMP_ins_int_DLL_D_W)
	@-if exist $(TARG_TEST_COMP_ins_real_DLL_D_W) $(RM) $(TARG_TEST_COMP_ins_real_DLL_D_W)
	@-if exist $(OBJ_TEST_COMP_ins_real_DLL_D_W) $(RM) $(OBJ_TEST_COMP_ins_real_DLL_D_W)
	@-if exist $(TARG_TEST_COMP_itr_fmt_DLL_D_W) $(RM) $(TARG_TEST_COMP_ins_real_DLL_D_W)
	@-if exist $(OBJ_TEST_COMP_itr_fmt_DLL_D_W) $(RM) $(OBJ_TEST_COMP_ins_real_DLL_D_W)
	@-if exist $(TARG_TEST_COMP_null_sink_DLL_D_W) $(RM) $(TARG_TEST_COMP_null_sink_DLL_D_W)
	@-if exist $(OBJ_TEST_COMP_null_sink_DLL_D_W) $(RM) $(OBJ_TEST_COMP_null_sink_DLL_D_W)
	@-if exist $(TARG_TEST_COMP_snk_a_b_DLL_D_W) $(RM) $(TARG_TEST_COMP_snk_a_b_DLL_D_W)
	@-if exist $(OBJ_TEST_COMP_snk_a_b_DLL_D_W) $(RM) $(OBJ_TEST_COMP_snk_a_b_DLL_D_W)
	@-if exist $(TARG_TEST_COMP_write_sink_DLL_D_W) $(RM) $(TARG_TEST_COMP_write_sink_DLL_D_W)
	@-if exist $(OBJ_TEST_COMP_write_sink_DLL_D_W) $(RM) $(OBJ_TEST_COMP_write_sink_DLL_D_W)
	@-if exist $(TARG_TEST_COMP_x_1_DLL_D_W) $(RM) $(TARG_TEST_COMP_x_1_DLL_D_W)
	@-if exist $(OBJ_TEST_COMP_x_1_DLL_D_W) $(RM) $(OBJ_TEST_COMP_x_1_DLL_D_W)
	@-if exist $(TARG_TEST_COMP_snk_ostm_DLL_D_W) $(RM) $(TARG_TEST_COMP_snk_ostm_DLL_D_W)
	@-if exist $(OBJ_TEST_COMP_snk_ostm_DLL_D_W) $(RM) $(OBJ_TEST_COMP_snk_ostm_DLL_D_W)
	@-if exist test.component.*.pdb $(RM) test.component.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest
	@-if exist $(TARG_TEST_COMP_file_DLL_R) $(RM) $(TARG_TEST_COMP_file_DLL_R)
	@-if exist $(OBJ_TEST_COMP_file_DLL_R) $(RM) $(OBJ_TEST_COMP_file_DLL_R)
	@-if exist $(TARG_TEST_COMP_fmt_sink_DLL_R) $(RM) $(TARG_TEST_COMP_fmt_sink_DLL_R)
	@-if exist $(OBJ_TEST_COMP_fmt_sink_DLL_R) $(RM) $(OBJ_TEST_COMP_fmt_sink_DLL_R)
	@-if exist $(TARG_TEST_COMP_ins_hex_DLL_R) $(RM) $(TARG_TEST_COMP_ins_hex_DLL_R)
	@-if exist $(OBJ_TEST_COMP_ins_hex_DLL_R) $(RM) $(OBJ_TEST_COMP_ins_hex_DLL_R)
	@-if exist $(TARG_TEST_COMP_ins_int_DLL_R) $(RM) $(TARG_TEST_COMP_ins_int_DLL_R)
	@-if exist $(OBJ_TEST_COMP_ins_int_DLL_R) $(RM) $(OBJ_TEST_COMP_ins_int_DLL_R)
	@-if exist $(TARG_TEST_COMP_ins_real_DLL_R) $(RM) $(TARG_TEST_COMP_ins_real_DLL_R)
	@-if exist $(OBJ_TEST_COMP_ins_real_DLL_R) $(RM) $(OBJ_TEST_COMP_ins_real_DLL_R)
	@-if exist $(TARG_TEST_COMP_itr_fmt_DLL_R) $(RM) $(TARG_TEST_COMP_ins_real_DLL_R)
	@-if exist $(OBJ_TEST_COMP_itr_fmt_DLL_R) $(RM) $(OBJ_TEST_COMP_ins_real_DLL_R)
	@-if exist $(TARG_TEST_COMP_null_sink_DLL_R) $(RM) $(TARG_TEST_COMP_null_sink_DLL_R)
	@-if exist $(OBJ_TEST_COMP_null_sink_DLL_R) $(RM) $(OBJ_TEST_COMP_null_sink_DLL_R)
	@-if exist $(TARG_TEST_COMP_snk_a_b_DLL_R) $(RM) $(TARG_TEST_COMP_snk_a_b_DLL_R)
	@-if exist $(OBJ_TEST_COMP_snk_a_b_DLL_R) $(RM) $(OBJ_TEST_COMP_snk_a_b_DLL_R)
	@-if exist $(TARG_TEST_COMP_write_sink_DLL_R) $(RM) $(TARG_TEST_COMP_write_sink_DLL_R)
	@-if exist $(OBJ_TEST_COMP_write_sink_DLL_R) $(RM) $(OBJ_TEST_COMP_write_sink_DLL_R)
	@-if exist $(TARG_TEST_COMP_x_1_DLL_R) $(RM) $(TARG_TEST_COMP_x_1_DLL_R)
	@-if exist $(OBJ_TEST_COMP_x_1_DLL_R) $(RM) $(OBJ_TEST_COMP_x_1_DLL_R)
	@-if exist $(TARG_TEST_COMP_snk_ostm_DLL_R) $(RM) $(TARG_TEST_COMP_snk_ostm_DLL_R)
	@-if exist $(OBJ_TEST_COMP_snk_ostm_DLL_R) $(RM) $(OBJ_TEST_COMP_snk_ostm_DLL_R)
	@-if exist test.component.*.pdb $(RM) test.component.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest
	@-if exist $(TARG_TEST_COMP_file_DLL_R_W) $(RM) $(TARG_TEST_COMP_file_DLL_R_W)
	@-if exist $(OBJ_TEST_COMP_file_DLL_R_W) $(RM) $(OBJ_TEST_COMP_file_DLL_R_W)
	@-if exist $(TARG_TEST_COMP_fmt_sink_DLL_R_W) $(RM) $(TARG_TEST_COMP_fmt_sink_DLL_R_W)
	@-if exist $(OBJ_TEST_COMP_fmt_sink_DLL_R_W) $(RM) $(OBJ_TEST_COMP_fmt_sink_DLL_R_W)
	@-if exist $(TARG_TEST_COMP_ins_hex_DLL_R_W) $(RM) $(TARG_TEST_COMP_ins_hex_DLL_R_W)
	@-if exist $(OBJ_TEST_COMP_ins_hex_DLL_R_W) $(RM) $(OBJ_TEST_COMP_ins_hex_DLL_R_W)
	@-if exist $(TARG_TEST_COMP_ins_int_DLL_R_W) $(RM) $(TARG_TEST_COMP_ins_int_DLL_R_W)
	@-if exist $(OBJ_TEST_COMP_ins_int_DLL_R_W) $(RM) $(OBJ_TEST_COMP_ins_int_DLL_R_W)
	@-if exist $(TARG_TEST_COMP_ins_real_DLL_R_W) $(RM) $(TARG_TEST_COMP_ins_real_DLL_R_W)
	@-if exist $(OBJ_TEST_COMP_ins_real_DLL_R_W) $(RM) $(OBJ_TEST_COMP_ins_real_DLL_R_W)
	@-if exist $(TARG_TEST_COMP_itr_fmt_DLL_R_W) $(RM) $(TARG_TEST_COMP_ins_real_DLL_R_W)
	@-if exist $(OBJ_TEST_COMP_itr_fmt_DLL_R_W) $(RM) $(OBJ_TEST_COMP_ins_real_DLL_R_W)
	@-if exist $(TARG_TEST_COMP_null_sink_DLL_R_W) $(RM) $(TARG_TEST_COMP_null_sink_DLL_R_W)
	@-if exist $(OBJ_TEST_COMP_null_sink_DLL_R_W) $(RM) $(OBJ_TEST_COMP_null_sink_DLL_R_W)
	@-if exist $(TARG_TEST_COMP_snk_a_b_DLL_R_W) $(RM) $(TARG_TEST_COMP_snk_a_b_DLL_R_W)
	@-if exist $(OBJ_TEST_COMP_snk_a_b_DLL_R_W) $(RM) $(OBJ_TEST_COMP_snk_a_b_DLL_R_W)
	@-if exist $(TARG_TEST_COMP_write_sink_DLL_R_W) $(RM) $(TARG_TEST_COMP_write_sink_DLL_R_W)
	@-if exist $(OBJ_TEST_COMP_write_sink_DLL_R_W) $(RM) $(OBJ_TEST_COMP_write_sink_DLL_R_W)
	@-if exist $(TARG_TEST_COMP_x_1_DLL_R_W) $(RM) $(TARG_TEST_COMP_x_1_DLL_R_W)
	@-if exist $(OBJ_TEST_COMP_x_1_DLL_R_W) $(RM) $(OBJ_TEST_COMP_x_1_DLL_R_W)
	@-if exist $(TARG_TEST_COMP_snk_ostm_DLL_R_W) $(RM) $(TARG_TEST_COMP_snk_ostm_DLL_R_W)
	@-if exist $(OBJ_TEST_COMP_snk_ostm_DLL_R_W) $(RM) $(OBJ_TEST_COMP_snk_ostm_DLL_R_W)
	@-if exist test.component.*.pdb $(RM) test.component.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest
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
	@-if exist test.component.*.pdb $(RM) test.component.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest
	@-if exist $(TARG_TEST_COMP_file_MT_R_W) $(RM) $(TARG_TEST_COMP_file_MT_R_W)
	@-if exist $(OBJ_TEST_COMP_file_MT_R_W) $(RM) $(OBJ_TEST_COMP_file_MT_R_W)
	@-if exist $(TARG_TEST_COMP_fmt_sink_MT_R_W) $(RM) $(TARG_TEST_COMP_fmt_sink_MT_R_W)
	@-if exist $(OBJ_TEST_COMP_fmt_sink_MT_R_W) $(RM) $(OBJ_TEST_COMP_fmt_sink_MT_R_W)
	@-if exist $(TARG_TEST_COMP_ins_hex_MT_R_W) $(RM) $(TARG_TEST_COMP_ins_hex_MT_R_W)
	@-if exist $(OBJ_TEST_COMP_ins_hex_MT_R_W) $(RM) $(OBJ_TEST_COMP_ins_hex_MT_R_W)
	@-if exist $(TARG_TEST_COMP_ins_int_MT_R_W) $(RM) $(TARG_TEST_COMP_ins_int_MT_R_W)
	@-if exist $(OBJ_TEST_COMP_ins_int_MT_R_W) $(RM) $(OBJ_TEST_COMP_ins_int_MT_R_W)
	@-if exist $(TARG_TEST_COMP_ins_real_MT_R_W) $(RM) $(TARG_TEST_COMP_ins_real_MT_R_W)
	@-if exist $(OBJ_TEST_COMP_ins_real_MT_R_W) $(RM) $(OBJ_TEST_COMP_ins_real_MT_R_W)
	@-if exist $(TARG_TEST_COMP_itr_fmt_MT_R_W) $(RM) $(TARG_TEST_COMP_ins_real_MT_R_W)
	@-if exist $(OBJ_TEST_COMP_itr_fmt_MT_R_W) $(RM) $(OBJ_TEST_COMP_ins_real_MT_R_W)
	@-if exist $(TARG_TEST_COMP_null_sink_MT_R_W) $(RM) $(TARG_TEST_COMP_null_sink_MT_R_W)
	@-if exist $(OBJ_TEST_COMP_null_sink_MT_R_W) $(RM) $(OBJ_TEST_COMP_null_sink_MT_R_W)
	@-if exist $(TARG_TEST_COMP_snk_a_b_MT_R_W) $(RM) $(TARG_TEST_COMP_snk_a_b_MT_R_W)
	@-if exist $(OBJ_TEST_COMP_snk_a_b_MT_R_W) $(RM) $(OBJ_TEST_COMP_snk_a_b_MT_R_W)
	@-if exist $(TARG_TEST_COMP_write_sink_MT_R_W) $(RM) $(TARG_TEST_COMP_write_sink_MT_R_W)
	@-if exist $(OBJ_TEST_COMP_write_sink_MT_R_W) $(RM) $(OBJ_TEST_COMP_write_sink_MT_R_W)
	@-if exist $(TARG_TEST_COMP_x_1_MT_R_W) $(RM) $(TARG_TEST_COMP_x_1_MT_R_W)
	@-if exist $(OBJ_TEST_COMP_x_1_MT_R_W) $(RM) $(OBJ_TEST_COMP_x_1_MT_R_W)
	@-if exist $(TARG_TEST_COMP_snk_ostm_MT_R_W) $(RM) $(TARG_TEST_COMP_snk_ostm_MT_R_W)
	@-if exist $(OBJ_TEST_COMP_snk_ostm_MT_R_W) $(RM) $(OBJ_TEST_COMP_snk_ostm_MT_R_W)
	@-if exist test.component.*.pdb $(RM) test.component.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest

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
!ifdef BOOST
	@-if exist $(TARG_TEST_PERF_scen8_MT_D) $(RM) $(TARG_TEST_PERF_scen8_MT_D)
	@-if exist $(OBJ_TEST_PERF_scen8_MT_D) $(RM) $(OBJ_TEST_PERF_scen8_MT_D)
!endif # BOOST
	@-if exist test.performance.*.pdb $(RM) test.performance.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.*.manifest
	@-if exist $(TARG_TEST_PERF_scen1_MT_D_W) $(RM) $(TARG_TEST_PERF_scen1_MT_D_W)
	@-if exist $(OBJ_TEST_PERF_scen1_MT_D_W) $(RM) $(OBJ_TEST_PERF_scen1_MT_D_W)
	@-if exist $(TARG_TEST_PERF_scen2_MT_D_W) $(RM) $(TARG_TEST_PERF_scen2_MT_D_W)
	@-if exist $(OBJ_TEST_PERF_scen2_MT_D_W) $(RM) $(OBJ_TEST_PERF_scen2_MT_D_W)
	@-if exist $(TARG_TEST_PERF_scen3_MT_D_W) $(RM) $(TARG_TEST_PERF_scen3_MT_D_W)
	@-if exist $(OBJ_TEST_PERF_scen3_MT_D_W) $(RM) $(OBJ_TEST_PERF_scen3_MT_D_W)
	@-if exist $(TARG_TEST_PERF_scen4_MT_D_W) $(RM) $(TARG_TEST_PERF_scen4_MT_D_W)
	@-if exist $(OBJ_TEST_PERF_scen4_MT_D_W) $(RM) $(OBJ_TEST_PERF_scen4_MT_D_W)
	@-if exist $(TARG_TEST_PERF_scen5_MT_D_W) $(RM) $(TARG_TEST_PERF_scen5_MT_D_W)
	@-if exist $(OBJ_TEST_PERF_scen5_MT_D_W) $(RM) $(OBJ_TEST_PERF_scen5_MT_D_W)
	@-if exist $(TARG_TEST_PERF_scen6_MT_D_W) $(RM) $(TARG_TEST_PERF_scen6_MT_D_W)
	@-if exist $(OBJ_TEST_PERF_scen6_MT_D_W) $(RM) $(OBJ_TEST_PERF_scen6_MT_D_W)
	@-if exist $(TARG_TEST_PERF_scen7_MT_D_W) $(RM) $(TARG_TEST_PERF_scen7_MT_D_W)
	@-if exist $(OBJ_TEST_PERF_scen7_MT_D_W) $(RM) $(OBJ_TEST_PERF_scen7_MT_D_W)
!ifdef BOOST
	@-if exist $(TARG_TEST_PERF_scen8_MT_D_W) $(RM) $(TARG_TEST_PERF_scen8_MT_D_W)
	@-if exist $(OBJ_TEST_PERF_scen8_MT_D_W) $(RM) $(OBJ_TEST_PERF_scen8_MT_D_W)
!endif # BOOST
	@-if exist test.performance.*.pdb $(RM) test.performance.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.*.manifest
	@-if exist $(TARG_TEST_PERF_scen1_DLL_D) $(RM) $(TARG_TEST_PERF_scen1_DLL_D)
	@-if exist $(OBJ_TEST_PERF_scen1_DLL_D) $(RM) $(OBJ_TEST_PERF_scen1_DLL_D)
	@-if exist $(TARG_TEST_PERF_scen2_DLL_D) $(RM) $(TARG_TEST_PERF_scen2_DLL_D)
	@-if exist $(OBJ_TEST_PERF_scen2_DLL_D) $(RM) $(OBJ_TEST_PERF_scen2_DLL_D)
	@-if exist $(TARG_TEST_PERF_scen3_DLL_D) $(RM) $(TARG_TEST_PERF_scen3_DLL_D)
	@-if exist $(OBJ_TEST_PERF_scen3_DLL_D) $(RM) $(OBJ_TEST_PERF_scen3_DLL_D)
	@-if exist $(TARG_TEST_PERF_scen4_DLL_D) $(RM) $(TARG_TEST_PERF_scen4_DLL_D)
	@-if exist $(OBJ_TEST_PERF_scen4_DLL_D) $(RM) $(OBJ_TEST_PERF_scen4_DLL_D)
	@-if exist $(TARG_TEST_PERF_scen5_DLL_D) $(RM) $(TARG_TEST_PERF_scen5_DLL_D)
	@-if exist $(OBJ_TEST_PERF_scen5_DLL_D) $(RM) $(OBJ_TEST_PERF_scen5_DLL_D)
	@-if exist $(TARG_TEST_PERF_scen6_DLL_D) $(RM) $(TARG_TEST_PERF_scen6_DLL_D)
	@-if exist $(OBJ_TEST_PERF_scen6_DLL_D) $(RM) $(OBJ_TEST_PERF_scen6_DLL_D)
	@-if exist $(TARG_TEST_PERF_scen7_DLL_D) $(RM) $(TARG_TEST_PERF_scen7_DLL_D)
	@-if exist $(OBJ_TEST_PERF_scen7_DLL_D) $(RM) $(OBJ_TEST_PERF_scen7_DLL_D)
!ifdef BOOST
	@-if exist $(TARG_TEST_PERF_scen8_DLL_D) $(RM) $(TARG_TEST_PERF_scen8_DLL_D)
	@-if exist $(OBJ_TEST_PERF_scen8_DLL_D) $(RM) $(OBJ_TEST_PERF_scen8_DLL_D)
!endif # BOOST
	@-if exist test.performance.*.pdb $(RM) test.performance.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.*.manifest
	@-if exist $(TARG_TEST_PERF_scen1_DLL_D_W) $(RM) $(TARG_TEST_PERF_scen1_DLL_D_W)
	@-if exist $(OBJ_TEST_PERF_scen1_DLL_D_W) $(RM) $(OBJ_TEST_PERF_scen1_DLL_D_W)
	@-if exist $(TARG_TEST_PERF_scen2_DLL_D_W) $(RM) $(TARG_TEST_PERF_scen2_DLL_D_W)
	@-if exist $(OBJ_TEST_PERF_scen2_DLL_D_W) $(RM) $(OBJ_TEST_PERF_scen2_DLL_D_W)
	@-if exist $(TARG_TEST_PERF_scen3_DLL_D_W) $(RM) $(TARG_TEST_PERF_scen3_DLL_D_W)
	@-if exist $(OBJ_TEST_PERF_scen3_DLL_D_W) $(RM) $(OBJ_TEST_PERF_scen3_DLL_D_W)
	@-if exist $(TARG_TEST_PERF_scen4_DLL_D_W) $(RM) $(TARG_TEST_PERF_scen4_DLL_D_W)
	@-if exist $(OBJ_TEST_PERF_scen4_DLL_D_W) $(RM) $(OBJ_TEST_PERF_scen4_DLL_D_W)
	@-if exist $(TARG_TEST_PERF_scen5_DLL_D_W) $(RM) $(TARG_TEST_PERF_scen5_DLL_D_W)
	@-if exist $(OBJ_TEST_PERF_scen5_DLL_D_W) $(RM) $(OBJ_TEST_PERF_scen5_DLL_D_W)
	@-if exist $(TARG_TEST_PERF_scen6_DLL_D_W) $(RM) $(TARG_TEST_PERF_scen6_DLL_D_W)
	@-if exist $(OBJ_TEST_PERF_scen6_DLL_D_W) $(RM) $(OBJ_TEST_PERF_scen6_DLL_D_W)
	@-if exist $(TARG_TEST_PERF_scen7_DLL_D_W) $(RM) $(TARG_TEST_PERF_scen7_DLL_D_W)
	@-if exist $(OBJ_TEST_PERF_scen7_DLL_D_W) $(RM) $(OBJ_TEST_PERF_scen7_DLL_D_W)
!ifdef BOOST
	@-if exist $(TARG_TEST_PERF_scen8_DLL_D_W) $(RM) $(TARG_TEST_PERF_scen8_DLL_D_W)
	@-if exist $(OBJ_TEST_PERF_scen8_DLL_D_W) $(RM) $(OBJ_TEST_PERF_scen8_DLL_D_W)
!endif # BOOST
	@-if exist test.performance.*.pdb $(RM) test.performance.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.*.manifest
	@-if exist $(TARG_TEST_PERF_scen1_DLL_R) $(RM) $(TARG_TEST_PERF_scen1_DLL_R)
	@-if exist $(OBJ_TEST_PERF_scen1_DLL_R) $(RM) $(OBJ_TEST_PERF_scen1_DLL_R)
	@-if exist $(TARG_TEST_PERF_scen2_DLL_R) $(RM) $(TARG_TEST_PERF_scen2_DLL_R)
	@-if exist $(OBJ_TEST_PERF_scen2_DLL_R) $(RM) $(OBJ_TEST_PERF_scen2_DLL_R)
	@-if exist $(TARG_TEST_PERF_scen3_DLL_R) $(RM) $(TARG_TEST_PERF_scen3_DLL_R)
	@-if exist $(OBJ_TEST_PERF_scen3_DLL_R) $(RM) $(OBJ_TEST_PERF_scen3_DLL_R)
	@-if exist $(TARG_TEST_PERF_scen4_DLL_R) $(RM) $(TARG_TEST_PERF_scen4_DLL_R)
	@-if exist $(OBJ_TEST_PERF_scen4_DLL_R) $(RM) $(OBJ_TEST_PERF_scen4_DLL_R)
	@-if exist $(TARG_TEST_PERF_scen5_DLL_R) $(RM) $(TARG_TEST_PERF_scen5_DLL_R)
	@-if exist $(OBJ_TEST_PERF_scen5_DLL_R) $(RM) $(OBJ_TEST_PERF_scen5_DLL_R)
	@-if exist $(TARG_TEST_PERF_scen6_DLL_R) $(RM) $(TARG_TEST_PERF_scen6_DLL_R)
	@-if exist $(OBJ_TEST_PERF_scen6_DLL_R) $(RM) $(OBJ_TEST_PERF_scen6_DLL_R)
	@-if exist $(TARG_TEST_PERF_scen7_DLL_R) $(RM) $(TARG_TEST_PERF_scen7_DLL_R)
	@-if exist $(OBJ_TEST_PERF_scen7_DLL_R) $(RM) $(OBJ_TEST_PERF_scen7_DLL_R)
!ifdef BOOST
	@-if exist $(TARG_TEST_PERF_scen8_DLL_R) $(RM) $(TARG_TEST_PERF_scen8_DLL_R)
	@-if exist $(OBJ_TEST_PERF_scen8_DLL_R) $(RM) $(OBJ_TEST_PERF_scen8_DLL_R)
!endif # BOOST
	@-if exist test.performance.*.pdb $(RM) test.performance.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.*.manifest
	@-if exist $(TARG_TEST_PERF_scen1_DLL_R_W) $(RM) $(TARG_TEST_PERF_scen1_DLL_R_W)
	@-if exist $(OBJ_TEST_PERF_scen1_DLL_R_W) $(RM) $(OBJ_TEST_PERF_scen1_DLL_R_W)
	@-if exist $(TARG_TEST_PERF_scen2_DLL_R_W) $(RM) $(TARG_TEST_PERF_scen2_DLL_R_W)
	@-if exist $(OBJ_TEST_PERF_scen2_DLL_R_W) $(RM) $(OBJ_TEST_PERF_scen2_DLL_R_W)
	@-if exist $(TARG_TEST_PERF_scen3_DLL_R_W) $(RM) $(TARG_TEST_PERF_scen3_DLL_R_W)
	@-if exist $(OBJ_TEST_PERF_scen3_DLL_R_W) $(RM) $(OBJ_TEST_PERF_scen3_DLL_R_W)
	@-if exist $(TARG_TEST_PERF_scen4_DLL_R_W) $(RM) $(TARG_TEST_PERF_scen4_DLL_R_W)
	@-if exist $(OBJ_TEST_PERF_scen4_DLL_R_W) $(RM) $(OBJ_TEST_PERF_scen4_DLL_R_W)
	@-if exist $(TARG_TEST_PERF_scen5_DLL_R_W) $(RM) $(TARG_TEST_PERF_scen5_DLL_R_W)
	@-if exist $(OBJ_TEST_PERF_scen5_DLL_R_W) $(RM) $(OBJ_TEST_PERF_scen5_DLL_R_W)
	@-if exist $(TARG_TEST_PERF_scen6_DLL_R_W) $(RM) $(TARG_TEST_PERF_scen6_DLL_R_W)
	@-if exist $(OBJ_TEST_PERF_scen6_DLL_R_W) $(RM) $(OBJ_TEST_PERF_scen6_DLL_R_W)
	@-if exist $(TARG_TEST_PERF_scen7_DLL_R_W) $(RM) $(TARG_TEST_PERF_scen7_DLL_R_W)
	@-if exist $(OBJ_TEST_PERF_scen7_DLL_R_W) $(RM) $(OBJ_TEST_PERF_scen7_DLL_R_W)
!ifdef BOOST
	@-if exist $(TARG_TEST_PERF_scen8_DLL_R_W) $(RM) $(TARG_TEST_PERF_scen8_DLL_R_W)
	@-if exist $(OBJ_TEST_PERF_scen8_DLL_R_W) $(RM) $(OBJ_TEST_PERF_scen8_DLL_R_W)
!endif # BOOST
	@-if exist test.performance.*.pdb $(RM) test.performance.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.*.manifest
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
!ifdef BOOST
	@-if exist $(TARG_TEST_PERF_scen8_MT_R) $(RM) $(TARG_TEST_PERF_scen8_MT_R)
	@-if exist $(OBJ_TEST_PERF_scen8_MT_R) $(RM) $(OBJ_TEST_PERF_scen8_MT_R)
!endif # BOOST
	@-if exist test.performance.*.pdb $(RM) test.performance.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.*.manifest
	@-if exist $(TARG_TEST_PERF_scen1_MT_R_W) $(RM) $(TARG_TEST_PERF_scen1_MT_R_W)
	@-if exist $(OBJ_TEST_PERF_scen1_MT_R_W) $(RM) $(OBJ_TEST_PERF_scen1_MT_R_W)
	@-if exist $(TARG_TEST_PERF_scen2_MT_R_W) $(RM) $(TARG_TEST_PERF_scen2_MT_R_W)
	@-if exist $(OBJ_TEST_PERF_scen2_MT_R_W) $(RM) $(OBJ_TEST_PERF_scen2_MT_R_W)
	@-if exist $(TARG_TEST_PERF_scen3_MT_R_W) $(RM) $(TARG_TEST_PERF_scen3_MT_R_W)
	@-if exist $(OBJ_TEST_PERF_scen3_MT_R_W) $(RM) $(OBJ_TEST_PERF_scen3_MT_R_W)
	@-if exist $(TARG_TEST_PERF_scen4_MT_R_W) $(RM) $(TARG_TEST_PERF_scen4_MT_R_W)
	@-if exist $(OBJ_TEST_PERF_scen4_MT_R_W) $(RM) $(OBJ_TEST_PERF_scen4_MT_R_W)
	@-if exist $(TARG_TEST_PERF_scen5_MT_R_W) $(RM) $(TARG_TEST_PERF_scen5_MT_R_W)
	@-if exist $(OBJ_TEST_PERF_scen5_MT_R_W) $(RM) $(OBJ_TEST_PERF_scen5_MT_R_W)
	@-if exist $(TARG_TEST_PERF_scen6_MT_R_W) $(RM) $(TARG_TEST_PERF_scen6_MT_R_W)
	@-if exist $(OBJ_TEST_PERF_scen6_MT_R_W) $(RM) $(OBJ_TEST_PERF_scen6_MT_R_W)
	@-if exist $(TARG_TEST_PERF_scen7_MT_R_W) $(RM) $(TARG_TEST_PERF_scen7_MT_R_W)
	@-if exist $(OBJ_TEST_PERF_scen7_MT_R_W) $(RM) $(OBJ_TEST_PERF_scen7_MT_R_W)
!ifdef BOOST
	@-if exist $(TARG_TEST_PERF_scen8_MT_R_W) $(RM) $(TARG_TEST_PERF_scen8_MT_R_W)
	@-if exist $(OBJ_TEST_PERF_scen8_MT_R_W) $(RM) $(OBJ_TEST_PERF_scen8_MT_R_W)
!endif # BOOST
	@-if exist test.performance.*.pdb $(RM) test.performance.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.*.manifest

clean.test.scratch:
	@echo cleaning Test::Scratch files ...
	@-if exist $(TARG_TEST_SCRT_file_MT_D) $(RM) $(TARG_TEST_SCRT_file_MT_D)
	@-if exist $(OBJ_TEST_SCRT_file_MT_D) $(RM) $(OBJ_TEST_SCRT_file_MT_D)
	@-if exist $(PDB_TEST_SCRT_file_MT_D) $(RM) $(PDB_TEST_SCRT_file_MT_D)
	@-if exist $(TARG_TEST_SCRT_speech_MT_D) $(RM) $(TARG_TEST_SCRT_speech_MT_D)
	@-if exist $(OBJ_TEST_SCRT_speech_MT_D) $(RM) $(OBJ_TEST_SCRT_speech_MT_D)
	@-if exist $(PDB_TEST_SCRT_speech_MT_D) $(RM) $(PDB_TEST_SCRT_speech_MT_D)
	@-if exist $(TARG_TEST_SCRT_file_MT_D_W) $(RM) $(TARG_TEST_SCRT_file_MT_D_W)
	@-if exist $(OBJ_TEST_SCRT_file_MT_D_W) $(RM) $(OBJ_TEST_SCRT_file_MT_D_W)
	@-if exist $(PDB_TEST_SCRT_file_MT_D_W) $(RM) $(PDB_TEST_SCRT_file_MT_D_W)
	@-if exist $(TARG_TEST_SCRT_speech_MT_D_W) $(RM) $(TARG_TEST_SCRT_speech_MT_D_W)
	@-if exist $(OBJ_TEST_SCRT_speech_MT_D_W) $(RM) $(OBJ_TEST_SCRT_speech_MT_D_W)
	@-if exist $(PDB_TEST_SCRT_speech_MT_D_W) $(RM) $(PDB_TEST_SCRT_speech_MT_D_W)
	@-if exist $(TARG_TEST_SCRT_file_DLL_D) $(RM) $(TARG_TEST_SCRT_file_DLL_D)
	@-if exist $(OBJ_TEST_SCRT_file_DLL_D) $(RM) $(OBJ_TEST_SCRT_file_DLL_D)
	@-if exist $(PDB_TEST_SCRT_file_DLL_D) $(RM) $(PDB_TEST_SCRT_file_DLL_D)
	@-if exist $(TARG_TEST_SCRT_speech_DLL_D) $(RM) $(TARG_TEST_SCRT_speech_DLL_D)
	@-if exist $(OBJ_TEST_SCRT_speech_DLL_D) $(RM) $(OBJ_TEST_SCRT_speech_DLL_D)
	@-if exist $(PDB_TEST_SCRT_speech_DLL_D) $(RM) $(PDB_TEST_SCRT_speech_DLL_D)
	@-if exist $(TARG_TEST_SCRT_file_DLL_D_W) $(RM) $(TARG_TEST_SCRT_file_DLL_D_W)
	@-if exist $(OBJ_TEST_SCRT_file_DLL_D_W) $(RM) $(OBJ_TEST_SCRT_file_DLL_D_W)
	@-if exist $(PDB_TEST_SCRT_file_DLL_D_W) $(RM) $(PDB_TEST_SCRT_file_DLL_D_W)
	@-if exist $(TARG_TEST_SCRT_speech_DLL_D_W) $(RM) $(TARG_TEST_SCRT_speech_DLL_D_W)
	@-if exist $(OBJ_TEST_SCRT_speech_DLL_D_W) $(RM) $(OBJ_TEST_SCRT_speech_DLL_D_W)
	@-if exist $(PDB_TEST_SCRT_speech_DLL_D_W) $(RM) $(PDB_TEST_SCRT_speech_DLL_D_W)
	@-if exist $(TARG_TEST_SCRT_file_DLL_R) $(RM) $(TARG_TEST_SCRT_file_DLL_R)
	@-if exist $(OBJ_TEST_SCRT_file_DLL_R) $(RM) $(OBJ_TEST_SCRT_file_DLL_R)
	@-if exist $(TARG_TEST_SCRT_speech_DLL_R) $(RM) $(TARG_TEST_SCRT_speech_DLL_R)
	@-if exist $(OBJ_TEST_SCRT_speech_DLL_R) $(RM) $(OBJ_TEST_SCRT_speech_DLL_R)
	@-if exist $(TARG_TEST_SCRT_file_DLL_R_W) $(RM) $(TARG_TEST_SCRT_file_DLL_R_W)
	@-if exist $(OBJ_TEST_SCRT_file_DLL_R_W) $(RM) $(OBJ_TEST_SCRT_file_DLL_R_W)
	@-if exist $(TARG_TEST_SCRT_speech_DLL_R_W) $(RM) $(TARG_TEST_SCRT_speech_DLL_R_W)
	@-if exist $(OBJ_TEST_SCRT_speech_DLL_R_W) $(RM) $(OBJ_TEST_SCRT_speech_DLL_R_W)
	@-if exist $(TARG_TEST_SCRT_file_MT_R) $(RM) $(TARG_TEST_SCRT_file_MT_R)
	@-if exist $(OBJ_TEST_SCRT_file_MT_R) $(RM) $(OBJ_TEST_SCRT_file_MT_R)
	@-if exist $(TARG_TEST_SCRT_speech_MT_R) $(RM) $(TARG_TEST_SCRT_speech_MT_R)
	@-if exist $(OBJ_TEST_SCRT_speech_MT_R) $(RM) $(OBJ_TEST_SCRT_speech_MT_R)
	@-if exist $(TARG_TEST_SCRT_file_MT_R_W) $(RM) $(TARG_TEST_SCRT_file_MT_R_W)
	@-if exist $(OBJ_TEST_SCRT_file_MT_R_W) $(RM) $(OBJ_TEST_SCRT_file_MT_R_W)
	@-if exist $(TARG_TEST_SCRT_speech_MT_R_W) $(RM) $(TARG_TEST_SCRT_speech_MT_R_W)
	@-if exist $(OBJ_TEST_SCRT_speech_MT_R_W) $(RM) $(OBJ_TEST_SCRT_speech_MT_R_W)

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
	@-if exist $(TARG_TEST_UNIT_ins_ss_MT_D) $(RM) $(TARG_TEST_UNIT_ins_ch_MT_D)
	@-if exist $(OBJ_TEST_UNIT_ins_ss_MT_D) $(RM) $(OBJ_TEST_UNIT_ins_ch_MT_D)
	@-if exist $(TARG_TEST_UNIT_shim_fi_MT_D) $(RM) $(TARG_TEST_UNIT_shim_fi_MT_D)
	@-if exist $(OBJ_TEST_UNIT_shim_fi_MT_D) $(RM) $(OBJ_TEST_UNIT_shim_fi_MT_D)
	@-if exist $(TARG_TEST_UNIT_shim_ns_MT_D) $(RM) $(TARG_TEST_UNIT_shim_ns_MT_D)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_1_MT_D) $(RM) $(OBJ_TEST_UNIT_shim_ns_1_MT_D)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_2_MT_D) $(RM) $(OBJ_TEST_UNIT_shim_ns_2_MT_D)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_3_MT_D) $(RM) $(OBJ_TEST_UNIT_shim_ns_3_MT_D)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_4_MT_D) $(RM) $(OBJ_TEST_UNIT_shim_ns_4_MT_D)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_5_MT_D) $(RM) $(OBJ_TEST_UNIT_shim_ns_5_MT_D)
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
	@-if exist test.unit.*.pdb $(RM) test.unit.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest
	@-if exist $(TARG_TEST_UNIT_api_acsllen_MT_D_W) $(RM) $(TARG_TEST_UNIT_api_acsllen_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_api_acsllen_MT_D_W) $(RM) $(OBJ_TEST_UNIT_api_acsllen_MT_D_W)
	@-if exist $(TARG_TEST_UNIT_api_crlf_MT_D_W) $(RM) $(TARG_TEST_UNIT_api_crlf_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_api_crlf_MT_D_W) $(RM) $(OBJ_TEST_UNIT_api_crlf_MT_D_W)
	@-if exist $(TARG_TEST_UNIT_api_flrpl_MT_D_W) $(RM) $(TARG_TEST_UNIT_api_flrpl_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_api_flrpl_MT_D_W) $(RM) $(OBJ_TEST_UNIT_api_flrpl_MT_D_W)
	@-if exist $(TARG_TEST_UNIT_api_init_MT_D_W) $(RM) $(TARG_TEST_UNIT_api_init_MT_D_W)
	@-if exist $(TARG_TEST_UNIT_api_illfmdh_MT_D_W) $(RM) $(TARG_TEST_UNIT_api_illfmdh_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_api_illfmdh_MT_D_W) $(RM) $(OBJ_TEST_UNIT_api_illfmdh_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_api_init_MT_D_W) $(RM) $(OBJ_TEST_UNIT_api_init_MT_D_W)
	@-if exist $(TARG_TEST_UNIT_api_lkptrn_MT_D_W) $(RM) $(TARG_TEST_UNIT_api_lkptrn_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_api_lkptrn_MT_D_W) $(RM) $(OBJ_TEST_UNIT_api_lkptrn_MT_D_W)
	@-if exist $(TARG_TEST_UNIT_api_msmtchh_MT_D_W) $(RM) $(TARG_TEST_UNIT_api_msmtchh_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_api_msmtchh_MT_D_W) $(RM) $(OBJ_TEST_UNIT_api_msmtchh_MT_D_W)
	@-if exist $(TARG_TEST_UNIT_api_prsrpl_MT_D_W) $(RM) $(TARG_TEST_UNIT_api_prsrpl_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_api_prsrpl_MT_D_W) $(RM) $(OBJ_TEST_UNIT_api_prsrpl_MT_D_W)
	@-if exist $(TARG_TEST_UNIT_bndl_winini_MT_D_W) $(RM) $(TARG_TEST_UNIT_bndl_winini_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_bndl_winini_MT_D_W) $(RM) $(OBJ_TEST_UNIT_bndl_winini_MT_D_W)
	@-if exist $(TARG_TEST_UNIT_fmt_stdfl_MT_D_W) $(RM) $(TARG_TEST_UNIT_fmt_stdfl_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_fmt_stdfl_MT_D_W) $(RM) $(OBJ_TEST_UNIT_fmt_stdfl_MT_D_W)
	@-if exist $(TARG_TEST_UNIT_snk_ods_MT_D_W) $(RM) $(TARG_TEST_UNIT_snk_ods_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_snk_ods_MT_D_W) $(RM) $(OBJ_TEST_UNIT_snk_ods_MT_D_W)
	@-if exist $(TARG_TEST_UNIT_ins_ch_MT_D_W) $(RM) $(TARG_TEST_UNIT_ins_ch_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_ins_ch_MT_D_W) $(RM) $(OBJ_TEST_UNIT_ins_ch_MT_D_W)
	@-if exist $(TARG_TEST_UNIT_ins_i_MT_D_W) $(RM) $(TARG_TEST_UNIT_ins_i_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_ins_i_MT_D_W) $(RM) $(OBJ_TEST_UNIT_ins_i_MT_D_W)
	@-if exist $(TARG_TEST_UNIT_ins_ss_MT_D_W) $(RM) $(TARG_TEST_UNIT_ins_ch_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_ins_ss_MT_D_W) $(RM) $(OBJ_TEST_UNIT_ins_ch_MT_D_W)
	@-if exist $(TARG_TEST_UNIT_shim_fi_MT_D_W) $(RM) $(TARG_TEST_UNIT_shim_fi_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_shim_fi_MT_D_W) $(RM) $(OBJ_TEST_UNIT_shim_fi_MT_D_W)
	@-if exist $(TARG_TEST_UNIT_shim_ns_MT_D_W) $(RM) $(TARG_TEST_UNIT_shim_ns_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_1_MT_D_W) $(RM) $(OBJ_TEST_UNIT_shim_ns_1_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_2_MT_D_W) $(RM) $(OBJ_TEST_UNIT_shim_ns_2_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_3_MT_D_W) $(RM) $(OBJ_TEST_UNIT_shim_ns_3_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_4_MT_D_W) $(RM) $(OBJ_TEST_UNIT_shim_ns_4_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_5_MT_D_W) $(RM) $(OBJ_TEST_UNIT_shim_ns_5_MT_D_W)
	@-if exist $(TARG_TEST_UNIT_snk_a_b_MT_D_W) $(RM) $(TARG_TEST_UNIT_snk_a_b_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_snk_a_b_MT_D_W) $(RM) $(OBJ_TEST_UNIT_snk_a_b_MT_D_W)
	@-if exist $(TARG_TEST_UNIT_snk_c_str_MT_D_W) $(RM) $(TARG_TEST_UNIT_snk_c_str_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_snk_c_str_MT_D_W) $(RM) $(OBJ_TEST_UNIT_snk_c_str_MT_D_W)
	@-if exist $(TARG_TEST_UNIT_snk_chbuf_MT_D_W) $(RM) $(TARG_TEST_UNIT_snk_chbuf_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_snk_chbuf_MT_D_W) $(RM) $(OBJ_TEST_UNIT_snk_chbuf_MT_D_W)
	@-if exist $(TARG_TEST_UNIT_snk_null_MT_D_W) $(RM) $(TARG_TEST_UNIT_snk_null_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_snk_null_MT_D_W) $(RM) $(OBJ_TEST_UNIT_snk_null_MT_D_W)
	@-if exist $(TARG_TEST_UNIT_snk_ostm_MT_D_W) $(RM) $(TARG_TEST_UNIT_snk_ostm_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_snk_ostm_MT_D_W) $(RM) $(OBJ_TEST_UNIT_snk_ostm_MT_D_W)
	@-if exist $(TARG_TEST_UNIT_snk_sstm_MT_D_W) $(RM) $(TARG_TEST_UNIT_snk_sstm_MT_D_W)
	@-if exist $(OBJ_TEST_UNIT_snk_sstm_MT_D_W) $(RM) $(OBJ_TEST_UNIT_snk_sstm_MT_D_W)
	@-if exist test.unit.*.pdb $(RM) test.unit.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest
	@-if exist $(TARG_TEST_UNIT_api_acsllen_DLL_D) $(RM) $(TARG_TEST_UNIT_api_acsllen_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_api_acsllen_DLL_D) $(RM) $(OBJ_TEST_UNIT_api_acsllen_DLL_D)
	@-if exist $(TARG_TEST_UNIT_api_crlf_DLL_D) $(RM) $(TARG_TEST_UNIT_api_crlf_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_api_crlf_DLL_D) $(RM) $(OBJ_TEST_UNIT_api_crlf_DLL_D)
	@-if exist $(TARG_TEST_UNIT_api_flrpl_DLL_D) $(RM) $(TARG_TEST_UNIT_api_flrpl_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_api_flrpl_DLL_D) $(RM) $(OBJ_TEST_UNIT_api_flrpl_DLL_D)
	@-if exist $(TARG_TEST_UNIT_api_init_DLL_D) $(RM) $(TARG_TEST_UNIT_api_init_DLL_D)
	@-if exist $(TARG_TEST_UNIT_api_illfmdh_DLL_D) $(RM) $(TARG_TEST_UNIT_api_illfmdh_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_api_illfmdh_DLL_D) $(RM) $(OBJ_TEST_UNIT_api_illfmdh_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_api_init_DLL_D) $(RM) $(OBJ_TEST_UNIT_api_init_DLL_D)
	@-if exist $(TARG_TEST_UNIT_api_lkptrn_DLL_D) $(RM) $(TARG_TEST_UNIT_api_lkptrn_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_api_lkptrn_DLL_D) $(RM) $(OBJ_TEST_UNIT_api_lkptrn_DLL_D)
	@-if exist $(TARG_TEST_UNIT_api_msmtchh_DLL_D) $(RM) $(TARG_TEST_UNIT_api_msmtchh_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_api_msmtchh_DLL_D) $(RM) $(OBJ_TEST_UNIT_api_msmtchh_DLL_D)
	@-if exist $(TARG_TEST_UNIT_api_prsrpl_DLL_D) $(RM) $(TARG_TEST_UNIT_api_prsrpl_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_api_prsrpl_DLL_D) $(RM) $(OBJ_TEST_UNIT_api_prsrpl_DLL_D)
	@-if exist $(TARG_TEST_UNIT_bndl_winini_DLL_D) $(RM) $(TARG_TEST_UNIT_bndl_winini_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_bndl_winini_DLL_D) $(RM) $(OBJ_TEST_UNIT_bndl_winini_DLL_D)
	@-if exist $(TARG_TEST_UNIT_fmt_stdfl_DLL_D) $(RM) $(TARG_TEST_UNIT_fmt_stdfl_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_fmt_stdfl_DLL_D) $(RM) $(OBJ_TEST_UNIT_fmt_stdfl_DLL_D)
	@-if exist $(TARG_TEST_UNIT_snk_ods_DLL_D) $(RM) $(TARG_TEST_UNIT_snk_ods_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_snk_ods_DLL_D) $(RM) $(OBJ_TEST_UNIT_snk_ods_DLL_D)
	@-if exist $(TARG_TEST_UNIT_ins_ch_DLL_D) $(RM) $(TARG_TEST_UNIT_ins_ch_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_ins_ch_DLL_D) $(RM) $(OBJ_TEST_UNIT_ins_ch_DLL_D)
	@-if exist $(TARG_TEST_UNIT_ins_i_DLL_D) $(RM) $(TARG_TEST_UNIT_ins_i_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_ins_i_DLL_D) $(RM) $(OBJ_TEST_UNIT_ins_i_DLL_D)
	@-if exist $(TARG_TEST_UNIT_ins_ss_DLL_D) $(RM) $(TARG_TEST_UNIT_ins_ch_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_ins_ss_DLL_D) $(RM) $(OBJ_TEST_UNIT_ins_ch_DLL_D)
	@-if exist $(TARG_TEST_UNIT_shim_fi_DLL_D) $(RM) $(TARG_TEST_UNIT_shim_fi_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_shim_fi_DLL_D) $(RM) $(OBJ_TEST_UNIT_shim_fi_DLL_D)
	@-if exist $(TARG_TEST_UNIT_shim_ns_DLL_D) $(RM) $(TARG_TEST_UNIT_shim_ns_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_1_DLL_D) $(RM) $(OBJ_TEST_UNIT_shim_ns_1_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_2_DLL_D) $(RM) $(OBJ_TEST_UNIT_shim_ns_2_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_3_DLL_D) $(RM) $(OBJ_TEST_UNIT_shim_ns_3_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_4_DLL_D) $(RM) $(OBJ_TEST_UNIT_shim_ns_4_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_5_DLL_D) $(RM) $(OBJ_TEST_UNIT_shim_ns_5_DLL_D)
	@-if exist $(TARG_TEST_UNIT_snk_a_b_DLL_D) $(RM) $(TARG_TEST_UNIT_snk_a_b_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_snk_a_b_DLL_D) $(RM) $(OBJ_TEST_UNIT_snk_a_b_DLL_D)
	@-if exist $(TARG_TEST_UNIT_snk_c_str_DLL_D) $(RM) $(TARG_TEST_UNIT_snk_c_str_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_snk_c_str_DLL_D) $(RM) $(OBJ_TEST_UNIT_snk_c_str_DLL_D)
	@-if exist $(TARG_TEST_UNIT_snk_chbuf_DLL_D) $(RM) $(TARG_TEST_UNIT_snk_chbuf_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_snk_chbuf_DLL_D) $(RM) $(OBJ_TEST_UNIT_snk_chbuf_DLL_D)
	@-if exist $(TARG_TEST_UNIT_snk_mfccstr_DLL_D) $(RM) $(TARG_TEST_UNIT_snk_mfccstr_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_snk_mfccstr_DLL_D) $(RM) $(OBJ_TEST_UNIT_snk_mfccstr_DLL_D)
	@-if exist $(TARG_TEST_UNIT_snk_null_DLL_D) $(RM) $(TARG_TEST_UNIT_snk_null_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_snk_null_DLL_D) $(RM) $(OBJ_TEST_UNIT_snk_null_DLL_D)
	@-if exist $(TARG_TEST_UNIT_snk_ostm_DLL_D) $(RM) $(TARG_TEST_UNIT_snk_ostm_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_snk_ostm_DLL_D) $(RM) $(OBJ_TEST_UNIT_snk_ostm_DLL_D)
	@-if exist $(TARG_TEST_UNIT_snk_sstm_DLL_D) $(RM) $(TARG_TEST_UNIT_snk_sstm_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_snk_sstm_DLL_D) $(RM) $(OBJ_TEST_UNIT_snk_sstm_DLL_D)
	@-if exist test.unit.*.pdb $(RM) test.unit.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest
	@-if exist $(TARG_TEST_UNIT_api_acsllen_DLL_D_W) $(RM) $(TARG_TEST_UNIT_api_acsllen_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_api_acsllen_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_api_acsllen_DLL_D_W)
	@-if exist $(TARG_TEST_UNIT_api_crlf_DLL_D_W) $(RM) $(TARG_TEST_UNIT_api_crlf_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_api_crlf_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_api_crlf_DLL_D_W)
	@-if exist $(TARG_TEST_UNIT_api_flrpl_DLL_D_W) $(RM) $(TARG_TEST_UNIT_api_flrpl_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_api_flrpl_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_api_flrpl_DLL_D_W)
	@-if exist $(TARG_TEST_UNIT_api_init_DLL_D_W) $(RM) $(TARG_TEST_UNIT_api_init_DLL_D_W)
	@-if exist $(TARG_TEST_UNIT_api_illfmdh_DLL_D_W) $(RM) $(TARG_TEST_UNIT_api_illfmdh_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_api_illfmdh_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_api_illfmdh_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_api_init_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_api_init_DLL_D_W)
	@-if exist $(TARG_TEST_UNIT_api_lkptrn_DLL_D_W) $(RM) $(TARG_TEST_UNIT_api_lkptrn_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_api_lkptrn_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_api_lkptrn_DLL_D_W)
	@-if exist $(TARG_TEST_UNIT_api_msmtchh_DLL_D_W) $(RM) $(TARG_TEST_UNIT_api_msmtchh_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_api_msmtchh_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_api_msmtchh_DLL_D_W)
	@-if exist $(TARG_TEST_UNIT_api_prsrpl_DLL_D_W) $(RM) $(TARG_TEST_UNIT_api_prsrpl_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_api_prsrpl_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_api_prsrpl_DLL_D_W)
	@-if exist $(TARG_TEST_UNIT_bndl_winini_DLL_D_W) $(RM) $(TARG_TEST_UNIT_bndl_winini_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_bndl_winini_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_bndl_winini_DLL_D_W)
	@-if exist $(TARG_TEST_UNIT_fmt_stdfl_DLL_D_W) $(RM) $(TARG_TEST_UNIT_fmt_stdfl_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_fmt_stdfl_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_fmt_stdfl_DLL_D_W)
	@-if exist $(TARG_TEST_UNIT_snk_ods_DLL_D_W) $(RM) $(TARG_TEST_UNIT_snk_ods_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_snk_ods_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_snk_ods_DLL_D_W)
	@-if exist $(TARG_TEST_UNIT_ins_ch_DLL_D_W) $(RM) $(TARG_TEST_UNIT_ins_ch_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_ins_ch_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_ins_ch_DLL_D_W)
	@-if exist $(TARG_TEST_UNIT_ins_i_DLL_D_W) $(RM) $(TARG_TEST_UNIT_ins_i_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_ins_i_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_ins_i_DLL_D_W)
	@-if exist $(TARG_TEST_UNIT_ins_ss_DLL_D_W) $(RM) $(TARG_TEST_UNIT_ins_ch_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_ins_ss_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_ins_ch_DLL_D_W)
	@-if exist $(TARG_TEST_UNIT_shim_fi_DLL_D_W) $(RM) $(TARG_TEST_UNIT_shim_fi_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_shim_fi_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_shim_fi_DLL_D_W)
	@-if exist $(TARG_TEST_UNIT_shim_ns_DLL_D_W) $(RM) $(TARG_TEST_UNIT_shim_ns_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_1_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_shim_ns_1_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_2_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_shim_ns_2_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_3_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_shim_ns_3_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_4_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_shim_ns_4_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_5_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_shim_ns_5_DLL_D_W)
	@-if exist $(TARG_TEST_UNIT_snk_a_b_DLL_D_W) $(RM) $(TARG_TEST_UNIT_snk_a_b_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_snk_a_b_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_snk_a_b_DLL_D_W)
	@-if exist $(TARG_TEST_UNIT_snk_c_str_DLL_D_W) $(RM) $(TARG_TEST_UNIT_snk_c_str_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_snk_c_str_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_snk_c_str_DLL_D_W)
	@-if exist $(TARG_TEST_UNIT_snk_chbuf_DLL_D_W) $(RM) $(TARG_TEST_UNIT_snk_chbuf_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_snk_chbuf_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_snk_chbuf_DLL_D_W)
	@-if exist $(TARG_TEST_UNIT_snk_mfccstr_DLL_D_W) $(RM) $(TARG_TEST_UNIT_snk_mfccstr_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_snk_mfccstr_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_snk_mfccstr_DLL_D_W)
	@-if exist $(TARG_TEST_UNIT_snk_null_DLL_D_W) $(RM) $(TARG_TEST_UNIT_snk_null_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_snk_null_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_snk_null_DLL_D_W)
	@-if exist $(TARG_TEST_UNIT_snk_ostm_DLL_D_W) $(RM) $(TARG_TEST_UNIT_snk_ostm_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_snk_ostm_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_snk_ostm_DLL_D_W)
	@-if exist $(TARG_TEST_UNIT_snk_sstm_DLL_D_W) $(RM) $(TARG_TEST_UNIT_snk_sstm_DLL_D_W)
	@-if exist $(OBJ_TEST_UNIT_snk_sstm_DLL_D_W) $(RM) $(OBJ_TEST_UNIT_snk_sstm_DLL_D_W)
	@-if exist test.unit.*.pdb $(RM) test.unit.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest
	@-if exist $(TARG_TEST_UNIT_api_acsllen_DLL_R) $(RM) $(TARG_TEST_UNIT_api_acsllen_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_api_acsllen_DLL_R) $(RM) $(OBJ_TEST_UNIT_api_acsllen_DLL_R)
	@-if exist $(TARG_TEST_UNIT_api_crlf_DLL_R) $(RM) $(TARG_TEST_UNIT_api_crlf_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_api_crlf_DLL_R) $(RM) $(OBJ_TEST_UNIT_api_crlf_DLL_R)
	@-if exist $(TARG_TEST_UNIT_api_flrpl_DLL_R) $(RM) $(TARG_TEST_UNIT_api_flrpl_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_api_flrpl_DLL_R) $(RM) $(OBJ_TEST_UNIT_api_flrpl_DLL_R)
	@-if exist $(TARG_TEST_UNIT_api_init_DLL_R) $(RM) $(TARG_TEST_UNIT_api_init_DLL_R)
	@-if exist $(TARG_TEST_UNIT_api_illfmdh_DLL_R) $(RM) $(TARG_TEST_UNIT_api_illfmdh_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_api_illfmdh_DLL_R) $(RM) $(OBJ_TEST_UNIT_api_illfmdh_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_api_init_DLL_R) $(RM) $(OBJ_TEST_UNIT_api_init_DLL_R)
	@-if exist $(TARG_TEST_UNIT_api_lkptrn_DLL_R) $(RM) $(TARG_TEST_UNIT_api_lkptrn_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_api_lkptrn_DLL_R) $(RM) $(OBJ_TEST_UNIT_api_lkptrn_DLL_R)
	@-if exist $(TARG_TEST_UNIT_api_msmtchh_DLL_R) $(RM) $(TARG_TEST_UNIT_api_msmtchh_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_api_msmtchh_DLL_R) $(RM) $(OBJ_TEST_UNIT_api_msmtchh_DLL_R)
	@-if exist $(TARG_TEST_UNIT_api_prsrpl_DLL_R) $(RM) $(TARG_TEST_UNIT_api_prsrpl_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_api_prsrpl_DLL_R) $(RM) $(OBJ_TEST_UNIT_api_prsrpl_DLL_R)
	@-if exist $(TARG_TEST_UNIT_bndl_winini_DLL_R) $(RM) $(TARG_TEST_UNIT_bndl_winini_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_bndl_winini_DLL_R) $(RM) $(OBJ_TEST_UNIT_bndl_winini_DLL_R)
	@-if exist $(TARG_TEST_UNIT_fmt_stdfl_DLL_R) $(RM) $(TARG_TEST_UNIT_fmt_stdfl_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_fmt_stdfl_DLL_R) $(RM) $(OBJ_TEST_UNIT_fmt_stdfl_DLL_R)
	@-if exist $(TARG_TEST_UNIT_snk_ods_DLL_R) $(RM) $(TARG_TEST_UNIT_snk_ods_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_snk_ods_DLL_R) $(RM) $(OBJ_TEST_UNIT_snk_ods_DLL_R)
	@-if exist $(TARG_TEST_UNIT_ins_ch_DLL_R) $(RM) $(TARG_TEST_UNIT_ins_ch_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_ins_ch_DLL_R) $(RM) $(OBJ_TEST_UNIT_ins_ch_DLL_R)
	@-if exist $(TARG_TEST_UNIT_ins_i_DLL_R) $(RM) $(TARG_TEST_UNIT_ins_i_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_ins_i_DLL_R) $(RM) $(OBJ_TEST_UNIT_ins_i_DLL_R)
	@-if exist $(TARG_TEST_UNIT_ins_ss_DLL_R) $(RM) $(TARG_TEST_UNIT_ins_ch_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_ins_ss_DLL_R) $(RM) $(OBJ_TEST_UNIT_ins_ch_DLL_R)
	@-if exist $(TARG_TEST_UNIT_shim_fi_DLL_R) $(RM) $(TARG_TEST_UNIT_shim_fi_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_shim_fi_DLL_R) $(RM) $(OBJ_TEST_UNIT_shim_fi_DLL_R)
	@-if exist $(TARG_TEST_UNIT_shim_ns_DLL_R) $(RM) $(TARG_TEST_UNIT_shim_ns_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_1_DLL_R) $(RM) $(OBJ_TEST_UNIT_shim_ns_1_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_2_DLL_R) $(RM) $(OBJ_TEST_UNIT_shim_ns_2_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_3_DLL_R) $(RM) $(OBJ_TEST_UNIT_shim_ns_3_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_4_DLL_R) $(RM) $(OBJ_TEST_UNIT_shim_ns_4_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_5_DLL_R) $(RM) $(OBJ_TEST_UNIT_shim_ns_5_DLL_R)
	@-if exist $(TARG_TEST_UNIT_snk_a_b_DLL_R) $(RM) $(TARG_TEST_UNIT_snk_a_b_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_snk_a_b_DLL_R) $(RM) $(OBJ_TEST_UNIT_snk_a_b_DLL_R)
	@-if exist $(TARG_TEST_UNIT_snk_c_str_DLL_R) $(RM) $(TARG_TEST_UNIT_snk_c_str_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_snk_c_str_DLL_R) $(RM) $(OBJ_TEST_UNIT_snk_c_str_DLL_R)
	@-if exist $(TARG_TEST_UNIT_snk_chbuf_DLL_R) $(RM) $(TARG_TEST_UNIT_snk_chbuf_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_snk_chbuf_DLL_R) $(RM) $(OBJ_TEST_UNIT_snk_chbuf_DLL_R)
	@-if exist $(TARG_TEST_UNIT_snk_mfccstr_DLL_R) $(RM) $(TARG_TEST_UNIT_snk_mfccstr_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_snk_mfccstr_DLL_R) $(RM) $(OBJ_TEST_UNIT_snk_mfccstr_DLL_R)
	@-if exist $(TARG_TEST_UNIT_snk_null_DLL_R) $(RM) $(TARG_TEST_UNIT_snk_null_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_snk_null_DLL_R) $(RM) $(OBJ_TEST_UNIT_snk_null_DLL_R)
	@-if exist $(TARG_TEST_UNIT_snk_ostm_DLL_R) $(RM) $(TARG_TEST_UNIT_snk_ostm_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_snk_ostm_DLL_R) $(RM) $(OBJ_TEST_UNIT_snk_ostm_DLL_R)
	@-if exist $(TARG_TEST_UNIT_snk_sstm_DLL_R) $(RM) $(TARG_TEST_UNIT_snk_sstm_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_snk_sstm_DLL_R) $(RM) $(OBJ_TEST_UNIT_snk_sstm_DLL_R)
	@-if exist test.unit.*.pdb $(RM) test.unit.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest
	@-if exist $(TARG_TEST_UNIT_api_acsllen_DLL_R_W) $(RM) $(TARG_TEST_UNIT_api_acsllen_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_api_acsllen_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_api_acsllen_DLL_R_W)
	@-if exist $(TARG_TEST_UNIT_api_crlf_DLL_R_W) $(RM) $(TARG_TEST_UNIT_api_crlf_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_api_crlf_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_api_crlf_DLL_R_W)
	@-if exist $(TARG_TEST_UNIT_api_flrpl_DLL_R_W) $(RM) $(TARG_TEST_UNIT_api_flrpl_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_api_flrpl_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_api_flrpl_DLL_R_W)
	@-if exist $(TARG_TEST_UNIT_api_init_DLL_R_W) $(RM) $(TARG_TEST_UNIT_api_init_DLL_R_W)
	@-if exist $(TARG_TEST_UNIT_api_illfmdh_DLL_R_W) $(RM) $(TARG_TEST_UNIT_api_illfmdh_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_api_illfmdh_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_api_illfmdh_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_api_init_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_api_init_DLL_R_W)
	@-if exist $(TARG_TEST_UNIT_api_lkptrn_DLL_R_W) $(RM) $(TARG_TEST_UNIT_api_lkptrn_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_api_lkptrn_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_api_lkptrn_DLL_R_W)
	@-if exist $(TARG_TEST_UNIT_api_msmtchh_DLL_R_W) $(RM) $(TARG_TEST_UNIT_api_msmtchh_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_api_msmtchh_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_api_msmtchh_DLL_R_W)
	@-if exist $(TARG_TEST_UNIT_api_prsrpl_DLL_R_W) $(RM) $(TARG_TEST_UNIT_api_prsrpl_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_api_prsrpl_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_api_prsrpl_DLL_R_W)
	@-if exist $(TARG_TEST_UNIT_bndl_winini_DLL_R_W) $(RM) $(TARG_TEST_UNIT_bndl_winini_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_bndl_winini_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_bndl_winini_DLL_R_W)
	@-if exist $(TARG_TEST_UNIT_fmt_stdfl_DLL_R_W) $(RM) $(TARG_TEST_UNIT_fmt_stdfl_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_fmt_stdfl_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_fmt_stdfl_DLL_R_W)
	@-if exist $(TARG_TEST_UNIT_snk_ods_DLL_R_W) $(RM) $(TARG_TEST_UNIT_snk_ods_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_snk_ods_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_snk_ods_DLL_R_W)
	@-if exist $(TARG_TEST_UNIT_ins_ch_DLL_R_W) $(RM) $(TARG_TEST_UNIT_ins_ch_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_ins_ch_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_ins_ch_DLL_R_W)
	@-if exist $(TARG_TEST_UNIT_ins_i_DLL_R_W) $(RM) $(TARG_TEST_UNIT_ins_i_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_ins_i_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_ins_i_DLL_R_W)
	@-if exist $(TARG_TEST_UNIT_ins_ss_DLL_R_W) $(RM) $(TARG_TEST_UNIT_ins_ch_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_ins_ss_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_ins_ch_DLL_R_W)
	@-if exist $(TARG_TEST_UNIT_shim_fi_DLL_R_W) $(RM) $(TARG_TEST_UNIT_shim_fi_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_shim_fi_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_shim_fi_DLL_R_W)
	@-if exist $(TARG_TEST_UNIT_shim_ns_DLL_R_W) $(RM) $(TARG_TEST_UNIT_shim_ns_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_1_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_shim_ns_1_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_2_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_shim_ns_2_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_3_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_shim_ns_3_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_4_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_shim_ns_4_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_5_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_shim_ns_5_DLL_R_W)
	@-if exist $(TARG_TEST_UNIT_snk_a_b_DLL_R_W) $(RM) $(TARG_TEST_UNIT_snk_a_b_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_snk_a_b_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_snk_a_b_DLL_R_W)
	@-if exist $(TARG_TEST_UNIT_snk_c_str_DLL_R_W) $(RM) $(TARG_TEST_UNIT_snk_c_str_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_snk_c_str_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_snk_c_str_DLL_R_W)
	@-if exist $(TARG_TEST_UNIT_snk_chbuf_DLL_R_W) $(RM) $(TARG_TEST_UNIT_snk_chbuf_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_snk_chbuf_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_snk_chbuf_DLL_R_W)
	@-if exist $(TARG_TEST_UNIT_snk_mfccstr_DLL_R_W) $(RM) $(TARG_TEST_UNIT_snk_mfccstr_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_snk_mfccstr_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_snk_mfccstr_DLL_R_W)
	@-if exist $(TARG_TEST_UNIT_snk_null_DLL_R_W) $(RM) $(TARG_TEST_UNIT_snk_null_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_snk_null_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_snk_null_DLL_R_W)
	@-if exist $(TARG_TEST_UNIT_snk_ostm_DLL_R_W) $(RM) $(TARG_TEST_UNIT_snk_ostm_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_snk_ostm_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_snk_ostm_DLL_R_W)
	@-if exist $(TARG_TEST_UNIT_snk_sstm_DLL_R_W) $(RM) $(TARG_TEST_UNIT_snk_sstm_DLL_R_W)
	@-if exist $(OBJ_TEST_UNIT_snk_sstm_DLL_R_W) $(RM) $(OBJ_TEST_UNIT_snk_sstm_DLL_R_W)
	@-if exist test.unit.*.pdb $(RM) test.unit.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest
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
	@-if exist $(TARG_TEST_UNIT_ins_ss_MT_R) $(RM) $(TARG_TEST_UNIT_ins_ch_MT_R)
	@-if exist $(OBJ_TEST_UNIT_ins_ss_MT_R) $(RM) $(OBJ_TEST_UNIT_ins_ch_MT_R)
	@-if exist $(TARG_TEST_UNIT_shim_fi_MT_R) $(RM) $(TARG_TEST_UNIT_shim_fi_MT_R)
	@-if exist $(OBJ_TEST_UNIT_shim_fi_MT_R) $(RM) $(OBJ_TEST_UNIT_shim_fi_MT_R)
	@-if exist $(TARG_TEST_UNIT_shim_ns_MT_R) $(RM) $(TARG_TEST_UNIT_shim_ns_MT_R)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_1_MT_R) $(RM) $(OBJ_TEST_UNIT_shim_ns_1_MT_R)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_2_MT_R) $(RM) $(OBJ_TEST_UNIT_shim_ns_2_MT_R)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_3_MT_R) $(RM) $(OBJ_TEST_UNIT_shim_ns_3_MT_R)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_4_MT_R) $(RM) $(OBJ_TEST_UNIT_shim_ns_4_MT_R)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_5_MT_R) $(RM) $(OBJ_TEST_UNIT_shim_ns_5_MT_R)
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
	@-if exist test.unit.*.pdb $(RM) test.unit.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest
	@-if exist $(TARG_TEST_UNIT_api_acsllen_MT_R_W) $(RM) $(TARG_TEST_UNIT_api_acsllen_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_api_acsllen_MT_R_W) $(RM) $(OBJ_TEST_UNIT_api_acsllen_MT_R_W)
	@-if exist $(TARG_TEST_UNIT_api_crlf_MT_R_W) $(RM) $(TARG_TEST_UNIT_api_crlf_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_api_crlf_MT_R_W) $(RM) $(OBJ_TEST_UNIT_api_crlf_MT_R_W)
	@-if exist $(TARG_TEST_UNIT_api_flrpl_MT_R_W) $(RM) $(TARG_TEST_UNIT_api_flrpl_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_api_flrpl_MT_R_W) $(RM) $(OBJ_TEST_UNIT_api_flrpl_MT_R_W)
	@-if exist $(TARG_TEST_UNIT_api_init_MT_R_W) $(RM) $(TARG_TEST_UNIT_api_init_MT_R_W)
	@-if exist $(TARG_TEST_UNIT_api_illfmdh_MT_R_W) $(RM) $(TARG_TEST_UNIT_api_illfmdh_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_api_illfmdh_MT_R_W) $(RM) $(OBJ_TEST_UNIT_api_illfmdh_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_api_init_MT_R_W) $(RM) $(OBJ_TEST_UNIT_api_init_MT_R_W)
	@-if exist $(TARG_TEST_UNIT_api_lkptrn_MT_R_W) $(RM) $(TARG_TEST_UNIT_api_lkptrn_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_api_lkptrn_MT_R_W) $(RM) $(OBJ_TEST_UNIT_api_lkptrn_MT_R_W)
	@-if exist $(TARG_TEST_UNIT_api_msmtchh_MT_R_W) $(RM) $(TARG_TEST_UNIT_api_msmtchh_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_api_msmtchh_MT_R_W) $(RM) $(OBJ_TEST_UNIT_api_msmtchh_MT_R_W)
	@-if exist $(TARG_TEST_UNIT_api_prsrpl_MT_R_W) $(RM) $(TARG_TEST_UNIT_api_prsrpl_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_api_prsrpl_MT_R_W) $(RM) $(OBJ_TEST_UNIT_api_prsrpl_MT_R_W)
	@-if exist $(TARG_TEST_UNIT_bndl_winini_MT_R_W) $(RM) $(TARG_TEST_UNIT_bndl_winini_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_bndl_winini_MT_R_W) $(RM) $(OBJ_TEST_UNIT_bndl_winini_MT_R_W)
	@-if exist $(TARG_TEST_UNIT_fmt_stdfl_MT_R_W) $(RM) $(TARG_TEST_UNIT_fmt_stdfl_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_fmt_stdfl_MT_R_W) $(RM) $(OBJ_TEST_UNIT_fmt_stdfl_MT_R_W)
	@-if exist $(TARG_TEST_UNIT_snk_ods_MT_R_W) $(RM) $(TARG_TEST_UNIT_snk_ods_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_snk_ods_MT_R_W) $(RM) $(OBJ_TEST_UNIT_snk_ods_MT_R_W)
	@-if exist $(TARG_TEST_UNIT_ins_ch_MT_R_W) $(RM) $(TARG_TEST_UNIT_ins_ch_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_ins_ch_MT_R_W) $(RM) $(OBJ_TEST_UNIT_ins_ch_MT_R_W)
	@-if exist $(TARG_TEST_UNIT_ins_i_MT_R_W) $(RM) $(TARG_TEST_UNIT_ins_i_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_ins_i_MT_R_W) $(RM) $(OBJ_TEST_UNIT_ins_i_MT_R_W)
	@-if exist $(TARG_TEST_UNIT_ins_ss_MT_R_W) $(RM) $(TARG_TEST_UNIT_ins_ch_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_ins_ss_MT_R_W) $(RM) $(OBJ_TEST_UNIT_ins_ch_MT_R_W)
	@-if exist $(TARG_TEST_UNIT_shim_fi_MT_R_W) $(RM) $(TARG_TEST_UNIT_shim_fi_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_shim_fi_MT_R_W) $(RM) $(OBJ_TEST_UNIT_shim_fi_MT_R_W)
	@-if exist $(TARG_TEST_UNIT_shim_ns_MT_R_W) $(RM) $(TARG_TEST_UNIT_shim_ns_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_1_MT_R_W) $(RM) $(OBJ_TEST_UNIT_shim_ns_1_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_2_MT_R_W) $(RM) $(OBJ_TEST_UNIT_shim_ns_2_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_3_MT_R_W) $(RM) $(OBJ_TEST_UNIT_shim_ns_3_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_4_MT_R_W) $(RM) $(OBJ_TEST_UNIT_shim_ns_4_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_shim_ns_5_MT_R_W) $(RM) $(OBJ_TEST_UNIT_shim_ns_5_MT_R_W)
	@-if exist $(TARG_TEST_UNIT_snk_a_b_MT_R_W) $(RM) $(TARG_TEST_UNIT_snk_a_b_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_snk_a_b_MT_R_W) $(RM) $(OBJ_TEST_UNIT_snk_a_b_MT_R_W)
	@-if exist $(TARG_TEST_UNIT_snk_c_str_MT_R_W) $(RM) $(TARG_TEST_UNIT_snk_c_str_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_snk_c_str_MT_R_W) $(RM) $(OBJ_TEST_UNIT_snk_c_str_MT_R_W)
	@-if exist $(TARG_TEST_UNIT_snk_chbuf_MT_R_W) $(RM) $(TARG_TEST_UNIT_snk_chbuf_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_snk_chbuf_MT_R_W) $(RM) $(OBJ_TEST_UNIT_snk_chbuf_MT_R_W)
	@-if exist $(TARG_TEST_UNIT_snk_null_MT_R_W) $(RM) $(TARG_TEST_UNIT_snk_null_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_snk_null_MT_R_W) $(RM) $(OBJ_TEST_UNIT_snk_null_MT_R_W)
	@-if exist $(TARG_TEST_UNIT_snk_ostm_MT_R_W) $(RM) $(TARG_TEST_UNIT_snk_ostm_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_snk_ostm_MT_R_W) $(RM) $(OBJ_TEST_UNIT_snk_ostm_MT_R_W)
	@-if exist $(TARG_TEST_UNIT_snk_sstm_MT_R_W) $(RM) $(TARG_TEST_UNIT_snk_sstm_MT_R_W)
	@-if exist $(OBJ_TEST_UNIT_snk_sstm_MT_R_W) $(RM) $(OBJ_TEST_UNIT_snk_sstm_MT_R_W)
	@-if exist test.unit.*.pdb $(RM) test.unit.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest

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
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_MT_D)

$(OBJ_cr_api_MT_D): $(PROJ_SRC_DIR)\api.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.cpp
$(OBJ_cr_enumstr_MT_D): $(PROJ_SRC_DIR)\enum_strings.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\enum_strings.cpp
$(OBJ_cr_fsdhndlrs_MT_D): $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp
$(OBJ_cr_fmtcache_MT_D): $(PROJ_SRC_DIR)\fmt_cache.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\fmt_cache.cpp
$(OBJ_cr_initstr_MT_D): $(PROJ_SRC_DIR)\init_code_strings.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\init_code_strings.cpp
$(OBJ_cr_mempool_MT_D): $(PROJ_SRC_DIR)\memory_pool.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\memory_pool.cpp
$(OBJ_cr_replacements_MT_D): $(PROJ_SRC_DIR)\replacements.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\replacements.cpp
$(OBJ_cr_snprintf_MT_D): $(PROJ_SRC_DIR)\snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\snprintf.cpp

$(LIB_CORE_MT_D_W): $(OBJ_CORE_MT_D_W) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_MT_D_W)

$(OBJ_cr_api_MT_D_W): $(PROJ_SRC_DIR)\api.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D_W) -Fo$@ $(PROJ_SRC_DIR)\api.cpp
$(OBJ_cr_enumstr_MT_D_W): $(PROJ_SRC_DIR)\enum_strings.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D_W) -Fo$@ $(PROJ_SRC_DIR)\enum_strings.cpp
$(OBJ_cr_fsdhndlrs_MT_D_W): $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D_W) -Fo$@ $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp
$(OBJ_cr_fmtcache_MT_D_W): $(PROJ_SRC_DIR)\fmt_cache.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D_W) -Fo$@ $(PROJ_SRC_DIR)\fmt_cache.cpp
$(OBJ_cr_initstr_MT_D_W): $(PROJ_SRC_DIR)\init_code_strings.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D_W) -Fo$@ $(PROJ_SRC_DIR)\init_code_strings.cpp
$(OBJ_cr_mempool_MT_D_W): $(PROJ_SRC_DIR)\memory_pool.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D_W) -Fo$@ $(PROJ_SRC_DIR)\memory_pool.cpp
$(OBJ_cr_replacements_MT_D_W): $(PROJ_SRC_DIR)\replacements.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D_W) -Fo$@ $(PROJ_SRC_DIR)\replacements.cpp
$(OBJ_cr_snprintf_MT_D_W): $(PROJ_SRC_DIR)\snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_D_W) -Fo$@ $(PROJ_SRC_DIR)\snprintf.cpp

$(LIB_CORE_DLL_D): $(OBJ_CORE_DLL_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_DLL_D)

$(OBJ_cr_api_DLL_D): $(PROJ_SRC_DIR)\api.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.cpp
$(OBJ_cr_enumstr_DLL_D): $(PROJ_SRC_DIR)\enum_strings.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\enum_strings.cpp
$(OBJ_cr_fsdhndlrs_DLL_D): $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp
$(OBJ_cr_fmtcache_DLL_D): $(PROJ_SRC_DIR)\fmt_cache.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\fmt_cache.cpp
$(OBJ_cr_initstr_DLL_D): $(PROJ_SRC_DIR)\init_code_strings.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\init_code_strings.cpp
$(OBJ_cr_mempool_DLL_D): $(PROJ_SRC_DIR)\memory_pool.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\memory_pool.cpp
$(OBJ_cr_replacements_DLL_D): $(PROJ_SRC_DIR)\replacements.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\replacements.cpp
$(OBJ_cr_snprintf_DLL_D): $(PROJ_SRC_DIR)\snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\snprintf.cpp

$(LIB_CORE_DLL_D_W): $(OBJ_CORE_DLL_D_W) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_DLL_D_W)

$(OBJ_cr_api_DLL_D_W): $(PROJ_SRC_DIR)\api.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_D_W) -Fo$@ $(PROJ_SRC_DIR)\api.cpp
$(OBJ_cr_enumstr_DLL_D_W): $(PROJ_SRC_DIR)\enum_strings.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_D_W) -Fo$@ $(PROJ_SRC_DIR)\enum_strings.cpp
$(OBJ_cr_fsdhndlrs_DLL_D_W): $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_D_W) -Fo$@ $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp
$(OBJ_cr_fmtcache_DLL_D_W): $(PROJ_SRC_DIR)\fmt_cache.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_D_W) -Fo$@ $(PROJ_SRC_DIR)\fmt_cache.cpp
$(OBJ_cr_initstr_DLL_D_W): $(PROJ_SRC_DIR)\init_code_strings.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_D_W) -Fo$@ $(PROJ_SRC_DIR)\init_code_strings.cpp
$(OBJ_cr_mempool_DLL_D_W): $(PROJ_SRC_DIR)\memory_pool.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_D_W) -Fo$@ $(PROJ_SRC_DIR)\memory_pool.cpp
$(OBJ_cr_replacements_DLL_D_W): $(PROJ_SRC_DIR)\replacements.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_D_W) -Fo$@ $(PROJ_SRC_DIR)\replacements.cpp
$(OBJ_cr_snprintf_DLL_D_W): $(PROJ_SRC_DIR)\snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_D_W) -Fo$@ $(PROJ_SRC_DIR)\snprintf.cpp

$(LIB_CORE_DLL_R): $(OBJ_CORE_DLL_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_DLL_R)

$(OBJ_cr_api_DLL_R): $(PROJ_SRC_DIR)\api.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.cpp
$(OBJ_cr_enumstr_DLL_R): $(PROJ_SRC_DIR)\enum_strings.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\enum_strings.cpp
$(OBJ_cr_fsdhndlrs_DLL_R): $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp
$(OBJ_cr_fmtcache_DLL_R): $(PROJ_SRC_DIR)\fmt_cache.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\fmt_cache.cpp
$(OBJ_cr_initstr_DLL_R): $(PROJ_SRC_DIR)\init_code_strings.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\init_code_strings.cpp
$(OBJ_cr_mempool_DLL_R): $(PROJ_SRC_DIR)\memory_pool.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\memory_pool.cpp
$(OBJ_cr_replacements_DLL_R): $(PROJ_SRC_DIR)\replacements.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\replacements.cpp
$(OBJ_cr_snprintf_DLL_R): $(PROJ_SRC_DIR)\snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\snprintf.cpp

$(LIB_CORE_DLL_R_W): $(OBJ_CORE_DLL_R_W) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_DLL_R_W)

$(OBJ_cr_api_DLL_R_W): $(PROJ_SRC_DIR)\api.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_R_W) -Fo$@ $(PROJ_SRC_DIR)\api.cpp
$(OBJ_cr_enumstr_DLL_R_W): $(PROJ_SRC_DIR)\enum_strings.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_R_W) -Fo$@ $(PROJ_SRC_DIR)\enum_strings.cpp
$(OBJ_cr_fsdhndlrs_DLL_R_W): $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_R_W) -Fo$@ $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp
$(OBJ_cr_fmtcache_DLL_R_W): $(PROJ_SRC_DIR)\fmt_cache.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_R_W) -Fo$@ $(PROJ_SRC_DIR)\fmt_cache.cpp
$(OBJ_cr_initstr_DLL_R_W): $(PROJ_SRC_DIR)\init_code_strings.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_R_W) -Fo$@ $(PROJ_SRC_DIR)\init_code_strings.cpp
$(OBJ_cr_mempool_DLL_R_W): $(PROJ_SRC_DIR)\memory_pool.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_R_W) -Fo$@ $(PROJ_SRC_DIR)\memory_pool.cpp
$(OBJ_cr_replacements_DLL_R_W): $(PROJ_SRC_DIR)\replacements.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_R_W) -Fo$@ $(PROJ_SRC_DIR)\replacements.cpp
$(OBJ_cr_snprintf_DLL_R_W): $(PROJ_SRC_DIR)\snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_DLL_R_W) -Fo$@ $(PROJ_SRC_DIR)\snprintf.cpp

$(LIB_CORE_MT_R): $(OBJ_CORE_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_MT_R)

$(OBJ_cr_api_MT_R): $(PROJ_SRC_DIR)\api.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.cpp
$(OBJ_cr_enumstr_MT_R): $(PROJ_SRC_DIR)\enum_strings.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\enum_strings.cpp
$(OBJ_cr_fsdhndlrs_MT_R): $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp
$(OBJ_cr_fmtcache_MT_R): $(PROJ_SRC_DIR)\fmt_cache.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\fmt_cache.cpp
$(OBJ_cr_initstr_MT_R): $(PROJ_SRC_DIR)\init_code_strings.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\init_code_strings.cpp
$(OBJ_cr_mempool_MT_R): $(PROJ_SRC_DIR)\memory_pool.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\memory_pool.cpp
$(OBJ_cr_replacements_MT_R): $(PROJ_SRC_DIR)\replacements.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\replacements.cpp
$(OBJ_cr_snprintf_MT_R): $(PROJ_SRC_DIR)\snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\snprintf.cpp

$(LIB_CORE_MT_R_W): $(OBJ_CORE_MT_R_W) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_MT_R_W)

$(OBJ_cr_api_MT_R_W): $(PROJ_SRC_DIR)\api.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R_W) -Fo$@ $(PROJ_SRC_DIR)\api.cpp
$(OBJ_cr_enumstr_MT_R_W): $(PROJ_SRC_DIR)\enum_strings.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R_W) -Fo$@ $(PROJ_SRC_DIR)\enum_strings.cpp
$(OBJ_cr_fsdhndlrs_MT_R_W): $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R_W) -Fo$@ $(PROJ_SRC_DIR)\fmt_spec_defect_handlers.cpp
$(OBJ_cr_fmtcache_MT_R_W): $(PROJ_SRC_DIR)\fmt_cache.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R_W) -Fo$@ $(PROJ_SRC_DIR)\fmt_cache.cpp
$(OBJ_cr_initstr_MT_R_W): $(PROJ_SRC_DIR)\init_code_strings.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R_W) -Fo$@ $(PROJ_SRC_DIR)\init_code_strings.cpp
$(OBJ_cr_mempool_MT_R_W): $(PROJ_SRC_DIR)\memory_pool.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R_W) -Fo$@ $(PROJ_SRC_DIR)\memory_pool.cpp
$(OBJ_cr_replacements_MT_R_W): $(PROJ_SRC_DIR)\replacements.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R_W) -Fo$@ $(PROJ_SRC_DIR)\replacements.cpp
$(OBJ_cr_snprintf_MT_R_W): $(PROJ_SRC_DIR)\snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_CORE_ARGS_MT_R_W) -Fo$@ $(PROJ_SRC_DIR)\snprintf.cpp

########################################
# Loki.SafeFormat library - 'loki.safefmt.X.core.a'

!ifdef LOKI

$(LOKI_SFMT_SRC_DIR)\loki.safefmt.cpp:	$(PROJ_MAKEFILE_NAME)
	@-if not exist $(LOKI_SFMT_SRC_DIR)\NUL mkdir $(LOKI_SFMT_SRC_DIR)
	echo #include "../src/SafeFormat.cpp" > $@

$(LIB_LOKI_SFMT_MT_D): $(OBJ_LOKI_SFMT_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_LOKI_SFMT_MT_D)

$(OBJ_lok_sfmt_MT_D): $(LOKI_SFMT_SRC_DIR)\loki.safefmt.cpp $(LOKI_SFMT_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_LOKI_SFMT_INCLUDES_MT_D) -Fo$@ $(LOKI_SFMT_SRC_DIR)\loki.safefmt.cpp

$(LIB_LOKI_SFMT_MT_D_W): $(OBJ_LOKI_SFMT_MT_D_W) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_LOKI_SFMT_MT_D_W)

$(OBJ_lok_sfmt_MT_D_W): $(LOKI_SFMT_SRC_DIR)\loki.safefmt.cpp $(LOKI_SFMT_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) $(CPPC_LOKI_SFMT_INCLUDES_MT_D_W) -Fo$@ $(LOKI_SFMT_SRC_DIR)\loki.safefmt.cpp

$(LIB_LOKI_SFMT_DLL_D): $(OBJ_LOKI_SFMT_DLL_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_LOKI_SFMT_DLL_D)

$(OBJ_lok_sfmt_DLL_D): $(LOKI_SFMT_SRC_DIR)\loki.safefmt.cpp $(LOKI_SFMT_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) $(CPPC_LOKI_SFMT_INCLUDES_DLL_D) -Fo$@ $(LOKI_SFMT_SRC_DIR)\loki.safefmt.cpp

$(LIB_LOKI_SFMT_DLL_D_W): $(OBJ_LOKI_SFMT_DLL_D_W) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_LOKI_SFMT_DLL_D_W)

$(OBJ_lok_sfmt_DLL_D_W): $(LOKI_SFMT_SRC_DIR)\loki.safefmt.cpp $(LOKI_SFMT_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) $(CPPC_LOKI_SFMT_INCLUDES_DLL_D_W) -Fo$@ $(LOKI_SFMT_SRC_DIR)\loki.safefmt.cpp

$(LIB_LOKI_SFMT_DLL_R): $(OBJ_LOKI_SFMT_DLL_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_LOKI_SFMT_DLL_R)

$(OBJ_lok_sfmt_DLL_R): $(LOKI_SFMT_SRC_DIR)\loki.safefmt.cpp $(LOKI_SFMT_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) $(CPPC_LOKI_SFMT_INCLUDES_DLL_R) -Fo$@ $(LOKI_SFMT_SRC_DIR)\loki.safefmt.cpp

$(LIB_LOKI_SFMT_DLL_R_W): $(OBJ_LOKI_SFMT_DLL_R_W) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_LOKI_SFMT_DLL_R_W)

$(OBJ_lok_sfmt_DLL_R_W): $(LOKI_SFMT_SRC_DIR)\loki.safefmt.cpp $(LOKI_SFMT_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) $(CPPC_LOKI_SFMT_INCLUDES_DLL_R_W) -Fo$@ $(LOKI_SFMT_SRC_DIR)\loki.safefmt.cpp

$(LIB_LOKI_SFMT_MT_R): $(OBJ_LOKI_SFMT_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_LOKI_SFMT_MT_R)

$(OBJ_lok_sfmt_MT_R): $(LOKI_SFMT_SRC_DIR)\loki.safefmt.cpp $(LOKI_SFMT_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_LOKI_SFMT_INCLUDES_MT_R) -Fo$@ $(LOKI_SFMT_SRC_DIR)\loki.safefmt.cpp

$(LIB_LOKI_SFMT_MT_R_W): $(OBJ_LOKI_SFMT_MT_R_W) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_LOKI_SFMT_MT_R_W)

$(OBJ_lok_sfmt_MT_R_W): $(LOKI_SFMT_SRC_DIR)\loki.safefmt.cpp $(LOKI_SFMT_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) $(CPPC_LOKI_SFMT_INCLUDES_MT_R_W) -Fo$@ $(LOKI_SFMT_SRC_DIR)\loki.safefmt.cpp

!endif # LOKI
########################################
# shwild library - 'shwild.X.core.a'

$(LIB_SHWILD_MT_D): $(OBJ_SHWILD_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_MT_D)

$(OBJ_shw_api_MT_D): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_SHWILD_INCLUDES_MT_D) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_MT_D): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_SHWILD_INCLUDES_MT_D) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_MT_D): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_SHWILD_INCLUDES_MT_D) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_MT_D_W): $(OBJ_SHWILD_MT_D_W) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_MT_D_W)

$(OBJ_shw_api_MT_D_W): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) $(CPPC_SHWILD_INCLUDES_MT_D_W) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_MT_D_W): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) $(CPPC_SHWILD_INCLUDES_MT_D_W) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_MT_D_W): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) $(CPPC_SHWILD_INCLUDES_MT_D_W) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_DLL_D): $(OBJ_SHWILD_DLL_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_DLL_D)

$(OBJ_shw_api_DLL_D): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) $(CPPC_SHWILD_INCLUDES_DLL_D) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_DLL_D): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) $(CPPC_SHWILD_INCLUDES_DLL_D) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_DLL_D): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) $(CPPC_SHWILD_INCLUDES_DLL_D) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_DLL_D_W): $(OBJ_SHWILD_DLL_D_W) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_DLL_D_W)

$(OBJ_shw_api_DLL_D_W): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) $(CPPC_SHWILD_INCLUDES_DLL_D_W) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_DLL_D_W): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) $(CPPC_SHWILD_INCLUDES_DLL_D_W) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_DLL_D_W): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) $(CPPC_SHWILD_INCLUDES_DLL_D_W) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_DLL_R): $(OBJ_SHWILD_DLL_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_DLL_R)

$(OBJ_shw_api_DLL_R): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) $(CPPC_SHWILD_INCLUDES_DLL_R) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_DLL_R): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) $(CPPC_SHWILD_INCLUDES_DLL_R) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_DLL_R): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) $(CPPC_SHWILD_INCLUDES_DLL_R) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_DLL_R_W): $(OBJ_SHWILD_DLL_R_W) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_DLL_R_W)

$(OBJ_shw_api_DLL_R_W): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) $(CPPC_SHWILD_INCLUDES_DLL_R_W) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_DLL_R_W): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) $(CPPC_SHWILD_INCLUDES_DLL_R_W) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_DLL_R_W): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) $(CPPC_SHWILD_INCLUDES_DLL_R_W) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_MT_R): $(OBJ_SHWILD_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_MT_R)

$(OBJ_shw_api_MT_R): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_SHWILD_INCLUDES_MT_R) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_MT_R): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_SHWILD_INCLUDES_MT_R) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_MT_R): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_SHWILD_INCLUDES_MT_R) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_MT_R_W): $(OBJ_SHWILD_MT_R_W) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_MT_R_W)

$(OBJ_shw_api_MT_R_W): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) $(CPPC_SHWILD_INCLUDES_MT_R_W) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_MT_R_W): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) $(CPPC_SHWILD_INCLUDES_MT_R_W) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_MT_R_W): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) $(CPPC_SHWILD_INCLUDES_MT_R_W) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

########################################
# xTests library - 'xtests.X.ff.core.a'

$(LIB_XTESTS_MT_D): $(OBJ_XTESTS_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_MT_D)

$(OBJ_xts_core_MT_D): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_XTESTS_INCLUDES_MT_D) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_MT_D_W): $(OBJ_XTESTS_MT_D_W) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_MT_D_W)

$(OBJ_xts_core_MT_D_W): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) $(CPPC_XTESTS_INCLUDES_MT_D_W) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_DLL_D): $(OBJ_XTESTS_DLL_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_DLL_D)

$(OBJ_xts_core_DLL_D): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) $(CPPC_XTESTS_INCLUDES_DLL_D) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_DLL_D_W): $(OBJ_XTESTS_DLL_D_W) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_DLL_D_W)

$(OBJ_xts_core_DLL_D_W): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) $(CPPC_XTESTS_INCLUDES_DLL_D_W) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_DLL_R): $(OBJ_XTESTS_DLL_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_DLL_R)

$(OBJ_xts_core_DLL_R): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) $(CPPC_XTESTS_INCLUDES_DLL_R) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_DLL_R_W): $(OBJ_XTESTS_DLL_R_W) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_DLL_R_W)

$(OBJ_xts_core_DLL_R_W): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) $(CPPC_XTESTS_INCLUDES_DLL_R_W) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_MT_R): $(OBJ_XTESTS_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_MT_R)

$(OBJ_xts_core_MT_R): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_XTESTS_INCLUDES_MT_R) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_MT_R_W): $(OBJ_XTESTS_MT_R_W) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_MT_R_W)

$(OBJ_xts_core_MT_R_W): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) $(CPPC_XTESTS_INCLUDES_MT_R_W) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

##################################################
# Examples: BitBucket

$(BITBUCKET_SRC_DIR)\bitbucket.cpp:	#$(PROJ_MAKEFILE_NAME)
	@-if not exist $(BITBUCKET_SRC_DIR)\NUL mkdir $(BITBUCKET_SRC_DIR)
	echo #include "stdio.h" > $@
	echo int main(int, char**) { int ch; for(; EOF != (ch = getchar());) { ; } return 0; } >> $@

$(TARG_BITBUCKET_MT_D):	$(OBJ_BITBUCKET_MT_D)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_BITBUCKET_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_BITBUCKET_MT_D):	$(BITBUCKET_SRC_DIR)\bitbucket.cpp $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(BITBUCKET_SRC_DIR)\bitbucket.cpp

$(TARG_BITBUCKET_MT_D_W):	$(OBJ_BITBUCKET_MT_D_W)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_BITBUCKET_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_BITBUCKET_MT_D_W):	$(BITBUCKET_SRC_DIR)\bitbucket.cpp $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(BITBUCKET_SRC_DIR)\bitbucket.cpp

$(TARG_BITBUCKET_DLL_D):	$(OBJ_BITBUCKET_DLL_D)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_BITBUCKET_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_BITBUCKET_DLL_D):	$(BITBUCKET_SRC_DIR)\bitbucket.cpp $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(BITBUCKET_SRC_DIR)\bitbucket.cpp

$(TARG_BITBUCKET_DLL_D_W):	$(OBJ_BITBUCKET_DLL_D_W)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_BITBUCKET_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_BITBUCKET_DLL_D_W):	$(BITBUCKET_SRC_DIR)\bitbucket.cpp $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(BITBUCKET_SRC_DIR)\bitbucket.cpp

$(TARG_BITBUCKET_DLL_R):	$(OBJ_BITBUCKET_DLL_R)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_BITBUCKET_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_BITBUCKET_DLL_R):	$(BITBUCKET_SRC_DIR)\bitbucket.cpp $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(BITBUCKET_SRC_DIR)\bitbucket.cpp

$(TARG_BITBUCKET_DLL_R_W):	$(OBJ_BITBUCKET_DLL_R_W)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_BITBUCKET_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_BITBUCKET_DLL_R_W):	$(BITBUCKET_SRC_DIR)\bitbucket.cpp $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(BITBUCKET_SRC_DIR)\bitbucket.cpp

$(TARG_BITBUCKET_MT_R):	$(OBJ_BITBUCKET_MT_R)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_BITBUCKET_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_BITBUCKET_MT_R):	$(BITBUCKET_SRC_DIR)\bitbucket.cpp $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(BITBUCKET_SRC_DIR)\bitbucket.cpp

$(TARG_BITBUCKET_MT_R_W):	$(OBJ_BITBUCKET_MT_R_W)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_BITBUCKET_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_BITBUCKET_MT_R_W):	$(BITBUCKET_SRC_DIR)\bitbucket.cpp $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(BITBUCKET_SRC_DIR)\bitbucket.cpp


##################################################
# Examples

$(TARG_EX_boolean_MT_D):    \
		$(OBJ_EX_boolean_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_boolean_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_boolean_MT_D): $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp

$(TARG_EX_boolean_MT_D_W):    \
		$(OBJ_EX_boolean_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_EX_boolean_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_EX_boolean_MT_D_W): $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp

$(TARG_EX_boolean_DLL_D):    \
		$(OBJ_EX_boolean_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_boolean_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_boolean_DLL_D): $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp

$(TARG_EX_boolean_DLL_D_W):    \
		$(OBJ_EX_boolean_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_EX_boolean_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_EX_boolean_DLL_D_W): $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp

$(TARG_EX_boolean_DLL_R):    \
		$(OBJ_EX_boolean_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_boolean_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_boolean_DLL_R): $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp

$(TARG_EX_boolean_DLL_R_W):    \
		$(OBJ_EX_boolean_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_EX_boolean_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_EX_boolean_DLL_R_W): $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp

$(TARG_EX_boolean_MT_R):    \
		$(OBJ_EX_boolean_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_boolean_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_boolean_MT_R): $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp

$(TARG_EX_boolean_MT_R_W):    \
		$(OBJ_EX_boolean_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_EX_boolean_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_EX_boolean_MT_R_W): $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.boolean\example.arguments.boolean.cpp

$(TARG_EX_character_MT_D):    \
		$(OBJ_EX_character_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_character_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_character_MT_D): $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp

$(TARG_EX_character_MT_D_W):    \
		$(OBJ_EX_character_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_EX_character_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_EX_character_MT_D_W): $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp

$(TARG_EX_character_DLL_D):    \
		$(OBJ_EX_character_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_character_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_character_DLL_D): $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp

$(TARG_EX_character_DLL_D_W):    \
		$(OBJ_EX_character_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_EX_character_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_EX_character_DLL_D_W): $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp

$(TARG_EX_character_DLL_R):    \
		$(OBJ_EX_character_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_character_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_character_DLL_R): $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp

$(TARG_EX_character_DLL_R_W):    \
		$(OBJ_EX_character_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_EX_character_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_EX_character_DLL_R_W): $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp

$(TARG_EX_character_MT_R):    \
		$(OBJ_EX_character_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_character_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_character_MT_R): $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp

$(TARG_EX_character_MT_R_W):    \
		$(OBJ_EX_character_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_EX_character_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_EX_character_MT_R_W): $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.character\example.arguments.character.cpp

$(TARG_EX_reals_MT_D):    \
		$(OBJ_EX_reals_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_reals_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_reals_MT_D): $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp

$(TARG_EX_reals_MT_D_W):    \
		$(OBJ_EX_reals_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_EX_reals_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_EX_reals_MT_D_W): $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp

$(TARG_EX_reals_DLL_D):    \
		$(OBJ_EX_reals_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_reals_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_reals_DLL_D): $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp

$(TARG_EX_reals_DLL_D_W):    \
		$(OBJ_EX_reals_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_EX_reals_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_EX_reals_DLL_D_W): $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp

$(TARG_EX_reals_DLL_R):    \
		$(OBJ_EX_reals_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_reals_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_reals_DLL_R): $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp

$(TARG_EX_reals_DLL_R_W):    \
		$(OBJ_EX_reals_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_EX_reals_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_EX_reals_DLL_R_W): $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp

$(TARG_EX_reals_MT_R):    \
		$(OBJ_EX_reals_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_reals_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_reals_MT_R): $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp

$(TARG_EX_reals_MT_R_W):    \
		$(OBJ_EX_reals_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_EX_reals_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_EX_reals_MT_R_W): $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.reals\example.arguments.reals.cpp

$(TARG_EX_voidptrs_MT_D):    \
		$(OBJ_EX_voidptrs_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_voidptrs_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_voidptrs_MT_D): $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp

$(TARG_EX_voidptrs_MT_D_W):    \
		$(OBJ_EX_voidptrs_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_EX_voidptrs_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_EX_voidptrs_MT_D_W): $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp

$(TARG_EX_voidptrs_DLL_D):    \
		$(OBJ_EX_voidptrs_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_voidptrs_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_voidptrs_DLL_D): $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp

$(TARG_EX_voidptrs_DLL_D_W):    \
		$(OBJ_EX_voidptrs_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_EX_voidptrs_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_EX_voidptrs_DLL_D_W): $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp

$(TARG_EX_voidptrs_DLL_R):    \
		$(OBJ_EX_voidptrs_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_voidptrs_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_voidptrs_DLL_R): $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp

$(TARG_EX_voidptrs_DLL_R_W):    \
		$(OBJ_EX_voidptrs_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_EX_voidptrs_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_EX_voidptrs_DLL_R_W): $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp

$(TARG_EX_voidptrs_MT_R):    \
		$(OBJ_EX_voidptrs_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_voidptrs_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_voidptrs_MT_R): $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp

$(TARG_EX_voidptrs_MT_R_W):    \
		$(OBJ_EX_voidptrs_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_EX_voidptrs_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_EX_voidptrs_MT_R_W): $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.arguments.void_pointers\example.arguments.void_pointers.cpp

$(TARG_EX_ff_101_MT_D):    \
		$(OBJ_EX_ff_101_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ff_101_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ff_101_MT_D): $(PROJ_EXAMPLES_DIR)\example.ff_101\example.ff_101.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.ff_101\example.ff_101.cpp

$(TARG_EX_ff_101_DLL_D):    \
		$(OBJ_EX_ff_101_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ff_101_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ff_101_DLL_D): $(PROJ_EXAMPLES_DIR)\example.ff_101\example.ff_101.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.ff_101\example.ff_101.cpp

$(TARG_EX_ff_101_DLL_R):    \
		$(OBJ_EX_ff_101_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ff_101_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ff_101_DLL_R): $(PROJ_EXAMPLES_DIR)\example.ff_101\example.ff_101.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.ff_101\example.ff_101.cpp

$(TARG_EX_ff_101_MT_R):    \
		$(OBJ_EX_ff_101_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ff_101_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ff_101_MT_R): $(PROJ_EXAMPLES_DIR)\example.ff_101\example.ff_101.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.ff_101\example.ff_101.cpp

$(TARG_EX_ff_101_nons_MT_D):    \
		$(OBJ_EX_ff_101_nons_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ff_101_nons_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ff_101_nons_MT_D): $(PROJ_EXAMPLES_DIR)\example.ff_101.no_namespace\example.ff_101.no_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.ff_101.no_namespace\example.ff_101.no_namespace.cpp

$(TARG_EX_ff_101_nons_DLL_D):    \
		$(OBJ_EX_ff_101_nons_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ff_101_nons_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ff_101_nons_DLL_D): $(PROJ_EXAMPLES_DIR)\example.ff_101.no_namespace\example.ff_101.no_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.ff_101.no_namespace\example.ff_101.no_namespace.cpp

$(TARG_EX_ff_101_nons_DLL_R):    \
		$(OBJ_EX_ff_101_nons_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ff_101_nons_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ff_101_nons_DLL_R): $(PROJ_EXAMPLES_DIR)\example.ff_101.no_namespace\example.ff_101.no_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.ff_101.no_namespace\example.ff_101.no_namespace.cpp

$(TARG_EX_ff_101_nons_MT_R):    \
		$(OBJ_EX_ff_101_nons_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ff_101_nons_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ff_101_nons_MT_R): $(PROJ_EXAMPLES_DIR)\example.ff_101.no_namespace\example.ff_101.no_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.ff_101.no_namespace\example.ff_101.no_namespace.cpp

$(TARG_EX_flush_MT_D):    \
		$(OBJ_EX_flush_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_flush_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_flush_MT_D): $(PROJ_EXAMPLES_DIR)\example.flush\example.flush.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.flush\example.flush.cpp

$(TARG_EX_flush_DLL_D):    \
		$(OBJ_EX_flush_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_flush_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_flush_DLL_D): $(PROJ_EXAMPLES_DIR)\example.flush\example.flush.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.flush\example.flush.cpp

$(TARG_EX_flush_DLL_R):    \
		$(OBJ_EX_flush_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_flush_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_flush_DLL_R): $(PROJ_EXAMPLES_DIR)\example.flush\example.flush.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.flush\example.flush.cpp

$(TARG_EX_flush_MT_R):    \
		$(OBJ_EX_flush_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_flush_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_flush_MT_R): $(PROJ_EXAMPLES_DIR)\example.flush\example.flush.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.flush\example.flush.cpp

$(TARG_EX_ins_hex_MT_D):    \
		$(OBJ_EX_ins_hex_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ins_hex_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ins_hex_MT_D): $(PROJ_EXAMPLES_DIR)\example.inserter.hex\example.inserter.hex.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.inserter.hex\example.inserter.hex.cpp

$(TARG_EX_ins_hex_DLL_D):    \
		$(OBJ_EX_ins_hex_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ins_hex_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ins_hex_DLL_D): $(PROJ_EXAMPLES_DIR)\example.inserter.hex\example.inserter.hex.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.inserter.hex\example.inserter.hex.cpp

$(TARG_EX_ins_hex_DLL_R):    \
		$(OBJ_EX_ins_hex_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ins_hex_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ins_hex_DLL_R): $(PROJ_EXAMPLES_DIR)\example.inserter.hex\example.inserter.hex.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.inserter.hex\example.inserter.hex.cpp

$(TARG_EX_ins_hex_MT_R):    \
		$(OBJ_EX_ins_hex_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ins_hex_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ins_hex_MT_R): $(PROJ_EXAMPLES_DIR)\example.inserter.hex\example.inserter.hex.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.inserter.hex\example.inserter.hex.cpp

$(TARG_EX_ins_integers_MT_D):    \
		$(OBJ_EX_ins_integers_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ins_integers_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ins_integers_MT_D): $(PROJ_EXAMPLES_DIR)\example.inserter.integers\example.inserter.integers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.inserter.integers\example.inserter.integers.cpp

$(TARG_EX_ins_integers_DLL_D):    \
		$(OBJ_EX_ins_integers_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ins_integers_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ins_integers_DLL_D): $(PROJ_EXAMPLES_DIR)\example.inserter.integers\example.inserter.integers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.inserter.integers\example.inserter.integers.cpp

$(TARG_EX_ins_integers_DLL_R):    \
		$(OBJ_EX_ins_integers_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ins_integers_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ins_integers_DLL_R): $(PROJ_EXAMPLES_DIR)\example.inserter.integers\example.inserter.integers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.inserter.integers\example.inserter.integers.cpp

$(TARG_EX_ins_integers_MT_R):    \
		$(OBJ_EX_ins_integers_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ins_integers_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ins_integers_MT_R): $(PROJ_EXAMPLES_DIR)\example.inserter.integers\example.inserter.integers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.inserter.integers\example.inserter.integers.cpp

$(TARG_EX_ins_reals_MT_D):    \
		$(OBJ_EX_ins_reals_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ins_reals_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ins_reals_MT_D): $(PROJ_EXAMPLES_DIR)\example.inserter.reals\example.inserter.reals.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.inserter.reals\example.inserter.reals.cpp

$(TARG_EX_ins_reals_DLL_D):    \
		$(OBJ_EX_ins_reals_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ins_reals_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ins_reals_DLL_D): $(PROJ_EXAMPLES_DIR)\example.inserter.reals\example.inserter.reals.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.inserter.reals\example.inserter.reals.cpp

$(TARG_EX_ins_reals_DLL_R):    \
		$(OBJ_EX_ins_reals_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ins_reals_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ins_reals_DLL_R): $(PROJ_EXAMPLES_DIR)\example.inserter.reals\example.inserter.reals.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.inserter.reals\example.inserter.reals.cpp

$(TARG_EX_ins_reals_MT_R):    \
		$(OBJ_EX_ins_reals_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ins_reals_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ins_reals_MT_R): $(PROJ_EXAMPLES_DIR)\example.inserter.reals\example.inserter.reals.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.inserter.reals\example.inserter.reals.cpp


$(TARG_EX_ins_WLIs_MT_D):    \
		$(OBJ_EX_ins_WLIs_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ins_WLIs_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ins_WLIs_MT_D): $(PROJ_EXAMPLES_DIR)\example.inserter.integers.WindowsLargeIntegers\example.inserter.integers.WindowsLargeIntegers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.inserter.integers.WindowsLargeIntegers\example.inserter.integers.WindowsLargeIntegers.cpp

$(TARG_EX_ins_WLIs_DLL_D):    \
		$(OBJ_EX_ins_WLIs_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ins_WLIs_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ins_WLIs_DLL_D): $(PROJ_EXAMPLES_DIR)\example.inserter.integers.WindowsLargeIntegers\example.inserter.integers.WindowsLargeIntegers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.inserter.integers.WindowsLargeIntegers\example.inserter.integers.WindowsLargeIntegers.cpp

$(TARG_EX_ins_WLIs_DLL_R):    \
		$(OBJ_EX_ins_WLIs_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ins_WLIs_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ins_WLIs_DLL_R): $(PROJ_EXAMPLES_DIR)\example.inserter.integers.WindowsLargeIntegers\example.inserter.integers.WindowsLargeIntegers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.inserter.integers.WindowsLargeIntegers\example.inserter.integers.WindowsLargeIntegers.cpp

$(TARG_EX_ins_WLIs_MT_R):    \
		$(OBJ_EX_ins_WLIs_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ins_WLIs_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ins_WLIs_MT_R): $(PROJ_EXAMPLES_DIR)\example.inserter.integers.WindowsLargeIntegers\example.inserter.integers.WindowsLargeIntegers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.inserter.integers.WindowsLargeIntegers\example.inserter.integers.WindowsLargeIntegers.cpp


$(TARG_EX_itr_fmt_MT_D):    \
		$(OBJ_EX_itr_fmt_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARG_BITBUCKET_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_itr_fmt_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_itr_fmt_MT_D): $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp

$(TARG_EX_itr_fmt_MT_D_W):    \
		$(OBJ_EX_itr_fmt_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(TARG_BITBUCKET_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_EX_itr_fmt_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_EX_itr_fmt_MT_D_W): $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp

$(TARG_EX_itr_fmt_DLL_D):    \
		$(OBJ_EX_itr_fmt_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARG_BITBUCKET_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_itr_fmt_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_itr_fmt_DLL_D): $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp

$(TARG_EX_itr_fmt_DLL_D_W):    \
		$(OBJ_EX_itr_fmt_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(TARG_BITBUCKET_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_EX_itr_fmt_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_EX_itr_fmt_DLL_D_W): $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp

$(TARG_EX_itr_fmt_DLL_R):    \
		$(OBJ_EX_itr_fmt_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARG_BITBUCKET_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_itr_fmt_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_itr_fmt_DLL_R): $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp

$(TARG_EX_itr_fmt_DLL_R_W):    \
		$(OBJ_EX_itr_fmt_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(TARG_BITBUCKET_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_EX_itr_fmt_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_EX_itr_fmt_DLL_R_W): $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp

$(TARG_EX_itr_fmt_MT_R):    \
		$(OBJ_EX_itr_fmt_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARG_BITBUCKET_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_itr_fmt_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_itr_fmt_MT_R): $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp

$(TARG_EX_itr_fmt_MT_R_W):    \
		$(OBJ_EX_itr_fmt_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(TARG_BITBUCKET_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_EX_itr_fmt_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_EX_itr_fmt_MT_R_W): $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.iterators.format_iterator\example.iterators.format_iterator.cpp

$(TARG_EX_ovld2_filt_MT_D):    \
		$(OBJ_EX_ovld2_filt_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ovld2_filt_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ovld2_filt_MT_D): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.filter_type\example.overload.2.custom_type.filter_type.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.filter_type\example.overload.2.custom_type.filter_type.cpp

$(TARG_EX_ovld2_filt_DLL_D):    \
		$(OBJ_EX_ovld2_filt_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ovld2_filt_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ovld2_filt_DLL_D): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.filter_type\example.overload.2.custom_type.filter_type.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.filter_type\example.overload.2.custom_type.filter_type.cpp

$(TARG_EX_ovld2_filt_DLL_R):    \
		$(OBJ_EX_ovld2_filt_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ovld2_filt_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ovld2_filt_DLL_R): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.filter_type\example.overload.2.custom_type.filter_type.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.filter_type\example.overload.2.custom_type.filter_type.cpp

$(TARG_EX_ovld2_filt_MT_R):    \
		$(OBJ_EX_ovld2_filt_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ovld2_filt_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ovld2_filt_MT_R): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.filter_type\example.overload.2.custom_type.filter_type.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.filter_type\example.overload.2.custom_type.filter_type.cpp


$(TARG_EX_ovld2_ins_MT_D):    \
		$(OBJ_EX_ovld2_ins_MT_D)\
		$(PROJ_BUNDLES_DIR)\superhero.properties\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ovld2_ins_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ovld2_ins_MT_D): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.inserter\example.overload.2.custom_type.inserter.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.inserter\example.overload.2.custom_type.inserter.cpp

$(TARG_EX_ovld2_ins_DLL_D):    \
		$(OBJ_EX_ovld2_ins_DLL_D)\
		$(PROJ_BUNDLES_DIR)\superhero.properties\
		$(LIB_CORE_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ovld2_ins_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ovld2_ins_DLL_D): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.inserter\example.overload.2.custom_type.inserter.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.inserter\example.overload.2.custom_type.inserter.cpp

$(TARG_EX_ovld2_ins_DLL_R):    \
		$(OBJ_EX_ovld2_ins_DLL_R)\
		$(PROJ_BUNDLES_DIR)\superhero.properties\
		$(LIB_CORE_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ovld2_ins_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ovld2_ins_DLL_R): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.inserter\example.overload.2.custom_type.inserter.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.inserter\example.overload.2.custom_type.inserter.cpp

$(TARG_EX_ovld2_ins_MT_R):    \
		$(OBJ_EX_ovld2_ins_MT_R)\
		$(PROJ_BUNDLES_DIR)\superhero.properties\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ovld2_ins_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ovld2_ins_MT_R): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.inserter\example.overload.2.custom_type.inserter.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.inserter\example.overload.2.custom_type.inserter.cpp

$(TARG_EX_ovld2_sas_MT_D):    \
		$(OBJ_EX_ovld2_sas_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ovld2_sas_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ovld2_sas_MT_D): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.string_access_shims\example.overload.2.custom_type.string_access_shims.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.string_access_shims\example.overload.2.custom_type.string_access_shims.cpp

$(TARG_EX_ovld2_sas_DLL_D):    \
		$(OBJ_EX_ovld2_sas_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ovld2_sas_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ovld2_sas_DLL_D): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.string_access_shims\example.overload.2.custom_type.string_access_shims.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.string_access_shims\example.overload.2.custom_type.string_access_shims.cpp

$(TARG_EX_ovld2_sas_DLL_R):    \
		$(OBJ_EX_ovld2_sas_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ovld2_sas_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ovld2_sas_DLL_R): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.string_access_shims\example.overload.2.custom_type.string_access_shims.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.string_access_shims\example.overload.2.custom_type.string_access_shims.cpp

$(TARG_EX_ovld2_sas_MT_R):    \
		$(OBJ_EX_ovld2_sas_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ovld2_sas_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ovld2_sas_MT_R): $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.string_access_shims\example.overload.2.custom_type.string_access_shims.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.2.custom_type.string_access_shims\example.overload.2.custom_type.string_access_shims.cpp

$(TARG_EX_ovld3_fpcol_MT_D):    \
		$(OBJ_EX_ovld3_fpcol_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARG_BITBUCKET_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ovld3_fpcol_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ovld3_fpcol_MT_D): $(PROJ_EXAMPLES_DIR)\example.overload.3.floatingpoint_columns\example.overload.3.floatingpoint_columns.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.3.floatingpoint_columns\example.overload.3.floatingpoint_columns.cpp

$(TARG_EX_ovld3_fpcol_DLL_D):    \
		$(OBJ_EX_ovld3_fpcol_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARG_BITBUCKET_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ovld3_fpcol_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ovld3_fpcol_DLL_D): $(PROJ_EXAMPLES_DIR)\example.overload.3.floatingpoint_columns\example.overload.3.floatingpoint_columns.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.3.floatingpoint_columns\example.overload.3.floatingpoint_columns.cpp

$(TARG_EX_ovld3_fpcol_DLL_R):    \
		$(OBJ_EX_ovld3_fpcol_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARG_BITBUCKET_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ovld3_fpcol_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ovld3_fpcol_DLL_R): $(PROJ_EXAMPLES_DIR)\example.overload.3.floatingpoint_columns\example.overload.3.floatingpoint_columns.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.3.floatingpoint_columns\example.overload.3.floatingpoint_columns.cpp

$(TARG_EX_ovld3_fpcol_MT_R):    \
		$(OBJ_EX_ovld3_fpcol_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARG_BITBUCKET_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ovld3_fpcol_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ovld3_fpcol_MT_R): $(PROJ_EXAMPLES_DIR)\example.overload.3.floatingpoint_columns\example.overload.3.floatingpoint_columns.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.3.floatingpoint_columns\example.overload.3.floatingpoint_columns.cpp

$(TARG_EX_ovld3_tabs_MT_D):    \
		$(OBJ_EX_ovld3_tabs_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARG_BITBUCKET_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ovld3_tabs_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ovld3_tabs_MT_D): $(PROJ_EXAMPLES_DIR)\example.overload.3.tabulations\example.overload.3.tabulations.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.3.tabulations\example.overload.3.tabulations.cpp

$(TARG_EX_ovld3_tabs_DLL_D):    \
		$(OBJ_EX_ovld3_tabs_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARG_BITBUCKET_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ovld3_tabs_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ovld3_tabs_DLL_D): $(PROJ_EXAMPLES_DIR)\example.overload.3.tabulations\example.overload.3.tabulations.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.3.tabulations\example.overload.3.tabulations.cpp

$(TARG_EX_ovld3_tabs_DLL_R):    \
		$(OBJ_EX_ovld3_tabs_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARG_BITBUCKET_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ovld3_tabs_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ovld3_tabs_DLL_R): $(PROJ_EXAMPLES_DIR)\example.overload.3.tabulations\example.overload.3.tabulations.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.3.tabulations\example.overload.3.tabulations.cpp

$(TARG_EX_ovld3_tabs_MT_R):    \
		$(OBJ_EX_ovld3_tabs_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARG_BITBUCKET_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ovld3_tabs_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ovld3_tabs_MT_R): $(PROJ_EXAMPLES_DIR)\example.overload.3.tabulations\example.overload.3.tabulations.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.3.tabulations\example.overload.3.tabulations.cpp

$(TARG_EX_ovld3_svrlg_MT_D):    \
		$(OBJ_EX_ovld3_svrlg_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARG_BITBUCKET_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ovld3_svrlg_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ovld3_svrlg_MT_D): $(PROJ_EXAMPLES_DIR)\example.overload.3.server_log\example.overload.3.server_log.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.3.server_log\example.overload.3.server_log.cpp

$(TARG_EX_ovld3_svrlg_DLL_D):    \
		$(OBJ_EX_ovld3_svrlg_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARG_BITBUCKET_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ovld3_svrlg_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ovld3_svrlg_DLL_D): $(PROJ_EXAMPLES_DIR)\example.overload.3.server_log\example.overload.3.server_log.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.3.server_log\example.overload.3.server_log.cpp

$(TARG_EX_ovld3_svrlg_DLL_R):    \
		$(OBJ_EX_ovld3_svrlg_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARG_BITBUCKET_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ovld3_svrlg_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ovld3_svrlg_DLL_R): $(PROJ_EXAMPLES_DIR)\example.overload.3.server_log\example.overload.3.server_log.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.3.server_log\example.overload.3.server_log.cpp

$(TARG_EX_ovld3_svrlg_MT_R):    \
		$(OBJ_EX_ovld3_svrlg_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARG_BITBUCKET_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ovld3_svrlg_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ovld3_svrlg_MT_R): $(PROJ_EXAMPLES_DIR)\example.overload.3.server_log\example.overload.3.server_log.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.3.server_log\example.overload.3.server_log.cpp

$(TARG_EX_ovld3_rcins_MT_D):    \
		$(OBJ_EX_ovld3_rcins_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARG_BITBUCKET_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ovld3_rcins_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ovld3_rcins_MT_D): $(PROJ_EXAMPLES_DIR)\example.overload.3.record_insert\example.overload.3.record_insert.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.3.record_insert\example.overload.3.record_insert.cpp

$(TARG_EX_ovld3_rcins_DLL_D):    \
		$(OBJ_EX_ovld3_rcins_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARG_BITBUCKET_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ovld3_rcins_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ovld3_rcins_DLL_D): $(PROJ_EXAMPLES_DIR)\example.overload.3.record_insert\example.overload.3.record_insert.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.3.record_insert\example.overload.3.record_insert.cpp

$(TARG_EX_ovld3_rcins_DLL_R):    \
		$(OBJ_EX_ovld3_rcins_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARG_BITBUCKET_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ovld3_rcins_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ovld3_rcins_DLL_R): $(PROJ_EXAMPLES_DIR)\example.overload.3.record_insert\example.overload.3.record_insert.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.3.record_insert\example.overload.3.record_insert.cpp

$(TARG_EX_ovld3_rcins_MT_R):    \
		$(OBJ_EX_ovld3_rcins_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARG_BITBUCKET_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ovld3_rcins_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ovld3_rcins_MT_R): $(PROJ_EXAMPLES_DIR)\example.overload.3.record_insert\example.overload.3.record_insert.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.overload.3.record_insert\example.overload.3.record_insert.cpp

$(TARG_EX_pad_hash_MT_D):    \
		$(OBJ_EX_pad_hash_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARG_BITBUCKET_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_pad_hash_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_pad_hash_MT_D): $(PROJ_EXAMPLES_DIR)\example.pad.hash\example.pad.hash.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.pad.hash\example.pad.hash.cpp

$(TARG_EX_pad_hash_DLL_D):    \
		$(OBJ_EX_pad_hash_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARG_BITBUCKET_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_pad_hash_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_pad_hash_DLL_D): $(PROJ_EXAMPLES_DIR)\example.pad.hash\example.pad.hash.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.pad.hash\example.pad.hash.cpp

$(TARG_EX_pad_hash_DLL_R):    \
		$(OBJ_EX_pad_hash_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARG_BITBUCKET_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_pad_hash_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_pad_hash_DLL_R): $(PROJ_EXAMPLES_DIR)\example.pad.hash\example.pad.hash.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.pad.hash\example.pad.hash.cpp

$(TARG_EX_pad_hash_MT_R):    \
		$(OBJ_EX_pad_hash_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARG_BITBUCKET_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_pad_hash_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_pad_hash_MT_R): $(PROJ_EXAMPLES_DIR)\example.pad.hash\example.pad.hash.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.pad.hash\example.pad.hash.cpp

$(TARG_EX_sink_cstr_MT_D):    \
		$(OBJ_EX_sink_cstr_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARG_BITBUCKET_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_sink_cstr_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_sink_cstr_MT_D): $(PROJ_EXAMPLES_DIR)\example.sink.c_string\example.sink.c_string.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.sink.c_string\example.sink.c_string.cpp

$(TARG_EX_sink_cstr_DLL_D):    \
		$(OBJ_EX_sink_cstr_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARG_BITBUCKET_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_sink_cstr_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_sink_cstr_DLL_D): $(PROJ_EXAMPLES_DIR)\example.sink.c_string\example.sink.c_string.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.sink.c_string\example.sink.c_string.cpp

$(TARG_EX_sink_cstr_DLL_R):    \
		$(OBJ_EX_sink_cstr_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARG_BITBUCKET_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_sink_cstr_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_sink_cstr_DLL_R): $(PROJ_EXAMPLES_DIR)\example.sink.c_string\example.sink.c_string.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.sink.c_string\example.sink.c_string.cpp

$(TARG_EX_sink_cstr_MT_R):    \
		$(OBJ_EX_sink_cstr_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARG_BITBUCKET_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_sink_cstr_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_sink_cstr_MT_R): $(PROJ_EXAMPLES_DIR)\example.sink.c_string\example.sink.c_string.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.sink.c_string\example.sink.c_string.cpp

$(TARG_EX_sink_ODS_MT_D):    \
		$(OBJ_EX_sink_ODS_MT_D)\
		$(LIB_CORE_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_sink_ODS_MT_D)\
		$(LIB_CORE_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_sink_ODS_MT_D): $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp

$(TARG_EX_sink_ODS_MT_D_W):    \
		$(OBJ_EX_sink_ODS_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_EX_sink_ODS_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_EX_sink_ODS_MT_D_W): $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp

$(TARG_EX_sink_ODS_DLL_D):    \
		$(OBJ_EX_sink_ODS_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_sink_ODS_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_sink_ODS_DLL_D): $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp

$(TARG_EX_sink_ODS_DLL_D_W):    \
		$(OBJ_EX_sink_ODS_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_EX_sink_ODS_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_EX_sink_ODS_DLL_D_W): $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp

$(TARG_EX_sink_ODS_DLL_R):    \
		$(OBJ_EX_sink_ODS_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_sink_ODS_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_sink_ODS_DLL_R): $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp

$(TARG_EX_sink_ODS_DLL_R_W):    \
		$(OBJ_EX_sink_ODS_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_EX_sink_ODS_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_EX_sink_ODS_DLL_R_W): $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp

$(TARG_EX_sink_ODS_MT_R):    \
		$(OBJ_EX_sink_ODS_MT_R)\
		$(LIB_CORE_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_sink_ODS_MT_R)\
		$(LIB_CORE_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_sink_ODS_MT_R): $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp

$(TARG_EX_sink_ODS_MT_R_W):    \
		$(OBJ_EX_sink_ODS_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_EX_sink_ODS_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_EX_sink_ODS_MT_R_W): $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_EXAMPLES_DIR)\example.sink.OutputDebugString\example.sink.OutputDebugString.cpp

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
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_snk_a_b_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_snk_a_b_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp

$(TARG_TEST_COMP_snk_a_b_MT_D_W):    \
		$(OBJ_TEST_COMP_snk_a_b_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_COMP_snk_a_b_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_COMP_snk_a_b_MT_D_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp

$(TARG_TEST_COMP_snk_a_b_DLL_D):    \
		$(OBJ_TEST_COMP_snk_a_b_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_COMP_snk_a_b_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_COMP_snk_a_b_DLL_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp

$(TARG_TEST_COMP_snk_a_b_DLL_D_W):    \
		$(OBJ_TEST_COMP_snk_a_b_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_COMP_snk_a_b_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_COMP_snk_a_b_DLL_D_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp

$(TARG_TEST_COMP_snk_a_b_DLL_R):    \
		$(OBJ_TEST_COMP_snk_a_b_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_COMP_snk_a_b_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_COMP_snk_a_b_DLL_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp

$(TARG_TEST_COMP_snk_a_b_DLL_R_W):    \
		$(OBJ_TEST_COMP_snk_a_b_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_COMP_snk_a_b_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_COMP_snk_a_b_DLL_R_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp

$(TARG_TEST_COMP_snk_a_b_MT_R):    \
		$(OBJ_TEST_COMP_snk_a_b_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_snk_a_b_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_snk_a_b_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp

$(TARG_TEST_COMP_snk_a_b_MT_R_W):    \
		$(OBJ_TEST_COMP_snk_a_b_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_COMP_snk_a_b_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_COMP_snk_a_b_MT_R_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.auto_buffer\test.component.sink.auto_buffer.cpp

$(TARG_TEST_COMP_file_MT_D):    \
		$(OBJ_TEST_COMP_file_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_file_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_file_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp

$(TARG_TEST_COMP_file_MT_D_W):    \
		$(OBJ_TEST_COMP_file_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_COMP_file_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_COMP_file_MT_D_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp

$(TARG_TEST_COMP_file_DLL_D):    \
		$(OBJ_TEST_COMP_file_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_COMP_file_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_COMP_file_DLL_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp

$(TARG_TEST_COMP_file_DLL_D_W):    \
		$(OBJ_TEST_COMP_file_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_COMP_file_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_COMP_file_DLL_D_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp

$(TARG_TEST_COMP_file_DLL_R):    \
		$(OBJ_TEST_COMP_file_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_COMP_file_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_COMP_file_DLL_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp

$(TARG_TEST_COMP_file_DLL_R_W):    \
		$(OBJ_TEST_COMP_file_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_COMP_file_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_COMP_file_DLL_R_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp

$(TARG_TEST_COMP_file_MT_R):    \
		$(OBJ_TEST_COMP_file_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_file_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_file_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp

$(TARG_TEST_COMP_file_MT_R_W):    \
		$(OBJ_TEST_COMP_file_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_COMP_file_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_COMP_file_MT_R_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.FILE\test.component.FILE.cpp

$(TARG_TEST_COMP_fmt_sink_MT_D):    \
		$(OBJ_TEST_COMP_fmt_sink_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_fmt_sink_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_fmt_sink_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp

$(TARG_TEST_COMP_fmt_sink_MT_D_W):    \
		$(OBJ_TEST_COMP_fmt_sink_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_COMP_fmt_sink_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_COMP_fmt_sink_MT_D_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp

$(TARG_TEST_COMP_fmt_sink_DLL_D):    \
		$(OBJ_TEST_COMP_fmt_sink_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_COMP_fmt_sink_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_COMP_fmt_sink_DLL_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp

$(TARG_TEST_COMP_fmt_sink_DLL_D_W):    \
		$(OBJ_TEST_COMP_fmt_sink_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_COMP_fmt_sink_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_COMP_fmt_sink_DLL_D_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp

$(TARG_TEST_COMP_fmt_sink_DLL_R):    \
		$(OBJ_TEST_COMP_fmt_sink_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_COMP_fmt_sink_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_COMP_fmt_sink_DLL_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp

$(TARG_TEST_COMP_fmt_sink_DLL_R_W):    \
		$(OBJ_TEST_COMP_fmt_sink_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_COMP_fmt_sink_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_COMP_fmt_sink_DLL_R_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp

$(TARG_TEST_COMP_fmt_sink_MT_R):    \
		$(OBJ_TEST_COMP_fmt_sink_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_fmt_sink_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_fmt_sink_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp

$(TARG_TEST_COMP_fmt_sink_MT_R_W):    \
		$(OBJ_TEST_COMP_fmt_sink_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_COMP_fmt_sink_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_COMP_fmt_sink_MT_R_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.fmt\test.component.sink.string.fmt.cpp

$(TARG_TEST_COMP_write_sink_MT_D):    \
		$(OBJ_TEST_COMP_write_sink_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_write_sink_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_write_sink_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp

$(TARG_TEST_COMP_write_sink_MT_D_W):    \
		$(OBJ_TEST_COMP_write_sink_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_COMP_write_sink_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_COMP_write_sink_MT_D_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp

$(TARG_TEST_COMP_write_sink_DLL_D):    \
		$(OBJ_TEST_COMP_write_sink_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_COMP_write_sink_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_COMP_write_sink_DLL_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp

$(TARG_TEST_COMP_write_sink_DLL_D_W):    \
		$(OBJ_TEST_COMP_write_sink_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_COMP_write_sink_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_COMP_write_sink_DLL_D_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp

$(TARG_TEST_COMP_write_sink_DLL_R):    \
		$(OBJ_TEST_COMP_write_sink_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_COMP_write_sink_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_COMP_write_sink_DLL_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp

$(TARG_TEST_COMP_write_sink_DLL_R_W):    \
		$(OBJ_TEST_COMP_write_sink_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_COMP_write_sink_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_COMP_write_sink_DLL_R_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp

$(TARG_TEST_COMP_write_sink_MT_R):    \
		$(OBJ_TEST_COMP_write_sink_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_write_sink_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_write_sink_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp

$(TARG_TEST_COMP_write_sink_MT_R_W):    \
		$(OBJ_TEST_COMP_write_sink_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_COMP_write_sink_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_COMP_write_sink_MT_R_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.string.write\test.component.sink.string.write.cpp

$(TARG_TEST_COMP_x_1_MT_D):    \
		$(OBJ_TEST_COMP_x_1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_x_1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_x_1_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp

$(TARG_TEST_COMP_x_1_MT_D_W):    \
		$(OBJ_TEST_COMP_x_1_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_COMP_x_1_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_COMP_x_1_MT_D_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp

$(TARG_TEST_COMP_x_1_DLL_D):    \
		$(OBJ_TEST_COMP_x_1_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_COMP_x_1_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_COMP_x_1_DLL_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp

$(TARG_TEST_COMP_x_1_DLL_D_W):    \
		$(OBJ_TEST_COMP_x_1_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_COMP_x_1_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_COMP_x_1_DLL_D_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp

$(TARG_TEST_COMP_x_1_DLL_R):    \
		$(OBJ_TEST_COMP_x_1_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_COMP_x_1_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_COMP_x_1_DLL_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp

$(TARG_TEST_COMP_x_1_DLL_R_W):    \
		$(OBJ_TEST_COMP_x_1_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_COMP_x_1_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_COMP_x_1_DLL_R_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp

$(TARG_TEST_COMP_x_1_MT_R):    \
		$(OBJ_TEST_COMP_x_1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_x_1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_x_1_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp

$(TARG_TEST_COMP_x_1_MT_R_W):    \
		$(OBJ_TEST_COMP_x_1_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_COMP_x_1_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_COMP_x_1_MT_R_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.format_specification_defect_exceptions\test.component.format_specification_defect_exceptions.cpp

$(TARG_TEST_COMP_null_sink_MT_D):    \
		$(OBJ_TEST_COMP_null_sink_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_null_sink_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_null_sink_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp

$(TARG_TEST_COMP_null_sink_MT_D_W):    \
		$(OBJ_TEST_COMP_null_sink_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_COMP_null_sink_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_COMP_null_sink_MT_D_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp

$(TARG_TEST_COMP_null_sink_DLL_D):    \
		$(OBJ_TEST_COMP_null_sink_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_COMP_null_sink_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_COMP_null_sink_DLL_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp

$(TARG_TEST_COMP_null_sink_DLL_D_W):    \
		$(OBJ_TEST_COMP_null_sink_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_COMP_null_sink_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_COMP_null_sink_DLL_D_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp

$(TARG_TEST_COMP_null_sink_DLL_R):    \
		$(OBJ_TEST_COMP_null_sink_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_COMP_null_sink_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_COMP_null_sink_DLL_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp

$(TARG_TEST_COMP_null_sink_DLL_R_W):    \
		$(OBJ_TEST_COMP_null_sink_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_COMP_null_sink_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_COMP_null_sink_DLL_R_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp

$(TARG_TEST_COMP_null_sink_MT_R):    \
		$(OBJ_TEST_COMP_null_sink_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_null_sink_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_null_sink_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp

$(TARG_TEST_COMP_null_sink_MT_R_W):    \
		$(OBJ_TEST_COMP_null_sink_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_COMP_null_sink_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_COMP_null_sink_MT_R_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.null\test.component.sink.null.cpp

$(TARG_TEST_COMP_ins_hex_MT_D):    \
		$(OBJ_TEST_COMP_ins_hex_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_ins_hex_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_ins_hex_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp

$(TARG_TEST_COMP_ins_hex_MT_D_W):    \
		$(OBJ_TEST_COMP_ins_hex_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_COMP_ins_hex_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_COMP_ins_hex_MT_D_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp

$(TARG_TEST_COMP_ins_hex_DLL_D):    \
		$(OBJ_TEST_COMP_ins_hex_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_COMP_ins_hex_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_COMP_ins_hex_DLL_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp

$(TARG_TEST_COMP_ins_hex_DLL_D_W):    \
		$(OBJ_TEST_COMP_ins_hex_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_COMP_ins_hex_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_COMP_ins_hex_DLL_D_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp

$(TARG_TEST_COMP_ins_hex_DLL_R):    \
		$(OBJ_TEST_COMP_ins_hex_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_COMP_ins_hex_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_COMP_ins_hex_DLL_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp

$(TARG_TEST_COMP_ins_hex_DLL_R_W):    \
		$(OBJ_TEST_COMP_ins_hex_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_COMP_ins_hex_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_COMP_ins_hex_DLL_R_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp

$(TARG_TEST_COMP_ins_hex_MT_R):    \
		$(OBJ_TEST_COMP_ins_hex_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_ins_hex_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_ins_hex_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp

$(TARG_TEST_COMP_ins_hex_MT_R_W):    \
		$(OBJ_TEST_COMP_ins_hex_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_COMP_ins_hex_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_COMP_ins_hex_MT_R_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.hex\test.component.inserter.hex.cpp

$(TARG_TEST_COMP_ins_int_MT_D):    \
		$(OBJ_TEST_COMP_ins_int_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_ins_int_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_ins_int_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp

$(TARG_TEST_COMP_ins_int_MT_D_W):    \
		$(OBJ_TEST_COMP_ins_int_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_COMP_ins_int_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_COMP_ins_int_MT_D_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp

$(TARG_TEST_COMP_ins_int_DLL_D):    \
		$(OBJ_TEST_COMP_ins_int_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_COMP_ins_int_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_COMP_ins_int_DLL_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp

$(TARG_TEST_COMP_ins_int_DLL_D_W):    \
		$(OBJ_TEST_COMP_ins_int_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_COMP_ins_int_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_COMP_ins_int_DLL_D_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp

$(TARG_TEST_COMP_ins_int_DLL_R):    \
		$(OBJ_TEST_COMP_ins_int_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_COMP_ins_int_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_COMP_ins_int_DLL_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp

$(TARG_TEST_COMP_ins_int_DLL_R_W):    \
		$(OBJ_TEST_COMP_ins_int_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_COMP_ins_int_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_COMP_ins_int_DLL_R_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp

$(TARG_TEST_COMP_ins_int_MT_R):    \
		$(OBJ_TEST_COMP_ins_int_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_ins_int_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_ins_int_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp

$(TARG_TEST_COMP_ins_int_MT_R_W):    \
		$(OBJ_TEST_COMP_ins_int_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_COMP_ins_int_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_COMP_ins_int_MT_R_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.integer\test.component.inserter.integer.cpp

$(TARG_TEST_COMP_ins_real_MT_D):    \
		$(OBJ_TEST_COMP_ins_real_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_ins_real_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_ins_real_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp

$(TARG_TEST_COMP_ins_real_MT_D_W):    \
		$(OBJ_TEST_COMP_ins_real_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_COMP_ins_real_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_COMP_ins_real_MT_D_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp

$(TARG_TEST_COMP_ins_real_DLL_D):    \
		$(OBJ_TEST_COMP_ins_real_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_COMP_ins_real_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_COMP_ins_real_DLL_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp

$(TARG_TEST_COMP_ins_real_DLL_D_W):    \
		$(OBJ_TEST_COMP_ins_real_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_COMP_ins_real_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_COMP_ins_real_DLL_D_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp

$(TARG_TEST_COMP_ins_real_DLL_R):    \
		$(OBJ_TEST_COMP_ins_real_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_COMP_ins_real_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_COMP_ins_real_DLL_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp

$(TARG_TEST_COMP_ins_real_DLL_R_W):    \
		$(OBJ_TEST_COMP_ins_real_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_COMP_ins_real_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_COMP_ins_real_DLL_R_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp

$(TARG_TEST_COMP_ins_real_MT_R):    \
		$(OBJ_TEST_COMP_ins_real_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_ins_real_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_ins_real_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp

$(TARG_TEST_COMP_ins_real_MT_R_W):    \
		$(OBJ_TEST_COMP_ins_real_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_COMP_ins_real_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_COMP_ins_real_MT_R_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserter.real\test.component.inserter.real.cpp

$(TARG_TEST_COMP_itr_fmt_MT_D):    \
		$(OBJ_TEST_COMP_itr_fmt_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_itr_fmt_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_itr_fmt_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp

$(TARG_TEST_COMP_itr_fmt_MT_D_W):    \
		$(OBJ_TEST_COMP_itr_fmt_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_COMP_itr_fmt_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_COMP_itr_fmt_MT_D_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp

$(TARG_TEST_COMP_itr_fmt_DLL_D):    \
		$(OBJ_TEST_COMP_itr_fmt_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_COMP_itr_fmt_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_COMP_itr_fmt_DLL_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp

$(TARG_TEST_COMP_itr_fmt_DLL_D_W):    \
		$(OBJ_TEST_COMP_itr_fmt_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_COMP_itr_fmt_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_COMP_itr_fmt_DLL_D_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp

$(TARG_TEST_COMP_itr_fmt_DLL_R):    \
		$(OBJ_TEST_COMP_itr_fmt_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_COMP_itr_fmt_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_COMP_itr_fmt_DLL_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp

$(TARG_TEST_COMP_itr_fmt_DLL_R_W):    \
		$(OBJ_TEST_COMP_itr_fmt_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_COMP_itr_fmt_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_COMP_itr_fmt_DLL_R_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp

$(TARG_TEST_COMP_itr_fmt_MT_R):    \
		$(OBJ_TEST_COMP_itr_fmt_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_itr_fmt_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_itr_fmt_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp

$(TARG_TEST_COMP_itr_fmt_MT_R_W):    \
		$(OBJ_TEST_COMP_itr_fmt_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_COMP_itr_fmt_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_COMP_itr_fmt_MT_R_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.iterators.format_iterator\test.component.iterators.format_iterator.cpp

$(TARG_TEST_COMP_snk_ostm_MT_D):    \
		$(OBJ_TEST_COMP_snk_ostm_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_snk_ostm_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_snk_ostm_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp

$(TARG_TEST_COMP_snk_ostm_MT_D_W):    \
		$(OBJ_TEST_COMP_snk_ostm_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_COMP_snk_ostm_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_COMP_snk_ostm_MT_D_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp

$(TARG_TEST_COMP_snk_ostm_DLL_D):    \
		$(OBJ_TEST_COMP_snk_ostm_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_COMP_snk_ostm_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_COMP_snk_ostm_DLL_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp

$(TARG_TEST_COMP_snk_ostm_DLL_D_W):    \
		$(OBJ_TEST_COMP_snk_ostm_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_COMP_snk_ostm_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_COMP_snk_ostm_DLL_D_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp

$(TARG_TEST_COMP_snk_ostm_DLL_R):    \
		$(OBJ_TEST_COMP_snk_ostm_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_COMP_snk_ostm_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_COMP_snk_ostm_DLL_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp

$(TARG_TEST_COMP_snk_ostm_DLL_R_W):    \
		$(OBJ_TEST_COMP_snk_ostm_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_COMP_snk_ostm_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_COMP_snk_ostm_DLL_R_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp

$(TARG_TEST_COMP_snk_ostm_MT_R):    \
		$(OBJ_TEST_COMP_snk_ostm_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_snk_ostm_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_snk_ostm_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp

$(TARG_TEST_COMP_snk_ostm_MT_R_W):    \
		$(OBJ_TEST_COMP_snk_ostm_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_COMP_snk_ostm_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_COMP_snk_ostm_MT_R_W): $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.sink.ostream\test.component.sink.ostream.cpp

##############################
# Performance Tests

$(TARG_TEST_PERF_scen1_MT_D):    \
		$(OBJ_TEST_PERF_scen1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_PERF_scen1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_PERF_scen1_MT_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp

$(TARG_TEST_PERF_scen1_MT_D_W):    \
		$(OBJ_TEST_PERF_scen1_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_LOKI_SFMT_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_PERF_scen1_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_LOKI_SFMT_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_PERF_scen1_MT_D_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp

$(TARG_TEST_PERF_scen1_DLL_D):    \
		$(OBJ_TEST_PERF_scen1_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_LOKI_SFMT_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_PERF_scen1_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_LOKI_SFMT_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_PERF_scen1_DLL_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp

$(TARG_TEST_PERF_scen1_DLL_D_W):    \
		$(OBJ_TEST_PERF_scen1_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_LOKI_SFMT_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_PERF_scen1_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_LOKI_SFMT_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_PERF_scen1_DLL_D_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp

$(TARG_TEST_PERF_scen1_DLL_R):    \
		$(OBJ_TEST_PERF_scen1_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_LOKI_SFMT_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_PERF_scen1_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_LOKI_SFMT_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_PERF_scen1_DLL_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp

$(TARG_TEST_PERF_scen1_DLL_R_W):    \
		$(OBJ_TEST_PERF_scen1_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_LOKI_SFMT_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_PERF_scen1_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_LOKI_SFMT_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_PERF_scen1_DLL_R_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp

$(TARG_TEST_PERF_scen1_MT_R):    \
		$(OBJ_TEST_PERF_scen1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_PERF_scen1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_PERF_scen1_MT_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp

$(TARG_TEST_PERF_scen1_MT_R_W):    \
		$(OBJ_TEST_PERF_scen1_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_LOKI_SFMT_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_PERF_scen1_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_LOKI_SFMT_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_PERF_scen1_MT_R_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.overload.ex.1\test.performance.overload.ex.1.cpp

$(TARG_TEST_PERF_scen2_MT_D):    \
		$(OBJ_TEST_PERF_scen2_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_PERF_scen2_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_PERF_scen2_MT_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp

$(TARG_TEST_PERF_scen2_MT_D_W):    \
		$(OBJ_TEST_PERF_scen2_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_LOKI_SFMT_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_PERF_scen2_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_LOKI_SFMT_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_PERF_scen2_MT_D_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp

$(TARG_TEST_PERF_scen2_DLL_D):    \
		$(OBJ_TEST_PERF_scen2_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_LOKI_SFMT_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_PERF_scen2_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_LOKI_SFMT_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_PERF_scen2_DLL_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp

$(TARG_TEST_PERF_scen2_DLL_D_W):    \
		$(OBJ_TEST_PERF_scen2_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_LOKI_SFMT_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_PERF_scen2_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_LOKI_SFMT_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_PERF_scen2_DLL_D_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp

$(TARG_TEST_PERF_scen2_DLL_R):    \
		$(OBJ_TEST_PERF_scen2_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_LOKI_SFMT_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_PERF_scen2_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_LOKI_SFMT_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_PERF_scen2_DLL_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp

$(TARG_TEST_PERF_scen2_DLL_R_W):    \
		$(OBJ_TEST_PERF_scen2_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_LOKI_SFMT_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_PERF_scen2_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_LOKI_SFMT_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_PERF_scen2_DLL_R_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp

$(TARG_TEST_PERF_scen2_MT_R):    \
		$(OBJ_TEST_PERF_scen2_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_PERF_scen2_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_PERF_scen2_MT_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp

$(TARG_TEST_PERF_scen2_MT_R_W):    \
		$(OBJ_TEST_PERF_scen2_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_LOKI_SFMT_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_PERF_scen2_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_LOKI_SFMT_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_PERF_scen2_MT_R_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.name_age_height\test.performance.name_age_height.cpp

$(TARG_TEST_PERF_scen3_MT_D):    \
		$(OBJ_TEST_PERF_scen3_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_PERF_scen3_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_PERF_scen3_MT_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp

$(TARG_TEST_PERF_scen3_MT_D_W):    \
		$(OBJ_TEST_PERF_scen3_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_LOKI_SFMT_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_PERF_scen3_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_LOKI_SFMT_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_PERF_scen3_MT_D_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp

$(TARG_TEST_PERF_scen3_DLL_D):    \
		$(OBJ_TEST_PERF_scen3_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_LOKI_SFMT_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_PERF_scen3_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_LOKI_SFMT_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_PERF_scen3_DLL_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp

$(TARG_TEST_PERF_scen3_DLL_D_W):    \
		$(OBJ_TEST_PERF_scen3_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_LOKI_SFMT_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_PERF_scen3_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_LOKI_SFMT_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_PERF_scen3_DLL_D_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp

$(TARG_TEST_PERF_scen3_DLL_R):    \
		$(OBJ_TEST_PERF_scen3_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_LOKI_SFMT_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_PERF_scen3_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_LOKI_SFMT_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_PERF_scen3_DLL_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp

$(TARG_TEST_PERF_scen3_DLL_R_W):    \
		$(OBJ_TEST_PERF_scen3_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_LOKI_SFMT_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_PERF_scen3_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_LOKI_SFMT_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_PERF_scen3_DLL_R_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp

$(TARG_TEST_PERF_scen3_MT_R):    \
		$(OBJ_TEST_PERF_scen3_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_PERF_scen3_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_PERF_scen3_MT_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp

$(TARG_TEST_PERF_scen3_MT_R_W):    \
		$(OBJ_TEST_PERF_scen3_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_LOKI_SFMT_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_PERF_scen3_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_LOKI_SFMT_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_PERF_scen3_MT_R_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_integer\test.performance.one_integer.cpp

$(TARG_TEST_PERF_scen4_MT_D):    \
		$(OBJ_TEST_PERF_scen4_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_PERF_scen4_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_PERF_scen4_MT_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp

$(TARG_TEST_PERF_scen4_MT_D_W):    \
		$(OBJ_TEST_PERF_scen4_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_LOKI_SFMT_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_PERF_scen4_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_LOKI_SFMT_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_PERF_scen4_MT_D_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp

$(TARG_TEST_PERF_scen4_DLL_D):    \
		$(OBJ_TEST_PERF_scen4_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_LOKI_SFMT_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_PERF_scen4_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_LOKI_SFMT_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_PERF_scen4_DLL_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp

$(TARG_TEST_PERF_scen4_DLL_D_W):    \
		$(OBJ_TEST_PERF_scen4_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_LOKI_SFMT_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_PERF_scen4_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_LOKI_SFMT_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_PERF_scen4_DLL_D_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp

$(TARG_TEST_PERF_scen4_DLL_R):    \
		$(OBJ_TEST_PERF_scen4_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_LOKI_SFMT_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_PERF_scen4_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_LOKI_SFMT_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_PERF_scen4_DLL_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp

$(TARG_TEST_PERF_scen4_DLL_R_W):    \
		$(OBJ_TEST_PERF_scen4_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_LOKI_SFMT_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_PERF_scen4_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_LOKI_SFMT_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_PERF_scen4_DLL_R_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp

$(TARG_TEST_PERF_scen4_MT_R):    \
		$(OBJ_TEST_PERF_scen4_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_PERF_scen4_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_PERF_scen4_MT_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp

$(TARG_TEST_PERF_scen4_MT_R_W):    \
		$(OBJ_TEST_PERF_scen4_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_LOKI_SFMT_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_PERF_scen4_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_LOKI_SFMT_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_PERF_scen4_MT_R_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.one_pointer\test.performance.one_pointer.cpp

$(TARG_TEST_PERF_scen5_MT_D):    \
		$(OBJ_TEST_PERF_scen5_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_PERF_scen5_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_PERF_scen5_MT_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp

$(TARG_TEST_PERF_scen5_MT_D_W):    \
		$(OBJ_TEST_PERF_scen5_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_LOKI_SFMT_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_PERF_scen5_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_LOKI_SFMT_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_PERF_scen5_MT_D_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp

$(TARG_TEST_PERF_scen5_DLL_D):    \
		$(OBJ_TEST_PERF_scen5_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_LOKI_SFMT_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_PERF_scen5_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_LOKI_SFMT_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_PERF_scen5_DLL_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp

$(TARG_TEST_PERF_scen5_DLL_D_W):    \
		$(OBJ_TEST_PERF_scen5_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_LOKI_SFMT_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_PERF_scen5_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_LOKI_SFMT_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_PERF_scen5_DLL_D_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp

$(TARG_TEST_PERF_scen5_DLL_R):    \
		$(OBJ_TEST_PERF_scen5_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_LOKI_SFMT_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_PERF_scen5_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_LOKI_SFMT_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_PERF_scen5_DLL_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp

$(TARG_TEST_PERF_scen5_DLL_R_W):    \
		$(OBJ_TEST_PERF_scen5_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_LOKI_SFMT_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_PERF_scen5_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_LOKI_SFMT_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_PERF_scen5_DLL_R_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp

$(TARG_TEST_PERF_scen5_MT_R):    \
		$(OBJ_TEST_PERF_scen5_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_PERF_scen5_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_PERF_scen5_MT_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp

$(TARG_TEST_PERF_scen5_MT_R_W):    \
		$(OBJ_TEST_PERF_scen5_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_LOKI_SFMT_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_PERF_scen5_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_LOKI_SFMT_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_PERF_scen5_MT_R_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.scenario1\test.performance.scenario1.cpp

$(TARG_TEST_PERF_scen6_MT_D):    \
		$(OBJ_TEST_PERF_scen6_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_PERF_scen6_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_PERF_scen6_MT_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp

$(TARG_TEST_PERF_scen6_MT_D_W):    \
		$(OBJ_TEST_PERF_scen6_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_LOKI_SFMT_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_PERF_scen6_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_LOKI_SFMT_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_PERF_scen6_MT_D_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp

$(TARG_TEST_PERF_scen6_DLL_D):    \
		$(OBJ_TEST_PERF_scen6_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_LOKI_SFMT_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_PERF_scen6_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_LOKI_SFMT_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_PERF_scen6_DLL_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp

$(TARG_TEST_PERF_scen6_DLL_D_W):    \
		$(OBJ_TEST_PERF_scen6_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_LOKI_SFMT_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_PERF_scen6_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_LOKI_SFMT_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_PERF_scen6_DLL_D_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp

$(TARG_TEST_PERF_scen6_DLL_R):    \
		$(OBJ_TEST_PERF_scen6_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_LOKI_SFMT_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_PERF_scen6_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_LOKI_SFMT_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_PERF_scen6_DLL_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp

$(TARG_TEST_PERF_scen6_DLL_R_W):    \
		$(OBJ_TEST_PERF_scen6_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_LOKI_SFMT_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_PERF_scen6_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_LOKI_SFMT_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_PERF_scen6_DLL_R_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp

$(TARG_TEST_PERF_scen6_MT_R):    \
		$(OBJ_TEST_PERF_scen6_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_PERF_scen6_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_PERF_scen6_MT_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp

$(TARG_TEST_PERF_scen6_MT_R_W):    \
		$(OBJ_TEST_PERF_scen6_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_LOKI_SFMT_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_PERF_scen6_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_LOKI_SFMT_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_PERF_scen6_MT_R_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.ten_strings_twice\test.performance.ten_strings_twice.cpp

$(TARG_TEST_PERF_scen7_MT_D):    \
		$(OBJ_TEST_PERF_scen7_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_PERF_scen7_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_PERF_scen7_MT_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp

$(TARG_TEST_PERF_scen7_MT_D_W):    \
		$(OBJ_TEST_PERF_scen7_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_LOKI_SFMT_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_PERF_scen7_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_LOKI_SFMT_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_PERF_scen7_MT_D_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp

$(TARG_TEST_PERF_scen7_DLL_D):    \
		$(OBJ_TEST_PERF_scen7_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_LOKI_SFMT_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_PERF_scen7_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_LOKI_SFMT_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_PERF_scen7_DLL_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp

$(TARG_TEST_PERF_scen7_DLL_D_W):    \
		$(OBJ_TEST_PERF_scen7_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_LOKI_SFMT_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_PERF_scen7_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_LOKI_SFMT_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_PERF_scen7_DLL_D_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp

$(TARG_TEST_PERF_scen7_DLL_R):    \
		$(OBJ_TEST_PERF_scen7_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_LOKI_SFMT_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_PERF_scen7_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_LOKI_SFMT_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_PERF_scen7_DLL_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp

$(TARG_TEST_PERF_scen7_DLL_R_W):    \
		$(OBJ_TEST_PERF_scen7_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_LOKI_SFMT_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_PERF_scen7_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_LOKI_SFMT_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_PERF_scen7_DLL_R_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp

$(TARG_TEST_PERF_scen7_MT_R):    \
		$(OBJ_TEST_PERF_scen7_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_PERF_scen7_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_PERF_scen7_MT_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp

$(TARG_TEST_PERF_scen7_MT_R_W):    \
		$(OBJ_TEST_PERF_scen7_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_LOKI_SFMT_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_PERF_scen7_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_LOKI_SFMT_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_PERF_scen7_MT_R_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.three_strings_one_integer\test.performance.three_strings_one_integer.cpp

!ifdef BOOST
$(TARG_TEST_PERF_scen8_MT_D):    \
		$(OBJ_TEST_PERF_scen8_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_PERF_scen8_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_LOKI_SFMT_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_PERF_scen8_MT_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp

$(TARG_TEST_PERF_scen8_MT_D_W):    \
		$(OBJ_TEST_PERF_scen8_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_LOKI_SFMT_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_PERF_scen8_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_LOKI_SFMT_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_PERF_scen8_MT_D_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp

$(TARG_TEST_PERF_scen8_DLL_D):    \
		$(OBJ_TEST_PERF_scen8_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_LOKI_SFMT_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_PERF_scen8_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_LOKI_SFMT_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_PERF_scen8_DLL_D): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp

$(TARG_TEST_PERF_scen8_DLL_D_W):    \
		$(OBJ_TEST_PERF_scen8_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_LOKI_SFMT_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_PERF_scen8_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_LOKI_SFMT_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_PERF_scen8_DLL_D_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp

$(TARG_TEST_PERF_scen8_DLL_R):    \
		$(OBJ_TEST_PERF_scen8_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_LOKI_SFMT_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_PERF_scen8_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_LOKI_SFMT_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_PERF_scen8_DLL_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp

$(TARG_TEST_PERF_scen8_DLL_R_W):    \
		$(OBJ_TEST_PERF_scen8_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_LOKI_SFMT_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_PERF_scen8_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_LOKI_SFMT_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_PERF_scen8_DLL_R_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp

$(TARG_TEST_PERF_scen8_MT_R):    \
		$(OBJ_TEST_PERF_scen8_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_PERF_scen8_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_LOKI_SFMT_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_PERF_scen8_MT_R): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp

$(TARG_TEST_PERF_scen8_MT_R_W):    \
		$(OBJ_TEST_PERF_scen8_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_LOKI_SFMT_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_PERF_scen8_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_LOKI_SFMT_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_PERF_scen8_MT_R_W): $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.boost.karma\test.performance.boost.karma.cpp

!endif # BOOST
##############################
# Scratch Tests

$(TARG_TEST_SCRT_file_MT_D):    \
		$(OBJ_TEST_SCRT_file_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_SCRT_file_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_SCRT_file_MT_D): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp

$(TARG_TEST_SCRT_file_MT_D_W):    \
		$(OBJ_TEST_SCRT_file_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_SCRT_file_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_SCRT_file_MT_D_W): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp

$(TARG_TEST_SCRT_file_DLL_D):    \
		$(OBJ_TEST_SCRT_file_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_SCRT_file_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_SCRT_file_DLL_D): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp

$(TARG_TEST_SCRT_file_DLL_D_W):    \
		$(OBJ_TEST_SCRT_file_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_SCRT_file_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_SCRT_file_DLL_D_W): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp

$(TARG_TEST_SCRT_file_DLL_R):    \
		$(OBJ_TEST_SCRT_file_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_SCRT_file_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_SCRT_file_DLL_R): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp

$(TARG_TEST_SCRT_file_DLL_R_W):    \
		$(OBJ_TEST_SCRT_file_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_SCRT_file_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_SCRT_file_DLL_R_W): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp

$(TARG_TEST_SCRT_file_MT_R):    \
		$(OBJ_TEST_SCRT_file_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_SCRT_file_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_SCRT_file_MT_R): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp

$(TARG_TEST_SCRT_file_MT_R_W):    \
		$(OBJ_TEST_SCRT_file_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_SCRT_file_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_SCRT_file_MT_R_W): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.FILE\test.scratch.FILE.cpp

$(TARG_TEST_SCRT_speech_MT_D):    \
		$(OBJ_TEST_SCRT_speech_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_SCRT_speech_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_SCRT_speech_MT_D): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp

$(TARG_TEST_SCRT_speech_MT_D_W):    \
		$(OBJ_TEST_SCRT_speech_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_SCRT_speech_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_SCRT_speech_MT_D_W): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp

$(TARG_TEST_SCRT_speech_DLL_D):    \
		$(OBJ_TEST_SCRT_speech_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_SCRT_speech_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_SCRT_speech_DLL_D): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp

$(TARG_TEST_SCRT_speech_DLL_D_W):    \
		$(OBJ_TEST_SCRT_speech_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_SCRT_speech_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_SCRT_speech_DLL_D_W): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp

$(TARG_TEST_SCRT_speech_DLL_R):    \
		$(OBJ_TEST_SCRT_speech_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_SCRT_speech_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_SCRT_speech_DLL_R): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp

$(TARG_TEST_SCRT_speech_DLL_R_W):    \
		$(OBJ_TEST_SCRT_speech_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_SCRT_speech_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_SCRT_speech_DLL_R_W): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp

$(TARG_TEST_SCRT_speech_MT_R):    \
		$(OBJ_TEST_SCRT_speech_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_SCRT_speech_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_SCRT_speech_MT_R): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp

$(TARG_TEST_SCRT_speech_MT_R_W):    \
		$(OBJ_TEST_SCRT_speech_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_SCRT_speech_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_SCRT_speech_MT_R_W): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.speech\test.scratch.speech.cpp

##############################
# Unit Tests


$(TARG_TEST_UNIT_api_acsllen_MT_D):    \
		$(OBJ_TEST_UNIT_api_acsllen_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_acsllen_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_api_acsllen_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp

$(TARG_TEST_UNIT_api_acsllen_MT_D_W):    \
		$(OBJ_TEST_UNIT_api_acsllen_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_acsllen_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_UNIT_api_acsllen_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp

$(TARG_TEST_UNIT_api_acsllen_DLL_D):    \
		$(OBJ_TEST_UNIT_api_acsllen_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_acsllen_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_api_acsllen_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp

$(TARG_TEST_UNIT_api_acsllen_DLL_D_W):    \
		$(OBJ_TEST_UNIT_api_acsllen_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_acsllen_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_api_acsllen_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp

$(TARG_TEST_UNIT_api_acsllen_DLL_R):    \
		$(OBJ_TEST_UNIT_api_acsllen_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_acsllen_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_api_acsllen_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp

$(TARG_TEST_UNIT_api_acsllen_DLL_R_W):    \
		$(OBJ_TEST_UNIT_api_acsllen_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_acsllen_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_api_acsllen_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp

$(TARG_TEST_UNIT_api_acsllen_MT_R):    \
		$(OBJ_TEST_UNIT_api_acsllen_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_acsllen_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_api_acsllen_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp

$(TARG_TEST_UNIT_api_acsllen_MT_R_W):    \
		$(OBJ_TEST_UNIT_api_acsllen_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_acsllen_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_UNIT_api_acsllen_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.accum_slice_lens\test.unit.api.accum_slice_lens.cpp

$(TARG_TEST_UNIT_api_crlf_MT_D):    \
		$(OBJ_TEST_UNIT_api_crlf_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_crlf_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_api_crlf_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp

$(TARG_TEST_UNIT_api_crlf_MT_D_W):    \
		$(OBJ_TEST_UNIT_api_crlf_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_crlf_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_UNIT_api_crlf_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp

$(TARG_TEST_UNIT_api_crlf_DLL_D):    \
		$(OBJ_TEST_UNIT_api_crlf_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_crlf_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_api_crlf_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp

$(TARG_TEST_UNIT_api_crlf_DLL_D_W):    \
		$(OBJ_TEST_UNIT_api_crlf_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_crlf_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_api_crlf_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp

$(TARG_TEST_UNIT_api_crlf_DLL_R):    \
		$(OBJ_TEST_UNIT_api_crlf_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_crlf_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_api_crlf_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp

$(TARG_TEST_UNIT_api_crlf_DLL_R_W):    \
		$(OBJ_TEST_UNIT_api_crlf_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_crlf_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_api_crlf_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp

$(TARG_TEST_UNIT_api_crlf_MT_R):    \
		$(OBJ_TEST_UNIT_api_crlf_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_crlf_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_api_crlf_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp

$(TARG_TEST_UNIT_api_crlf_MT_R_W):    \
		$(OBJ_TEST_UNIT_api_crlf_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_crlf_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_UNIT_api_crlf_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.crlf_for_platform\test.unit.api.crlf_for_platform.cpp

$(TARG_TEST_UNIT_api_flrpl_MT_D):    \
		$(OBJ_TEST_UNIT_api_flrpl_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_flrpl_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_api_flrpl_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp

$(TARG_TEST_UNIT_api_flrpl_MT_D_W):    \
		$(OBJ_TEST_UNIT_api_flrpl_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_flrpl_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_UNIT_api_flrpl_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp

$(TARG_TEST_UNIT_api_flrpl_DLL_D):    \
		$(OBJ_TEST_UNIT_api_flrpl_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_flrpl_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_api_flrpl_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp

$(TARG_TEST_UNIT_api_flrpl_DLL_D_W):    \
		$(OBJ_TEST_UNIT_api_flrpl_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_flrpl_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_api_flrpl_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp

$(TARG_TEST_UNIT_api_flrpl_DLL_R):    \
		$(OBJ_TEST_UNIT_api_flrpl_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_flrpl_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_api_flrpl_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp

$(TARG_TEST_UNIT_api_flrpl_DLL_R_W):    \
		$(OBJ_TEST_UNIT_api_flrpl_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_flrpl_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_api_flrpl_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp

$(TARG_TEST_UNIT_api_flrpl_MT_R):    \
		$(OBJ_TEST_UNIT_api_flrpl_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_flrpl_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_api_flrpl_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp

$(TARG_TEST_UNIT_api_flrpl_MT_R_W):    \
		$(OBJ_TEST_UNIT_api_flrpl_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_flrpl_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_UNIT_api_flrpl_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.fill_replacements\test.unit.api.fill_replacements.cpp

$(TARG_TEST_UNIT_api_init_MT_D):    \
		$(OBJ_TEST_UNIT_api_init_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_init_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_api_init_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp

$(TARG_TEST_UNIT_api_init_MT_D_W):    \
		$(OBJ_TEST_UNIT_api_init_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_init_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_UNIT_api_init_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp

$(TARG_TEST_UNIT_api_init_DLL_D):    \
		$(OBJ_TEST_UNIT_api_init_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_init_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_api_init_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp

$(TARG_TEST_UNIT_api_init_DLL_D_W):    \
		$(OBJ_TEST_UNIT_api_init_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_init_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_api_init_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp

$(TARG_TEST_UNIT_api_init_DLL_R):    \
		$(OBJ_TEST_UNIT_api_init_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_init_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_api_init_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp

$(TARG_TEST_UNIT_api_init_DLL_R_W):    \
		$(OBJ_TEST_UNIT_api_init_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_init_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_api_init_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp

$(TARG_TEST_UNIT_api_init_MT_R):    \
		$(OBJ_TEST_UNIT_api_init_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_init_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_api_init_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp

$(TARG_TEST_UNIT_api_init_MT_R_W):    \
		$(OBJ_TEST_UNIT_api_init_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_init_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_UNIT_api_init_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.initialisation\test.unit.api.initialisation.cpp

$(TARG_TEST_UNIT_api_lkptrn_MT_D):    \
		$(OBJ_TEST_UNIT_api_lkptrn_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_lkptrn_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_api_lkptrn_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp

$(TARG_TEST_UNIT_api_lkptrn_MT_D_W):    \
		$(OBJ_TEST_UNIT_api_lkptrn_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_lkptrn_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_UNIT_api_lkptrn_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp

$(TARG_TEST_UNIT_api_lkptrn_DLL_D):    \
		$(OBJ_TEST_UNIT_api_lkptrn_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_lkptrn_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_api_lkptrn_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp

$(TARG_TEST_UNIT_api_lkptrn_DLL_D_W):    \
		$(OBJ_TEST_UNIT_api_lkptrn_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_lkptrn_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_api_lkptrn_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp

$(TARG_TEST_UNIT_api_lkptrn_DLL_R):    \
		$(OBJ_TEST_UNIT_api_lkptrn_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_lkptrn_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_api_lkptrn_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp

$(TARG_TEST_UNIT_api_lkptrn_DLL_R_W):    \
		$(OBJ_TEST_UNIT_api_lkptrn_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_lkptrn_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_api_lkptrn_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp

$(TARG_TEST_UNIT_api_lkptrn_MT_R):    \
		$(OBJ_TEST_UNIT_api_lkptrn_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_lkptrn_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_api_lkptrn_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp

$(TARG_TEST_UNIT_api_lkptrn_MT_R_W):    \
		$(OBJ_TEST_UNIT_api_lkptrn_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_lkptrn_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_UNIT_api_lkptrn_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.lookup_pattern\test.unit.api.lookup_pattern.cpp

$(TARG_TEST_UNIT_api_prsrpl_MT_D):    \
		$(OBJ_TEST_UNIT_api_prsrpl_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_prsrpl_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_api_prsrpl_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp

$(TARG_TEST_UNIT_api_prsrpl_MT_D_W):    \
		$(OBJ_TEST_UNIT_api_prsrpl_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_prsrpl_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_UNIT_api_prsrpl_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp

$(TARG_TEST_UNIT_api_prsrpl_DLL_D):    \
		$(OBJ_TEST_UNIT_api_prsrpl_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_prsrpl_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_api_prsrpl_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp

$(TARG_TEST_UNIT_api_prsrpl_DLL_D_W):    \
		$(OBJ_TEST_UNIT_api_prsrpl_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_prsrpl_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_api_prsrpl_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp

$(TARG_TEST_UNIT_api_prsrpl_DLL_R):    \
		$(OBJ_TEST_UNIT_api_prsrpl_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_prsrpl_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_api_prsrpl_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp

$(TARG_TEST_UNIT_api_prsrpl_DLL_R_W):    \
		$(OBJ_TEST_UNIT_api_prsrpl_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_prsrpl_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_api_prsrpl_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp

$(TARG_TEST_UNIT_api_prsrpl_MT_R):    \
		$(OBJ_TEST_UNIT_api_prsrpl_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_prsrpl_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_api_prsrpl_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp

$(TARG_TEST_UNIT_api_prsrpl_MT_R_W):    \
		$(OBJ_TEST_UNIT_api_prsrpl_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_prsrpl_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_UNIT_api_prsrpl_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.parse_format\test.unit.api.parse_format.cpp

$(TARG_TEST_UNIT_api_illfmdh_MT_D):    \
		$(OBJ_TEST_UNIT_api_illfmdh_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_illfmdh_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_api_illfmdh_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp

$(TARG_TEST_UNIT_api_illfmdh_MT_D_W):    \
		$(OBJ_TEST_UNIT_api_illfmdh_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_illfmdh_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_UNIT_api_illfmdh_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp

$(TARG_TEST_UNIT_api_illfmdh_DLL_D):    \
		$(OBJ_TEST_UNIT_api_illfmdh_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_illfmdh_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_api_illfmdh_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp

$(TARG_TEST_UNIT_api_illfmdh_DLL_D_W):    \
		$(OBJ_TEST_UNIT_api_illfmdh_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_illfmdh_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_api_illfmdh_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp

$(TARG_TEST_UNIT_api_illfmdh_DLL_R):    \
		$(OBJ_TEST_UNIT_api_illfmdh_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_illfmdh_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_api_illfmdh_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp

$(TARG_TEST_UNIT_api_illfmdh_DLL_R_W):    \
		$(OBJ_TEST_UNIT_api_illfmdh_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_illfmdh_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_api_illfmdh_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp

$(TARG_TEST_UNIT_api_illfmdh_MT_R):    \
		$(OBJ_TEST_UNIT_api_illfmdh_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_illfmdh_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_api_illfmdh_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp

$(TARG_TEST_UNIT_api_illfmdh_MT_R_W):    \
		$(OBJ_TEST_UNIT_api_illfmdh_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_illfmdh_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_UNIT_api_illfmdh_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.illformed_handlers\test.unit.api.illformed_handlers.cpp

$(TARG_TEST_UNIT_api_msmtchh_MT_D):    \
		$(OBJ_TEST_UNIT_api_msmtchh_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_msmtchh_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_api_msmtchh_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp

$(TARG_TEST_UNIT_api_msmtchh_MT_D_W):    \
		$(OBJ_TEST_UNIT_api_msmtchh_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_msmtchh_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_UNIT_api_msmtchh_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp

$(TARG_TEST_UNIT_api_msmtchh_DLL_D):    \
		$(OBJ_TEST_UNIT_api_msmtchh_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_msmtchh_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_api_msmtchh_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp

$(TARG_TEST_UNIT_api_msmtchh_DLL_D_W):    \
		$(OBJ_TEST_UNIT_api_msmtchh_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_msmtchh_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_api_msmtchh_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp

$(TARG_TEST_UNIT_api_msmtchh_DLL_R):    \
		$(OBJ_TEST_UNIT_api_msmtchh_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_msmtchh_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_api_msmtchh_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp

$(TARG_TEST_UNIT_api_msmtchh_DLL_R_W):    \
		$(OBJ_TEST_UNIT_api_msmtchh_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_msmtchh_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_api_msmtchh_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp

$(TARG_TEST_UNIT_api_msmtchh_MT_R):    \
		$(OBJ_TEST_UNIT_api_msmtchh_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_msmtchh_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_api_msmtchh_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp

$(TARG_TEST_UNIT_api_msmtchh_MT_R_W):    \
		$(OBJ_TEST_UNIT_api_msmtchh_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_api_msmtchh_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_UNIT_api_msmtchh_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.mismatched_handlers\test.unit.api.mismatched_handlers.cpp

$(TARG_TEST_UNIT_bndl_winini_MT_D):    \
		$(OBJ_TEST_UNIT_bndl_winini_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_bndl_winini_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_bndl_winini_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp

$(TARG_TEST_UNIT_bndl_winini_MT_D_W):    \
		$(OBJ_TEST_UNIT_bndl_winini_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_bndl_winini_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_UNIT_bndl_winini_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp

$(TARG_TEST_UNIT_bndl_winini_DLL_D):    \
		$(OBJ_TEST_UNIT_bndl_winini_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_bndl_winini_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_bndl_winini_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp

$(TARG_TEST_UNIT_bndl_winini_DLL_D_W):    \
		$(OBJ_TEST_UNIT_bndl_winini_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_bndl_winini_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_bndl_winini_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp

$(TARG_TEST_UNIT_bndl_winini_DLL_R):    \
		$(OBJ_TEST_UNIT_bndl_winini_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_bndl_winini_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_bndl_winini_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp

$(TARG_TEST_UNIT_bndl_winini_DLL_R_W):    \
		$(OBJ_TEST_UNIT_bndl_winini_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_bndl_winini_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_bndl_winini_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp

$(TARG_TEST_UNIT_bndl_winini_MT_R):    \
		$(OBJ_TEST_UNIT_bndl_winini_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_bndl_winini_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_bndl_winini_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp

$(TARG_TEST_UNIT_bndl_winini_MT_R_W):    \
		$(OBJ_TEST_UNIT_bndl_winini_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_bndl_winini_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_UNIT_bndl_winini_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.bundle.winini\test.unit.bundle.winini.cpp

$(TARG_TEST_UNIT_snk_ods_MT_D):    \
		$(OBJ_TEST_UNIT_snk_ods_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_snk_ods_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_snk_ods_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp

$(TARG_TEST_UNIT_snk_ods_MT_D_W):    \
		$(OBJ_TEST_UNIT_snk_ods_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_ods_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_UNIT_snk_ods_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp

$(TARG_TEST_UNIT_snk_ods_DLL_D):    \
		$(OBJ_TEST_UNIT_snk_ods_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_snk_ods_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_snk_ods_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp

$(TARG_TEST_UNIT_snk_ods_DLL_D_W):    \
		$(OBJ_TEST_UNIT_snk_ods_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_ods_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_snk_ods_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp

$(TARG_TEST_UNIT_snk_ods_DLL_R):    \
		$(OBJ_TEST_UNIT_snk_ods_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_snk_ods_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_snk_ods_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp

$(TARG_TEST_UNIT_snk_ods_DLL_R_W):    \
		$(OBJ_TEST_UNIT_snk_ods_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_ods_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_snk_ods_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp

$(TARG_TEST_UNIT_snk_ods_MT_R):    \
		$(OBJ_TEST_UNIT_snk_ods_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_snk_ods_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_snk_ods_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp

$(TARG_TEST_UNIT_snk_ods_MT_R_W):    \
		$(OBJ_TEST_UNIT_snk_ods_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_ods_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_UNIT_snk_ods_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.OutputDebugString\test.unit.sink.OutputDebugString.cpp

$(TARG_TEST_UNIT_fmt_stdfl_MT_D):    \
		$(OBJ_TEST_UNIT_fmt_stdfl_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_fmt_stdfl_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_fmt_stdfl_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp

$(TARG_TEST_UNIT_fmt_stdfl_MT_D_W):    \
		$(OBJ_TEST_UNIT_fmt_stdfl_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_fmt_stdfl_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_UNIT_fmt_stdfl_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp

$(TARG_TEST_UNIT_fmt_stdfl_DLL_D):    \
		$(OBJ_TEST_UNIT_fmt_stdfl_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_fmt_stdfl_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_fmt_stdfl_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp

$(TARG_TEST_UNIT_fmt_stdfl_DLL_D_W):    \
		$(OBJ_TEST_UNIT_fmt_stdfl_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_fmt_stdfl_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_fmt_stdfl_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp

$(TARG_TEST_UNIT_fmt_stdfl_DLL_R):    \
		$(OBJ_TEST_UNIT_fmt_stdfl_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_fmt_stdfl_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_fmt_stdfl_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp

$(TARG_TEST_UNIT_fmt_stdfl_DLL_R_W):    \
		$(OBJ_TEST_UNIT_fmt_stdfl_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_fmt_stdfl_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_fmt_stdfl_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp

$(TARG_TEST_UNIT_fmt_stdfl_MT_R):    \
		$(OBJ_TEST_UNIT_fmt_stdfl_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_fmt_stdfl_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_fmt_stdfl_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp

$(TARG_TEST_UNIT_fmt_stdfl_MT_R_W):    \
		$(OBJ_TEST_UNIT_fmt_stdfl_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_fmt_stdfl_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_UNIT_fmt_stdfl_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.format.standard_flags\test.unit.format.standard_flags.cpp

$(TARG_TEST_UNIT_ins_ch_MT_D):    \
		$(OBJ_TEST_UNIT_ins_ch_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_ins_ch_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_ins_ch_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp

$(TARG_TEST_UNIT_ins_ch_MT_D_W):    \
		$(OBJ_TEST_UNIT_ins_ch_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_ins_ch_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_UNIT_ins_ch_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp

$(TARG_TEST_UNIT_ins_ch_DLL_D):    \
		$(OBJ_TEST_UNIT_ins_ch_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_ins_ch_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_ins_ch_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp

$(TARG_TEST_UNIT_ins_ch_DLL_D_W):    \
		$(OBJ_TEST_UNIT_ins_ch_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_ins_ch_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_ins_ch_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp

$(TARG_TEST_UNIT_ins_ch_DLL_R):    \
		$(OBJ_TEST_UNIT_ins_ch_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_ins_ch_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_ins_ch_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp

$(TARG_TEST_UNIT_ins_ch_DLL_R_W):    \
		$(OBJ_TEST_UNIT_ins_ch_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_ins_ch_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_ins_ch_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp

$(TARG_TEST_UNIT_ins_ch_MT_R):    \
		$(OBJ_TEST_UNIT_ins_ch_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_ins_ch_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_ins_ch_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp

$(TARG_TEST_UNIT_ins_ch_MT_R_W):    \
		$(OBJ_TEST_UNIT_ins_ch_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_ins_ch_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_UNIT_ins_ch_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.character\test.unit.inserters.character.cpp

$(TARG_TEST_UNIT_ins_i_MT_D):    \
		$(OBJ_TEST_UNIT_ins_i_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_ins_i_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_ins_i_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp

$(TARG_TEST_UNIT_ins_i_MT_D_W):    \
		$(OBJ_TEST_UNIT_ins_i_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_ins_i_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_UNIT_ins_i_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp

$(TARG_TEST_UNIT_ins_i_DLL_D):    \
		$(OBJ_TEST_UNIT_ins_i_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_ins_i_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_ins_i_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp

$(TARG_TEST_UNIT_ins_i_DLL_D_W):    \
		$(OBJ_TEST_UNIT_ins_i_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_ins_i_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_ins_i_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp

$(TARG_TEST_UNIT_ins_i_DLL_R):    \
		$(OBJ_TEST_UNIT_ins_i_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_ins_i_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_ins_i_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp

$(TARG_TEST_UNIT_ins_i_DLL_R_W):    \
		$(OBJ_TEST_UNIT_ins_i_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_ins_i_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_ins_i_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp

$(TARG_TEST_UNIT_ins_i_MT_R):    \
		$(OBJ_TEST_UNIT_ins_i_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_ins_i_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_ins_i_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp

$(TARG_TEST_UNIT_ins_i_MT_R_W):    \
		$(OBJ_TEST_UNIT_ins_i_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_ins_i_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_UNIT_ins_i_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.integer\test.unit.inserters.integer.cpp

$(TARG_TEST_UNIT_ins_ss_MT_D):    \
		$(OBJ_TEST_UNIT_ins_ss_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_ins_ss_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_ins_ss_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.storage_size\test.unit.inserters.storage_size.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.storage_size\test.unit.inserters.storage_size.cpp

$(TARG_TEST_UNIT_ins_ss_MT_D_W):    \
		$(OBJ_TEST_UNIT_ins_ss_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_ins_ss_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_UNIT_ins_ss_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.storage_size\test.unit.inserters.storage_size.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.storage_size\test.unit.inserters.storage_size.cpp

$(TARG_TEST_UNIT_ins_ss_DLL_D):    \
		$(OBJ_TEST_UNIT_ins_ss_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_ins_ss_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_ins_ss_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.storage_size\test.unit.inserters.storage_size.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.storage_size\test.unit.inserters.storage_size.cpp

$(TARG_TEST_UNIT_ins_ss_DLL_D_W):    \
		$(OBJ_TEST_UNIT_ins_ss_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_ins_ss_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_ins_ss_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.storage_size\test.unit.inserters.storage_size.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.storage_size\test.unit.inserters.storage_size.cpp

$(TARG_TEST_UNIT_ins_ss_DLL_R):    \
		$(OBJ_TEST_UNIT_ins_ss_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_ins_ss_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_ins_ss_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.storage_size\test.unit.inserters.storage_size.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.storage_size\test.unit.inserters.storage_size.cpp

$(TARG_TEST_UNIT_ins_ss_DLL_R_W):    \
		$(OBJ_TEST_UNIT_ins_ss_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_ins_ss_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_ins_ss_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.storage_size\test.unit.inserters.storage_size.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.storage_size\test.unit.inserters.storage_size.cpp

$(TARG_TEST_UNIT_ins_ss_MT_R):    \
		$(OBJ_TEST_UNIT_ins_ss_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_ins_ss_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_ins_ss_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.storage_size\test.unit.inserters.storage_size.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.storage_size\test.unit.inserters.storage_size.cpp

$(TARG_TEST_UNIT_ins_ss_MT_R_W):    \
		$(OBJ_TEST_UNIT_ins_ss_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_ins_ss_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_UNIT_ins_ss_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.storage_size\test.unit.inserters.storage_size.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.inserters.storage_size\test.unit.inserters.storage_size.cpp

$(TARG_TEST_UNIT_shim_fi_MT_D):    \
		$(OBJ_TEST_UNIT_shim_fi_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_shim_fi_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_shim_fi_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp

$(TARG_TEST_UNIT_shim_fi_MT_D_W):    \
		$(OBJ_TEST_UNIT_shim_fi_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_shim_fi_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_UNIT_shim_fi_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp

$(TARG_TEST_UNIT_shim_fi_DLL_D):    \
		$(OBJ_TEST_UNIT_shim_fi_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_shim_fi_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_shim_fi_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp

$(TARG_TEST_UNIT_shim_fi_DLL_D_W):    \
		$(OBJ_TEST_UNIT_shim_fi_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_shim_fi_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_shim_fi_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp

$(TARG_TEST_UNIT_shim_fi_DLL_R):    \
		$(OBJ_TEST_UNIT_shim_fi_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_shim_fi_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_shim_fi_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp

$(TARG_TEST_UNIT_shim_fi_DLL_R_W):    \
		$(OBJ_TEST_UNIT_shim_fi_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_shim_fi_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_shim_fi_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp

$(TARG_TEST_UNIT_shim_fi_MT_R):    \
		$(OBJ_TEST_UNIT_shim_fi_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_shim_fi_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_shim_fi_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp

$(TARG_TEST_UNIT_shim_fi_MT_R_W):    \
		$(OBJ_TEST_UNIT_shim_fi_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_shim_fi_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_UNIT_shim_fi_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims.fast_integers\test.unit.shims.fast_integers.cpp

$(TARG_TEST_UNIT_shim_ns_MT_D):    \
		$(OBJ_TEST_UNIT_shim_ns_1_MT_D)\
		$(OBJ_TEST_UNIT_shim_ns_2_MT_D)\
		$(OBJ_TEST_UNIT_shim_ns_3_MT_D)\
		$(OBJ_TEST_UNIT_shim_ns_4_MT_D)\
		$(OBJ_TEST_UNIT_shim_ns_5_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_shim_ns_1_MT_D)\
		$(OBJ_TEST_UNIT_shim_ns_2_MT_D)\
		$(OBJ_TEST_UNIT_shim_ns_3_MT_D)\
		$(OBJ_TEST_UNIT_shim_ns_4_MT_D)\
		$(OBJ_TEST_UNIT_shim_ns_5_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_shim_ns_1_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.main.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.main.cpp
$(OBJ_TEST_UNIT_shim_ns_2_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.with_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.with_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_3_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_fastformat_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_fastformat_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_4_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_stlsoft_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_stlsoft_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_5_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_either_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_either_namespace.cpp

$(TARG_TEST_UNIT_shim_ns_MT_D_W):    \
		$(OBJ_TEST_UNIT_shim_ns_1_MT_D_W)\
		$(OBJ_TEST_UNIT_shim_ns_2_MT_D_W)\
		$(OBJ_TEST_UNIT_shim_ns_3_MT_D_W)\
		$(OBJ_TEST_UNIT_shim_ns_4_MT_D_W)\
		$(OBJ_TEST_UNIT_shim_ns_5_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_shim_ns_1_MT_D_W)\
		$(OBJ_TEST_UNIT_shim_ns_2_MT_D_W)\
		$(OBJ_TEST_UNIT_shim_ns_3_MT_D_W)\
		$(OBJ_TEST_UNIT_shim_ns_4_MT_D_W)\
		$(OBJ_TEST_UNIT_shim_ns_5_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_UNIT_shim_ns_1_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.main.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.main.cpp
$(OBJ_TEST_UNIT_shim_ns_2_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.with_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.with_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_3_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_fastformat_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_fastformat_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_4_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_stlsoft_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_stlsoft_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_5_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_either_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_either_namespace.cpp

$(TARG_TEST_UNIT_shim_ns_DLL_D):    \
		$(OBJ_TEST_UNIT_shim_ns_1_DLL_D)\
		$(OBJ_TEST_UNIT_shim_ns_2_DLL_D)\
		$(OBJ_TEST_UNIT_shim_ns_3_DLL_D)\
		$(OBJ_TEST_UNIT_shim_ns_4_DLL_D)\
		$(OBJ_TEST_UNIT_shim_ns_5_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_shim_ns_1_DLL_D)\
		$(OBJ_TEST_UNIT_shim_ns_2_DLL_D)\
		$(OBJ_TEST_UNIT_shim_ns_3_DLL_D)\
		$(OBJ_TEST_UNIT_shim_ns_4_DLL_D)\
		$(OBJ_TEST_UNIT_shim_ns_5_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_shim_ns_1_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.main.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.main.cpp
$(OBJ_TEST_UNIT_shim_ns_2_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.with_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.with_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_3_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_fastformat_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_fastformat_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_4_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_stlsoft_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_stlsoft_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_5_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_either_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_either_namespace.cpp

$(TARG_TEST_UNIT_shim_ns_DLL_D_W):    \
		$(OBJ_TEST_UNIT_shim_ns_1_DLL_D_W)\
		$(OBJ_TEST_UNIT_shim_ns_2_DLL_D_W)\
		$(OBJ_TEST_UNIT_shim_ns_3_DLL_D_W)\
		$(OBJ_TEST_UNIT_shim_ns_4_DLL_D_W)\
		$(OBJ_TEST_UNIT_shim_ns_5_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_shim_ns_1_DLL_D_W)\
		$(OBJ_TEST_UNIT_shim_ns_2_DLL_D_W)\
		$(OBJ_TEST_UNIT_shim_ns_3_DLL_D_W)\
		$(OBJ_TEST_UNIT_shim_ns_4_DLL_D_W)\
		$(OBJ_TEST_UNIT_shim_ns_5_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_shim_ns_1_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.main.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.main.cpp
$(OBJ_TEST_UNIT_shim_ns_2_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.with_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.with_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_3_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_fastformat_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_fastformat_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_4_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_stlsoft_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_stlsoft_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_5_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_either_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_either_namespace.cpp

$(TARG_TEST_UNIT_shim_ns_DLL_R):    \
		$(OBJ_TEST_UNIT_shim_ns_1_DLL_R)\
		$(OBJ_TEST_UNIT_shim_ns_2_DLL_R)\
		$(OBJ_TEST_UNIT_shim_ns_3_DLL_R)\
		$(OBJ_TEST_UNIT_shim_ns_4_DLL_R)\
		$(OBJ_TEST_UNIT_shim_ns_5_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_shim_ns_1_DLL_R)\
		$(OBJ_TEST_UNIT_shim_ns_2_DLL_R)\
		$(OBJ_TEST_UNIT_shim_ns_3_DLL_R)\
		$(OBJ_TEST_UNIT_shim_ns_4_DLL_R)\
		$(OBJ_TEST_UNIT_shim_ns_5_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_shim_ns_1_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.main.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.main.cpp
$(OBJ_TEST_UNIT_shim_ns_2_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.with_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.with_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_3_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_fastformat_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_fastformat_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_4_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_stlsoft_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_stlsoft_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_5_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_either_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_either_namespace.cpp

$(TARG_TEST_UNIT_shim_ns_DLL_R_W):    \
		$(OBJ_TEST_UNIT_shim_ns_1_DLL_R_W)\
		$(OBJ_TEST_UNIT_shim_ns_2_DLL_R_W)\
		$(OBJ_TEST_UNIT_shim_ns_3_DLL_R_W)\
		$(OBJ_TEST_UNIT_shim_ns_4_DLL_R_W)\
		$(OBJ_TEST_UNIT_shim_ns_5_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_shim_ns_1_DLL_R_W)\
		$(OBJ_TEST_UNIT_shim_ns_2_DLL_R_W)\
		$(OBJ_TEST_UNIT_shim_ns_3_DLL_R_W)\
		$(OBJ_TEST_UNIT_shim_ns_4_DLL_R_W)\
		$(OBJ_TEST_UNIT_shim_ns_5_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_shim_ns_1_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.main.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.main.cpp
$(OBJ_TEST_UNIT_shim_ns_2_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.with_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.with_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_3_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_fastformat_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_fastformat_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_4_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_stlsoft_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_stlsoft_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_5_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_either_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_either_namespace.cpp

$(TARG_TEST_UNIT_shim_ns_MT_R):    \
		$(OBJ_TEST_UNIT_shim_ns_1_MT_R)\
		$(OBJ_TEST_UNIT_shim_ns_2_MT_R)\
		$(OBJ_TEST_UNIT_shim_ns_3_MT_R)\
		$(OBJ_TEST_UNIT_shim_ns_4_MT_R)\
		$(OBJ_TEST_UNIT_shim_ns_5_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_shim_ns_1_MT_R)\
		$(OBJ_TEST_UNIT_shim_ns_2_MT_R)\
		$(OBJ_TEST_UNIT_shim_ns_3_MT_R)\
		$(OBJ_TEST_UNIT_shim_ns_4_MT_R)\
		$(OBJ_TEST_UNIT_shim_ns_5_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_shim_ns_1_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.main.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.main.cpp
$(OBJ_TEST_UNIT_shim_ns_2_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.with_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.with_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_3_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_fastformat_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_fastformat_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_4_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_stlsoft_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_stlsoft_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_5_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_either_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_either_namespace.cpp

$(TARG_TEST_UNIT_shim_ns_MT_R_W):    \
		$(OBJ_TEST_UNIT_shim_ns_1_MT_R_W)\
		$(OBJ_TEST_UNIT_shim_ns_2_MT_R_W)\
		$(OBJ_TEST_UNIT_shim_ns_3_MT_R_W)\
		$(OBJ_TEST_UNIT_shim_ns_4_MT_R_W)\
		$(OBJ_TEST_UNIT_shim_ns_5_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_shim_ns_1_MT_R_W)\
		$(OBJ_TEST_UNIT_shim_ns_2_MT_R_W)\
		$(OBJ_TEST_UNIT_shim_ns_3_MT_R_W)\
		$(OBJ_TEST_UNIT_shim_ns_4_MT_R_W)\
		$(OBJ_TEST_UNIT_shim_ns_5_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_UNIT_shim_ns_1_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.main.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.main.cpp
$(OBJ_TEST_UNIT_shim_ns_2_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.with_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.with_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_3_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_fastformat_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_fastformat_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_4_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_stlsoft_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_stlsoft_namespace.cpp
$(OBJ_TEST_UNIT_shim_ns_5_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_either_namespace.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.shims_and_namespaces\test.unit.shims_and_namespaces.without_either_namespace.cpp

$(TARG_TEST_UNIT_snk_a_b_MT_D):    \
		$(OBJ_TEST_UNIT_snk_a_b_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_snk_a_b_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_snk_a_b_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp

$(TARG_TEST_UNIT_snk_a_b_MT_D_W):    \
		$(OBJ_TEST_UNIT_snk_a_b_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_a_b_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_UNIT_snk_a_b_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp

$(TARG_TEST_UNIT_snk_a_b_DLL_D):    \
		$(OBJ_TEST_UNIT_snk_a_b_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_snk_a_b_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_snk_a_b_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp

$(TARG_TEST_UNIT_snk_a_b_DLL_D_W):    \
		$(OBJ_TEST_UNIT_snk_a_b_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_a_b_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_snk_a_b_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp

$(TARG_TEST_UNIT_snk_a_b_DLL_R):    \
		$(OBJ_TEST_UNIT_snk_a_b_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_snk_a_b_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_snk_a_b_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp

$(TARG_TEST_UNIT_snk_a_b_DLL_R_W):    \
		$(OBJ_TEST_UNIT_snk_a_b_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_a_b_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_snk_a_b_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp

$(TARG_TEST_UNIT_snk_a_b_MT_R):    \
		$(OBJ_TEST_UNIT_snk_a_b_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_snk_a_b_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_snk_a_b_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp

$(TARG_TEST_UNIT_snk_a_b_MT_R_W):    \
		$(OBJ_TEST_UNIT_snk_a_b_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_a_b_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_UNIT_snk_a_b_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.auto_buffer\test.unit.sink.auto_buffer.cpp

$(TARG_TEST_UNIT_snk_c_str_MT_D):    \
		$(OBJ_TEST_UNIT_snk_c_str_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_snk_c_str_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_snk_c_str_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp

$(TARG_TEST_UNIT_snk_c_str_MT_D_W):    \
		$(OBJ_TEST_UNIT_snk_c_str_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_c_str_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_UNIT_snk_c_str_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp

$(TARG_TEST_UNIT_snk_c_str_DLL_D):    \
		$(OBJ_TEST_UNIT_snk_c_str_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_snk_c_str_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_snk_c_str_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp

$(TARG_TEST_UNIT_snk_c_str_DLL_D_W):    \
		$(OBJ_TEST_UNIT_snk_c_str_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_c_str_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_snk_c_str_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp

$(TARG_TEST_UNIT_snk_c_str_DLL_R):    \
		$(OBJ_TEST_UNIT_snk_c_str_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_snk_c_str_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_snk_c_str_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp

$(TARG_TEST_UNIT_snk_c_str_DLL_R_W):    \
		$(OBJ_TEST_UNIT_snk_c_str_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_c_str_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_snk_c_str_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp

$(TARG_TEST_UNIT_snk_c_str_MT_R):    \
		$(OBJ_TEST_UNIT_snk_c_str_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_snk_c_str_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_snk_c_str_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp

$(TARG_TEST_UNIT_snk_c_str_MT_R_W):    \
		$(OBJ_TEST_UNIT_snk_c_str_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_c_str_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_UNIT_snk_c_str_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.c_string\test.unit.sink.c_string.cpp

$(TARG_TEST_UNIT_snk_chbuf_MT_D):    \
		$(OBJ_TEST_UNIT_snk_chbuf_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_snk_chbuf_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_snk_chbuf_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp

$(TARG_TEST_UNIT_snk_chbuf_MT_D_W):    \
		$(OBJ_TEST_UNIT_snk_chbuf_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_chbuf_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_UNIT_snk_chbuf_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp

$(TARG_TEST_UNIT_snk_chbuf_DLL_D):    \
		$(OBJ_TEST_UNIT_snk_chbuf_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_snk_chbuf_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_snk_chbuf_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp

$(TARG_TEST_UNIT_snk_chbuf_DLL_D_W):    \
		$(OBJ_TEST_UNIT_snk_chbuf_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_chbuf_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_snk_chbuf_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp

$(TARG_TEST_UNIT_snk_chbuf_DLL_R):    \
		$(OBJ_TEST_UNIT_snk_chbuf_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_snk_chbuf_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_snk_chbuf_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp

$(TARG_TEST_UNIT_snk_chbuf_DLL_R_W):    \
		$(OBJ_TEST_UNIT_snk_chbuf_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_chbuf_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_snk_chbuf_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp

$(TARG_TEST_UNIT_snk_chbuf_MT_R):    \
		$(OBJ_TEST_UNIT_snk_chbuf_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_snk_chbuf_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_snk_chbuf_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp

$(TARG_TEST_UNIT_snk_chbuf_MT_R_W):    \
		$(OBJ_TEST_UNIT_snk_chbuf_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_chbuf_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_UNIT_snk_chbuf_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.char_buffer\test.unit.sink.char_buffer.cpp

$(TARG_TEST_UNIT_snk_null_MT_D):    \
		$(OBJ_TEST_UNIT_snk_null_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_snk_null_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_snk_null_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp

$(TARG_TEST_UNIT_snk_null_MT_D_W):    \
		$(OBJ_TEST_UNIT_snk_null_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_null_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_UNIT_snk_null_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp

$(TARG_TEST_UNIT_snk_null_DLL_D):    \
		$(OBJ_TEST_UNIT_snk_null_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_snk_null_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_snk_null_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp

$(TARG_TEST_UNIT_snk_null_DLL_D_W):    \
		$(OBJ_TEST_UNIT_snk_null_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_null_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_snk_null_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp

$(TARG_TEST_UNIT_snk_null_DLL_R):    \
		$(OBJ_TEST_UNIT_snk_null_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_snk_null_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_snk_null_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp

$(TARG_TEST_UNIT_snk_null_DLL_R_W):    \
		$(OBJ_TEST_UNIT_snk_null_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_null_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_snk_null_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp

$(TARG_TEST_UNIT_snk_null_MT_R):    \
		$(OBJ_TEST_UNIT_snk_null_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_snk_null_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_snk_null_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp

$(TARG_TEST_UNIT_snk_null_MT_R_W):    \
		$(OBJ_TEST_UNIT_snk_null_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_null_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_UNIT_snk_null_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.null\test.unit.sink.null.cpp

$(TARG_TEST_UNIT_snk_ostm_MT_D):    \
		$(OBJ_TEST_UNIT_snk_ostm_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_snk_ostm_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_snk_ostm_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp

$(TARG_TEST_UNIT_snk_ostm_MT_D_W):    \
		$(OBJ_TEST_UNIT_snk_ostm_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_ostm_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_UNIT_snk_ostm_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp

$(TARG_TEST_UNIT_snk_ostm_DLL_D):    \
		$(OBJ_TEST_UNIT_snk_ostm_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_snk_ostm_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_snk_ostm_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp

$(TARG_TEST_UNIT_snk_ostm_DLL_D_W):    \
		$(OBJ_TEST_UNIT_snk_ostm_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_ostm_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_snk_ostm_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp

$(TARG_TEST_UNIT_snk_ostm_DLL_R):    \
		$(OBJ_TEST_UNIT_snk_ostm_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_snk_ostm_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_snk_ostm_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp

$(TARG_TEST_UNIT_snk_ostm_DLL_R_W):    \
		$(OBJ_TEST_UNIT_snk_ostm_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_ostm_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_snk_ostm_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp

$(TARG_TEST_UNIT_snk_ostm_MT_R):    \
		$(OBJ_TEST_UNIT_snk_ostm_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_snk_ostm_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_snk_ostm_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp

$(TARG_TEST_UNIT_snk_ostm_MT_R_W):    \
		$(OBJ_TEST_UNIT_snk_ostm_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_ostm_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_UNIT_snk_ostm_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.ostream\test.unit.sink.ostream.cpp

$(TARG_TEST_UNIT_snk_mfccstr_DLL_D):    \
		$(OBJ_TEST_UNIT_snk_mfccstr_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_snk_mfccstr_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_snk_mfccstr_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.CString\test.unit.sink.CString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.CString\test.unit.sink.CString.cpp

$(TARG_TEST_UNIT_snk_mfccstr_DLL_D_W):    \
		$(OBJ_TEST_UNIT_snk_mfccstr_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_mfccstr_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_snk_mfccstr_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.CString\test.unit.sink.CString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.CString\test.unit.sink.CString.cpp

$(TARG_TEST_UNIT_snk_mfccstr_DLL_R):    \
		$(OBJ_TEST_UNIT_snk_mfccstr_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_snk_mfccstr_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_snk_mfccstr_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.CString\test.unit.sink.CString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.CString\test.unit.sink.CString.cpp

$(TARG_TEST_UNIT_snk_mfccstr_DLL_R_W):    \
		$(OBJ_TEST_UNIT_snk_mfccstr_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_mfccstr_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_snk_mfccstr_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.CString\test.unit.sink.CString.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.CString\test.unit.sink.CString.cpp

$(TARG_TEST_UNIT_snk_sstm_MT_D):    \
		$(OBJ_TEST_UNIT_snk_sstm_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_snk_sstm_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_snk_sstm_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp

$(TARG_TEST_UNIT_snk_sstm_MT_D_W):    \
		$(OBJ_TEST_UNIT_snk_sstm_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_sstm_MT_D_W)\
		$(LIB_CORE_MT_D_W)\
		$(LIB_SHWILD_MT_D_W)\
		$(LIB_XTESTS_MT_D_W)\
		$(TARGET_LIB_MT_D_W)

$(OBJ_TEST_UNIT_snk_sstm_MT_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp

$(TARG_TEST_UNIT_snk_sstm_DLL_D):    \
		$(OBJ_TEST_UNIT_snk_sstm_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_snk_sstm_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_snk_sstm_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp

$(TARG_TEST_UNIT_snk_sstm_DLL_D_W):    \
		$(OBJ_TEST_UNIT_snk_sstm_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_sstm_DLL_D_W)\
		$(LIB_CORE_DLL_D_W)\
		$(LIB_SHWILD_DLL_D_W)\
		$(LIB_XTESTS_DLL_D_W)\
		$(TARGET_LIB_DLL_D_W)

$(OBJ_TEST_UNIT_snk_sstm_DLL_D_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp

$(TARG_TEST_UNIT_snk_sstm_DLL_R):    \
		$(OBJ_TEST_UNIT_snk_sstm_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_snk_sstm_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_snk_sstm_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp

$(TARG_TEST_UNIT_snk_sstm_DLL_R_W):    \
		$(OBJ_TEST_UNIT_snk_sstm_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_sstm_DLL_R_W)\
		$(LIB_CORE_DLL_R_W)\
		$(LIB_SHWILD_DLL_R_W)\
		$(LIB_XTESTS_DLL_R_W)\
		$(TARGET_LIB_DLL_R_W)

$(OBJ_TEST_UNIT_snk_sstm_DLL_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp

$(TARG_TEST_UNIT_snk_sstm_MT_R):    \
		$(OBJ_TEST_UNIT_snk_sstm_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_snk_sstm_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_snk_sstm_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp

$(TARG_TEST_UNIT_snk_sstm_MT_R_W):    \
		$(OBJ_TEST_UNIT_snk_sstm_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R_W) -out:$@ \
		$(OBJ_TEST_UNIT_snk_sstm_MT_R_W)\
		$(LIB_CORE_MT_R_W)\
		$(LIB_SHWILD_MT_R_W)\
		$(LIB_XTESTS_MT_R_W)\
		$(TARGET_LIB_MT_R_W)

$(OBJ_TEST_UNIT_snk_sstm_MT_R_W): $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R_W) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.sink.stringstream\test.unit.sink.stringstream.cpp

############################### end of file ################################
