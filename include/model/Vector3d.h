#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

class Vector3d {
public:
    enum VectorState {
        GET_NORMALIZED,
        GET_REGULAR
    };
protected:
    float vec[4] = { 0, 0, 0, 1 }, vecNormalized[4] = { 0, 0, 0, 1 };
    VectorState state = GET_REGULAR;
public:
    Vector3d() = default;
    Vector3d(const Vector3d &v);
    Vector3d(float x, float y, float z);
    void setState(VectorState state);
    void setValue(unsigned pos, float value);
    float getValue(unsigned pos) const;
    float getX() const;
    float getY() const;
    float getZ() const;
    float getW() const;
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void setW(float w);
    bool isNormalized() const;
    void normalize();
    Vector3d getNormalized() const;
    float mod() const;
    float sum() const;
    static float scalarProd(Vector3d &v1, Vector3d &v2);
    static Vector3d crossProd(Vector3d &v1, Vector3d &v2);
    Vector3d invert() const;
    friend bool operator==(const Vector3d &v1, const Vector3d &v2);
    friend Vector3d operator*(const Vector3d &v1, const Vector3d &v2);
    friend Vector3d operator+(const Vector3d &v1, const Vector3d &v2);
    friend Vector3d operator-(const Vector3d &v1, const Vector3d &v2);
    friend Vector3d operator*(int n, const Vector3d &v);
    friend std::ostream &operator<<(std::ostream &out, Vector3d &v);
};

#endif