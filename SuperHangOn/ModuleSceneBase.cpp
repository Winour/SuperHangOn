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
}


ModuleSceneBase::~ModuleSceneBase() {
}

bool ModuleSceneBase::Start() {
    SetUpGUIPos();
    SetUpColors();
    for (int i = 0; i < 1000; i++) {
        if ((i / 500) % 2 == 0) {
            Segment* s = new Segment();
            s->wZ = i * segmentLength;
            s->wY = (i > 0) ? (segments[i - 1])->wY : 0;
            s->curve = 10.0f;
            segments.push_back(s);
        } else {
            Segment* s = new Segment();
            s->wZ = i * segmentLength;
            s->wY = (i > 0) ? (segments[i - 1])->wY : 0;
            s->curve = -5.0f;
            segments.push_back(s);
        }
    }
    roadLength = segments.size();
    return true;
}
update_status ModuleSceneBase::Update(float deltaTime) {
    App->renderer->DrawQuad(sky, blueSky.r, blueSky.g, blueSky.b, blueSky.a, false);
    RecalculatePosition(App->player->speed * deltaTime * 55);
    DrawRoad(deltaTime);
    DrawGUI();
    return UPDATE_CONTINUE;
}

void ModuleSceneBase::DrawGUI() {
    App->font->DrawText(App->font->redFont, to_string((int)App->player->speed).c_str(), speedPos.x, speedPos.y);

}

void ModuleSceneBase::DrawRoad(float deltaTime) {
    while (camZ >= roadLength * 200) camZ -= roadLength * segmentLength;
    while (camZ < 0) camZ += roadLength * segmentLength;
    float maxY = SCREEN_HEIGHT;
    int initPos = (int)(camZ / segmentLength);
    Segment* s = segments[initPos];
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

        App->renderer->DrawSegment(greyDark, p1x - p1w - (Sint16)(p1w * SMALL_RUMBLE_PROPORTION) - (Sint16)(p1w * BIG_RUMBLE_PROPORTION), p1y, (Sint16)(p1w * BIG_RUMBLE_PROPORTION), p2x - p2w - (Sint16)(p2w * SMALL_RUMBLE_PROPORTION) - (Sint16)(p2w * BIG_RUMBLE_PROPORTION), y2, (Sint16)(p2w * BIG_RUMBLE_PROPORTION));
        App->renderer->DrawSegment(greyDark, p1x + p1w + (Sint16)(p1w * SMALL_RUMBLE_PROPORTION) + (Sint16)(p1w * BIG_RUMBLE_PROPORTION), p1y, (Sint16)(p1w * BIG_RUMBLE_PROPORTION), p2x + p2w + (Sint16)(p2w * SMALL_RUMBLE_PROPORTION) + (Sint16)(p2w * BIG_RUMBLE_PROPORTION), y2, (Sint16)(p2w * BIG_RUMBLE_PROPORTION));

    }
}

void ModuleSceneBase::WorldToScreen(Segment &s, bool b) {
    float cameraX = s.wX - (int)(App->player->xPos - roadX);
    float cameraY = s.wY - camY;
    float cameraZ = s.wZ - (camZ - (b ? roadLength*segmentLength : 0));
    s.scale = camDepth / cameraZ;   
    s.sX = ((1.0f + (s.scale * cameraX)) * (SCREEN_WIDTH / 1.8f));
    s.sY = ((1.0f - (s.scale * cameraY)) * (SCREEN_HEIGHT / 1.8f));
    s.sZ = (s.scale*roadWidth * (SCREEN_WIDTH / 2));
}

void ModuleSceneBase::RecalculatePosition(float speed) {
    wPosZ += speed;
    while (wPosZ > segmentLength) {
        int n = (int)(wPosZ / segmentLength);
        wPosZ -= n * segmentLength;
        camZ += n * segmentLength;
    }
}


bool ModuleSceneBase::CleanUp() {
    return true;
}

void ModuleSceneBase::SetUpGUIPos() {
    speedPos.x = SCREEN_WIDTH - 20;
    speedPos.y = 100;

    sky.x = 0;
    sky.y = 0;
    sky.w = SCREEN_WIDTH;
    sky.h = SCREEN_HEIGHT;
}

void ModuleSceneBase::SetUpColors() {
    roadColor = GREY_ROAD;
    blueSky = BLUE_SKY;
    white = WHITE;
    greyDark = GREY_DARK;
    brownDark = BROWN_DARK;
    brownLight = BROWN_LIGHT;
}