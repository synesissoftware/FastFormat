#! /bin/bash

# ##########################################################
# functions - 1

sis_cmake_is_truey() {
  case "$(printf '%s' "${1:-}" | tr '[:upper:]' '[:lower:]')" in

    1|ok|on|true|yes|y)

      return 0
    ;;
    *)

      return 1
      ;;
  esac
}


# ##########################################################
# constants and variables

Basename=$(basename "$0")
Dir=$(cd "$(dirname "$0")" && pwd)
CMakeDir=${SIS_CMAKE_BUILD_DIR:-$Dir/_build}
ProjectNameFile="$Dir/.sis/project_name.txt"
ProjectName=$(tr -d '[:space:]' < "$ProjectNameFile")
ScriptPath=$0

AlwaysUseColours=${SIS_CMAKE_ALWAYS_USE_COLOURS:-${SIS_ALWAYS_USE_COLOURS:-0}}
BuildSharedLibs=0
Configuration=Release
ExamplesDisabled=0
MinGW=$(sis_cmake_is_truey "${SIS_CMAKE_MINGW:-}" && echo 1 || echo 0)
MSVC_MT=0
RunMake=0
SisUseColours=0
TestingDisabled=0
VerboseMakefile=0

# ##########################################################
# PROJECT-SPECIFIC FLAGS (customise per library; keep marker)
#
# Add project-only options here (e.g. --no-cpp, --stlsoft-root-dir,
# --no-shwild). The common body below must stay aligned with
# misc-dev-scripts/shell-scripts/cmake-helpers/prepare_cmake.sh.


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
# functions - 2

sis_cmake_build() {

  local config="${SIS_CMAKE_CONFIG:-Release}"
  local args=(--build "$CMakeDir")
  if [ -f "$CMakeDir/CMakeCache.txt" ] && grep -q '^CMAKE_CONFIGURATION_TYPES:' "$CMakeDir/CMakeCache.txt" 2>/dev/null; then

    args+=(--config "$config")
  fi
  if [ "$#" -gt 0 ]; then

    local t
    for t in "$@"; do

      args+=(--target "$t")
    done
  fi

  cmake "${args[@]}"
}


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

  case $1 in
    --always-use-colors|--always-use-colours|-A)

      # AlwaysUseColours=1 - this is handled by the for loop above
      ;;
    --build-shared-libs)

      BuildSharedLibs=1
      ;;
    --cmake-verbose-makefile|-v)

      VerboseMakefile=1
      ;;
    --debug-configuration|-d)

      Configuration=Debug
      ;;
    --disable-examples|-E)

      ExamplesDisabled=1
      ;;
    --disable-testing|-T)

      TestingDisabled=1
      ;;
    --mingw)

      MinGW=1
      ;;
    --msvc-mt)

      MSVC_MT=1
      ;;
    --run-make|-m)

      RunMake=1
      ;;
    --help)

      [ -f "$Dir/.sis/script_info_lines.txt" ] && cat "$Dir/.sis/script_info_lines.txt"
      cat << EOF
Creates/reinitialises the CMake build script(s)

${ScriptPath} [ ... flags/options ... ]

Flags/options:

    behaviour:

    -A
    --always-use-colors
    --always-use-colours
        forces use of colours even when stdout is not a TTY

    --build-shared-libs
        builds ${ProjectName} as a shared library (BUILD_SHARED_LIBS=ON)

    -v
    --cmake-verbose-makefile
        configures CMake to run verbosely (CMAKE_VERBOSE_MAKEFILE=ON)

    -d
    --debug-configuration
        use Debug configuration (CMAKE_BUILD_TYPE=Debug). Default is Release

    -E
    --disable-examples
        disables building of examples (BUILD_EXAMPLES=OFF)

    -T
    --disable-testing
        disables building of tests (BUILD_TESTING=OFF)

    --mingw
        uses explicitly the "MinGW Makefiles" generator

    --msvc-mt
        when using Visual C++ (MSVC), select the static runtime library

    -m
    --run-make
        executes a build via cmake --build after a successful configure


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

mkdir -p "$CMakeDir" || exit 1

echo
echo "Executing CMake for ${ProjectNameClr} (in ${CMakeDirClr})"

if [ $BuildSharedLibs -eq 0 ]; then CMakeBuildSharedLibsFlag="OFF" ; else CMakeBuildSharedLibsFlag="ON" ; fi
if [ $ExamplesDisabled -eq 0 ]; then CMakeBuildExamplesFlag="ON" ; else CMakeBuildExamplesFlag="OFF" ; fi
if [ $MSVC_MT -eq 0 ]; then CMakeMsvcMtFlag="OFF" ; else CMakeMsvcMtFlag="ON" ; fi
if [ $TestingDisabled -eq 0 ]; then CMakeBuildTestingFlag="ON" ; else CMakeBuildTestingFlag="OFF" ; fi
if [ $VerboseMakefile -eq 0 ]; then CMakeVerboseMakefileFlag="OFF" ; else CMakeVerboseMakefileFlag="ON" ; fi

# NOTE: the generator is the *only* thing that may differ between the MinGW
# and the default paths; every -D option is passed in both cases, so that no
# flag can be silently ignored according to the generator selected.

CMakeGeneratorArgs=()

if [ -n "${SIS_CMAKE_GENERATOR:-}" ] && [ $MinGW -eq 0 ]; then

  CMakeGeneratorArgs=(-G "$SIS_CMAKE_GENERATOR")
fi

if [ $MinGW -ne 0 ]; then

  CMakeGeneratorArgs=(-G "MinGW Makefiles")
fi

cmake \
  -DBUILD_EXAMPLES:BOOL=$CMakeBuildExamplesFlag \
  -DBUILD_SHARED_LIBS:BOOL=$CMakeBuildSharedLibsFlag \
  -DBUILD_TESTING:BOOL=$CMakeBuildTestingFlag \
  -DCMAKE_BUILD_TYPE=$Configuration \
  -DCMAKE_VERBOSE_MAKEFILE:BOOL=$CMakeVerboseMakefileFlag \
  -DMSVC_USE_MT:BOOL=$CMakeMsvcMtFlag \
  "${CMakeGeneratorArgs[@]}" \
  -B "$CMakeDir" \
  -S "$Dir" \
  || exit 1

status=0

if [ $RunMake -ne 0 ]; then

  echo
  echo "Executing build of ${ProjectNameClr} (via cmake --build)"

  sis_cmake_build
  status=$?
fi

if [ $VerboseMakefile -ne 0 ]; then

  echo
  echo -e "contents of ${CMakeDirClr}:"
  ls -al "$CMakeDir"
fi

exit $status


# ############################## end of file ############################# #
