#ifndef __MODULESCENENEWGAME_H_
#define __MODULESCENENEWGAME_H_

#include "Module.h"
#include "Globals.h"
#include "Animation.h"
#include "Point.h"

struct SDL_Texture;

class ModuleSceneNewGame : public Module {

public:
    ModuleSceneNewGame(bool active = true);
    ~ModuleSceneNewGame();

    bool Start();
    update_status Update();
    bool CleanUp();

public:

    SDL_Texture* hangOnTitle = nullptr;
    Animation logoAnim;
    Animation logoAnimLoop;
    iPoint titlePos;

    SDL_Texture* segaLogo = nullptr;
    Animation segaLogoAnim;
    iPoint logoPos;

    SDL_Texture* options = nullptr;
    SDL_Rect optionsOne;
    SDL_Rect optionsTwo;
    SDL_Rect copyRightSaga;
    Animation pointer;
    iPoint optionsOnePos;
    iPoint optionsTwoPos;
    iPoint copyRightPos;
    iPoint pointerPos;

    bool firstSelection = true;
};

#endif // !__MODULESCENENEWGAME_H_