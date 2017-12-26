#ifndef __MODULEFONT_H__
#define __MODULEFONT_H__

#include "Module.h"
#include "Globals.h"
#include "Point.h"

class ModuleFont : public Module{
public:
    ModuleFont(bool start_enabled = true);
    ~ModuleFont();

    bool Start();
    update_status Update(float deltaTime);
    bool CleanUp();
};

#endif // !__MODULEFONT_H__