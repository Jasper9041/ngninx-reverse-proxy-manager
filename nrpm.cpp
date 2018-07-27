#include <iostream>
#include <Exceptions/FileOpenException.h>

#include "Destination.h"
#include "Service.h"
#include "ConfigurationWriter.h"

#include <string>
using namespace std;

int main(int argc, char ** argv)
{

//    Destination d("test", 1234);
//
//    cout << d.toString();

    Service s("some-service");
    s.addHostname("some-host.name");
    s.addHostname("beaurain.servers.name.lol");
    Destination d("test", 1234);
    s.addDestination(d);

    try
    {
        ConfigurationWriter configurationWriter(s);
        configurationWriter.write();

    }
    catch(FileOpenException & e)
    {
        cout << e.what();
    }

//    cin.get();
};