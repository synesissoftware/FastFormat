# Microsoft Developer Studio Project File - Name="example.flush" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=example.flush - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "example.flush.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "example.flush.mak" CFG="example.flush - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "example.flush - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "example.flush - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "example.flush - Win32 Release Multithreaded" (based on "Win32 (x86) Application")
!MESSAGE "example.flush - Win32 Debug Multithreaded" (based on "Win32 (x86) Application")
!MESSAGE "example.flush - Win32 Release Multithreaded DLL" (based on "Win32 (x86) Application")
!MESSAGE "example.flush - Win32 Debug Multithreaded DLL" (based on "Win32 (x86) Application")
!MESSAGE "example.flush - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "example.flush - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE "example.flush - Win32 Unicode Release Multithreaded" (based on "Win32 (x86) Application")
!MESSAGE "example.flush - Win32 Unicode Debug Multithreaded" (based on "Win32 (x86) Application")
!MESSAGE "example.flush - Win32 Unicode Release Multithreaded DLL" (based on "Win32 (x86) Application")
!MESSAGE "example.flush - Win32 Unicode Debug Multithreaded DLL" (based on "Win32 (x86) Application")
!MESSAGE "example.flush - Win32 Release pseudoUNIX" (based on "Win32 (x86) Application")
!MESSAGE "example.flush - Win32 Debug pseudoUNIX" (based on "Win32 (x86) Application")
!MESSAGE "example.flush - Win32 Release Multithreaded pseudoUNIX" (based on "Win32 (x86) Application")
!MESSAGE "example.flush - Win32 Debug Multithreaded pseudoUNIX" (based on "Win32 (x86) Application")
!MESSAGE "example.flush - Win32 Release Multithreaded DLL pseudoUNIX" (based on "Win32 (x86) Application")
!MESSAGE "example.flush - Win32 Debug Multithreaded DLL pseudoUNIX" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "example.flush - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /WX /GR /GX /O2 /I "$(XTESTS_C_ROOT)/include" /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_CONSOLE" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /W3 /WX /GR /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_CONSOLE" /FR /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /machine:I386 /out:"../../../../bin/example.flush.vc6.exe" /libpath:"$(XTESTS_C_ROOT)/lib" /libpath:"$(FASTFORMAT_ROOT)/lib" /libpath:"$(SHWILD_ROOT)/lib"
# ADD LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /machine:I386 /out:"../../../../bin/example.flush.vc6.exe" /libpath:"$(FASTFORMAT_ROOT)/lib"

!ELSEIF  "$(CFG)" == "example.flush - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GR /GX /Zi /Od /I "$(XTESTS_C_ROOT)/include" /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_CONSOLE" /FD /GZ /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_CONSOLE" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /debug /machine:I386 /out:"../../../../bin/example.flush.vc6.debug.exe" /pdbtype:sept /libpath:"$(XTESTS_C_ROOT)/lib" /libpath:"$(FASTFORMAT_ROOT)/lib" /libpath:"$(SHWILD_ROOT)/lib"
# ADD LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /debug /machine:I386 /out:"../../../../bin/example.flush.vc6.debug.exe" /pdbtype:sept /libpath:"$(FASTFORMAT_ROOT)/lib"

!ELSEIF  "$(CFG)" == "example.flush - Win32 Release Multithreaded"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMT"
# PROP BASE Intermediate_Dir "ReleaseMT"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMT"
# PROP Intermediate_Dir "ReleaseMT"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /WX /GR /GX /O2 /I "$(XTESTS_C_ROOT)/include" /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_CONSOLE" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MT /W3 /WX /GR /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_CONSOLE" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /machine:I386 /out:"../../../../bin/example.flush.vc6.mt.exe" /libpath:"$(XTESTS_C_ROOT)/lib" /libpath:"$(FASTFORMAT_ROOT)/lib" /libpath:"$(SHWILD_ROOT)/lib"
# ADD LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /machine:I386 /out:"../../../../bin/example.flush.vc6.mt.exe" /libpath:"$(FASTFORMAT_ROOT)/lib"

