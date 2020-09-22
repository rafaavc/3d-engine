#ifndef OBSERVER_H
#define OBSERVER_H

#include "model/Vector3d.h"

class Observer {
private:
    Vector3d direction;
    Vector3d position;
public:
    Observer(Vector3d position, Vector3d direction);
    const Vector3d &getDirection() const;
    const Vector3d &getPosition() const;
};

#endif