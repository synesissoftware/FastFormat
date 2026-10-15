@echo off

SETLOCAL

SET SCRIPT_DIRECTORY=%~dp0
SET SCRIPT_PATH_DOC=%~n0[%~x0]

SET UnitOnly=0
SET ComponentOnly=0

FOR %%a IN (%*) DO (

	IF /I {--help}=={%%a} (

		IF EXIST "%SCRIPT_DIRECTORY%.sis\script_info_lines.txt" (

					type "%SCRIPT_DIRECTORY%.sis\script_info_lines.txt"
		)
		ECHO ^

Runs all ^(matching^) automated test programs ^(unit and component^) ^

^

%SCRIPT_PATH_DOC% [ ... flags/options ... ] ^

^

Flags/options: ^

    behaviour: ^

^

    --unit-only ^

        runs only unit-test programs ^

^

    --component-only ^

        runs only component-test programs ^

^

    standard flags: ^

^

        --help ^

            displays this help and terminates ^


		EXIT /B 0
	) ELSE IF /I {--unit-only}=={%%a} (

		SET UnitOnly=1
	) ELSE IF /I {--component-only}=={%%a} (

		SET ComponentOnly=1
	) ELSE (

		ECHO "%SCRIPT_DIRECTORY%: unrecognised argument '%%a'; use --help for usage" 1>&2

		EXIT /B 1
	)
)

IF %UnitOnly% NEQ 0 IF %ComponentOnly% NEQ 0 (

	ECHO %SCRIPT_PATH_DOC%: --unit-only and --component-only are mutually exclusive 1>&2

	EXIT /B 1
)

IF %UnitOnly% NEQ 0 (
	CALL "%SCRIPT_DIRECTORY%run_all_unit_tests.cmd"
	EXIT /B %ERRORLEVEL%
)

IF %ComponentOnly% NEQ 0 (
	CALL "%SCRIPT_DIRECTORY%run_all_component_tests.cmd"
	EXIT /B %ERRORLEVEL%
)

SET "ProjectName="
FOR /F "usebackq delims=" %%p IN ("%SCRIPT_DIRECTORY%.sis\project_name.txt") DO SET "ProjectName=%%p"

IF NOT DEFINED ProjectName (

    ECHO %SCRIPT_PATH_DOC%: could not read project name from .sis\project_name.txt 1>&2

    EXIT /B 1
)

ECHO Running all %ProjectName% automated test programs ^(unit and component^)

CALL "%SCRIPT_DIRECTORY%run_all_unit_tests.cmd"
IF ERRORLEVEL 1 EXIT /B %ERRORLEVEL%

CALL "%SCRIPT_DIRECTORY%run_all_component_tests.cmd"
EXIT /B %ERRORLEVEL%

ENDLOCAL
