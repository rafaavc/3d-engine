#include "controller/Engine.h"
#include "model/Matrix4x4.h"
#include "controller/TriangleController.h"
#include <string.h>

Engine::Engine(Model * model, Scene * scene) {
    this->model = model;
    this->projMatrix = TransformationMatrix::getProjectionMatrix(model, .1, 1000., 120.);
    setScene(scene);
}

void Engine::resetZBuffer() {
    memset(zBuffer, 0, WIDTH*HEIGHT);
}

bool Engine::isVisible(int x, int y, int z) {
    if (zBuffer[x][y] < z) {
        zBuffer[x][y] = z;
        return true;
    }
    return false;
}

void Engine::setScene(Scene * scene) {
    this->scene = scene;
}

void Engine::getTriangleProjections(std::vector<Triangle> & projectedTriangles) {
    timeVal += 0.4;
    std::vector<Triangle> triangles = scene->getTriangles();

    TransformationMatrix transfMatrix;

    for (Triangle triangle : triangles) {
        transfMatrix.setIdentity();
        transfMatrix.pushMatrix(TransformationMatrix::getTranslationMatrix(0, 0, 20));
        transfMatrix.pushMatrix(TransformationMatrix::getXRotationMatrix(timeVal));
        transfMatrix.pushMatrix(TransformationMatrix::getZRotationMatrix(timeVal));

        Triangle transformedTriangle = transfMatrix * triangle;
        if (TriangleController::backfaceCull(scene->getObserver()->getDirection(), scene->getObserver()->getPosition(), transformedTriangle)) continue;

        TriangleController::getColoredTriangle(scene, transformedTriangle);

        projectedTriangles.push_back(TriangleController::getProjectedTriangle(transformedTriangle, projMatrix, model));
    }
}

