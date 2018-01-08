#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleFadeToBlack.h"



ModuleSceneIntro::ModuleSceneIntro(bool active) : Module(active) {

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 3; j++) {
            anim.frames.push_back({ j * 640 , i * 65 , 640 , 65 });
        }
    }
    anim.speed = 0.25f;
    anim.loop = true;
}


ModuleSceneIntro::~ModuleSceneIntro() {

}

bool ModuleSceneIntro::Start() {
    App->renderer->camera.x = App->renderer->camera.y = 0;
    segaIntro = App->textures->Load("sprites/segaLogo.bmp");
    position.x = (SCREEN_WIDTH/2) - (anim.GetCurrentFrame().w/2);
    position.y = (SCREEN_HEIGHT/2) - (anim.GetCurrentFrame().h/2);
    App->renderer->camera.x = App->renderer->camera.y = 0;  
    anim.Reset();
    return true;
}

update_status ModuleSceneIntro::Update(float deltaTime) {

    if ((anim.Finished() || App->input->GetKey(SDL_SCANCODE_RETURN) == KEY_DOWN) && App->fade->isFading() == false) {
        App->fade->FadeToBlack((Module*)App->sceneNewGame, this, 0.5f);
    }

    App->renderer->Blit(segaIntro, position.x, position.y, &(anim.GetCurrentFrame()), 0.0f);

    return UPDATE_CONTINUE;
}

bool ModuleSceneIntro::CleanUp() {

    LOG("Unloading Intro");

    App->textures->Unload(segaIntro);

    return true;
}