#include "controller/TriangleController.h"
#include "controller/TransformationMatrix.h"


Triangle TriangleController::getProjectedTriangle(Triangle triangle, Matrix4x4 &projMatrix, Model * model) {
    TransformationMatrix transfMatrix;
    transfMatrix.setIdentity();
    transfMatrix.pushMatrix(TransformationMatrix::getScalingMatrix(model->getWidth()/2., model->getHeight()/2., 1));
    transfMatrix.pushMatrix(TransformationMatrix::getTranslationMatrix(1, 1, 0));
    transfMatrix.pushMatrix(projMatrix);
    transfMatrix.pushMatrix(TransformationMatrix::getTranslationMatrix(0, 0, 20));

    return transfMatrix * triangle;
}

