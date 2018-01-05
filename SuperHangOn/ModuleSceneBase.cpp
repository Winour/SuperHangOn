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

}


ModuleSceneBase::~ModuleSceneBase() {
}

bool ModuleSceneBase::Start() {
    App->player->Enable();
    textureBackground = App->textures->Load("sprites/backgrounds.png");
    guiTexture = App->textures->Load("sprites/map&players.png");
    SetUpGUI();
    SetUpColors();
    stageNumber = 1;
    timer = 5.0f;
    countdown = 50.0f;
    state = nextState = Intro;
    for (int i = 0; i < 1000; i++) {
        Segment* s = new Segment();
        s->wZ = i * segmentLength;
        s->wY = (i > 0) ? (segments[i - 1])->wY : 0;
        if (i % 50 == 0) {
            s->spriteID = 1;
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
            timer -= deltaTime;
            if (timer < 0.0f) {
                nextState = Race;
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
            break;

        case Finish:

            break;

        case GameOver:

            break;

        default:
            break;

    }
    state = nextState;
    RecalculatePosition(App->player->speed * deltaTime * 55);
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
    if (s->spriteID != 0) {

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