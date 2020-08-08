#ifndef TRANSFORMATIONMATRIX_H
#define TRANSFORMATIONMATRIX_H

#include <stack>
#include "model/Matrix4x4.h"
#include "model/Model.h"
#include "CONSTANTS.h"

class TransformationMatrix {
private:
    std::stack<Matrix4x4> matrixStack;

public:
    TransformationMatrix();
    void pushMatrix(Matrix4x4 mx);
    void popMatrix();
    void setIdentity();
    Matrix4x4 getTransformationMatrix() const;
    static Matrix4x4 getProjectionMatrix(Model * model, float zNear, float zFar, float visionAngle);
    static Matrix4x4 getTranslationMatrix(float Tx, float Ty, float Tz);
    static Matrix4x4 getScalingMatrix(float Sx, float Sy, float Sz);
    static Matrix4x4 getZRotationMatrix(float angle);
    static Matrix4x4 getYRotationMatrix(float angle);
    static Matrix4x4 getXRotationMatrix(float angle);
};

#endif