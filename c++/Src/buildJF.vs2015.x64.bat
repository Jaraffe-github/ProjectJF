@ECHO ------------------------------------------
@ECHO            JFProject for C++
@ECHO             Build Projects
@ECHO:
@ECHO      	x64 Debug/Release
@ECHO        Build for Visual Studio 2015
@ECHO ------------------------------------------
@ECHO @ Start Compile

@ECHO OFF
call "%VS140COMNTOOLS%vsvars32.bat"


:COMPILE_COMMON_CLASSES
IF EXIST "JFCommonClasses.vs2015.sln" GOTO COMPILE_3D_CLASSES
  @ECHO @ Compile JFCommon Classes
  devenv JFCommonClasses.sln /rebuild "Debug|x64"
  devenv JFCommonClasses.sln /rebuild "Debug_DLL|x64"
  devenv JFCommonClasses.sln /rebuild "Release|x64"
  devenv JFCommonClasses.sln /rebuild "Release_DLL|x64"

:COMPILE_COMPLETE
@ECHO ------------------------------------------
@ECHO @ Complete!!! (For Visual Studio 2015)
@ECHO          x64 Debug/Release
@ECHO ------------------------------------------

pause
