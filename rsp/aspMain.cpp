#include "rsp.h"
#include "rsp_vu_impl.h"
RspExitReason aspMain(uint8_t* rdram) {
    uint32_t           r1 = 0,  r2 = 0,  r3 = 0,  r4 = 0,  r5 = 0,  r6 = 0,  r7 = 0;
    uint32_t  r8 = 0,  r9 = 0, r10 = 0, r11 = 0, r12 = 0, r13 = 0, r14 = 0, r15 = 0;
    uint32_t r16 = 0, r17 = 0, r18 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0;
    uint32_t r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    uint32_t dma_dmem_address = 0, dma_dram_address = 0, jump_target = 0;
    const char * debug_file = NULL; int debug_line = 0;
    RSP rsp{};
    r1 = 0xFC0;
    // sw          $1, 0x0($4)
    RSP_MEM_W_STORE(0X0, r4, r1);
    // lw          $8, 0x4($15)
    r8 = RSP_MEM_W_LOAD(0X4, r15);
    // addiu       $29, $29, 0x8
    r29 = RSP_ADD32(r29, 0X8);
    // jr          $ra
    jump_target = r31;
    debug_file = __FILE__; debug_line = __LINE__;
    // sw          $8, 0x4($4)
    RSP_MEM_W_STORE(0X4, r4, r8);
    goto do_indirect_jump;
    // sw          $8, 0x4($4)
    RSP_MEM_W_STORE(0X4, r4, r8);
    // nop

    // nop

    // nop

    // addi        $24, $zero, 0x360
    r24 = RSP_ADD32(0, 0X360);
    // addi        $23, $zero, 0xF90
    r23 = RSP_ADD32(0, 0XF90);
    // lw          $28, 0x30($1)
    r28 = RSP_MEM_W_LOAD(0X30, r1);
    // lw          $27, 0x34($1)
    r27 = RSP_MEM_W_LOAD(0X34, r1);
    // mfc0        $5, DPC_STATUS
    r5 = 0;
    // andi        $4, $5, 0x1
    r4 = r5 & 0X1;
    // beq         $4, $zero, L_1054
    if (r4 == 0) {
        // andi        $4, $5, 0x100
        r4 = r5 & 0X100;
        goto L_1054;
    }
    // andi        $4, $5, 0x100
    r4 = r5 & 0X100;
    // beq         $4, $zero, L_1054
    if (r4 == 0) {
        // nop
    
        goto L_1054;
    }
    // nop

L_1048:
    // mfc0        $4, DPC_STATUS
    r4 = 0;
    // andi        $4, $4, 0x100
    r4 = r4 & 0X100;
    // bgtz        $4, L_1048
    if (RSP_SIGNED(r4) > 0) {
        // nop
    
        goto L_1048;
    }
L_1054:
    // nop

    // jal         0x1160
    r31 = 0x1060;
    // nop

    goto L_1160;
    // nop

L_1060:
    // addi        $2, $zero, 0xF
    r2 = RSP_ADD32(0, 0XF);
    // addi        $1, $zero, 0x320
    r1 = RSP_ADD32(0, 0X320);
L_1068:
    // sw          $zero, 0x0($1)
    RSP_MEM_W_STORE(0X0, r1, 0);
    // bgtz        $2, L_1068
    if (RSP_SIGNED(r2) > 0) {
        // addi        $2, $2, -0x1
        r2 = RSP_ADD32(r2, -0X1);
        goto L_1068;
    }
    // addi        $2, $2, -0x1
    r2 = RSP_ADD32(r2, -0X1);
L_1074:
    // mfc0        $2, SP_DMA_BUSY
    r2 = 0;
    // bne         $2, $zero, L_1074
    if (r2 != 0) {
        // addi        $29, $zero, 0x380
        r29 = RSP_ADD32(0, 0X380);
        goto L_1074;
    }
    // addi        $29, $zero, 0x380
    r29 = RSP_ADD32(0, 0X380);
    // mtc0        $zero, SP_SEMAPHORE
L_1084:
    // lw          $26, 0x0($29)
    r26 = RSP_MEM_W_LOAD(0X0, r29);
    // lw          $25, 0x4($29)
    r25 = RSP_MEM_W_LOAD(0X4, r29);
    // srl         $1, $26, 23
    r1 = S32(U32(r26) >> 23);
    // andi        $1, $1, 0xFE
    r1 = r1 & 0XFE;
    // addi        $28, $28, 0x8
    r28 = RSP_ADD32(r28, 0X8);
    // addi        $27, $27, -0x8
    r27 = RSP_ADD32(r27, -0X8);
    // addi        $29, $29, 0x8
    r29 = RSP_ADD32(r29, 0X8);
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
    // add         $2, $zero, $1
    r2 = RSP_ADD32(0, r1);
    // lh          $2, 0x10($2)
    r2 = RSP_MEM_H_LOAD(0X10, r2);
    // jr          $2
    jump_target = r2;
    debug_file = __FILE__; debug_line = __LINE__;
    // nop

    goto do_indirect_jump;
    // nop

    // break       0
    return RspExitReason::Broke;
L_10B8:
    // bgtz        $30, L_1084
    if (RSP_SIGNED(r30) > 0) {
        // nop
    
        goto L_1084;
    }
    // nop

    // blez        $27, L_10D8
    if (RSP_SIGNED(r27) <= 0) {
        // nop
    
        goto L_10D8;
    }
    // nop

    // jal         0x1160
    r31 = 0x10D0;
    // nop

    goto L_1160;
    // nop

L_10D0:
    // j           L_10D4
    // nop

    goto L_10D4;
L_10D4:
    // nop

L_10D8:
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
    // bne         $1, $zero, L_10D8
    if (r1 != 0) {
        // nop
    
        goto L_10D8;
    }
    // nop

    // mtc0        $zero, SP_SEMAPHORE
    // ori         $1, $zero, 0x4000
    r1 = 0 | 0X4000;
    // mtc0        $1, SP_STATUS
    // break       0
    return RspExitReason::Broke;
    // nop

L_10F8:
    // b           L_10F8
    // nop

    goto L_10F8;
    // nop

    // addi        $5, $ra, 0x0
    r5 = RSP_ADD32(r31, 0X0);
    // add         $2, $zero, $28
    r2 = RSP_ADD32(0, r28);
    // addi        $3, $27, 0x0
    r3 = RSP_ADD32(r27, 0X0);
    // addi        $4, $3, -0x140
    r4 = RSP_ADD32(r3, -0X140);
    // blez        $4, L_111C
    if (RSP_SIGNED(r4) <= 0) {
        // addi        $1, $zero, 0x380
        r1 = RSP_ADD32(0, 0X380);
        goto L_111C;
    }
    // addi        $1, $zero, 0x380
    r1 = RSP_ADD32(0, 0X380);
L_1118:
    // addi        $3, $zero, 0x140
    r3 = RSP_ADD32(0, 0X140);
L_111C:
    // addi        $30, $3, 0x0
    r30 = RSP_ADD32(r3, 0X0);
    // jal         0x1194
    r31 = 0x1128;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    goto L_1194;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
L_1128:
    // addi        $29, $zero, 0x380
    r29 = RSP_ADD32(0, 0X380);
    // jr          $5
    jump_target = r5;
    debug_file = __FILE__; debug_line = __LINE__;
    // nop

    goto do_indirect_jump;
    // nop

    // mfc0        $4, SP_SEMAPHORE
    r4 = 0;
L_1138:
    // mfc0        $4, SP_DMA_FULL
    r4 = 0;
    // bne         $4, $zero, L_1138
    if (r4 != 0) {
        // nop
    
        goto L_1138;
    }
    // nop

    // mtc0        $1, SP_MEM_ADDR
    SET_DMA_DMEM(r1);
    // mtc0        $2, SP_DRAM_ADDR
    SET_DMA_DRAM(r2);
    // mtc0        $3, SP_RD_LEN
    DO_DMA_READ(r3);
    // lui         $4, 0x8000
    r4 = S32(0X8000 << 16);
    // or          $22, $4, $22
    r22 = r4 | r22;
    // jr          $ra
    jump_target = r31;
    debug_file = __FILE__; debug_line = __LINE__;
    // nop

    goto do_indirect_jump;
    // nop

L_1160:
    // mfc0        $4, SP_SEMAPHORE
    r4 = 0;
L_1164:
    // mfc0        $4, SP_DMA_FULL
    r4 = 0;
    // bne         $4, $zero, L_1164
    if (r4 != 0) {
        // nop
    
        goto L_1164;
    }
    // nop

    // mtc0        $1, SP_MEM_ADDR
    SET_DMA_DMEM(r1);
    // mtc0        $2, SP_DRAM_ADDR
    SET_DMA_DRAM(r2);
    // mtc0        $3, SP_WR_LEN
    DO_DMA_WRITE(r3);
    // lui         $4, 0x8000
    r4 = S32(0X8000 << 16);
    // or          $22, $4, $22
    r22 = r4 | r22;
    // jr          $ra
    jump_target = r31;
    debug_file = __FILE__; debug_line = __LINE__;
    // nop

    goto do_indirect_jump;
    // nop

    // andi        $3, $25, 0xFFFF
    r3 = r25 & 0XFFFF;
    // beq         $3, $zero, L_10B8
    if (r3 == 0) {
        // addi        $4, $zero, 0x5C0
        r4 = RSP_ADD32(0, 0X5C0);
        goto L_10B8;
    }
L_1194:
    // addi        $4, $zero, 0x5C0
    r4 = RSP_ADD32(0, 0X5C0);
    // andi        $1, $26, 0xFFFF
    r1 = r26 & 0XFFFF;
    // add         $1, $1, $4
    r1 = RSP_ADD32(r1, r4);
    // vxor        $v1, $v1, $v1
    rsp.VXOR<0>(rsp.vpu.r[1], rsp.vpu.r[1], rsp.vpu.r[1]);
    // addi        $3, $3, -0x10
    r3 = RSP_ADD32(r3, -0X10);
    // beq         $22, $zero, L_11C0
    if (r22 == 0) {
        // nop
    
        goto L_11C0;
    }
    // nop

L_11B0:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // bne         $5, $zero, L_11B0
    if (r5 != 0) {
        // nop
    
        goto L_11B0;
    }
    // nop

    // and         $22, $zero, $zero
    r22 = 0 & 0;
L_11C0:
    // sdv         $v1[0], 0x0($1)
    rsp.SDV<0>(rsp.vpu.r[1], r1, 0X0);
    // sdv         $v1[0], 0x8($1)
    rsp.SDV<0>(rsp.vpu.r[1], r1, 0X1);
    // addi        $1, $1, 0x10
    r1 = RSP_ADD32(r1, 0X10);
    // bgtz        $3, L_11C0
    if (RSP_SIGNED(r3) > 0) {
        // addi        $3, $3, -0x10
        r3 = RSP_ADD32(r3, -0X10);
        goto L_11C0;
    }
    // addi        $3, $3, -0x10
    r3 = RSP_ADD32(r3, -0X10);
    // j           L_1118
    // nop

    goto L_1118;
    // nop

    // lhu         $3, 0x4($24)
    r3 = RSP_MEM_HU_LOAD(0X4, r24);
    // beq         $3, $zero, L_10B8
    if (r3 == 0) {
        // sll         $2, $25, 8
        r2 = S32(r25) << 8;
        goto L_10B8;
    }
    // sll         $2, $25, 8
    r2 = S32(r25) << 8;
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
    // srl         $4, $25, 24
    r4 = S32(U32(r25) >> 24);
    // sll         $4, $4, 2
    r4 = S32(r4) << 2;
    // lw          $5, 0x320($4)
    r5 = RSP_MEM_W_LOAD(0X320, r4);
    // add         $2, $2, $5
    r2 = RSP_ADD32(r2, r5);
    // lhu         $1, 0x0($24)
    r1 = RSP_MEM_HU_LOAD(0X0, r24);
    // jal         0x1194
    r31 = 0x1208;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    goto L_1194;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
L_1208:
    // j           L_1118
    // nop

    goto L_1118;
    // nop

    // lhu         $3, 0x4($24)
    r3 = RSP_MEM_HU_LOAD(0X4, r24);
    // beq         $3, $zero, L_10B8
    if (r3 == 0) {
        // sll         $2, $25, 8
        r2 = S32(r25) << 8;
        goto L_10B8;
    }
    // sll         $2, $25, 8
    r2 = S32(r25) << 8;
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
    // srl         $4, $25, 24
    r4 = S32(U32(r25) >> 24);
    // sll         $4, $4, 2
    r4 = S32(r4) << 2;
    // lw          $5, 0x320($4)
    r5 = RSP_MEM_W_LOAD(0X320, r4);
    // add         $2, $2, $5
    r2 = RSP_ADD32(r2, r5);
    // lhu         $1, 0x2($24)
    r1 = RSP_MEM_HU_LOAD(0X2, r24);
    // jal         0x11C0
    r31 = 0x123C;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    goto L_11C0;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
L_123C:
    // j           L_1118
    // nop

    goto L_1118;
    // nop

    // sll         $2, $25, 8
    r2 = S32(r25) << 8;
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
    // srl         $4, $25, 24
    r4 = S32(U32(r25) >> 24);
    // sll         $4, $4, 2
    r4 = S32(r4) << 2;
    // lw          $5, 0x320($4)
    r5 = RSP_MEM_W_LOAD(0X320, r4);
    // add         $2, $2, $5
    r2 = RSP_ADD32(r2, r5);
    // addi        $1, $zero, 0x4C0
    r1 = RSP_ADD32(0, 0X4C0);
    // andi        $3, $26, 0xFFFF
    r3 = r26 & 0XFFFF;
    // jal         0x1194
    r31 = 0x126C;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    goto L_1194;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
L_126C:
    // j           L_1118
    // nop

    goto L_1118;
    // nop

    // sll         $3, $25, 8
    r3 = S32(r25) << 8;
    // srl         $3, $3, 8
    r3 = S32(U32(r3) >> 8);
    // srl         $2, $25, 24
    r2 = S32(U32(r25) >> 24);
    // sll         $2, $2, 2
    r2 = S32(r2) << 2;
    // add         $4, $zero, $2
    r4 = RSP_ADD32(0, r2);
    // j           L_1118
    // sw          $3, 0x320($4)
    RSP_MEM_W_STORE(0X320, r4, r3);
    goto L_1118;
    // sw          $3, 0x320($4)
    RSP_MEM_W_STORE(0X320, r4, r3);
    // addi        $1, $26, 0x5C0
    r1 = RSP_ADD32(r26, 0X5C0);
    // srl         $2, $25, 16
    r2 = S32(U32(r25) >> 16);
    // addi        $2, $2, 0x5C0
    r2 = RSP_ADD32(r2, 0X5C0);
    // srl         $4, $26, 16
    r4 = S32(U32(r26) >> 16);
    // andi        $4, $4, 0x8
    r4 = r4 & 0X8;
    // bgtz        $4, L_12BC
    if (RSP_SIGNED(r4) > 0) {
        // addi        $3, $25, 0x5C0
        r3 = RSP_ADD32(r25, 0X5C0);
        goto L_12BC;
    }
    // addi        $3, $25, 0x5C0
    r3 = RSP_ADD32(r25, 0X5C0);
    // sh          $1, 0x0($24)
    RSP_MEM_H_STORE(0X0, r24, r1);
    // sh          $2, 0x2($24)
    RSP_MEM_H_STORE(0X2, r24, r2);
    // j           L_1118
    // sh          $25, 0x4($24)
    RSP_MEM_H_STORE(0X4, r24, r25);
    goto L_1118;
    // sh          $25, 0x4($24)
    RSP_MEM_H_STORE(0X4, r24, r25);
L_12BC:
    // sh          $3, 0xE($24)
    RSP_MEM_H_STORE(0XE, r24, r3);
    // sh          $1, 0xA($24)
    RSP_MEM_H_STORE(0XA, r24, r1);
    // j           L_1118
    // sh          $2, 0xC($24)
    RSP_MEM_H_STORE(0XC, r24, r2);
    goto L_1118;
    // sh          $2, 0xC($24)
    RSP_MEM_H_STORE(0XC, r24, r2);
    // srl         $2, $26, 16
    r2 = S32(U32(r26) >> 16);
    // andi        $1, $2, 0x8
    r1 = r2 & 0X8;
    // beq         $1, $zero, L_12E8
    if (r1 == 0) {
        // andi        $1, $2, 0x4
        r1 = r2 & 0X4;
        goto L_12E8;
    }
    // andi        $1, $2, 0x4
    r1 = r2 & 0X4;
    // sh          $26, 0x1C($24)
    RSP_MEM_H_STORE(0X1C, r24, r26);
    // j           L_1118
    // sh          $25, 0x1E($24)
    RSP_MEM_H_STORE(0X1E, r24, r25);
    goto L_1118;
    // sh          $25, 0x1E($24)
    RSP_MEM_H_STORE(0X1E, r24, r25);
L_12E8:
    // beq         $1, $zero, L_1308
    if (r1 == 0) {
        // andi        $1, $2, 0x2
        r1 = r2 & 0X2;
        goto L_1308;
    }
    // andi        $1, $2, 0x2
    r1 = r2 & 0X2;
    // beq         $1, $zero, L_1300
    if (r1 == 0) {
        // nop
    
        goto L_1300;
    }
    // nop

    // j           L_1118
    // sh          $26, 0x6($24)
    RSP_MEM_H_STORE(0X6, r24, r26);
    goto L_1118;
    // sh          $26, 0x6($24)
    RSP_MEM_H_STORE(0X6, r24, r26);
L_1300:
    // j           L_1118
    // sh          $26, 0x8($24)
    RSP_MEM_H_STORE(0X8, r24, r26);
    goto L_1118;
    // sh          $26, 0x8($24)
    RSP_MEM_H_STORE(0X8, r24, r26);
L_1308:
    // beq         $1, $zero, L_1320
    if (r1 == 0) {
        // srl         $1, $25, 16
        r1 = S32(U32(r25) >> 16);
        goto L_1320;
    }
    // srl         $1, $25, 16
    r1 = S32(U32(r25) >> 16);
    // sh          $26, 0x10($24)
    RSP_MEM_H_STORE(0X10, r24, r26);
    // sh          $1, 0x12($24)
    RSP_MEM_H_STORE(0X12, r24, r1);
    // j           L_1118
    // sh          $25, 0x14($24)
    RSP_MEM_H_STORE(0X14, r24, r25);
    goto L_1118;
    // sh          $25, 0x14($24)
    RSP_MEM_H_STORE(0X14, r24, r25);
L_1320:
    // sh          $26, 0x16($24)
    RSP_MEM_H_STORE(0X16, r24, r26);
    // sh          $1, 0x18($24)
    RSP_MEM_H_STORE(0X18, r24, r1);
    // j           L_1118
    // sh          $25, 0x1A($24)
    RSP_MEM_H_STORE(0X1A, r24, r25);
    goto L_1118;
    // sh          $25, 0x1A($24)
    RSP_MEM_H_STORE(0X1A, r24, r25);
    // lhu         $4, 0x4($24)
    r4 = RSP_MEM_HU_LOAD(0X4, r24);
    // lhu         $3, 0x2($24)
    r3 = RSP_MEM_HU_LOAD(0X2, r24);
    // beq         $4, $zero, L_10B8
    if (r4 == 0) {
        // andi        $2, $25, 0xFFFF
        r2 = r25 & 0XFFFF;
        goto L_10B8;
    }
    // andi        $2, $25, 0xFFFF
    r2 = r25 & 0XFFFF;
    // addi        $2, $2, 0x5C0
    r2 = RSP_ADD32(r2, 0X5C0);
    // srl         $1, $25, 16
    r1 = S32(U32(r25) >> 16);
    // addi        $1, $1, 0x5C0
    r1 = RSP_ADD32(r1, 0X5C0);
    // beq         $22, $zero, L_1364
    if (r22 == 0) {
        // nop
    
        goto L_1364;
    }
    // nop

L_1354:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // bne         $5, $zero, L_1354
    if (r5 != 0) {
        // nop
    
        goto L_1354;
    }
    // nop

    // and         $22, $zero, $zero
    r22 = 0 & 0;
L_1364:
    // lqv         $v1[0], 0x0($1)
    rsp.LQV<0>(rsp.vpu.r[1], r1, 0X0);
    // lqv         $v2[0], 0x0($2)
    rsp.LQV<0>(rsp.vpu.r[2], r2, 0X0);
    // ssv         $v1[0], 0x0($3)
    rsp.SSV<0>(rsp.vpu.r[1], r3, 0X0);
    // ssv         $v2[0], 0x2($3)
    rsp.SSV<0>(rsp.vpu.r[2], r3, 0X1);
    // ssv         $v1[2], 0x4($3)
    rsp.SSV<2>(rsp.vpu.r[1], r3, 0X2);
    // ssv         $v2[2], 0x6($3)
    rsp.SSV<2>(rsp.vpu.r[2], r3, 0X3);
    // ssv         $v1[4], 0x8($3)
    rsp.SSV<4>(rsp.vpu.r[1], r3, 0X4);
    // ssv         $v2[4], 0xA($3)
    rsp.SSV<4>(rsp.vpu.r[2], r3, 0X5);
    // ssv         $v1[6], 0xC($3)
    rsp.SSV<6>(rsp.vpu.r[1], r3, 0X6);
    // ssv         $v2[6], 0xE($3)
    rsp.SSV<6>(rsp.vpu.r[2], r3, 0X7);
    // ssv         $v1[8], 0x10($3)
    rsp.SSV<8>(rsp.vpu.r[1], r3, 0X8);
    // ssv         $v2[8], 0x12($3)
    rsp.SSV<8>(rsp.vpu.r[2], r3, 0X9);
    // ssv         $v1[10], 0x14($3)
    rsp.SSV<10>(rsp.vpu.r[1], r3, 0XA);
    // ssv         $v2[10], 0x16($3)
    rsp.SSV<10>(rsp.vpu.r[2], r3, 0XB);
    // ssv         $v1[12], 0x18($3)
    rsp.SSV<12>(rsp.vpu.r[1], r3, 0XC);
    // ssv         $v2[12], 0x1A($3)
    rsp.SSV<12>(rsp.vpu.r[2], r3, 0XD);
    // ssv         $v1[14], 0x1C($3)
    rsp.SSV<14>(rsp.vpu.r[1], r3, 0XE);
    // ssv         $v2[14], 0x1E($3)
    rsp.SSV<14>(rsp.vpu.r[2], r3, 0XF);
    // addi        $4, $4, -0x10
    r4 = RSP_ADD32(r4, -0X10);
    // addi        $1, $1, 0x10
    r1 = RSP_ADD32(r1, 0X10);
    // addi        $2, $2, 0x10
    r2 = RSP_ADD32(r2, 0X10);
    // bgtz        $4, L_1364
    if (RSP_SIGNED(r4) > 0) {
        // addi        $3, $3, 0x20
        r3 = RSP_ADD32(r3, 0X20);
        goto L_1364;
    }
    // addi        $3, $3, 0x20
    r3 = RSP_ADD32(r3, 0X20);
    // j           L_1118
    // nop

    goto L_1118;
    // nop

    // andi        $3, $25, 0xFFFF
    r3 = r25 & 0XFFFF;
    // beq         $3, $zero, L_10B8
    if (r3 == 0) {
        // andi        $1, $26, 0xFFFF
        r1 = r26 & 0XFFFF;
        goto L_10B8;
    }
    // andi        $1, $26, 0xFFFF
    r1 = r26 & 0XFFFF;
    // addi        $1, $1, 0x5C0
    r1 = RSP_ADD32(r1, 0X5C0);
    // srl         $2, $25, 16
    r2 = S32(U32(r25) >> 16);
    // addi        $2, $2, 0x5C0
    r2 = RSP_ADD32(r2, 0X5C0);
    // beq         $22, $zero, L_13F8
    if (r22 == 0) {
        // nop
    
        goto L_13F8;
    }
    // nop

L_13E8:
    // mfc0        $4, SP_DMA_BUSY
    r4 = 0;
    // bne         $4, $zero, L_13E8
    if (r4 != 0) {
        // nop
    
        goto L_13E8;
    }
    // nop

    // and         $22, $zero, $zero
    r22 = 0 & 0;
L_13F8:
    // ldv         $v1[0], 0x0($1)
    rsp.LDV<0>(rsp.vpu.r[1], r1, 0X0);
    // ldv         $v2[0], 0x8($1)
    rsp.LDV<0>(rsp.vpu.r[2], r1, 0X1);
    // addi        $3, $3, -0x10
    r3 = RSP_ADD32(r3, -0X10);
    // addi        $1, $1, 0x10
    r1 = RSP_ADD32(r1, 0X10);
    // sdv         $v1[0], 0x0($2)
    rsp.SDV<0>(rsp.vpu.r[1], r2, 0X0);
    // sdv         $v2[0], 0x8($2)
    rsp.SDV<0>(rsp.vpu.r[2], r2, 0X1);
    // bgtz        $3, L_13F8
    if (RSP_SIGNED(r3) > 0) {
        // addi        $2, $2, 0x10
        r2 = RSP_ADD32(r2, 0X10);
        goto L_13F8;
    }
    // addi        $2, $2, 0x10
    r2 = RSP_ADD32(r2, 0X10);
    // j           L_1118
    // nop

    goto L_1118;
    // nop

    // sll         $1, $25, 8
    r1 = S32(r25) << 8;
    // srl         $1, $1, 8
    r1 = S32(U32(r1) >> 8);
    // srl         $3, $25, 24
    r3 = S32(U32(r25) >> 24);
    // sll         $3, $3, 2
    r3 = S32(r3) << 2;
    // lw          $2, 0x320($3)
    r2 = RSP_MEM_W_LOAD(0X320, r3);
    // add         $1, $1, $2
    r1 = RSP_ADD32(r1, r2);
    // sw          $1, 0x10($24)
    RSP_MEM_W_STORE(0X10, r24, r1);
    // j           L_1118
    // nop

    goto L_1118;
    // nop

    // lqv         $v31[0], 0x0($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X0);
    // vxor        $v27, $v27, $v27
    rsp.VXOR<0>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[27]);
    // lhu         $21, 0x0($24)
    r21 = RSP_MEM_HU_LOAD(0X0, r24);
    // vxor        $v25, $v25, $v25
    rsp.VXOR<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[25]);
    // vxor        $v24, $v24, $v24
    rsp.VXOR<0>(rsp.vpu.r[24], rsp.vpu.r[24], rsp.vpu.r[24]);
    // addi        $20, $21, 0x1
    r20 = RSP_ADD32(r21, 0X1);
    // lhu         $19, 0x2($24)
    r19 = RSP_MEM_HU_LOAD(0X2, r24);
    // vxor        $v13, $v13, $v13
    rsp.VXOR<0>(rsp.vpu.r[13], rsp.vpu.r[13], rsp.vpu.r[13]);
    // vxor        $v14, $v14, $v14
    rsp.VXOR<0>(rsp.vpu.r[14], rsp.vpu.r[14], rsp.vpu.r[14]);
    // lhu         $18, 0x4($24)
    r18 = RSP_MEM_HU_LOAD(0X4, r24);
    // vxor        $v15, $v15, $v15
    rsp.VXOR<0>(rsp.vpu.r[15], rsp.vpu.r[15], rsp.vpu.r[15]);
    // lui         $1, 0xFF
    r1 = S32(0XFF << 16);
    // vxor        $v16, $v16, $v16
    rsp.VXOR<0>(rsp.vpu.r[16], rsp.vpu.r[16], rsp.vpu.r[16]);
    // ori         $1, $1, 0xFFFF
    r1 = r1 | 0XFFFF;
    // vxor        $v17, $v17, $v17
    rsp.VXOR<0>(rsp.vpu.r[17], rsp.vpu.r[17], rsp.vpu.r[17]);
    // and         $17, $25, $1
    r17 = r25 & r1;
    // vxor        $v18, $v18, $v18
    rsp.VXOR<0>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[18]);
    // srl         $2, $25, 24
    r2 = S32(U32(r25) >> 24);
    // vxor        $v19, $v19, $v19
    rsp.VXOR<0>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[19]);
    // sll         $2, $2, 2
    r2 = S32(r2) << 2;
    // lw          $3, 0x320($2)
    r3 = RSP_MEM_W_LOAD(0X320, r2);
    // add         $17, $17, $3
    r17 = RSP_ADD32(r17, r3);
    // sqv         $v27[0], 0x0($19)
    rsp.SQV<0>(rsp.vpu.r[27], r19, 0X0);
    // sqv         $v27[0], 0x10($19)
    rsp.SQV<0>(rsp.vpu.r[27], r19, 0X1);
    // srl         $1, $26, 16
    r1 = S32(U32(r26) >> 16);
    // andi        $1, $1, 0x1
    r1 = r1 & 0X1;
    // bgtz        $1, L_14E0
    if (RSP_SIGNED(r1) > 0) {
        // srl         $1, $26, 16
        r1 = S32(U32(r26) >> 16);
        goto L_14E0;
    }
    // srl         $1, $26, 16
    r1 = S32(U32(r26) >> 16);
    // andi        $1, $1, 0x2
    r1 = r1 & 0X2;
    // beq         $zero, $1, L_14C4
    if (0 == r1) {
        // addi        $2, $17, 0x0
        r2 = RSP_ADD32(r17, 0X0);
        goto L_14C4;
    }
    // addi        $2, $17, 0x0
    r2 = RSP_ADD32(r17, 0X0);
    // lw          $2, 0x10($24)
    r2 = RSP_MEM_W_LOAD(0X10, r24);
