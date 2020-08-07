#include "model/Vector.h"
#include <cmath>

Vector::Vector() {
    this->x = -1;
    this->y = -1;
    this->z = -1;
}

Vector::Vector(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

float Vector::getX() {
    return x;
}

float Vector::getY() {
    return y;
}

float Vector::getZ() {
    return z;
}

float Vector::mod() {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

float Vector::sum() {
    return x + y + z;
}

float Vector::scalarProd(Vector * v1, Vector * v2) {
    return (*v1 * *v2).sum();
}

Vector Vector::invert() {
    return Vector(-x, -y, -z);
}

Vector operator*(const Vector &v1, const Vector &v2) {
    return Vector(v1.x*v2.x, v1.y*v2.y, v1.z*v2.z);
}
Vector operator*(int n, const Vector &v) {
    return Vector(n*v.x, n*v.y, n*v.z);
}

Vector operator+(const Vector &v1, const Vector &v2) {
    return Vector(v1.x+v2.x, v1.y+v2.y, v1.z+v2.z);
}

Vector operator-(const Vector &v1, const Vector &v2) {
    return Vector(v1.x-v2.x, v1.y-v2.y, v1.z-v2.z);
}
