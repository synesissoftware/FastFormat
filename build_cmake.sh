#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakeDir=${SIS_CMAKE_BUILD_DIR:-$Dir/_build}
[[ -n "$MSYSTEM" ]] && DefaultMakeCmd=mingw32-make.exe || DefaultMakeCmd=make
MakeCmd=${SIS_CMAKE_MAKE_COMMAND:-${SIS_CMAKE_COMMAND:-$DefaultMakeCmd}}
ProjectNameFile="$Dir/.sis/project_name.txt"
ProjectName=$(tr -d '[:space:]' < "$ProjectNameFile")

IgnoreRemainingFlagsAndOptions=0
Targets=()


# ##########################################################
# functions

function join_by { local IFS="$1"; shift; echo "$*"; }


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

  if [ $IgnoreRemainingFlagsAndOptions -ne 0 ]; then

    Targets+=($1)

    shift

    continue
  else

    if [ ! ${1:0:1} = '-' ]; then

      Targets+=($1)

      shift

      continue
    fi
  fi

  case $1 in
    --)

      IgnoreRemainingFlagsAndOptions=1
      ;;
    --help)

      [ -f "$Dir/.sis/script_info_lines.txt" ] && cat "$Dir/.sis/script_info_lines.txt"
      cat << EOF
Executes CMake-generated artefacts to (re)build project

$ScriptPath [ ... flags/options ... ]

Flags/options:

    behaviour:


    standard flags:

    --help
        displays this help and terminates

EOF

      exit 0
      ;;
    *)

      >&2 echo "$ScriptPath: unrecognised argument '$1'; use --help for usage"

      exit 1
      ;;
  esac

  shift
done


# ##########################################################
# main()

if [ ! -d "$CMakeDir" ]; then

  >&2 echo "$ScriptPath: CMake build directory '$CMakeDir' not found so nothing to do; use script 'prepare_cmake.sh' if you wish to prepare CMake artefacts"

  exit 1
else

  cd $CMakeDir

  if [ ! -f "$CMakeDir/Makefile" ]; then

    >&2 echo "$ScriptPath: CMake build directory '$CMakeDir' does not contain expected file 'Makefile', so a clean cannot be performed. It is recommended that you remove all CMake artefacts using script 'remove_cmake_artefacts.sh' followed by regeneration via 'prepare_cmake.sh'"

    cd ->/dev/null

    exit 1
  else

    if [ -z "$Targets" ]; then

      echo "Executing build for ${ProjectName} (via command \`$MakeCmd\`)"
    else

      echo "Executing build for ${ProjectName} (via command \`$MakeCmd\`) with specific target(s) $(join_by , "${Targets[@]}")"
    fi

    $MakeCmd ${Targets[*]}
    status=$?

    cd ->/dev/null

    exit $status
  fi
fi


# ############################## end of file ############################# #

