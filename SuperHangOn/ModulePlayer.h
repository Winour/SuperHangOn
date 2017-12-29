#ifndef __MODULEPLAYER_H__
#define __MODULEPLAYER_H__

#include "Module.h"

class ModulePlayer : public Module {
public:
    ModulePlayer(bool active = true);
    ~ModulePlayer();
};

#endif // !__MODULEPLAYER_H__