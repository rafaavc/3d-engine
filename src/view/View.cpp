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
    Vector3d v11 = triangle.getVertexes()[0];
    Vector3d v21 = triangle.getVertexes()[1];
    Vector3d v31 = triangle.getVertexes()[2];

    std::pair<int, int> v1 = {v11.getX(), v11.getY()};
    std::pair<int, int> v2 = {v21.getX(), v21.getY()};
    std::pair<int, int> v3 = {v31.getX(), v31.getY()};

    // ordering the vertexes
    if (v2.second < v1.second) swap(v2, v1);
    if (v3.second < v1.second) swap(v3, v1);
    if (v3.second < v2.second) swap(v2, v3);

    // SPAGHETTIIIIIII!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // TODO: Refactor

    int dy2 = v2.second-v1.second;
    int dy3 = v3.second-v1.second;

    int currentY = v1.second;

    float dx2y = (v2.first-v1.first)/(float)dy2;
    float dx3y = (v3.first-v1.first)/(float)dy3;

    int ycount = 0;
    int x2, x3;
    while(ycount != dy2) {
        x2 = v1.first + (float)ycount*dx2y;
        x3 = v1.first + (float)ycount*dx3y;

        if (x3 < x2) {
            for (int i = x3; i <= x2; i++) {
                graphics->drawPixel(i, currentY);
            }
        } else {
            for (int i = x2; i <= x3; i++) {
                graphics->drawPixel(i, currentY);
            }
        }
        ycount++;
        currentY++;
    }

    dy2 = v3.second - v2.second;
    dx2y = (v3.first-v2.first)/(float)dy2;

    int x2Begin = v2.first;

    int prevYCount = ycount;
    ycount = 0;
    while(ycount != dy2) {
        x2 = x2Begin + (float)ycount*dx2y;
        x3 = v1.first + (float)(prevYCount+ycount)*dx3y;

        if (x3 < x2) {
            for (int i = x3; i <= x2; i++) {
                graphics->drawPixel(i, currentY);
            }
        } else {
            for (int i = x2; i <= x3; i++) {
                graphics->drawPixel(i, currentY);
            }
        }

        ycount++;
        currentY++;
    }

    /*graphics->drawLine(v1.first, v1.second, v2.first, v2.second);
    graphics->drawLine(v1.first, v1.second, v3.first, v3.second);
    graphics->drawLine(v2.first, v2.second, v3.first, v3.second);*/

}


void View::draw() {
    graphics->clear(RGBAColor(0, 0, 0));

    std::vector<Triangle> triangles;
    engine->getTriangleProjections(triangles);

    for (Triangle triangle : triangles) {
        drawTriangle(triangle);
    }

    graphics->render();
    usleep(3000);
}
