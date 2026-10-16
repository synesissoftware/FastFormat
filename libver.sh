#! /bin/bash

ScriptPath=$0
Dir=$(cd "$(dirname "$ScriptPath")" && pwd)
Basename=$(basename "$ScriptPath")
CMakeDir=${SIS_CMAKE_BUILD_DIR:-$Dir/_build}
MakeCmd=${SIS_CMAKE_COMMAND:-make}
ProjectNameFile="$Dir/.sis/project_name.txt"
ProjectName=$(tr -d '[:space:]' < "$ProjectNameFile")

ListOnly=0
RunMake=1


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

  case $1 in
    -l|--list-only)

      ListOnly=1
      ;;
    -M|--no-make)

      RunMake=0
      ;;
    --help)

      [ -f "$Dir/.sis/script_info_lines.txt" ] && cat "$Dir/.sis/script_info_lines.txt"
      cat << EOF
Builds (unless suppressed) and runs the ${ProjectName} libver program

$ScriptPath [ ... flags/options ... ]

Flags/options:

    behaviour:

    -l
    --list-only
        lists the libver program path but does not execute it

    -M
    --no-make
        does not execute make before running libver


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

    echo "Executing build (via command \`$MakeCmd\`) and then running ${ProjectName} libver"

    mkdir -p $CMakeDir || exit 1

    cd $CMakeDir

    $MakeCmd libver
    status=$?

    cd ->/dev/null
  fi
else

  if [ ! -d "$CMakeDir" ] || [ ! -f "$CMakeDir/CMakeCache.txt" ] || [ ! -d "$CMakeDir/CMakeFiles" ]; then

    >&2 echo "$ScriptPath: cannot run in '--no-make' mode without a previous successful build step"

    exit 1
  fi
fi

if [ $status -eq 0 ]; then

  LibVerExe=$(find "$CMakeDir" -type f -name 'libver' -exec test -x {} \; -print | head -1)

  if [ -z "$LibVerExe" ]; then

    # Windows / MinGW may emit libver.exe
    LibVerExe=$(find "$CMakeDir" -type f \( -name 'libver' -o -name 'libver.exe' \) -print | head -1)
  fi

  if [ -z "$LibVerExe" ]; then

    >&2 echo "$ScriptPath: libver executable not found under '$CMakeDir'"

    exit 1
  fi

  if [ $ListOnly -ne 0 ]; then

    echo "would execute $LibVerExe:"
  else

    echo "Running ${ProjectName} libver ($LibVerExe):"

    "$LibVerExe"
    status=$?
  fi
fi

exit $status


# ############################## end of file ############################# #
