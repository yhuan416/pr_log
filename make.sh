#!/bin/sh

mkdir -p build
cd build
cmake .. -DBUILD_TEST=ON
cmake --build . --verbose
ctest --verbose
