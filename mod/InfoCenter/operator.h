#ifndef OPERATOR_H
#define OPERATOR_H
#include <random>

class Operator {
public:
    Operator(double _t, double _dt, double _comp): t(_t), dt(_dt), comp(_comp) {
        std::random_device rd;
        std::default_random_engine generator(rd());
        std::normal_distribution<double> distribution(t,sqrt(dt)); // нормальное распределение m+-s
        //std::uniform_real_distribution<> distribution(t-dt,t+dt);
        gen = generator;
        dist = distribution;
    }
    void recieve(double time);
    void process();
    double generateTime();
    double time_of_release = 0;
    int comp;

private:
    double t;
    double dt;
    std::default_random_engine gen;
    std::normal_distribution<double> dist;
    //std::uniform_real_distribution<> dist;
};

#endif // OPERATOR_H
