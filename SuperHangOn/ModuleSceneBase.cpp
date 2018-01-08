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
#include "ModuleSceneBase.h"
#include "Segment.h"

#include <string>
#include "SDL_gfx/include/sdl2_gfxprimitives.h"
#pragma comment( lib, "SDL_gfx/libx86/SDL2_gfx.lib" )

using namespace std;

ModuleSceneBase::ModuleSceneBase(bool active) : Module(active) {
    background = { 20 , 61 , 350 , 275 };
    mountains = { 668 , 98 , 625 , 28 };
    score = { 175 , 437 , 98 , 26};
    time = { 97, 437, 76, 26 };
    course = { 409, 421, 98, 18 };
    stage = { 275, 421, 83, 18 };
    africa = { 266 , 467 , 99 , 20 };
    top = { 33 , 437 , 62 , 25 };
    speed = { 275 , 441 , 82 , 18 };
    km = { 367 , 441 , 34 , 18 };
    sg = { 33 , 467 , 226 , 18 };
    gameOver = { 1153 , 248 , 184 , 34 };
    extendedPlay = { 1153 , 294 , 158 , 19 };

    semaphore.frames.push_back({ 9, 264, 72, 143 });
    semaphore.frames.push_back({ 9, 264, 72, 143 });
    semaphore.frames.push_back({ 81, 264, 72, 143 });
    semaphore.frames.push_back({ 154, 264,69, 143 });
    semaphore.frames.push_back({ 222, 264, 72, 143 });
    semaphore.frames.push_back({ 0, 0, 0, 0 });
    semaphore.loop = false;
    semaphore.speed = 0.016f;

    greenStraight.frames.push_back({ 180,878, 67,147 });
    greenStraight.frames.push_back({ 256,878, 67,147 });
    greenStraight.speed = 0.08f;
    greenStraight.loop = true;

    greenLeftOne.frames.push_back({ 336,888, 73,137 });
    greenLeftOne.frames.push_back({ 412,888, 73,137 });
    greenLeftOne.speed = 0.2f;
    greenLeftOne.loop = true;

    greenLeftTwo.frames.push_back({ 486,898, 93,127 });
    greenLeftTwo.frames.push_back({ 588,898, 93,127 });
    greenLeftTwo.speed = 0.2f;
    greenLeftTwo.loop = true;

    greenLeftThree.frames.push_back({ 688,914,127,111 });
    greenLeftThree.frames.push_back({ 818,914,127,111 });
    greenLeftThree.speed = 0.2f;
    greenLeftThree.loop = true;

    greenRightOne.frames.push_back({ 782, 1224, 73, 137 });
    greenRightOne.frames.push_back({ 858, 1224, 73, 137 });
    greenRightOne.speed = 0.2f;
    greenRightOne.loop = true;

    greenRightTwo.frames.push_back({ 584, 1230, 93, 127 });
    greenRightTwo.frames.push_back({ 686, 1230, 93, 127 });
    greenRightTwo.speed = 0.2f;
    greenRightTwo.loop = true;

    greenRightThree.frames.push_back({ 450,1246,127,111 });
    greenRightThree.frames.push_back({ 320,1246,127,111 });
    greenRightThree.speed = 0.2f;
    greenRightThree.loop = true;

    yellowStraight.frames.push_back({ 180,1038, 67,147 });
    yellowStraight.frames.push_back({ 256,1038, 67,147 });
    yellowStraight.speed = 0.06f;
    yellowStraight.loop = true;

    yellowLeftOne.frames.push_back({ 336,1042, 73,147 });
    yellowLeftOne.frames.push_back({ 412,1042, 73,147 });
    yellowLeftOne.speed = 0.2f;
    yellowLeftOne.loop = true;

    yellowLeftTwo.frames.push_back({ 486,1058, 93,127 });
    yellowLeftTwo.frames.push_back({ 588,1058, 93,127 });
    yellowLeftTwo.speed = 0.2f;
    yellowLeftTwo.loop = true;

    yellowLeftThree.frames.push_back({ 688,1074,127,111 });
    yellowLeftThree.frames.push_back({ 818,1074,127,111 });
    yellowLeftThree.speed = 0.2f;
    yellowLeftThree.loop = true;

    yellowRightOne.frames.push_back({ 782, 1374, 73, 147 });
    yellowRightOne.frames.push_back({ 858, 1374, 73, 147 });
    yellowRightOne.speed = 0.2f;
    yellowRightOne.loop = true;

    yellowRightTwo.frames.push_back({ 584, 1390, 93, 127 });
    yellowRightTwo.frames.push_back({ 686, 1390, 93, 127 });
    yellowRightTwo.speed = 0.2f;
    yellowRightTwo.loop = true;

    yellowRightThree.frames.push_back({ 320,1406,127,111 });
    yellowRightThree.frames.push_back({ 450,1406,127,111 });
    yellowRightThree.speed = 0.2f;
    yellowRightThree.loop = true;

    SDL_Rect r;
    r = { 649, 0, 138, 209 };
    objects.push_back(r);
    bushID = objects.size() - 1;

    r = { 961, 31, 173, 122 };
    objects.push_back(r);
    signLeftID = objects.size() - 1;

    r = { 1164, 28, 173, 126 };
    objects.push_back(r);
    signRightID = objects.size() - 1;

    r = { 1517, 178, 175, 170 };
    objects.push_back(r);
    barrelID = objects.size() - 1;

    r = { 1377, 37, 431, 120 };
    objects.push_back(r);
    bidalStoneID = objects.size() - 1;

    r = { 1290, 358, 356, 168 };
    objects.push_back(r);
    rockID = objects.size() - 1;

    r = { 17, 426, 834, 278 };
    objects.push_back(r);
    startSignID = objects.size() - 1;

    r = { 13, 721, 840, 279 };
    objects.push_back(r);
    checkSignID = objects.size() - 1;

    r = { 7, 1003, 852, 311 };
    objects.push_back(r);
    goalSignID = objects.size() - 1;

    r = { 21, 1357, 548, 184 };
    objects.push_back(r);
    peopleID = objects.size() - 1;

}


