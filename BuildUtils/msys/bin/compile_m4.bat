@echo off

REM --- Get current working directory and tool directory ---
set TOOL_DIR=%~d0%~p0
set BUILD_DIR=%~d1%~p1
set BUILD_FILE=%~d1%~p1%~n1%~x1
set file=%~n1%~x1

echo ======================================================================================
echo .	m4-file:	%file%
echo .	tool:		compile_m4.py
echo .	
echo .	TOOL_DIR=%TOOL_DIR%
echo .	BUILD_DIR=%BUILD_DIR%
echo .	BUILD_FILE=%BUILD_FILE%
echo ======================================================================================

REM --- Extract the file postfix to get the m4 file type ---
set filetype=%file:~-6%
REM echo %filetype%

REM --- Find the directory of the components folder ---
set ppath=""
call %TOOL_DIR%\findroot.bat

REM --- check if path was found ---
IF "%ppath%" == "" goto error

REM --- compile interface ---
IF %filetype% == Itf.m4 python %TOOL_DIR%/compile_m4.py -d -m %TOOL_DIR%/../../M4Defs %BUILD_FILE% & goto end

REM --- compile dependencies ---
IF %filetype% == Dep.m4 python %TOOL_DIR%/compile_m4.py -i -m %TOOL_DIR%/../../M4Defs %BUILD_FILE% & goto end

:end
echo %file% processed
goto finish

REM --- usage ---
:usage
print "usage: %0 <m4-filename>"

REM --- finale ---
:final
rem pause

rem exit

REM --- error ---
:error
echo "error, path not found"
pause

:finish