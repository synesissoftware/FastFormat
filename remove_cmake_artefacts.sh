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
Directories=(
  CMakeFiles
  Testing
  cmake
  examples
  projects
  src
  test
)
Files=(
  CMakeCache.txt
  CTestTestfile.cmake
  DartConfiguration.tcl
  Makefile
  cmake_install.cmake
  install_manifest.txt
)
SisUseColours=0


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

CMakeDirClr="${SisClr_Blue}${SisClr_Bold}${CMakeDir}${SisClr_None}"
ProjectNameClr="${SisClr_Blue}${SisClr_Bold}${ProjectName}${SisClr_None}"
ScriptPathClr="${SisClr_Blue}${SisClr_Bold}${ScriptPath}${SisClr_None}"


# ##########################################################
# operating environment detection

OsName="$(uname -s 2>/dev/null || echo Unknown)"
case "${OsName}" in
  CYGWIN*|MINGW*|MSYS_NT*|Windows_NT)

    Directories+=(
      ARM64
      Win32
      x64
    )
    Files+=(
      "*.filters"
      "*.sln"
      "*.vcxproj"
    )
    ;;
esac


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

  case $1 in
    --always-use-colors|--always-use-colours|-A)

      # AlwaysUseColours=1 - this is handled by the for loop above
      ;;
    --help)

      [ -f "$Dir/.sis/script_info_lines.txt" ] && cat "$Dir/.sis/script_info_lines.txt"
      cat << EOF
Removes all known CMake artefacts

${ScriptPath} [ ... flags/options ... ]

Flags/options:

    behaviour:

    -A
    --always-use-colors
    --always-use-colours
        forces use of colours even when stdout is not a TTY


    standard flags:

    --help
        displays this help and terminates

EOF

      exit 0
      ;;
    *)

      >&2 echo "${ScriptPathClr}: unrecognised argument '${SisClr_Red}${SisClr_Bold}$1${SisClr_None}'; use --help for usage"

      exit 1
      ;;
  esac

  shift
done


# ##########################################################
# main()

if [ ! -d "$CMakeDir" ]; then

  echo "${ScriptPathClr}: CMake build directory '${CMakeDirClr}' not found so nothing to do; use script 'prepare_cmake.sh' if you wish to prepare CMake artefacts"

  exit 0
fi

echo "Removing all ${ProjectNameClr} cmake artefacts in '${CMakeDirClr}'"

num_dirs_removed=0
num_files_removed=0

for d in "${Directories[@]}"; do

  fq_dir_path="$CMakeDir/$d"

  [ -d "$fq_dir_path" ] || continue

  echo "removing directory '$d'"

  rm -dfr "$fq_dir_path"

  num_dirs_removed=$((num_dirs_removed+1))
done

for f in "${Files[@]}"; do

  for fq_file_path in "$CMakeDir"/$f; do

    [ -f "$fq_file_path" ] || continue

    echo "removing file '$fq_file_path'"

    rm -f "$fq_file_path"

    num_files_removed=$((num_files_removed+1))
  done
done

if [ 0 -eq $num_dirs_removed ] && [ 0 -eq $num_files_removed ]; then

  echo "nothing to do"
else

  echo "removed $num_dirs_removed directories and $num_files_removed files"
fi


# ############################## end of file ############################# #
