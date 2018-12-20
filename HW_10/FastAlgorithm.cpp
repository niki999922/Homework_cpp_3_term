#include "FastAlgorithm.h"
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>


std::string FastAlgorithm::getName() {
    return "Fast";
}

std::vector<std::vector<Point>> FastAlgorithm::optimizeRoutes(size_t upperBound, const std::vector<Point>& points, MetricsI* metric) {
    std::vector<Point> currentPoints = points;
    std::vector<std::vector<Point>> routes;
    size_t nTime = 1;
    size_t n = ceil(static_cast<double>(points.size()) / upperBound);
    for (size_t i = 0; i < n; ++i) {
        std::cout << "Start computing number " << nTime << "...\n";
        ++nTime;
        //std::cout << "Initialization\n";
        if (currentPoints.size() < upperBound) upperBound = currentPoints.size();
        std::vector<bool> used(currentPoints.size(), false);
        std::vector<Point> route;
        std::vector<size_t> positions;
        size_t tmp = 0;
        //std::cout << "Finding shortest path\n";
        while (tmp < upperBound) {
            size_t pos = rand() % currentPoints.size();
            if (used[pos]) continue;
            used[pos] = true;
            positions.push_back(pos);
            ++tmp;
            route.push_back(currentPoints[pos]);
        }
        //std::cout << "Add path\n";
        routes.push_back(route);
        std::sort(positions.begin(), positions.end(), [](size_t a, size_t b) {
            return a > b;
        });
        for (size_t j = 0; j < positions.size(); ++j) {
            currentPoints.erase(currentPoints.begin() + positions[j]);
        }
    }
    std::cout << "End computing\n\n";
    return routes;
}
