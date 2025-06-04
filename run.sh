#!/bin/bash
mkdir -p build
cd build
cmake ..
make
./game
rm -rf game