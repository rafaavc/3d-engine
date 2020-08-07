#include "model/UnitVector.h"
#include <cmath>

UnitarianVector::UnitarianVector(int x, int y, int z) {
    float mod = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    this->x = x/mod;
    this->y = y/mod;
    this->z = z/mod;
}

UnitarianVector::UnitarianVector(Vector v) {
    float x, y, z;
    x = v.getX();
    y = v.getY();
    z = v.getZ();
    
    float mod = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    this->x = x/mod;
    this->y = y/mod;
    this->z = z/mod;
}

