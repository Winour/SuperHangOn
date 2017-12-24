#ifndef __MODULESCENEINTRO_H__
#define __MODULESCENEINTRO_H__

#include "Module.h"
#include "Globals.h"
#include "Animation.h"
#include "Point.h"

//struct SDL_Texture;

class ModuleSceneIntro : public Module {
public:
    ModuleSceneIntro(bool active = true);
    ~ModuleSceneIntro();

    bool Start();
    update_status Update();
    bool CleanUp();

public:
    SDL_Texture* segaIntro = nullptr;
    Animation anim;
    iPoint position;
};

#endif // !__MODULESCENEINTRO_H__