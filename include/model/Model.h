#ifndef MODEL_H
#define MODEL_H

#include <string>

using namespace std;

class Model {
private:
    string windowTitle;
    int width, height;
public:
    Model(string windowTitle, int width, int height);
    string getWindowTitle();
    int getWidth();
    int getHeight();
};

#endif
