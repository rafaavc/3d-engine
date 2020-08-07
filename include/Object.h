#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

class Object {
private:
    std::vector<unsigned> vertexes;
    std::vector<unsigned> edges;
    std::vector<unsigned> polygons;
public:
    void setVertexesEdgesAndPolygons(std::vector<unsigned> &vertexes, std::vector<unsigned> &edges, std::vector<unsigned> &polygons);
    void addVertex(unsigned x, unsigned y, unsigned z);
    void addEdge(unsigned v1, unsigned v2);
    void addPolygon(unsigned e1, unsigned e2, unsigned e3);
    std::vector<unsigned> getVertex(unsigned v);
};

#endif

