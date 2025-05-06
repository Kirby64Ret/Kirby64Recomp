#include "patches.h"
#include "GObj.h"
#include "graphics.h"

extern Gfx *gDisplayListHeads[];

extern void func_80017FEC(GObj *, Gfx **, int);

typedef struct {
    u32 _0;
    u32 _4;
    Vp viewport;
} CamHeader;

void edit_cam_viewport(CamHeader *ch) {
    // u32 width, height;
    // recomp_get_window_resolution(&width, &height);

    // recomp_printf("New res: %d %d\n", width, height);

    // ch->viewport.vp.vscale[0] = ((width))*4;
    // ch->viewport.vp.vscale[1] = ((height)/2)*4;
    // ch->viewport.vp.vtrans[0] = ((width))*4;
    // ch->viewport.vp.vtrans[1] = ((height)/2)*4;
}

// Sets 3C viewport params to handle widescreen
RECOMP_PATCH void func_8001806C(struct GObj *arg0) {
    edit_cam_viewport((CamHeader *) arg0->data);
    func_80017FEC(arg0, &gDisplayListHeads[0], 0);
}

RECOMP_PATCH void func_80018094(struct GObj *arg0) {
    edit_cam_viewport((CamHeader *) arg0->data);
    func_80017FEC(arg0, &gDisplayListHeads[1], 1);
}

RECOMP_PATCH void func_800180BC(struct GObj *arg0) {
    edit_cam_viewport((CamHeader *) arg0->data);
    func_80017FEC(arg0, &gDisplayListHeads[2], 2);
}

RECOMP_PATCH void func_800180E4(struct GObj *arg0) {
    edit_cam_viewport((CamHeader *) arg0->data);
    func_80017FEC(arg0, &gDisplayListHeads[3], 3);
}


