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



ModuleSceneAfrica::ModuleSceneAfrica(bool active) : Module(active) {
}


ModuleSceneAfrica::~ModuleSceneAfrica() {
}

bool ModuleSceneAfrica::Start() {
    IDtest = App->font->LoadFont("fonts/numbers18x30.png", "9876543210", 18, 30);
    return true;
}

update_status ModuleSceneAfrica::Update(float deltaTime) {
    App->font->DrawText(IDtest, "529", 0, 0);
    return UPDATE_CONTINUE;
}

bool ModuleSceneAfrica::CleanUp() {
    return true;
}