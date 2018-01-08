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
#include "Segment.h"
#include "ModuleSceneAfrica.h"



ModuleSceneAfrica::ModuleSceneAfrica(bool active) : ModuleSceneBase(active) {

}


ModuleSceneAfrica::~ModuleSceneAfrica() {
}

bool ModuleSceneAfrica::Start() {
    ModuleSceneBase::Start();
    segments.clear();
    for (int i = 0; i < 12200; i++) {
        Segment* s = new Segment();
        s->wZ = i * segmentLength;
        s->wY = (i > 0) ? (segments[i - 1])->wY : 0;
        if (i > 30) {
            if (i % 50 == 0) {
                s->spriteID = bushID;
                s->spriteX = -2;
            }
            if ((i + 8) % 50 == 0) {
                s->spriteID = bushID;
                s->spriteX = 2;
            }            
            if (i % 150 == 0) {
                s->spriteID = bushID;
                s->spriteX = -4;
            }
            if ((i + 8) % 150 == 0) {
                s->spriteID = bushID;
                s->spriteX = 4;
            }
            if ((i - 2) % 95 == 0) {
                s->spriteID = barrelID;
                s->spriteX = -3;
            }
            if ((i - 7) % 120 == 0) {
                s->spriteID = barrelID;
                s->spriteX = 2;
            }
            if (i < 8000) {
                if ((i - 4) % 190 == 0 && i > 2000) {
                    s->spriteID = rockID;
                    s->spriteX = -2;
                }
                if ((i + 3) % 184 == 0 && i > 2100) {
                    s->spriteID = rockID;
                    s->spriteX = 3;
                }
            } else {
                if ((i - 3) % 217 == 0) {
                    s->spriteID = bidalStoneID;
                    s->spriteX = 3;
                }
                if ((i - 1) % 203 == 0) {
                    s->spriteID = bidalStoneID;
                    s->spriteX = -2;
                }
            }
            if ((i - 4) % 490 == 0 && i > 8000) {
                s->spriteID = rockID;
                s->spriteX = -4;
            }
            if ((i + 3) % 584 == 0 && i > 2100) {
                s->spriteID = rockID;
                s->spriteX = 3;
            }


        }
        // 15-60  /  70-130  GOOD VALUES

        //Hills
        if (i > 130 && i < 500) Hill(segments[i - 1], s, i, 30, 90);
        if (i > 800 && i < 1300) Hill(segments[i - 1], s, i, 50, 115);
        if (i > 1500 && i < 1900) Hill(segments[i - 1], s, i, 30, 80);
        if (i > 2200 && i < 2400) Hill(segments[i - 1], s, i, 60, 90);
        if (i > 2400 && i < 2700) Hill(segments[i - 1], s, i, 25, 130);
        if (i > 2950 && i < 3200) Hill(segments[i - 1], s, i, 30, 90);
        if (i > 3200 && i < 3350) Hill(segments[i - 1], s, i, 40, 100);
        if (i > 3500 && i < 3700) Hill(segments[i - 1], s, i, 50, 115);
        if (i > 4050 && i < 4300) Hill(segments[i - 1], s, i, 30, 80);
        if (i > 4300 && i < 4600) Hill(segments[i - 1], s, i, 60, 90);
        if (i > 4800 && i < 5100) Hill(segments[i - 1], s, i, 25, 120);
        if (i > 5350 && i < 5550) Hill(segments[i - 1], s, i, 30, 90);
        if (i > 5700 && i < 5950) Hill(segments[i - 1], s, i, 40, 90);
        if (i > 6100 && i < 6350) Hill(segments[i - 1], s, i, 40, 100);
        if (i > 6400 && i < 6650) Hill(segments[i - 1], s, i, 50, 115);
        if (i > 6700 && i < 6900) Hill(segments[i - 1], s, i, 30, 80);
        if (i > 7050 && i < 7400) Hill(segments[i - 1], s, i, 60, 90);
        if (i > 7500 && i < 7900) Hill(segments[i - 1], s, i, 45, 110);
        if (i > 8100 && i < 8450) Hill(segments[i - 1], s, i, 50, 115);
        if (i > 8600 && i < 9000) Hill(segments[i - 1], s, i, 30, 80);
        if (i > 9000 && i < 9200) Hill(segments[i - 1], s, i, 40, 90);
        if (i > 9300 && i < 9650) Hill(segments[i - 1], s, i, 45, 110);
        if (i > 9700 && i < 9900) Hill(segments[i - 1], s, i, 50, 115);
        if (i > 10050 && i < 10450) Hill(segments[i - 1], s, i, 30, 80);
        if (i > 10600 && i < 11000) Hill(segments[i - 1], s, i, 40, 90);
        if (i > 11150 && i < 11500) Hill(segments[i - 1], s, i, 50, 110);
        if (i > 11600 && i < 11900) Hill(segments[i - 1], s, i, 40, 90);

        //Curves
        if (i > 0 && i < 200) s->curve = 0;
        if (i > 200 && i < 500) s->curve = 3;
        if (i > 500 && i < 700) s->curve = -5;
        if (i > 700 && i < 800) s->curve = 0;
        if (i > 800 && i < 950) s->curve = -5;
        if (i > 950 && i < 1000) s->curve = 8;
        if (i > 1000 && i < 1100) s->curve = 0;
        if (i > 1100 && i < 1400) s->curve = -6;
        if (i > 1400 && i < 1600) s->curve = 7;
        if (i > 1600 && i < 1900) s->curve = -5;
        if (i > 1900 && i < 2100) s->curve = 0;
        if (i > 2100 && i < 2300) s->curve = 7;
        if (i > 2300 && i < 2500) s->curve = -8;
        if (i > 2500 && i < 2700) s->curve = -3;
        if (i > 2700 && i < 2900) s->curve = 6;
        if (i > 2900 && i < 3050) s->curve = 0;
        if (i > 3050 && i < 3200) s->curve = 8;
        if (i > 3200 && i < 3300) s->curve = -8;
        if (i > 3300 && i < 3600) s->curve = 9;
        if (i > 3600 && i < 3800) s->curve = -8;
        if (i > 3800 && i < 3900) s->curve = 4;
        if (i > 3900 && i < 4100) s->curve = 0;
        if (i > 4100 && i < 4250) s->curve = -8;
        if (i > 4250 && i < 4400) s->curve = 7;
        if (i > 4400 && i < 4450) s->curve = 0;
        if (i > 4450 && i < 4650) s->curve = -5;
        if (i > 4650 && i < 4900) s->curve = 8;
        if (i > 4900 && i < 5100) s->curve = -7;
        if (i > 5100 && i < 5300) s->curve = 8;
        if (i > 5300 && i < 5450) s->curve = 8;
        if (i > 5450 && i < 5600) s->curve = 0;
        if (i > 5600 && i < 5800) s->curve = -8;
        if (i > 5800 && i < 5900) s->curve = 7;
        if (i > 5900 && i < 6050) s->curve = 0;
        if (i > 6050 && i < 6200) s->curve = -8;
        if (i > 6200 && i < 6400) s->curve = 7;
        if (i > 6400 && i < 6550) s->curve = -6;
        if (i > 6550 && i < 6650) s->curve = 0;
        if (i > 6650 && i < 6700) s->curve = 7;
        if (i > 6700 && i < 6800) s->curve = -8;
        if (i > 6800 && i < 6950) s->curve = -3;
        if (i > 6950 && i < 7200) s->curve = 6;
        if (i > 7200 && i < 7300) s->curve = 0;
        if (i > 7300 && i < 7400) s->curve = 8;
        if (i > 7400 && i < 7700) s->curve = -7;
        if (i > 7700 && i < 7850) s->curve = 8;
        if (i > 7850 && i < 7950) s->curve = -7;
        if (i > 7950 && i < 8050) s->curve = 0;
        if (i > 8050 && i < 8300) s->curve = 5;
        if (i > 8300 && i < 8450) s->curve = -8;
        if (i > 8450 && i < 8600) s->curve = 7;
        if (i > 8600 && i < 8700) s->curve = 0;
        if (i > 8700 && i < 8950) s->curve = -8;
        if (i > 8950 && i < 9150) s->curve = 8;
        if (i > 9150 && i < 9300) s->curve = -7;
        if (i > 9300 && i < 9500) s->curve = 8;
        if (i > 9500 && i < 9800) s->curve = -8;
        if (i > 9800 && i < 9900) s->curve = -5;
        if (i > 9900 && i < 10050) s->curve = 0;
        if (i > 10050 && i < 10250) s->curve = 7;
        if (i > 10250 && i < 10400) s->curve = -5;
        if (i > 10400 && i < 10550) s->curve = 8;
        if (i > 10550 && i < 10700) s->curve = -7;
        if (i > 10700 && i < 10850) s->curve = 8;
        if (i > 10850 && i < 11000) s->curve = -8;
        if (i > 11000 && i < 11200) s->curve = 8;
        if (i > 11200 && i < 11350) s->curve = -7;
        if (i > 11350 && i < 11500) s->curve = 6;
        if (i > 11500 && i < 11700) s->curve = 8;
        if (i > 11700 && i < 11900) s->curve = -5;
        if (i > 11900 && i < 12200) s->curve = 0;

        //Important Events
        if (i == 8) {
            s->spriteID = startSignID;
            s->spriteX = 0;
            s->collides = false;
            s->smallItem = false;
        }

        if (i == 2000) {
            s->spriteID = checkSignID;
            s->spriteX = 0;
            s->collides = false;
            s->smallItem = false;
        }

        if (i == 4000) {
            s->spriteID = checkSignID;
            s->spriteX = 0;
            s->collides = false;
            s->smallItem = false;
        }
        if (i == 6000) {
            s->spriteID = checkSignID;
            s->spriteX = 0;
            s->collides = false;
            s->smallItem = false;
        }
        if (i == 8000) {
            s->spriteID = checkSignID;
            s->spriteX = 0;
            s->collides = false;
            s->smallItem = false;
        }
        if (i == 10000) {
            s->spriteID = checkSignID;
            s->spriteX = 0;
            s->collides = false;
            s->smallItem = false;
        }
        if (i == 12000) {
            s->spriteID = goalSignID;
            s->spriteX = 0;
            s->collides = false;
            s->smallItem = false;
        }
        
        segments.push_back(s);
    }
    roadLength = segments.size();
    return true;
}