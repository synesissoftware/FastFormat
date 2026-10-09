#! /bin/bash

# ##########################################################
# constants and variables

Basename=$(basename "$0")
Dir=$(cd "$(dirname "$0")" && pwd)
CMakeDir=${SIS_CMAKE_BUILD_DIR:-$Dir/_build}
ProjectNameFile="$Dir/.sis/project_name.txt"
ProjectName=$(tr -d '[:space:]' < "$ProjectNameFile")
ScriptPath=$0

AlwaysUseColours=${SIS_CMAKE_ALWAYS_USE_COLOURS:-${SIS_ALWAYS_USE_COLOURS:-0}}
ComponentOnly=0
ForwardedArgs=()
SisUseColours=0
UnitOnly=0


# ##########################################################
# colours
#
# Enable when tput is available and either:
#   - AlwaysUseColours is set (overrides NO_COLOR; may set TERM if
#     empty/dumb), or
#   - NO_COLOR is unset, stdout is a TTY, and TERM is not dumb (union of
#     collect-c's "TERM set + TTY" and cstring's "TTY" — empty TERM on a
#     TTY is OK).

SisClr_Blue=
SisClr_Bold=
SisClr_Green=
SisClr_None=
SisClr_Red=
SisClr_Yellow=

for arg in "$@"; do

  case $arg in
    --always-use-colors|--always-use-colours|-A)

      AlwaysUseColours=1
      ;;
  esac
done

if command -v tput >/dev/null 2>&1; then

  if [ $AlwaysUseColours -ne 0 ]; then

    if [ -z "${TERM:-}" ] || [ "$TERM" = "dumb" ]; then

      TERM=xterm-256color
    fi

    SisUseColours=1
  elif [ -z "${NO_COLOR:-}" ] && [ -t 1 ] && [ "${TERM:-}" != "dumb" ]; then

    SisUseColours=1
  fi
fi

if [ $SisUseColours -ne 0 ]; then

  SisClr_Blue=${FG_BLUE:-$(tput setaf 4)}
  SisClr_Bold=${FD_BOLD:-$(tput bold)}
  SisClr_Green=${FG_GREEN:-$(tput setaf 2)}
  SisClr_None=${FD_NONE:-$(tput sgr0)}
  SisClr_Red=${FG_RED:-$(tput setaf 1)}
  SisClr_Yellow=${FG_YELLOW:-$(tput setaf 3)}
fi

ProjectNameClr="${SisClr_Blue}${SisClr_Bold}${ProjectName}${SisClr_None}"
ScriptPathClr="${SisClr_Blue}${SisClr_Bold}${ScriptPath}${SisClr_None}"


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

  case $1 in
    --always-use-colors|--always-use-colours|-A)

      # AlwaysUseColours=1 - handled above; forward so category runners see it
      ForwardedArgs+=("$1")
      ;;
    --unit-only)

      UnitOnly=1
      ;;
    --component-only)

      ComponentOnly=1
      ;;
    --help)

      [ -f "$Dir/.sis/script_info_lines.txt" ] && cat "$Dir/.sis/script_info_lines.txt"
      cat << EOF
Runs all (matching) automated test programs (unit and component)

${ScriptPath} [ ... flags/options ... ]

Flags/options:

    behaviour:

    -A
    --always-use-colors
    --always-use-colours
        forces use of colours even when stdout is not a TTY

    --component-only
        runs only component-test programs

    --unit-only
        runs only unit-test programs

    (all other flags are forwarded to the category runner script)


    standard flags:

    --help
        displays this help and terminates

EOF

      exit 0
      ;;
    *)

      ForwardedArgs+=("$1")
      ;;
  esac

  shift
done

if [ $UnitOnly -ne 0 ] && [ $ComponentOnly -ne 0 ]; then

  >&2 echo "${ScriptPathClr}: ${SisClr_Red}${SisClr_Bold}--unit-only${SisClr_None} and ${SisClr_Red}${SisClr_Bold}--component-only${SisClr_None} are mutually exclusive"

  exit 1
fi


# ##########################################################
# main()

status=0

if [ $UnitOnly -ne 0 ]; then

  "$Dir/run_all_unit_tests.sh" "${ForwardedArgs[@]}"
  exit $?
fi

if [ $ComponentOnly -ne 0 ]; then

  "$Dir/run_all_component_tests.sh" "${ForwardedArgs[@]}"
  exit $?
fi

echo
echo "Running all ${ProjectNameClr} automated test programs (unit and component)"

"$Dir/run_all_unit_tests.sh" "${ForwardedArgs[@]}"
status=$?

if [ $status -eq 0 ]; then

  "$Dir/run_all_component_tests.sh" "${ForwardedArgs[@]}"
  status=$?
fi

exit $status


# ############################## end of file ############################# #
