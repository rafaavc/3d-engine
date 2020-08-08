#ifndef VIEW_H
#define VIEW_H

#include "controller/Engine.h"
#include "view/SDLAdapter.h"

class View {
private:
    Model * model;
    Graphics * graphics;
    Engine * engine;
public:
    View(Model * model, Engine * engine, Graphics * graphics);
    void init();
    void quit();
    Graphics::GraphicsCommand getUserInput(char * specifier);
    void draw();
};


#endif