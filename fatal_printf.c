#include "recomp.h"
#include "disable_warnings.h"

void fatal_printf(uint8_t* rdram, recomp_context* ctx) {
    printf((const char*)ctx->r4);
    assert(false);
    return;
}
