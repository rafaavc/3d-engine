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
    void clear();
    void setDrawColor(RGBAColor color = RGBAColor(255, 255, 255));
    void drawPixel(int xpos, int ypos);
    void drawLine(int x1, int y1, int x2, int y2);
    void render();
    Graphics::GraphicsCommand getUserInput(char * specifier);
};

#endif