#pragma once

class String {
public:
    String();
    String(const char c, const size_t size);
    String(const char* string);
    ~String();

    void show();
    void append(const char* string);
    void append(const String& string);
    String& operator=(const String& string);
    String(const String& string);
    char* getString();
    size_t getSize();

private:
    char *string;
    size_t size;
};