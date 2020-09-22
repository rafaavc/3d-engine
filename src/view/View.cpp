#include "view/View.h"
#include <unistd.h>

View::View(Model * model, Engine * engine, Graphics * graphics) {
    this->model = model;
    this->graphics = graphics;
    this->engine = engine;
}

void View::init() {
    graphics->initGraphics(model->getWindowTitle(), model->getWidth(), model->getHeight());
}

void View::quit(){
    graphics->quitGraphics();
}

Graphics::GraphicsCommand View::getUserInput(char * specifier) {
    return graphics->getUserInput(specifier);
}

void View::drawTriangle(Triangle &triangle) {
    Vector3d v1 = triangle.getVertexes()[0];
    Vector3d v2 = triangle.getVertexes()[1];
    Vector3d v3 = triangle.getVertexes()[2];

    v1.setState(Vector3d::GET_TRUNCATED);
    v2.setState(Vector3d::GET_TRUNCATED);
    v3.setState(Vector3d::GET_TRUNCATED);

    // ordering the vertexes
    if (v2.getY() < v1.getY()) swap(v2, v1);
    if (v3.getY() < v1.getY()) swap(v3, v1);
    if (v3.getY() < v2.getY()) swap(v2, v3);

    graphics->setDrawColor(triangle.getColor());

    // SPAGHETTIIIIIII!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // TODO: Refactor

    int dy2 = v2.getY()-v1.getY();
    int dy3 = v3.getY()-v1.getY();

    int currentY = v1.getY();

    float dx2y = (v2.getX()-v1.getX())/(float)dy2;
    float dx3y = (v3.getX()-v1.getX())/(float)dy3;
    float dz2y = (v2.getZ()-v1.getZ())/(float)dy2;
    float dz3y = (v3.getZ()-v1.getZ())/(float)dy3;

    //float dz2y = 

    int ycount = 0;
    int x2, x3;
    float z2, z3;
    while(ycount != dy2) {
        x2 = v1.getX() + (float)ycount*dx2y;
        x3 = v1.getX() + (float)ycount*dx3y;
        z2 = v1.getZ() + (float)ycount*dz2y;
        z3 = v1.getZ() + (float)ycount*dz3y;

        if (x3 < x2) swap(x3, x2);
        if (z3 < z2) swap(z3, z2);
        for (int i = x2; i <= x3; i++) {
            float z = z2;
            //std::cout << z << std::endl;
            if (x2 != x3)
                z = z2 + (float)((i-x2)*((float)(z3-z2)/(float)(x3-x2)));
            //std::cout << z << std::endl;
            if (engine->isVisible(i, currentY, z))
                graphics->drawPixel(i, currentY);
        }

        ycount++;
        currentY++;
    }

    dy2 = v3.getY() - v2.getY();
    dx2y = (v3.getX()-v2.getX())/(float)dy2;
    dz2y = (v3.getZ()-v2.getZ())/(float)dy2;

    int prevYCount = ycount;
    ycount = 0;
    while(ycount != dy2) {
        x2 = v2.getX() + (float)ycount*dx2y;
        x3 = v1.getX() + (float)(prevYCount+ycount)*dx3y;
        z2 = v2.getZ() + (float)ycount*dz2y;
        z3 = v1.getZ() + (float)ycount*dz3y;

        if (x3 < x2) swap(x3, x2);
        if (z3 < z2) swap(z3, z2);
        for (int i = x2; i <= x3; i++) {
            float z = z2;
            if (x2 != x3)
                z = z2 + (float)((i-x2)*((float)(z3-z2)/(float)(x3-x2)));
            if (engine->isVisible(i, currentY, z))
                graphics->drawPixel(i, currentY);
        }

        ycount++;
        currentY++;
    }

    /*graphics->drawLine(v1.first, v1.second, v2.first, v2.second);
    graphics->drawLine(v1.first, v1.second, v3.first, v3.second);
    graphics->drawLine(v2.first, v2.second, v3.first, v3.second);*/

}


void View::draw() {
    graphics->setDrawColor(RGBAColor(0, 0, 0));
    graphics->clear();

    engine->resetZBuffer();

    std::vector<Triangle> triangles;
    engine->getTriangleProjections(triangles);

    for (Triangle triangle : triangles) {
        drawTriangle(triangle);
    }

    graphics->render();
    //usleep(3000);
}
