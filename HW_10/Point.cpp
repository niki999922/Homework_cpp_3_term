#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "Point.h"

Point::Point(double x, double y) : x(x), y(y) {}

void Point::readPoints(const std::string& name, std::vector<Point>& points, size_t& border) {
    std::ifstream file(name);
    if (!(file.is_open())) throw std::invalid_argument("Can't open map file.");
    size_t n;
    double x, y;
    file >> n >> border;
    for (size_t i = 0; i < n; ++i) {
        file >> x >> y;
        points.push_back(Point(x, y));
    }
    std::cout << "Complete reading map file.\n";
    file.seekg(0, std::ios_base::end);
    std::cout << "File size (byte): " << file.tellg() << "\n";
    std::cout << "File size (Kbyte): " << file.tellg()/1024 << "\n\n";
}