L_14C4:
    // addi        $1, $19, 0x0
    r1 = RSP_ADD32(r19, 0X0);
    // jal         0x1194
    r31 = 0x14D0;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
    goto L_1194;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
L_14D0:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // bne         $5, $zero, L_14D0
    if (r5 != 0) {
        // nop
    
        goto L_14D0;
    }
    // nop

    // add         $22, $zero, $zero
    r22 = RSP_ADD32(0, 0);
L_14E0:
    // beq         $22, $zero, L_14F8
    if (r22 == 0) {
        // nop
    
        goto L_14F8;
    }
    // nop

L_14E8:
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
    // bne         $1, $zero, L_14E8
    if (r1 != 0) {
        // nop
    
        goto L_14E8;
    }
    // nop

    // and         $22, $zero, $zero
    r22 = 0 & 0;
L_14F8:
    // addi        $16, $zero, 0x30
    r16 = RSP_ADD32(0, 0X30);
    // addi        $15, $zero, 0x4C0
    r15 = RSP_ADD32(0, 0X4C0);
    // ldv         $v25[0], 0x0($16)
    rsp.LDV<0>(rsp.vpu.r[25], r16, 0X0);
    // ldv         $v24[8], 0x0($16)
    rsp.LDV<8>(rsp.vpu.r[24], r16, 0X0);
    // ldv         $v23[0], 0x8($16)
    rsp.LDV<0>(rsp.vpu.r[23], r16, 0X1);
    // ldv         $v23[8], 0x8($16)
    rsp.LDV<8>(rsp.vpu.r[23], r16, 0X1);
    // lqv         $v27[0], 0x10($19)
    rsp.LQV<0>(rsp.vpu.r[27], r19, 0X1);
    // addi        $19, $19, 0x20
    r19 = RSP_ADD32(r19, 0X20);
    // beq         $18, $zero, L_16D4
    if (r18 == 0) {
        // ldv         $v1[0], 0x0($20)
        rsp.LDV<0>(rsp.vpu.r[1], r20, 0X0);
        goto L_16D4;
    }
    // ldv         $v1[0], 0x0($20)
    rsp.LDV<0>(rsp.vpu.r[1], r20, 0X0);
    // lbu         $1, 0x0($21)
    r1 = RSP_MEM_BU(0X0, r21);
    // andi        $11, $1, 0xF
    r11 = r1 & 0XF;
    // sll         $11, $11, 5
    r11 = S32(r11) << 5;
    // vand        $v3, $v25, $v1[0]
    rsp.VAND<8>(rsp.vpu.r[3], rsp.vpu.r[25], rsp.vpu.r[1]);
    // add         $13, $11, $15
    r13 = RSP_ADD32(r11, r15);
    // vand        $v4, $v24, $v1[1]
    rsp.VAND<9>(rsp.vpu.r[4], rsp.vpu.r[24], rsp.vpu.r[1]);
    // srl         $14, $1, 4
    r14 = S32(U32(r1) >> 4);
    // vand        $v5, $v25, $v1[2]
    rsp.VAND<10>(rsp.vpu.r[5], rsp.vpu.r[25], rsp.vpu.r[1]);
    // addi        $2, $zero, 0xC
    r2 = RSP_ADD32(0, 0XC);
    // vand        $v6, $v24, $v1[3]
    rsp.VAND<11>(rsp.vpu.r[6], rsp.vpu.r[24], rsp.vpu.r[1]);
    // sub         $14, $2, $14
    r14 = RSP_SUB32(r2, r14);
    // addi        $2, $14, -0x1
    r2 = RSP_ADD32(r14, -0X1);
    // addi        $3, $zero, 0x1
    r3 = RSP_ADD32(0, 0X1);
    // sll         $3, $3, 15
    r3 = S32(r3) << 15;
    // srlv        $4, $3, $2
    r4 = S32(U32(r3) >> (r2 & 31));
    // mtc2        $4, $v22[0]
    rsp.MTC2<0>(r4, rsp.vpu.r[22]);
    // lqv         $v21[0], 0x0($13)
    rsp.LQV<0>(rsp.vpu.r[21], r13, 0X0);
    // lqv         $v20[0], 0x10($13)
    rsp.LQV<0>(rsp.vpu.r[20], r13, 0X1);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v19[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[19], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v18[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[18], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v17[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[17], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v16[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[16], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v15[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[15], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v14[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[14], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v13[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[13], r13, 0X2);
L_15A0:
    // addi        $20, $20, 0x9
    r20 = RSP_ADD32(r20, 0X9);
    // vmudn       $v30, $v3, $v23
    rsp.VMUDN<0>(rsp.vpu.r[30], rsp.vpu.r[3], rsp.vpu.r[23]);
    // addi        $21, $21, 0x9
    r21 = RSP_ADD32(r21, 0X9);
    // vmadn       $v30, $v4, $v23
    rsp.VMADN<0>(rsp.vpu.r[30], rsp.vpu.r[4], rsp.vpu.r[23]);
    // ldv         $v1[0], 0x0($20)
    rsp.LDV<0>(rsp.vpu.r[1], r20, 0X0);
    // vmudn       $v29, $v5, $v23
    rsp.VMUDN<0>(rsp.vpu.r[29], rsp.vpu.r[5], rsp.vpu.r[23]);
    // lbu         $1, 0x0($21)
    r1 = RSP_MEM_BU(0X0, r21);
    // vmadn       $v29, $v6, $v23
    rsp.VMADN<0>(rsp.vpu.r[29], rsp.vpu.r[6], rsp.vpu.r[23]);
    // blez        $14, L_15D0
    if (RSP_SIGNED(r14) <= 0) {
        // andi        $11, $1, 0xF
        r11 = r1 & 0XF;
        goto L_15D0;
    }
    // andi        $11, $1, 0xF
    r11 = r1 & 0XF;
    // vmudm       $v30, $v30, $v22[0]
    rsp.VMUDM<8>(rsp.vpu.r[30], rsp.vpu.r[30], rsp.vpu.r[22]);
    // vmudm       $v29, $v29, $v22[0]
    rsp.VMUDM<8>(rsp.vpu.r[29], rsp.vpu.r[29], rsp.vpu.r[22]);
L_15D0:
    // sll         $11, $11, 5
    r11 = S32(r11) << 5;
    // vand        $v3, $v25, $v1[0]
    rsp.VAND<8>(rsp.vpu.r[3], rsp.vpu.r[25], rsp.vpu.r[1]);
    // add         $13, $11, $15
    r13 = RSP_ADD32(r11, r15);
    // vand        $v4, $v24, $v1[1]
    rsp.VAND<9>(rsp.vpu.r[4], rsp.vpu.r[24], rsp.vpu.r[1]);
    // vand        $v5, $v25, $v1[2]
    rsp.VAND<10>(rsp.vpu.r[5], rsp.vpu.r[25], rsp.vpu.r[1]);
    // vand        $v6, $v24, $v1[3]
    rsp.VAND<11>(rsp.vpu.r[6], rsp.vpu.r[24], rsp.vpu.r[1]);
    // srl         $14, $1, 4
    r14 = S32(U32(r1) >> 4);
    // vmudh       $v2, $v21, $v27[6]
    rsp.VMUDH<14>(rsp.vpu.r[2], rsp.vpu.r[21], rsp.vpu.r[27]);
    // addi        $2, $zero, 0xC
    r2 = RSP_ADD32(0, 0XC);
    // vmadh       $v2, $v20, $v27[7]
    rsp.VMADH<15>(rsp.vpu.r[2], rsp.vpu.r[20], rsp.vpu.r[27]);
    // sub         $14, $2, $14
    r14 = RSP_SUB32(r2, r14);
    // vmadh       $v2, $v19, $v30[0]
    rsp.VMADH<8>(rsp.vpu.r[2], rsp.vpu.r[19], rsp.vpu.r[30]);
    // addi        $2, $14, -0x1
    r2 = RSP_ADD32(r14, -0X1);
    // vmadh       $v2, $v18, $v30[1]
    rsp.VMADH<9>(rsp.vpu.r[2], rsp.vpu.r[18], rsp.vpu.r[30]);
    // addi        $3, $zero, 0x1
    r3 = RSP_ADD32(0, 0X1);
    // vmadh       $v2, $v17, $v30[2]
    rsp.VMADH<10>(rsp.vpu.r[2], rsp.vpu.r[17], rsp.vpu.r[30]);
    // sll         $3, $3, 15
    r3 = S32(r3) << 15;
    // vmadh       $v2, $v16, $v30[3]
    rsp.VMADH<11>(rsp.vpu.r[2], rsp.vpu.r[16], rsp.vpu.r[30]);
    // srlv        $4, $3, $2
    r4 = S32(U32(r3) >> (r2 & 31));
    // vmadh       $v28, $v15, $v30[4]
    rsp.VMADH<12>(rsp.vpu.r[28], rsp.vpu.r[15], rsp.vpu.r[30]);
    // mtc2        $4, $v22[0]
    rsp.MTC2<0>(r4, rsp.vpu.r[22]);
    // vmadh       $v2, $v14, $v30[5]
    rsp.VMADH<13>(rsp.vpu.r[2], rsp.vpu.r[14], rsp.vpu.r[30]);
    // vmadh       $v2, $v13, $v30[6]
    rsp.VMADH<14>(rsp.vpu.r[2], rsp.vpu.r[13], rsp.vpu.r[30]);
    // vmadh       $v2, $v30, $v31[5]
    rsp.VMADH<13>(rsp.vpu.r[2], rsp.vpu.r[30], rsp.vpu.r[31]);
    // vsar        $v26, $v7, $v28[1]
    rsp.VSAR<9>(rsp.vpu.r[26], rsp.vpu.r[7]);
    // vsar        $v28, $v7, $v28[0]
    rsp.VSAR<8>(rsp.vpu.r[28], rsp.vpu.r[7]);
    // vmudn       $v2, $v26, $v31[4]
    rsp.VMUDN<12>(rsp.vpu.r[2], rsp.vpu.r[26], rsp.vpu.r[31]);
    // vmadh       $v28, $v28, $v31[4]
    rsp.VMADH<12>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[31]);
    // vmudh       $v2, $v19, $v29[0]
    rsp.VMUDH<8>(rsp.vpu.r[2], rsp.vpu.r[19], rsp.vpu.r[29]);
    // addi        $12, $13, -0x2
    r12 = RSP_ADD32(r13, -0X2);
    // vmadh       $v2, $v18, $v29[1]
    rsp.VMADH<9>(rsp.vpu.r[2], rsp.vpu.r[18], rsp.vpu.r[29]);
    // lrv         $v19[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[19], r12, 0X2);
    // vmadh       $v2, $v17, $v29[2]
    rsp.VMADH<10>(rsp.vpu.r[2], rsp.vpu.r[17], rsp.vpu.r[29]);
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
    // vmadh       $v2, $v16, $v29[3]
    rsp.VMADH<11>(rsp.vpu.r[2], rsp.vpu.r[16], rsp.vpu.r[29]);
    // lrv         $v18[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[18], r12, 0X2);
    // vmadh       $v2, $v15, $v29[4]
    rsp.VMADH<12>(rsp.vpu.r[2], rsp.vpu.r[15], rsp.vpu.r[29]);
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
    // vmadh       $v2, $v14, $v29[5]
    rsp.VMADH<13>(rsp.vpu.r[2], rsp.vpu.r[14], rsp.vpu.r[29]);
    // lrv         $v17[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[17], r12, 0X2);
    // vmadh       $v2, $v13, $v29[6]
    rsp.VMADH<14>(rsp.vpu.r[2], rsp.vpu.r[13], rsp.vpu.r[29]);
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
    // vmadh       $v2, $v29, $v31[5]
    rsp.VMADH<13>(rsp.vpu.r[2], rsp.vpu.r[29], rsp.vpu.r[31]);
    // lrv         $v16[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[16], r12, 0X2);
    // vmadh       $v2, $v21, $v28[6]
    rsp.VMADH<14>(rsp.vpu.r[2], rsp.vpu.r[21], rsp.vpu.r[28]);
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
    // vmadh       $v2, $v20, $v28[7]
    rsp.VMADH<15>(rsp.vpu.r[2], rsp.vpu.r[20], rsp.vpu.r[28]);
    // lrv         $v15[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[15], r12, 0X2);
    // vsar        $v26, $v7, $v27[1]
    rsp.VSAR<9>(rsp.vpu.r[26], rsp.vpu.r[7]);
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
    // vsar        $v27, $v7, $v27[0]
    rsp.VSAR<8>(rsp.vpu.r[27], rsp.vpu.r[7]);
    // lrv         $v14[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[14], r12, 0X2);
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
    // lrv         $v13[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[13], r12, 0X2);
    // lqv         $v21[0], 0x0($13)
    rsp.LQV<0>(rsp.vpu.r[21], r13, 0X0);
    // vmudn       $v2, $v26, $v31[4]
    rsp.VMUDN<12>(rsp.vpu.r[2], rsp.vpu.r[26], rsp.vpu.r[31]);
    // lqv         $v20[0], 0x10($13)
    rsp.LQV<0>(rsp.vpu.r[20], r13, 0X1);
    // vmadh       $v27, $v27, $v31[4]
    rsp.VMADH<12>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[31]);
    // addi        $18, $18, -0x20
    r18 = RSP_ADD32(r18, -0X20);
    // sdv         $v28[0], 0x0($19)
    rsp.SDV<0>(rsp.vpu.r[28], r19, 0X0);
    // sdv         $v28[8], 0x8($19)
    rsp.SDV<8>(rsp.vpu.r[28], r19, 0X1);
    // sdv         $v27[0], 0x10($19)
    rsp.SDV<0>(rsp.vpu.r[27], r19, 0X2);
    // sdv         $v27[8], 0x18($19)
    rsp.SDV<8>(rsp.vpu.r[27], r19, 0X3);
    // bgtz        $18, L_15A0
    if (RSP_SIGNED(r18) > 0) {
        // addi        $19, $19, 0x20
        r19 = RSP_ADD32(r19, 0X20);
        goto L_15A0;
    }
    // addi        $19, $19, 0x20
    r19 = RSP_ADD32(r19, 0X20);
L_16D4:
    // addi        $1, $19, -0x20
    r1 = RSP_ADD32(r19, -0X20);
    // addi        $2, $17, 0x0
    r2 = RSP_ADD32(r17, 0X0);
    // jal         0x11C0
    r31 = 0x16E4;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
    goto L_11C0;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
L_16E4:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // bne         $5, $zero, L_16E4
    if (r5 != 0) {
        // nop
    
        goto L_16E4;
    }
    // nop

    // j           L_1118
    // and         $22, $zero, $zero
    r22 = 0 & 0;
    goto L_1118;
    // and         $22, $zero, $zero
    r22 = 0 & 0;
    // lqv         $v31[0], 0x0($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X0);
    // vxor        $v28, $v28, $v28
    rsp.VXOR<0>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[28]);
    // lhu         $21, 0x0($24)
    r21 = RSP_MEM_HU_LOAD(0X0, r24);
    // vxor        $v17, $v17, $v17
    rsp.VXOR<0>(rsp.vpu.r[17], rsp.vpu.r[17], rsp.vpu.r[17]);
    // lhu         $20, 0x2($24)
    r20 = RSP_MEM_HU_LOAD(0X2, r24);
    // vxor        $v18, $v18, $v18
    rsp.VXOR<0>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[18]);
    // lhu         $19, 0x4($24)
    r19 = RSP_MEM_HU_LOAD(0X4, r24);
    // vxor        $v19, $v19, $v19
    rsp.VXOR<0>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[19]);
    // beq         $19, $zero, L_186C
    if (r19 == 0) {
        // andi        $14, $26, 0xFFFF
        r14 = r26 & 0XFFFF;
        goto L_186C;
    }
    // andi        $14, $26, 0xFFFF
    r14 = r26 & 0XFFFF;
    // mtc2        $14, $v31[10]
    rsp.MTC2<10>(r14, rsp.vpu.r[31]);
    // sll         $14, $14, 2
    r14 = S32(r14) << 2;
    // mtc2        $14, $v16[0]
    rsp.MTC2<0>(r14, rsp.vpu.r[16]);
    // lui         $1, 0xFF
    r1 = S32(0XFF << 16);
    // vxor        $v20, $v20, $v20
    rsp.VXOR<0>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[20]);
    // ori         $1, $1, 0xFFFF
    r1 = r1 | 0XFFFF;
    // vxor        $v21, $v21, $v21
    rsp.VXOR<0>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[21]);
    // and         $18, $25, $1
    r18 = r25 & r1;
    // vxor        $v22, $v22, $v22
    rsp.VXOR<0>(rsp.vpu.r[22], rsp.vpu.r[22], rsp.vpu.r[22]);
    // srl         $2, $25, 24
    r2 = S32(U32(r25) >> 24);
    // vxor        $v23, $v23, $v23
    rsp.VXOR<0>(rsp.vpu.r[23], rsp.vpu.r[23], rsp.vpu.r[23]);
    // sll         $2, $2, 2
    r2 = S32(r2) << 2;
    // lw          $3, 0x320($2)
    r3 = RSP_MEM_W_LOAD(0X320, r2);
    // add         $18, $18, $3
    r18 = RSP_ADD32(r18, r3);
    // slv         $v28[0], 0x0($23)
    rsp.SLV<0>(rsp.vpu.r[28], r23, 0X0);
    // srl         $1, $26, 16
    r1 = S32(U32(r26) >> 16);
    // andi        $1, $1, 0x1
    r1 = r1 & 0X1;
    // bgtz        $1, L_178C
    if (RSP_SIGNED(r1) > 0) {
        // nop
    
        goto L_178C;
    }
    // nop

    // addi        $1, $23, 0x0
    r1 = RSP_ADD32(r23, 0X0);
    // addi        $2, $18, 0x0
    r2 = RSP_ADD32(r18, 0X0);
    // jal         0x1194
    r31 = 0x177C;
    // addi        $3, $zero, 0x7
    r3 = RSP_ADD32(0, 0X7);
    goto L_1194;
    // addi        $3, $zero, 0x7
    r3 = RSP_ADD32(0, 0X7);
