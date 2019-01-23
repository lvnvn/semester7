#ifndef GENERATOR_H
#define GENERATOR_H

#include <random>

class Generator
{
public:
    Generator(double _t, double _dt): t(_t), dt(_dt) {
        std::random_device rd;
        std::default_random_engine generator(rd());
        //std::normal_distribution<double> distribution(t,sqrt(dt)); // нормальное распределение m+-s
        std::uniform_real_distribution<> distribution(t-dt,t+dt);
        gen = generator;
        dist = distribution;
    }
    double generate();
private:
    double t;
    double dt;
    std::default_random_engine gen;
    //std::normal_distribution<double> dist;
    std::uniform_real_distribution<> dist;

};

#endif // GENERATOR_H
