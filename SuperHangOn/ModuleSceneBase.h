#ifndef __MODULESCENEBASE_H__
#define __MODULESCENEBASE_H__

#include "Module.h"
#include "Globals.h"
#include "Point.h"
#include <vector>


class Segment;

enum States {
    Intro,
    Race,
    Finish,
    GameOver
};

struct Enemy {
    enum RunningStates {
        LEFT_THREE = -3,
        LEFT_TWO,
        LEFT_ONE,
        STRAIGHT,
        RIGHT_ONE,
        RIGHT_TWO,
        RIGHT_THREE,
    };
    int state = STRAIGHT;
    Animation* currentAnimation = nullptr;
    bool isYellow = false;
    float x = 0;
    float z = 0;
    float speed = 90.0f;
    float timer = 0.0f;
    float timeOnAnim = 0.0f;
};

class ModuleSceneBase : public Module {
public:
    ModuleSceneBase(bool active = true);
    ~ModuleSceneBase();

    bool Start();
    update_status Update(float deltaTime);
    bool CleanUp();

private:
    void DrawGUI();
    void DrawRoad(float deltaTime);
    void DrawTrack(const Segment* s1, const Segment* s2, bool colorOne);
    void DrawBackground(float curve);
    void DrawObjects(const Segment* s);

    void WorldToScreen(Segment &s, bool b);
    void RecalculatePosition(float speed);
    void UpdateEnemy(Enemy* e, float deltaTime);

    void Hill(const Segment* a, Segment* b, float value, float length, float height);

    void SetUpGUI();
    void SetUpColors();

public:
    States state, nextState;

private:
    float timer, timerSemaphore;
    float countdown;
    int stageNumber;
    int beamNumber;

private: //Enemy
    std::vector<Enemy*> enemies;

    Animation greenStraight;
    Animation greenLeftOne;
    Animation greenLeftTwo;
    Animation greenLeftThree;
    Animation greenRightOne;
    Animation greenRightTwo;
    Animation greenRightThree;

    Animation yellowStraight;
    Animation yellowLeftOne;
    Animation yellowLeftTwo;
    Animation yellowLeftThree;
    Animation yellowRightOne;
    Animation yellowRightTwo;
    Animation yellowRightThree;

    void DrawEnemy(const Enemy* e);

private: // Road
    SDL_Rect sky;
    SDL_Texture* textureBackground = nullptr;
    SDL_Texture* textureObjects = nullptr;
    SDL_Rect background;
    SDL_Rect mountains;
    std::vector<Segment*> segments;
    const float roadWidth = ROAD_WIDTH;
    const float segmentLength = SEGMENT_LENGTH;
    const int segmentsToDraw = 90;
    float roadX = 0.0f;
    float roadY = 0.0f;
    float backgroundOffset = 0.0f;
    float mountainsOffset = 0.0f;
    unsigned int roadLength = 0;
    unsigned int finishID;
    bool goal = false;
    SDL_Color roadColor, blueSky, white, greyDark, brownDark, brownLight;
    std::vector<SDL_Rect> objects;
    unsigned int bushID, signLeftID, signRightID, barrelID, bidalStoneID, rockID, startSignID, checkSignID, goalSignID, peopleID;
    Animation semaphore;

private: //Sounds
    unsigned int semaphoreFX, semaphoreFinalFX, loadTrackFX, engineFX, outOfRoadFX, colisionFX, lapFX;

private: //Camera
    const float camDepth = CAMERA_DEPTH;
    float camY = 1500.0f;
    float camZ = 0.0f;
    float wPosZ = 0.0f;
    float offsetX = 0.0f;

private: //GUI
    SDL_Texture* guiTexture;
    SDL_Rect score;
    SDL_Rect time;
    SDL_Rect course;
    SDL_Rect stage;
    SDL_Rect africa;
    SDL_Rect top;
    SDL_Rect speed;
    SDL_Rect km;
    SDL_Rect sg;

    iPoint scorePos;
    iPoint timePos;
    iPoint coursePos;
    iPoint stagePos;
    iPoint africaPos;
    iPoint topPos;
    iPoint kmPos;
    iPoint sgPos;
    iPoint speedPos;
    iPoint speedNumberPos;
    iPoint topNumberPos;
    iPoint stageNumberPos;
    iPoint countdownPos;
    iPoint scoreNumberPos;
};

#endif // !__MODULESCENEBASE_H__