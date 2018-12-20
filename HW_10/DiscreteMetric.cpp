#include "DiscreteMetric.h"
#include <cmath>

std::string DiscreteMetric::getName() {
    return "Discrete";
}

double DiscreteMetric::calculateDistance(const Point& p1,const Point& p2) {
    if ((abs(p1.x - p2.x) < EPS) && (abs(p1.y - p2.y) < EPS)) {
        return 0;
    } else {
        return 1;   
    }
}

