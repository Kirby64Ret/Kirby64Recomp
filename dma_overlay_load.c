#include "recomp.h"
#include "disable_warnings.h"

void dma_overlay_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    recomp_ovl_load_hook(MEM_W(0, ctx->r4), MEM_W(0x8, ctx->r4), (uint32_t)(MEM_W(0x24, ctx->r4) - MEM_W(0x8, ctx->r4)));
    return;
;}
