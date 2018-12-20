#pragma once

#include "MetricsI.h"

class DiscreteMetric : public MetricsI {
public:
    std::string getName() override;
    double calculateDistance(const Point&, const Point&) override;
};