#pragma once
#include <string>

#include "ConvertString.h"

template<class T>
T from_string(std::string data) {
    std::istringstream stringStream(data);
    if (typeid(T).name() != typeid(string).name())
        stringStream >> std::noskipws;
    T value;
    stringStream >> value;
    if (stringStream.fail() || (stringStream.get() && !stringStream.eof())) {
        std::stringstream tmp;
        tmp << "Can't convert from string to " << typeid(T).name() << ".";
        throw BadFromStringException(tmp.str());
    }
    return value;
}
