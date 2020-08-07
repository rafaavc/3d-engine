#ifndef UNITARIANVECTOR_H
#define UNITARIANVECTOR_H

#include "Vector.h"

class UnitarianVector : public Vector {
private:

public:
    UnitarianVector(int x, int y, int z);
    UnitarianVector(Vector v);
};

#endif
