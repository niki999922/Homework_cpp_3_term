#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
	freopen("Test3.txt", "w", stdout);
	int n =11, m = 4;
	cout << n << " " << m << '\n';
	cout.precision(10);
    /*double d;
    for(int i = 0; i < n; i++) {
    	d = static_cast<double>(rand()%1000);
    	d = d * (0.312341);
    	cout << fixed << d << " ";
    	d = static_cast<double>(rand()%1000);
    	d = d * (0.829123);
    	cout << fixed  << d << endl;
    }*/
    
    int d;
    for(int i = 0; i < n; i++) {
    	d = rand()%1000;
    	cout << d << " ";
    	d = rand()%1000;
    	cout << d << endl;
    }
    return 0;
}
