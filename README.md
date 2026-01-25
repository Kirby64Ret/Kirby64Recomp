# Kirby 64: Recompiled
Imagine Majora's Mask or Banjo Recomp but it plays Kirby instead. This is that repo.

### **This repository and its releases do not contain game assets. The original game is required to build or run this project.**

### **This repository is Under Construction. There are no downloads yet.**
 - If you use Windows and want to maintain a release, go to the Kirby 64 Decomp repo and join that discord server

The requirements, attributions, and most of the instructions are in the [Zelda Recomp](https://github.com/Zelda64Recomp/Zelda64Recomp/blob/dev/README.md) repo. Anything specific to this project will be below.

Special thanks to Wiseguy for dealing with the runtime fixes to support this game (and there were a lot of them; this game creates so many threads)

## Instructions
- Clone this repo recursively (this folder should be about 1.1GB of stuff)
- Place your copy of Kirby 64 in here and name it `NK4E.z64`
- See the Clang Info section below.
- In `patches/Makefile`, set the `DECOMP` variable to a valid Kirby 64 Decomp repo.
- Run `make`
- wait
- wait some more
- It should create a `Kirby64Recompiled` executable in the `build` folder
- Give it your copy of Kirby 64 and select Start Game

## Clang Info
This repo was tested to build and run on clang version 18, which is now outdated on some bleeding edge distros (like Arch/Endeavour/Bazzite/etc). For Arch-based distros, you can still install the `clang18` package at the time of reading and this repo will just work.

In the case that other distros install clang to a different location:
- Run `ls /usr/lib/llvm18/bin` in your terminal.
  - If it shows a `clang` and `clang++`, then you don't have to do anything. Go back to the Instructions.
  - If not, continue below.
- Open the `Makefile`
  - Note the file paths of the `CLANG_EXE` and `CLANGXX_EXE` variables. Set these to wherever clang and clang++ version 18 get installed to
  - Usually this is embedded in the relevant package info.