!ELSEIF  "$(CFG)" == "example.flush - Win32 Debug Multithreaded"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugMT"
# PROP BASE Intermediate_Dir "DebugMT"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugMT"
# PROP Intermediate_Dir "DebugMT"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GR /GX /Zi /Od /I "$(XTESTS_C_ROOT)/include" /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_CONSOLE" /FD /GZ /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MTd /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_CONSOLE" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /debug /machine:I386 /out:"../../../../bin/example.flush.vc6.mt.debug.exe" /pdbtype:sept /libpath:"$(XTESTS_C_ROOT)/lib" /libpath:"$(FASTFORMAT_ROOT)/lib" /libpath:"$(SHWILD_ROOT)/lib"
# ADD LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /debug /machine:I386 /out:"../../../../bin/example.flush.vc6.mt.debug.exe" /pdbtype:sept /libpath:"$(FASTFORMAT_ROOT)/lib"

!ELSEIF  "$(CFG)" == "example.flush - Win32 Release Multithreaded DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseDLL"
# PROP BASE Intermediate_Dir "ReleaseDLL"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseDLL"
# PROP Intermediate_Dir "ReleaseDLL"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /WX /GR /GX /O2 /I "$(XTESTS_C_ROOT)/include" /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_CONSOLE" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MD /W3 /WX /GR /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_CONSOLE" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /machine:I386 /out:"../../../../bin/example.flush.vc6.dll.exe" /libpath:"$(XTESTS_C_ROOT)/lib" /libpath:"$(FASTFORMAT_ROOT)/lib" /libpath:"$(SHWILD_ROOT)/lib"
# ADD LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /machine:I386 /out:"../../../../bin/example.flush.vc6.dll.exe" /libpath:"$(FASTFORMAT_ROOT)/lib"

!ELSEIF  "$(CFG)" == "example.flush - Win32 Debug Multithreaded DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugDLL"
# PROP BASE Intermediate_Dir "DebugDLL"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugDLL"
# PROP Intermediate_Dir "DebugDLL"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /I "$(XTESTS_C_ROOT)/include" /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_CONSOLE" /FD /GZ /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_CONSOLE" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /debug /machine:I386 /out:"../../../../bin/example.flush.vc6.dll.debug.exe" /pdbtype:sept /libpath:"$(XTESTS_C_ROOT)/lib" /libpath:"$(FASTFORMAT_ROOT)/lib" /libpath:"$(SHWILD_ROOT)/lib"
# ADD LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /debug /machine:I386 /out:"../../../../bin/example.flush.vc6.dll.debug.exe" /pdbtype:sept /libpath:"$(FASTFORMAT_ROOT)/lib"

!ELSEIF  "$(CFG)" == "example.flush - Win32 Unicode Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "URelease"
# PROP BASE Intermediate_Dir "URelease"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "URelease"
# PROP Intermediate_Dir "URelease"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /WX /GR /GX /O2 /I "$(XTESTS_C_ROOT)/include" /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_UNICODE" /D "UNICODE" /D "_CONSOLE" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /W3 /WX /GR /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_UNICODE" /D "UNICODE" /D "_CONSOLE" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /machine:I386 /out:"../../../../bin/example.flush.vc6.widestring.exe" /libpath:"$(XTESTS_C_ROOT)/lib" /libpath:"$(FASTFORMAT_ROOT)/lib" /libpath:"$(SHWILD_ROOT)/lib"
# ADD LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /machine:I386 /out:"../../../../bin/example.flush.vc6.widestring.exe" /libpath:"$(FASTFORMAT_ROOT)/lib"

!ELSEIF  "$(CFG)" == "example.flush - Win32 Unicode Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "UDebug"
# PROP BASE Intermediate_Dir "UDebug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "UDebug"
# PROP Intermediate_Dir "UDebug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GR /GX /Zi /Od /I "$(XTESTS_C_ROOT)/include" /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_UNICODE" /D "UNICODE" /D "_CONSOLE" /FD /GZ /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_UNICODE" /D "UNICODE" /D "_CONSOLE" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /debug /machine:I386 /out:"../../../../bin/example.flush.vc6.widestring.debug.exe" /pdbtype:sept /libpath:"$(XTESTS_C_ROOT)/lib" /libpath:"$(FASTFORMAT_ROOT)/lib" /libpath:"$(SHWILD_ROOT)/lib"
# ADD LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /debug /machine:I386 /out:"../../../../bin/example.flush.vc6.widestring.debug.exe" /pdbtype:sept /libpath:"$(FASTFORMAT_ROOT)/lib"

