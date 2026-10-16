#! /bin/bash

#############################################################################
# File:     generate_doxygen.sh
#
# Purpose:  Generates HTML API documentation from public headers via Doxygen
#
#############################################################################

ScriptPath=$0
Dir=$(cd "$(dirname "$ScriptPath")" && pwd)
Basename=$(basename "$ScriptPath")
CMakeDir=${SIS_CMAKE_BUILD_DIR:-$Dir/_build}
ProjectNameFile="$Dir/.sis/project_name.txt"
ProjectName=$(tr -d '[:space:]' < "$ProjectNameFile")

DoxygenOptions=()
DoxyfilePath="$Dir/Doxyfile"
OutputDir="$CMakeDir/doxygen"
VersionHeader="$Dir/include/fastformat/fastformat.h"


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

  case $1 in
    --quiet|-q)

      DoxygenOptions=(-q)
      ;;
    --help)

      [ -f "$Dir/.sis/script_info_lines.txt" ] && cat "$Dir/.sis/script_info_lines.txt"
      cat << EOF
Generates HTML API documentation from the public headers via Doxygen

$ScriptPath [ ... flags/options ... ]

Flags/options:

    behaviour:

    -q
    --quiet
        causes the flag -q to be passed to Doxygen, which will then act as
        if QUIET=YES has been set


    standard flags:

    --help
        displays this help and terminates

Environment:

    SIS_CMAKE_BUILD_DIR
        CMake build directory (default: <project>/_build); documentation is
        written to <build-dir>/doxygen/html/

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

if ! command -v doxygen >/dev/null 2>&1; then

  >&2 echo "$ScriptPath: doxygen not found on PATH"

  exit 1
fi

if [ ! -f "$DoxyfilePath" ]; then

  >&2 echo "$ScriptPath: Doxygen configuration file '$DoxyfilePath' not found"

  exit 1
fi

# take the version from the public header, as CMakeLists.txt does, so that it
# cannot fall out of step with the PROJECT_NUMBER recorded in the Doxyfile
ProjectVersion=$(
  sed -n \
    -e 's/^#[ \t]*define[ \t]\{1,\}FASTFORMAT_VER_MAJOR[ \t]\{1,\}\([0-9]\{1,\}\).*/\1/p' \
    -e 's/^#[ \t]*define[ \t]\{1,\}FASTFORMAT_VER_MINOR[ \t]\{1,\}\([0-9]\{1,\}\).*/\1/p' \
    -e 's/^#[ \t]*define[ \t]\{1,\}FASTFORMAT_VER_PATCH[ \t]\{1,\}\([0-9]\{1,\}\).*/\1/p' \
    "$VersionHeader" | paste -sd. -
)

mkdir -p "$OutputDir" || exit 1

echo "Executing Doxygen for ${ProjectName} ${ProjectVersion} (in ${OutputDir})"

# NOTE: Doxygen resolves relative INPUT / EXAMPLE_PATH entries against the
# current directory, so the configuration is fed from, and Doxygen is run in,
# the project directory - never the build directory.
cd "$Dir" || exit 1

{
  cat "$DoxyfilePath"
  echo ""
  echo "# the following are overridden by ${Basename}"
  echo "OUTPUT_DIRECTORY = $OutputDir"
  [ -n "$ProjectVersion" ] && echo "PROJECT_NUMBER = $ProjectVersion"
} | doxygen "${DoxygenOptions[@]}" -
status=${PIPESTATUS[1]}

if [ $status -ne 0 ]; then

  >&2 echo "$ScriptPath: Doxygen failed with exit status $status"

  exit $status
fi

echo "${ProjectName} API documentation written to ${OutputDir}/html/index.html"

exit 0


# ############################## end of file ############################# #
