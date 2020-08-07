#include "model/Model.h"

Model::Model(string windowTitle, int width, int height) {
    this->windowTitle = windowTitle;
    this->width = width;
    this->height = height;
}

string Model::getWindowTitle() {
    return windowTitle;
}

int Model::getWidth() {
    return width;
}

int Model::getHeight() {
    return height;
}
