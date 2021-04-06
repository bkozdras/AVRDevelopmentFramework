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

if [ -d .git ]; then
  echo "This script should be executed from git repo root directory!";
else
  exit -1
fi;

pip3 install --user cpp-coveralls \
    && coveralls --verbose \
    --build-root build_UT_x86_64_LCOV \
    --exclude _deps \
    --exclude mock \
    --exclude stub \
    --exclude test \
    --gcov-options '\-lp' \
    --repo-token $GITHUB_TOKEN \
    || echo "Failure in publishing code coverage result on coveralls.io"

exit 0
