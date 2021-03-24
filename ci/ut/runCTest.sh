#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

#!/bin/bash

THIS_DIR_NAME=${PWD##*/}
if [ "$THIS_DIR_NAME" != "buildCI" ]
then
    echo "ERROR: CI pipeline issue! This script (runCTest.sh) should be executed from buildCI directory!"
    echo "This directory: $THIS_DIR_NAME"
    exit -1
fi

ctest -j$(nproc --all) --output-on-failure --timeout 5

if [ $? -ne 0 ]
then
    echo "Failure in ctest. Cleaning up directory..."
    rm -r -f *
    exit -1
fi

exit 0
