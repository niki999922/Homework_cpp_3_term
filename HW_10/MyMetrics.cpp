#include "MyMetric.h"
#include <cmath>

std::string MyMetric::getName() {
    return "MyMetric";
}

double MyMetric::calculateDistance(const Point& p1, const Point& p2) {
    if ((abs(p1.y - p2.y) < EPS) && (abs(p1.x - p2.x) < EPS)) {
        return 0;
    } else {
        return abs(p1.x - p2.x) + abs(p1.y - p2.y);
    }
}
