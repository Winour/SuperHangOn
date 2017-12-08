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
    iPoint titlePos;

    SDL_Texture* segaLogo = nullptr;
    Animation segaLogoAnim;
    iPoint logoPos;

    SDL_Texture* options = nullptr;
    SDL_Rect backgroundOptions;
    SDL_Rect backgroundOptionsTwo;
    SDL_Rect copyRightSaga;
    Animation pointer;
    //iPoint pointerPos;
    //iPoint pointerPos;
    iPoint pointerPos;
    bool firstSelection = true;
};

#endif // !__MODULESCENENEWGAME_H_