L_177C:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // bne         $5, $zero, L_177C
    if (r5 != 0) {
        // nop
    
        goto L_177C;
    }
    // nop

    // add         $22, $zero, $zero
    r22 = RSP_ADD32(0, 0);
L_178C:
    // beq         $22, $zero, L_17A4
    if (r22 == 0) {
        // nop
    
        goto L_17A4;
    }
    // nop

L_1794:
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
    // bne         $1, $zero, L_1794
    if (r1 != 0) {
        // nop
    
        goto L_1794;
    }
    // nop

    // add         $22, $zero, $zero
    r22 = RSP_ADD32(0, 0);
L_17A4:
    // addi        $13, $zero, 0x4C0
    r13 = RSP_ADD32(0, 0X4C0);
    // addi        $1, $zero, 0x4
    r1 = RSP_ADD32(0, 0X4);
    // mtc2        $1, $v14[0]
    rsp.MTC2<0>(r1, rsp.vpu.r[14]);
    // lqv         $v24[0], 0x10($13)
    rsp.LQV<0>(rsp.vpu.r[24], r13, 0X1);
    // vmudm       $v16, $v24, $v16[0]
    rsp.VMUDM<8>(rsp.vpu.r[16], rsp.vpu.r[24], rsp.vpu.r[16]);
    // ldv         $v28[8], 0x0($23)
    rsp.LDV<8>(rsp.vpu.r[28], r23, 0X0);
    // sqv         $v16[0], 0x10($13)
    rsp.SQV<0>(rsp.vpu.r[16], r13, 0X1);
    // lqv         $v25[0], 0x0($13)
    rsp.LQV<0>(rsp.vpu.r[25], r13, 0X0);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v23[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[23], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v22[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[22], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v21[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[21], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v20[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[20], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v19[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[19], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v18[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[18], r13, 0X2);
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
    // lrv         $v17[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[17], r13, 0X2);
    // ldv         $v30[0], 0x0($21)
    rsp.LDV<0>(rsp.vpu.r[30], r21, 0X0);
    // ldv         $v30[8], 0x8($21)
    rsp.LDV<8>(rsp.vpu.r[30], r21, 0X1);
L_1804:
    // vmudh       $v16, $v25, $v28[6]
    rsp.VMUDH<14>(rsp.vpu.r[16], rsp.vpu.r[25], rsp.vpu.r[28]);
    // addi        $21, $21, 0x10
    r21 = RSP_ADD32(r21, 0X10);
    // vmadh       $v16, $v24, $v28[7]
    rsp.VMADH<15>(rsp.vpu.r[16], rsp.vpu.r[24], rsp.vpu.r[28]);
    // addi        $19, $19, -0x10
    r19 = RSP_ADD32(r19, -0X10);
    // vmadh       $v16, $v23, $v30[0]
    rsp.VMADH<8>(rsp.vpu.r[16], rsp.vpu.r[23], rsp.vpu.r[30]);
    // vmadh       $v16, $v22, $v30[1]
    rsp.VMADH<9>(rsp.vpu.r[16], rsp.vpu.r[22], rsp.vpu.r[30]);
    // vmadh       $v16, $v21, $v30[2]
    rsp.VMADH<10>(rsp.vpu.r[16], rsp.vpu.r[21], rsp.vpu.r[30]);
    // vmadh       $v16, $v20, $v30[3]
    rsp.VMADH<11>(rsp.vpu.r[16], rsp.vpu.r[20], rsp.vpu.r[30]);
    // vmadh       $v28, $v19, $v30[4]
    rsp.VMADH<12>(rsp.vpu.r[28], rsp.vpu.r[19], rsp.vpu.r[30]);
    // vmadh       $v16, $v18, $v30[5]
    rsp.VMADH<13>(rsp.vpu.r[16], rsp.vpu.r[18], rsp.vpu.r[30]);
    // vmadh       $v16, $v17, $v30[6]
    rsp.VMADH<14>(rsp.vpu.r[16], rsp.vpu.r[17], rsp.vpu.r[30]);
    // vmadh       $v16, $v30, $v31[5]
    rsp.VMADH<13>(rsp.vpu.r[16], rsp.vpu.r[30], rsp.vpu.r[31]);
    // ldv         $v30[0], 0x0($21)
    rsp.LDV<0>(rsp.vpu.r[30], r21, 0X0);
    // vsar        $v26, $v15, $v28[1]
    rsp.VSAR<9>(rsp.vpu.r[26], rsp.vpu.r[15]);
    // ldv         $v30[8], 0x8($21)
    rsp.LDV<8>(rsp.vpu.r[30], r21, 0X1);
    // vsar        $v28, $v15, $v28[0]
    rsp.VSAR<8>(rsp.vpu.r[28], rsp.vpu.r[15]);
    // vmudn       $v16, $v26, $v14[0]
    rsp.VMUDN<8>(rsp.vpu.r[16], rsp.vpu.r[26], rsp.vpu.r[14]);
    // vmadh       $v28, $v28, $v14[0]
    rsp.VMADH<8>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[14]);
    // sdv         $v28[0], 0x0($20)
    rsp.SDV<0>(rsp.vpu.r[28], r20, 0X0);
    // sdv         $v28[8], 0x8($20)
    rsp.SDV<8>(rsp.vpu.r[28], r20, 0X1);
    // bgtz        $19, L_1804
    if (RSP_SIGNED(r19) > 0) {
        // addi        $20, $20, 0x10
        r20 = RSP_ADD32(r20, 0X10);
        goto L_1804;
    }
    // addi        $20, $20, 0x10
    r20 = RSP_ADD32(r20, 0X10);
    // addi        $1, $20, -0x8
    r1 = RSP_ADD32(r20, -0X8);
    // addi        $2, $18, 0x0
    r2 = RSP_ADD32(r18, 0X0);
    // jal         0x11C0
    r31 = 0x186C;
    // addi        $3, $zero, 0x7
    r3 = RSP_ADD32(0, 0X7);
    goto L_11C0;
    // addi        $3, $zero, 0x7
    r3 = RSP_ADD32(0, 0X7);
L_186C:
    // j           L_1118
    // nop

    goto L_1118;
    // nop

    // lh          $8, 0x0($24)
    r8 = RSP_MEM_H_LOAD(0X0, r24);
    // lh          $19, 0x2($24)
    r19 = RSP_MEM_H_LOAD(0X2, r24);
    // lh          $18, 0x4($24)
    r18 = RSP_MEM_H_LOAD(0X4, r24);
    // lui         $4, 0xFF
    r4 = S32(0XFF << 16);
    // ori         $4, $4, 0xFFFF
    r4 = r4 | 0XFFFF;
    // and         $2, $25, $4
    r2 = r25 & r4;
    // srl         $5, $25, 24
    r5 = S32(U32(r25) >> 24);
    // sll         $5, $5, 2
    r5 = S32(r5) << 2;
    // lw          $6, 0x320($5)
    r6 = RSP_MEM_W_LOAD(0X320, r5);
    // add         $2, $2, $6
    r2 = RSP_ADD32(r2, r6);
    // addi        $1, $23, 0x0
    r1 = RSP_ADD32(r23, 0X0);
    // sw          $2, 0x40($23)
    RSP_MEM_W_STORE(0X40, r23, r2);
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
    // srl         $7, $26, 16
    r7 = S32(U32(r26) >> 16);
    // andi        $10, $7, 0x1
    r10 = r7 & 0X1;
    // bgtz        $10, L_18D8
    if (RSP_SIGNED(r10) > 0) {
        // nop
    
        goto L_18D8;
    }
    // nop

    // jal         0x1194
    r31 = 0x18C0;
    // add         $10, $zero, $7
    r10 = RSP_ADD32(0, r7);
    goto L_1194;
    // add         $10, $zero, $7
    r10 = RSP_ADD32(0, r7);
L_18C0:
    // add         $7, $zero, $10
    r7 = RSP_ADD32(0, r10);
L_18C4:
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
    // bne         $1, $zero, L_18C4
    if (r1 != 0) {
        // nop
    
        goto L_18C4;
    }
    // nop

    // j           L_195C
    // add         $22, $zero, $zero
    r22 = RSP_ADD32(0, 0);
    goto L_195C;
    // add         $22, $zero, $zero
    r22 = RSP_ADD32(0, 0);
L_18D8:
    // beq         $22, $zero, L_18F0
    if (r22 == 0) {
        // nop
    
        goto L_18F0;
    }
    // nop

L_18E0:
    // mfc0        $10, SP_DMA_BUSY
    r10 = 0;
    // bne         $10, $zero, L_18E0
    if (r10 != 0) {
        // nop
    
        goto L_18E0;
    }
    // nop

    // and         $22, $zero, $zero
    r22 = 0 & 0;
L_18F0:
    // sh          $zero, 0x8($23)
    RSP_MEM_H_STORE(0X8, r23, 0);
    // vxor        $v16, $v16, $v16
    rsp.VXOR<0>(rsp.vpu.r[16], rsp.vpu.r[16], rsp.vpu.r[16]);
    // sdv         $v16[0], 0x0($23)
    rsp.SDV<0>(rsp.vpu.r[16], r23, 0X0);
    // andi        $10, $7, 0x2
    r10 = r7 & 0X2;
    // beq         $10, $zero, L_191C
    if (r10 == 0) {
        // nop
    
        goto L_191C;
    }
    // nop

    // lh          $11, 0xA($23)
    r11 = RSP_MEM_H_LOAD(0XA, r23);
    // lqv         $v3[0], 0x10($23)
    rsp.LQV<0>(rsp.vpu.r[3], r23, 0X1);
    // sdv         $v3[0], 0x3F0($8)
    rsp.SDV<0>(rsp.vpu.r[3], r8, -0X2);
    // sdv         $v3[8], 0x3F8($8)
    rsp.SDV<8>(rsp.vpu.r[3], r8, -0X1);
    // sub         $8, $8, $11
    r8 = RSP_SUB32(r8, r11);
L_191C:
    // addi        $8, $8, -0x8
    r8 = RSP_ADD32(r8, -0X8);
    // lsv         $v23[14], 0x8($23)
    rsp.LSV<14>(rsp.vpu.r[23], r23, 0X4);
    // ldv         $v16[0], 0x0($23)
    rsp.LDV<0>(rsp.vpu.r[16], r23, 0X0);
    // sdv         $v16[0], 0x0($8)
    rsp.SDV<0>(rsp.vpu.r[16], r8, 0X0);
    // mtc2        $8, $v18[4]
    rsp.MTC2<4>(r8, rsp.vpu.r[18]);
    // addi        $10, $zero, 0xD0
    r10 = RSP_ADD32(0, 0XD0);
    // mtc2        $10, $v18[6]
    rsp.MTC2<6>(r10, rsp.vpu.r[18]);
    // mtc2        $26, $v18[8]
    rsp.MTC2<8>(r26, rsp.vpu.r[18]);
    // addi        $10, $zero, 0x40
    r10 = RSP_ADD32(0, 0X40);
    // mtc2        $10, $v18[10]
    rsp.MTC2<10>(r10, rsp.vpu.r[18]);
    // addi        $9, $zero, 0x50
    r9 = RSP_ADD32(0, 0X50);
    // lqv         $v31[0], 0x10($9)
    rsp.LQV<0>(rsp.vpu.r[31], r9, 0X1);
    // lqv         $v25[0], 0x0($9)
    rsp.LQV<0>(rsp.vpu.r[25], r9, 0X0);
    // vsub        $v25, $v25, $v31
    rsp.VSUB<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[31]);
    // lqv         $v30[0], 0x20($9)
    rsp.LQV<0>(rsp.vpu.r[30], r9, 0X2);
    // lqv         $v29[0], 0x30($9)
    rsp.LQV<0>(rsp.vpu.r[29], r9, 0X3);
L_195C:
    // lqv         $v28[0], 0x40($9)
    rsp.LQV<0>(rsp.vpu.r[28], r9, 0X4);
    // lqv         $v27[0], 0x50($9)
    rsp.LQV<0>(rsp.vpu.r[27], r9, 0X5);
    // lqv         $v26[0], 0x60($9)
    rsp.LQV<0>(rsp.vpu.r[26], r9, 0X6);
    // vsub        $v25, $v25, $v31
    rsp.VSUB<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[31]);
    // lqv         $v24[0], 0x70($9)
    rsp.LQV<0>(rsp.vpu.r[24], r9, 0X7);
    // addi        $21, $23, 0x20
    r21 = RSP_ADD32(r23, 0X20);
    // addi        $20, $23, 0x30
    r20 = RSP_ADD32(r23, 0X30);
    // vxor        $v22, $v22, $v22
    rsp.VXOR<0>(rsp.vpu.r[22], rsp.vpu.r[22], rsp.vpu.r[22]);
    // vmudm       $v23, $v31, $v23[7]
    rsp.VMUDM<15>(rsp.vpu.r[23], rsp.vpu.r[31], rsp.vpu.r[23]);
    // vmadm       $v22, $v25, $v18[4]
    rsp.VMADM<12>(rsp.vpu.r[22], rsp.vpu.r[25], rsp.vpu.r[18]);
    // vmadn       $v23, $v31, $v30[0]
    rsp.VMADN<8>(rsp.vpu.r[23], rsp.vpu.r[31], rsp.vpu.r[30]);
    // vmudn       $v21, $v31, $v18[2]
    rsp.VMUDN<10>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[18]);
    // vmadn       $v21, $v22, $v30[2]
    rsp.VMADN<10>(rsp.vpu.r[21], rsp.vpu.r[22], rsp.vpu.r[30]);
    // vmudl       $v17, $v23, $v18[5]
    rsp.VMUDL<13>(rsp.vpu.r[17], rsp.vpu.r[23], rsp.vpu.r[18]);
    // vmudn       $v17, $v17, $v30[4]
    rsp.VMUDN<12>(rsp.vpu.r[17], rsp.vpu.r[17], rsp.vpu.r[30]);
    // vmadn       $v17, $v31, $v18[3]
    rsp.VMADN<11>(rsp.vpu.r[17], rsp.vpu.r[31], rsp.vpu.r[18]);
    // lqv         $v25[0], 0x0($9)
    rsp.LQV<0>(rsp.vpu.r[25], r9, 0X0);
    // sqv         $v21[0], 0x0($21)
    rsp.SQV<0>(rsp.vpu.r[21], r21, 0X0);
    // sqv         $v17[0], 0x0($20)
    rsp.SQV<0>(rsp.vpu.r[17], r20, 0X0);
    // ssv         $v23[7], 0x8($23)
    rsp.SSV<7>(rsp.vpu.r[23], r23, 0X4);
    // lh          $17, 0x0($21)
    r17 = RSP_MEM_H_LOAD(0X0, r21);
    // lh          $9, 0x0($20)
    r9 = RSP_MEM_H_LOAD(0X0, r20);
    // lh          $13, 0x8($21)
    r13 = RSP_MEM_H_LOAD(0X8, r21);
    // lh          $5, 0x8($20)
    r5 = RSP_MEM_H_LOAD(0X8, r20);
    // lh          $16, 0x2($21)
    r16 = RSP_MEM_H_LOAD(0X2, r21);
    // lh          $8, 0x2($20)
    r8 = RSP_MEM_H_LOAD(0X2, r20);
    // lh          $12, 0xA($21)
    r12 = RSP_MEM_H_LOAD(0XA, r21);
    // lh          $4, 0xA($20)
    r4 = RSP_MEM_H_LOAD(0XA, r20);
    // lh          $15, 0x4($21)
    r15 = RSP_MEM_H_LOAD(0X4, r21);
    // lh          $7, 0x4($20)
    r7 = RSP_MEM_H_LOAD(0X4, r20);
    // lh          $11, 0xC($21)
    r11 = RSP_MEM_H_LOAD(0XC, r21);
    // lh          $3, 0xC($20)
    r3 = RSP_MEM_H_LOAD(0XC, r20);
    // lh          $14, 0x6($21)
    r14 = RSP_MEM_H_LOAD(0X6, r21);
    // lh          $6, 0x6($20)
    r6 = RSP_MEM_H_LOAD(0X6, r20);
    // lh          $10, 0xE($21)
    r10 = RSP_MEM_H_LOAD(0XE, r21);
    // lh          $2, 0xE($20)
    r2 = RSP_MEM_H_LOAD(0XE, r20);
    // ldv         $v16[0], 0x0($17)
    rsp.LDV<0>(rsp.vpu.r[16], r17, 0X0);
    // vmudm       $v23, $v31, $v23[7]
    rsp.VMUDM<15>(rsp.vpu.r[23], rsp.vpu.r[31], rsp.vpu.r[23]);
    // ldv         $v15[0], 0x0($9)
    rsp.LDV<0>(rsp.vpu.r[15], r9, 0X0);
    // vmadh       $v23, $v31, $v22[7]
    rsp.VMADH<15>(rsp.vpu.r[23], rsp.vpu.r[31], rsp.vpu.r[22]);
    // ldv         $v16[8], 0x0($13)
    rsp.LDV<8>(rsp.vpu.r[16], r13, 0X0);
    // vmadm       $v22, $v25, $v18[4]
    rsp.VMADM<12>(rsp.vpu.r[22], rsp.vpu.r[25], rsp.vpu.r[18]);
    // ldv         $v15[8], 0x0($5)
    rsp.LDV<8>(rsp.vpu.r[15], r5, 0X0);
    // vmadn       $v23, $v31, $v30[0]
    rsp.VMADN<8>(rsp.vpu.r[23], rsp.vpu.r[31], rsp.vpu.r[30]);
    // ldv         $v14[0], 0x0($16)
    rsp.LDV<0>(rsp.vpu.r[14], r16, 0X0);
    // vmudn       $v21, $v31, $v18[2]
    rsp.VMUDN<10>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[18]);
    // ldv         $v13[0], 0x0($8)
    rsp.LDV<0>(rsp.vpu.r[13], r8, 0X0);
    // vmadn       $v21, $v22, $v30[2]
    rsp.VMADN<10>(rsp.vpu.r[21], rsp.vpu.r[22], rsp.vpu.r[30]);
    // ldv         $v14[8], 0x0($12)
    rsp.LDV<8>(rsp.vpu.r[14], r12, 0X0);
    // vmudl       $v17, $v23, $v18[5]
    rsp.VMUDL<13>(rsp.vpu.r[17], rsp.vpu.r[23], rsp.vpu.r[18]);
    // ldv         $v13[8], 0x0($4)
    rsp.LDV<8>(rsp.vpu.r[13], r4, 0X0);
    // ldv         $v12[0], 0x0($15)
    rsp.LDV<0>(rsp.vpu.r[12], r15, 0X0);
    // ldv         $v11[0], 0x0($7)
    rsp.LDV<0>(rsp.vpu.r[11], r7, 0X0);
    // ldv         $v12[8], 0x0($11)
    rsp.LDV<8>(rsp.vpu.r[12], r11, 0X0);
    // vmudn       $v17, $v17, $v30[4]
    rsp.VMUDN<12>(rsp.vpu.r[17], rsp.vpu.r[17], rsp.vpu.r[30]);
    // ldv         $v11[8], 0x0($3)
    rsp.LDV<8>(rsp.vpu.r[11], r3, 0X0);
    // ldv         $v10[0], 0x0($14)
    rsp.LDV<0>(rsp.vpu.r[10], r14, 0X0);
    // ldv         $v9[0], 0x0($6)
    rsp.LDV<0>(rsp.vpu.r[9], r6, 0X0);
    // vmadn       $v17, $v31, $v18[3]
    rsp.VMADN<11>(rsp.vpu.r[17], rsp.vpu.r[31], rsp.vpu.r[18]);
    // ldv         $v10[8], 0x0($10)
    rsp.LDV<8>(rsp.vpu.r[10], r10, 0X0);
