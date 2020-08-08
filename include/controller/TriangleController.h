#ifndef TRIANGLECONTROLLER_H
#define TRIANGLECONTROLLER_H

#include "model/Triangle.h"
#include "model/Matrix4x4.h"
#include "model/Model.h"

class TriangleController {
public:
    static Triangle getProjectedTriangle(Triangle triangle, Matrix4x4 &projMatrix, Model * model);
};

#endif