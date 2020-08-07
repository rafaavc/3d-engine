#ifndef ENGINE_H
#define ENGINE_H

#include "view/SDLAdapter.h"
#include "model/Model.h"
#include "model/Scene.h"

class Engine {
private:
    Model * model;
    Graphics * graphics;
public:
    Engine(Model * model, Graphics * graphics, Scene * scene);
    void render();
};

#endif
