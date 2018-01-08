#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleFont.h"



ModuleFont::ModuleFont(bool start_enabled) : Module(start_enabled) {
}


ModuleFont::~ModuleFont() {
}

bool ModuleFont :: CleanUp() {
    for (int i = 0; i < fonts.size(); i++) {
        App->textures->Unload(fonts[i].texture);
    }
    fonts.clear();
    return true;
}

bool ModuleFont::Start() {
    countdownFont = LoadFont("fonts/numbers18x30.png", "9876543210", 18, 30);
    yellowFont = LoadFont("fonts/numbers18x18.png", "1234567890", 16, 18);
    whiteFont = LoadFont("fonts/numbers18x18.png", "1234567890", 16, 18, 18);
    redFont = LoadFont("fonts/numbers18x18.png", "1234567890", 16, 18, 36);
    greenFont = LoadFont("fonts/numbers18x18.png", "1234567890", 16, 18, 54);
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
    for (size_t i = 0; i < strlen(text); i++) {
        SDL_Rect* n = new SDL_Rect ({ fonts[fontID].fontMap[text[i]] , fonts[fontID].initY , fonts[fontID].width , fonts[fontID].height });    
        App->renderer->Blit(fonts[fontID].texture, _posX - fonts[fontID].width * (strlen(text) - i), _posY, n, 0.0f);
        delete n;
    }
}