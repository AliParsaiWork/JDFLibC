# Microsoft Developer Studio Project File - Name="TestURL" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=TestURL - Win32 DebugDLL
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TestURL.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TestURL.mak" CFG="TestURL - Win32 DebugDLL"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TestURL - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "TestURL - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "TestURL - Win32 DebugDLL" (based on "Win32 (x86) Console Application")
!MESSAGE "TestURL - Win32 ReleaseDLL" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "TestURL"
# PROP Scc_LocalPath "."
CPP=xicl6.exe
RSC=rc.exe

!IF  "$(CFG)" == "TestURL - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\..\Build\Win32\VC6\Release"
# PROP Intermediate_Dir "..\..\..\..\Build\Win32\VC6\Release\Test\obj"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "..\..\..\..\external\stlport\stlport" /I "..\..\..\..\external\xerces\src" /I "..\..\..\..\external\xerces\src\xercesc" /I "..\..\..\..\src" /I "..\..\..\..\tests\testURL" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "PROJ_JDFTOOLS" /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x813 /d "NDEBUG"
# ADD RSC /l 0x813 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=xilink6.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /subsystem:console /machine:I386 /nodefaultlib:"libc.lib" /nodefaultlib:"libcd.lib" /libpath:"..\..\..\..\external\xerces\Build\Win32\VC6\Release" /libpath:"..\..\..\..\Build\Win32\Vc6\Release"

!ELSEIF  "$(CFG)" == "TestURL - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\..\Build\Win32\VC6\Debug"
# PROP Intermediate_Dir "..\..\..\..\Build\Win32\VC6\Debug\Test\obj"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /I "..\..\..\..\external\stlport\stlport" /I "..\..\..\..\external\xerces\src" /I "..\..\..\..\external\xerces\src\xercesc" /I "..\..\..\..\src" /I "..\..\..\..\tests\testURL" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "PROJ_JDFTOOLS" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x813 /d "_DEBUG"
# ADD RSC /l 0x813 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=xilink6.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib wsock32.lib /nologo /subsystem:console /debug /machine:I386 /nodefaultlib:"libc.lib" /nodefaultlib:"libcd.lib" /pdbtype:sept /libpath:"..\..\..\..\external\xerces\Build\Win32\VC6\Debug" /libpath:"..\..\..\..\Build\Win32\Vc6\Debug"

!ELSEIF  "$(CFG)" == "TestURL - Win32 DebugDLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "TestURL___Win32_DebugDLL"
# PROP BASE Intermediate_Dir "TestURL___Win32_DebugDLL"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\..\Build\Win32\VC6\DebugDLL"
# PROP Intermediate_Dir "..\..\..\..\Build\Win32\VC6\DebugDLL\Test\obj"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /I "..\..\..\..\external\xerces\src" /I "..\..\..\..\src" /I "..\..\..\..\tests\testURL" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FD /GZ /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /I "..\..\..\..\external\stlport\stlport" /I "..\..\..\..\external\xerces\src" /I "..\..\..\..\external\xerces\src\xercesc" /I "..\..\..\..\src" /I "..\..\..\..\tests\testURL" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x813 /d "_DEBUG"
# ADD RSC /l 0x813 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=xilink6.exe
# ADD BASE LINK32 kernel32.lib user32.lib wsock32.lib xerces-c_1D.lib jdftools_D.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /libpath:"..\..\..\..\external\xerces\Build\Win32\VC6\Debug" /libpath:"..\..\..\..\Build\Win32\Vc6\Debug"
# ADD LINK32 kernel32.lib user32.lib wsock32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /libpath:"..\..\..\..\external\xerces\Build\Win32\VC6\Debug" /libpath:"..\..\..\..\Build\Win32\Vc6\Debug"