ModuleSceneBase::~ModuleSceneBase() {

}

bool ModuleSceneBase::Start() {
    App->player->Enable();
    textureBackground = App->textures->Load("sprites/backgrounds.png");
    guiTexture = App->textures->Load("sprites/map&players.png");
    textureObjects = App->textures->Load("sprites/decoration.png");
    SetUpGUI();
    SetUpColors();
    stageNumber = 1;
    beamNumber = 3;
    timer = 5.0f;
    countdown = 5.0f;
    state = nextState = Intro;
    timerSemaphore = 0.0f;
    camY = 1500.0f;
    camZ = 0.0f;
    wPosZ = 0.0f;
    offsetX = 0.0f;
    roadX = 0.0f;
    roadY = 0.0f;
    backgroundOffset = 0.0f;
    mountainsOffset = 0.0f;
    roadLength = 0;

    if (enemies.size() == 0) {
        Enemy* e = new Enemy;
        e->x = 0.0f;
        e->z = 6;
        e->isYellow = true;
        e->speed = 50.0f;  // = 200 player speed
        e->currentAnimation = &yellowStraight;
        enemies.push_back(e);

        e = new Enemy;
        e->x = -0.35f;
        e->z = 5;
        e->isYellow = false;
        e->speed = 50.0f;
        e->currentAnimation = &greenStraight;
        enemies.push_back(e);

        e = new Enemy;
        e->x = 0.35f;
        e->z = 5;
        e->isYellow = false;
        e->speed = 50.0f;
        e->currentAnimation = &greenStraight;
        enemies.push_back(e);

        e = new Enemy;
        e->x = 0.65f;
        e->z = 4;
        e->isYellow = true;
        e->speed = 50.0f;
        e->currentAnimation = &yellowStraight;
        enemies.push_back(e);

        e = new Enemy;
        e->x = -0.65f;
        e->z = 4;
        e->isYellow = true;
        e->speed = 50.0f;
        e->currentAnimation = &yellowStraight;
        enemies.push_back(e);
    } else {
        enemies.clear();
        Enemy* e = new Enemy;
        e->x = 0.0f;
        e->z = 6;
        e->isYellow = true;
        e->speed = 50.0f;  // = 200 player speed
        e->currentAnimation = &yellowStraight;
        enemies.push_back(e);

        e = new Enemy;
        e->x = -0.35f;
        e->z = 5;
        e->isYellow = false;
        e->speed = 50.0f;
        e->currentAnimation = &greenStraight;
        enemies.push_back(e);

        e = new Enemy;
        e->x = 0.35f;
        e->z = 5;
        e->isYellow = false;
        e->speed = 50.0f;
        e->currentAnimation = &greenStraight;
        enemies.push_back(e);

        e = new Enemy;
        e->x = 0.65f;
        e->z = 4;
        e->isYellow = true;
        e->speed = 50.0f;
        e->currentAnimation = &yellowStraight;
        enemies.push_back(e);

        e = new Enemy;
        e->x = -0.65f;
        e->z = 4;
        e->isYellow = true;
        e->speed = 50.0f;
        e->currentAnimation = &yellowStraight;
        enemies.push_back(e);
    }
    semaphoreFX = App->audio->LoadFx("music/fxSemaphoreOne.wav");
    semaphoreFinalFX = App->audio->LoadFx("music/fxSemaphoreFinal.wav");
    loadTrackFX = App->audio->LoadFx("music/fxLoadTrack.wav");
    lapFX = App->audio->LoadFx("music/fxLap.wav");
    segments.clear();
    for (int i = 0; i < 1000; i++) {
        Segment* s = new Segment();
        s->wZ = i * segmentLength;
        s->wY = (i > 0) ? (segments[i - 1])->wY : 0;
        if (i == 8) {
            s->spriteID = startSignID;
            s->spriteX = 0;
            s->collides = false;
        }
        if (i < 200) {
        } else if (i < 500) {
            s->curve = -5.0f;
        } else {
            s->curve = 0.0f;
        }

        if (i > 20) {
            //Hill(segments[i - 1], s, i, 50, 90);
        }
        if (i % 50 == 0) {
            s->spriteID = 0;
            s->spriteX = -2;
        }
                                                     // 15-60  /  70-130  GOOD VALUES
        segments.push_back(s);  
    }
    roadLength = segments.size();
    return true;
}
update_status ModuleSceneBase::Update(float deltaTime) {
    App->renderer->DrawQuad(sky, blueSky.r, blueSky.g, blueSky.b, blueSky.a, false);
    switch (state) {
        case Intro:

            App->player->stateRace == IDLE;
            for (int i = 0; i < enemies.size(); i++) {
                enemies[i]->currentAnimation->speed = 0.0f;
            }
            timer -= deltaTime;
            timerSemaphore += deltaTime;
            App->player->speed = 0.0f;
            if (beamNumber == 3) {
                App->audio->PlayFx(loadTrackFX);
                beamNumber--;
            }
            if (timerSemaphore > 2.5f && beamNumber > 0) {
                App->audio->PlayFx(semaphoreFX);
                timerSemaphore -= 1.0f;
                beamNumber--;
            }if (timerSemaphore > 2.5f && beamNumber == 0) {
                App->audio->PlayFx(semaphoreFinalFX);
                beamNumber = -5;
            }
            if (timer < 0.0f) {
                nextState = Race;          
                App->player->stateRace = RUNNING;
                for (int i = 0; i < enemies.size(); i++) {
                    enemies[i]->currentAnimation->speed = 0.25f;
                }
                switch (App->musicSelected) {
                    case 0:
                        App->audio->PlayMusic("music/2OutrideaCrisis.ogg", 0.f);
                        break;
                    case 1:
                        App->audio->PlayMusic("music/3Sprinter.ogg", 0.f);
                        break;
                    case 2:
                        App->audio->PlayMusic("music/4WinningRun.ogg", 0.f);
                        break;
                    case 3:
                        App->audio->PlayMusic("music/5HardRoad.ogg", 0.f);
                        break;
                    default:
                        break;
                }
            }
            break;

        case Race:
            countdown -= deltaTime;
            RecalculatePosition(App->player->speed * deltaTime * 55);   
            for (int i = enemies.size() - 1; i >= 0; i--) {
                UpdateEnemy(enemies[i], deltaTime);
            }
            if (countdown < 0) {
                timer = 3.0f;
                nextState = GameOver;
            }
            break;

        case Finish:

            break;

        case GameOver:
            timer -= deltaTime;
            App->player->stateRace = GAME_OVER;
            if (timer <= 0.0f) {
                timer = 99.0f;
                App->audio->StopMusic(0.1f);
                App->audio->StopFx();
                App->fade->FadeToBlack((Module*)App->sceneIntro, this, 0.1f);
                App->player->Disable();
            }
            break;

        default:
            break;

    }
    state = nextState;

    DrawRoad(deltaTime);

    DrawGUI();
    return UPDATE_CONTINUE;
}


