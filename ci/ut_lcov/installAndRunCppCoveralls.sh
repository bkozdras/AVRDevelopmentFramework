#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

#!/bin/bash

if ! pip3 --version &> /dev/null
then
    echo "pi3 is not found!"
    exit -1
fi

THIS_DIR_NAME=${PWD##*/}
if [ "$THIS_DIR_NAME" != "build_UT_x86_64_LCOV" ]
then
    echo "ERROR: CI pipeline issue! This script (installAndRunCppCoveralls.sh) should be executed from build_UT_x86_64_LCOV directory!"
    echo "This directory: $THIS_DIR_NAME"
    exit -1
fi

pip3 install --user cpp-coveralls \
    && coveralls --verbose \
    --exclude _deps \
    --exclude stub \
    --exclude test \
    --repo-token $GITHUB_TOKEN \
    || echo "Failure in publishing code coverage result on coveralls.io"

exit 0
