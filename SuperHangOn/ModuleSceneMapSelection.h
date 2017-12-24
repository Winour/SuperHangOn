#ifndef __MODULESCENEMAPSELECTION__H__
#define __MODULESCENEMAPSELECTION__H__

#include "Module.h"
#include "Globals.h"
#include "Point.h"

class Animation;

class ModuleSceneMapSelection : public Module {

public:
    ModuleSceneMapSelection();
    ~ModuleSceneMapSelection();

    bool Start();
    update_status Update();
    bool CleanUp();

public:
    uint music;
};

#endif // !__MODULESCENEMAPSELECTION__H__