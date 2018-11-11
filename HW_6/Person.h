#ifndef SOMETHING_PERSON_H
#define SOMETHING_PERSON_H

#include <iostream>
#include <string>

using std::string;

class Person {
public:
    explicit Person() : name("null"), iq(0) {};
    
    Person(string, int);
    ~Person() {};

    Person& operator=(const Person&);
    Person operator+(const Person&) const;
    Person& operator+=(const Person&);
    Person operator-(const Person&) const;
    Person& operator-=(const Person&);
    Person operator+() const;
    Person operator-() const;
    Person operator*(const Person&) const;
    Person& operator*=(const Person&);
    Person operator/(const Person&) const;
    Person& operator/=(const Person&);
    Person operator%(const Person&) const;
    Person& operator%=(const Person&);
    
    Person& operator++();
    Person operator++(int); //postfix
    Person& operator--();   
    Person operator--(int); //postfix

    bool operator==(const Person& rhs) const;

    bool operator!=(const Person& rhs) const;
    bool operator<(const Person& rhs) const;
    bool operator>(const Person& rhs) const;
    bool operator<=(const Person& rhs) const;
    bool operator>=(const Person& rhs) const;

    Person operator!() const;
    Person operator&&(const Person& ) const;
    Person operator||(const Person& ) const;

    Person operator~() const;
    Person operator&(const Person& ) const;
    Person& operator&=(const Person& );
    Person operator|(const Person& ) const;
    Person& operator|=(const Person& );
    Person operator^(const Person& ) const;
    Person& operator^=(const Person& );
    Person operator<<(const Person& ) const;
    Person& operator<<=(const Person& );
    Person operator>>(const Person& ) const;
    Person& operator>>=(const Person& );

    char operator[](int) const;
    Person operator*() const;
    string operator&() const;
    string operator->() const;
    void operator()();
    Person operator,(const Person&);

    friend std::ostream& operator<<(std::ostream& os, const Person& op);
    friend std::istream& operator>>(std::istream& is, Person& op);

    explicit operator int() const;

private:
    string name;
    int iq;
};

#endif
