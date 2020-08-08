#include "controller/TransformationMatrix.h"
#include <math.h>
#include "CONSTANTS.h"

TransformationMatrix::TransformationMatrix() {
    this->matrixStack.push(Matrix4x4::getIdentity());
}

void TransformationMatrix::pushMatrix(Matrix4x4 mx) {
    this->matrixStack.push(this->matrixStack.top() * mx);
}

void TransformationMatrix::popMatrix() {
    if (matrixStack.size() == 1) return; // the matrix that exists is the identity
    this->matrixStack.pop();
}

void TransformationMatrix::setIdentity() {
    while(matrixStack.size() != 1) {
        matrixStack.pop();
    }
}

Matrix4x4 TransformationMatrix::getTransformationMatrix() const {
    return this->matrixStack.top();
}

Matrix4x4 TransformationMatrix::getProjectionMatrix(Model * model, float zNear, float zFar, float visionAngle) {
    Matrix4x4 res;

    float aspectRatio = model->getHeight() / (float) model->getWidth();
    float visionAngleMultiplier = 1. / tan(0.5 * degreesToRadians(visionAngle));

    res.setValue(0, 0, aspectRatio * visionAngleMultiplier);
    res.setValue(1, 1, visionAngleMultiplier);
    res.setValue(2, 2, zFar / (zFar - zNear));
    res.setValue(3, 2, (-zFar * zNear) / (zFar - zNear));
    res.setValue(2, 3, 1.);
    return res;
}

Matrix4x4 TransformationMatrix::getTranslationMatrix(float Tx, float Ty, float Tz) {
    float grid[4][4] = {{1., 0., 0., Tx}, {0., 1., 0., Ty}, {0., 0., 1., Tz}, {0., 0., 0., 1.}};
    return Matrix4x4(grid);
}

Matrix4x4 TransformationMatrix::getScalingMatrix(float Sx, float Sy, float Sz) {
    float grid[4][4] = {{Sx, 0., 0., 0.}, {0., Sy, 0., 0.}, {0., 0., Sz, 0.}, {0., 0., 0., 1.}};
    return Matrix4x4(grid);
}

Matrix4x4 TransformationMatrix::getZRotationMatrix(float angle /* degrees */) {
    float a = degreesToRadians(angle);
    float grid[4][4] = {{cos(a), -sin(a), 0., 0.}, {sin(a), cos(a), 0., 0.}, {0., 0., 1., 0.}, {0., 0., 0., 1.}};
    return Matrix4x4(grid);
}

Matrix4x4 TransformationMatrix::getYRotationMatrix(float angle /* degrees */) {
    float a = degreesToRadians(angle);
    float grid[4][4] = {{cos(a), 0., sin(a), 0.}, {0., 1., 0., 0.}, {-sin(a), 0., cos(a), 0.}, {0., 0., 0., 1.}};
    return Matrix4x4(grid);
}

Matrix4x4 TransformationMatrix::getXRotationMatrix(float angle /* degrees */) {
    float a = degreesToRadians(angle);
    float grid[4][4] = {{1., 0., 0., 0.}, {0., cos(a), -sin(a), 0.}, {0., sin(a), cos(a), 0.}, {0., 0., 0., 1.}};
    return Matrix4x4(grid);
}

Triangle operator*(TransformationMatrix &tm, Triangle &triangle) {
    Matrix4x4 transf = tm.getTransformationMatrix();
    return transf * triangle;
}

