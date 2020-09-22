#include "model/Light.h"


Light::Light(float ambient, float direct, Vector3d position, Vector3d direction) {
    this->ambient = ambient;
    this->direct = direct;
    this->direction = direction;
    this->position = position;
    direction.setState(Vector3d::GET_NORMALIZED);
}

float Light::getAmbient() {
    return ambient;
}

float Light::getDirect() {
    return direct;
}

const Vector3d &Light::getDirection() const {
    return direction;
}

const Vector3d &Light::getPosition() const {
    return position;
}
