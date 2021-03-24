#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

#!/bin/bash

if ! cmake --version &> /dev/null
then
    echo "CMake is not found!"
    exit -1
fi

THIS_DIR_NAME=${PWD##*/}
if [ "$THIS_DIR_NAME" != "buildCI" ]
then
    echo "ERROR: CI pipeline issue! This script (runCMake.sh) should be executed from buildCI directory!"
    echo "This directory: $THIS_DIR_NAME"
    exit -1
fi

cmake \
    -DAVR_FRAMEWORK_BUILD_LIBRARY_STATIC=ON \
    -DAVR_FRAMEWORK_BUILD_STUB_LIBRARY_STATIC=ON \
    -DAVR_FRAMEWORK_UNIT_TESTING_ENABLED=ON .. \

exit 0
