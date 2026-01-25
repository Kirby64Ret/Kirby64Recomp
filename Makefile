default: all

all: build/Kirby64Recompiled

LLVM_VER := 18
CLANG_EXE := /usr/lib/llvm$(LLVM_VER)/bin/clang
CLANGXX_EXE := /usr/lib/llvm$(LLVM_VER)/bin/clang++
N64RECOMP := build/N64Recomp/N64Recomp
RSPRECOMP := build/N64Recomp/RSPRecomp
JOB_FLAG := $(filter -j%, $(subst -j ,-j,$(MAKEFLAGS)))
USE_NINJA := -G Ninja
USE_CLANG := CC=$(CLANG_EXE) CXX=$(CLANGXX_EXE)

recomp:
	cp $(N64RECOMP)/build/N64Recomp ./N64Recomp
	./N64Recomp NK4E.toml
	$(N64RECOMP)/build/RSPRecomp n_aspMain.toml

# 	$(MAKE) -C build/N64Recomp
build/:
	mkdir -p build/N64Recomp
	$(USE_CLANG) cmake -B build/N64Recomp -S N64Recomp $(USE_NINJA)
	CLICOLOR_FORCE=1 ninja $(JOB_FLAG) -C build/N64Recomp
	$(N64RECOMP) NK4E.toml
	$(RSPRECOMP) n_aspMain.toml
	$(USE_CLANG) cmake -DCMAKE_C_COMPILER=$(CLANG_EXE) -DCMAKE_CXX_COMPILER=$(CLANGXX_EXE) -B build -S . $(USE_NINJA)

# 	$(MAKE) -C build
build/Kirby64Recompiled: build/
	CLICOLOR_FORCE=1 ninja $(JOB_FLAG) -C build

clean:
	rm -rf build

print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
