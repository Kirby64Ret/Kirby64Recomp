#!/bin/bash
set -e
set -v

rm -rf RecompiledFuncs rsp
cp ~/Decomps/kirby64/build/kirby.us.elf NK4E.us.elf
../N64Recomp/build/N64Recomp NK4E.toml
../N64Recomp/build/RSPRecomp n_aspMain.toml
# cp -R ../N64Recomp/RecompiledFuncs .
# cp -R ../N64Recomp/rsp/ .
# cp FFFFFFFF.c RecompiledFuncs/
# cp dma_overlay_load.c RecompiledFuncs/
# cp fatal_printf.c RecompiledFuncs/
# touch src/recomp/overlays.cpp
