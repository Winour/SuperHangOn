#include "Globals.h"
#include "Application.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFont.h"
#include "ModuleSceneMapSelection.h"
#include <string>



ModuleSceneMapSelection::ModuleSceneMapSelection(bool active) : Module(active) {
    background.x = 0;
    background.y = 0;
    background.w = SCREEN_WIDTH;
    background.h = SCREEN_HEIGHT;

    africa = { 584, 2, 110, 116 };
    europe = { 694, 6, 118, 104 };
    america = { 564 , 120, 196, 260 };
    asia = { 784, 106, 240, 276 };

    textEurope = { 428, 40, 147, 36 };
    textAfrica = { 281, 0, 147, 39 };
    textAsia = { 281, 40, 147, 39 };
    textAmerica = { 426, 0, 149, 40 };

    textSelectClass = { 3, 3, 278, 21 };
    textPushStart = { 3, 26, 278, 20 };
}


ModuleSceneMapSelection::~ModuleSceneMapSelection() {
}

bool ModuleSceneMapSelection::Start() {
    App->renderer->camera.x = App->renderer->camera.y = 0;

    map = App->textures->Load("sprites/map&players.png");
    App->audio->PlayMusic("music/1SelectYourClass.ogg", 0.5f);

    americaPos.x = SCREEN_WIDTH / 8;
    americaPos.y = (int)(SCREEN_HEIGHT * 0.55f) - america.h / 2;

    textAmericaPos.x = americaPos.x + 40;
    textAmericaPos.y = americaPos.y + 60;

    europePos.x = (int)(SCREEN_WIDTH * 0.55f) - europe.w * 2 / 3;
    europePos.y = (int)(SCREEN_HEIGHT * 0.48f) - europe.h;

    textEuropePos.x = europePos.x;
    textEuropePos.y = europePos.y + 30;

    africaPos.x = (int)(SCREEN_WIDTH * 0.55f) - europe.w * 2 / 3 + 8;
    africaPos.y = (int)(SCREEN_HEIGHT * 0.48f) - 7;

    textAfricaPos.x = africaPos.x;
    textAfricaPos.y = africaPos.y + 30;

    asiaPos.x = (int)(SCREEN_WIDTH * 1.05f) - (int)(asia.w * 1.49f);
    asiaPos.y = (int)(SCREEN_HEIGHT * 0.55f) - asia.h * 2 / 3 + 17;

    textAsiaPos.x = asiaPos.x + 50;
    textAsiaPos.y = asiaPos.y + 35;

    textPushStartPos.x = SCREEN_WIDTH / 2 - textPushStart.w / 2;
    textPushStartPos.y = SCREEN_HEIGHT * 4 / 5;

    textSelectClassPos.x = SCREEN_WIDTH / 2 - textSelectClass.w / 2;
    textSelectClassPos.y = SCREEN_HEIGHT / 8;

    countdownPos.x = SCREEN_WIDTH / 2 + 15;
    countdownPos.y = (int)(SCREEN_HEIGHT * 0.7f);
    return true;
}

update_status ModuleSceneMapSelection::Update(float deltaTime) {
    timerFast += deltaTime;
    timerSlow += deltaTime;
    if (!timeOut) {
        if (countdown > 0.0f) {
            countdown -= deltaTime;
        } else {
            timeOut = true;
        }
        if (countdown < 0.0f) {
            countdown = 0.0f;
        }
    }
    if (timerSlow >= BLINK_SLOW * 2) timerSlow -= BLINK_SLOW * 2;  
    if (timerFast >= (BLINK_FAST * 2)) timerFast -= BLINK_FAST * 2;
    if (!switching) {
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN) {
            (selection == 3) ? selection = 0 : ++selection;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN) {
            (selection == 0) ? selection = 3 : --selection;
        }
        if (App->input->GetKey(SDL_SCANCODE_RETURN) == KEY_DOWN || timeOut) {
            switching = true;
            App->fade->FadeToBlack((Module*)App->sceneMusicSelection, this, 1.0f);
        }
        if (selection > 3 || selection < 0) {
            selection = 0;
        }
    }

    App->renderer->DrawQuad(background, (Uint8)160, (Uint8)190, (Uint8)225, (Uint8)255, false);
    if ((timerFast > BLINK_FAST && selection == AMERICA) || selection != AMERICA) {
        App->renderer->Blit(map, americaPos.x, americaPos.y, &america, 0);
    }
    if ((timerFast > BLINK_FAST && selection == EUROPE) || selection != EUROPE) {
        App->renderer->Blit(map, europePos.x, europePos.y, &europe, 0);
    }
    if ((timerFast > BLINK_FAST && selection == AFRICA) || selection != AFRICA) {
        App->renderer->Blit(map, africaPos.x, africaPos.y, &africa, 0);
    }
    if ((timerFast > BLINK_FAST && selection == ASIA) || selection != ASIA) {
        App->renderer->Blit(map, asiaPos.x, asiaPos.y, &asia, 0);
    }

    App->renderer->Blit(map, textAmericaPos.x, textAmericaPos.y, &textAmerica, 0);
    App->renderer->Blit(map, textEuropePos.x, textEuropePos.y, &textEurope, 0);
    App->renderer->Blit(map, textAfricaPos.x, textAfricaPos.y, &textAfrica, 0);
    App->renderer->Blit(map, textAsiaPos.x, textAsiaPos.y, &textAsia, 0);

    if (timerSlow > BLINK_SLOW) {
        App->renderer->Blit(map, textPushStartPos.x, textPushStartPos.y, &textPushStart, 0);
    }
    App->renderer->Blit(map, textSelectClassPos.x, textSelectClassPos.y, &textSelectClass, 0);
    App->font->DrawText(App->font->countdownFont, to_string((int)countdown).c_str(), countdownPos.x, countdownPos.y);

    return UPDATE_CONTINUE;
}

bool ModuleSceneMapSelection::CleanUp() {
    return true;
}