#include "controller/Controller.h"

using namespace std;

int main() {
    Model * model = new Model("Testin'", 1920, 1080);
    
	Graphics * graphics = new SDLAdapter();

    Light * myLight = new Light(0.2, 0.4, new Vector(-10, 10, 10), new UnitarianVector(1, -1, -1));
    Object * myObject = new Object();

    myObject->addVertex(-1, -1, -1); // 0
    myObject->addVertex(1, -1, -1); // 1
    myObject->addVertex(-1, -1, 1); // 2
    myObject->addVertex(1, -1, 1); // 3
    myObject->addVertex(-1, 1, -1); // 4
    myObject->addVertex(1, 1, -1); // 5
    myObject->addVertex(-1, 1, 1); // 6
    myObject->addVertex(1, 1, 1); // 7

    myObject->addEdge(0, 1); // 0
    myObject->addEdge(0, 2); // 1
    myObject->addEdge(0, 4); // 2
    myObject->addEdge(3, 1); // 3
    myObject->addEdge(3, 2); // 4
    myObject->addEdge(3, 7); // 5
    myObject->addEdge(7, 6); // 6
    myObject->addEdge(7, 5); // 7
    myObject->addEdge(4, 5); // 8
    myObject->addEdge(4, 6); // 9
    myObject->addEdge(1, 5); // 10
    myObject->addEdge(2, 6); // 11

    myObject->addPolygon(0, 1, 2);
    // (...)

    Scene * scene = new Scene();
    scene->addLight(myLight);
    scene->addObject(myObject);
    Observer * myObserver = new Observer(new Vector(-2, 5, 8), new UnitarianVector(2, -5, -8));
    scene->setObserver(myObserver);

    Engine * engine = new Engine(model, graphics, scene);

    View * view = new View(model, engine, graphics);

    Controller * controller = new Controller(model, view);

    controller->start();

    delete model;
    delete graphics;
    delete engine;
    delete view;
    delete controller;
    delete scene;

    return EXIT_SUCCESS;
}

