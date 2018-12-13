#pragma once;

typedef unsigned char byte;

template<typename T>
class Array {
public:
    explicit Array(size_t size = 0, const T &value = T());
    Array(const Array &);
    ~Array();
    Array& operator=(const Array<T> &);
    size_t size() const;
    T& operator[](size_t);
    const T& operator[](size_t) const;
    void print();
    Array(Array&& tmp);
    
    Array& operator=(Array&& tmp);

private:
    void destroy();
    void mSwap(Array<T> &arr);
    size_t mArraySize;
    byte *mData;
};
#include "Array.hpp"


