#include "model/Scene.h"

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


