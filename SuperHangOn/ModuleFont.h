#ifndef __MODULEFONT_H__
#define __MODULEFONT_H__

#include <map>
#include <vector>

#include "Module.h"

struct SDL_Surface;
struct SDL_Texture;

struct Font {
    Uint8 width;
    Uint8 height;
    Uint8 initY;
    SDL_Texture* texture = nullptr;
    std::map<char, int> fontMap;
};

class ModuleFont : public Module{
public:
    ModuleFont(bool start_enabled = true);
    ~ModuleFont();

    bool Start();
    update_status Update(float deltaTime);
    bool CleanUp();
    unsigned int LoadFont(const char* filePath, const char* style, int _width, int _heigth, int _initY = 0);
    void DrawText(unsigned int fontID, const char* text, int _posX, int _posY);


public:
    std::vector<Font> fonts;

};

#endif // !__MODULEFONT_H__