#ifndef __MODULESCENENEWGAME_H__
#define __MODULESCENENEWGAME_H__

#include "Module.h"
#include "Globals.h"
#include "Point.h"

class Animation;

struct SDL_Texture;

class ModuleSceneNewGame : public Module {

public:
    ModuleSceneNewGame(bool active = true);
    ~ModuleSceneNewGame();

    bool Start();
    update_status Update(float deltaTime);
    bool CleanUp();

private:

    SDL_Texture* textureHangOnTitle = nullptr;
    Animation logoAnim;
    Animation logoAnimLoop;
    iPoint titlePos;

    SDL_Texture* textureSegaLogo = nullptr;
    Animation segaLogoAnim;
    iPoint logoPos;

    SDL_Texture* textureOptions = nullptr;
    SDL_Rect optionsOne;
    SDL_Rect optionsTwo;
    SDL_Rect copyRight;
    Animation pointer;
    iPoint optionsOnePos;
    iPoint optionsTwoPos;
    iPoint copyRightPos;
    iPoint pointerPos;

    bool firstSelection;
    bool firstMenu;
    bool switching;
};

#endif // !__MODULESCENENEWGAME_H__