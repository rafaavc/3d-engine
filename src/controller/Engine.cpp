#include "controller/Engine.h"
#include <unistd.h>
#include "model/Matrix4x4.h"
#include "controller/TriangleController.h"

Engine::Engine(Model * model, Graphics * graphics, Scene * scene) {
    this->graphics = graphics;
    this->model = model;
    this->projMatrix = TransformationMatrix::getProjectionMatrix(model, .1, 1000., 120.);
    setScene(scene);
}

void Engine::setScene(Scene * scene) {
    this->scene = scene;
}

void Engine::render() {
    timeVal += 0.5;
    std::vector<Triangle> triangles = scene->getTriangles();

    graphics->clear(RGBAColor(0, 0, 0));

    std::vector<Triangle> projectedTriangles;

    TransformationMatrix transfMatrix;

    for (Triangle triangle : triangles) {
        transfMatrix.setIdentity();
        transfMatrix.pushMatrix(TransformationMatrix::getXRotationMatrix(timeVal));
        transfMatrix.pushMatrix(TransformationMatrix::getZRotationMatrix(timeVal));

        Triangle transformedTriangle = transfMatrix * triangle;

        projectedTriangles.push_back(TriangleController::getProjectedTriangle(transformedTriangle, projMatrix, model));
    }

    for (Triangle triangle : projectedTriangles) {
        //std::cout << triangle.getVertexes()[0]->getX() << ", " <<  triangle.getVertexes()[0]->getY() << std::endl;
        graphics->drawLine(triangle.getVertexes()[0].getX(), triangle.getVertexes()[0].getY(), triangle.getVertexes()[1].getX(), triangle.getVertexes()[1].getY());
        graphics->drawLine(triangle.getVertexes()[0].getX(), triangle.getVertexes()[0].getY(), triangle.getVertexes()[2].getX(), triangle.getVertexes()[2].getY());
        graphics->drawLine(triangle.getVertexes()[1].getX(), triangle.getVertexes()[1].getY(), triangle.getVertexes()[2].getX(), triangle.getVertexes()[2].getY());
    }
    usleep(3000);
}