void ModuleSceneBase::DrawRoad(float deltaTime) {
    while (camZ >= roadLength * segmentLength) {
        camZ -= roadLength * segmentLength;
        stageNumber++;
    }
    while (camZ < 0) camZ += roadLength * segmentLength;
    float maxY = SCREEN_HEIGHT;
    int initPos = (int)(camZ / segmentLength);
    Segment* s = segments[initPos];
    DrawBackground(s->curve*deltaTime);
    App->player->CentripetalForce(-s->curve * deltaTime);
    camY = (1500 + s->wY);
    offsetX = 0;
    roadX = 0;
    // Draw Road
    for (int i = initPos + 1; i < initPos + segmentsToDraw; ++i) {
        Segment *thisS = segments[i%roadLength];
        WorldToScreen(*thisS, (i >= (int)roadLength));
        roadX += offsetX;
        offsetX += thisS->curve;
        thisS->cc = (float)maxY;
        if ((thisS->sY < maxY)) {
            maxY = thisS->sY;
            Segment *previousS = segments[(i - 1) % roadLength];
            DrawTrack((previousS), (thisS), ((i / 3) % 2 == 0));
        }      
    }
    //Draw Objects
    for (int i = initPos + 100; i >= initPos; i--) {
        DrawObjects(segments[i%roadLength]);
    }
    if (state == Intro) {
        App->renderer->Blit(textureObjects, 56, 190, &semaphore.GetCurrentFrame(), 0, 1.225f, 0.95f);
    }
    //Draw Enemies
    if (state == Intro || state == Race) {
        for (int i = enemies.size() - 1; i >= 0; i--) {
            DrawEnemy(enemies[i]);
        }
    }

}

