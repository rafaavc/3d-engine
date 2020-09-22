#include "controller/TriangleController.h"
#include "controller/TransformationMatrix.h"


Triangle TriangleController::getProjectedTriangle(Triangle &triangle, Matrix4x4 &projMatrix, Model * model) {
    TransformationMatrix transfMatrix;
    transfMatrix.setIdentity();
    transfMatrix.pushMatrix(TransformationMatrix::getScalingMatrix(model->getWidth()/2., model->getHeight()/2., 1));
    transfMatrix.pushMatrix(TransformationMatrix::getTranslationMatrix(1, 1, 0));
    transfMatrix.pushMatrix(projMatrix);

    Triangle res = transfMatrix * triangle;
    res.setColor(triangle.getColor());
    return res;
}

void TriangleController::getColoredTriangle(Scene * scene, Triangle & triangle) {
    Vector3d vertex1 = triangle.getVertexes()[0];

    Vector3d vertex2 = triangle.getVertexes()[1];
    Vector3d vertex3 = triangle.getVertexes()[2];

    Vector3d v1 = vertex2 - vertex1;
    Vector3d v2 = vertex3 - vertex2;

    Vector3d normal = Vector3d::crossProd(v2, v1);
    normal.setState(Vector3d::GET_NORMALIZED);

    float factor = 0;
    for (Light * light : scene->getLights()) {
        Vector3d lightDir = light->getDirection();
        lightDir = lightDir.invert();
        lightDir.setState(Vector3d::GET_NORMALIZED);
        float angleCos = Vector3d::scalarProd(lightDir, normal);
        if (angleCos > 0) factor += angleCos*light->getDirect();
    }

    triangle.setColor(RGBAColor(factor*255, factor*255, factor*255));
}


bool TriangleController::backfaceCull(const Vector3d &cameraDir, const Vector3d &cameraPosition, const Triangle &triangle) {
    Vector3d vertex1 = triangle.getVertexes()[0];

    Vector3d vectorFromCameraToFace = vertex1 - cameraPosition;

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