L_1A4C:
    // vmulf       $v8, $v16, $v15
    rsp.VMULF<0>(rsp.vpu.r[8], rsp.vpu.r[16], rsp.vpu.r[15]);
    // ldv         $v9[8], 0x0($2)
    rsp.LDV<8>(rsp.vpu.r[9], r2, 0X0);
    // vmulf       $v7, $v14, $v13
    rsp.VMULF<0>(rsp.vpu.r[7], rsp.vpu.r[14], rsp.vpu.r[13]);
    // sqv         $v21[0], 0x0($21)
    rsp.SQV<0>(rsp.vpu.r[21], r21, 0X0);
    // vmulf       $v6, $v12, $v11
    rsp.VMULF<0>(rsp.vpu.r[6], rsp.vpu.r[12], rsp.vpu.r[11]);
    // sqv         $v17[0], 0x0($20)
    rsp.SQV<0>(rsp.vpu.r[17], r20, 0X0);
    // lh          $17, 0x0($21)
    r17 = RSP_MEM_H_LOAD(0X0, r21);
    // vmulf       $v5, $v10, $v9
    rsp.VMULF<0>(rsp.vpu.r[5], rsp.vpu.r[10], rsp.vpu.r[9]);
    // lh          $9, 0x0($20)
    r9 = RSP_MEM_H_LOAD(0X0, r20);
    // vadd        $v8, $v8, $v8[1q]
    rsp.VADD<3>(rsp.vpu.r[8], rsp.vpu.r[8], rsp.vpu.r[8]);
    // lh          $13, 0x8($21)
    r13 = RSP_MEM_H_LOAD(0X8, r21);
    // vadd        $v7, $v7, $v7[1q]
    rsp.VADD<3>(rsp.vpu.r[7], rsp.vpu.r[7], rsp.vpu.r[7]);
    // lh          $5, 0x8($20)
    r5 = RSP_MEM_H_LOAD(0X8, r20);
    // vadd        $v6, $v6, $v6[1q]
    rsp.VADD<3>(rsp.vpu.r[6], rsp.vpu.r[6], rsp.vpu.r[6]);
    // lh          $16, 0x2($21)
    r16 = RSP_MEM_H_LOAD(0X2, r21);
    // vadd        $v5, $v5, $v5[1q]
    rsp.VADD<3>(rsp.vpu.r[5], rsp.vpu.r[5], rsp.vpu.r[5]);
    // lh          $8, 0x2($20)
    r8 = RSP_MEM_H_LOAD(0X2, r20);
    // vadd        $v8, $v8, $v8[2h]
    rsp.VADD<6>(rsp.vpu.r[8], rsp.vpu.r[8], rsp.vpu.r[8]);
    // lh          $12, 0xA($21)
    r12 = RSP_MEM_H_LOAD(0XA, r21);
    // vadd        $v7, $v7, $v7[2h]
    rsp.VADD<6>(rsp.vpu.r[7], rsp.vpu.r[7], rsp.vpu.r[7]);
    // lh          $4, 0xA($20)
    r4 = RSP_MEM_H_LOAD(0XA, r20);
    // vadd        $v6, $v6, $v6[2h]
    rsp.VADD<6>(rsp.vpu.r[6], rsp.vpu.r[6], rsp.vpu.r[6]);
    // lh          $15, 0x4($21)
    r15 = RSP_MEM_H_LOAD(0X4, r21);
    // vadd        $v5, $v5, $v5[2h]
    rsp.VADD<6>(rsp.vpu.r[5], rsp.vpu.r[5], rsp.vpu.r[5]);
    // lh          $7, 0x4($20)
    r7 = RSP_MEM_H_LOAD(0X4, r20);
    // vmudn       $v4, $v29, $v8[0h]
    rsp.VMUDN<4>(rsp.vpu.r[4], rsp.vpu.r[29], rsp.vpu.r[8]);
    // lh          $11, 0xC($21)
    r11 = RSP_MEM_H_LOAD(0XC, r21);
    // vmadn       $v4, $v28, $v7[0h]
    rsp.VMADN<4>(rsp.vpu.r[4], rsp.vpu.r[28], rsp.vpu.r[7]);
    // lh          $3, 0xC($20)
    r3 = RSP_MEM_H_LOAD(0XC, r20);
    // vmadn       $v4, $v27, $v6[0h]
    rsp.VMADN<4>(rsp.vpu.r[4], rsp.vpu.r[27], rsp.vpu.r[6]);
    // lh          $14, 0x6($21)
    r14 = RSP_MEM_H_LOAD(0X6, r21);
    // vmadn       $v4, $v26, $v5[0h]
    rsp.VMADN<4>(rsp.vpu.r[4], rsp.vpu.r[26], rsp.vpu.r[5]);
    // lh          $6, 0x6($20)
    r6 = RSP_MEM_H_LOAD(0X6, r20);
    // lh          $10, 0xE($21)
    r10 = RSP_MEM_H_LOAD(0XE, r21);
    // addi        $18, $18, -0x10
    r18 = RSP_ADD32(r18, -0X10);
    // sqv         $v4[0], 0x0($19)
    rsp.SQV<0>(rsp.vpu.r[4], r19, 0X0);
    // blez        $18, L_1AEC
    if (RSP_SIGNED(r18) <= 0) {
        // lh          $2, 0xE($20)
        r2 = RSP_MEM_H_LOAD(0XE, r20);
        goto L_1AEC;
    }
    // lh          $2, 0xE($20)
    r2 = RSP_MEM_H_LOAD(0XE, r20);
    // j           L_1A4C
    // addi        $19, $19, 0x10
    r19 = RSP_ADD32(r19, 0X10);
    goto L_1A4C;
    // addi        $19, $19, 0x10
    r19 = RSP_ADD32(r19, 0X10);