void ModuleSceneBase::DrawTrack(const Segment* s1, const Segment* s2, bool colorOne) {
    assert(s1 != nullptr);
    assert(s2 != nullptr);
    Sint16 p1x = (Sint16)s1->sX;
    Sint16 p1y = (Sint16)s1->sY;
    Sint16 p1w = (Sint16)s1->sZ;
    Sint16 p2x = (Sint16)s2->sX;
    Sint16 p2y = (Sint16)s2->sY;
    Sint16 p2w = (Sint16)s2->sZ;
    if (colorOne) {
        App->renderer->DrawSegment(brownDark, SCREEN_WIDTH / 2, p1y, SCREEN_WIDTH, SCREEN_WIDTH / 2, p2y, SCREEN_WIDTH);
        App->renderer->DrawSegment(roadColor, p1x, p1y, p1w, p2x, p2y, p2w);

        App->renderer->DrawSegment(white, p1x, p1y, (Sint16)(p1w * SMALL_RUMBLE_PROPORTION), p2x, p2y, (Sint16)(p2w * SMALL_RUMBLE_PROPORTION));

        App->renderer->DrawSegment(greyDark, p1x - p1w - (Sint16)(p1w * SMALL_RUMBLE_PROPORTION), p1y, (Sint16)(p1w * SMALL_RUMBLE_PROPORTION), p2x - p2w - (Sint16)(p2w * SMALL_RUMBLE_PROPORTION), p2y, (Sint16)(p2w * SMALL_RUMBLE_PROPORTION));
        App->renderer->DrawSegment(greyDark, p1x + p1w + (Sint16)(p1w * SMALL_RUMBLE_PROPORTION), p1y, (Sint16)(p1w * SMALL_RUMBLE_PROPORTION), p2x + p2w + (Sint16)(p2w * SMALL_RUMBLE_PROPORTION), p2y, (Sint16)(p2w * SMALL_RUMBLE_PROPORTION));

        App->renderer->DrawSegment(white, p1x - p1w - (Sint16)(p1w * SMALL_RUMBLE_PROPORTION) - (Sint16)(p1w * BIG_RUMBLE_PROPORTION), p1y, (Sint16)(p1w * BIG_RUMBLE_PROPORTION), p2x - p2w - (Sint16)(p2w * SMALL_RUMBLE_PROPORTION) - (Sint16)(p2w * BIG_RUMBLE_PROPORTION), p2y, (Sint16)(p2w * BIG_RUMBLE_PROPORTION));
        App->renderer->DrawSegment(white, p1x + p1w + (Sint16)(p1w * SMALL_RUMBLE_PROPORTION) + (Sint16)(p1w * BIG_RUMBLE_PROPORTION), p1y, (Sint16)(p1w * BIG_RUMBLE_PROPORTION), p2x + p2w + (Sint16)(p2w * SMALL_RUMBLE_PROPORTION) + (Sint16)(p2w * BIG_RUMBLE_PROPORTION), p2y, (Sint16)(p2w * BIG_RUMBLE_PROPORTION));

    } else {
        App->renderer->DrawSegment(brownLight, SCREEN_WIDTH / 2, p1y, SCREEN_WIDTH, SCREEN_WIDTH / 2, p2y, SCREEN_WIDTH);
        App->renderer->DrawSegment(roadColor, p1x, p1y, p1w, p2x, p2y, p2w);

        App->renderer->DrawSegment(white, p1x - p1w - (Sint16)(p1w * SMALL_RUMBLE_PROPORTION), p1y, (Sint16)(p1w * SMALL_RUMBLE_PROPORTION), p2x - p2w - (Sint16)(p2w * SMALL_RUMBLE_PROPORTION), p2y, (Sint16)(p2w * SMALL_RUMBLE_PROPORTION));
        App->renderer->DrawSegment(white, p1x + p1w + (Sint16)(p1w * SMALL_RUMBLE_PROPORTION), p1y, (Sint16)(p1w * SMALL_RUMBLE_PROPORTION), p2x + p2w + (Sint16)(p2w * SMALL_RUMBLE_PROPORTION), p2y, (Sint16)(p2w * SMALL_RUMBLE_PROPORTION));

        App->renderer->DrawSegment(greyDark, p1x - p1w - (Sint16)(p1w * SMALL_RUMBLE_PROPORTION) - (Sint16)(p1w * BIG_RUMBLE_PROPORTION), p1y, (Sint16)(p1w * BIG_RUMBLE_PROPORTION), p2x - p2w - (Sint16)(p2w * SMALL_RUMBLE_PROPORTION) - (Sint16)(p2w * BIG_RUMBLE_PROPORTION), p2y, (Sint16)(p2w * BIG_RUMBLE_PROPORTION));
        App->renderer->DrawSegment(greyDark, p1x + p1w + (Sint16)(p1w * SMALL_RUMBLE_PROPORTION) + (Sint16)(p1w * BIG_RUMBLE_PROPORTION), p1y, (Sint16)(p1w * BIG_RUMBLE_PROPORTION), p2x + p2w + (Sint16)(p2w * SMALL_RUMBLE_PROPORTION) + (Sint16)(p2w * BIG_RUMBLE_PROPORTION), p2y, (Sint16)(p2w * BIG_RUMBLE_PROPORTION));
    }
}