!ELSEIF  "$(CFG)" == "example.flush - Win32 Unicode Release Multithreaded"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "UReleaseMT"
# PROP BASE Intermediate_Dir "UReleaseMT"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "UReleaseMT"
# PROP Intermediate_Dir "UReleaseMT"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /WX /GR /GX /O2 /I "$(XTESTS_C_ROOT)/include" /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_UNICODE" /D "UNICODE" /D "_CONSOLE" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MT /W3 /WX /GR /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_UNICODE" /D "UNICODE" /D "_CONSOLE" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /machine:I386 /out:"../../../../bin/example.flush.vc6.widestring.mt.exe" /libpath:"$(XTESTS_C_ROOT)/lib" /libpath:"$(FASTFORMAT_ROOT)/lib" /libpath:"$(SHWILD_ROOT)/lib"
# ADD LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /machine:I386 /out:"../../../../bin/example.flush.vc6.widestring.mt.exe" /libpath:"$(FASTFORMAT_ROOT)/lib"

!ELSEIF  "$(CFG)" == "example.flush - Win32 Unicode Debug Multithreaded"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "UDebugMT"
# PROP BASE Intermediate_Dir "UDebugMT"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "UDebugMT"
# PROP Intermediate_Dir "UDebugMT"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GR /GX /Zi /Od /I "$(XTESTS_C_ROOT)/include" /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_UNICODE" /D "UNICODE" /D "_CONSOLE" /FD /GZ /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MTd /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_UNICODE" /D "UNICODE" /D "_CONSOLE" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /debug /machine:I386 /out:"../../../../bin/example.flush.vc6.widestring.mt.debug.exe" /pdbtype:sept /libpath:"$(XTESTS_C_ROOT)/lib" /libpath:"$(FASTFORMAT_ROOT)/lib" /libpath:"$(SHWILD_ROOT)/lib"
# ADD LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /debug /machine:I386 /out:"../../../../bin/example.flush.vc6.widestring.mt.debug.exe" /pdbtype:sept /libpath:"$(FASTFORMAT_ROOT)/lib"

!ELSEIF  "$(CFG)" == "example.flush - Win32 Unicode Release Multithreaded DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "UReleaseDLL"
# PROP BASE Intermediate_Dir "UReleaseDLL"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "UReleaseDLL"
# PROP Intermediate_Dir "UReleaseDLL"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /WX /GR /GX /O2 /I "$(XTESTS_C_ROOT)/include" /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_UNICODE" /D "UNICODE" /D "_CONSOLE" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MD /W3 /WX /GR /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_UNICODE" /D "UNICODE" /D "_CONSOLE" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /machine:I386 /out:"../../../../bin/example.flush.vc6.widestring.dll.exe" /libpath:"$(XTESTS_C_ROOT)/lib" /libpath:"$(FASTFORMAT_ROOT)/lib" /libpath:"$(SHWILD_ROOT)/lib"
# ADD LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /machine:I386 /out:"../../../../bin/example.flush.vc6.widestring.dll.exe" /libpath:"$(FASTFORMAT_ROOT)/lib"

!ELSEIF  "$(CFG)" == "example.flush - Win32 Unicode Debug Multithreaded DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "UDebugDLL"
# PROP BASE Intermediate_Dir "UDebugDLL"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "UDebugDLL"
# PROP Intermediate_Dir "UDebugDLL"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /I "$(XTESTS_C_ROOT)/include" /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_UNICODE" /D "UNICODE" /D "_CONSOLE" /FD /GZ /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_UNICODE" /D "UNICODE" /D "_CONSOLE" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /debug /machine:I386 /out:"../../../../bin/example.flush.vc6.widestring.dll.debug.exe" /pdbtype:sept /libpath:"$(XTESTS_C_ROOT)/lib" /libpath:"$(FASTFORMAT_ROOT)/lib" /libpath:"$(SHWILD_ROOT)/lib"
# ADD LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /debug /machine:I386 /out:"../../../../bin/example.flush.vc6.widestring.dll.debug.exe" /pdbtype:sept /libpath:"$(FASTFORMAT_ROOT)/lib"

