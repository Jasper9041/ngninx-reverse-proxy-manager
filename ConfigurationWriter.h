#ifndef NGNINX_REVERSE_PROXY_MANAGER_CONFIGURATIONWRITER_H
#define NGNINX_REVERSE_PROXY_MANAGER_CONFIGURATIONWRITER_H


#include "Service.h"
#include <string>

using std::string;

class ConfigurationWriter
{
    private:
        std::string templateFileName;
        Service service;

        void writeServerNames(string & line);
        void writeName(string & line);
        void writeUpstreams(string & line);
        void replaceInLine(string & line, string original, string replacement);
    public:
        ConfigurationWriter() = delete;
        ConfigurationWriter(Service &service);
        ConfigurationWriter(Service &service, string templateFileName);
        void write();
};


#endif
