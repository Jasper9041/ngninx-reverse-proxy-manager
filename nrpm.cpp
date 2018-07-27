#include <iostream>
#include <Exceptions/FileOpenException.h>

#include "Destination.h"
#include "Service.h"
#include "ConfigurationWriter.h"

#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

bool file_exists(string filename)
{
    ifstream f(filename);
    if(!f.is_open())
    {
        return false;
    }
    return f.good();
}

bool isStop(string & str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str.compare("stop") == 0;
}

int main(int argc, char ** argv)
{
    string path = "/etc/nginx/conf.d/";
    if(argc == 2)
    {
        path = string(argv[1]);
    }

    string name;
    cout << "Enter service name: ";
    getline(cin, name);

    Service service(name);

    cout << "Enter external hostnames for the service.\nType stop to finish adding hostnames.\n";
    string hostname;
    getline(cin, hostname);
    while(!isStop(hostname))
    {
        service.addHostname(hostname);
        getline(cin, hostname);
    }

    cout << "Enter upstream hosts for the service.\nType the ip or hostname on one line and the port on the next\nType stop twice to finish adding upstream hosts.\n";
    string address;
    string portString;
    cout << "Enter upstream address:";
    getline(cin, address);
    cout << "Enter upstream port:";
    getline(cin, portString);
    while( ! isStop(address) && ! isStop(portString))
    {
        Destination destination(address, stoi(portString));
        service.addDestination(destination);

        cout << "Enter upstream address:";
        getline(cin, address);
        cout << "Enter upstream port:";
        getline(cin, portString);
    }

    if(file_exists(service.getConfigFileName()))
    {
        cout << "File exists! Do you want to overwrite? (yes to overwrite)";
        string answer;
        getline(cin, answer);

        if(answer.compare("yes") != 0)
        {
            cout << "Cancelling!";
            exit(0);
        }

        cout << "Overwriting file!";
    }

    try
    {
        ConfigurationWriter configurationWriter(service);
        configurationWriter.write(path);

        cout << "\nFile written!";
    }
    catch(FileOpenException & e)
    {
        cout << e.what();
    }
};