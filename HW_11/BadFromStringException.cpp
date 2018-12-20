#include <string>

#include "BadFromStringException.h"

const char* BadFromStringException::what() const {
    return message.c_str();
}

BadFromStringException::BadFromStringException(const std::string data) : message(data) {}

BadFromStringException::BadFromStringException(const char* data) : message(data) {}