#include "model/Matrix4x4.h"

Matrix4x4::Matrix4x4(float grid[4][4]) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            this->grid[i][j] = grid[i][j];
        }
    }
}

void Matrix4x4::setValue(unsigned row, unsigned col, float value) {
    this->grid[row][col] = value;
}

float Matrix4x4::getValue(unsigned row, unsigned col) {
    return this->grid[row][col];
}

Matrix4x4 Matrix4x4::getIdentity() {
    Matrix4x4 mx = Matrix4x4();
    mx.setValue(0, 0, 1);
    mx.setValue(1, 1, 1);
    mx.setValue(2, 2, 1);
    mx.setValue(3, 3, 1);
    return mx;
}

Matrix4x4 operator*(Matrix4x4 &mx1, Matrix4x4 &mx2) {
    Matrix4x4 res;

    //std::cout << "Multiplying:\n" << mx1 << "and\n" << mx2 << std::endl;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            float value = 0;

            for (int k = 0; k < 4; k++)
                value += mx1.getValue(i, k) * mx2.getValue(k, j);

            res.setValue(i, j, value);
        }
    }

    //std::cout << "Result:\n" << res << std::endl;

    return res;
}

Vector3d operator*(Matrix4x4 &mx, Vector3d &v) {
    Vector3d res;

    for (int i = 0; i < 3; i++) {
        float value = 0;

        for (int k = 0; k < 4; k++)
            value += mx.getValue(i, k) * v.getValue(k);

        res.setValue(i, value);
    }

    float value = mx.getValue(3, 0) * v.getValue(0) + mx.getValue(3, 1) * v.getValue(1) + mx.getValue(3, 2) * v.getValue(2) + mx.getValue(3, 3);
    if (value != 0.) {
        res.setX(res.getX()/value);
        res.setY(res.getY()/value);
        res.setZ(res.getZ()/value);
    }

    return res;
}

Triangle operator*(Matrix4x4 &mx, Triangle &triangle) {
    Vector3d v1 = triangle.getVertexes()[0];
    Vector3d v2 = triangle.getVertexes()[1];
    Vector3d v3 = triangle.getVertexes()[2];

    v1 = mx * (v1);
    v2 = mx * (v2);
    v3 = mx * (v3);

    return Triangle(v1, v2, v3);
}

std::ostream &operator<<(std::ostream & out, Matrix4x4 mx) {
    out << "[";
    for (int i = 0; i < 4; i++) {
        out << "[ ";
        for (int j = 0; j < 4; j++) {
            out << mx.getValue(i, j);
            if (j != 3) out << ", ";
        }
        out << " ]";
        if (i != 3) out << std::endl;
    }
    out << "]" << std::endl;
    return out;
}

