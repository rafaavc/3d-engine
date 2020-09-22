#include "model/Model.h"

Model::Model(std::string windowTitle, int width, int height) {
    this->windowTitle = windowTitle;
    this->width = width;
    this->height = height;
}

std::string Model::getWindowTitle() {
    return windowTitle;
}

int Model::getWidth() {
    return width;
}

int Model::getHeight() {
    return height;
}
