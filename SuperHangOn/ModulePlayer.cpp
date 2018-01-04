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
    state = 0;
    texture = App->textures->Load("sprites/map&players.png");
    textureFalls = App->textures->Load("sprites/falls.png");
    currentAnimation = &straight;
    position.x = SCREEN_WIDTH / 2 - currentAnimation->GetCurrentFrame().w / 2;
    position.y = SCREEN_HEIGHT * 5 / 6 - currentAnimation->GetCurrentFrame().h / 2;
    return true;
}

update_status ModulePlayer::Update(float deltaTime) {
    if (!fall) {
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
        speed = 0;
    }
    if (App->input->GetKey(SDL_SCANCODE_0) == KEY_DOWN) {
        currentAnimation = &fastFall;
        fall = true;
        fallSpeed = speed * 0.25f;
    }

    if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT) {
        if (state != LEFT_THREE) {
            timer += deltaTime;
            if (timer >= SWAP_ANIM) {
                animChange = true;
                state--;
                timer -= SWAP_ANIM;
            }
        }
    } else if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT) {
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
        if (timer >= SWAP_ANIM) {
            animChange = true;
            state++;
            timer -= SWAP_ANIM;
        }
    } else if (state > STRAIGHT) {
        timer += deltaTime;
        if (timer >= SWAP_ANIM) {
            animChange = true;
            state--;
            timer -= SWAP_ANIM;
        }
    }
    xPos += deltaTime * speed * 8.0f * state;
    if (xPos > MAX_X) {
        xPos = MAX_X;
    } else if (xPos< -MAX_X) {
        xPos = -MAX_X;
    }
    if (xPos > ROAD_WIDTH * 1.4f) {
        outOfRoad = true;
    } else if (xPos< -ROAD_WIDTH* 1.4f) {
        outOfRoad = true;
    } else {
        outOfRoad = false;
    }



    if (animChange) {
        animChange = false;
        switch (state) {
            case LEFT_THREE:
                currentAnimation = &turnLeftThree;
                break;
            case LEFT_TWO:
                currentAnimation = &turnLeftTwo;
                break;
            case LEFT_ONE:
                currentAnimation = &turnLeftOne;
                break;
            case STRAIGHT:
                currentAnimation = &straight;
                break;
            case RIGHT_ONE:
                currentAnimation = &turnRightOne;
                break;
            case RIGHT_TWO:
                currentAnimation = &turnRightTwo;
                break;
            case RIGHT_THREE:
                currentAnimation = &turnRightThree;
                break;
            default:
                break;
            }
        RecalculatePos();
    }
    if (!fall) {
        App->renderer->Blit(texture, position.x, position.y, &currentAnimation->GetCurrentFrame(), 0);
    } else {
        position.y -= fallSpeed;
        App->renderer->Blit(textureFalls, position.x - 40, position.y - 80, &currentAnimation->GetCurrentFrame(), 0,2.0f);
        fallSpeed = fallSpeed * 2 / 3;
    }
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