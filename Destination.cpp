#include "Destination.h"
#include <string>

using std::string;

Destination::Destination(string address, int port)
{
    this->address = address;
    this->port = port;
}

string Destination::toString()
{
    return this->address + ":" + std::to_string(this->port);
};