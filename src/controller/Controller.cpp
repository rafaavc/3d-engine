#include "controller/Controller.h"
#include <unistd.h>

Controller::Controller(Model * model, View * view) {
    this->model = model;
    this->view = view;
}

void Controller::update() {

}

void Controller::start() {
    view->init();

    char specifier;

    while(true) {
        if (view->getUserInput(&specifier) == Graphics::QUIT) break;
        update();
        view->draw();
    }

    view->quit();
}

