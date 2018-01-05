#ifndef __APPLICATION_CPP__
#define __APPLICATION_CPP__

#include<list>
#include<time.h>
#include "Globals.h"
#include "Module.h"

class ModuleRender;
class ModuleWindow;
class ModuleTextures;
class ModuleInput;
class ModuleAudio;
class ModuleFadeToBlack;
class ModuleCollision;
class ModuleParticles;
class ModuleFont;

class ModuleSceneIntro;
class ModuleSceneNewGame;
class ModuleSceneMapSelection;
class ModuleSceneMusicSelection;
class ModuleSceneAfrica;

class ModulePlayer;

class Application {
public:
	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

public:
	ModuleRender* renderer;
	ModuleWindow* window;
	ModuleTextures* textures;
	ModuleInput* input;
	ModuleAudio* audio;
	ModuleFadeToBlack* fade;
	ModuleCollision* collision;
	ModuleParticles* particles;
    ModuleFont* font;

    ModuleSceneIntro* sceneIntro;
    ModuleSceneNewGame* sceneNewGame;
    ModuleSceneMapSelection* sceneMapSelection;
    ModuleSceneMusicSelection* sceneMusicSelection;
    ModuleSceneAfrica* sceneAfrica;

    ModulePlayer* player;

    Uint8 musicSelected = 0;
    unsigned int topScore = 1000000;

private:
	std::list<Module*> modules;
    clock_t timer = 0;
    float deltaTime = 0;
};

extern Application* App;

#endif // __APPLICATION_CPP__