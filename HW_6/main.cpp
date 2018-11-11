#include <iostream>
#include "Person.h"

using std::cout;
using std::cin;

void test1() {
    Person p1("TOM",227), p2("MAX", 96);
    cout << "p1: " << p1 << "\n\n";
    cout << "p2: " << p2 << "\n\n";
    
    cout << "p1 == p2 " << (p1 == p2) << "\n\n";
    cout << "p1 > p2 " << (p1 > p2) << "\n\n";
    cout << "p1 >= p2 " << (p1 >= p2) << "\n\n";
    cout << "p1 < p2 " << (p1 < p2) << "\n\n";
    cout << "p1 <= p2 " << (p1 <= p2) << "\n\n";
    cout << "p1 != p2 " << (p1 != p2) << "\n\n";
    
    cout << "~p1: " << ~p1 << "\n\n";
    cout << "!p1 " << !(p1) << "\n\n";
    cout << "p1 && p2 " << (p1 && p2) << "\n\n";
    cout << "p1 || p2 " << (p1 || p2) << "\n\n";

    cout << "p1 << p2: " << (p1 << p2) << "\n\n";
    cout << "p1 >> p2: " << (p1 >> p2) << "\n\n";

    cout << "*p1: " << *p1 << "\n\n";
    
    cout << "&p1: " << (&p1) << "\n\n";
    
    cout << "p1[]: " << p1[1] << "\n\n";
    
    p1++;
    ++p1;
    p2++;
    ++p2;
    p1();
    p2();
    
    cout << "p1 + p2 " << (p1 + p2) << "\n\n";
    cout << "p1 - p2 " << (p1 - p2) << "\n\n";
    cout << "p1 * p2 " << (p1 * p2) << "\n\n";
    cout << "p1 / p2 " << (p1 / p2) << "\n\n";
    cout << "p1 ^ p2 " << (p1 ^ p2) << "\n\n";
    cout << "p1 | p2 " << (p1 | p2) << "\n\n";
    cout << "p1  p2 " << (p1 | p2) << "\n\n";

    cout << "p1, p2 " << (p1, p2) << "\n\n";

    cout << "p1: " << p1 << "\n\n";
    
    p1 += p2;
    p1 -= p2;
    p1 ^= p2;
    p1 |= p2;
    p1 *= p2;
    p1 /= p2;
}

int main(int argc, const char* argv[]) {
    test1();
    system("pause");
    return 0;
}