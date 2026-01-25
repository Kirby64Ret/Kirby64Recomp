#include "patches.h"
#include "GObj.h"
#include "graphics.h"

#include "wsextern.h"
extern Gfx *gDisplayListHeads[];

extern void func_80017FEC(GObj *, Gfx **, int);

typedef struct {
    u32 _0;
    u32 _4;
    Vp viewport;
} CamHeader;

extern f32 D_8003DE74[8];

void edit_cam_viewport(CamHeader *ch) {
    u32 width, height;
    recomp_get_window_resolution(&width, &height);

    // recomp_printf("New res: %d %d\n", width, height);

    // ch->viewport.vp.vscale[0] = ((width))*4;
    // ch->viewport.vp.vscale[1] = ((height)/2)*4;
    // ch->viewport.vp.vtrans[0] = ((width))*4;
    // ch->viewport.vp.vtrans[1] = ((height)/2)*4;

    D_8003DE74[1] = -width/2;
    D_8003DE74[2] = width/2;

    f32 new_width = width;

    // D_80187878_ovl5 = new_width;
    // D_8018A998_ovl5 = new_width;
    // D_8018B5F0_ovl5 = new_width;
    // D_8018B610_ovl5 = new_width;
    // D_8018B630_ovl5 = new_width;
    // D_8018B650_ovl5 = new_width;
    // D_8018B670_ovl5 = new_width;
    // D_8018B690_ovl5 = new_width;
    // D_8018B6B0_ovl5 = new_width;
    // D_8018B6D0_ovl5 = new_width;
    // D_8018B6F0_ovl5 = new_width;
    // D_8018B710_ovl5 = new_width;
    // D_8018B730_ovl5 = new_width;
    // D_8018B750_ovl5 = new_width;
    // D_8018B770_ovl5 = new_width;
    // D_8018B790_ovl5 = new_width;
    // D_8018B7B0_ovl5 = new_width;
    // D_8018B7D0_ovl5 = new_width;
    // D_8018B7F0_ovl5 = new_width;
    // D_8018B810_ovl5 = new_width;
    // D_8018B830_ovl5 = new_width;
    // D_8018B850_ovl5 = new_width;
    // D_8018B870_ovl5 = new_width;
    // D_8018B890_ovl5 = new_width;
    // D_8018B8B0_ovl5 = new_width;
    // D_8018B8D0_ovl5 = new_width;
    // D_8018B8F0_ovl5 = new_width;
    // D_8018B910_ovl5 = new_width;
    // D_8018B930_ovl5 = new_width;
    // D_8018B950_ovl5 = new_width;
    // D_8018B970_ovl5 = new_width;
    // D_8018B990_ovl5 = new_width;
    // D_8018B9B0_ovl5 = new_width;
    // D_8018B9D0_ovl5 = new_width;
    // D_8018B9F0_ovl5 = new_width;
    // D_8018BA10_ovl5 = new_width;
    // D_8018BA30_ovl5 = new_width;
    // D_8018BA50_ovl5 = new_width;
    // D_8018BA70_ovl5 = new_width;
    // D_8018BA90_ovl5 = new_width;
    // D_8018BAB0_ovl5 = new_width;
    // D_8018BAD0_ovl5 = new_width;
    // D_8018BAF0_ovl5 = new_width;
    // D_8018BB10_ovl5 = new_width;
    // D_8018BB30_ovl5 = new_width;
    // D_8018BB50_ovl5 = new_width;
    // D_8018BB70_ovl5 = new_width;
    // D_8018BB90_ovl5 = new_width;
    // D_8018BBB0_ovl5 = new_width;
    // D_8018BBD0_ovl5 = new_width;
    // D_8018BBF0_ovl5 = new_width;
    // D_8018BC10_ovl5 = new_width;
    // D_8018BC30_ovl5 = new_width;
    // D_8018BC50_ovl5 = new_width;
    // D_8018BC70_ovl5 = new_width;
    // D_8018BC90_ovl5 = new_width;
    // D_8018BCB0_ovl5 = new_width;
    // D_8018BCD0_ovl5 = new_width;
    // D_8018BCF0_ovl5 = new_width;
    // D_8018BD10_ovl5 = new_width;
    // D_8018BD30_ovl5 = new_width;
    // D_8018BD50_ovl5 = new_width;
    // D_8018BD70_ovl5 = new_width;
    // D_8018BD90_ovl5 = new_width;
    // D_8018BDB0_ovl5 = new_width;
    // D_8018BDD0_ovl5 = new_width;
    // D_8018BDF0_ovl5 = new_width;
    // D_8018BE10_ovl5 = new_width;
    // D_8018BE30_ovl5 = new_width;
    // D_8018BE50_ovl5 = new_width;
    // D_8018BE70_ovl5 = new_width;
    // D_8018BE90_ovl5 = new_width;
    // D_8018BEB0_ovl5 = new_width;
    // D_8018BED0_ovl5 = new_width;
    // D_8018BEF0_ovl5 = new_width;
    // D_8018BF10_ovl5 = new_width;
    // D_8018BF30_ovl5 = new_width;
    // D_8018BF50_ovl5 = new_width;
    // D_8018BF70_ovl5 = new_width;
    // D_8018BF90_ovl5 = new_width;
    // D_8018BFB0_ovl5 = new_width;
    // D_8018BFD0_ovl5 = new_width;
    // D_8018BFF0_ovl5 = new_width;
}

// // Sets 3C viewport params to handle widescreen
// RECOMP_PATCH void func_8001806C(struct GObj *arg0) {
//     edit_cam_viewport((CamHeader *) arg0->data);
//     func_80017FEC(arg0, &gDisplayListHeads[0], 0);
// }

// RECOMP_PATCH void func_80018094(struct GObj *arg0) {
//     edit_cam_viewport((CamHeader *) arg0->data);
//     func_80017FEC(arg0, &gDisplayListHeads[1], 1);
// }

// RECOMP_PATCH void func_800180BC(struct GObj *arg0) {
//     edit_cam_viewport((CamHeader *) arg0->data);
//     func_80017FEC(arg0, &gDisplayListHeads[2], 2);
// }

// RECOMP_PATCH void func_800180E4(struct GObj *arg0) {
//     edit_cam_viewport((CamHeader *) arg0->data);
//     func_80017FEC(arg0, &gDisplayListHeads[3], 3);
// }

extern f32 D_800D6B10, D_800D6B14;
void func_800075DC(u16, u16);
RECOMP_PATCH void func_800A41B0(f32 tick) {
    recomp_printf("Setting tick rate to %f!\n", 60.0f / tick);
    D_800D6B10 = tick;
    D_800D6B14 = 1.0f / tick;
    func_800075DC((u16)tick, 1);
}
