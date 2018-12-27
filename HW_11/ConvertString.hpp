#pragma once
#include <string>
#include <sstream>

#include "ConvertString.h"

template<class T>
T from_string(std::string string) {
    std::istringstream stream(string);
    stream.exceptions(std::istringstream::failbit | std::istringstream::badbit);
    T value;
    try {
        stream >> std::noskipws >> value;
    } catch (std::istringstream::failure const& e) {
        if (stream.fail()) {
            throw BadFromStringException("Impossible to convert string to " + std::string(typeid(T).name()) + ".");
        }
        throw BadFromStringException("Read Error.");
    }
    if (stream.good() && stream.peek() != EOF) {
        throw BadFromStringException("Impossible to convertstring to type, wrong argument.");
    }
    return value;
}