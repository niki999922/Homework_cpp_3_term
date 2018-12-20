#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <stdexcept>
#include <ctime>
#include <queue>

#include "DiscreteMetric.h"
#include "MyMetric.h"
#include "EuclideanMetric.h"
#include "EnumerationAlgorithm.h"
#include "DijkstraAlgorithm.h"
#include "FastAlgorithm.h"



// example: program.exe -map "Somemap.txt" -a Dijkstra -m Euclidean -o resultfile.txt
// Cpptask10.exe -map "Test1.txt" -a Dijkstra -m Euclidean -o resultfile.txt

// "-map" -  file with coordinate of points
// "-o" -  output file for result
// "-a" - algorithm 
// "-m" - metric
// "--help" - for getting help

//"Initialization.conf" - config file with: algorithm 
//                                          metric                         


std::vector<std::string> split(std::string str) {
    std::vector<std::string> v;
    std::queue<size_t> q;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == ' ') q.push(i);
    }
    size_t left = 0;
    while (!q.empty()) {
        size_t pos = q.front();
        q.pop();
        v.push_back(str.substr(left, pos - left));
        left = pos + 1;
    }
    if (str[str.size() - 1] != ' ') {
        v.push_back(str.substr(left, str.size() - left));
    }
    return v;
}

inline void parseConfigurations(std::map<std::string, std::vector<std::string>>& configurations, std::string conf = "Initialization.txt") {
    std::ifstream input(conf);
    if (!input.is_open()) throw std::invalid_argument("Can't find \"Initialization.txt\" or another init file.");
    size_t n, m;
    std::string tmp, key;
    input >> n;
    for (size_t i = 0; i < n; ++i) {
        input >> m >> key;
        std::vector<std::string> vec;
        for (size_t j = 0; j < m - 1; ++j) {
            input >> tmp;
            vec.push_back(tmp);
        }
        configurations.insert(std::pair<std::string, std::vector<std::string>>(key, vec));
    }
    std::cout << "Complete parse input configuration file.\n";
    input.seekg(0, std::ios_base::end);
    std::cout << "File size (byte): " << input.tellg() << "\n\n";
    input.close();
}

inline void parseInputArgs(std::map<std::string, std::string>& configurations, std::map<std::string, std::vector<std::string>>& configs, size_t& argsSize, char* args[]) {
    size_t tmp1, tmp2;
    if (argsSize % 2 == 0) throw std::invalid_argument("Can't correct read input flags.");
    for (size_t i = 1; i < argsSize; i+=2) {
        tmp1 = configs.count(args[i]);
        tmp2 = configs.count(args[i + 1]);
        if (!(tmp1 ^ tmp2) || tmp2) {
            throw std::invalid_argument("Can't correct read input flags.");
        } else {
            configurations.insert(std::pair<std::string, std::string>(args[i], args[i + 1]));
        }
    }
    std::cout << "Complete reading input flags.\n\n";
}

inline bool findWord(size_t& argsSize, char* args[], std::string str) {
    for (size_t i = 1; i < argsSize; ++i) {
        if (args[i] == str) 
            return true;
    }
    return false;
}

void printHelp() {
    std::cout << "Usage: Cpptask10.exe [options] ...\n"
         << "Options:\n"
         << " --help         Display this information.\n"
         << " -map           File with coordinate of points.\n"
         << " -o             Output file for result.\n"
         << " -a             Algorithm.\n"
         << " -m             Metric.\n";
}


int main(size_t argc, char* argv[]) {
    unsigned int startTime = clock(), endTime = 0;
    std::map<std::string, std::string> inputDataConfigurations;
    std::map<std::string, std::vector<std::string>> configurations;
    try {
        parseConfigurations(configurations);    
        if (argc == 1) {
            throw std::invalid_argument("not enough arguments");
        }
        if (findWord(argc, argv, "--help")) {
            printHelp();
        } else {    
            parseInputArgs(inputDataConfigurations, configurations, argc, argv);
            std::string algorithm = "Dijkstra", metric = "Euclidean", mapFile, outputName = "";
            if (inputDataConfigurations.count("-a")) {
                algorithm = inputDataConfigurations.at("-a");
                std::vector<std::string> tmp = configurations.at("-a");
                bool flag = true;
                for (auto it : tmp) {
                    if (it == algorithm) {
                        flag = false;
                        break;
                    }
                }
                if (flag) throw std::invalid_argument("Can't find algorithm.");
            }
            if (inputDataConfigurations.count("-m")) {
                metric = inputDataConfigurations.at("-m");
                std::vector<std::string> tmp = configurations.at("-m");
                bool flag = true;
                for (auto it : tmp) {
                    if (it == metric) {
                        flag = false;
                        break;
                    }
                }
                if (flag) throw std::invalid_argument("Can't find metric.");
            }
            if (inputDataConfigurations.count("-map")) {
                mapFile = inputDataConfigurations.at("-map");
            } else {
                throw std::invalid_argument("Can't find map file.");
            }
            if (inputDataConfigurations.count("-o")) {
                outputName = inputDataConfigurations.at("-o");
            }

            MetricsI* metricsClass = nullptr;
            OptimizeAlgorithmI* algorithmClass = nullptr;
            std::vector<Point> points;
            size_t upperBound;
            Point::readPoints(mapFile, points, upperBound);

            // I don't know dynamic initialization of class.
            if (algorithm == "Enumeration") {
                algorithmClass = new EnumerationAlgorithm();
            } else if (algorithm == "Dijkstra") {
                algorithmClass = new DijkstraAlgorithm();
            } else if (algorithm == "Fast") {
                algorithmClass = new FastAlgorithm();

            }

            if (metric == "Euclidean") {
                metricsClass = new EuclideanMetric();
            } else if (metric == "Discrete") {
                metricsClass = new DiscreteMetric();
            } else if (metric == "My") {
                metricsClass = new MyMetric();
            }

            std::cout << "Algorithm : " << algorithmClass->getName() << '\n';
            std::cout << "Metric    : " << metricsClass->getName()   << '\n';
            std::cout << "\nSolving...\n\n";
            std::vector<std::vector<Point>> result = algorithmClass->optimizeRoutes(upperBound, points, metricsClass);
            if (outputName == "") {
                for (size_t i = 0; i < result.size(); ++i) {
                    std::cout << "Route ¹:" << i + 1 << ":\n";
                    for (auto& point : result[i]) {
                        std::cout << "(" << std::fixed << point.x << "; " << point.y << ")\n";
                    }
                    std::cout << '\n';
                }
            } else {
                std::ofstream output(outputName);
                for (size_t i = 0; i < result.size(); ++i) {
                    output << "Route ¹" << i + 1 << ":\n";
                    for (auto& point : result[i]) {
                        output << "(" << std::fixed << point.x << "; " << point.y << ")\n";
                    }
                    output << std::endl;
                }
            }
        }
    } catch (std::invalid_argument& e) {
        std::cout << "Fatal error: "<< e.what() <<'\n';
    } catch (...) {
        std::cout << "Error!\n";
    }
    endTime = clock();
    std::cout << "Ticks : " << (endTime - startTime) << '\n';
    std::cout << "Time : " << (static_cast<float>(endTime - startTime)) / CLOCKS_PER_SEC << " seconds.\n";
    return 0;
}