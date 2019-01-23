#include "generator.h"
#include <random>
#include <iostream>

double Generator::generateRequest() {
    return dist(gen);
}