!ELSEIF  "$(CFG)" == "example.flush - Win32 Release pseudoUNIX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseUNIX"
# PROP BASE Intermediate_Dir "ReleaseUNIX"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseUNIX"
# PROP Intermediate_Dir "ReleaseUNIX"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /WX /GR /GX /O2 /I "$(XTESTS_C_ROOT)/include" /I "../../../../include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /I "$(PTHREADS_WIN32)/include" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "NDEBUG" /D "_MBCS" /D "_CONSOLE" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /W3 /WX /GR /GX /O2 /I "$(UNIXEM)/include" /I "$(PTHREADS_WIN32)/include" /I "../../../include" /I "$(STLSOFT)/include" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "NDEBUG" /D "_MBCS" /D "_CONSOLE" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /machine:I386 /out:"../../../../bin/example.flush.vc6.unix.exe" /libpath:"$(XTESTS_C_ROOT)/lib" /libpath:"$(FASTFORMAT_ROOT)/lib" /libpath:"$(SHWILD_ROOT)/lib"
# ADD LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /machine:I386 /out:"../../../../bin/example.flush.vc6.unix.exe" /libpath:"$(FASTFORMAT_ROOT)/lib"

!ELSEIF  "$(CFG)" == "example.flush - Win32 Debug pseudoUNIX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugUNIX"
# PROP BASE Intermediate_Dir "DebugUNIX"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugUNIX"
# PROP Intermediate_Dir "DebugUNIX"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GR /GX /Zi /Od /I "$(XTESTS_C_ROOT)/include" /I "../../../../include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /I "$(PTHREADS_WIN32)/include" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "_DEBUG" /D "_MBCS" /D "_CONSOLE" /FD /GZ /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /W3 /Gm /GR /GX /Zi /Od /I "$(UNIXEM)/include" /I "$(PTHREADS_WIN32)/include" /I "../../../include" /I "$(STLSOFT)/include" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "_DEBUG" /D "_MBCS" /D "_CONSOLE" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /debug /machine:I386 /out:"../../../../bin/example.flush.vc6.unix.debug.exe" /pdbtype:sept /libpath:"$(XTESTS_C_ROOT)/lib" /libpath:"$(FASTFORMAT_ROOT)/lib" /libpath:"$(SHWILD_ROOT)/lib"
# ADD LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /debug /machine:I386 /out:"../../../../bin/example.flush.vc6.unix.debug.exe" /pdbtype:sept /libpath:"$(FASTFORMAT_ROOT)/lib"

!ELSEIF  "$(CFG)" == "example.flush - Win32 Release Multithreaded pseudoUNIX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMTUNIX"
# PROP BASE Intermediate_Dir "ReleaseMTUNIX"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMTUNIX"
# PROP Intermediate_Dir "ReleaseMTUNIX"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /WX /GR /GX /O2 /I "$(XTESTS_C_ROOT)/include" /I "../../../../include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /I "$(PTHREADS_WIN32)/include" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "NDEBUG" /D "_MBCS" /D "_CONSOLE" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MT /W3 /WX /GR /GX /O2 /I "$(UNIXEM)/include" /I "$(PTHREADS_WIN32)/include" /I "../../../include" /I "$(STLSOFT)/include" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "NDEBUG" /D "_MBCS" /D "_CONSOLE" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /machine:I386 /out:"../../../../bin/example.flush.vc6.unix.mt.exe" /libpath:"$(XTESTS_C_ROOT)/lib" /libpath:"$(FASTFORMAT_ROOT)/lib" /libpath:"$(SHWILD_ROOT)/lib"
# ADD LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /machine:I386 /out:"../../../../bin/example.flush.vc6.unix.mt.exe" /libpath:"$(FASTFORMAT_ROOT)/lib"

