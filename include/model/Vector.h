#ifndef VECTOR_H
#define VECTOR_H

class Vector {
protected:
    float x, y, z;
public:
    Vector();
    Vector(float x, float y, float z);
    float getX();
    float getY();
    float getZ();
    float mod();
    float sum();
    static float scalarProd(Vector * v1, Vector * v2);
    Vector invert();
    friend Vector operator*(const Vector &v1, const Vector &v2);
    friend Vector operator+(const Vector &v1, const Vector &v2);
    friend Vector operator-(const Vector &v1, const Vector &v2);
    friend Vector operator*(int n, const Vector &v);
};

#endif