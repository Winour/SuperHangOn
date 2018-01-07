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

    void Hill(const Segment* a, Segment* b, float value, float length, float height);

    void SetUpGUI();
    void SetUpColors();

public:
    States state, nextState;

private:
    float timer;
    float countdown;
    int stageNumber;

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