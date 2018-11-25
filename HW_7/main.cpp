#include <iostream>
#include <string>

#include "Array.h"

using std::cout;
using std::cin;
using std::string;

template<typename T>
struct SomeType {
    SomeType() {
        this->mData = new T();
        *this->mData = 1;
    }

    SomeType(const SomeType &inX) {
        this->mData = new T();
        *this->mData = *inX.mData;
    }

    ~SomeType() { delete this->mData; }

    friend std::ostream &operator<<(std::ostream &s, const SomeType &obj) {
        s << *(obj.mData);
        return s;
    }

    void set(T elem) {
        *(this->mData) = elem;
    }

    T get() {
        return *mData;
    }
    
private:
    T *mData;
};

bool minimal(int a, int b) {
    return a < b;
}

bool minimal(SomeType<double> a, SomeType<double> b) {
    return a.get() < b.get();
}

class Greater {
public:
    bool operator()(SomeType<double> a, SomeType<double> b) {
        return b.get() < a.get();
    }

    bool operator()(int a, int b) {
        return b < a;
    }
};

void test() {
    {
        Array<char> ar(size_t(5), '0');
        Array<char> x(size_t(4), '4');
        Array<char> x2(size_t(6), '6');
        ar = x;
        ar.print();
        ar = x2;
        ar.print();
    }
    {
        Array<string> cr(size_t(5), "0");
        Array<string> cx(size_t(4), "4");
        Array<string> cx2(size_t(6), "6");
        cr = cx;
        cr.print();
        cr = cx2;
        cr.print();
    }
    {
        Array<int> ir(size_t(5), 0);
        Array<int> ix(size_t(4), 4);
        Array<int> ix2(size_t(6), 6);
        ir = ix;
        ir.print();
        ir = ix2;
        ir.print();
    }
    {
        Array<double> dr(size_t(5), 0.5);
        Array<double> dx(size_t(4), 4.5);
        Array<double> ix2(size_t(6), 6.6);
        dr = dx;
        dx.print();
        dr = ix2;
        dr.print();
    }
    {
        Array<char> ar(size_t(100), '0');
        Array<char> x(size_t(0), '1');
        ar = x;
        ar.print();
    }
    {
        Array<string> cr(size_t(100), "Str0");
        Array<string> cx(size_t(0), "Str1");
        Array<string> cx2(size_t(2), "Str3");
        cr = cx;
        cr.print();
        cr = cx2;
        cr.print();
    }
    {
        Array<int> cr(size_t(100), 0);
        Array<int> cx(size_t(0), 15);
        Array<int> cx2(size_t(2), 55);
        cr = cx;
        cr.print();
        cr = cx2;
        cr.print();
    }
    {
        Array<char> x(size_t(3), '3');
        Array<char> ar(x);
        ar.print();
    }
    {
        Array<string> x(size_t(3), "333");
        Array<string> ar(x);
        ar.print();
    }
    {
        Array<char> ar(size_t(0), '0');
        ar = ar;
        ar.print();
    }
    {
        Array<string> ar(size_t(0), "0");
        ar = ar;
        ar.print();
    }
    {
        Array<char> ar(size_t(4), '0');
        ar = ar;
        ar.print();
    }
    {
        Array<char> ar(size_t(4), '0');
        try {
            cout << ar[10] << endl;
        }
        catch (const char* e) {
            cout << e << endl;
        }
    }
    {
        Array<char> ar(size_t(4), '0');
        try {
            cout << ar[-10] << endl;
        }
        catch (const char* e) {
            cout << e << endl;
        }
    }
    {
        Array<char>* ar = new Array<char>(size_t(4), '4');
        ar->print();
        delete ar;
    }
    {
        Array<char>* ar = new Array<char>(size_t(5), '5');
        Array<char>* xr = ar;
        ar->print();
        xr->print();
        delete ar;
    }
    {
        SomeType<int> x;
        x.set(4);
        auto *ar = new Array<SomeType<int>>(size_t(4), x);
        ar->print();
        delete ar;
    }
    {
        SomeType<char> x;
        x.set('c');
        auto *ar = new Array<SomeType<char>>(size_t(4), x);
        ar->print();
        Array<SomeType<char>> *xr = ar;
        xr->print();
        Array<SomeType<char>> y(*xr);
        y.print();
        delete ar;
    }
    {
        Array<int> array(5, -1);
        Greater g;
        array[0] = 2;
        array[1] = 5;
        array[2] = 4;
        array[3] = 1;
        array[4] = 3;
        cout << minimum(array, minimal) << endl;
        cout << minimum(array, g) << endl;
    }
    {
        Array<int> ints(3);
        Greater g;
        ints[0] = 10;
        ints[1] = 2;
        ints[2] = 15;
        cout << minimum(ints, minimal) << endl;
        cout << minimum(ints, g) << endl;
    }
    {
        SomeType<double> x;
        x.set(2.3);
        Array<SomeType<double>> array(7, x);
        array[5].set(-0.2);
        Greater g;
        cout << minimum(array, minimal) << endl;
        cout << minimum(array, g) << endl;
    }
    {
        int n = 3;
        Array<int> inner((size_t)n);
        for (int i = 0; i < n; ++i) {
            inner[i] = i + 3 * i;
        }
        Array<Array<int>> l2(2, inner);
        Array<Array<Array<int>>> l3(2, l2);
        Array<Array<Array<Array<int>>>> array(2, l3);
        flatten(array, cout);
    }
}


int main() {
    test();
    system("pause");
    return 0;
}