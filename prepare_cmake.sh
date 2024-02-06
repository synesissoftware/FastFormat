#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakePath=$Dir/_build


CMakeExamplesDisabled=0
CMakeTestingDisabled=0
CMakeVerboseMakefile=0
Configuration=Release
RunMake=0
STLSoftDirGiven=


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do
    case $1 in
        -v|--cmake-verbose-makefile)

            CMakeVerboseMakefile=1
            ;;
        -d|--debug-configuration)

            Configuration=Debug
            ;;
        -E|--disable-examples)

            CMakeExamplesDisabled=1
            ;;
        -T|--disable-testing)

            CMakeTestingDisabled=1
            ;;
        -m|--run-make)

            RunMake=1
            ;;
        --help)

            cat << EOF
FastFormat is very fast and very robust C++ formatting library
Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
Copyright (c) 2006-2019, Matthew Wilson and Synesis Software
Creates/reinitialises the CMake build script(s)

$ScriptPath [ ... flags/options ... ]

Flags/options:

    behaviour:

    -v
    --cmake-verbose-makefile
        configures CMake to run verbosely (by setting
        CMAKE_VERBOSE_MAKEFILE=ON)

    -d
    --debug-configuration
        use Debug configuration (by setting CMAKE_BUILD_TYPE=Debug). Default
        is to use Release

    -E
    --disable-examples
        disables building of examples (by setting BUILD_EXAMPLES=OFF)

    -T
    --disable-testing
        disables building of tests (by setting BUILD_TESTING=OFF). This is
        necessary, for example, when installing on a system that does not
        (yet) have xTests - which itself depends on STLSOFT - installed

    -m
    --run-make
        executes make after a successful running of CMake


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

mkdir -p $CMakePath || exit 1

cd $CMakePath

echo "Executing CMake"

if [ $CMakeExamplesDisabled -eq 0 ]; then CMakeBuildExamplesFlag="ON" ; else CMakeBuildExamplesFlag="OFF" ; fi

if [ $CMakeTestingDisabled -eq 0 ]; then CMakeBuildTestingFlag="ON" ; else CMakeBuildTestingFlag="OFF" ; fi

if [ $CMakeVerboseMakefile -eq 0 ]; then CMakeVerboseMakefileFlag="OFF" ; else CMakeVerboseMakefileFlag="ON" ; fi

cmake \
    -DBUILD_EXAMPLES:BOOL=$CMakeBuildExamplesFlag \
    -DBUILD_TESTING:BOOL=$CMakeBuildTestingFlag \
    -DCMAKE_BUILD_TYPE=$Configuration \
    -DCMAKE_VERBOSE_MAKEFILE:BOOL=$CMakeVerboseMakefileFlag \
    .. || (cd ->/dev/null ; exit 1)

status=0

if [ $RunMake -ne 0 ]; then

    echo "Executing make"

    make

    status=$?
fi

cd ->/dev/null

if [ $CMakeVerboseMakefile -ne 0 ]; then

    echo -e "contents of $CMakePath:"
    ls -al $CMakePath
fi

exit $status


# ############################## end of file ############################# #

