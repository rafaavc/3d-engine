#ifndef LIGHT_H
#define LIGHT_H

#include "model/UnitVector.h"

class Light {
private:
    float ambient, direct;
    UnitarianVector * direction;
    Vector * position;
public:
    Light(float ambient, float direct, Vector * position, UnitarianVector * direction);
    float getAmbient();
    float getDirect();
    UnitarianVector * getDirection();
    Vector * getPosition();
    ~Light();
};

#endif