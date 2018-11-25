#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <map>
#include <string>

class Date {
public:
    explicit Date(int mDay, int month, int year);
    explicit Date(int mTime);
    virtual ~Date();
    
    Date(const Date &other);

    Date &operator=(const Date &other);

    Date &operator+=(const Date &other);
    Date &operator-=(const Date &other);
    Date &operator*=(const Date &other);
    Date &operator/=(const Date &other);
    Date &operator%=(const Date &other);
    Date operator+(const Date &other);
    Date operator-(const Date &other);
    Date operator+() const;
    Date operator-() const;
    Date operator*(const Date &other);
    Date operator/(const Date &other);
    Date operator%(const Date &other);

    Date &operator|=(const Date &other);
    Date &operator^=(const Date &other);
    Date &operator&=(const Date &other);
    Date operator|(const Date &other);
    Date operator^(const Date &other);
    Date operator&(const Date &other);
    Date &operator~();

    friend std::ostream &operator<<(std::ostream &out, const Date &date);
    friend std::istream &operator>>(std::istream &in, Date &date);

    Date &operator++();
    const Date operator++(int);  //postfix
    Date &operator--();
    const Date operator--(int);  //postfix

    bool operator==(const Date &rhs) const;
    bool operator!=(const Date &rhs) const;
    bool operator<(const Date &rhs) const;
    bool operator>(const Date &rhs) const;
    bool operator<=(const Date &rhs) const;
    bool operator>=(const Date &rhs) const;

    Date &operator<<=(int);
    Date &operator>>=(int);
    Date operator<<(int);
    Date operator>>(int);

    Date operator!() const;
    bool operator&&(const Date &other);
    bool operator||(const Date &other);
    int operator[](size_t) const;
    int operator()(size_t) const;

    explicit operator std::string() const;

    const Date operator,(Date &v2);
        
 private:
    void recalcDatebyTime();
    void recalcTimebyDate();
    void recalcIsAfter();
    void initMap();

    std::map<int, int> daysInMonth;
    int mTime;
    int mDay;
    int mMonth;
    int mYear;
    int mIsAfter;
};
#endif 
