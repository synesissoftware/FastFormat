# Microsoft Developer Studio Project File - Name="fastformat.core" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=fastformat.core - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "fastformat.core.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "fastformat.core.mak" CFG="fastformat.core - Win32 Release"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "fastformat.core - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "fastformat.core - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "fastformat.core - Win32 Release Multithreaded" (based on "Win32 (x86) Static Library")
!MESSAGE "fastformat.core - Win32 Debug Multithreaded" (based on "Win32 (x86) Static Library")
!MESSAGE "fastformat.core - Win32 Release Multithreaded DLL" (based on "Win32 (x86) Static Library")
!MESSAGE "fastformat.core - Win32 Debug Multithreaded DLL" (based on "Win32 (x86) Static Library")
!MESSAGE "fastformat.core - Win32 Unicode Release" (based on "Win32 (x86) Static Library")
!MESSAGE "fastformat.core - Win32 Unicode Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "fastformat.core - Win32 Unicode Release Multithreaded" (based on "Win32 (x86) Static Library")
!MESSAGE "fastformat.core - Win32 Unicode Debug Multithreaded" (based on "Win32 (x86) Static Library")
!MESSAGE "fastformat.core - Win32 Unicode Release Multithreaded DLL" (based on "Win32 (x86) Static Library")
!MESSAGE "fastformat.core - Win32 Unicode Debug Multithreaded DLL" (based on "Win32 (x86) Static Library")
!MESSAGE "fastformat.core - Win32 Release pseudoUNIX" (based on "Win32 (x86) Static Library")
!MESSAGE "fastformat.core - Win32 Debug pseudoUNIX" (based on "Win32 (x86) Static Library")
!MESSAGE "fastformat.core - Win32 Release Multithreaded pseudoUNIX" (based on "Win32 (x86) Static Library")
!MESSAGE "fastformat.core - Win32 Debug Multithreaded pseudoUNIX" (based on "Win32 (x86) Static Library")
!MESSAGE "fastformat.core - Win32 Release Multithreaded DLL pseudoUNIX" (based on "Win32 (x86) Static Library")
!MESSAGE "fastformat.core - Win32 Debug Multithreaded DLL pseudoUNIX" (based on "Win32 (x86) Static Library")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "fastformat.core - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /WX /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /W3 /WX /GR /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /FI"pch.hpp" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /Yu"pch.hpp" /FD /c
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.lib"
# ADD LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.lib"

!ELSEIF  "$(CFG)" == "fastformat.core - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /FD /GZ /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /FI"pch.hpp" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /Yu"pch.hpp" /FD /GZ /c
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.debug.lib"
# ADD LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.debug.lib"

!ELSEIF  "$(CFG)" == "fastformat.core - Win32 Release Multithreaded"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMT"
# PROP BASE Intermediate_Dir "ReleaseMT"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMT"
# PROP Intermediate_Dir "ReleaseMT"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /WX /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MT /W3 /WX /GR /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /FI"pch.hpp" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /Yu"pch.hpp" /FD /c
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.mt.lib"
# ADD LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.mt.lib"

!ELSEIF  "$(CFG)" == "fastformat.core - Win32 Debug Multithreaded"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugMT"
# PROP BASE Intermediate_Dir "DebugMT"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugMT"
# PROP Intermediate_Dir "DebugMT"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /FD /GZ /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MTd /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /FI"pch.hpp" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /Yu"pch.hpp" /FD /GZ /c
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.mt.debug.lib"
# ADD LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.mt.debug.lib"

!ELSEIF  "$(CFG)" == "fastformat.core - Win32 Release Multithreaded DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseDLL"
# PROP BASE Intermediate_Dir "ReleaseDLL"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseDLL"
# PROP Intermediate_Dir "ReleaseDLL"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /WX /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MD /W3 /WX /GR /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /FI"pch.hpp" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /Yu"pch.hpp" /FD /c
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.dll.lib"
# ADD LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.dll.lib"

!ELSEIF  "$(CFG)" == "fastformat.core - Win32 Debug Multithreaded DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugDLL"
# PROP BASE Intermediate_Dir "DebugDLL"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugDLL"
# PROP Intermediate_Dir "DebugDLL"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /FD /GZ /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /FI"pch.hpp" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /Yu"pch.hpp" /FD /GZ /c
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.dll.debug.lib"
# ADD LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.dll.debug.lib"

!ELSEIF  "$(CFG)" == "fastformat.core - Win32 Unicode Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "URelease"
# PROP BASE Intermediate_Dir "URelease"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "URelease"
# PROP Intermediate_Dir "URelease"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /WX /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_UNICODE" /D "UNICODE" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /W3 /WX /GR /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /FI"pch.hpp" /D "WIN32" /D "NDEBUG" /D "_UNICODE" /D "UNICODE" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /Yu"pch.hpp" /FD /c
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.widestring.lib"
# ADD LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.widestring.lib"

