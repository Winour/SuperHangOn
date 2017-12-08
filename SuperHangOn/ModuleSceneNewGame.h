#ifndef __MODULESCENENEWGAME_H_
#define __MODULESCENENEWGAME_H_

#include "Module.h"
#include "Globals.h"
#include "Animation.h"
#include "Point.h"

struct SDL_Texture;

class ModuleSceneNewGame : public Module {
public:
    ModuleSceneNewGame();
    ~ModuleSceneNewGame();
};

#endif // !__MODULESCENENEWGAME_H_