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
#include "ModulePlayer.h"



ModulePlayer::ModulePlayer(bool active) : Module(active) {


    straight.frames.push_back({ 181, 559, 66, 146 });
    straight.frames.push_back({ 257, 559, 66, 146 });
    straight.loop = true;
    straight.speed = 0.15f;

    turnRightOne.frames.push_back({ 871, 721, 72, 142 });
    turnRightOne.frames.push_back({ 795, 721, 72, 142 });
    turnRightOne.loop = true;
    turnRightOne.speed = 0.15f;

    turnRightTwo.frames.push_back({ 699, 737, 92, 126 });
    turnRightTwo.frames.push_back({ 597, 737, 92, 126 });
    turnRightTwo.loop = true;
    turnRightTwo.speed = 0.15f;

    turnRightThree.frames.push_back({ 463, 753, 126, 110 });
    turnRightThree.frames.push_back({ 333, 753, 126, 110 });
    turnRightThree.loop = true;
    turnRightThree.speed = 0.15f;

    turnLeftOne.frames.push_back({ 335, 563, 72, 142 });
    turnLeftOne.frames.push_back({ 411, 563, 72, 142 });
    turnLeftOne.loop = true;
    turnLeftOne.speed = 0.15f;

    turnLeftTwo.frames.push_back({ 487, 579, 92, 126 });
    turnLeftTwo.frames.push_back({ 589, 579, 92, 126 });
    turnLeftTwo.loop = true;
    turnLeftTwo.speed = 0.15f;

    turnLeftThree.frames.push_back({ 689, 595, 126, 110 });
    turnLeftThree.frames.push_back({ 819, 595, 126, 110 });
    turnLeftThree.loop = true;
    turnLeftThree.speed = 0.15f;

    turboRightThree.frames.push_back({ 1141,900,126,110 });
    turboRightThree.frames.push_back({ 1271, 900,126,110 });
    turboRightThree.loop = true;
    turboRightThree.speed = 0.04f;

    turboRightTwo.frames.push_back({ 1411,890,92,126 });
    turboRightTwo.frames.push_back({ 1513,890,92,126 });
    turboRightTwo.loop = true;
    turboRightTwo.speed = 0.04f;

    turboRightOne.frames.push_back({ 1608, 890, 72, 142 });
    turboRightOne.frames.push_back({ 1684, 890, 72, 142 });
    turboRightOne.loop = true;
    turboRightOne.speed = 0.04f;

    turboLeftThree.frames.push_back({ 1506,1091,126,110 });
    turboLeftThree.frames.push_back({ 1636, 1091,126,110 });
    turboLeftThree.loop = true;
    turboLeftThree.speed = 0.04f;

    turboLeftTwo.frames.push_back({ 1304,1075,92,126 });
    turboLeftTwo.frames.push_back({ 1406,1075,92,126 });
    turboLeftTwo.loop = true;
    turboLeftTwo.speed = 0.04f;

    turboLeftOne.frames.push_back({ 1152, 1059, 72, 142 });
    turboLeftOne.frames.push_back({ 1228, 1059, 72, 142 });
    turboLeftOne.loop = true;
    turboLeftOne.speed = 0.04f;

    turboStraight.frames.push_back({ 982, 870, 66, 146 });
    turboStraight.frames.push_back({ 1058, 870, 66, 146 });
    turboStraight.loop = true;
    turboStraight.speed = 0.04f;

    dust.frames.push_back({ 1285,56,28,50 });
    dust.frames.push_back({ 1317,44,43,25 });
    dust.frames.push_back({ 1363,19,45,50 });
    dust.frames.push_back({ 1238,12,41,56 });
    dust.loop = true;
    dust.speed = 0.2f;

    slowFall.frames.push_back({ 0, 0, 220, 124 });
    slowFall.frames.push_back({ 220, 0, 220, 124 });
    slowFall.frames.push_back({ 440, 0, 220, 124 });
    slowFall.frames.push_back({ 660, 0, 220, 124 });
    slowFall.frames.push_back({ 880, 0, 220, 124 });
    slowFall.frames.push_back({ 1100, 0, 220, 124 });
    slowFall.frames.push_back({ 0, 124, 220, 124 });
    slowFall.frames.push_back({ 220, 124, 220, 124 });
    slowFall.frames.push_back({ 440, 124, 220, 124 });
    slowFall.frames.push_back({ 660, 124, 220, 124 });
    slowFall.frames.push_back({ 880, 124, 220, 124 });
    slowFall.frames.push_back({ 1100, 124, 220, 124 });
    slowFall.frames.push_back({ 0, 248, 220, 124 });
    slowFall.frames.push_back({ 0, 248, 220, 124 });
    slowFall.frames.push_back({ 0, 248, 220, 124 });
    slowFall.frames.push_back({ 0, 248, 220, 124 });
    slowFall.frames.push_back({ 0, 248, 220, 124 });
    slowFall.frames.push_back({ 0, 248, 220, 124 });
    slowFall.loop = false;
    slowFall.speed = 0.2f;

    fastFall.frames.push_back({ 0, 373, 171, 144 });
    fastFall.frames.push_back({ 171, 373, 171, 144 });
    fastFall.frames.push_back({ 342, 373, 171, 144 });
    fastFall.frames.push_back({ 513, 373, 171, 144 });
    fastFall.frames.push_back({ 684, 373, 171, 144 });
    fastFall.frames.push_back({ 855, 373, 171, 144 });
    fastFall.frames.push_back({ 1026, 373, 171, 144 });
    fastFall.frames.push_back({ 0, 517, 171, 144 });
    fastFall.frames.push_back({ 171, 517, 171, 144 });
    fastFall.frames.push_back({ 342, 517, 171, 144 });
    fastFall.frames.push_back({ 513, 517, 171, 144 });
    fastFall.frames.push_back({ 513, 517, 171, 144 });
    fastFall.frames.push_back({ 513, 517, 171, 144 });
    fastFall.frames.push_back({ 513, 517, 171, 144 });
    fastFall.frames.push_back({ 513, 517, 171, 144 });
    fastFall.frames.push_back({ 513, 517, 171, 144 });
    fastFall.loop = false;
    fastFall.speed = 0.2f;
}


