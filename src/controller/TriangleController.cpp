#include "controller/TriangleController.h"
#include "controller/TransformationMatrix.h"


Triangle TriangleController::getProjectedTriangle(Triangle &triangle, Matrix4x4 &projMatrix, Model * model) {
    TransformationMatrix transfMatrix;
    transfMatrix.setIdentity();
    transfMatrix.pushMatrix(TransformationMatrix::getScalingMatrix(model->getWidth()/2., model->getHeight()/2., 1));
    transfMatrix.pushMatrix(TransformationMatrix::getTranslationMatrix(1, 1, 0));
    transfMatrix.pushMatrix(projMatrix);

    return transfMatrix * triangle;
}


bool TriangleController::backfaceCull(Vector3d &cameraDir, Vector3d &cameraPosition, Triangle &triangle) {
    Vector3d vertex1 = triangle.getVertexes()[0];

    Vector3d vectorFromCameraToFace = vertex1 - cameraPosition;

    cameraDir.setState(Vector3d::GET_NORMALIZED);
    vectorFromCameraToFace.setState(Vector3d::GET_NORMALIZED);

    if (Vector3d::scalarProd(vectorFromCameraToFace, cameraDir) <= 0) return true;


    Vector3d vertex2 = triangle.getVertexes()[1];
    Vector3d vertex3 = triangle.getVertexes()[2];

    Vector3d v1 = vertex2 - vertex1;
    Vector3d v2 = vertex3 - vertex2;

    Vector3d normal = Vector3d::crossProd(v2, v1);
    normal.setState(Vector3d::GET_NORMALIZED);

    Vector3d vectorFromFaceToCamera = vectorFromCameraToFace.invert();

    return Vector3d::scalarProd(vectorFromFaceToCamera, normal) <= 0;
}

