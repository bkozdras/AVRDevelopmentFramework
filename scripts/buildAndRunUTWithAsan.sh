#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Purpose: To build and run unit tests for the AVR framework / utilities.          #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

#!/bin/bash

if [[ "$AVR_BUILD_ENVIRONMENT_CONTAINER" != "1" ]]
then
    echo "This script should be called from docker container - see docker submodule!"
    exit -1
fi

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

THIS_DIR=$(pwd)
EXPECTED_DIR=$(git rev-parse --show-toplevel)

if [[ "$THIS_DIR" != "$EXPECTED_DIR" ]]
then
    echo "This script should be called from git repo root directory!"
    exit -1
fi

mkdir -p build
cd build

THIS_ARCH=$(uname -m | tr -d '\n')
BUILD_DIR=ut_asan_$THIS_ARCH

mkdir -p $BUILD_DIR
cd $BUILD_DIR

cmake \
    -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_C_COMPILER=gcc-$GCC_MAJOR_VERSION \
    -DCMAKE_CXX_COMPILER=g++-$GCC_MAJOR_VERSION \
    -DAVR_FRAMEWORK_BUILD_LIBRARY_STATIC=ON \
    -DAVR_FRAMEWORK_BUILD_MOCK_LIBRARY_STATIC=ON \
    -DAVR_FRAMEWORK_BUILD_STUB_LIBRARY_STATIC=ON \
    -DAVR_FRAMEWORK_UNIT_TESTING_ENABLED=ON \
    -DAVR_FRAMEWORK_USE_ADDRESS_SANITIZER=ON \
    -DAVR_FRAMEWORK_AVR_MCU_FREQ=16000000UL ../.. \
    && make -j$(nproc --all) \
    && ctest -j$(nproc --all) --output-on-failure --timeout 5

exit 0
