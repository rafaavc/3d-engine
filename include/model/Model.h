#ifndef MODEL_H
#define MODEL_H

#include <string>

class Model {
private:
    std::string windowTitle;
    int width, height;
public:
    Model(std::string windowTitle, int width, int height);
    std::string getWindowTitle();
    int getWidth();
    int getHeight();
};

#endif
