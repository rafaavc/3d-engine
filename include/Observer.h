#ifndef OBSERVER_H
#define OBSERVER_H


#include "model/UnitVector.h"

class Observer {
private:
    UnitarianVector * direction;
    Vector * position;
public:
    Observer(Vector * position, UnitarianVector * direction);
    UnitarianVector * getDirection();
    Vector * getPosition();
    ~Observer();
};

#endif