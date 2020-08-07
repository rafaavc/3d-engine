#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "view/View.h"

class Controller {
private:
    Model * model;
    View * view;
public:
    Controller(Model * model, View * view);
    void start();
    void update();
};

#endif
