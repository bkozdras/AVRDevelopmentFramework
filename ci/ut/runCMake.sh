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
if [ "$THIS_DIR_NAME" != "build_UT_x86_64" ]
then
    echo "ERROR: CI pipeline issue! This script (runCMake.sh) should be executed from build_UT_x86_64 directory!"
    echo "This directory: $THIS_DIR_NAME"
    exit -1
fi

cmake \
    -DCMAKE_C_COMPILER=gcc-$GCC_MAJOR_VERSION \
    -DCMAKE_CXX_COMPILER=g++-$GCC_MAJOR_VERSION \
    -DAVR_FRAMEWORK_BUILD_LIBRARY_STATIC=ON \
    -DAVR_FRAMEWORK_BUILD_STUB_LIBRARY_STATIC=ON \
    -DAVR_FRAMEWORK_UNIT_TESTING_ENABLED=ON \
    -DF_CPU=16000000UL ..

if [ $? -ne 0 ]
then
    echo "Failure in cmake. Cleaning up directory..."
    rm -r -f *
    exit -1
fi

exit 0
