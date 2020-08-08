#ifndef OBSERVER_H
#define OBSERVER_H


#include "model/UnitVector.h"

class Observer {
private:
    UnitarianVector * direction;
    Vector3d * position;
public:
    Observer(Vector3d * position, UnitarianVector * direction);
    UnitarianVector * getDirection();
    Vector3d * getPosition();
    ~Observer();
};

#endif