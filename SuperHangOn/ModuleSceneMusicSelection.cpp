#include "Globals.h"
#include "Application.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneMusicSelection.h"



ModuleSceneMusicSelection::ModuleSceneMusicSelection(bool active): Module(active) {
    background.x = 0;
    background.y = 0;
    background.w = SCREEN_WIDTH;
    background.h = SCREEN_HEIGHT;
    listMask.x = 0;
    listMask.y = 0;
    listMask.w = SCREEN_WIDTH;
    listMask.h = 217/4;
    musicList = { 4, 54, 564, 217 };
    textPushStart = { 255, 2, 313, 22 };
    textSelectMusic = { 8, 3, 223, 24 };
    countdown.loop = true;
    countdown.speed = 0.016f;


}


ModuleSceneMusicSelection::~ModuleSceneMusicSelection() {
}

bool ModuleSceneMusicSelection::Start() {
    App->renderer->camera.x = App->renderer->camera.y = 0;
    graphics = App->textures->Load("sprites/musicMenu.png");
    App->audio->PlayMusic("music/2OutrideaCrisis.ogg", 0.f);

    musicListPos.x = SCREEN_WIDTH / 2 - musicList.w / 2;
    musicListPos.y = SCREEN_HEIGHT / 5;

    textPushStartPos.x = SCREEN_WIDTH / 2 - textPushStart.w / 2;
    textPushStartPos.y = SCREEN_HEIGHT * 4 / 5;

    textSelectMusicPos.x = SCREEN_WIDTH / 2 - textSelectMusic.w / 2;
    textSelectMusicPos.y = SCREEN_HEIGHT / 10;

    return true;
}

update_status ModuleSceneMusicSelection::Update(float deltaTime) {
    timerFast += deltaTime;
    timerSlow += deltaTime;
    if (timerSlow >= BLINK_SLOW * 2) timerSlow -= BLINK_SLOW * 2;
    if (timerFast >= (BLINK_FAST * 2)) timerFast -= BLINK_FAST * 2;
    if (!switching) {
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN) {
            (selection == 0) ? selection = 3 : --selection;
            musicChanged = true;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN) {
            (selection == 3) ? selection = 0 : ++selection;
            musicChanged = true;
        }
        if (selection > 3 || selection < 0) {
            return UPDATE_STOP;
        }
    }

    if (musicChanged) {
        musicChanged = false;
        switch (selection) {
            case OUTRIDE:
                App->audio->PlayMusic("music/2OutrideaCrisis.ogg", 0.f);
                break;
            case SPRINTER:
                App->audio->PlayMusic("music/3Sprinter.ogg", 0.f);
                break;
            case WINNING:
                App->audio->PlayMusic("music/4WinningRun.ogg", 0.f);
                break;
            case HARD:
                App->audio->PlayMusic("music/5HardRoad.ogg", 0.f);
                break;
            default:
                break;
        }
    }

    App->renderer->DrawQuad(background, (Uint8)225, (Uint8)160, (Uint8)0, (Uint8)255, false);

    App->renderer->Blit(graphics, musicListPos.x, musicListPos.y, &musicList, 0);
    App->renderer->Blit(graphics, textSelectMusicPos.x, textSelectMusicPos.y, &textSelectMusic,0);

    if (timerSlow > BLINK_SLOW) {
        App->renderer->Blit(graphics, textPushStartPos.x, textPushStartPos.y, &textPushStart, 0);
    }

    listMask.y = musicListPos.y + musicList.h * selection / 4;
    if (timerFast > BLINK_FAST) {
        App->renderer->DrawQuad(listMask, (Uint8)225, (Uint8)160, (Uint8)0, (Uint8)255, false);
    }

    return UPDATE_CONTINUE;
}

bool ModuleSceneMusicSelection::CleanUp() {
    return true;
}
