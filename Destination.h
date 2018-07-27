#ifndef __Destination_h_INCLUDED__
#define __Destination_h_INCLUDED__

#include <string>

using std::string;

class Destination
{
    private:
        string address;
        int port;

    public:
        Destination() = delete;
        Destination(string address, int port);
        string toString();

};

#endif
