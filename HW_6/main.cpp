#include <iostream>
#include "Date.h"

using std::cout;
using std::cin;

void test() {
    Date d1(24, 5, 180), d2(-5,-8, 212);
    cout << "d1: " << d1 << "\n\n";
    cout << "d2: " << d2 << "\n\n";
    
    cout << "d1 == d2 " << (d1 == d2) << "\n\n";
    cout << "d1 > d2 " << (d1 > d2) << "\n\n";
    cout << "d1 >= d2 " << (d1 >= d2) << "\n\n";
    cout << "d1 < d2 " << (d1 < d2) << "\n\n";
    cout << "d1 <= d2 " << (d1 <= d2) << "\n\n";
    cout << "d1 != d2 " << (d1 != d2) << "\n\n";
    
    cout << "~d1: " << ~d1 << "\n\n";
    cout << "!d1 " << !d1 << "\n\n";
    cout << "d1 && d2 " << (d1 && d2) << "\n\n";
    cout << "d1 || d2 " << (d1 || d2) << "\n\n";

    cout << "d1 << d2: " << (d1 << 4) << "\n\n";
    cout << "d1 >> d2: " << (d1 >> 6) << "\n\n";

    cout << "&d1: " << (&d1) << "\n\n";
    
    cout << "d1[]: " << d1[1] << "\n\n";
    
    d1++;
    ++d1;
    d2++;
    ++d2;
    d1(5);
    d2(12);
    
    cout << "d1 + d2 " << (d1 + d2) << "\n\n";
    cout << "d1 - d2 " << (d1 - d2) << "\n\n";
    cout << "d1 * d2 " << (d1 * d2) << "\n\n";
    cout << "d1 / d2 " << (d1 / d2) << "\n\n";
    cout << "d1 ^ d2 " << (d1 ^ d2) << "\n\n";
    cout << "d1 | d2 " << (d1 | d2) << "\n\n";
    
    cout << "d1, d2 " << (d1, d2) << "\n\n";

    cout << "d1: " << d1 << "\n\n";
    
    d1 += d2;
    d1 -= d2;
    d1 ^= d2;
    d1 |= d2;
    d1 *= d2;
    d1 /= d2;
}



int main(int argc, const char* argv[]) {
    test();
    return 0;
}