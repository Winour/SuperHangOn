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
    SDL_Texture* graphics = nullptr;
    SDL_Rect background;

    SDL_Rect musicList;
    SDL_Rect listMask;

    SDL_Rect textPushStart;
    SDL_Rect textSelectMusic;
    Animation countdown;

    iPoint musicListPos, textPushStartPos, textSelectMusicPos, countdownPos;

    Uint8 selection = 0;
    float timerFast = 0.0f;
    float timerSlow = 0.0f;
    bool musicChanged = false;
};

#endif // !__MODULESCENEMUSICSELECTION_H__