#ifndef ENGINE_H
#define ENGINE_H

#include "model/Model.h"
#include "model/Scene.h"
#include "controller/TransformationMatrix.h"

class Engine {
private:
    Model * model;
    Scene * scene;
    Matrix4x4 projMatrix;
    float timeVal = 0;
    float zBuffer[WIDTH][HEIGHT];
public:
    Engine(Model * model, Scene * scene);
    void resetZBuffer();
    bool isVisible(int x, int y, float z);
    void setScene(Scene * scene);
    void getTriangleProjections(std::vector<Triangle> & projectedTriangles);
};

#endif
