#include <iostream>

#include "String.h"

void test1() {
    String s1("Hello, ");
    String s2("world!");
    String s3("OPA");
    std::cout << "s1 = " << s1.getString() << '\n';
    std::cout << "s2 = " << s2.getString() << '\n';
    std::cout << "s3 = " << s3.getString() << '\n';
    s1.append(s2);
    std::cout << "s1 + s2 = " << s1.getString() << '\n';
    std::cout << "_______________________________________" << '\n';
}

void test2() {
    String s1, s2("Tom"), s3, s4('O', 20);
    s1 = String("Mark");
    s3 = String(s2);
    std::cout << "s1 = " << s1.getString() << '\n';
    std::cout << "s2 = " << s2.getString() << '\n';
    std::cout << "s3 = " << s3.getString() << '\n';
    std::cout << "s4 = " << s4.getString() << '\n';
    std::cout << "_______________________________________" << '\n';
}

void test3() {
    String s1("one");
    String s2("two");
    std::cout << "before: " << '\n';
    std::cout << "s1 = " << s1.getString() << '\n';
    std::cout << "s2 = " << s2.getString() << '\n';
    s1 = s2;
    std::cout << "after: " << '\n';
    std::cout << "s1 = " << s1.getString() << '\n';
    std::cout << "s2 = " << s2.getString() << '\n';
    std::cout << "_______________________________________" << '\n';
}

int main() {
    test1();
    test2();
    test3();
    std::cout << "No leaks bro" << '\n';
    return 0;
}