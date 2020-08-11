#include "model/Vector3d.h"
#include <cmath>

Vector3d::Vector3d(float x, float y, float z) {
    setX(x);
    setY(y);
    setZ(z);
    normalize();
}

Vector3d::Vector3d(const Vector3d &v) {
    setX(v.getX());
    setY(v.getY());
    setZ(v.getZ());
    normalize();
}

void Vector3d::setState(VectorState state) {
    this->state = state;
}

void Vector3d::setValue(unsigned pos, float value) {
    vec[pos] = value;
    normalize();
}

float Vector3d::getValue(unsigned pos) const {
    if (state == GET_NORMALIZED)
        return vecNormalized[pos];
    else if (state == TRUNCATED && pos != 2) return (int)vec[pos];
    return vec[pos];
}

float Vector3d::getX() const {
    return getValue(0);
}

float Vector3d::getY() const {
    return getValue(1);
}

float Vector3d::getZ() const {
    return getValue(2);
}

float Vector3d::getW() const {
    return getValue(3);
}

void Vector3d::setX(float x) {
    setValue(0, x);
}

void Vector3d::setY(float y) {
    setValue(1, y);
}

void Vector3d::setZ(float z) {
    setValue(2, z);
}

void Vector3d::setW(float w) {
    setValue(3, w);
}

void Vector3d::normalize() {
    float mod = std::sqrt(std::pow(getX(), 2) + std::pow(getY(), 2) + std::pow(getZ(), 2));
    vecNormalized[0] = getX()/mod;
    vecNormalized[1] = getY()/mod;
    vecNormalized[2] = getZ()/mod;
}

Vector3d Vector3d::getNormalized() const {
    return Vector3d(vecNormalized[0], vecNormalized[1],vecNormalized[2]);
}

float Vector3d::mod() const {
    return sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2));
}

float Vector3d::sum() const {
    return getX() + getY() + getZ();
}

float Vector3d::scalarProd(Vector3d &v1, Vector3d &v2) {
    return (v1 * v2).sum();
}

Vector3d Vector3d::crossProd(Vector3d &v1, Vector3d &v2) {
    float x = v1.getY()*v2.getZ() - v2.getY()*v1.getZ();
    float y = -v1.getX()*v2.getZ() + v2.getX()*v1.getZ();
    float z = v1.getX()*v2.getY() - v2.getX()*v1.getY();
    return Vector3d(x, y, z);
}

Vector3d Vector3d::invert() const {
    return Vector3d(-getX(), -getY(), -getZ());
}

bool operator==(const Vector3d &v1, const Vector3d &v2) {
    return (int)v1.getX() == (int)v2.getX() && (int)v1.getY() == (int)v2.getY();
}

Vector3d operator*(const Vector3d &v1, const Vector3d &v2) {
    return Vector3d(v1.getX()*v2.getX(), v1.getY()*v2.getY(), v1.getZ()*v2.getZ());
}
Vector3d operator*(int n, const Vector3d &v) {
    return Vector3d(n*v.getX(), n*v.getY(), n*v.getZ());
}

Vector3d operator+(const Vector3d &v1, const Vector3d &v2) {
    return Vector3d(v1.getX()+v2.getX(), v1.getY()+v2.getY(), v1.getZ()+v2.getZ());
}

Vector3d operator-(const Vector3d &v1, const Vector3d &v2) {
    return Vector3d(v1.getX()-v2.getX(), v1.getY()-v2.getY(), v1.getZ()-v2.getZ());
}

std::ostream &operator<<(std::ostream &out, Vector3d &v) {
    out << "{" << v.getX() << ", " << v.getY() << ", " << v.getZ() << "}" << std::endl;
    return out;
}
