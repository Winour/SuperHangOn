#ifndef __MODULESCENEAFRICA_H__
#define __MODULESCENEAFRICA_H__

#include "ModuleSceneBase.h"

class ModuleSceneAfrica : public ModuleSceneBase {
public:
    ModuleSceneAfrica(bool active = true);
    ~ModuleSceneAfrica();

    bool Start();
    update_status Update(float deltaTime);
    bool CleanUp();
    
public:

};

#endif // !__MODULESCENEAFRICA_H__