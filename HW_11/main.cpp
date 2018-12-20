#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>

#include "BadFromStringException.h"

using std::string;

template<class T>
T from_string(string data) {
    std::istringstream stringStream(data);
    if (typeid(T).name() != typeid(string).name()) stringStream >> std::noskipws;
    T value;
    stringStream >> value;
    if (stringStream.fail() || (stringStream.get() && !stringStream.eof())) {
        std::stringstream tmp;
        tmp << "Can't convert from string to " << typeid(T).name() << ".";
        throw BadFromStringException(tmp.str());
    }
    return value;
}

void test1() {
    std::cout << "Start testing #1...\n";
    try {
        string  s1("123");
        int    a1 = from_string<int>(s1); // a1 = 123
        double b1 = from_string<double>(s1); // b1 = 123.0  
        string c1 = from_string<string>(s1); // c1 = "123"
    }
    catch (BadFromStringException& e) {
        std::cout << e.what() << '\n';
    }
    catch (...) {
        std::cout << "Error!\n";
    }

    try {
        string  s2("12.3");
        int    a2 = from_string<int>(s2); // exception
        double b2 = from_string<double>(s2); // b2 = 123.0
        string c2 = from_string<string>(s2); // c2 = "12.3
    }
    catch (BadFromStringException& e) {
        std::cout << e.what() << '\n';
    }
    catch (...) {
        std::cout << "Error!\n";
    }

    try {
        string  s3("abc");
        int    a3 = from_string<int>(s3); // exception    
        std::cout << a3 << '\n';
        double b3 = from_string<double>(s3); // exception
        std::cout << b3 << '\n';
        string c3 = from_string<string>(s3); // c3 = "abc"
        std::cout << c3 << '\n';
    }
    catch (BadFromStringException& e) {
        std::cout << e.what() << '\n';
    }
    catch (...) {
        std::cout << "Error!\n";
    }

    std::cout << "End testing.\n\n";
}

void test2() {
    std::cout << "Start testing #2...\n";
    try {
        string s(" abc");
        string a = from_string<string>(s);
    }
    catch (BadFromStringException& e) {
        std::cout << e.what() << '\n';
    }
    catch (...) {
        std::cout << "Error!\n";
    }

    try {
        string s("12.0 ");
        int a = from_string<int>(s); // exception    
    }
    catch (BadFromStringException& e) {
        std::cout << e.what() << '\n';
    }
    catch (...) {
        std::cout << "Error!\n";
    }

    try {
        string s(" 12 ");
        int a = from_string<int>(s); // exception    
    }
    catch (BadFromStringException& e) {
        std::cout << e.what() << '\n';
    }
    catch (...) {
        std::cout << "Error!\n";
    }

    try {
        string s(" 13.6");
        double a = from_string<double>(s); // exception    
    }
    catch (BadFromStringException& e) {
        std::cout << e.what() << '\n';
    }
    catch (...) {
        std::cout << "Error!\n";
    }

    try {
        string s(" 1");
        int a = from_string<int>(s); // exception    
    }
    catch (BadFromStringException& e) {
        std::cout << e.what() << '\n';
    }
    catch (...) {
        std::cout << "Error!\n";
    }

    std::cout << "End testing.\n\n";
}

void test() {
    test1();
    test2();
}

int main() {
    test();
    system("pause");
    return 0;
}