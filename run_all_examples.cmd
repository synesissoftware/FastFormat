@echo off

SETLOCAL

SET SCRIPT_DIRECTORY=%~dp0
SET SCRIPT_PATH_DOC=%~n0[%~x0]
SET "ALLOWED_TO_FAIL_FILE=%SCRIPT_DIRECTORY%.sis\ci_examples_allowed_to_fail.txt"
SET "PROGRAM_STATUS=0"

IF DEFINED SIS_CMAKE_BUILD_DIR (

    SET CMAKE_DIR=%SIS_CMAKE_BUILD_DIR%
) ELSE (

    SET CMAKE_DIR=%SCRIPT_DIRECTORY%_build
)

FOR %%a IN (%*) DO (

	IF /I {--help}=={%%a} (

		IF EXIST "%SCRIPT_DIRECTORY%.sis\script_info_lines.txt" (

					type "%SCRIPT_DIRECTORY%.sis\script_info_lines.txt"
		)
		ECHO ^

Runs all ^(matching^) example programs ^

^

%SCRIPT_PATH_DOC% [ ... flags/options ... ] ^

^

Flags/options: ^

    behaviour: ^

^

    standard flags: ^

^

        --help ^

            displays this help and terminates ^

^

    files: ^

^

        .sis\ci_examples_allowed_to_fail.txt ^

            optional list of example programs ^(one name per line; ^

            lines beginning with '#' are ignored^) that are allowed to fail; ^

            such a program is still executed, but a non-zero exit is ^

            reported as anticipated and does not stop the run ^


		EXIT /B 0
	) ELSE (

		ECHO "%SCRIPT_DIRECTORY%: unrecognised argument '%%a'; use --help for usage" 1>&2

		EXIT /B 1
	)
)

if NOT EXIST "%CMAKE_DIR%" (

    ECHO "CMake build directory '%CMAKE_DIR%' does not exist"

    EXIT /B 1
)

SET "ProjectName="
FOR /F "usebackq delims=" %%p IN ("%SCRIPT_DIRECTORY%.sis\project_name.txt") DO SET "ProjectName=%%p"

IF NOT DEFINED ProjectName (

    ECHO %SCRIPT_PATH_DOC%: could not read project name from .sis\project_name.txt 1>&2

    EXIT /B 1
)

REM Examples that require human input may honour SIS_EXAMPLE_SMOKE for a
REM no-arg built-in tmpfile demo (see example.c.cstring_vector).
SET SIS_EXAMPLE_SMOKE=1

ECHO Running all %ProjectName% example programs

FOR /F "usebackq" %%f IN (`DIR /A:-D /B /S "%CMAKE_DIR%" ^| FINDSTR /I example.*\.exe$`) DO CALL :run_program "%%f"

ENDLOCAL & EXIT /B %PROGRAM_STATUS%


REM ##########################################################
REM subroutines

:run_program
IF %PROGRAM_STATUS% NEQ 0 EXIT /B 0
ECHO .
ECHO executing %~1
"%~1"
SET "FAILURE_STATUS=%ERRORLEVEL%"
IF %FAILURE_STATUS% EQU 0 EXIT /B 0
CALL :is_allowed_to_fail "%~1"
IF NOT DEFINED ALLOWED_TO_FAIL GOTO run_program_failed
ECHO anticipated failure: %~1 exited with status %FAILURE_STATUS%; it is listed in .sis\ci_examples_allowed_to_fail.txt
EXIT /B 0
:run_program_failed
SET "PROGRAM_STATUS=%FAILURE_STATUS%"
EXIT /B 0

:is_allowed_to_fail
SET "ALLOWED_TO_FAIL="
IF NOT EXIST "%ALLOWED_TO_FAIL_FILE%" EXIT /B 0
FOR /F "usebackq eol=# tokens=1" %%n IN ("%ALLOWED_TO_FAIL_FILE%") DO CALL :match_allowed "%%n" "%~n1" "%~nx1"
EXIT /B 0

:match_allowed
IF /I "%~1"=="%~2" SET "ALLOWED_TO_FAIL=1"
IF /I "%~1"=="%~3" SET "ALLOWED_TO_FAIL=1"
EXIT /B 0
