#!/bin/bash

mkdir build
cd build
cmake .. -DBUILD_TESTING=ON -DCMAKE_BUILD_TYPE=Debug
make
