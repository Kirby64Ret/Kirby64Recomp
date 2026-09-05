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
- Run `make`
- wait
- wait some more
- It should create a `Kirby64Recompiled` executable in the `build` folder
- Make sure your copy of `NK4E.z64` is in the same folder as `Kirby64Recompiled`
  - Or, if running from the terminal, the same folder as the place you're running it from
- Launch the exe and play it

## Clang Info
This repo was tested to build and run on clang version 21. If you have another clang version you'd like to test (on Linux), the `Makefile` in this repo has a place to set that version.

Expect the tested clang version to increase over time.
