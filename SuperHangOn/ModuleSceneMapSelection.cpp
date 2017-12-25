#include "Globals.h"
#include "Application.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneMapSelection.h"



ModuleSceneMapSelection::ModuleSceneMapSelection(bool active) : Module(active) {
    background.x = 0;
    background.y = 0;
    background.w = SCREEN_WIDTH;
    background.h = SCREEN_HEIGHT;

    countdown.frames.push_back({ 4 , 49 , 32 , 30 });
    countdown.frames.push_back({ 41 , 49 , 18 , 30 });
    countdown.frames.push_back({ 63 , 49 , 18 , 30 });
    countdown.frames.push_back({ 85 , 49 , 18 , 30 });
    countdown.frames.push_back({ 107 , 49 , 18 , 30 });
    countdown.frames.push_back({ 129 , 49 , 18 , 30 });
    countdown.frames.push_back({ 151 , 49 , 18 , 30 });
    countdown.frames.push_back({ 173 , 49 , 18 , 30 });
    countdown.frames.push_back({ 195 , 49 , 18 , 30 });
    countdown.frames.push_back({ 217 , 49 , 18 , 30 });
    countdown.frames.push_back({ 236 , 49 , 18 , 30 });
    countdown.loop = true;
    countdown.speed = 0.016f;

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
    americaPos.y = SCREEN_HEIGHT * 0.55f - america.h / 2;

    textAmericaPos.x = americaPos.x + 40;
    textAmericaPos.y = americaPos.y + 60;

    europePos.x = SCREEN_WIDTH * 0.55f - europe.w * 2 / 3;
    europePos.y = SCREEN_HEIGHT * 0.48f - europe.h;

    textEuropePos.x = europePos.x;
    textEuropePos.y = europePos.y + 30;

    africaPos.x = SCREEN_WIDTH * 0.55f - europe.w * 2 / 3 + 8;
    africaPos.y = SCREEN_HEIGHT * 0.48f - 7;

    textAfricaPos.x = africaPos.x;
    textAfricaPos.y = africaPos.y + 30;

    asiaPos.x = SCREEN_WIDTH * 1.05f - asia.w * 1.49f;
    asiaPos.y = SCREEN_HEIGHT * 0.55f - asia.h * 2 / 3 + 17;

    textAsiaPos.x = asiaPos.x + 50;
    textAsiaPos.y = asiaPos.y + 35;

    textPushStartPos.x = SCREEN_WIDTH / 2 - textPushStart.w / 2;
    textPushStartPos.y = SCREEN_HEIGHT * 4 / 5;

    textSelectClassPos.x = SCREEN_WIDTH / 2 - textSelectClass.w / 2;
    textSelectClassPos.y = SCREEN_HEIGHT / 8;

    countdownPos.x = SCREEN_WIDTH / 2 - countdown.GetCurrentFrame().w / 2;
    countdownPos.y = SCREEN_HEIGHT * 0.7f;
    return true;
}

update_status ModuleSceneMapSelection::Update(float deltaTime) {
    timerFast += deltaTime;
    timerSlow += deltaTime;
    if (timerSlow >= BLINK_SLOW * 2) timerSlow -= BLINK_SLOW * 2;  
    if (timerFast >= (BLINK_FAST * 2)) timerFast -= BLINK_FAST * 2;
    
    if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN) {
        (selection == 3) ? selection = 0 : ++selection;
    }
    if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN) {
        (selection == 0) ? selection = 3 : --selection;
    }
    if (selection > 3 || selection < 0) {
        return UPDATE_STOP;
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
    App->renderer->Blit(map, countdownPos.x, countdownPos.y, &(countdown.GetCurrentFrame()), 0);

    return UPDATE_CONTINUE;
}

bool ModuleSceneMapSelection::CleanUp() {
    return true;
}