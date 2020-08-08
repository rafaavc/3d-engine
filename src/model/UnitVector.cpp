#include "model/UnitVector.h"
#include <cmath>

UnitarianVector::UnitarianVector(int x, int y, int z) : Vector3d(x, y, z) {
    normalize();
}

UnitarianVector::UnitarianVector(Vector3d v) {
    float x, y, z;
    x = v.getX();
    y = v.getY();
    z = v.getZ();
    
    float mod = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    setX(x/mod);
    setY(y/mod);
    setZ(z/mod);
}

