#ifndef SCENE_H
#define SCENE_H

#include "Object.h"
#include "Light.h"
#include "Observer.h"

class Scene {
private:
    std::vector<Object *> sceneObjects;
    std::vector<Light *> sceneLights;
    Observer * observer;
public:
    void addObject(Object * obj);
    void addLight(Light * light);
    std::vector<Light *> &getLights();
    Observer * getObserver();
    void setObserver(Observer * observerPosition);
    ~Scene();
};

#endif