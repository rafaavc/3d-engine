#include "controller/Engine.h"
#include <unistd.h>
#include "model/Matrix4x4.h"

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
    timeVal += .5;
    std::vector<Triangle> triangles = scene->getTriangles();

    graphics->clear(RGBAColor(0, 0, 0));

    std::vector<Triangle> projectedTriangles;

    TransformationMatrix transfMatrix;

    for (Triangle triangle : triangles) {
        //std::cout << "START" << std::endl;
        transfMatrix.setIdentity();
        transfMatrix.pushMatrix(TransformationMatrix::getXRotationMatrix(timeVal));
        transfMatrix.pushMatrix(TransformationMatrix::getZRotationMatrix(timeVal));


        Vector3d v1 = triangle.getVertexes()[0];
        Vector3d v2 = triangle.getVertexes()[1];
        Vector3d v3 = triangle.getVertexes()[2];

        Matrix4x4 transf = transfMatrix.getTransformationMatrix();

        Vector3d v11 = transf * (v1);
        Vector3d v21 = transf * (v2);
        Vector3d v31 = transf * (v3);

        Triangle transformedTriangle(v11, v21, v31);

        projectedTriangles.push_back(transformedTriangle.getProjectedTriangle(projMatrix, model));
    }

    for (Triangle triangle : projectedTriangles) {
        //std::cout << triangle.getVertexes()[0]->getX() << ", " <<  triangle.getVertexes()[0]->getY() << std::endl;
        graphics->drawLine(triangle.getVertexes()[0].getX(), triangle.getVertexes()[0].getY(), triangle.getVertexes()[1].getX(), triangle.getVertexes()[1].getY());
        graphics->drawLine(triangle.getVertexes()[0].getX(), triangle.getVertexes()[0].getY(), triangle.getVertexes()[2].getX(), triangle.getVertexes()[2].getY());
        graphics->drawLine(triangle.getVertexes()[1].getX(), triangle.getVertexes()[1].getY(), triangle.getVertexes()[2].getX(), triangle.getVertexes()[2].getY());
    }
    usleep(3000);
}

