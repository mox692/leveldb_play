#!/bin/bash
set -e

cd build && make leveldb_play
cd .. && ./run.sh
