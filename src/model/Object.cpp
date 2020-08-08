#include "model/Object.h"
#include <iostream>

void Object::setVertexes(std::vector<int> &vertexes) {
    for (int i = 0; i < vertexes.size(); i++) {
        if (i%3 == 0) 
            this->vertexes.push_back(new Vector3d(vertexes.at(i), vertexes.at(i+1), vertexes.at(i+2)));
    }
}

void Object::addVertex(float x, float y, float z) {
    this->vertexes.push_back(new Vector3d(x, y, z));
}

void Object::addTriangle(unsigned v1, unsigned v2, unsigned v3) {
    Triangle triangle(*vertexes.at(v1), *vertexes.at(v2), *vertexes.at(v3));    
    this->triangles.push_back(triangle);
}

const std::vector<Triangle> &Object::getTriangles() const {
    return triangles;
}

Object::~Object() {
    for (Vector3d * v : vertexes) delete v;
}