ModulePlayer::~ModulePlayer() {
}

bool ModulePlayer::Start() {
    timer = speed = xPos = 0.0f;
    state = score = stateRace = 0;
    texture = App->textures->Load("sprites/map&players.png");
    textureFalls = App->textures->Load("sprites/falls.png");
    engineFX = App->audio->LoadFx("music/fxEngine.wav");
    outOfRoadFX = App->audio->LoadFx("music/fxOutRoad.wav");
    colisionFX = App->audio->LoadFx("music/fxColision.wav");
    currentAnimation = &straight;
    position.x = SCREEN_WIDTH / 2 - currentAnimation->GetCurrentFrame().w / 2;
    position.y = SCREEN_HEIGHT * 5 / 6 - currentAnimation->GetCurrentFrame().h / 2;
    dustPos.x = position.x + 13;
    dustPos.y = position.y + 100;
    return true;
}

update_status ModulePlayer::Update(float deltaTime) {
    RecalculateAnimSpeed();

    if (stateRace == RUNNING) {
        if (App->input->GetKey(SDL_SCANCODE_X) == KEY_REPEAT) {
            if (!outOfRoad) {
                speed += deltaTime * ACCELERATION * 2;
                if (speed > MAX_SPEED) {
                    speed = MAX_SPEED;
                }
            } else {
                speed += deltaTime * ACCELERATION * 2;
                if (speed > MAX_SPEED_OUT_OF_ROAD) {
                    speed -= deltaTime * 10 *ACCELERATION;
                }
            }
        } else {
            if (speed < IDLE_SPEED) {
                speed += deltaTime * ACCELERATION;
            } else {
                speed -= deltaTime * ACCELERATION * 1.5f;
            }
            if (speed < IDLE_SPEED + 1 && speed > IDLE_SPEED - 1) {
                speed = IDLE_SPEED;
            }
        }
    } else {
        speed = 0.0f;
    }

    if (stateRace == RUNNING) {
        if (outOfRoad) {
            App->audio->PlayFx(outOfRoadFX, (speed / MAX_SPEED) / 3);
        } else {
            App->audio->PlayFx(engineFX, (speed / MAX_SPEED) / 7);
        }
        if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT) {
            if (xPos - dustPos.x + position.x * 3 > ROAD_WIDTH * 1.35f) {
                outOfRoad = true;
            } else if (xPos - dustPos.x + position.x < -ROAD_WIDTH* 1.4f) {
                outOfRoad = true;
            } else {
                outOfRoad = false;
            }
            if (state != LEFT_THREE) {
                timer += deltaTime;
                if (timer >= SWAP_ANIM) {
                    animChange = true;
                    state--;
                    timer -= SWAP_ANIM;
                }
            }
        } else if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT) {
            if (xPos - dustPos.x + position.x > ROAD_WIDTH * 1.35f) {
                outOfRoad = true;
            } else if (xPos - dustPos.x * 2 + position.x < -ROAD_WIDTH* 1.3f) {
                outOfRoad = true;
            } else {
                outOfRoad = false;
            }
            if (state != RIGHT_THREE) {
                timer += deltaTime;
                if (timer >= SWAP_ANIM) {
                    animChange = true;
                    state++;
                    timer -= SWAP_ANIM;
                }
            }
        } else if (state < STRAIGHT) {
            timer += deltaTime;
            if (xPos - dustPos.x + position.x > ROAD_WIDTH * 1.3f) {
                outOfRoad = true;
            } else if (xPos - dustPos.x + position.x < -ROAD_WIDTH* 1.3f) {
                outOfRoad = true;
            } else {
                outOfRoad = false;
            }
            if (timer >= SWAP_ANIM) {
                animChange = true;
                state++;
                timer -= SWAP_ANIM;
            }
        } else if (state > STRAIGHT) {
            timer += deltaTime;
            if (xPos - dustPos.x + position.x > ROAD_WIDTH * 1.3f) {
                outOfRoad = true;
            } else if (xPos - dustPos.x + position.x < -ROAD_WIDTH* 1.3f) {
                outOfRoad = true;
            } else {
                outOfRoad = false;
            }
            if (timer >= SWAP_ANIM) {
                animChange = true;
                state--;
                timer -= SWAP_ANIM;
            }
        } else {
            if (xPos - dustPos.x + position.x > ROAD_WIDTH * 1.3f) {
                outOfRoad = true;
            } else if (xPos - dustPos.x + position.x < -ROAD_WIDTH* 1.3f) {
                outOfRoad = true;
            } else {
                outOfRoad = false;
            }
        }
        xPos += deltaTime * speed * 8.0f * state;

        if (xPos > MAX_X) {
            xPos = MAX_X;
        } else if (xPos< -MAX_X) {
            xPos = -MAX_X;
        }
    }

    if (animChange && stateRace == RUNNING) {
        animChange = false;
        switch (state) {
            case LEFT_THREE:
                currentAnimation = &turnLeftThree;
                RecalculatePos();
                dustPos.x = position.x + 100;
                dustPos.y = position.y + 70;
                break;
            case LEFT_TWO:
                currentAnimation = &turnLeftTwo;
                RecalculatePos();
                dustPos.x = position.x + 60;
                dustPos.y = position.y + 90;
                break;
            case LEFT_ONE:
                currentAnimation = &turnLeftOne;
                RecalculatePos();
                dustPos.x = position.x + 28;
                dustPos.y = position.y + 100;
                break;
            case STRAIGHT:
                currentAnimation = &straight;
                RecalculatePos();
                dustPos.x = position.x + 13;
                dustPos.y = position.y + 100;
                break;
            case RIGHT_ONE:
                currentAnimation = &turnRightOne;
                RecalculatePos();
                dustPos.x = position.x;
                dustPos.y = position.y + 100;
                break;
            case RIGHT_TWO:
                currentAnimation = &turnRightTwo;
                RecalculatePos();
                dustPos.x = position.x;
                dustPos.y = position.y + 100;
                break;
            case RIGHT_THREE:
                currentAnimation = &turnRightThree;
                RecalculatePos();
                dustPos.x = position.x - 10;
                dustPos.y = position.y + 70;
                break;
            default:
                break;
            }

    }

    if (backToRoadTimer > 0.0f && stateRace == ON_THE_FLOOR) {
        backToRoadTimer -= deltaTime;
        if (backToRoadTimer <= 0.0f) {
            stateRace = RESPAWNING;
            backToRoadTimer = 2.0f;
            state = STRAIGHT;
            currentAnimation = &straight;
            RecalculatePos();
            offsetToRoad = (0 - xPos) / 2;
        }
    }

    if (backToRoadTimer > 0.0f && stateRace == RESPAWNING) {
        backToRoadTimer -= deltaTime;
        xPos += offsetToRoad * deltaTime;
        RecalculatePos();
        if (backToRoadTimer <= 0.0f) {
            stateRace = RUNNING;
            backToRoadTimer = -2.0f;
            fall = false;
        }
    }

    collider = { SCREEN_WIDTH / 2 - currentAnimation->GetCurrentFrame().w / 2, SCREEN_HEIGHT - 10, currentAnimation->GetCurrentFrame().w, -currentAnimation->GetCurrentFrame().h };
    
    if (stateRace == FALLING) {
        if (speed > 150) {
            currentAnimation = &fastFall;
            fallSpeed = speed * 0.05f;
        } else {
            currentAnimation = &slowFall;
            fallSpeed = speed * 0.05f;
        }
        speed = 0;
        stateRace = ON_THE_FLOOR;
    }
    if (stateRace == RESPAWNING) {
        if ((int)(backToRoadTimer * 5) % 2 == 0){
            App->renderer->Blit(texture, position.x, position.y, &currentAnimation->GetCurrentFrame(), 0);
        }
    } else {
        if (!fall) {
            if (!outOfRoad) {
                App->renderer->Blit(texture, position.x, position.y, &currentAnimation->GetCurrentFrame(), 0);
            } else {
                App->renderer->Blit(texture, position.x + rand() % 4 - 2, position.y + rand() % 4 - 2, &currentAnimation->GetCurrentFrame(), 0);
                App->renderer->Blit(texture, dustPos.x, dustPos.y, &dust.GetCurrentFrame(), 0);
            }
        } else {
            position.y -= fallSpeed;
            App->renderer->Blit(textureFalls, position.x - 40, position.y - 80, &currentAnimation->GetCurrentFrame(), 0, 2.5f);
            fallSpeed = fallSpeed * 2 / 3;
        }
    }

    if (!outOfRoad) {
        score += (int)(speed * speed * deltaTime / 40) * 10;
    }
    App->topScore = MAX(App->topScore, score);
    
    return UPDATE_CONTINUE;
}

bool ModulePlayer::CleanUp() {
    return true;
}

void ModulePlayer::RecalculatePos() {
    position.x = SCREEN_WIDTH / 2 - currentAnimation->GetCurrentFrame().w / 2;
    position.y = SCREEN_HEIGHT * 5 / 6 - currentAnimation->GetCurrentFrame().h / 2;
}

void ModulePlayer::CentripetalForce(float value) {
    xPos += 3 * value * speed * speed / MAX_SPEED;
}

void ModulePlayer::RecalculateAnimSpeed() {
    if (!fall) {
        currentAnimation->speed = (speed / MAX_SPEED)/3;
    }
}

void ModulePlayer::Collision(SDL_Rect object) {
    App->renderer->DrawQuad(collider, 0, 0, 255, 100, false);
    if (!(collider.x > object.x + object.w || collider.x + collider.w < object.x) ) {
        fall = true;
        stateRace = FALLING;
        App->audio->PlayFx(colisionFX);
        backToRoadTimer = 2.0f;
    }
}