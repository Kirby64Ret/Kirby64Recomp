default: all


DECOMP := ~/Decomps/kirby64
N64RECOMP := ~/Devel/N64Recomp


all: build/Kirby64Recompiled

build/Kirby64Recompiled:
	cp $(N64RECOMP)/build/N64Recomp ./N64Recomp
	./N64Recomp NK4E.toml
	$(N64RECOMP)/build/RSPRecomp n_aspMain.toml
	cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -B build -S .
	$(MAKE) -C build

clean:
	rm -rf build
