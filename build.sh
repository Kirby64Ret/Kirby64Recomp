#!/bin/bash
set -e
set -v
cmake -S . -B build
make -C build $1
