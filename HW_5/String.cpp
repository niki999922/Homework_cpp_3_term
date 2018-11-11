#include<cstring>
#include <iostream>

#include"String.h"

String::String() {
    string = nullptr;
    size = 0;
}

String::String(const char c, const size_t size) {
    string = new char[size + 1];
    for (register int i = 0; i < size; ++i) {
        string[i] = c;
    }
    string[size] = '\0';
    this->size = size;
}

String::String(const char* string) {
    this->string = new char[std::strlen(string) + 1];
    register int i = 0;
    while (string[i]) {
        this->string[i] = string[i];
        ++i;
    }
    this->string[i] = '\0';
    size = i;
}

String::~String() { 
    delete[] string; 
}

size_t String::getSize() {
    return size;
}

char* String::getString() {
    return string;
}

//assignment
String& String::operator=(const String& string) {
    delete[] this->string;
    this->string = new char[string.size + 1];
    this->size = string.size;
    for (register int i = 0; i < string.size; ++i) {
        this->string[i] = string.string[i];
    }
    this->string[this->size] = '\0';
    return *this;
}

//copied
String::String(const String& string) {
    this->string = new char[string.size + 1];
    this->size = string.size;
    for (register int i = 0; i < string.size; ++i) {
        this->string[i] = string.string[i];
    }
    this->string[this->size] = '\0';
}

void String::append(const char* string) {
    size_t updateSize = std::strlen(string) + this->size + 1;
    char* updateString = new char[updateSize];
    for (register int i = 0; i < this->size; ++i) {
        updateString[i] = this->string[i];
    }
    for (register int i = 0; i < std::strlen(string); ++i) {
        updateString[i + this->size] = string[i];
    }
    updateString[updateSize] = '\0';
    delete[] this->string;
    this->size = updateSize;
    this->string = updateString;
}

void String::append(const String& string) {
    size_t updateSize = string.size + this->size;
    char* updateString = new char[updateSize + 1];
    for (register int i = 0; i < this->size; ++i) {
        updateString[i] = this->string[i];
    }
    for (register int i = 0; i < string.size; ++i) {
        updateString[i + this->size] = string.string[i];
    }
    updateString[updateSize] = '\0';
    delete[] this->string;
    this->size = updateSize;
    this->string = updateString;
}