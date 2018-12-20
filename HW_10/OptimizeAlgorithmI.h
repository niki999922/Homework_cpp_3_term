#pragma once

#include <string>
#include <vector>
#include "Point.h"
#include "MetricsI.h"

class OptimizeAlgorithmI {
public:
    virtual std::string getName() = 0;
    virtual std::vector<std::vector<Point>> optimizeRoutes(size_t k, const std::vector<Point>& points, MetricsI* metric) = 0;
};