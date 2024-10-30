#include "patches.h"
#include "ctx.h"

extern void func_8011DD5C(f32 *a, f32 *b);
extern void func_800F8C70(GObj *g);
extern void func_800F8E6C(GObj *g);
extern void func_80112A40(s32, Vector*, Vector*);
extern s32 change_kirby_hp(f32);
extern u8 ovl1_TamperCheck(void);

#define SPEEDCHANGE (1.0f)

s32 get_stickX() {
    return gControllers[0].stick_x;
}

f32 get_speed_change() {
    s32 x = get_stickX();
    if (ABSVAL(x) < 10) return SPEEDCHANGE;
    return SPEEDCHANGE * ((f32)ABSVAL(x) / 80.0f);
}

RECOMP_PATCH void func_800B531C(s32 arg0) {
    Vector sp64;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    s32 sp48;
    Vector sp3C;
    Vector sp30;
    f32 var_f2;
    f32 var_f2_2;
    f32 var_f2_3;
    s32 var_v0;
    u16 var_v0_2;

    // recomp_printf("This is a patched func\n");

    func_800B35F0();
    if (gKirbyState.unk18 == 0) {
        gKirbyState.forwardVel = D_800E64D0[D_8004A7C4->objId];
        gKirbyState.vel[0] = D_800E3050[D_8004A7C4->objId];
        gKirbyState.vel[1] = D_800E3210[D_8004A7C4->objId];
        gKirbyState.vel[2] = D_800E33D0[D_8004A7C4->objId];
        sp64.x = D_800E64D0[D_8004A7C4->objId];
        sp64.y = D_800E6690[D_8004A7C4->objId];
        sp64.z = D_800E6850[D_8004A7C4->objId];
        func_800B50C4(&sp64);
        sp58 = sp64.x + sp64.y;
    }
    func_8011DD5C(&sp54, &sp50);
    if (gKirbyState.unk18 != 0) {
        D_800E64D0[D_8004A7C4->objId] =
        D_800E6690[D_8004A7C4->objId] =
        D_800E6850[D_8004A7C4->objId] = 0.0f;
        sp58 = 0.0f;
    } else if (D_800D6B54 == 0) {
        D_800E64D0[D_8004A7C4->objId] = get_speed_change() * (D_800E5510[D_8004A7C4->objId] + sp58 + sp54);
        if (gKirbyState.unk160 == 0) {
            if (gKirbyState.unk164 != 0) {
                if (D_800E8920[D_8004A7C4->objId] != 0) {
                    gKirbyState.unk164 = 0;
                } else if ((gKirbyState.horizontalCollision != 0) && (gKirbyState.unk104 != 2) && (gKirbyState.unk106 != 2)) {
                    gKirbyState.unk164 = 0.0f;
                } else {
                    if (gKirbyState.action == 9) {
                        var_f2 = 0.5f;
                    } else {
                        var_f2 = 0.1f;
                    }
                    if (gKirbyState.unk164 > 0.0f) {
                        gKirbyState.unk164 -= var_f2;
                        if (gKirbyState.unk164 < 0.0f) {
                            gKirbyState.unk164 = 0.0f;
                        }
                    } else {
                        gKirbyState.unk164 += var_f2;
                        if (gKirbyState.unk164 > 0.0f) {
                            gKirbyState.unk164 = 0.0f;
                        }
                    }
                    D_800E64D0[D_8004A7C4->objId] += gKirbyState.unk164;
                }
            }
            if (gKirbyState.unk168 != 0.0f) {
                if (gKirbyState.ceilingCollisionNext != 0) {
                    gKirbyState.unk168 = 0.0f;
                } else {
                    if (gKirbyState.action == 9) {
                        var_f2_2 = 1.28f;
                    } else {
                        var_f2_2 = 1.14f;
                    }
                    if (gKirbyState.unk168 > 0.0f) {
                        gKirbyState.unk168 -= var_f2_2;
                        if (gKirbyState.unk168 < 0.0f) {
                            gKirbyState.unk168 = 0.0f;
                        }
                    } else {
                        gKirbyState.unk168 += var_f2_2;
                        if (gKirbyState.unk168 > 0.0f) {
                            gKirbyState.unk168 = 0.0f;
                        }
                    }
                    gEntitiesNextPosYArray[D_8004A7C4->objId] += gKirbyState.unk168;
                }
            }
        }
    }
    gKirbyState.unk170 = D_800E5F90[D_8004A7C4->objId];
    func_800F8E6C(D_800DE350[D_8004A7C4->objId]);
    func_800F8C70(D_800DE350[D_8004A7C4->objId]);
    D_800E64D0[D_8004A7C4->objId] = sp58;
    func_800B46F8();
    if (D_800D6B54 == 0) {
        D_800E3210[D_8004A7C4->objId] += (D_800E5C10[D_8004A7C4->objId] + sp50);
    }
    gEntitiesNextPosXArray[D_8004A7C4->objId] += D_800E3050[D_8004A7C4->objId];
    gEntitiesNextPosYArray[D_8004A7C4->objId] += D_800E3210[D_8004A7C4->objId];
    gEntitiesNextPosZArray[D_8004A7C4->objId] += D_800E33D0[D_8004A7C4->objId];
    if (gEntitiesNextPosYArray[D_8004A7C4->objId] < -10000.0f) {
        D_800E3750[D_8004A7C4->objId] = 0;
        D_800E3210[D_8004A7C4->objId] = D_800E3750[D_8004A7C4->objId];
        D_800E3C90[D_8004A7C4->objId] = 65535.0f;
        func_8011D40C();
        gEntitiesNextPosYArray[D_8004A7C4->objId] = -10000.0f;
    }
    if (gKirbyHp != 0) {
        sp48 = 0x14;
        if (gKirbyState.unk162 == 0x14) {
            if (D_800E8920[D_8004A7C4->objId] != 0) {
                gKirbyState.unk162 = func_8011E244(0.0f);
            }
        }
        if (gKirbyState.unk162 != 0x14) {
            func_8011E31C(&sp3C);
            func_80112A40(gKirbyState.unk162, &sp3C, &sp30);
            if ((sp30.x != 0) || (sp30.z != 0.f)) {
                var_f2_3 = func_800F8728(D_8004A7C4->objId, sp30.x, sp30.z);
            } else {
                var_f2_3 = 0;
            }
            gEntitiesNextPosXArray[D_8004A7C4->objId] += sp30.x;
            gEntitiesNextPosYArray[D_8004A7C4->objId] += sp30.y;
            gEntitiesNextPosZArray[D_8004A7C4->objId] += sp30.z;
            gKirbyState.unk160 = 1;
            gKirbyState.unk164 = var_f2_3;
            gKirbyState.unk168 = sp30.y;
        } else {
            gKirbyState.unk160 = 0;
        }
    } else {
        gKirbyState.unk168 = 0.0f;
        gKirbyState.unk160 = 0;
        gKirbyState.unk164 = gKirbyState.unk168;
    }
    change_kirby_hp(6.0f);
}

