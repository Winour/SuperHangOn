#ifndef __MODULESCENEINTRO_H_
#define __MODULESCENEINTRO_H_

#include "Module.h"
#include "Globals.h"
#include "Animation.h"
#include "Point.h"

struct SDL_Texture;

class ModuleSceneIntro : public Module {
public:
    ModuleSceneIntro(bool active = true);
    ~ModuleSceneIntro();

    bool Start();
    update_status Update();
    bool CleanUp();

public:
    SDL_Texture * segaIntro = nullptr;
    Animation* currentAnim;
    Animation anim;
    iPoint position;
};

#endif // !__MODULESCENEINTRO_H_