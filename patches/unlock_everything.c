#include "patches.h"
#include "ctx.h"

void play_sound(s32);
void save_file_set_to_full_completion(s32);

// Sets save file 3 to completed
// (wait until the HAL logo shows up on game boot)
RECOMP_PATCH void func_80151100_ovl4(s32 arg0) {
    switch (D_800E9C60[D_8004A7C4->objId]) {
        case 0:
            save_file_set_to_full_completion(2);
            play_sound(1); // 1up sound
            D_800E9C60[D_8004A7C4->objId] = -1;
            break;
    }
}
