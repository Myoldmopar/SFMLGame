#!/bin/bash

mkdir build
cd build
cmake .. -DBUILD_TESTING=ON
make
