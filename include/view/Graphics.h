#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>
#include <iostream>
#include "model/RGBAColor.h"

using namespace std;

class Graphics {
public:
    enum GraphicsCommand {
        NONE,
        QUIT,
        KEYPRESS,
        KEYRELEASE
    };
    
    virtual void initGraphics(string windowTitle, int width, int height) = 0;
    virtual void quitGraphics() = 0;
    virtual void render() = 0;
    virtual void clear() = 0;
    virtual void setDrawColor(RGBAColor color = RGBAColor(255, 255, 255)) = 0;
    virtual void drawPixel(int xpos, int ypos) = 0;
    virtual void drawLine(int x1, int y1, int x2, int y2) = 0;
    virtual GraphicsCommand getUserInput(char * specifier) = 0;
};

#endif
