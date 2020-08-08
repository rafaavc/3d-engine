#include "model/Light.h"


Light::Light(float ambient, float direct, Vector3d * position, UnitarianVector * direction) {
    this->ambient = ambient;
    this->direct = direct;
    this->direction = direction;
    this->position = position;
}

float Light::getAmbient() {
    return ambient;
}

float Light::getDirect() {
    return direct;
}

UnitarianVector * Light::getDirection() {
    return direction;
}

Vector3d * Light::getPosition() {
    return position;
}

Light::~Light() {
    delete direction;
    delete position;
}
