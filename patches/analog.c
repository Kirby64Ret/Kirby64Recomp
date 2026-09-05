// #include "patches.h"
// #include "ctx.h"
// #include "ovl2/ovl2_8.h"

// #define CONT_A      0x8000
// #define CONT_B      0x4000
// #define CONT_G      0x2000
// #define CONT_START  0x1000
// #define CONT_UP     0x0800
// #define CONT_DOWN   0x0400
// #define CONT_LEFT   0x0200
// #define CONT_RIGHT  0x0100
// #define CONT_L      0x0020
// #define CONT_R      0x0010
// #define CONT_E      0x0008
// #define CONT_D      0x0004
// #define CONT_C      0x0002
// #define CONT_F      0x0001

// /* Nintendo's official button names */

// #define A_BUTTON    CONT_A
// #define B_BUTTON    CONT_B
// #define L_TRIG      CONT_L
// #define R_TRIG      CONT_R
// #define Z_TRIG      CONT_G
// #define START_BUTTON    CONT_START
// #define U_JPAD      CONT_UP
// #define L_JPAD      CONT_LEFT
// #define R_JPAD      CONT_RIGHT
// #define D_JPAD      CONT_DOWN
// #define U_CBUTTONS  CONT_E
// #define L_CBUTTONS  CONT_C
// #define R_CBUTTONS  CONT_F
// #define D_CBUTTONS  CONT_D

// extern void func_8011DD5C(f32 *a, f32 *b);
// extern void func_800F8C70(GObj *g);
// extern void func_800F8E6C(GObj *g);
// extern void func_80112A40(s32, Vector*, Vector*);
// extern s32 change_kirby_hp(f32);
// extern u8 ovl1_TamperCheck(void);

// #define SPEEDCHANGE (2.0f)

// s32 get_stickX() {
//     return gControllers[0].stick_x;
// }

// f32 get_speed_change() {
//     s32 x = get_stickX();
//     if (ABSVAL(x) < 10) return SPEEDCHANGE;
//     return SPEEDCHANGE * ((f32)ABSVAL(x) / 80.0f);
// }
// extern GObj *D_8004A7C4;
// int test = 0;


// void printmatrix(float m[4][4]) {
//     recomp_printf("----MATRIX----\n");
//     recomp_printf("%f %f %f %f\n", m[0][0], m[0][1], m[0][2], m[0][3]);
//     recomp_printf("%f %f %f %f\n", m[1][0], m[1][1], m[1][2], m[1][3]);
//     recomp_printf("%f %f %f %f\n", m[2][0], m[2][1], m[2][2], m[2][3]);
//     recomp_printf("%f %f %f %f\n", m[3][0], m[3][1], m[3][2], m[3][3]);
// }

// extern float D_800D6ED0[][4][4];
// #define PRINT3(a, b, c) recomp_printf("%08X %08X %08X\n", *((u32*)(a)), *((u32*)(b)), *((u32*)(c)))
// #define PRINT3F(i, a, b, c) recomp_printf("%f %f %f\n", a[i], b[i], c[i])

// struct Normal {
//     f32 x, y, z, originOffset;
// };
// extern struct Normal D_800E6F50[];
// f32 sqrtf(f32);

// f32 dist_to_player (Vector *v) {
//     Vector fromPlayer;
//     fromPlayer.x = v->x - gEntitiesPosXArray[0];
//     fromPlayer.y = v->y - (gEntitiesPosYArray[0]);
//     fromPlayer.z = v->z - gEntitiesPosZArray[0];

//     return sqrtf((fromPlayer.x * fromPlayer.x) + (fromPlayer.y * fromPlayer.y) + (fromPlayer.z * fromPlayer.z));
// }

// int closest_track() {
//     f32 minDist = 999999.9f;
//     int ret = -1;
//     for (int i = 1; i < 0x70; i++) {
//         Vector pos;
//         pos.x = gEntitiesPosXArray[i];
//         pos.y = gEntitiesPosYArray[i];
//         pos.z = gEntitiesPosZArray[i];

//         f32 dist = dist_to_player(&pos);
//         if (dist < minDist) {
//             ret = i;
//             minDist = dist;
//         }
//     }

//     return ret;
// }