L_1AEC:
    // ssv         $v23[0], 0x8($23)
    rsp.SSV<0>(rsp.vpu.r[23], r23, 0X4);
    // ldv         $v16[0], 0x0($17)
    rsp.LDV<0>(rsp.vpu.r[16], r17, 0X0);
    // sdv         $v16[0], 0x0($23)
    rsp.SDV<0>(rsp.vpu.r[16], r23, 0X0);
    // lh          $6, 0x0($24)
    r6 = RSP_MEM_H_LOAD(0X0, r24);
    // addi        $17, $17, 0x8
    r17 = RSP_ADD32(r17, 0X8);
    // sub         $5, $17, $6
    r5 = RSP_SUB32(r17, r6);
    // andi        $4, $5, 0xF
    r4 = r5 & 0XF;
    // sub         $17, $17, $4
    r17 = RSP_SUB32(r17, r4);
    // beq         $4, $zero, L_1B18
    if (r4 == 0) {
        // addi        $7, $zero, 0x10
        r7 = RSP_ADD32(0, 0X10);
        goto L_1B18;
    }
    // addi        $7, $zero, 0x10
    r7 = RSP_ADD32(0, 0X10);
    // sub         $4, $7, $4
    r4 = RSP_SUB32(r7, r4);
L_1B18:
    // sh          $4, 0xA($23)
    RSP_MEM_H_STORE(0XA, r23, r4);
    // ldv         $v3[0], 0x0($17)
    rsp.LDV<0>(rsp.vpu.r[3], r17, 0X0);
    // ldv         $v3[8], 0x8($17)
    rsp.LDV<8>(rsp.vpu.r[3], r17, 0X1);
    // sqv         $v3[0], 0x10($23)
    rsp.SQV<0>(rsp.vpu.r[3], r23, 0X1);
    // lw          $2, 0x40($23)
    r2 = RSP_MEM_W_LOAD(0X40, r23);
    // addi        $1, $23, 0x0
    r1 = RSP_ADD32(r23, 0X0);
    // jal         0x11C0
    r31 = 0x1B38;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
    goto L_11C0;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
