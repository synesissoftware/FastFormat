#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakePath=$Dir/_build

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
# command-line handling

while [[ $# -gt 0 ]]; do
    case $1 in
        --help)
            cat << EOF
FastFormat is very fast and very robust C++ formatting library
Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
Copyright (c) 2006-2019, Matthew Wilson and Synesis Software
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

if [ ! -d "$CMakePath" ]; then

    echo "$ScriptPath: CMake build directory '$CMakePath' not found so nothing to do; use script 'prepare_cmake.sh' if you wish to prepare CMake artefacts"

    exit 0
else

    echo "Removing all cmake artefacts in '$CMakePath'"

    num_dirs_removed=0
    num_files_removed=0

    for d in ${Directories[@]}
    do
        fq_dir_path="$CMakePath/$d"

        [ -d "$fq_dir_path" ] || continue

        echo "removing directory '$d'"

        rm -dfr "$fq_dir_path"

        num_dirs_removed=$((num_dirs_removed+1))
    done

    for f in ${Files[@]}
    do
        fq_file_path="$CMakePath/$f"

        [ -f "$fq_file_path" ] || continue

        echo "removing file '$f'"

        rm -f "$fq_file_path"

        num_files_removed=$((num_files_removed+1))
    done

    if [ 0 -eq $num_dirs_removed ] && [ 0 -eq $num_files_removed ]; then

        echo "nothing to do"
    else

        echo "removed $num_dirs_removed directories and $num_files_removed files"
    fi
fi


# ############################## end of file ############################# #

