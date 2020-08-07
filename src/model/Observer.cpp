#include "model/Observer.h"


Observer::Observer(Vector * position, UnitarianVector * direction) {
    this->direction = direction;
    this->position = position;
}

UnitarianVector * Observer::getDirection() {
    return direction;
}

Vector * Observer::getPosition() {
    return position;
}

Observer::~Observer() {
    delete direction;
    delete position;
}
