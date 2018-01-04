#include "Globals.h"
#include "Application.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFont.h"
#include "ModuleSceneAfrica.h"



ModuleSceneAfrica::ModuleSceneAfrica(bool active) : ModuleSceneBase(active) {
}


ModuleSceneAfrica::~ModuleSceneAfrica() {
}

bool ModuleSceneAfrica::Start() {
    ModuleSceneBase::Start();
    return true;
}