#include <iostream>

using namespace std;

int sum(int a, int b) {
    return a + b;
}

float sum(float a, float b) {
    return a + b;
}

//Can be rewrited with templates
void some_func(int arg, ...) {
    int *p1 = &arg;
    while (*p1) {
        cout << *p1 << " ";
        p1++;
    }
    cout << endl;
}

void foo() {
    cout << "void function" << endl;
}

int def_arg(int b = 100000) {
    return b;
}

void pass_by_value(int a, int b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void pass_by_reference(int& a, int& b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int& return_by_reference(int a) {
    int l = 7;
    l += a;
    return l;
}


class A {
private:
    int t;

public:
    A() {};
    A(int a) {
        t = a;
    }

    int some_f(int a);
protected:
    int c;
};

class B : public A {
public:
    int q;
};

int A::some_f(int a) {
    return a * 2;
}

int main() {

    cout << sum(3, 4) << " = 7" << endl;
    cout << sum((float)3.0, 5.0) << " = 8.0" << endl;
    some_func(1, 5, 123, 3, 5, 4, 3, 2, 1, 0);
    foo();
    cout << "Without use def arg = " << def_arg(15) << endl;
    cout << "With use def arg = " << def_arg() << endl;
    int a = 11, b = 13;
    cout << "Pre: " << endl;
    cout << "a = " << a << " b = " << b << endl;
    pass_by_value(a, b);
    cout << "value a = " << a << " b = " << b << endl;
    pass_by_reference(a, b);
    cout << "reference a = " << a << " b = " << b << endl;
    //why it's work?   
    int &t = return_by_reference(4);
    cout << t << endl;
    system("pause");
    return 0;
}

/*

1. Write  a Program to demonstrate functions. OK

2. Write  a Program to demonstrate function overloading. OK

3. Write  a Program to demonstrate default arguments. OK

4. Write  a Program to demonstrate pass by value, pass by reference and return by reference. OK

5. Write  a Program to demonstrate classes and objects. OK

6. Write  a Program to demonstrate  constructors. OK

*/