!ELSEIF  "$(CFG)" == "example.flush - Win32 Debug Multithreaded pseudoUNIX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugMTUNIX"
# PROP BASE Intermediate_Dir "DebugMTUNIX"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugMTUNIX"
# PROP Intermediate_Dir "DebugMTUNIX"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GR /GX /Zi /Od /I "$(XTESTS_C_ROOT)/include" /I "../../../../include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /I "$(PTHREADS_WIN32)/include" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "_DEBUG" /D "_MBCS" /D "_CONSOLE" /FD /GZ /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MTd /W3 /Gm /GR /GX /Zi /Od /I "$(UNIXEM)/include" /I "$(PTHREADS_WIN32)/include" /I "../../../include" /I "$(STLSOFT)/include" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "_DEBUG" /D "_MBCS" /D "_CONSOLE" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /debug /machine:I386 /out:"../../../../bin/example.flush.vc6.unix.mt.debug.exe" /pdbtype:sept /libpath:"$(XTESTS_C_ROOT)/lib" /libpath:"$(FASTFORMAT_ROOT)/lib" /libpath:"$(SHWILD_ROOT)/lib"
# ADD LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /debug /machine:I386 /out:"../../../../bin/example.flush.vc6.unix.mt.debug.exe" /pdbtype:sept /libpath:"$(FASTFORMAT_ROOT)/lib"

!ELSEIF  "$(CFG)" == "example.flush - Win32 Release Multithreaded DLL pseudoUNIX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseDLLUNIX"
# PROP BASE Intermediate_Dir "ReleaseDLLUNIX"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseDLLUNIX"
# PROP Intermediate_Dir "ReleaseDLLUNIX"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /WX /GR /GX /O2 /I "$(XTESTS_C_ROOT)/include" /I "../../../../include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /I "$(PTHREADS_WIN32)/include" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "NDEBUG" /D "_MBCS" /D "_CONSOLE" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MD /W3 /WX /GR /GX /O2 /I "$(UNIXEM)/include" /I "$(PTHREADS_WIN32)/include" /I "../../../include" /I "$(STLSOFT)/include" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "NDEBUG" /D "_MBCS" /D "_CONSOLE" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /machine:I386 /out:"../../../../bin/example.flush.vc6.unix.dll.exe" /libpath:"$(XTESTS_C_ROOT)/lib" /libpath:"$(FASTFORMAT_ROOT)/lib" /libpath:"$(SHWILD_ROOT)/lib"
# ADD LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /machine:I386 /out:"../../../../bin/example.flush.vc6.unix.dll.exe" /libpath:"$(FASTFORMAT_ROOT)/lib"

!ELSEIF  "$(CFG)" == "example.flush - Win32 Debug Multithreaded DLL pseudoUNIX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugDLLUNIX"
# PROP BASE Intermediate_Dir "DebugDLLUNIX"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugDLLUNIX"
# PROP Intermediate_Dir "DebugDLLUNIX"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /I "$(XTESTS_C_ROOT)/include" /I "../../../../include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /I "$(PTHREADS_WIN32)/include" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "_DEBUG" /D "_MBCS" /D "_CONSOLE" /FD /GZ /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /I "$(UNIXEM)/include" /I "$(PTHREADS_WIN32)/include" /I "../../../include" /I "$(STLSOFT)/include" /D "UNIX" /D "_STLSOFT_FORCE_ANY_COMPILER" /D "_DEBUG" /D "_MBCS" /D "_CONSOLE" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /debug /machine:I386 /out:"../../../../bin/example.flush.vc6.unix.dll.debug.exe" /pdbtype:sept /libpath:"$(XTESTS_C_ROOT)/lib" /libpath:"$(FASTFORMAT_ROOT)/lib" /libpath:"$(SHWILD_ROOT)/lib"
# ADD LINK32 kernel32.lib advapi32.lib ole32.lib oleaut32.lib /nologo /subsystem:console /debug /machine:I386 /out:"../../../../bin/example.flush.vc6.unix.dll.debug.exe" /pdbtype:sept /libpath:"$(FASTFORMAT_ROOT)/lib"

