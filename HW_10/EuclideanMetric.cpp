#include "EuclideanMetric.h"
#include <cmath>

std::string EuclideanMetric::getName() {
    return "Euclidean";
}

double EuclideanMetric::calculateDistance(const Point& p1, const Point& p2) {
    if ((abs(p1.x - p2.x) < EPS) && (abs(p1.y - p2.y) < EPS)) {
        return 0;
    } else {
        return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }
}
