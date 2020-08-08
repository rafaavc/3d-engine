#include "model/Triangle.h"
#include "controller/TransformationMatrix.h"

Triangle::Triangle(Vector3d &v1,Vector3d &v2, Vector3d &v3) {
    this->vertexes[0] = v1;
    this->vertexes[1] = v2;
    this->vertexes[2] = v3;
}


Vector3d * Triangle::getVertexes() const {
    return (Vector3d *) vertexes;
}

Triangle Triangle::getProjectedTriangle(Matrix4x4 &projMatrix, Model * model) {
    TransformationMatrix transfMatrix;
    transfMatrix.setIdentity();
    transfMatrix.pushMatrix(TransformationMatrix::getScalingMatrix(model->getWidth()/2., model->getHeight()/2., 1));
    transfMatrix.pushMatrix(TransformationMatrix::getTranslationMatrix(1, 1, 0));
    transfMatrix.pushMatrix(projMatrix);
    transfMatrix.pushMatrix(TransformationMatrix::getTranslationMatrix(0, 0, 20));

    Matrix4x4 transf = transfMatrix.getTransformationMatrix();

    Vector3d v11 = transf * (vertexes[0]);
    Vector3d v21 = transf * (vertexes[1]);
    Vector3d v31 = transf * (vertexes[2]);

    return Triangle(v11, v21, v31);
}

Triangle::~Triangle() {
    
}