#include "controller/Engine.h"
#include "model/Matrix4x4.h"
#include "controller/TriangleController.h"
#include "CONSTANTS.h"

Engine::Engine(Model * model, Scene * scene) {
    this->model = model;
    this->projMatrix = TransformationMatrix::getProjectionMatrix(model, .1, 1000., 120.);
    setScene(scene);
}

void Engine::resetZBuffer() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            zBuffer[i][j] = -10000000.;
        }
    }
}

bool Engine::isVisible(int x, int y, float z) {
    if (x >= WIDTH || y >= HEIGHT) return false;
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
    timeVal += 0.5;
    std::vector<Triangle> triangles = scene->getTriangles();

    TransformationMatrix transfMatrix;

    for (Triangle triangle : triangles) {
        transfMatrix.setIdentity();
        transfMatrix.pushMatrix(TransformationMatrix::getTranslationMatrix(0, 0, 20));
        transfMatrix.pushMatrix(TransformationMatrix::getScalingMatrix(0.1, 0.1, 0.1));
        transfMatrix.pushMatrix(TransformationMatrix::getXRotationMatrix(timeVal));
        transfMatrix.pushMatrix(TransformationMatrix::getZRotationMatrix(timeVal));
        transfMatrix.pushMatrix(TransformationMatrix::getTranslationMatrix(0, -3, 0));

        Triangle transformedTriangle = transfMatrix * triangle;
        if (TriangleController::backfaceCull(scene->getObserver()->getDirection(), scene->getObserver()->getPosition(), transformedTriangle)) continue;

        TriangleController::getColoredTriangle(scene, transformedTriangle);

        projectedTriangles.push_back(TriangleController::getProjectedTriangle(transformedTriangle, projMatrix, model));
    }
}

