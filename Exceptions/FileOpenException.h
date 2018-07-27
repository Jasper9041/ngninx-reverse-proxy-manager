//
// Created by ik on 27/07/2018.
//

#ifndef NGNINX_REVERSE_PROXY_MANAGER_FILEOPENEXCEPTION_H
#define NGNINX_REVERSE_PROXY_MANAGER_FILEOPENEXCEPTION_H


#include <exception>
#include <stdexcept>
#include <string>

class FileOpenException : public std::runtime_error {
    public:
        FileOpenException() = delete;
        FileOpenException(std::string fileName);
};


#endif