// f32 closest_dist() {
//     f32 minDist = 999999.9f;
//     int ret = -1;
//     for (int i = 1; i < 0x70; i++) {
//         Vector pos;
//         pos.x = gEntitiesPosXArray[i];
//         pos.y = gEntitiesPosYArray[i];
//         pos.z = gEntitiesPosZArray[i];

//         f32 dist = dist_to_player(&pos);
//         if (dist < minDist) {
//             ret = i;
//             minDist = dist;
//         }
//     }

//     return minDist;
// }

// void debug_print() {
//     recomp_printf("START DEBUG PULSE\n");
//     // PRINT3F(D_800E10D0, D_800E1290, D_800E1450);
//     // struct Normal *n = &D_800E6F50[closest_track()];
//     // recomp_printf("normal %f %f %f %f\n", n->x, n->y, n->z, n->originOffset);
//     // recomp_printf("closest %f\n", closest_dist());

//     // PRINT3F(closest_track(), gEntitiesNextPosXArray, gEntitiesNextPosYArray, gEntitiesNextPosZArray);
//     PRINT3F(0, D_800E4FD0, D_800E5190, D_800E5350);
//     PRINT3F(0, gEntitiesScaleXArray, gEntitiesScaleYArray, gEntitiesScaleZArray);

//     gEntitiesScaleXArray[0] = 0.4f;
//     gEntitiesScaleYArray[0] = 0.4f;
//     gEntitiesScaleZArray[0] = 0.4f;
//     // printmatrix(D_800D6ED0[0]);
//     // printmatrix(D_800D6ED0[1]);
//     // printmatrix(D_800D6ED0[2]);
// }

// // This function is not matched in Decomp,
// //  but is not functionally equivalent either.
// RECOMP_PATCH void func_800B531C(s32 arg0) {
//     Vector sp64;
//     f32 sp58;
//     f32 sp54;
//     f32 sp50;
//     s32 sp48;
//     Vector sp3C;
//     Vector sp30;
//     f32 var_f2;
//     f32 var_f2_2;
//     f32 var_f2_3;
//     s32 var_v0;
//     u16 var_v0_2;

//     // recomp_printf("This is a patched func\n");

