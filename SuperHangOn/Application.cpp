#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleFont.h"

#include "ModuleSceneIntro.h"
#include "ModuleSceneNewGame.h"
#include "ModuleSceneMapSelection.h"
#include "ModuleSceneMusicSelection.h"
#include "ModuleSceneAfrica.h"

#include "ModulePlayer.h"


using namespace std;

Application::Application()
{
	// Order matters: they will init/start/pre/update/post in this order
	modules.push_back(input = new ModuleInput());
	modules.push_back(window = new ModuleWindow());

	modules.push_back(renderer = new ModuleRender());
	modules.push_back(textures = new ModuleTextures());
	modules.push_back(audio = new ModuleAudio());
    modules.push_back(font = new ModuleFont());

	// Game Modules
    modules.push_back(sceneIntro = new ModuleSceneIntro(false));
    modules.push_back(sceneNewGame = new ModuleSceneNewGame(false));
    modules.push_back(sceneMapSelection = new ModuleSceneMapSelection(false));
    modules.push_back(sceneMusicSelection = new ModuleSceneMusicSelection(false));
    modules.push_back(sceneAfrica = new ModuleSceneAfrica(false));

    modules.push_back(player = new ModulePlayer(false));

	// Modules to draw on top of game logic
	modules.push_back(fade = new ModuleFadeToBlack());
}

Application::~Application()
{
	for(list<Module*>::iterator it = modules.begin(); it != modules.end(); ++it)
		RELEASE(*it);
}

bool Application::Init()
{
	bool ret = true;

	for(list<Module*>::iterator it = modules.begin(); it != modules.end() && ret; ++it)
		ret = (*it)->Init(); // we init everything, even if not anabled

	for(list<Module*>::iterator it = modules.begin(); it != modules.end() && ret; ++it)
	{
		if((*it)->IsEnabled() == true)
			ret = (*it)->Start();
	}

	// Start the first scene --
	fade->FadeToBlack(sceneNewGame, nullptr, 0.5f);

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;
    clock_t now = clock();
    deltaTime += (float)(now - timer) / CLOCKS_PER_SEC;
    if (deltaTime > 1 / FPS) {
        timer = now;
        for (list<Module*>::iterator it = modules.begin(); it != modules.end() && ret == UPDATE_CONTINUE; ++it)
            if ((*it)->IsEnabled() == true)
                ret = (*it)->PreUpdate(deltaTime);

        for (list<Module*>::iterator it = modules.begin(); it != modules.end() && ret == UPDATE_CONTINUE; ++it)
            if ((*it)->IsEnabled() == true)
                ret = (*it)->Update(deltaTime);

        for (list<Module*>::iterator it = modules.begin(); it != modules.end() && ret == UPDATE_CONTINUE; ++it)
            if ((*it)->IsEnabled() == true)
                ret = (*it)->PostUpdate(deltaTime);
        deltaTime = 0;
    }
    LOG("Time since last frame = %f", (float)(clock() - now));
	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for(list<Module*>::reverse_iterator it = modules.rbegin(); it != modules.rend() && ret; ++it)
		if((*it)->IsEnabled() == true) 
			ret = (*it)->CleanUp();

	return ret;
}