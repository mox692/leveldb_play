#!/bin/bash
set -e

cmake -S . -B build -DBUILD_SHARED_LIBS=ON &&
cmake --build build
./run.sh
