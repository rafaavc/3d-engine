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
    void clear(RGBAColor color = RGBAColor(0, 0, 0));
    void setDrawColor(RGBAColor color = RGBAColor(255, 255, 255));
    void drawPixel(int xpos, int ypos, RGBAColor color = RGBAColor(255, 255, 255));
    void drawLine(int x1, int y1, int x2, int y2, RGBAColor color = RGBAColor(255, 255, 255));
    void render();
    Graphics::GraphicsCommand getUserInput(char * specifier);
};

#endif