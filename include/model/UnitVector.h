#ifndef UNITARIANVECTOR_H
#define UNITARIANVECTOR_H

#include "Vector3d.h"

class UnitarianVector : public Vector3d {
private:

public:
    UnitarianVector(int x, int y, int z);
    UnitarianVector(Vector3d v);
};

#endif
