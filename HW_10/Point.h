#pragma once

#include <string>
#include <vector>

class Point {
public:
    double x, y;
    Point() {};
    Point(double x, double y);
    static void readPoints(const std::string& name, std::vector<Point>& points, size_t& border);
};



