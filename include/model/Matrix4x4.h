#ifndef MATRIX4X4_h
#define MATRIX4X4_h

#include "model/Vector3d.h"
#include "model/Triangle.h"
#include <iostream>

class Matrix4x4 {
private:
    float grid[4][4] = { 0 };
public:
    Matrix4x4() = default;
    Matrix4x4(float grid[4][4]);
    void setValue(unsigned row, unsigned col, float value);
    float getValue(unsigned row, unsigned col);
    static Matrix4x4 getIdentity();
    friend Matrix4x4 operator*(Matrix4x4 &mx1, Matrix4x4 &mx2);
    friend Vector3d operator*(Matrix4x4 &mx, Vector3d &v);
    friend std::ostream &operator<<(std::ostream & out, Matrix4x4 mx);
    friend Triangle operator*(Matrix4x4 &mx, Triangle &triangle);
};


#endif
