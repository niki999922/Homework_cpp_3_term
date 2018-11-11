#include <iostream>
#include <string>
#include "Book.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Book::Book() {
    this->mBookNumber = 0;
    this->mPrice = 0;
}

Book::~Book() {}

float Book::mTotalCost(const int& n) const {
    return n * mPrice;  
}

void Book::input() {
    string str = "";
    cout << "Enter book number: ";
    cin >> mBookNumber;
    cout << "Enter book title: \n";
    cout << "Max lenght : " << NUMBER_BOOK_TITLE << '\n';
    cin >> str;
    if (str.length() > NUMBER_BOOK_TITLE) {
        for (size_t i = 0; i < NUMBER_BOOK_TITLE + 1; ++i) 
            mBookTitle[i] = str[i];
    }
    mBookTitle[NUMBER_BOOK_TITLE] = '\0';
    cout << "Enter book price: ";
    cin >> mPrice;
}

void Book::purchase() const {
    cout << "Enter n: ";
    int n;
    cin >> n;
    cout << mTotalCost(n) << endl;
}