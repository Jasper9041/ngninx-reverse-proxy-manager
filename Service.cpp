#include "Service.h"

#include <iostream>

string Service::getName()
{
    return this->name;
}

vector<string> Service::getHostnames()
{
    return this->hostnames;
}

void Service::addHostname(string hostname)
{
    this->hostnames.emplace_back(hostname);
}

void Service::addDestination(Destination &destination)
{
    this->destinations.emplace_back(destination);
}

vector<Destination> Service::getDestinations()
{
    return this->destinations;
}

Service::Service(string name) : name(name), acceptsHttp(false), acceptsHttps(true)
{}

string Service::getConfigFileName()
{
    return this->getName().append(".conf");
}
