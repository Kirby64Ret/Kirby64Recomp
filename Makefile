default: all

N64RECOMP := ~/Devel/N64Recomp

all: build/Kirby64Recompiled

recomp:
	cp $(N64RECOMP)/build/N64Recomp ./N64Recomp
	./N64Recomp NK4E.toml
	$(N64RECOMP)/build/RSPRecomp n_aspMain.toml

build/:
	cp $(N64RECOMP)/build/N64Recomp ./N64Recomp
	./N64Recomp NK4E.toml
	$(N64RECOMP)/build/RSPRecomp n_aspMain.toml
	cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -B build -S .

build/Kirby64Recompiled: build/
	$(MAKE) -C build

clean:
	rm -rf build
