#include <iostream>

using namespace std;

int sum(int a, int b) {
    return a + b;
}

float sum(float a, float b) {
    return a + b;
}

void foo() {
    cout << "void function" << endl;
}

int def_arg(int b = 100000) {
    return b;
}

void function(int arg, ...) {
    int *p1 = &arg;
    while (++p1) {
        int arg_next = *p1;
        cout << arg_next << " ";
    }
}

int main() {
    int a;
    cout << sum(3, 4) << " = 7" << endl;
    cout << sum((float)3.0, 5.0) << " = 8.0" << endl;
    foo();
    cout << "Without use def arg = "<< def_arg(15) << endl;
    cout << "With use def arg = "<< def_arg() << endl;
    system("pause");
    return 0;
}

/*

1. Write  a Program to demonstrate functions.

2. Write  a Program to demonstrate function overloading.

3. Write  a Program to demonstrate default arguments.

4. Write  a Program to demonstrate pass by value, pass by reference and return by reference.

5. Write  a Program to demonstrate classes and objects.

6. Write  a Program to demonstrate  constructors.

*/