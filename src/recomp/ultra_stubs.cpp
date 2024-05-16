#include "../ultramodern/ultra64.h"
#include "../ultramodern/ultramodern.hpp"
#include "recomp.h"

// None of these functions need to be reimplemented, so stub them out
extern "C" void osUnmapTLBAll_recomp(uint8_t * rdram, recomp_context * ctx) {
    // TODO this will need to be implemented in the future for any games that actually use the TLB
}

extern "C" void osVoiceInit_recomp(uint8_t * rdram, recomp_context * ctx) {
    ctx->r2 = 11; // CONT_ERR_DEVICE
}

extern "C" void osVoiceSetWord_recomp(uint8_t * rdram, recomp_context * ctx) {
    assert(false);
}

extern "C" void osVoiceCheckWord_recomp(uint8_t * rdram, recomp_context * ctx) {
    assert(false);
}

extern "C" void osVoiceStopReadData_recomp(uint8_t * rdram, recomp_context * ctx) {
    assert(false);
}

extern "C" void osVoiceMaskDictionary_recomp(uint8_t * rdram, recomp_context * ctx) {
    assert(false);
}

extern "C" void osVoiceStartReadData_recomp(uint8_t * rdram, recomp_context * ctx) {
    assert(false);
}

extern "C" void osVoiceControlGain_recomp(uint8_t * rdram, recomp_context * ctx) {
    assert(false);
}

extern "C" void osVoiceGetReadData_recomp(uint8_t * rdram, recomp_context * ctx) {
    assert(false);
}

extern "C" void osVoiceClearDictionary_recomp(uint8_t * rdram, recomp_context * ctx) {
    assert(false);
}

extern "C" void osEPiRawStartDma_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}
extern "C" void __osSiGetAccess_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}
extern "C" void __osSiRawStartDma_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}
extern "C" void __osSiRelAccess_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}
extern "C" void __osPfsSelectBank_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}
extern "C" void __osContRamRead_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}
extern "C" void __osPfsRWInode_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}
extern "C" void __osContRamWrite_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}

extern "C" void __osGetId_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}
extern "C" void __osPfsGetStatus_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}
extern "C" void __osSpSetStatus_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}
extern "C" void _removeEvents_00004DFC(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}
extern "C" void bcmp_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}
extern "C" void bcopy_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}
extern "C" void bzero_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}
extern "C" void func_800245F0(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}
extern "C" void osPfsInit_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}
extern "C" void osPfsIsPlug_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}
extern "C" void osPfsNumFiles_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}
extern "C" void rmonPrintf_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}
extern "C" void sqrtf_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}

extern "C" void __f_to_ll_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}
extern "C" void __ll_lshift_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}
extern "C" void __ll_to_f_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}
extern "C" void __ull_rshift_recomp(uint8_t *rdram, recomp_context *ctx) {
    assert(false);
}