//     debug_print();
//     func_800B35F0();
//     if (gKirbyState.unk18 == 0) {
//         gKirbyState.forwardVel = D_800E64D0[D_8004A7C4->objId];
//         gKirbyState.vel[0] = D_800E3050[D_8004A7C4->objId];
//         gKirbyState.vel[1] = D_800E3210[D_8004A7C4->objId];
//         gKirbyState.vel[2] = D_800E33D0[D_8004A7C4->objId];
//         sp64.x = D_800E64D0[D_8004A7C4->objId];
//         sp64.y = D_800E6690[D_8004A7C4->objId];
//         sp64.z = D_800E6850[D_8004A7C4->objId];
//         func_800B50C4(&sp64);
//         sp58 = sp64.x + sp64.y;
//     }
//     func_8011DD5C(&sp54, &sp50);
//     if (gKirbyState.unk18 != 0) {
//         D_800E64D0[D_8004A7C4->objId] =
//         D_800E6690[D_8004A7C4->objId] =
//         D_800E6850[D_8004A7C4->objId] = 0.0f;
//         sp58 = 0.0f;
//     } else if (D_800D6B54 == 0) {
//         D_800E64D0[D_8004A7C4->objId] = get_speed_change() * (D_800E5510[D_8004A7C4->objId] + sp58 + sp54);
//         if (gKirbyState.unk160 == 0) {
//             if (gKirbyState.unk164 != 0) {
//                 if (D_800E8920[D_8004A7C4->objId] != 0) {
//                     gKirbyState.unk164 = 0;
//                 } else if ((gKirbyState.horizontalCollision != 0) && (gKirbyState.unk104 != 2) && (gKirbyState.unk106 != 2)) {
//                     gKirbyState.unk164 = 0.0f;
//                 } else {
//                     if (gKirbyState.action == 9) {
//                         var_f2 = 0.5f;
//                     } else {
//                         var_f2 = 0.1f;
//                     }
//                     if (gKirbyState.unk164 > 0.0f) {
//                         gKirbyState.unk164 -= var_f2;
//                         if (gKirbyState.unk164 < 0.0f) {
//                             gKirbyState.unk164 = 0.0f;
//                         }
//                     } else {
//                         gKirbyState.unk164 += var_f2;
//                         if (gKirbyState.unk164 > 0.0f) {
//                             gKirbyState.unk164 = 0.0f;
//                         }
//                     }
//                     D_800E64D0[D_8004A7C4->objId] += gKirbyState.unk164;
//                 }
//             }
//             if (gKirbyState.unk168 != 0.0f) {
//                 if (gKirbyState.ceilingCollisionNext != 0) {
//                     gKirbyState.unk168 = 0.0f;
//                 } else {
//                     if (gKirbyState.action == 9) {
//                         var_f2_2 = 1.28f;
//                     } else {
//                         var_f2_2 = 1.14f;
//                     }
//                     if (gKirbyState.unk168 > 0.0f) {
//                         gKirbyState.unk168 -= var_f2_2;
//                         if (gKirbyState.unk168 < 0.0f) {
//                             gKirbyState.unk168 = 0.0f;
//                         }
//                     } else {
//                         gKirbyState.unk168 += var_f2_2;
//                         if (gKirbyState.unk168 > 0.0f) {
//                             gKirbyState.unk168 = 0.0f;
//                         }
//                     }
//                     gEntitiesNextPosYArray[D_8004A7C4->objId] += gKirbyState.unk168;
//                 }
//             }
//         }
//     }
//     gKirbyState.unk170 = D_800E5F90[D_8004A7C4->objId];
//     func_800F8E6C(D_800DE350[D_8004A7C4->objId]);
//     func_800F8C70(D_800DE350[D_8004A7C4->objId]);
//     D_800E64D0[D_8004A7C4->objId] = sp58;
//     func_800B46F8();
//     if (D_800D6B54 == 0) {
//         D_800E3210[D_8004A7C4->objId] += (D_800E5C10[D_8004A7C4->objId] + sp50);
//     }
//     gEntitiesNextPosXArray[D_8004A7C4->objId] += D_800E3050[D_8004A7C4->objId];
//     gEntitiesNextPosYArray[D_8004A7C4->objId] += D_800E3210[D_8004A7C4->objId];
//     gEntitiesNextPosZArray[D_8004A7C4->objId] += D_800E33D0[D_8004A7C4->objId];
//     if (gEntitiesNextPosYArray[D_8004A7C4->objId] < -10000.0f) {
//         D_800E3750[D_8004A7C4->objId] = 0;
//         D_800E3210[D_8004A7C4->objId] = D_800E3750[D_8004A7C4->objId];
//         D_800E3C90[D_8004A7C4->objId] = 65535.0f;
//         func_8011D40C();
//         gEntitiesNextPosYArray[D_8004A7C4->objId] = -10000.0f;
//     }
//     if (gKirbyHp != 0) {
//         sp48 = 0x14;
//         if (gKirbyState.unk162 == 0x14) {
//             if (D_800E8920[D_8004A7C4->objId] != 0) {
//                 gKirbyState.unk162 = func_8011E244(0.0f);
//             }
//         }
//         if (gKirbyState.unk162 != 0x14) {
//             func_8011E31C(&sp3C);
//             func_80112A40(gKirbyState.unk162, &sp3C, &sp30);
//             if ((sp30.x != 0) || (sp30.z != 0.f)) {
//                 var_f2_3 = func_800F8728(D_8004A7C4->objId, sp30.x, sp30.z);
//             } else {
//                 var_f2_3 = 0;
//             }
//             gEntitiesNextPosXArray[D_8004A7C4->objId] += sp30.x;
//             gEntitiesNextPosYArray[D_8004A7C4->objId] += sp30.y;
//             gEntitiesNextPosZArray[D_8004A7C4->objId] += sp30.z;
//             gKirbyState.unk160 = 1;
//             gKirbyState.unk164 = var_f2_3;
//             gKirbyState.unk168 = sp30.y;
//         } else {
//             gKirbyState.unk160 = 0;
//         }
//     } else {
//         gKirbyState.unk168 = 0.0f;
//         gKirbyState.unk160 = 0;
//         gKirbyState.unk164 = gKirbyState.unk168;
//     }
// }

