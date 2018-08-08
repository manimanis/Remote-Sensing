# Microsoft Developer Studio Project File - Name="RmtSensing" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=RmtSensing - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "RmtSensing.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "RmtSensing.mak" CFG="RmtSensing - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "RmtSensing - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "RmtSensing - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "RmtSensing - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x40c /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x40c /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "RmtSensing - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x40c /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x40c /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "RmtSensing - Win32 Release"
# Name "RmtSensing - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BitmapManipulations.cpp
# End Source File
# Begin Source File

SOURCE=.\ChildFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\Common.cpp
# End Source File
# Begin Source File

SOURCE=.\ComposanteB.cpp
# End Source File
# Begin Source File

SOURCE=.\ComposanteG.cpp
# End Source File
# Begin Source File

SOURCE=.\ComposanteR.cpp
# End Source File
# Begin Source File

SOURCE=.\ComposantesRGB.cpp
# End Source File
# Begin Source File

SOURCE=.\ExponentialExpansion.cpp
# End Source File
# Begin Source File

SOURCE=.\ExponentialOptimisationsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Hstogramme.cpp
# End Source File
# Begin Source File

SOURCE=.\LinearExpansion.cpp
# End Source File
# Begin Source File

SOURCE=.\LinearOptimisationDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LogarithmicExpansion.cpp
# End Source File
# Begin Source File

SOURCE=.\LogarithmicOptimisationsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LookUpTables.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\OptimisationsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PictureHistogrammeFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\PictureHistogrammeSettingsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PictureHistogrammeView.cpp
# End Source File
# Begin Source File

SOURCE=.\PIeceWiseLinearExpansion.cpp
# End Source File
# Begin Source File

SOURCE=.\PieceWiseLinearOptimisationDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\RmtSensing.cpp
# End Source File
# Begin Source File

SOURCE=.\Hlp\RmtSensing.hpj

!IF  "$(CFG)" == "RmtSensing - Win32 Release"

!ELSEIF  "$(CFG)" == "RmtSensing - Win32 Debug"

USERDEP__RMTSE="hlp\AfxCore.rtf"	"hlp\$(TargetName).hm"	
# Begin Custom Build - Making help file...
OutDir=.\Debug
TargetName=RmtSensing
InputPath=.\Hlp\RmtSensing.hpj
InputName=RmtSensing

"$(OutDir)\$(TargetName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cd 
	start /wait hcw /C /E /M "hlp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "hlp\$(InputName).hlp" goto :Error 
	copy "hlp\$(InputName).hlp" $(OutDir) 
	goto :done 
	:Error 
	echo hlp\$(InputName).hpj(1) : error: 
	type "hlp\$(InputName).log" 
	:done 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RmtSensing.rc
# End Source File
# Begin Source File

SOURCE=.\RmtSensingDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\RmtSensingFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\RmtSensingView.cpp
# End Source File
# Begin Source File

SOURCE=.\SaturatingLinearExpansion.cpp
# End Source File
# Begin Source File

SOURCE=.\SaturatingLinearOptimisationDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SplashScreen.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\BitmapManipulations.h
# End Source File
# Begin Source File

SOURCE=.\ChildFrm.h
# End Source File
# Begin Source File

SOURCE=.\Common.h
# End Source File
# Begin Source File

SOURCE=.\ComposanteB.h
# End Source File
# Begin Source File

SOURCE=.\ComposanteG.h
# End Source File
# Begin Source File

SOURCE=.\ComposanteR.h
# End Source File
# Begin Source File

SOURCE=.\ComposantesRGB.h
# End Source File
# Begin Source File

SOURCE=.\ExponentialExpansion.h
# End Source File
# Begin Source File

SOURCE=.\ExponentialOptimisationsDlg.h
# End Source File
# Begin Source File

SOURCE=.\Hstogramme.h
# End Source File
# Begin Source File

SOURCE=.\LinearExpansion.h
# End Source File
# Begin Source File

SOURCE=.\LinearOptimisationDlg.h
# End Source File
# Begin Source File

SOURCE=.\LogarithmicExpansion.h
# End Source File
# Begin Source File

SOURCE=.\LogarithmicOptimisationsDlg.h
# End Source File
# Begin Source File

SOURCE=.\LookUpTables.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\OptimisationsDlg.h
# End Source File
# Begin Source File

SOURCE=.\PictureHistogrammeFrame.h
# End Source File
# Begin Source File

