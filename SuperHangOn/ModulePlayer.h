#ifndef __MODULEPLAYER_H__
#define __MODULEPLAYER_H__

#include "Module.h"
#include "Point.h"

class Animation;

struct SDL_Texture;

enum RunningStates {
    LEFT_THREE = -3,
    LEFT_TWO,
    LEFT_ONE,
    STRAIGHT,
    RIGHT_ONE,
    RIGHT_TWO,
    RIGHT_THREE,
};

class ModulePlayer : public Module {
public:
    ModulePlayer(bool active = true);
    ~ModulePlayer();

    bool Start();
    update_status Update(float deltaTime);
    bool CleanUp();
    void CentripetalForce(float value);

public:
    float speed;
    float xPos = 0.0f;

private:
    void RecalculatePos();

private:
    SDL_Texture* texture = nullptr;
    Animation* currentAnimation = nullptr;
    Animation turnRightThree;
    Animation turnRightTwo;
    Animation turnRightOne;
    Animation straight;
    Animation turnLeftOne;
    Animation turnLeftTwo;
    Animation turnLeftThree;
    Animation turboRightThree;
    Animation turboRightTwo;
    Animation turboRightOne;
    Animation turboStraight;
    Animation turboLeftOne;
    Animation turboLeftTwo;
    Animation turboLeftThree;

    iPoint position;


    int state;
    float timer;
    bool animChange = false;
    bool turbo = false;




};

#endif // !__MODULEPLAYER_H__