#include "model/Object.h"
#include <exception>
#include <string>

class ErrorOpeningFileException : public std::exception {};

class FileManager {
public:
    static std::vector<std::string> readFileContents(std::string filePath);
    static Object * getObjectFromObjFile(std::string filePath);
};



