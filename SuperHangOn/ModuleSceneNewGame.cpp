#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleSceneNewGame.h"



ModuleSceneNewGame::ModuleSceneNewGame(bool active) : Module(active) {
    backgroundOptions.x = 0;
    backgroundOptions.y = 0;
    backgroundOptions.w = 640;
    backgroundOptions.h = 48;
}


ModuleSceneNewGame::~ModuleSceneNewGame() {
}

bool ModuleSceneNewGame::Start() {
    options = App->textures->Load("sprites/MenuOneOptions.bmp");
    return true;
}

update_status ModuleSceneNewGame::Update() {
    App->renderer->Blit(options, 0, 0, &backgroundOptions);
    return UPDATE_CONTINUE;
}

bool ModuleSceneNewGame::CleanUp() {
    return true;
}