SOURCE=.\PictureHistogrammeSettingsDlg.h
# End Source File
# Begin Source File

SOURCE=.\PictureHistogrammeView.h
# End Source File
# Begin Source File

SOURCE=.\PieceWiseLinearExpansion.h
# End Source File
# Begin Source File

SOURCE=.\PieceWiseLinearOptimisationDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RmtSensing.h
# End Source File
# Begin Source File

SOURCE=.\Hlp\RmtSensing.hm
# End Source File
# Begin Source File

SOURCE=.\RmtSensingDoc.h
# End Source File
# Begin Source File

SOURCE=.\RmtSensingFrame.h
# End Source File
# Begin Source File

SOURCE=.\RmtSensingView.h
# End Source File
# Begin Source File

SOURCE=.\SaturatingLinearExpansion.h
# End Source File
# Begin Source File

SOURCE=.\SaturatingLinearOptimisationDlg.h
# End Source File
# Begin Source File

SOURCE=.\SplashScreen.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\Hlp\Appexit.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00001.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp00002.bmp
# End Source File
# Begin Source File

SOURCE=.\Hlp\Bullet.bmp
# End Source File
# Begin Source File

SOURCE=.\Hlp\Curarw2.bmp
# End Source File
# Begin Source File

SOURCE=.\Hlp\Curarw4.bmp
# End Source File
# Begin Source File

SOURCE=.\Hlp\Curhelp.bmp
# End Source File
# Begin Source File

SOURCE=.\Hlp\Editcopy.bmp
# End Source File
# Begin Source File

SOURCE=.\Hlp\Editcut.bmp
# End Source File
# Begin Source File

SOURCE=.\Hlp\Editpast.bmp
# End Source File
# Begin Source File

SOURCE=.\Hlp\Editundo.bmp
# End Source File
# Begin Source File

SOURCE=.\Hlp\Filenew.bmp
# End Source File
# Begin Source File

SOURCE=.\Hlp\Fileopen.bmp
# End Source File
# Begin Source File

SOURCE=.\Hlp\Fileprnt.bmp
# End Source File
# Begin Source File

SOURCE=.\Hlp\Filesave.bmp
# End Source File
# Begin Source File

SOURCE=.\Hlp\Hlpsbar.bmp
# End Source File
# Begin Source File

SOURCE=.\Hlp\Hlptbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ico00001.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\Hlp\Maccmd.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\OptimisationRadio.bmp
# End Source File
# Begin Source File

SOURCE=.\res\outils_h.ico
# End Source File
# Begin Source File

SOURCE=.\res\pictureh.bmp
# End Source File
# Begin Source File

SOURCE=.\Hlp\Recfirst.bmp
# End Source File
# Begin Source File

SOURCE=.\Hlp\Reclast.bmp
# End Source File
# Begin Source File

SOURCE=.\Hlp\Recnext.bmp
# End Source File
# Begin Source File

SOURCE=.\Hlp\Recprev.bmp
# End Source File
# Begin Source File

SOURCE=.\res\RmtSensing.ico
# End Source File
# Begin Source File

SOURCE=.\res\RmtSensing.rc2
# End Source File
# Begin Source File

SOURCE=.\res\RmtSensingDoc.ico
# End Source File
# Begin Source File

SOURCE=.\Hlp\Scmax.bmp
# End Source File
# Begin Source File

SOURCE=.\Hlp\Scmenu.bmp
# End Source File
# Begin Source File

SOURCE=.\Hlp\Scmin.bmp
# End Source File
# Begin Source File

SOURCE=.\res\TFE.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar1.bmp
# End Source File
# End Group
# Begin Group "Help Files"

# PROP Default_Filter "*.cnt;*.rtf"
# Begin Source File

SOURCE=.\Hlp\Afxcore.rtf
# End Source File
# Begin Source File

SOURCE=.\Hlp\RmtSensing.cnt

!IF  "$(CFG)" == "RmtSensing - Win32 Release"

!ELSEIF  "$(CFG)" == "RmtSensing - Win32 Debug"

# Begin Custom Build - Copying contents file...
OutDir=.\Debug
InputPath=.\Hlp\RmtSensing.cnt
InputName=RmtSensing

"$(OutDir)\$(InputName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "hlp\$(InputName).cnt" $(OutDir)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\HLP\Winnt(gris)-flou.bmp"
# End Source File
# Begin Source File

SOURCE=".\HLP\Winnt(gris).bmp"
# End Source File
# End Group
# End Target
# End Project
