#ifndef COMPUTER_H
#define COMPUTER_H

class Computer {
public:
    Computer(double _t): t(_t) {}
    void recieve(double time);
    void process();

private:
    double t;
    int requests = 0;
};
#endif // COMPUTER_H
