#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakeDir=${SIS_CMAKE_BUILD_DIR:-$Dir/_build}
[[ -n "$MSYSTEM" ]] && DefaultMakeCmd=mingw32-make.exe || DefaultMakeCmd=make
MakeCmd=${SIS_CMAKE_MAKE_COMMAND:-${SIS_CMAKE_COMMAND:-$DefaultMakeCmd}}
ProjectNameFile="$Dir/.sis/project_name.txt"
ProjectName=$(tr -d '[:space:]' < "$ProjectNameFile")

ListOnly=0
RunMake=1
Verbosity=${XTESTS_VERBOSITY:-${TEST_VERBOSITY:-3}}


# ##########################################################
# colours

if command -v tput > /dev/null; then

  RbEnvClr_Blue=${FG_BLUE:-$(tput setaf 4)}
  RbEnvClr_Red=${FG_BLUE:-$(tput setaf 1)}
  RbEnvClr_Bold=${FD_BOLD:-$(tput bold)}
  RbEnvClr_None=${FD_NONE:-$(tput sgr0)}
else

  RbEnvClr_Blue=
  RbEnvClr_Red=
  RbEnvClr_Bold=
  RbEnvClr_None=
fi


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

  case $1 in
    --list-only|-l)

      ListOnly=1
      ;;
    --no-make|-M)

      RunMake=0
      ;;
    --verbosity)

      shift
      Verbosity=$1
      ;;
    --help)

      [ -f "$Dir/.sis/script_info_lines.txt" ] && cat "$Dir/.sis/script_info_lines.txt"
      cat << EOF
Runs all (matching) performance-test and scratch-test programs

$ScriptPath [ ... flags/options ... ]

Flags/options:

    behaviour:

    -l
    --list-only
        lists the target programs but does not execute them

    -M
    --no-make
        does not execute CMake and make before running tests

    --verbosity <verbosity>
        specifies an explicit verbosity for the unit-test(s)


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

status=0

if [ $RunMake -ne 0 ]; then

  if [ $ListOnly -eq 0 ]; then

    echo "Executing build (via command \`$MakeCmd\`) and then running all ${ProjectName} scratch (and performance) test programs"

    mkdir -p $CMakeDir || exit 1

    cd $CMakeDir

    $MakeCmd
    status=$?

    cd ->/dev/null
  fi
else

  if [ ! -d "$CMakeDir" ] || [ ! -f "$CMakeDir/CMakeCache.txt" ] || [ ! -d "$CMakeDir/CMakeFiles" ]; then

    >&2 echo "$ScriptPath: cannot run in '--no-make' mode without a previous successful build step"
  fi
fi

if [ $status -eq 0 ]; then

  if [ $ListOnly -ne 0 ]; then

    echo "Listing all ${ProjectName} scratch (and performance) test programs"
  else

    echo "Running all ${ProjectName} scratch (and performance) test programs"
  fi

  for f in $(find $CMakeDir -type f '(' -name 'test_scratch*' -o -name 'test.scratch.*' -o -name 'test_performance*' -o -name 'test.performance.*' ')' -exec test -x {} \; -print)
  do

    if [ $ListOnly -ne 0 ]; then

      echo "would execute $RbEnvClr_Blue$RbEnvClr_Bold$f$RbEnvClr_None:"

      continue
    fi

    if [ $Verbosity -ge 3 ]; then

      echo
    fi
    if [ $Verbosity -ge 2 ]; then

      echo "executing $RbEnvClr_Blue$RbEnvClr_Bold$f$RbEnvClr_None:"
    fi

    if $f; then

      :
    else

      status=$?
    fi
  done
fi

exit $status


# ############################## end of file ############################# #

