#pragma once

#include "MetricsI.h"

class MyMetric : public MetricsI {
    std::string getName() override;
    double calculateDistance(const Point&, const Point&) override;
};



