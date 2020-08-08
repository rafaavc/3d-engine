#include "model/Observer.h"


Observer::Observer(Vector3d * position, UnitarianVector * direction) {
    this->direction = direction;
    this->position = position;
}

UnitarianVector * Observer::getDirection() {
    return direction;
}

Vector3d * Observer::getPosition() {
    return position;
}

Observer::~Observer() {
    delete direction;
    delete position;
}
