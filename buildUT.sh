#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Purpose: To build and run unit tests for the AVR framework / utilities.          #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

#!/bin/bash

if ! cmake --version &> /dev/null
then
    echo "CMake is not found!"
    exit -1
fi

if ! make --version &> /dev/null
then
    echo "Make is not found!"
    exit -1
fi

THIS_ARCH=$(uname -m | tr -d '\n')
BUILD_DIR=build_$THIS_ARCH

mkdir -p $BUILD_DIR
cd $BUILD_DIR

cmake \
    -DAVR_FRAMEWORK_BUILD_LIBRARY_STATIC=ON \
    -DAVR_FRAMEWORK_BUILD_STUB_LIBRARY_STATIC=ON \
    -DAVR_FRAMEWORK_UNIT_TESTING_ENABLED=ON .. \
    && make -j$(nproc --all) \
    && ctest -j$(nproc --all) --output-on-failure --timeout 5

exit 0
