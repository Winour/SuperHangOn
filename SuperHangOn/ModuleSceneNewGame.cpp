#include "Globals.h"
#include "Application.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneNewGame.h"



ModuleSceneNewGame::ModuleSceneNewGame(bool active) : Module(active) {

    int j = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            logoAnim.frames.push_back({ j * 640 , i * 185 , 640 , 190 });
        }
    }
    logoAnim.loop = false;
    logoAnim.speed = 0.2f;

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
    logoAnimLoop.loop = true;
    logoAnimLoop.speed = 0.12f;

    j = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            segaLogoAnim.frames.push_back({ j * 640 , i * 53 , 640 , 53 });
        }
    }
    segaLogoAnim.loop = true;
    segaLogoAnim.speed = 0.3f;

    pointer.frames.push_back({ 0, 68, 16, 16 });
    pointer.frames.push_back({ 0, 48, 16, 16 });
    pointer.loop = true;
    pointer.speed = 0.05f;

    optionsOne = { 0 , 0 , 640 , 48 };
    optionsTwo = { 0 , 84 , 640 , 48 };
    copyRight = { 0 , 48 , 640 , 20 };
}


ModuleSceneNewGame::~ModuleSceneNewGame() {
}

bool ModuleSceneNewGame::Start() {
    App->renderer->camera.x = App->renderer->camera.y = 0;

    textureOptions = App->textures->Load("sprites/MenuOneOptions.bmp");
    textureHangOnTitle = App->textures->Load("sprites/superHangOnLogo.bmp");
    textureSegaLogo = App->textures->Load("sprites/segaLogoMenuOne.bmp");

    logoAnim.Reset();
    logoAnimLoop.Reset();

    firstSelection = true;
    firstMenu = true;
    switching = false;

    optionsOnePos.x = (SCREEN_WIDTH / 2) - (optionsOne.w / 2);
    optionsOnePos.y = (SCREEN_HEIGHT / 2) + (optionsOne.h);
    optionsTwoPos.x = (SCREEN_WIDTH / 2) - (optionsTwo.w / 2);
    optionsTwoPos.y = (SCREEN_HEIGHT / 2) + (optionsTwo.h);
    titlePos.x = (SCREEN_WIDTH / 2) - (logoAnim.GetCurrentFrame().w / 2);
    titlePos.y = 0;
    copyRightPos.x = (SCREEN_WIDTH / 8);
    copyRightPos.y = (SCREEN_HEIGHT * 8 / 9);
    logoPos.x = (SCREEN_WIDTH / 2) - (segaLogoAnim.GetCurrentFrame().w / 2);
    logoPos.y = (SCREEN_HEIGHT * 7 / 9);

    return true;
}

update_status ModuleSceneNewGame::Update(float deltaTime) {
    if (!switching) {
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN) {
            firstSelection = !firstSelection;
        }
        if (App->input->GetKey(SDL_SCANCODE_RETURN) == KEY_DOWN && firstSelection) {
            if (firstMenu) {
                firstMenu = false;
            } else {
                switching = true;
                App->fade->FadeToBlack((Module*)App->sceneMapSelection, this, 0.5f);
            }
        }
    }
    if (logoAnim.Finished() == false) {
        App->renderer->Blit(textureHangOnTitle, titlePos.x, titlePos.y, &(logoAnim.GetCurrentFrame()), 0.0f);
    } else {
        App->renderer->Blit(textureHangOnTitle, titlePos.x, titlePos.y, &(logoAnimLoop.GetCurrentFrame()), 0.0f);
    }
    if (firstMenu) {
        App->renderer->Blit(textureOptions, optionsOnePos.x, optionsOnePos.y, &optionsOne, 0.0f);
    } else {
        App->renderer->Blit(textureOptions, optionsTwoPos.x, optionsTwoPos.y, &optionsTwo, 0.0f);
    }

    App->renderer->Blit(textureSegaLogo, logoPos.x, logoPos.y, &(segaLogoAnim.GetCurrentFrame()), 0.0f);
    App->renderer->Blit(textureOptions, copyRightPos.x, copyRightPos.y, &copyRight, 0.0f);
    if (firstMenu) {
        if (firstSelection) {
            pointerPos.x = (optionsOne.w * 3 / 7);
            pointerPos.y = (SCREEN_HEIGHT / 2) + (optionsOne.h);
        } else {
            pointerPos.x = (optionsOne.w * 3 / 7);
            pointerPos.y = (SCREEN_HEIGHT / 2) + (optionsOne.h * 5 / 3);
        }
    } else {
        if (firstSelection) {
            pointerPos.x = (optionsOne.w / 2) - 95;
            pointerPos.y = (SCREEN_HEIGHT / 2) + (optionsOne.h);
        } else {
            pointerPos.x = (optionsOne.w / 2) - 95;
            pointerPos.y = (SCREEN_HEIGHT / 2) + (optionsOne.h * 5 / 3);
        }
    }
    App->renderer->Blit(textureOptions, pointerPos.x, pointerPos.y, &(pointer.GetCurrentFrame()), 0.0f);

    return UPDATE_CONTINUE;
}

bool ModuleSceneNewGame::CleanUp() {
    App->textures->Unload(textureHangOnTitle);
    App->textures->Unload(textureSegaLogo);
    App->textures->Unload(textureOptions);
    return true;
}