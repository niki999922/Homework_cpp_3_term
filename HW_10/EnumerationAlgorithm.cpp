#include "EnumerationAlgorithm.h"
#include <algorithm>
#include <iostream>

std::string EnumerationAlgorithm::getName() {
    return "Enumeration";
}

std::vector<std::vector<Point>> EnumerationAlgorithm::optimizeRoutes(size_t upperBound, const std::vector<Point>& points, MetricsI* metric) {
    std::cout << "Start computing...\n";
    std::vector<int> permutation(points.size());
    std::vector<int> answer(points.size());
    std::vector<std::vector<Point>> routes;
    double length = -1;
    int size = 1;
    std::cout << "Initialization\n";
    for (size_t i = 0; i < points.size(); ++i) {
        permutation[i] = i;
    }
    do {
        double currentLength = 0;
        for (size_t i = 0; i < permutation.size() - 1; ++i) {
            if (size == upperBound) {
                size = 1;
                continue;
            }
            ++size;
            currentLength += metric->calculateDistance(points[permutation[i]], points[permutation[i + 1]]);
        }
        if (length == -1) {
            length = currentLength;
            answer = permutation;
        } else if (length > currentLength) {
            length = currentLength;
            answer = permutation;
        }
        size = 1;
    } while (std::next_permutation(permutation.begin(), permutation.end()));
    size = 0;
    std::vector<Point> temporary;

    for (size_t i : answer) {
        if (size == upperBound) {
            routes.push_back(temporary);
            temporary.clear();
            size = 0;
        }
        ++size;
        temporary.push_back(points[i]);
    }
    if (!temporary.empty()) {
        routes.push_back(temporary);
    }
    std::cout << "End computing\n\n";
    return routes;
}
