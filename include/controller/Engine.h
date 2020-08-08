#ifndef ENGINE_H
#define ENGINE_H

#include "view/SDLAdapter.h"
#include "model/Model.h"
#include "model/Scene.h"
#include "controller/TransformationMatrix.h"

class Engine {
private:
    Model * model;
    Graphics * graphics;
    Scene * scene;
    Matrix4x4 projMatrix;
    float timeVal = 0;
public:
    Engine(Model * model, Graphics * graphics, Scene * scene);
    void setScene(Scene * scene);
    void render();
};

#endif
