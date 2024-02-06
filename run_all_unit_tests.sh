#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakePath=$Dir/_build


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do
    case $1 in
        --help)

            cat << EOF
FastFormat is very fast and very robust C++ formatting library
Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
Copyright (c) 2006-2019, Matthew Wilson and Synesis Software
Runs all (matching) unit-test programs

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

mkdir -p $CMakePath || exit 1

cd $CMakePath

echo "Executing make and then running all test programs"

status=0

if make; then

    for f in $(find $Dir -type f -perm +111 '(' -name 'test*unit*' -o -name 'test*component*' ')')
    do

        echo
        echo "executing $f:"

        if $f; then

            :
        else

            status=$?

            break 1
        fi
    done
else

    status=$?
fi

cd ->/dev/null

exit $status


# ############################## end of file ############################# #