!ELSEIF  "$(CFG)" == "fastformat.core - Win32 Unicode Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "UDebug"
# PROP BASE Intermediate_Dir "UDebug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "UDebug"
# PROP Intermediate_Dir "UDebug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_UNICODE" /D "UNICODE" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /FD /GZ /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /FI"pch.hpp" /D "WIN32" /D "_DEBUG" /D "_UNICODE" /D "UNICODE" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /Yu"pch.hpp" /FD /GZ /c
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.widestring.debug.lib"
# ADD LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.widestring.debug.lib"

!ELSEIF  "$(CFG)" == "fastformat.core - Win32 Unicode Release Multithreaded"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "UReleaseMT"
# PROP BASE Intermediate_Dir "UReleaseMT"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "UReleaseMT"
# PROP Intermediate_Dir "UReleaseMT"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /WX /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_UNICODE" /D "UNICODE" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MT /W3 /WX /GR /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /FI"pch.hpp" /D "WIN32" /D "NDEBUG" /D "_UNICODE" /D "UNICODE" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /Yu"pch.hpp" /FD /c
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.widestring.mt.lib"
# ADD LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.widestring.mt.lib"

!ELSEIF  "$(CFG)" == "fastformat.core - Win32 Unicode Debug Multithreaded"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "UDebugMT"
# PROP BASE Intermediate_Dir "UDebugMT"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "UDebugMT"
# PROP Intermediate_Dir "UDebugMT"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_UNICODE" /D "UNICODE" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /FD /GZ /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MTd /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /FI"pch.hpp" /D "WIN32" /D "_DEBUG" /D "_UNICODE" /D "UNICODE" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /Yu"pch.hpp" /FD /GZ /c
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.widestring.mt.debug.lib"
# ADD LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.widestring.mt.debug.lib"

!ELSEIF  "$(CFG)" == "fastformat.core - Win32 Unicode Release Multithreaded DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "UReleaseDLL"
# PROP BASE Intermediate_Dir "UReleaseDLL"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "UReleaseDLL"
# PROP Intermediate_Dir "UReleaseDLL"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /WX /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_UNICODE" /D "UNICODE" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MD /W3 /WX /GR /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /FI"pch.hpp" /D "WIN32" /D "NDEBUG" /D "_UNICODE" /D "UNICODE" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /Yu"pch.hpp" /FD /c
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.widestring.dll.lib"
# ADD LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.widestring.dll.lib"

!ELSEIF  "$(CFG)" == "fastformat.core - Win32 Unicode Debug Multithreaded DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "UDebugDLL"
# PROP BASE Intermediate_Dir "UDebugDLL"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "UDebugDLL"
# PROP Intermediate_Dir "UDebugDLL"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_UNICODE" /D "UNICODE" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /FD /GZ /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /FI"pch.hpp" /D "WIN32" /D "_DEBUG" /D "_UNICODE" /D "UNICODE" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /Yu"pch.hpp" /FD /GZ /c
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.widestring.dll.debug.lib"
# ADD LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.widestring.dll.debug.lib"

!ELSEIF  "$(CFG)" == "fastformat.core - Win32 Release pseudoUNIX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseUNIX"
# PROP BASE Intermediate_Dir "ReleaseUNIX"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseUNIX"
# PROP Intermediate_Dir "ReleaseUNIX"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /WX /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /I "$(PTHREADS_WIN32)/include" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /W3 /WX /GR /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /FI"pch.hpp" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /Yu"pch.hpp" /FD /c
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.unix.lib"
# ADD LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.unix.lib"

!ELSEIF  "$(CFG)" == "fastformat.core - Win32 Debug pseudoUNIX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugUNIX"
# PROP BASE Intermediate_Dir "DebugUNIX"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugUNIX"
# PROP Intermediate_Dir "DebugUNIX"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /I "$(PTHREADS_WIN32)/include" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /FD /GZ /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /FI"pch.hpp" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /Yu"pch.hpp" /FD /GZ /c
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.unix.debug.lib"
# ADD LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.unix.debug.lib"

!ELSEIF  "$(CFG)" == "fastformat.core - Win32 Release Multithreaded pseudoUNIX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMTUNIX"
# PROP BASE Intermediate_Dir "ReleaseMTUNIX"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMTUNIX"
# PROP Intermediate_Dir "ReleaseMTUNIX"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /WX /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /I "$(PTHREADS_WIN32)/include" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MT /W3 /WX /GR /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /I "$(PTHREADS_WIN32)/include" /FI"pch.hpp" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /Yu"pch.hpp" /FD /c
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.unix.mt.lib"
# ADD LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.unix.mt.lib"

