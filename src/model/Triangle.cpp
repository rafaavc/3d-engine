#include "model/Triangle.h"

Triangle::Triangle(Vector3d &v1,Vector3d &v2, Vector3d &v3) {
    this->vertexes[0] = v1;
    this->vertexes[1] = v2;
    this->vertexes[2] = v3;
}


Vector3d * Triangle::getVertexes() const {
    return (Vector3d *) vertexes;
}