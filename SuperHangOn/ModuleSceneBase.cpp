#include "ModuleSceneBase.h"



ModuleSceneBase::ModuleSceneBase(bool active) : Module(active) {
}


ModuleSceneBase::~ModuleSceneBase() {
}

bool ModuleSceneBase::Start() {
    return true;
}
update_status ModuleSceneBase::Update(float deltaTime) {
    return UPDATE_CONTINUE;
}
bool ModuleSceneBase::CleanUp() {
    return true;
}