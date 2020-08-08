#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "model/Vector3d.h"

class Triangle {
private:
    Vector3d vertexes[3];
public:
    Triangle(Vector3d &v1, Vector3d &v2, Vector3d &v3);
    Vector3d * getVertexes() const;
};


#endif