void ModuleSceneBase::DrawObjects(const Segment* s) {
    if (s->spriteID != 999) {
        SDL_Rect sprite = objects[s->spriteID];
        float scale = s->sZ / SEGMENT_LENGTH;
        float destY = s->sY - sprite.h * scale;
        float destX = s->sX + (s->sZ * s->spriteX);
        int destH = (int)(sprite.h * scale);
        if (destY + destH > s->cc) {
            float clipH = destY + destH - s->cc;
            sprite.h = (int)(sprite.h - sprite.h * clipH / destH);
        }
        if (scale <= 2.5f) {
            App->renderer->Blit(textureObjects, destX - (sprite.w * scale)/2, (int)destY, &sprite, 0.0f, scale);
        }     
        int initPos = (int)(camZ / segmentLength);
        if (s->collides && scale > 1 && App->player->stateRace == RUNNING) {
            SDL_Rect collision = { destX - (sprite.w * scale) / 2, destY + sprite.h * scale,sprite.w * scale, -destH };
            App->player->Collision(collision);
        }
    }
}

void ModuleSceneBase::DrawEnemy(const Enemy* e) { 
    Segment* s = segments[(int)e->z % roadLength];
    SDL_Rect sprite = e->currentAnimation->GetCurrentFrame();
    float scale = s->sZ / (SEGMENT_LENGTH + 90);
    float destY = s->sY - sprite.h * scale + 3;
    float destX = s->sX + (s->sZ * e->x);
    int destH = (int)(sprite.h * scale);
    if (destY + destH > s->cc) {
        float clipH = destY + destH - s->cc;
        sprite.h = (int)(sprite.h - sprite.h * clipH / destH);
    }
    if (scale <= 1.5f) {
        App->renderer->Blit(guiTexture, destX - (sprite.w * scale) / 2, (int)destY, &sprite, 0.0f, scale);
    }
    int initPos = (int)(camZ / segmentLength);
    if (e->z > initPos + 1 && scale > 1 && App->player->stateRace == RUNNING) {
        SDL_Rect collision = { destX - (sprite.w * scale) / 2, destY + sprite.h * scale,sprite.w * scale, -destH };
        App->player->Collision(collision);
    }

}

