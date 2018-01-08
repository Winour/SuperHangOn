#ifndef __MODULESCENEMAPSELECTION__H__
#define __MODULESCENEMAPSELECTION__H__

#include "Module.h"
#include "Globals.h"
#include "Point.h"

class Animation;

enum Selection {
    AFRICA,
    EUROPE,
    AMERICA,
    ASIA
};

class ModuleSceneMapSelection : public Module {

public:
    ModuleSceneMapSelection(bool active = true);
    ~ModuleSceneMapSelection();

    bool Start();
    update_status Update(float deltaTime);
    bool CleanUp();

private:
    SDL_Texture* map = nullptr;
    SDL_Rect background;

    SDL_Rect africa;
    SDL_Rect europe;
    SDL_Rect america;
    SDL_Rect asia;

    SDL_Rect textEurope;
    SDL_Rect textAfrica;
    SDL_Rect textAsia;
    SDL_Rect textAmerica;

    SDL_Rect textPushStart;
    SDL_Rect textSelectClass;

    iPoint africaPos, europePos, americaPos, asiaPos;
    iPoint textEuropePos, textAfricaPos, textAsiaPos, textAmericaPos, textPushStartPos, textSelectClassPos, countdownPos;
    Uint8 selection;
    float countdown;
    float timerFast;
    float timerSlow;
    bool switching;
    bool timeOut;
};

#endif // !__MODULESCENEMAPSELECTION__H__