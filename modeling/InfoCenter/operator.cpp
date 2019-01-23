#include "operator.h"
#include <random>

double Operator::generateTime()
{
    return dist(gen);
}

void Operator::recieve(double time)
{
    time_of_release = round(time + generateTime());
}
