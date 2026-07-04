#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakeDir=${SIS_CMAKE_BUILD_DIR:-$Dir/_build}

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


# ##########################################################
# operating environment detection

OsName="$(uname -s)"
case "${OsName}" in
  CYGWIN*|MINGW*|MSYS_NT*)

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
  *)

    ;;
esac


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

  case $1 in
    --help)

      [ -f "$Dir/.sis/script_info_lines.txt" ] && cat "$Dir/.sis/script_info_lines.txt"
      cat << EOF
Removes all known CMake artefacts

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

  echo "$ScriptPath: CMake build directory '$CMakeDir' not found so nothing to do; use script 'prepare_cmake.sh' if you wish to prepare CMake artefacts"

  exit 0
else

  echo "Removing all cmake artefacts in '$CMakeDir'"

  num_dirs_removed=0
  num_files_removed=0

  for d in ${Directories[@]}
  do

    fq_dir_path="$CMakeDir/$d"

    [ -d "$fq_dir_path" ] || continue

    echo "removing directory '$d'"

    rm -dfr "$fq_dir_path"

    num_dirs_removed=$((num_dirs_removed+1))
  done

  cd "$CMakeDir"

  for f in ${Files[@]}
  do

    for fq_file_path in $f
    do

      [ -f "$fq_file_path" ] || continue

      echo "removing file '$fq_file_path'"

      rm -f "$fq_file_path"

      num_files_removed=$((num_files_removed+1))
    done
  done

  cd ->/dev/null

  if [ 0 -eq $num_dirs_removed ] && [ 0 -eq $num_files_removed ]; then

    echo "nothing to do"
  else

    echo "removed $num_dirs_removed directories and $num_files_removed files"
  fi
fi


# ############################## end of file ############################# #
