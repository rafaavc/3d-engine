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
    virtual void clear(RGBAColor * color) = 0;
    virtual void render() = 0;
    virtual void drawPixel(RGBAColor * color, int xpos, int ypos) = 0;
    virtual GraphicsCommand getUserInput(char * specifier) = 0;
};

#endif
