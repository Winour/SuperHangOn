#ifndef __MODULESCENEAFRICA_H__
#define __MODULESCENEAFRICA_H__

#include "Module.h"
#include "Globals.h"
#include "Point.h"

class Animation;

class ModuleSceneAfrica : public Module {
public:
    ModuleSceneAfrica(bool active = true);
    ~ModuleSceneAfrica();

    bool Start();
    update_status Update(float deltaTime);
    bool CleanUp();
};

#endif // !__MODULESCENEAFRICA_H__