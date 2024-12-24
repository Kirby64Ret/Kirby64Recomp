default: all

all: build/Kirby64Recompiled

N64RECOMP := build/N64Recomp/N64Recomp
RSPRECOMP := build/N64Recomp/RSPRecomp

recomp:
	cp $(N64RECOMP)/build/N64Recomp ./N64Recomp
	./N64Recomp NK4E.toml
	$(N64RECOMP)/build/RSPRecomp n_aspMain.toml

build/:
	mkdir -p build/N64Recomp
	cmake -B build/N64Recomp -S N64Recomp
	$(MAKE) -C build/N64Recomp
	$(N64RECOMP) NK4E.toml
	$(RSPRECOMP) n_aspMain.toml
	cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -B build -S .

build/Kirby64Recompiled: build/
	$(MAKE) -C build

clean:
	rm -rf build
