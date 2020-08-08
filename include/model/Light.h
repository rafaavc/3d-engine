#ifndef LIGHT_H
#define LIGHT_H

#include "model/UnitVector.h"

class Light {
private:
    float ambient, direct;
    UnitarianVector * direction;
    Vector3d * position;
public:
    Light(float ambient, float direct, Vector3d * position, UnitarianVector * direction);
    float getAmbient();
    float getDirect();
    UnitarianVector * getDirection();
    Vector3d * getPosition();
    ~Light();
};

#endif