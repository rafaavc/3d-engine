#ifndef LIGHT_H
#define LIGHT_H

#include "model/Vector3d.h"

class Light {
private:
    float ambient, direct;
    Vector3d direction, position;
public:
    Light(float ambient, float direct, Vector3d position, Vector3d direction);
    float getAmbient();
    float getDirect();
    const Vector3d &getDirection() const;
    const Vector3d &getPosition() const;
};

#endif