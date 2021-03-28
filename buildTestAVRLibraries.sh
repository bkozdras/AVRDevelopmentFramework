#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Purpose: To build AVR libraries with tested executable files for each library.   #
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

BUILD_DIR=build_AVR

mkdir -p $BUILD_DIR
cd $BUILD_DIR

cmake \
    -DCMAKE_C_COMPILER=avr-gcc \
    -DCMAKE_CXX_COMPILER=avr-g++ \
    -DAVR_FRAMEWORK_BUILD_FOR_TARGET=ON \
    -DAVR_FRAMEWORK_BUILD_TEST_EXECUTABLE_FOR_TARGET=ON .. \
    && make -j$(nproc --all)

exit 0
