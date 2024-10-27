# Kirby 64: Recompiled
Imagine Majora's Mask Recomp but it plays Kirby instead. This is that repo.

### **This repository and its releases do not contain game assets. The original game is required to build or run this project.**

The requirements, attributions, and most of the instructions are in the [Zelda Recomp](https://github.com/Zelda64Recomp/Zelda64Recomp/blob/dev/README.md) repo. Anything specific to this project will be below.

Special thanks to Wiseguy for dealing with the runtime fixes to support this game (and there were a lot of them; this game creates so many threads)

## Instructions
- Clone this repo recursively (this folder should be about 1.1GB of stuff)
- Build [Decomp](https://github.com/Kirby64Ret/kirby64) (Use the `splat` branch for now)
- Build [N64Recomp](https://github.com/Kirby64Ret/N64Recomp)
- In this repo, set the variables in the `Makefile` to the above 2 repos
- Run `make`
- wait
- wait some more
- It should create a `Kirby64Recompiled` executable in the `build` folder
- Give it your copy of Kirby 64 and select Start Game