!ENDIF 

# Begin Target

# Name "example.flush - Win32 Release"
# Name "example.flush - Win32 Debug"
# Name "example.flush - Win32 Release Multithreaded"
# Name "example.flush - Win32 Debug Multithreaded"
# Name "example.flush - Win32 Release Multithreaded DLL"
# Name "example.flush - Win32 Debug Multithreaded DLL"
# Name "example.flush - Win32 Unicode Release"
# Name "example.flush - Win32 Unicode Debug"
# Name "example.flush - Win32 Unicode Release Multithreaded"
# Name "example.flush - Win32 Unicode Debug Multithreaded"
# Name "example.flush - Win32 Unicode Release Multithreaded DLL"
# Name "example.flush - Win32 Unicode Debug Multithreaded DLL"
# Name "example.flush - Win32 Release pseudoUNIX"
# Name "example.flush - Win32 Debug pseudoUNIX"
# Name "example.flush - Win32 Release Multithreaded pseudoUNIX"
# Name "example.flush - Win32 Debug Multithreaded pseudoUNIX"
# Name "example.flush - Win32 Release Multithreaded DLL pseudoUNIX"
# Name "example.flush - Win32 Debug Multithreaded DLL pseudoUNIX"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\example.flush.cpp
# End Source File
# Begin Source File

SOURCE=..\implicit_link.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "STLSoft Header Files"

# PROP Default_Filter ""
# Begin Group "STLSoft"

# PROP Default_Filter ""
# End Group
# Begin Group "PlatformSTL"

# PROP Default_Filter ""
# End Group
# Begin Group "UNIXSTL"

# PROP Default_Filter ""
# End Group
# Begin Group "WinSTL"

# PROP Default_Filter ""
# End Group
# End Group
# Begin Group "FastFormat Header Files"

# PROP Default_Filter ""
# End Group
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\memory\allocator_features.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\memory\allocator_selector.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\algorithms\std\alt.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\include\fastformat\internal\generated\api_functions.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\memory\auto_buffer.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\shims\access\string\std\basic_string.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\shims\access\string\std\c_string.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\meta\capabilities.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\string\char_traits.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\collections\util\collections.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\util\constraints.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\include\fastformat\quality\contract.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\fastformat\quality\cover.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\winstl\error\error_functions.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\shims\access\string\std\exception.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\util\exception_string.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\include\fastformat\exceptions.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\platformstl\error\exceptions.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\error\exceptions.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\winstl\error\exceptions.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\include\fastformat\shims\conversion\filter_type\fast_integers.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\include\fastformat\fastformat.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\fastformat\fastformat.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\include\fastformat\ff.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\shims\access\string\fwd.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\fastformat\shims\action\fmt_slices\generic_string.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\include\fastformat\internal\generated\helper_functions.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\include\fastformat\util\sinks\helpers.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\include\fastformat\implicit_link.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\fastformat\internal\initialiser.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\conversion\integer_to_string.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\meta\is_integral_type.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\meta\is_pointer_type.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\meta\is_same_type.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\util\std\iterator_helper.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\util\std\library_discriminator.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\meta\util\meta_.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\internal\cccap\msvc.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\meta\n_types.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\internal\cccap\obsolete.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\error\os_exception.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\include\fastformat\sinks\ostream.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\platformstl\platformstl.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\platformstl\platformstl.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\algorithms\pod.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\error\project_exception.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\internal\safestr.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\smartptr\scoped_handle.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\include\fastformat\internal\shim_macros.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\string\shim_string.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\util\sign_traits.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\meta\size_of.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\util\size_traits.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\include\fastformat\format\standard_flags.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\util\std_swap.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\include\fastformat\internal\stlsoft.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\stlsoft.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\shims\access\string.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\include\fastformat\internal\string_encoding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\string\string_traits.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\string\string_traits_fwd.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\string\string_view.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\error\throw_policies.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\winstl\winstl.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\STLSoft\Releases\1.9\STLSoft\include\stlsoft\meta\yesno.hpp
# End Source File
# End Group
# End Target
# End Project