void ModuleSceneBase::UpdateEnemy(Enemy* e, float deltaTime) {
    e->z += e->speed * deltaTime;
    while (e->z < 0) e->z += roadLength * segmentLength;
    Segment* s = segments[(int)e->z % roadLength];
    if (s->curve > 3.0f) {
        if (e->state != 3) {
            e->timeOnAnim += deltaTime;
            if (e->timeOnAnim > SWAP_ANIM) {
                e->state++;
                e->timeOnAnim = 0.0f;
            }
        }
    } else if (s->curve > 1.5f) {
        if (e->state != 2) {
            e->timeOnAnim += deltaTime;
            if (e->timeOnAnim > SWAP_ANIM) {
                if (e->state > 2) {
                    e->state--;
                } else {
                    e->state++;
                }
                e->timeOnAnim = 0.0f;
            }

        }
    } else if (s->curve > 0.0f) {
        if (e->state != 1) {
            e->timeOnAnim += deltaTime;
            if (e->timeOnAnim > SWAP_ANIM) {
                if (e->state > 1) {
                    e->state--;
                } else {
                    e->state++;
                }
                e->timeOnAnim = 0.0f;
            }
        }
    } else if (s->curve == 0.0f) {
        if (e->state != 0) {
            e->timeOnAnim += deltaTime;
            if (e->timeOnAnim > SWAP_ANIM) {
                if (e->state > 0) {
                    e->state--;
                } else {
                    e->state++;
                }
                e->timeOnAnim = 0.0f;
            }
        }
    } else if (s->curve > 1.5f) {
        if (e->state != -1) {
            e->timeOnAnim += deltaTime;
            if (e->timeOnAnim > SWAP_ANIM) {
                if (e->state > -1) {
                    e->state--;
                } else {
                    e->state++;
                }
                e->timeOnAnim = 0.0f;
            }
        }
    } else if (s->curve > -3.0f) {
        if (e->state != -2) {
            e->timeOnAnim += deltaTime;
            if (e->timeOnAnim > SWAP_ANIM) {
                if (e->state > -2) {
                    e->state--;
                } else {
                    e->state++;
                }
                e->timeOnAnim = 0.0f;
            }
        }
    } else {
        if (e->state != -3) {
            e->timeOnAnim += deltaTime;
            if (e->timeOnAnim > SWAP_ANIM) {
                e->state--;
                e->timeOnAnim = 0.0f;
            }
        }
    }
    if (e->isYellow) {
        switch (e->state) {
        case LEFT_THREE:
            e->currentAnimation = &yellowLeftThree;
            break;
        case LEFT_TWO:
            e->currentAnimation = &yellowLeftTwo;
            break;
        case LEFT_ONE:
            e->currentAnimation = &yellowLeftOne;
            break;
        case STRAIGHT:
            e->currentAnimation = &yellowStraight;
            break;
        case RIGHT_ONE:
            e->currentAnimation = &yellowRightOne;
            break;
        case RIGHT_TWO:
            e->currentAnimation = &yellowRightTwo;
            break;
        case RIGHT_THREE:
            e->currentAnimation = &yellowRightThree;
            break;
        default:
            break;
        }
    } else {
        switch (e->state) {
        case LEFT_THREE:
            e->currentAnimation = &greenLeftThree;
            break;
        case LEFT_TWO:
            e->currentAnimation = &greenLeftTwo;
            break;
        case LEFT_ONE:
            e->currentAnimation = &greenLeftOne;
            break;
        case STRAIGHT:
            e->currentAnimation = &greenStraight;
            break;
        case RIGHT_ONE:
            e->currentAnimation = &greenRightOne;
            break;
        case RIGHT_TWO:
            e->currentAnimation = &greenRightTwo;
            break;
        case RIGHT_THREE:
            e->currentAnimation = &greenRightThree;
            break;
        default:
            break;
        }
    }
}