!ELSEIF  "$(CFG)" == "fastformat.core - Win32 Debug Multithreaded pseudoUNIX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugMTUNIX"
# PROP BASE Intermediate_Dir "DebugMTUNIX"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugMTUNIX"
# PROP Intermediate_Dir "DebugMTUNIX"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /I "$(PTHREADS_WIN32)/include" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /FD /GZ /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MTd /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /I "$(PTHREADS_WIN32)/include" /FI"pch.hpp" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /Yu"pch.hpp" /FD /GZ /c
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.unix.mt.debug.lib"
# ADD LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.unix.mt.debug.lib"

!ELSEIF  "$(CFG)" == "fastformat.core - Win32 Release Multithreaded DLL pseudoUNIX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseDLLUNIX"
# PROP BASE Intermediate_Dir "ReleaseDLLUNIX"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseDLLUNIX"
# PROP Intermediate_Dir "ReleaseDLLUNIX"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /WX /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /I "$(PTHREADS_WIN32)/include" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MD /W3 /WX /GR /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /I "$(PTHREADS_WIN32)/include" /FI"pch.hpp" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /Yu"pch.hpp" /FD /c
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.unix.dll.lib"
# ADD LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.unix.dll.lib"

!ELSEIF  "$(CFG)" == "fastformat.core - Win32 Debug Multithreaded DLL pseudoUNIX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugDLLUNIX"
# PROP BASE Intermediate_Dir "DebugDLLUNIX"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugDLLUNIX"
# PROP Intermediate_Dir "DebugDLLUNIX"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /I "$(PTHREADS_WIN32)/include" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /FD /GZ /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /I "$(PTHREADS_WIN32)/include" /FI"pch.hpp" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "FASTFORMAT_NO_INCLUDE_FASTFORMAT_STRING_ACCESS_SHIMS" /Yu"pch.hpp" /FD /GZ /c
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.unix.dll.debug.lib"
# ADD LIB32 /nologo /out:"../../../lib/fastformat.0.core.vc6.unix.dll.debug.lib"

!ENDIF

# Begin Target

# Name "fastformat.core - Win32 Release"
# Name "fastformat.core - Win32 Debug"
# Name "fastformat.core - Win32 Release Multithreaded"
# Name "fastformat.core - Win32 Debug Multithreaded"
# Name "fastformat.core - Win32 Release Multithreaded DLL"
# Name "fastformat.core - Win32 Debug Multithreaded DLL"
# Name "fastformat.core - Win32 Unicode Release"
# Name "fastformat.core - Win32 Unicode Debug"
# Name "fastformat.core - Win32 Unicode Release Multithreaded"
# Name "fastformat.core - Win32 Unicode Debug Multithreaded"
# Name "fastformat.core - Win32 Unicode Release Multithreaded DLL"
# Name "fastformat.core - Win32 Unicode Debug Multithreaded DLL"
# Name "fastformat.core - Win32 Release pseudoUNIX"
# Name "fastformat.core - Win32 Debug pseudoUNIX"
# Name "fastformat.core - Win32 Release Multithreaded pseudoUNIX"
# Name "fastformat.core - Win32 Debug Multithreaded pseudoUNIX"
# Name "fastformat.core - Win32 Release Multithreaded DLL pseudoUNIX"
# Name "fastformat.core - Win32 Debug Multithreaded DLL pseudoUNIX"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Module Source Files"

# PROP Default_Filter ""
# Begin Group "_dev_pragmatics_"

# PROP Default_Filter ""
# Begin Source File

SOURCE="..\_dev_pragmatics_\warnings.msvc.10+.h"
# End Source File
# End Group
# Begin Source File

SOURCE=..\pch.cpp
# ADD CPP /Yc"pch.hpp"
# End Source File
# Begin Source File

SOURCE=..\pch.hpp
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\src\api.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\enum_strings.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\fmt_cache.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\fmt_spec_defect_handlers.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\init_code_strings.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\memory_pool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\replacements.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\snprintf.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "STLSoft Header Files"