!ELSEIF  "$(CFG)" == "TestURL - Win32 ReleaseDLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "TestURL___Win32_ReleaseDLL"
# PROP BASE Intermediate_Dir "TestURL___Win32_ReleaseDLL"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\..\Build\Win32\VC6\ReleaseDLL"
# PROP Intermediate_Dir "..\..\..\..\Build\Win32\VC6\ReleaseDLL\Test\obj"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GR /GX /O2 /I "..\..\..\..\external\xerces\src" /I "..\..\..\..\src" /I "..\..\..\..\tests\testURL" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "..\..\..\..\external\stlport\stlport" /I "..\..\..\..\external\xerces\src" /I "..\..\..\..\external\xerces\src\xercesc" /I "..\..\..\..\src" /I "..\..\..\..\tests\testURL" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x813 /d "NDEBUG"
# ADD RSC /l 0x813 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=xilink6.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib xerces-c_1.lib jdftools.lib /nologo /subsystem:console /machine:I386 /libpath:"..\..\..\..\external\xerces\Build\Win32\VC6\Release" /libpath:"..\..\..\..\Build\Win32\Vc6\Release"
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /subsystem:console /machine:I386 /libpath:"..\..\..\..\external\xerces\Build\Win32\VC6\Release" /libpath:"..\..\..\..\Build\Win32\Vc6\Release"

!ENDIF 

# Begin Target

# Name "TestURL - Win32 Release"
# Name "TestURL - Win32 Debug"
# Name "TestURL - Win32 DebugDLL"
# Name "TestURL - Win32 ReleaseDLL"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\..\..\tests\TestURL\notifySender1.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\tests\TestURL\passwd.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\tests\TestURL\passwd.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\tests\TestURL\startUp.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\..\..\tests\TestURL\notifySender.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=..\..\..\..\tests\TestURL\1280.ico
# End Source File
# Begin Source File

SOURCE=..\..\..\..\tests\TestURL\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\tests\TestURL\resource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\tests\TestURL\testURL.rc

!IF  "$(CFG)" == "TestURL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "TestURL - Win32 Debug"

!ELSEIF  "$(CFG)" == "TestURL - Win32 DebugDLL"

!ELSEIF  "$(CFG)" == "TestURL - Win32 ReleaseDLL"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\..\Build\Win32\VC6\Release\JDFToolsLib.lib

!IF  "$(CFG)" == "TestURL - Win32 Release"

!ELSEIF  "$(CFG)" == "TestURL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "TestURL - Win32 DebugDLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "TestURL - Win32 ReleaseDLL"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\Build\Win32\VC6\Release\jdftools.lib

!IF  "$(CFG)" == "TestURL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "TestURL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "TestURL - Win32 DebugDLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "TestURL - Win32 ReleaseDLL"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\Build\Win32\VC6\Debug\jdftoolslib_D.lib

!IF  "$(CFG)" == "TestURL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "TestURL - Win32 Debug"

!ELSEIF  "$(CFG)" == "TestURL - Win32 DebugDLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "TestURL - Win32 ReleaseDLL"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\Build\Win32\VC6\Debug\jdftools_D.lib

!IF  "$(CFG)" == "TestURL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "TestURL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "TestURL - Win32 DebugDLL"

!ELSEIF  "$(CFG)" == "TestURL - Win32 ReleaseDLL"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE="..\..\..\..\external\xerces\lib\xerces-c_2.lib"

!IF  "$(CFG)" == "TestURL - Win32 Release"

!ELSEIF  "$(CFG)" == "TestURL - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "TestURL - Win32 DebugDLL"

!ELSEIF  "$(CFG)" == "TestURL - Win32 ReleaseDLL"

!ENDIF 

# End Source File
# Begin Source File

SOURCE="..\..\..\..\external\xerces\lib\xerces-c_2D.lib"

!IF  "$(CFG)" == "TestURL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "TestURL - Win32 Debug"

!ELSEIF  "$(CFG)" == "TestURL - Win32 DebugDLL"

!ELSEIF  "$(CFG)" == "TestURL - Win32 ReleaseDLL"

!ENDIF 

# End Source File
# End Target
# End Project
