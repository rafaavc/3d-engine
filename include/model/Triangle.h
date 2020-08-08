#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "model/Vector3d.h"
#include "model/RGBAColor.h"

class Triangle {
private:
    Vector3d vertexes[3];
    RGBAColor color;
public:
    Triangle(Vector3d &v1, Vector3d &v2, Vector3d &v3);
    Vector3d * getVertexes() const;
    RGBAColor getColor() const;
    void setColor(RGBAColor color);
};


#endif