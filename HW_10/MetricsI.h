#pragma once

#include "Point.h"
#include <string>

class MetricsI {
public:
    virtual std::string getName() = 0;
    virtual double calculateDistance(const Point& p1, const Point& p2) = 0;
protected:
    const double EPS = 1e-9;
};



