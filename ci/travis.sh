#!/usr/bin/env sh
set -evx

env | sort

mkdir build || true
cd build
cmake -DCMAKE_COMPILER_IS_GNUCXX=$COMPILER_IS_GNUCXX \
      -DCMAKE_CXX_FLAGS=$CXX_FLAGS \
      -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
      -DCMAKE_BUILD_COVERAGE=$BUILD_COVERAGE \
      ..
make
CTEST_OUTPUT_ON_FAILURE=1 make test
