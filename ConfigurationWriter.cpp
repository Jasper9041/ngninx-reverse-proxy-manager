#include "ConfigurationWriter.h"

#include <iostream>
#include <fstream>
#include <string>
#include <Exceptions/FileOpenException.h>

using std::string;

void ConfigurationWriter::write()
{
    vector<string> lines;

    this->readTemplate(lines);

    for(string & line : lines)
    {
        this->writeName(line);
        this->writeServerNames(line);
        this->writeUpstreams(line);
    }

    this->writeToOutputFile(lines);
}

ConfigurationWriter::ConfigurationWriter(Service &service) : service(service)
{
}

void ConfigurationWriter::writeUpstreams(string &line)
{
    string upstreams;

    for(Destination &destination : this->service.getDestinations())
    {
        upstreams = upstreams.append("server ").append(destination.toString()).append("\n");
    }

    this->replaceInLine(line, "{{UPSTREAMS}}", upstreams);
}

void ConfigurationWriter::writeName(string &line)
{
    this->replaceInLine(line, "{{NAME}}", this->service.getName());
}

void ConfigurationWriter::writeServerNames(string &line)
{
    string hostnames;

    for(const string &hostname : this->service.getHostnames())
    {
        hostnames = hostnames.append(hostname).append(" ");
    }

    //remove last space
    if(hostnames.length() > 0)
    {
        hostnames = hostnames.erase(hostnames.length() - 1, 1);
    }

    this->replaceInLine(line, "{{SERVERNAMES}}", hostnames);
}

void ConfigurationWriter::replaceInLine(string &line, string original, string replacement)
{
    std::size_t position = line.find(original);
    if(position != string::npos)
    {
        line.replace(position, string(original).length(), replacement);
    }
}

void ConfigurationWriter::readTemplate(vector<string> &lines)
{
    this->readFromFile("base-template.conf", lines);

    if(this->service.acceptsHttp)
    {
        this->readFromFile("http-template.conf", lines);
    }

    if(this->service.acceptsHttps)
    {
        this->readFromFile("https-template.conf", lines);
    }

    if( ! this->service.acceptsHttp && this->service.acceptsHttps)
    {
        this->readFromFile("http-to-https-redirect-template.conf", lines);
    }
}

void ConfigurationWriter::readFromFile(string fileName, vector<string> & lines) {
    std::ifstream inputStream;
    inputStream.open(fileName);

    if(! inputStream.is_open())
    {
        throw FileOpenException(fileName);
    }

    string line;

    while(getline(inputStream, line))
    {
        lines.emplace_back(line);
    }

    inputStream.close();
}

void ConfigurationWriter::writeToOutputFile(vector<string> & lines)
{
    std::ofstream outputStream;
    outputStream.open(this->service.getConfigFileName());

    if(! outputStream.is_open())
    {
        throw FileOpenException(this->service.getConfigFileName());
    }

    for(string &line : lines)
    {
        outputStream << line << std::endl;
    }

    outputStream.close();
}
