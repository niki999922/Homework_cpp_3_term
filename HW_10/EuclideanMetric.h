#pragma once

#include "MetricsI.h"

class EuclideanMetric : public MetricsI {
public:
    std::string getName() override;
    double calculateDistance(const Point&, const Point&) override;
};