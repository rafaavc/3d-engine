#include "model/Observer.h"


Observer::Observer(Vector3d * position, Vector3d * direction) {
    this->direction = direction;
    this->position = position;
}

Vector3d * Observer::getDirection() {
    return direction;
}

Vector3d * Observer::getPosition() {
    return position;
}

Observer::~Observer() {
    delete direction;
    delete position;
}