L_1B38:
    // j           L_1118
    // nop

    goto L_1118;
    // nop

    // lui         $4, 0xFF
    r4 = S32(0XFF << 16);
    // ori         $4, $4, 0xFFFF
    r4 = r4 | 0XFFFF;
    // and         $2, $25, $4
    r2 = r25 & r4;
    // srl         $5, $25, 24
    r5 = S32(U32(r25) >> 24);
    // sll         $5, $5, 2
    r5 = S32(r5) << 2;
    // lw          $6, 0x320($5)
    r6 = RSP_MEM_W_LOAD(0X320, r5);
    // add         $2, $2, $6
    r2 = RSP_ADD32(r2, r6);
    // addi        $1, $23, 0x0
    r1 = RSP_ADD32(r23, 0X0);
    // addi        $3, $zero, 0x4F
    r3 = RSP_ADD32(0, 0X4F);
    // vxor        $v0, $v0, $v0
    rsp.VXOR<0>(rsp.vpu.r[0], rsp.vpu.r[0], rsp.vpu.r[0]);
    // addi        $11, $zero, 0x50
    r11 = RSP_ADD32(0, 0X50);
    // lqv         $v31[0], 0x10($11)
    rsp.LQV<0>(rsp.vpu.r[31], r11, 0X1);
    // lqv         $v10[0], 0x0($zero)
    rsp.LQV<0>(rsp.vpu.r[10], 0, 0X0);
    // srl         $12, $26, 16
    r12 = S32(U32(r26) >> 16);
    // andi        $10, $12, 0x1
    r10 = r12 & 0X1;
    // beq         $10, $zero, L_1B8C
    if (r10 == 0) {
        // lqv         $v24[0], 0x10($24)
        rsp.LQV<0>(rsp.vpu.r[24], r24, 0X1);
        goto L_1B8C;
    }
    // lqv         $v24[0], 0x10($24)
    rsp.LQV<0>(rsp.vpu.r[24], r24, 0X1);
    // j           L_1C18
    // nop

    goto L_1C18;
    // nop

L_1B8C:
    // jal         0x1194
    r31 = 0x1B94;
    // nop

    goto L_1194;
    // nop

