#include "model/Scene.h"
#include <iostream>

Scene::~Scene() {
    for (Object * obj : sceneObjects) delete obj;
    for (Light * light : sceneLights) delete light;
}

void Scene::addObject(Object * obj) {
    sceneObjects.push_back(obj);
}

void Scene::addLight(Light * light) {
    sceneLights.push_back(light);
}

std::vector<Light *> & Scene::getLights() {
    return sceneLights;
}

void Scene::setObserver(Observer * observer) {
    this->observer = observer;
}

Observer * Scene::getObserver() {
    return observer;
}

const std::vector<Triangle> &Scene::getTriangles() const {
    return sceneObjects.at(0)->getTriangles();
}


