#include "sounds.h"


extern int D_800E9C60[];

extern void saveForceCompleteFile(int);
extern void play_sound(int);

struct GObj {
    unsigned long objId;
};

extern struct GObj *omCurrentObj;

void check_save_file_completion_cheat_code(__attribute__((unused)) struct GObj *arg0) {
    switch (D_800E9C60[omCurrentObj->objId]) {
        case 0:
            saveForceCompleteFile(2);
            play_sound(SOUND_1UP1);
            D_800E9C60[omCurrentObj->objId] = -1;
    }
}
