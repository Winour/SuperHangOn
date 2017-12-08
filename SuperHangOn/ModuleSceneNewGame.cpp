#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleSceneNewGame.h"



ModuleSceneNewGame::ModuleSceneNewGame(bool active) : Module(active) {

    int j = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            logoAnim.frames.push_back({ j * 640 , i * 185 , 640 , 190 });
        }
    }
    for (int i = 8; i < 11; i++) {
        for (int j = 0; j < 3; j++) {
            logoAnimLoop.frames.push_back({ j * 640 , i * 185 , 640 , 190 });
        }
    }
    for (int i = 11; i < 13; i++) {
        for (int j = 0; j < 3; j++) {
            logoAnimLoop.frames.push_back({ j * 640 , i * 185 - 1 , 640 , 190 });
        }
    }


    logoAnim.loop = false;
    logoAnim.speed = 0.2f;
    logoAnimLoop.loop = true;
    logoAnimLoop.speed = 0.12f;

    optionsOne.x = 0;
    optionsOne.y = 0;
    optionsOne.w = 640;
    optionsOne.h = 48;

}


ModuleSceneNewGame::~ModuleSceneNewGame() {
}

bool ModuleSceneNewGame::Start() {
    options = App->textures->Load("sprites/MenuOneOptions.bmp");
    hangOnTitle = App->textures->Load("sprites/superHangOnLogo.bmp");

    optionsOnePos.x = (SCREEN_WIDTH / 2) - (optionsOne.w / 2);
    optionsOnePos.y = (SCREEN_HEIGHT / 2) + (optionsOne.h);
    titlePos.x = (SCREEN_WIDTH / 2) - (logoAnim.GetCurrentFrame().w / 2);
    titlePos.y = 0;

    return true;
}

update_status ModuleSceneNewGame::Update() {
    App->renderer->Blit(options, optionsOnePos.x, optionsOnePos.y, &optionsOne);
    if (logoAnim.Finished() == false) {
        App->renderer->Blit(hangOnTitle, titlePos.x, titlePos.y, &(logoAnim.GetCurrentFrame()));
    } else {
        App->renderer->Blit(hangOnTitle, titlePos.x, titlePos.y, &(logoAnimLoop.GetCurrentFrame()));
    }
    return UPDATE_CONTINUE;
}

bool ModuleSceneNewGame::CleanUp() {
    return true;
}