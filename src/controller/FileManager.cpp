#include "controller/FileManager.h"
#include <fstream>
#include <sstream>

std::vector<std::string> FileManager::readFileContents(std::string filePath) {
    std::ifstream myFile(filePath);
    std::vector<std::string> res;

    if (!myFile.is_open()) throw ErrorOpeningFileException();

    std::string str;
    while(getline(myFile, str)) {
        res.push_back(str);
    }

    myFile.close();
    return res;
}

Object * FileManager::getObjectFromObjFile(std::string filePath) {
    std::vector<std::string> fileContent = FileManager::readFileContents(filePath);
    Object * res = new Object();

    int count = 0;
    for (std::string & line : fileContent) {
        float values[3];
        char holder;
        std::stringstream lineStream(line);
        std::string subStr;

        switch(line[0]) {
            case 'v':
                lineStream >> holder >> values[0] >> values[1] >> values[2];
                res->addVertex(values[0], values[1], values[2]);
                break;
            case 'f':
                lineStream >> holder;
                for (int i = 0; i < 3; i++) {
                    subStr.clear();
                    lineStream >> subStr;
                    int place = subStr.find('/');
                    values[i] = (float)stoi(subStr.substr(0, place));
                }
                res->addTriangle((unsigned)values[0]-1, (unsigned)values[1]-1, (unsigned)values[2]-1);
                break;
            default:
                break;
        }
        count++;
    }
    return res;
}



