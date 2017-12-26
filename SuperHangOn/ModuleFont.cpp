#include "ModuleFont.h"



ModuleFont::ModuleFont(bool start_enabled) : Module(start_enabled) {
}


ModuleFont::~ModuleFont() {
}

bool ModuleFont::Start() {
    return true;
}
update_status ModuleFont::Update(float deltaTime) {
    return UPDATE_CONTINUE;
}
bool ModuleFont::CleanUp() {
    return true;
}