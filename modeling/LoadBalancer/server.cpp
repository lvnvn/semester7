#include "server.h"
#include <iostream>

int Server::numberOfConnections()
{
    return connections.size();
}

void Server::update(double time)
{
    int i = 0;
    while(i < connections.size())
    {
        if(connections[i] < time)
        {
            connections.erase(connections.begin() + i);
            number_of_processed++;
        }
        else
            i++;
    }
}

void Server::recieve(double time)
{
    double responce = responceGenerator.generate();
    connections.push_back(time+responce);
    currently_connected_sum += connections.size();
    number_of_measurements++;
}