void ModuleSceneBase::WorldToScreen(Segment &s, bool b) {
    float cameraX = s.wX - (int)(App->player->xPos - roadX);
    float cameraY = s.wY - camY;
    float cameraZ = s.wZ - (camZ - (b ? roadLength*segmentLength : 0));
    s.scale = camDepth / cameraZ;   
    s.sX = ((1.0f + (s.scale * cameraX)) * (SCREEN_WIDTH / 2.0f));
    s.sY = ((1.0f - (s.scale * cameraY)) * (SCREEN_HEIGHT / 1.8f));
    s.sZ = (s.scale*roadWidth * (SCREEN_WIDTH / 1.8f));
}

void ModuleSceneBase::RecalculatePosition(float speed) {
    wPosZ += speed;
    while (wPosZ > segmentLength) {
        int n = (int)(wPosZ / segmentLength);
        wPosZ -= n * segmentLength;
        camZ += n * segmentLength;
    }
}

void ModuleSceneBase::Hill(const Segment* a, Segment* b, float value, float length, float height) {
    assert(a != nullptr);
    assert(b != nullptr);
    float previousY = a->wY;
    float newY = previousY + height * cos(value * length * 0.001f);
    b->wY = newY;
}


bool ModuleSceneBase::CleanUp() {
    return true;
}

void ModuleSceneBase::SetUpGUI() {
    speedNumberPos.x = SCREEN_WIDTH * 8 / 10 + 35;
    speedNumberPos.y = SCREEN_HEIGHT / 8;

    scorePos.x = SCREEN_WIDTH * 6 / 10;
    scorePos.y = SCREEN_HEIGHT / 20;

    timePos.x = SCREEN_WIDTH / 2 - time.w / 2;
    timePos.y = SCREEN_HEIGHT / 20;

    coursePos.x = SCREEN_WIDTH / 10;
    coursePos.y = SCREEN_HEIGHT / 8;

    stagePos.x = SCREEN_WIDTH / 10;
    stagePos.y = SCREEN_HEIGHT / 6;

    africaPos.x = SCREEN_WIDTH / 4 + 10;
    africaPos.y = SCREEN_HEIGHT / 8;

    topPos.x = SCREEN_WIDTH / 10;
    topPos.y = SCREEN_HEIGHT / 20;

    speedPos.x = SCREEN_WIDTH * 6 / 10 + 15;
    speedPos.y = SCREEN_HEIGHT / 8;

    kmPos.x = SCREEN_WIDTH * 8 / 10 + 35;
    kmPos.y = SCREEN_HEIGHT / 8;

    sgPos.x = SCREEN_WIDTH / 20;
    sgPos.y = SCREEN_HEIGHT / 5 + 5;

    topNumberPos.x = SCREEN_WIDTH / 2 - 80;
    topNumberPos.y = SCREEN_HEIGHT / 20 + 3;

    stageNumberPos.x = SCREEN_WIDTH / 4 + 25;
    stageNumberPos.y = SCREEN_HEIGHT / 6;

    countdownPos.x = SCREEN_WIDTH / 2 + 17;
    countdownPos.y = SCREEN_HEIGHT / 8;

    scoreNumberPos.x = SCREEN_WIDTH * 19 / 20;
    scoreNumberPos.y = SCREEN_HEIGHT / 20;

    sky.x = 0;
    sky.y = 0;
    sky.w = SCREEN_WIDTH;
    sky.h = SCREEN_HEIGHT;
}


