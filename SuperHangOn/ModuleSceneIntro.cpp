#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleSceneIntro.h"
#include "ModuleFadeToBlack.h"



ModuleSceneIntro::ModuleSceneIntro(bool active) : Module(active) {

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 3; j++) {
            anim.frames.push_back({ j * 640 , i * 65 , 640 , 65 });
        }
    }
    anim.speed = 0.25f;
    anim.loop = false;
}


ModuleSceneIntro::~ModuleSceneIntro() {

}

bool ModuleSceneIntro::Start() {

    LOG("Loading Intro scene");

    currentAnim = &anim;
    segaIntro = App->textures->Load("sprites/segaLogo.bmp");
    position.x = (SCREEN_WIDTH/2) - (currentAnim->GetCurrentFrame().w/2);
    position.y = (SCREEN_HEIGHT/2) - (currentAnim->GetCurrentFrame().h/2);
    App->renderer->camera.x = App->renderer->camera.y = 0;

    return true;
}

update_status ModuleSceneIntro::Update() {

    if (currentAnim->Finished()) {
        //App->fade->FadeToBlack();
    }
    App->renderer->Blit(segaIntro, position.x, position.y, &(currentAnim->GetCurrentFrame()));

    return UPDATE_CONTINUE;
}

bool ModuleSceneIntro::CleanUp() {

    LOG("Unloading Intro");

    App->textures->Unload(segaIntro);

    return true;
}