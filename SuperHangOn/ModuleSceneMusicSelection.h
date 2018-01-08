#ifndef __MODULESCENEMUSICSELECTION_H__
#define __MODULESCENEMUSICSELECTION_H__

#include "Module.h"
#include "Globals.h"
#include "Point.h"

class Animation;

enum MusicSelection {
    OUTRIDE,
    SPRINTER,
    WINNING,
    HARD
};

class ModuleSceneMusicSelection : public Module {
public:
    ModuleSceneMusicSelection(bool active = true);
    ~ModuleSceneMusicSelection();

    bool Start();
    update_status Update(float deltaTime);
    bool CleanUp();
private:
    SDL_Texture* texture = nullptr;
    SDL_Rect background;

    SDL_Rect musicList;
    SDL_Rect listMask;

    SDL_Rect textPushStart;
    SDL_Rect textSelectMusic;

    iPoint musicListPos, textPushStartPos, textSelectMusicPos, countdownPos;

    Uint8 selection;
    float timerFast;
    float timerSlow;
    float countdown;
    bool timeOut;
    bool musicChanged;
    bool switching;
};

#endif // !__MODULESCENEMUSICSELECTION_H__