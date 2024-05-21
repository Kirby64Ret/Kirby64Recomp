#include "recomp.h"
#include "disable_warnings.h"

void dma_overlay_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(0X10, ctx->r4);
    // lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(0XC, ctx->r4);
    // or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // subu        $v1, $t6, $v0
    ctx->r3 = SUB32(ctx->r14, ctx->r2);
    // beq         $v1, $zero, L_80002DCC
    if (ctx->r3 == 0) {
        // or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
        goto L_80002DCC;
    }
    // or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // jal         0x80033B10
    // or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    osInvalICache_recomp(rdram, ctx);
    goto after_0;
    // or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_0:
    // lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(0XC, ctx->r16);
    // lw          $t7, 0x10($s0)
    ctx->r15 = MEM_W(0X10, ctx->r16);
    // or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // jal         0x80033B90
    // subu        $a1, $t7, $v0
    ctx->r5 = SUB32(ctx->r15, ctx->r2);
    osInvalDCache_recomp(rdram, ctx);
    goto after_1;
    // subu        $a1, $t7, $v0
    ctx->r5 = SUB32(ctx->r15, ctx->r2);
    after_1:
L_80002DCC:
    // lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(0X14, ctx->r16);
    // lw          $t8, 0x18($s0)
    ctx->r24 = MEM_W(0X18, ctx->r16);
    // or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // subu        $v1, $t8, $v0
    ctx->r3 = SUB32(ctx->r24, ctx->r2);
    // beql        $v1, $zero, L_80002DF0
    if (ctx->r3 == 0) {
        // lw          $a1, 0x0($s0)
        ctx->r5 = MEM_W(0X0, ctx->r16);
        goto L_80002DF0;
    }
    goto skip_0;
    // lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(0X0, ctx->r16);
    skip_0:
    // jal         0x80033B90
    // or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    osInvalDCache_recomp(rdram, ctx);
    goto after_2;
    // or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(0X0, ctx->r16);
L_80002DF0:
    // lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(0X4, ctx->r16);
    // lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // subu        $a3, $t9, $a1
    ctx->r7 = SUB32(ctx->r25, ctx->r5);
    // beql        $a3, $zero, L_80002E18
    if (ctx->r7 == 0) {
        // lw          $v0, 0x1C($s0)
        ctx->r2 = MEM_W(0X1C, ctx->r16);
        goto L_80002E18;
    }
    goto skip_1;
    // lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(0X1C, ctx->r16);
    skip_1:
    // lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(0X8, ctx->r16);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x80002BD0
    // lw          $a0, -0x7310($a0)
    ctx->r4 = MEM_W(-0X7310, ctx->r4);
    // dma_copy(rdram, ctx);
    load_overlays(
        MEM_W(0, ctx->r4),
        MEM_W(0x8, ctx->r4),
        (uint32_t)(MEM_W(0x18, ctx->r4) - MEM_W(0x8, ctx->r4))
    );

    goto after_3;
    // lw          $a0, -0x7310($a0)
    ctx->r4 = MEM_W(-0X7310, ctx->r4);
    after_3:
    // lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(0X1C, ctx->r16);
L_80002E18:
    // lw          $t0, 0x20($s0)
    ctx->r8 = MEM_W(0X20, ctx->r16);
    // or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // subu        $v1, $t0, $v0
    ctx->r3 = SUB32(ctx->r8, ctx->r2);
    // beql        $v1, $zero, L_80002E38
    if (ctx->r3 == 0) {
        // lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(0X24, ctx->r29);
        goto L_80002E38;
    }
    goto skip_2;
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    skip_2:
    // jal         0x8002E8B0
    // or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    bzero_recomp(rdram, ctx);
    goto after_4;
    // or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_4:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
L_80002E38:
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
