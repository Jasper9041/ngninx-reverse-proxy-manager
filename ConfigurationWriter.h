#ifndef NGNINX_REVERSE_PROXY_MANAGER_CONFIGURATIONWRITER_H
#define NGNINX_REVERSE_PROXY_MANAGER_CONFIGURATIONWRITER_H


#include "Service.h"
#include <string>

using std::string;

class ConfigurationWriter
{
    private:
        Service service;

        void writeServerNames(string & line);
        void writeName(string & line);
        void writeUpstreams(string & line);
        void replaceInLine(string & line, string original, string replacement);
        void readFromFile(string fileName, vector<string> & lines);
        void writeToOutputFile(vector<string> & lines);
        void readTemplate(vector<string> & lines);
    public:
        ConfigurationWriter() = delete;
        ConfigurationWriter(Service &service);
        void write();
};


#endif
