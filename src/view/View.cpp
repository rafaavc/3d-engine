#include "view/View.h"

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
    engine->render();
    graphics->render();
}
