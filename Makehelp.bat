@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
REM echo // MAKEHELP.BAT generated Help Map file.  Used by RmtSensing.HPJ. >"hlp\RmtSensing.hm"
REM echo. >>"hlp\RmtSensing.hm"
REM echo // Commands (ID_* and IDM_*) >>"hlp\RmtSensing.hm"
REM makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\RmtSensing.hm"
REM echo. >>"hlp\RmtSensing.hm"
REM echo // Prompts (IDP_*) >>"hlp\RmtSensing.hm"
REM makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\RmtSensing.hm"
REM echo. >>"hlp\RmtSensing.hm"
REM echo // Resources (IDR_*) >>"hlp\RmtSensing.hm"
REM makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\RmtSensing.hm"
REM echo. >>"hlp\RmtSensing.hm"
REM echo // Dialogs (IDD_*) >>"hlp\RmtSensing.hm"
REM makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\RmtSensing.hm"
REM echo. >>"hlp\RmtSensing.hm"
REM echo // Frame Controls (IDW_*) >>"hlp\RmtSensing.hm"
REM makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\RmtSensing.hm"
REM REM -- Make help for Project RmtSensing

if "%1" == "?" goto :Error
if "%1" == "/?" goto :Error
if "%1" == "-?" goto :Error
if "%1" == "help" goto :Error
if "%1" == "-help" goto :Error
if "%1" == "/help" goto :Error

:Intel
if not "%1" == "" goto :Error
if not "%2" == "" goto :Error

echo Building Win32 Help files
start /wait hcrtf -x "hlp\RmtSensing.hpj"
echo.
if exist Debug\nul if exist hlp\RmtSensing.hlp copy "hlp\RmtSensing.hlp" Debug
if exist Debug\nul if exist hlp\RmtSensing.cnt copy "hlp\RmtSensing.cnt" Debug
if exist Release\nul if exist hlp\RmtSensing.hlp copy "hlp\RmtSensing.hlp" Release
if exist Release\nul if exist hlp\RmtSensing.cnt copy "hlp\RmtSensing.cnt" Release
goto :done

:Error
echo Usage MAKEHELP [MAC [macintosh-path]]
echo       Where macintosh-path is of the form:
echo       ":<MacintoshName>:...:<MacintoshHelpFile>"

:done
echo.

