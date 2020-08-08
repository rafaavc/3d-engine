#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3d {
protected:
    float vec[4] = { 0, 0, 0, 1 };
    bool normalized = false;
public:
    Vector3d() = default;
    Vector3d(const Vector3d &v);
    Vector3d(float x, float y, float z);
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
    float mod() const;
    float sum() const;
    static float scalarProd(Vector3d v1, Vector3d v2);
    Vector3d invert() const;
    friend Vector3d operator*(const Vector3d &v1, const Vector3d &v2);
    friend Vector3d operator+(const Vector3d &v1, const Vector3d &v2);
    friend Vector3d operator-(const Vector3d &v1, const Vector3d &v2);
    friend Vector3d operator*(int n, const Vector3d &v);
};

#endif