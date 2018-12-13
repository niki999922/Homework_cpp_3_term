#include <iostream>
#include <string>
#include <typeinfo>
#include <tuple>

#include "Array.h"

using std::cout;
using std::cin;
using std::string;

template<typename T>
void print_valueses(const T& value) {
    std::cout << typeid(value).name() << " " << value << '\n';
}

template<typename T, typename... Args>
void print_valueses(const T& value, const Args&... args) {
    print_valueses(value);
    print_valueses(args...);
}

void test1() {
    std::cout << "Testing print values...\n";
    print_valueses(0, 3.5, "Hello");
    std::cout << "__________\nComplete.\n\n";
}

 void test2() {
    std::cout << "Testing move...\n";
    Array<char> buffer1 = Array<char>(5, 'a');
    Array<char> buffer2 = Array<char>(5, 'b');
    buffer1.print();
    buffer2.print();
    Array<char> buffer3(std::move(buffer1));
    buffer3.print();
    Array<char> buffer4 = std::move(buffer2);
    buffer4.print();
    std::cout << "__________\nComplete.\n\n";
}

void test3() {
    std::cout << "Testing make_tuple and to_pair...\n";
    auto t = std::make_tuple(0, 3.5, "Hello");
    std::pair<double, char const *> p = to_pair<1, 2>(t);
    std::cout << p.first << ' ' << p.second << '\n';
    std::cout << "__________\nComplete.\n\n";
}

void test() {
    test1();
    test2();
    test3();
}

int main() {
    test();
    system("pause");
    return 0;
}