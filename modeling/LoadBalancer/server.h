#ifndef SERVER_H
#define SERVER_H
#include <vector>
#include "generator.h"

class Server{
public:
    Server(int _weight): weight(_weight) {}
    Server(){}
    int numberOfConnections();
    void update(double time); // удалить все заявки, обработка которых на момент time окончена
    void recieve(double time);
    int weight;
    //stats
    int currently_connected_sum = 0;
    int number_of_measurements = 0;
    int number_of_processed = 0;

private:
    std::vector<double> connections;
    Generator responceGenerator = Generator(2000,400);
};

#endif // SERVER_H
