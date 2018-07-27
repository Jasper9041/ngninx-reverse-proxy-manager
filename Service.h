#ifndef __Service_h_INCLUDED__
#define __Service_h_INCLUDED__

#include "Destination.h"
#include <vector>

using std::vector;
using std::string;

class Service
{
    // Name
    // Domain names
    // Destinations
    private:
        string name;
        vector<string> hostnames;
        bool enableSsl;
        vector<Destination> destinations;

    public:
        Service(string &name);
        Service(string name);
        string getName();
        vector<string> getHostnames();
        void addHostname(string hostname);
        void addDestination(Destination &destination);
        vector<Destination> getDestinations();

};

#endif
