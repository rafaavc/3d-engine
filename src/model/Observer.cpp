#include "model/Observer.h"


Observer::Observer(Vector3d position, Vector3d direction) {
    this->direction = direction;
    this->position = position;
    direction.setState(Vector3d::GET_NORMALIZED);
}

const Vector3d &Observer::getDirection() const {
    return direction;
}

const Vector3d &Observer::getPosition() const {
    return position;
}
