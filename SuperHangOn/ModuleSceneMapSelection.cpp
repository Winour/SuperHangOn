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
#include "ModuleSceneMapSelection.h"



ModuleSceneMapSelection::ModuleSceneMapSelection(bool active) : Module(active) {
    background.x = 0;
    background.y = 0;
    background.w = SCREEN_WIDTH;
    background.h = SCREEN_HEIGHT;

    africa = { 584, 2, 110, 116 };
    europe = { 694, 6, 118, 104 };
    america = { 564 , 120, 196, 260 };
    asia = { 784, 106, 240, 276 };
}


ModuleSceneMapSelection::~ModuleSceneMapSelection() {
}

bool ModuleSceneMapSelection::Start() {
    App->renderer->camera.x = App->renderer->camera.y = 0;

    map = App->textures->Load("sprites/map&players.png");
    App->audio->PlayMusic("music/1SelectYourClass.ogg", 0.5f);

    americaPos.x = SCREEN_WIDTH / 20;
    americaPos.y = SCREEN_HEIGHT / 2 - america.h / 2;
    return true;
}

update_status ModuleSceneMapSelection::Update() {
    App->renderer->DrawQuad(background, (Uint8)160, (Uint8)190, (Uint8)225, (Uint8)255, false);
    App->renderer->Blit(map, americaPos.x, americaPos.y, &america);
    return UPDATE_CONTINUE;
}

bool ModuleSceneMapSelection::CleanUp() {
    return true;
}