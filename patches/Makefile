TARGET = patches.elf

CC      ?= clang
LD      ?= ld.lld

DECOMP := ~/Decomps/kirby64
LIBULTRA_INC := $(DECOMP)/libreultra/include/2.0I
DECOMP_INCS := -I $(LIBULTRA_INC) -I $(LIBULTRA_INC)/PR -I $(DECOMP)/include -I $(DECOMP)/include/libc -I $(DECOMP)/src -I $(DECOMP)/assets -I../lib/rt64/include


CFLAGS   := $(DECOMP_INCS) -target mips -mips2 -mabi=32 -O2 -G0 -mno-abicalls -mno-odd-spreg -mno-check-zero-division \
			-fomit-frame-pointer -ffast-math -fno-unsafe-math-optimizations -fno-builtin-memset \
			-Wall -Wextra -Wno-incompatible-library-redeclaration -Wno-unused-parameter -Wno-unknown-pragmas -Wno-unused-variable -Wno-missing-braces -Wno-unsupported-floating-point-opt
CPPFLAGS := -nostdinc -Wno-incompatible-function-pointer-types -D_LANGUAGE_C -DTARGET_N64 -DMIPS -I dummy_headers $(DECOMP_INCS)
LDFLAGS  := -nostdlib -T patches.ld -T syms.ld -Map patches.map --unresolved-symbols=ignore-all --emit-relocs

C_SRCS := $(wildcard *.c)
C_OBJS := $(C_SRCS:.c=.o)
C_DEPS := $(C_SRCS:.c=.d)

$(TARGET): $(C_OBJS) patches.ld syms.ld
	$(LD) $(C_OBJS) $(LDFLAGS) -o $@

$(C_OBJS): %.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -MMD -MF $(@:.o=.d) -c -o $@

clean:
	rm -rf $(C_OBJS) $(TARGET) $(C_DEPS)

-include $(C_DEPS)

.PHONY: clean
