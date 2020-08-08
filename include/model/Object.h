#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "model/Vector3d.h"
#include "model/Triangle.h"

class Object {
private:
    std::vector<Vector3d *> vertexes;
    std::vector<Triangle> triangles;
public:
    void setVertexes(std::vector<int> &vertexes);
    void addVertex(float x, float y, float z);
    void addTriangle(unsigned v1, unsigned v2, unsigned v3);
    void setTriangles(std::vector<unsigned> &triangles);
    const std::vector<Triangle> &getTriangles() const;
    ~Object();
};

#endif

