#include <limits.h>
#include <algorithm>
#include <iostream>

#include "DijkstraAlgorithm.h"

std::string DijkstraAlgorithm::getName() {
    return "Dijkstra";
}


std::vector<std::vector<Point>> DijkstraAlgorithm::optimizeRoutes(size_t upperBound, const std::vector<Point>& points, MetricsI* metric) {
    std::vector<Point> currentPoints = points;
    std::vector<std::vector<Point>> routes;
    std::vector<Point> tmpPath;
    size_t nTime = 0;
    size_t curBound, randomBound;
    size_t start;
    bool flagStep = true;
    while (!currentPoints.empty()) {
        size_t n = currentPoints.size();
        if (flagStep) {
            randomBound = rand() % (std::min(n, upperBound)) + 1;
            tmpPath.clear();
            curBound = 0;
            flagStep = false;
            start = rand() % n;
            ++nTime;
            std::cout << "Start computing number " << nTime << "...\n";
        }
        std::vector<std::vector<std::pair<int, double>>> graph(n);        
        std::vector<int> p(n, -1);
        std::vector<double> d(n, DBL_MAX);
        std::vector<bool> used(n);
        d[start] = 0;
        //std::cout << "Initialization\n";
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (i != j) {
                    graph[i].emplace_back(j, metric->calculateDistance(currentPoints[i], currentPoints[j]));
                }

            }
        }
        //std::cout << "Finding shortest path\n";
        for (size_t i = 0; i < n; ++i) {
            int v = -1;
            for (size_t j = 0; j < n; ++j) {
                if (!used[j] && (v == -1 || d[j] < d[v])) {
                    v = j;
                }
            }
            if (d[v] == DBL_MAX) {
                break;
            }
            used[v] = true;
            for (size_t j = 0; j < graph[v].size(); ++j) {
                size_t to = graph[v][j].first;
                double curLength = graph[v][j].second;
                if (d[v] + curLength < d[to]) {
                    p[to] = v;
                    d[to] = d[v] + curLength;
                }
            }
        }
        //std::cout << "Recover path\n";
        bool flag = true;
        std::vector<size_t> path;
        while (flag) {
            size_t t;
            if (n != 1) t = rand() % (n - 1); else t = rand() % n;
            if (n == 2) t = rand() % 2;
            path.clear();
            for (size_t v = t; v != start; v = p[v]) {
                path.push_back(v);
            }
            path.push_back(start);
            if (path.size() > upperBound || (path.size() == 1 && n != 1)) continue;
            std::reverse(path.begin(), path.end());
            flag = false;
        }
        tmpPath.push_back(currentPoints[path[0]]);
        if (path.size() == 1) {
            start = path[0];
        } else {
            start = path[1];
        }
        ++curBound;
        if (curBound == randomBound) {
            if (n == 2) start = 0;
            flagStep = true;
            routes.push_back(tmpPath);
        }
        //std::cout << "Add path\n";
        currentPoints.erase(currentPoints.begin());
        //std::cout << "End computing\n\n";
    }
    return routes;
}
