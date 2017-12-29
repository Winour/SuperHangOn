#ifndef __MODULESCENEBASE_H__
#define __MODULESCENEBASE_H__

#include "Module.h"
#include "Globals.h"
#include "Point.h"

class ModuleSceneBase : public Module {
public:
    ModuleSceneBase(bool active = true);
    ~ModuleSceneBase();

    bool Start();
    update_status Update(float deltaTime);
    bool CleanUp();
};

#endif // !__MODULESCENEBASE_H__