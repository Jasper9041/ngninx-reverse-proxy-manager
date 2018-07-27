#include "FileOpenException.h"
#include <string>

FileOpenException::FileOpenException(std::string fileName) :
    std::runtime_error("Unable to open file: " + fileName)
{

}