void ModuleSceneBase::DrawGUI() {
    App->font->DrawText(App->font->redFont, to_string((int)App->player->speed).c_str(), speedNumberPos.x, speedNumberPos.y);
    App->font->DrawText(App->font->greenFont, to_string((int)App->player->score).c_str(), scoreNumberPos.x, scoreNumberPos.y);
    App->font->DrawText(App->font->countdownFont, to_string((int)countdown).c_str(), countdownPos.x, countdownPos.y);
    App->font->DrawText(App->font->whiteFont, to_string((int)stageNumber).c_str(), stageNumberPos.x, stageNumberPos.y);
    App->font->DrawText(App->font->redFont, to_string(App->topScore).c_str(), topNumberPos.x, topNumberPos.y);
    App->renderer->Blit(guiTexture, scorePos.x, scorePos.y, &score,0);
    App->renderer->Blit(guiTexture, timePos.x, timePos.y, &time,0);
    App->renderer->Blit(guiTexture, coursePos.x, coursePos.y, &course,0);
    App->renderer->Blit(guiTexture, stagePos.x, stagePos.y, &stage,0);
    App->renderer->Blit(guiTexture, africaPos.x, africaPos.y, &africa,0);
    App->renderer->Blit(guiTexture, topPos.x, topPos.y, &top, 0);
    App->renderer->Blit(guiTexture, speedPos.x, speedPos.y, &speed, 0);
    App->renderer->Blit(guiTexture, kmPos.x, kmPos.y, &km, 0);
    App->renderer->Blit(guiTexture, sgPos.x, sgPos.y, &sg, 0);
    if (state == GameOver) {
        if ((int)(timer * 10) / 3 % 2 == 0) {
            App->renderer->Blit(guiTexture, SCREEN_WIDTH / 2 - gameOver.w / 2, SCREEN_HEIGHT / 2, &gameOver, 0);
        }
    }
}

void ModuleSceneBase::SetUpColors() {
    roadColor = GREY_ROAD;
    blueSky = BLUE_SKY;
    white = WHITE;
    greyDark = GREY_DARK;
    brownDark = BROWN_DARK;
    brownLight = BROWN_LIGHT;
}

void ModuleSceneBase::DrawBackground(float curve) {
    int i = (int)(camZ / segmentLength) + segmentsToDraw - 5;
    i = i%roadLength;
    backgroundOffset -= curve * 1.5f;
    mountainsOffset -= curve * 3.0f;
    App->renderer->Blit(textureBackground, backgroundOffset, segments[i]->sY - 260, &background, 0);
    App->renderer->Blit(textureBackground, -background.w + backgroundOffset, segments[i]->sY-260, &background, 0);
    App->renderer->Blit(textureBackground, background.w + backgroundOffset, segments[i]->sY-260, &background, 0);
    App->renderer->Blit(textureBackground, 2 * background.w + backgroundOffset, segments[i]->sY - 260, &background, 0);
    App->renderer->Blit(textureBackground, 3 * background.w + backgroundOffset, segments[i]->sY - 260, &background, 0);
    App->renderer->Blit(textureBackground, mountainsOffset, segments[i]->sY - mountains.h, &mountains,0);
    App->renderer->Blit(textureBackground, -mountains.w + mountainsOffset, segments[i]->sY - mountains.h, &mountains,0);
    App->renderer->Blit(textureBackground, mountains.w + mountainsOffset, segments[i]->sY - mountains.h, &mountains,0);
}