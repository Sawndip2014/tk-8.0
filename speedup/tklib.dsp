# Microsoft Developer Studio Project File - Name="tklib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=tklib - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "tklib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "tklib.mak" CFG="tklib - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "tklib - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "tklib - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "tklib - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /Ot /Oi /Oy /Ob1 /Gf /Gy /D "BUILD_tk" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MT" /D "_WIN32" /D _X86_=1 /D try=__try /D except=__except /YX /FD /I /src/tk-8.0/speedup /I /src/tcl-8.0/win /I /src/tcl-8.0/generic /I /src/tk-8.0/generic /I /src/tk-8.0/bitmaps /I /src/tk-8.0/win/rc /c
# ADD BASE RSC /l 0x809
# ADD RSC /l 0x809
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "tklib - Win32 Debug"

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
# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /Z7 /Od /D "BUILD_tk" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MT" /D "_WIN32" /D _X86_=1 /D try=__try /D except=__except /YX /FD /I /src/tk-8.0/speedup /I /src/tcl-8.0/win /I /src/tcl-8.0/generic /I /src/tk-8.0/generic /I /src/tk-8.0/bitmaps /I /src/tk-8.0/win/rc /c
# ADD BASE RSC /l 0x809
# ADD RSC /l 0x809
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "tklib - Win32 Release"
# Name "tklib - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\win\stubs.c
# End Source File
# Begin Source File

SOURCE=..\generic\tk3d.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkArgv.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkAtom.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkBind.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkBitmap.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkButton.c

!IF  "$(CFG)" == "tklib - Win32 Release"

# ADD CPP /I "c:/src/tcl-8.0/win" /I "c:/src/tcl-8.0/generic" /I "c:/src/tk-8.0/win" /I "c:/src/tk-8.0/xlib" /I "c:/src/tk-8.0/bitmaps" /I "c:/src/tk-8.0/win/rc"

!ELSEIF  "$(CFG)" == "tklib - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\generic\tkCanvArc.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkCanvas.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkCanvBmap.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkCanvImg.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkCanvLine.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkCanvPoly.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkCanvPs.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkCanvText.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkCanvUtil.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkCanvWind.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkClipboard.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkCmds.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkColor.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkConfig.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkConsole.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkCursor.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkEntry.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkError.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkEvent.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkFileFilter.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkFocus.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkFont.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkFrame.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkGC.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkGeometry.c
# End Source File
# Begin Source File

SOURCE=.\tkGet.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkGrab.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkGrid.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkImage.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkImgBmap.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkImgGIF.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkImgPhoto.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkImgPPM.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkImgUtil.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkListbox.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkMacWinMenu.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkMain.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkMenu.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkMenubutton.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkMenuDraw.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkMessage.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkOption.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkPack.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkPlace.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkPointer.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkRectOval.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkScale.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkScrollbar.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkSelect.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkSquare.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkTest.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkText.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkTextBTree.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkTextDisp.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkTextImage.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkTextIndex.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkTextMark.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkTextTag.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkTextWind.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkTrig.c
# End Source File
# Begin Source File

SOURCE=..\unix\tkUnixMenubu.c
# End Source File
# Begin Source File

SOURCE=..\unix\tkUnixScale.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkUtil.c
# End Source File
# Begin Source File

SOURCE=..\generic\tkVisual.c
# End Source File
# Begin Source File

SOURCE=.\tkWin32Dll.c
# End Source File
# Begin Source File

SOURCE=.\tkWin3d.c
# End Source File
# Begin Source File

SOURCE=.\tkWinButton.c
# End Source File
# Begin Source File

SOURCE=.\tkWinClipboard.c
# End Source File
# Begin Source File

SOURCE=.\tkWinColor.c
# End Source File
# Begin Source File

SOURCE=.\tkWinCursor.c
# End Source File
# Begin Source File

SOURCE=.\tkWinDialog.c
# End Source File
# Begin Source File

SOURCE=.\tkWinDraw.c
# End Source File
# Begin Source File

SOURCE=.\tkWinEmbed.c
# End Source File
# Begin Source File

SOURCE=.\tkWinFont.c
# End Source File
# Begin Source File

SOURCE=.\tkWinGdi.c
# End Source File
# Begin Source File

SOURCE=.\tkWinImage.c
# End Source File
# Begin Source File

SOURCE=.\tkWinInit.c
# End Source File
# Begin Source File

SOURCE=.\tkWinKey.c
# End Source File
# Begin Source File

SOURCE=.\tkWinMenu.c
# End Source File
# Begin Source File

SOURCE=.\tkWinPixmap.c
# End Source File
# Begin Source File

SOURCE=.\tkWinPointer.c
# End Source File
# Begin Source File

SOURCE=.\tkWinRegion.c
# End Source File
# Begin Source File

SOURCE=.\tkWinScrlbr.c
# End Source File
# Begin Source File

SOURCE=.\tkWinSend.c
# End Source File
# Begin Source File

SOURCE=.\tkWinUtil.c
# End Source File
# Begin Source File

SOURCE=.\tkWinWindow.c
# End Source File
# Begin Source File

SOURCE=.\tkWinWm.c
# End Source File
# Begin Source File

SOURCE=.\tkWinX.c
# End Source File
# Begin Source File

SOURCE=.\xcolors.c
# End Source File
# Begin Source File

SOURCE=.\xdraw.c
# End Source File
# Begin Source File

SOURCE=.\xgc.c
# End Source File
# Begin Source File

SOURCE=.\ximage.c
# End Source File
# Begin Source File

SOURCE=.\xutil.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# End Group
# End Target
# End Project