# PROP Default_Filter ""
# Begin Group "STLSoft"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\memory\allocator_base.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\memory\util\allocator_features.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\memory\util\allocator_selector.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\algorithms\std\alt.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\memory\auto_buffer.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\shims\access\string\std\c_string.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\capabilities.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\string\char_traits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\collections\util\collections.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\synch\concepts.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\constraints.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\quality\contract.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\error\conversion_error.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\quality\cover.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\exception_string.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\exception_string_creator.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\shims\access\string\fwd.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\head_version.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\conversion\integer_to_string\integer_to_decimal_string.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\conversion\integer_to_string\integer_to_hexadecimal_string.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\conversion\integer_to_string\integer_to_octal_string.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\conversion\integer_to_string\integer_to_string.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\conversion\integer_to_string.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\limits\integral_format_width_limits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\limits\integral_limits.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\limits\integral_limits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\is_const_type.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\is_integral_type.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\is_pointer_type.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\is_same_type.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\is_signed_type.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\std\iterator_helper.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\lead_version.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\std\library_discriminator.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\exception\library_identifier_provider.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\diagnostics\LibraryIdentifier.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\synch\lock_scope.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\iterators\member_selector_iterator.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\util\meta_.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\cccap\msvc.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\n_types.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\synch\null_mutex.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\cccap\obsolete.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\exception\os_exception.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\exception\out_of_memory_exception.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\algorithms\pod.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\exception\project_exception.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\exception\project_identifier_provider.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\diagnostics\ProjectIdentifier.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\exception\root_exception.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\safestr.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\conversion\sap_cast.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\smartptr\scoped_handle.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\smartptr\shared_ptr.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\sign_traits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\size_of.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\size_traits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\synch\spin_mutex_base.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\exception\status_code_provider.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\exception\util\status_code_translating_exception_base.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\std_swap.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\stlsoft.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\string\string_traits_fwd.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\string\string_view.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\warnings\push\suppress_deprecation_.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\warnings\pop\suppress_deprecation_.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\string\tokeniser_functions.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\conversion\truncation_test.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\synch\util\windows_api_.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\yesno.hpp"
# End Source File
# End Group
# Begin Group "PlatformSTL"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(STLSOFT)\include\platformstl\synch\atomic_functions.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\platformstl\synch\atomic_types.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\platformstl\synch\util\features.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\platformstl\platformstl.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\platformstl\platformstl.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\platformstl\synch\spin_mutex.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\platformstl\synch\thread_mutex.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\platformstl\synch\tss_index.hpp"
# End Source File
# End Group
# Begin Group "UNIXSTL"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(STLSOFT)\include\unixstl\synch\util\features.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\unixstl\unixstl.h"
# End Source File
# End Group
# Begin Group "WinSTL"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\synch\atomic_functions.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\synch\atomic_types.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\synch\common.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\error\error_functions.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\synch\exceptions.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\api\external\MemoryManagement.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\memory\processheap_allocator.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\synch\spin_mutex.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\synch\spin_mutex_policies.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\synch\Synchronisation_status_code.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\api\external\Synchronization.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\synch\thread_mutex.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\synch\tss_index.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\exception\policy\windows_status_code_to_string_translation_policy.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\winstl.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\exception\winstl_exception.hpp"
# End Source File
# End Group
# End Group
# Begin Group "FastFormat Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\quality\contract.h"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\quality\cover.h"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\exceptions.hpp"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\internal\fastformat.c++.h"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\fastformat.h"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\internal\format_element.h"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\init_codes.h"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\internal\shim_macros.h"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\util\string\snprintf.h"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\internal\stlsoft.h"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\internal\string_encoding.h"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\include\fastformat\internal\threading.h"
# End Source File
# End Group
# Begin Group "UNIXem Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(UNIXEM)\include\unistd.h"
# End Source File
# Begin Source File

SOURCE="$(UNIXEM)\include\unixem\unistd.h"
# End Source File
# Begin Source File

SOURCE="$(UNIXEM)\include\unixem\unixem.h"
# End Source File
# End Group
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\src\ximpl_core.hpp"
# End Source File
# End Group
# Begin Group "Script Files"

# PROP Default_Filter "pl;py;rb;vbs"
# Begin Source File

SOURCE="..\..\..\scripts\make_hdrs.rb"
# End Source File
# End Group
# Begin Group "Distribution Files"

# PROP Default_Filter "pl;py;rb;vbs"
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\_internal\dist-src\AUTHORS.txt"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\_internal\dist-src\CHANGES.txt"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\_internal\dist-src\FAQ.txt"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\_internal\dist-src\HISTORY.txt"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\_internal\dist-src\INSTALL.txt"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\_internal\dist-src\KNOWN_ISSUES.txt"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\_internal\dist-src\LICENSE.txt"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\_internal\dist-src\NEWS.txt"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\_internal\dist-src\README.txt"
# End Source File
# Begin Source File

SOURCE="$(FASTFORMAT_ROOT)\_internal\dist-src\TODO.txt"
# End Source File
# End Group
# End Target
# End Project
