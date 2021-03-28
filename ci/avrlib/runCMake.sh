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
if [ "$THIS_DIR_NAME" != "build_AVR" ]
then
    echo "ERROR: CI pipeline issue! This script (runCMake.sh) should be executed from build_AVR directory!"
    echo "This directory: $THIS_DIR_NAME"
    exit -1
fi

cmake \
    -DCMAKE_C_COMPILER=avr-gcc \
    -DCMAKE_CXX_COMPILER=avr-g++ \
    -DAVR_FRAMEWORK_BUILD_FOR_TARGET=ON \
    -DAVR_FRAMEWORK_BUILD_TEST_EXECUTABLE_FOR_TARGET=ON ..

if [ $? -ne 0 ]
then
    echo "Failure in cmake. Cleaning up directory..."
    rm -r -f *
    exit -1
fi

exit 0
