#include "model/Object.h"

void Object::setVertexesEdgesAndPolygons(std::vector<unsigned> &vertexes, std::vector<unsigned> &edges, std::vector<unsigned> &polygons) {
    this->vertexes = vertexes;
    this->edges = edges;
    this->polygons = polygons;
}

void Object::addVertex(unsigned x, unsigned y, unsigned z) {
    this->vertexes.push_back(x);
    this->vertexes.push_back(y);
    this->vertexes.push_back(z);
}

void Object::addEdge(unsigned v1, unsigned v2) {
    this->edges.push_back(v1);
    this->edges.push_back(v2);
}

void Object::addPolygon(unsigned e1, unsigned e2, unsigned e3) {
    this->polygons.push_back(e1);
    this->polygons.push_back(e2);
    this->polygons.push_back(e3);
}

std::vector<unsigned> Object::getVertex(unsigned v) {
    std::vector<unsigned> res;
    unsigned vectorPos = v*3;
    res.push_back(this->vertexes.at(vectorPos));
    res.push_back(this->vertexes.at(vectorPos+1));
    res.push_back(this->vertexes.at(vectorPos+2));
    return res;
}

