#ifndef BOOK_H
#define BOOK_H

class Book {
public:
    explicit Book();
    ~Book();
    void input();
    void purchase() const;

private:
    static const int NUMBER_BOOK_TITLE = 20;
    int mBookNumber;
    char mBookTitle[NUMBER_BOOK_TITLE + 1] = {""};
    float mPrice;

    float mTotalCost(const int& n = 1) const;
};
#endif