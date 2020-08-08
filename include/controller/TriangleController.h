#ifndef TRIANGLECONTROLLER_H
#define TRIANGLECONTROLLER_H

#include "model/Triangle.h"
#include "model/Matrix4x4.h"
#include "model/Model.h"
#include "model/Scene.h"

class TriangleController {
public:
    static Triangle getProjectedTriangle(Triangle &triangle, Matrix4x4 &projMatrix, Model * model);
    static bool backfaceCull(Vector3d &cameraDir, Vector3d &cameraPosition, Triangle &triangle);
    static void getColoredTriangle(Scene * scene, Triangle & transformedTriangle);
};

#endif