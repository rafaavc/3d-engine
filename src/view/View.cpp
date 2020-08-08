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

void View::draw() {
    graphics->clear(RGBAColor(0, 0, 0));

    std::vector<Triangle> triangles;
    engine->getTriangleProjections(triangles);
    for (Triangle triangle : triangles) {
        //std::cout << triangle.getVertexes()[0]->getX() << ", " <<  triangle.getVertexes()[0]->getY() << std::endl;
        graphics->drawLine(triangle.getVertexes()[0].getX(), triangle.getVertexes()[0].getY(), triangle.getVertexes()[1].getX(), triangle.getVertexes()[1].getY());
        graphics->drawLine(triangle.getVertexes()[0].getX(), triangle.getVertexes()[0].getY(), triangle.getVertexes()[2].getX(), triangle.getVertexes()[2].getY());
        graphics->drawLine(triangle.getVertexes()[1].getX(), triangle.getVertexes()[1].getY(), triangle.getVertexes()[2].getX(), triangle.getVertexes()[2].getY());
    }

    graphics->render();
    usleep(3000);
}
