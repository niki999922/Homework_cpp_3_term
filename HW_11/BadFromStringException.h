#pragma once

#include <exception>
#include <string>

class BadFromStringException : public std::exception {
public:
    BadFromStringException(const std::string);
    BadFromStringException(const char *);
    ~BadFromStringException() = default;
    virtual const char* what() const override;

    const std::string message;
};