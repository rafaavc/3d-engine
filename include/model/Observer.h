#ifndef OBSERVER_H
#define OBSERVER_H

#include "model/Vector3d.h"

class Observer {
private:
    Vector3d * direction;
    Vector3d * position;
public:
    Observer(Vector3d * position, Vector3d * direction);
    Vector3d * getDirection();
    Vector3d * getPosition();
    ~Observer();
};

#endif