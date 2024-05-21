#!/bin/bash
set -e
set -v
rm -rf RecompiledFuncs
cp -R ../N64Recomp/RecompiledFuncs .
cp -R ../N64Recomp/rsp/ .
cp FFFFFFFF.c RecompiledFuncs/
cp dma_overlay_load.c RecompiledFuncs/
cp fatal_printf.c RecompiledFuncs/
touch src/recomp/overlays.cpp