L_1B94:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
    // bne         $5, $zero, L_1B94
    if (r5 != 0) {
        // nop
    
        goto L_1B94;
    }
    // nop

    // add         $22, $zero, $zero
    r22 = RSP_ADD32(0, 0);
    // lqv         $v20[0], 0x0($23)
    rsp.LQV<0>(rsp.vpu.r[20], r23, 0X0);
    // lqv         $v21[0], 0x10($23)
    rsp.LQV<0>(rsp.vpu.r[21], r23, 0X1);
    // lqv         $v18[0], 0x20($23)
    rsp.LQV<0>(rsp.vpu.r[18], r23, 0X2);
    // lqv         $v19[0], 0x30($23)
    rsp.LQV<0>(rsp.vpu.r[19], r23, 0X3);
    // lqv         $v24[0], 0x40($23)
    rsp.LQV<0>(rsp.vpu.r[24], r23, 0X4);
    // bne         $zero, $zero, L_1BD0
    if (0 != 0) {
        // nop
    
        goto L_1BD0;
    }
    // nop

L_1BC0:
    // mfc0        $9, SP_DMA_BUSY
    r9 = 0;
    // bne         $9, $zero, L_1BC0
    if (r9 != 0) {
        // nop
    
        goto L_1BC0;
    }
    // nop

    // and         $22, $zero, $zero
    r22 = 0 & 0;
L_1BD0:
    // lh          $13, 0x0($24)
    r13 = RSP_MEM_H_LOAD(0X0, r24);
    // lh          $19, 0x2($24)
    r19 = RSP_MEM_H_LOAD(0X2, r24);
    // lh          $18, 0xA($24)
    r18 = RSP_MEM_H_LOAD(0XA, r24);
    // lh          $17, 0xC($24)
    r17 = RSP_MEM_H_LOAD(0XC, r24);
    // lh          $16, 0xE($24)
    r16 = RSP_MEM_H_LOAD(0XE, r24);
    // lh          $14, 0x4($24)
    r14 = RSP_MEM_H_LOAD(0X4, r24);
    // addi        $15, $zero, 0x10
    r15 = RSP_ADD32(0, 0X10);
    // mfc2        $21, $v24[2]
    rsp.MFC2<2>(r21, rsp.vpu.r[24]);
    // mfc2        $20, $v24[8]
    rsp.MFC2<8>(r20, rsp.vpu.r[24]);
    // andi        $9, $12, 0x8
    r9 = r12 & 0X8;
    // bgtz        $9, L_1C0C
    if (RSP_SIGNED(r9) > 0) {
        // nop
    
        goto L_1C0C;
    }
    // nop

    // addi        $17, $23, 0x50
    r17 = RSP_ADD32(r23, 0X50);
    // add         $16, $zero, $17
    r16 = RSP_ADD32(0, r17);
    // addi        $15, $zero, 0x0
    r15 = RSP_ADD32(0, 0X0);
L_1C0C:
    // beq         $10, $zero, L_1CE8
    if (r10 == 0) {
        // lqv         $v30[0], 0x70($11)
        rsp.LQV<0>(rsp.vpu.r[30], r11, 0X7);
        goto L_1CE8;
    }
    // lqv         $v30[0], 0x70($11)
    rsp.LQV<0>(rsp.vpu.r[30], r11, 0X7);
    // lqv         $v17[0], 0x0($13)
    rsp.LQV<0>(rsp.vpu.r[17], r13, 0X0);
L_1C18:
    // lqv         $v29[0], 0x0($19)
    rsp.LQV<0>(rsp.vpu.r[29], r19, 0X0);
    // lqv         $v27[0], 0x0($17)
    rsp.LQV<0>(rsp.vpu.r[27], r17, 0X0);
    // vxor        $v21, $v21, $v21
    rsp.VXOR<0>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[21]);
    // lsv         $v20[14], 0x6($24)
    rsp.LSV<14>(rsp.vpu.r[20], r24, 0X3);
    // vmudl       $v23, $v30, $v24[2]
    rsp.VMUDL<10>(rsp.vpu.r[23], rsp.vpu.r[30], rsp.vpu.r[24]);
    // vmadn       $v23, $v30, $v24[1]
    rsp.VMADN<9>(rsp.vpu.r[23], rsp.vpu.r[30], rsp.vpu.r[24]);
    // vmadm       $v22, $v31, $v0[0]
    rsp.VMADM<8>(rsp.vpu.r[22], rsp.vpu.r[31], rsp.vpu.r[0]);
    // vmadm       $v21, $v31, $v21[7]
    rsp.VMADM<15>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[21]);
    // vmadh       $v20, $v31, $v20[7]
    rsp.VMADH<15>(rsp.vpu.r[20], rsp.vpu.r[31], rsp.vpu.r[20]);
    // bgtz        $21, L_1C50
    if (RSP_SIGNED(r21) > 0) {
        // vmadn       $v21, $v31, $v0[0]
        rsp.VMADN<8>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[0]);
        goto L_1C50;
    }
    // vmadn       $v21, $v31, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[0]);
    // vge         $v20, $v20, $v24[0]
    rsp.VGE<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    // j           L_1CB4
    // nop

    goto L_1CB4;
    // nop

L_1C50:
    // vcl         $v20, $v20, $v24[0]
    rsp.VCL<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    // vmulf       $v16, $v20, $v24[6]
    rsp.VMULF<14>(rsp.vpu.r[16], rsp.vpu.r[20], rsp.vpu.r[24]);
    // vmulf       $v15, $v20, $v24[7]
    rsp.VMULF<15>(rsp.vpu.r[15], rsp.vpu.r[20], rsp.vpu.r[24]);
    // vmulf       $v29, $v29, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[29], rsp.vpu.r[29], rsp.vpu.r[10]);
    // vmacf       $v29, $v17, $v16
    rsp.VMACF<0>(rsp.vpu.r[29], rsp.vpu.r[17], rsp.vpu.r[16]);
    // vmulf       $v27, $v27, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[10]);
    // vmacf       $v27, $v17, $v15
    rsp.VMACF<0>(rsp.vpu.r[27], rsp.vpu.r[17], rsp.vpu.r[15]);
    // sqv         $v29[0], 0x0($19)
    rsp.SQV<0>(rsp.vpu.r[29], r19, 0X0);
    // sqv         $v27[0], 0x0($17)
    rsp.SQV<0>(rsp.vpu.r[27], r17, 0X0);
    // lqv         $v28[0], 0x0($18)
    rsp.LQV<0>(rsp.vpu.r[28], r18, 0X0);
    // lqv         $v26[0], 0x0($16)
    rsp.LQV<0>(rsp.vpu.r[26], r16, 0X0);
    // vxor        $v19, $v19, $v19
    rsp.VXOR<0>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[19]);
    // lsv         $v18[14], 0x8($24)
    rsp.LSV<14>(rsp.vpu.r[18], r24, 0X4);
    // vmudl       $v23, $v30, $v24[5]
    rsp.VMUDL<13>(rsp.vpu.r[23], rsp.vpu.r[30], rsp.vpu.r[24]);
    // vmadn       $v23, $v30, $v24[4]
    rsp.VMADN<12>(rsp.vpu.r[23], rsp.vpu.r[30], rsp.vpu.r[24]);
    // vmadm       $v22, $v31, $v0[0]
    rsp.VMADM<8>(rsp.vpu.r[22], rsp.vpu.r[31], rsp.vpu.r[0]);
    // vmadm       $v19, $v31, $v19[7]
    rsp.VMADM<15>(rsp.vpu.r[19], rsp.vpu.r[31], rsp.vpu.r[19]);
    // vmadh       $v18, $v31, $v18[7]
    rsp.VMADH<15>(rsp.vpu.r[18], rsp.vpu.r[31], rsp.vpu.r[18]);
    // bgtz        $20, L_1CAC
    if (RSP_SIGNED(r20) > 0) {
        // vmadn       $v19, $v31, $v0[0]
        rsp.VMADN<8>(rsp.vpu.r[19], rsp.vpu.r[31], rsp.vpu.r[0]);
        goto L_1CAC;
    }
    // vmadn       $v19, $v31, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[19], rsp.vpu.r[31], rsp.vpu.r[0]);
    // vge         $v18, $v18, $v24[3]
    rsp.VGE<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
    // j           L_1D10
    // nop

    goto L_1D10;
    // nop

L_1CAC:
    // vcl         $v18, $v18, $v24[3]
    rsp.VCL<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
    // vmulf       $v16, $v18, $v24[6]
    rsp.VMULF<14>(rsp.vpu.r[16], rsp.vpu.r[18], rsp.vpu.r[24]);
L_1CB4:
    // vmulf       $v15, $v18, $v24[7]
    rsp.VMULF<15>(rsp.vpu.r[15], rsp.vpu.r[18], rsp.vpu.r[24]);
    // vmulf       $v28, $v28, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[10]);
    // vmacf       $v28, $v17, $v16
    rsp.VMACF<0>(rsp.vpu.r[28], rsp.vpu.r[17], rsp.vpu.r[16]);
    // vmulf       $v26, $v26, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[26], rsp.vpu.r[26], rsp.vpu.r[10]);
    // vmacf       $v26, $v17, $v15
    rsp.VMACF<0>(rsp.vpu.r[26], rsp.vpu.r[17], rsp.vpu.r[15]);
    // sqv         $v28[0], 0x0($18)
    rsp.SQV<0>(rsp.vpu.r[28], r18, 0X0);
    // sqv         $v26[0], 0x0($16)
    rsp.SQV<0>(rsp.vpu.r[26], r16, 0X0);
    // addi        $14, $14, -0x10
    r14 = RSP_ADD32(r14, -0X10);
    // addi        $13, $13, 0x10
    r13 = RSP_ADD32(r13, 0X10);
    // addi        $19, $19, 0x10
    r19 = RSP_ADD32(r19, 0X10);
    // addi        $18, $18, 0x10
    r18 = RSP_ADD32(r18, 0X10);
    // add         $17, $17, $15
    r17 = RSP_ADD32(r17, r15);
    // add         $16, $16, $15
    r16 = RSP_ADD32(r16, r15);
L_1CE8:
    // vaddc       $v21, $v21, $v24[2]
    rsp.VADDC<10>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[24]);
    // vadd        $v20, $v20, $v24[1]
    rsp.VADD<9>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    // bgtz        $21, L_1D14
    if (RSP_SIGNED(r21) > 0) {
        // lqv         $v17[0], 0x0($13)
        rsp.LQV<0>(rsp.vpu.r[17], r13, 0X0);
        goto L_1D14;
    }
    // lqv         $v17[0], 0x0($13)
    rsp.LQV<0>(rsp.vpu.r[17], r13, 0X0);
    // vge         $v20, $v20, $v24[0]
    rsp.VGE<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    // vaddc       $v19, $v19, $v24[5]
    rsp.VADDC<13>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[24]);
    // lqv         $v29[0], 0x0($19)
    rsp.LQV<0>(rsp.vpu.r[29], r19, 0X0);
    // vadd        $v18, $v18, $v24[4]
    rsp.VADD<12>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
    // lqv         $v27[0], 0x0($17)
    rsp.LQV<0>(rsp.vpu.r[27], r17, 0X0);
    // j           L_1D88
    // nop

    goto L_1D88;
L_1D10:
    // nop

L_1D14:
    // vcl         $v20, $v20, $v24[0]
    rsp.VCL<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    // vaddc       $v19, $v19, $v24[5]
    rsp.VADDC<13>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[24]);
    // lqv         $v29[0], 0x0($19)
    rsp.LQV<0>(rsp.vpu.r[29], r19, 0X0);
    // vadd        $v18, $v18, $v24[4]
    rsp.VADD<12>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
    // lqv         $v27[0], 0x0($17)
    rsp.LQV<0>(rsp.vpu.r[27], r17, 0X0);
    // vmulf       $v16, $v20, $v24[6]
    rsp.VMULF<14>(rsp.vpu.r[16], rsp.vpu.r[20], rsp.vpu.r[24]);
    // sqv         $v20[0], 0x0($23)
    rsp.SQV<0>(rsp.vpu.r[20], r23, 0X0);
    // vmulf       $v15, $v20, $v24[7]
    rsp.VMULF<15>(rsp.vpu.r[15], rsp.vpu.r[20], rsp.vpu.r[24]);
    // sqv         $v21[0], 0x10($23)
    rsp.SQV<0>(rsp.vpu.r[21], r23, 0X1);
    // vmulf       $v29, $v29, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[29], rsp.vpu.r[29], rsp.vpu.r[10]);
    // vmacf       $v29, $v17, $v16
    rsp.VMACF<0>(rsp.vpu.r[29], rsp.vpu.r[17], rsp.vpu.r[16]);
    // lqv         $v28[0], 0x0($18)
    rsp.LQV<0>(rsp.vpu.r[28], r18, 0X0);
    // vmulf       $v27, $v27, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[10]);
    // lqv         $v26[0], 0x0($16)
    rsp.LQV<0>(rsp.vpu.r[26], r16, 0X0);
    // vmacf       $v27, $v17, $v15
    rsp.VMACF<0>(rsp.vpu.r[27], rsp.vpu.r[17], rsp.vpu.r[15]);
