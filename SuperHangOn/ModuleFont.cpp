#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleFont.h"



ModuleFont::ModuleFont(bool start_enabled) : Module(start_enabled) {
}


ModuleFont::~ModuleFont() {
}

bool ModuleFont::Start() {
    return true;
}
update_status ModuleFont::Update(float deltaTime) {
    return UPDATE_CONTINUE;
}
bool ModuleFont::CleanUp() {
    return true;
}

unsigned int ModuleFont::LoadFont(const char* filePath, const char* style, int _width, int _height, int _initY) {
    Font f;
    f.texture = App->textures->Load(filePath);
    f.width = _width;
    f.height = _height;
    f.initY = _initY;
    for (int i = 0; style[i] != '\0'; i++) {
        f.fontMap[style[i]] = i * _width;
    }
    fonts.push_back(f);
    // Returns font ID
    return fonts.size() - 1;
}

void ModuleFont::DrawText(unsigned int fontID, const char* text, int _posX, int _posY) {
    for (int i = 0; i < strlen(text); i++) {
        SDL_Rect* n = new SDL_Rect ({fonts[fontID].fontMap[text[i]], 0, fonts[fontID].width, fonts[fontID].height });    
        App->renderer->Blit(fonts[fontID].texture, _posX + fonts[fontID].width * i, _posY, n);
        delete n;
    }
}