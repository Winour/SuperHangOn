#ifndef __MODULESCENEMUSICSELECTION_H__
#define __MODULESCENEMUSICSELECTION_H__

#include "Module.h"
#include "Globals.h"
#include "Point.h"

class Animation;

class ModuleSceneMusicSelection : public Module {
public:
    ModuleSceneMusicSelection(bool active = true);
    ~ModuleSceneMusicSelection();
};

#endif // !__MODULESCENEMUSICSELECTION_H__