L_1D50:
    // bgtz        $20, L_1D70
    if (RSP_SIGNED(r20) > 0) {
        // sqv         $v29[0], 0x0($19)
        rsp.SQV<0>(rsp.vpu.r[29], r19, 0X0);
        goto L_1D70;
    }
    // sqv         $v29[0], 0x0($19)
    rsp.SQV<0>(rsp.vpu.r[29], r19, 0X0);
    // vge         $v18, $v18, $v24[3]
    rsp.VGE<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
    // vaddc       $v21, $v21, $v24[2]
    rsp.VADDC<10>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[24]);
    // sqv         $v27[0], 0x0($17)
    rsp.SQV<0>(rsp.vpu.r[27], r17, 0X0);
    // vadd        $v20, $v20, $v24[1]
    rsp.VADD<9>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    // j           L_1DE0
    // nop

    goto L_1DE0;
    // nop

L_1D70:
    // vcl         $v18, $v18, $v24[3]
    rsp.VCL<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
    // vaddc       $v21, $v21, $v24[2]
    rsp.VADDC<10>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[24]);
    // sqv         $v27[0], 0x0($17)
    rsp.SQV<0>(rsp.vpu.r[27], r17, 0X0);
    // vadd        $v20, $v20, $v24[1]
    rsp.VADD<9>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
    // vmulf       $v16, $v18, $v24[6]
    rsp.VMULF<14>(rsp.vpu.r[16], rsp.vpu.r[18], rsp.vpu.r[24]);
    // addi        $14, $14, -0x10
    r14 = RSP_ADD32(r14, -0X10);
L_1D88:
    // vmulf       $v15, $v18, $v24[7]
    rsp.VMULF<15>(rsp.vpu.r[15], rsp.vpu.r[18], rsp.vpu.r[24]);
    // addi        $19, $19, 0x10
    r19 = RSP_ADD32(r19, 0X10);
    // vmulf       $v28, $v28, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[10]);
    // add         $17, $17, $15
    r17 = RSP_ADD32(r17, r15);
    // vmacf       $v28, $v17, $v16
    rsp.VMACF<0>(rsp.vpu.r[28], rsp.vpu.r[17], rsp.vpu.r[16]);
    // addi        $13, $13, 0x10
    r13 = RSP_ADD32(r13, 0X10);
    // vmulf       $v26, $v26, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[26], rsp.vpu.r[26], rsp.vpu.r[10]);
    // vmacf       $v26, $v17, $v15
    rsp.VMACF<0>(rsp.vpu.r[26], rsp.vpu.r[17], rsp.vpu.r[15]);
    // sqv         $v28[0], 0x0($18)
    rsp.SQV<0>(rsp.vpu.r[28], r18, 0X0);
    // addi        $18, $18, 0x10
    r18 = RSP_ADD32(r18, 0X10);
    // blez        $14, L_1DC0
    if (RSP_SIGNED(r14) <= 0) {
        // sqv         $v26[0], 0x0($16)
        rsp.SQV<0>(rsp.vpu.r[26], r16, 0X0);
        goto L_1DC0;
    }
    // sqv         $v26[0], 0x0($16)
    rsp.SQV<0>(rsp.vpu.r[26], r16, 0X0);
    // j           L_1D50
    // add         $16, $16, $15
    r16 = RSP_ADD32(r16, r15);
    goto L_1D50;
    // add         $16, $16, $15
    r16 = RSP_ADD32(r16, r15);
L_1DC0:
    // sqv         $v18[0], 0x20($23)
    rsp.SQV<0>(rsp.vpu.r[18], r23, 0X2);
    // sqv         $v19[0], 0x30($23)
    rsp.SQV<0>(rsp.vpu.r[19], r23, 0X3);
    // sqv         $v24[0], 0x40($23)
    rsp.SQV<0>(rsp.vpu.r[24], r23, 0X4);
    // jal         0x11C0
    r31 = 0x1DD4;
    // addi        $3, $zero, 0x4F
    r3 = RSP_ADD32(0, 0X4F);
    goto L_11C0;
    // addi        $3, $zero, 0x4F
    r3 = RSP_ADD32(0, 0X4F);
L_1DD4:
    // j           L_1118
    // nop

    goto L_1118;
    // nop

    // lqv         $v31[0], 0x0($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X0);
L_1DE0:
    // lhu         $18, 0x4($24)
    r18 = RSP_MEM_HU_LOAD(0X4, r24);
    // beq         $18, $zero, L_1ED4
    if (r18 == 0) {
        // nop
    
        goto L_1ED4;
    }
    // nop

    // andi        $2, $25, 0xFFFF
    r2 = r25 & 0XFFFF;
    // addi        $2, $2, 0x5C0
    r2 = RSP_ADD32(r2, 0X5C0);
    // srl         $1, $25, 16
    r1 = S32(U32(r25) >> 16);
    // addi        $1, $1, 0x5C0
    r1 = RSP_ADD32(r1, 0X5C0);
    // andi        $17, $26, 0xFFFF
    r17 = r26 & 0XFFFF;
    // mtc2        $17, $v30[0]
    rsp.MTC2<0>(r17, rsp.vpu.r[30]);
    // beq         $22, $zero, L_1E1C
    if (r22 == 0) {
        // nop
    
        goto L_1E1C;
    }
    // nop

L_1E0C:
    // mfc0        $3, SP_DMA_BUSY
    r3 = 0;
    // bne         $3, $zero, L_1E0C
    if (r3 != 0) {
        // nop
    
        goto L_1E0C;
    }
    // nop

    // add         $22, $zero, $zero
    r22 = RSP_ADD32(0, 0);
L_1E1C:
    // lqv         $v25[0], 0x0($2)
    rsp.LQV<0>(rsp.vpu.r[25], r2, 0X0);
    // lqv         $v29[0], 0x0($1)
    rsp.LQV<0>(rsp.vpu.r[29], r1, 0X0);
    // lqv         $v24[0], 0x10($2)
    rsp.LQV<0>(rsp.vpu.r[24], r2, 0X1);
    // lqv         $v28[0], 0x10($1)
    rsp.LQV<0>(rsp.vpu.r[28], r1, 0X1);
    // vmulf       $v25, $v25, $v31[6]
    rsp.VMULF<14>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[31]);
    // lqv         $v27[0], 0x20($1)
    rsp.LQV<0>(rsp.vpu.r[27], r1, 0X2);
    // lqv         $v23[0], 0x20($2)
    rsp.LQV<0>(rsp.vpu.r[23], r2, 0X2);
    // vmacf       $v25, $v29, $v30[0]
    rsp.VMACF<8>(rsp.vpu.r[25], rsp.vpu.r[29], rsp.vpu.r[30]);
    // addi        $18, $18, -0x20
    r18 = RSP_ADD32(r18, -0X20);
    // vmulf       $v24, $v24, $v31[6]
    rsp.VMULF<14>(rsp.vpu.r[24], rsp.vpu.r[24], rsp.vpu.r[31]);
    // lqv         $v26[0], 0x30($1)
    rsp.LQV<0>(rsp.vpu.r[26], r1, 0X3);
    // lqv         $v22[0], 0x30($2)
    rsp.LQV<0>(rsp.vpu.r[22], r2, 0X3);
    // addi        $1, $1, 0x40
    r1 = RSP_ADD32(r1, 0X40);
    // addi        $2, $2, 0x40
    r2 = RSP_ADD32(r2, 0X40);
    // vmacf       $v24, $v28, $v30[0]
    rsp.VMACF<8>(rsp.vpu.r[24], rsp.vpu.r[28], rsp.vpu.r[30]);
    // blez        $18, L_1ECC
    if (RSP_SIGNED(r18) <= 0) {
        // nop
    
        goto L_1ECC;
    }
    // nop

L_1E60:
    // vmulf       $v23, $v23, $v31[6]
    rsp.VMULF<14>(rsp.vpu.r[23], rsp.vpu.r[23], rsp.vpu.r[31]);
    // sqv         $v25[0], 0x7C0($2)
    rsp.SQV<0>(rsp.vpu.r[25], r2, -0X4);
    // lqv         $v29[0], 0x0($1)
    rsp.LQV<0>(rsp.vpu.r[29], r1, 0X0);
    // lqv         $v25[0], 0x0($2)
    rsp.LQV<0>(rsp.vpu.r[25], r2, 0X0);
    // vmacf       $v23, $v27, $v30[0]
    rsp.VMACF<8>(rsp.vpu.r[23], rsp.vpu.r[27], rsp.vpu.r[30]);
    // vmulf       $v22, $v22, $v31[6]
    rsp.VMULF<14>(rsp.vpu.r[22], rsp.vpu.r[22], rsp.vpu.r[31]);
    // sqv         $v24[0], 0x7D0($2)
    rsp.SQV<0>(rsp.vpu.r[24], r2, -0X3);
    // lqv         $v28[0], 0x10($1)
    rsp.LQV<0>(rsp.vpu.r[28], r1, 0X1);
    // lqv         $v24[0], 0x10($2)
    rsp.LQV<0>(rsp.vpu.r[24], r2, 0X1);
    // vmacf       $v22, $v26, $v30[0]
    rsp.VMACF<8>(rsp.vpu.r[22], rsp.vpu.r[26], rsp.vpu.r[30]);
    // addi        $1, $1, 0x40
    r1 = RSP_ADD32(r1, 0X40);
    // vmulf       $v25, $v25, $v31[6]
    rsp.VMULF<14>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[31]);
    // sqv         $v23[0], 0x7E0($2)
    rsp.SQV<0>(rsp.vpu.r[23], r2, -0X2);
    // lqv         $v27[0], 0x7E0($1)
    rsp.LQV<0>(rsp.vpu.r[27], r1, -0X2);
    // lqv         $v23[0], 0x20($2)
    rsp.LQV<0>(rsp.vpu.r[23], r2, 0X2);
    // vmacf       $v25, $v29, $v30[0]
    rsp.VMACF<8>(rsp.vpu.r[25], rsp.vpu.r[29], rsp.vpu.r[30]);
    // addi        $18, $18, -0x40
    r18 = RSP_ADD32(r18, -0X40);
    // vmulf       $v24, $v24, $v31[6]
    rsp.VMULF<14>(rsp.vpu.r[24], rsp.vpu.r[24], rsp.vpu.r[31]);
    // sqv         $v22[0], 0x7F0($2)
    rsp.SQV<0>(rsp.vpu.r[22], r2, -0X1);
    // lqv         $v26[0], 0x7F0($1)
    rsp.LQV<0>(rsp.vpu.r[26], r1, -0X1);
    // lqv         $v22[0], 0x30($2)
    rsp.LQV<0>(rsp.vpu.r[22], r2, 0X3);
    // vmacf       $v24, $v28, $v30[0]
    rsp.VMACF<8>(rsp.vpu.r[24], rsp.vpu.r[28], rsp.vpu.r[30]);
    // bgtz        $18, L_1E60
    if (RSP_SIGNED(r18) > 0) {
        // addi        $2, $2, 0x40
        r2 = RSP_ADD32(r2, 0X40);
        goto L_1E60;
    }
    // addi        $2, $2, 0x40
    r2 = RSP_ADD32(r2, 0X40);
    return RspExitReason::ImemOverrun;
do_indirect_jump:
    switch ((jump_target | 0x1000) & 0X1FFF) { 
        case 0x1ED4: goto L_1ED4;
        case 0x1ECC: goto L_1ECC;
        case 0x1060: goto L_1060;
        case 0x1DD4: goto L_1DD4;
        case 0x177C: goto L_177C;
        case 0x10D0: goto L_10D0;
        case 0x1208: goto L_1208;
        case 0x123C: goto L_123C;
        case 0x1B94: goto L_1B94;
        case 0x1128: goto L_1128;
        case 0x14D0: goto L_14D0;
        case 0x126C: goto L_126C;
        case 0x16E4: goto L_16E4;
        case 0x186C: goto L_186C;
        case 0x18C0: goto L_18C0;
        case 0x1B38: goto L_1B38;
    }
    printf("Unhandled jump target 0x%04X in microcode aspMain, coming from [%s:%d]\n", jump_target, debug_file, debug_line);
    printf("Register dump: r0  = %08X r1  = %08X r2  = %08X r3  = %08X r4  = %08X r5  = %08X r6  = %08X r7  = %08X\n"
           "               r8  = %08X r9  = %08X r10 = %08X r11 = %08X r12 = %08X r13 = %08X r14 = %08X r15 = %08X\n"
           "               r16 = %08X r17 = %08X r18 = %08X r19 = %08X r20 = %08X r21 = %08X r22 = %08X r23 = %08X\n"
           "               r24 = %08X r25 = %08X r26 = %08X r27 = %08X r28 = %08X r29 = %08X r30 = %08X r31 = %08X\n",
           0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15, r16,
           r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r29, r30, r31);
    return RspExitReason::UnhandledJumpTarget;
}
