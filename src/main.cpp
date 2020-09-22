#include "controller/Controller.h"
#include "controller/FileManager.h"

using namespace std;

int main(int argc, char ** argv) {
    Model * model = new Model("3D Engine", WIDTH, HEIGHT);
    
	Graphics * graphics = new SDLAdapter();

    Light * myLight = new Light(1, 1, Vector3d(0, 0, 0), Vector3d(0, 0, 1));
    Object * cube = new Object();

    cube->addVertex(-1, -1, -1); // 0
    cube->addVertex(1, -1, -1); // 1
    cube->addVertex(-1, -1, 1); // 2
    cube->addVertex(1, -1, 1); // 3
    cube->addVertex(-1, 1, -1); // 4
    cube->addVertex(1, 1, -1); // 5
    cube->addVertex(-1, 1, 1); // 6
    cube->addVertex(1, 1, 1); // 7

    cube->addTriangle(0, 2, 1); // bottom
    cube->addTriangle(1, 2, 3);

    cube->addTriangle(0, 1, 4); // backfacing
    cube->addTriangle(1, 5, 4);

    cube->addTriangle(1, 3, 5); // rightfacing
    cube->addTriangle(3, 7, 5);

    cube->addTriangle(3, 2, 7); // frontfacing
    cube->addTriangle(2, 6, 7);

    cube->addTriangle(2, 0, 4); // leftfacing
    cube->addTriangle(2, 4, 6);

    cube->addTriangle(4, 5, 6); // top
    cube->addTriangle(5, 7, 6);


    Scene * scene = new Scene();
    scene->addLight(myLight);

    if (argc > 1) {
        Object * obj;
        std::string s(argv[1]);
        obj = FileManager::getObjectFromObjFile(s);
        scene->addObject(obj);
    } else scene->addObject(cube);

    Observer * camera = new Observer(Vector3d(0, 0, 0), Vector3d(0, 0, 1));
    scene->setObserver(camera);

    Engine * engine = new Engine(model, scene);

    View * view = new View(model, engine, graphics);

    Controller * controller = new Controller(model, view);
    
    controller->start();

    return EXIT_SUCCESS;
}

