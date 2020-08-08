#include "controller/Engine.h"
#include "model/Matrix4x4.h"
#include "controller/TriangleController.h"

Engine::Engine(Model * model, Scene * scene) {
    this->model = model;
    this->projMatrix = TransformationMatrix::getProjectionMatrix(model, .1, 1000., 120.);
    setScene(scene);
}

void Engine::setScene(Scene * scene) {
    this->scene = scene;
}

void Engine::getTriangleProjections(std::vector<Triangle> & projectedTriangles) {
    timeVal += 1;
    std::vector<Triangle> triangles = scene->getTriangles();

    TransformationMatrix transfMatrix;

    for (Triangle triangle : triangles) {
        transfMatrix.setIdentity();
        transfMatrix.pushMatrix(TransformationMatrix::getTranslationMatrix(0, 0, 20));
        transfMatrix.pushMatrix(TransformationMatrix::getXRotationMatrix(timeVal));
        transfMatrix.pushMatrix(TransformationMatrix::getZRotationMatrix(timeVal));

        Triangle transformedTriangle = transfMatrix * triangle;
        if (TriangleController::backfaceCull(scene->getObserver()->getDirection(), scene->getObserver()->getPosition(), transformedTriangle)) continue;

        projectedTriangles.push_back(TriangleController::getProjectedTriangle(transformedTriangle, projMatrix, model));
    }
}

