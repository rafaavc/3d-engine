#ifndef SDLADAPTER_H
#define SDLADAPTER_H

#include "Graphics.h"
#include "SDL.h"

using namespace std;

class SDLAdapter : public Graphics {
private:
    SDL_Window * window = nullptr;
    SDL_Surface * screen = nullptr;
    SDL_Renderer * renderer = nullptr;
public:
    void initGraphics(string windowTitle, int width, int height);
    void quitGraphics();
    void setDrawColor(RGBAColor * color);
    void clear(RGBAColor * color);
    void drawPixel(RGBAColor * color, int xpos, int ypos);
    void render();
    Graphics::GraphicsCommand getUserInput(char * specifier);
};

#endif