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

class ModuleSceneIntro;
class ModuleSceneNewGame;
class ModuleSceneMapSelection;
class ModuleSceneMusicSelection;

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

    ModuleSceneIntro* sceneIntro;
    ModuleSceneNewGame* sceneNewGame;
    ModuleSceneMapSelection* sceneMapSelection;
    ModuleSceneMusicSelection* sceneMusicSelection;

private:
	std::list<Module*> modules;
    clock_t timer = 0;
    float deltaTime = 0;
};

extern Application* App;

#endif // __APPLICATION_CPP__