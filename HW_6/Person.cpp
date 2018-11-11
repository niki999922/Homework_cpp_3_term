#include <iostream>
#include <string>
#include "Person.h"

using std::cout;
using std::cin;
using std::string;

bool Person::operator==(const Person & p2) const {
    return iq == p2.iq;
}

bool Person::operator!=(const Person & p2) const {
    return !(*this == p2);
}

bool Person::operator<(const Person & p2) const {
    return iq < p2.iq;
}

bool Person::operator>(const Person & p2) const {
    return p2 < *this;
}

bool Person::operator<=(const Person & p2) const {
    return !(p2 < *this);
}

bool Person::operator>=(const Person & p2) const {
    return !(*this < p2);
}

Person::Person(string name, int iq) {
    this->name = name;
    this->iq = iq;
}

Person& Person::operator=(const Person & sec) = default;

Person Person::operator+(const Person& p2) const {
    cout << "Operator +" << '\n';
    Person tmp = p2;
    tmp += p2;
    return tmp;
}

Person &Person::operator+=(const Person& p2) {
    cout << "Operator +=" << '\n';
    (*this).iq += p2.iq;
    return *this;
}

Person Person::operator-(const Person & p2) const {
    cout << "Operator -" << '\n';
    Person tmp = *this;
    tmp -= p2;
    return tmp;
}

Person &Person::operator-=(const Person & p2) {
    cout << "Operator -=" << '\n';
    (*this).iq -= p2.iq;
    return *this;

}

Person Person::operator+() const {
    cout << "Operator only +" << '\n';
    return Person(this->name,this->iq);
}

Person Person::operator-() const {
    cout << "Operator only -" << '\n';
    return Person(this->name, this->iq);
}

Person Person::operator*(const Person & p2) const {
    cout << "Operator *" << '\n';
    return Person(this->name, this->iq * p2.iq);
}

Person &Person::operator*=(const Person & p2) {
    cout << "Operator *=" << '\n';
    this->iq = this->iq * p2.iq;
    return *this;
}

Person Person::operator/(const Person & p2) const {
    cout << "Operator /" << '\n';
    cout << "iq doesn't divine" << '\n';
    return Person(this->name,this->iq);
}

Person &Person::operator/=(const Person & p2) {
    cout << "Operator /=" << '\n';
    cout << "iq doesn't divine" << '\n';
    return *this;
}

Person Person::operator%(const Person & p2) const {
    cout << "Operator %" << '\n';
    cout << "iq doesn't divine" << '\n';
    return Person(this->name, this->iq);
}

Person &Person::operator%=(const Person & p2) {
    cout << "Operator %=" << '\n';
    cout << "iq doesn't divine" << '\n';
    return *this;
}

Person &Person::operator++() {
    cout << "Operator pref inc" << '\n';
    ++(this->iq);
    return *this;
}

Person Person::operator++(int) {
    cout << "Operator post inc" << '\n';
    return Person(this->name, this->iq + 1);
}

Person &Person::operator--() {
    cout << "Operator pref dec" << '\n';
    ++(this->iq);
    return *this;
}

Person Person::operator--(int) {
    cout << "Operator post dec" << '\n';
    return Person(this->name, this->iq - 1);
}

Person Person::operator!() const {
    cout << "Operator !" << '\n';
    cout << "iq doesn't work" << '\n';
    return Person(this->name, this->iq);
}

Person Person::operator&&(const Person & p2) const {
    cout << "Operator &&" << '\n';
    cout << "Work like &" << '\n';
    return Person(this->name, this->iq & p2.iq);
}

Person Person::operator||(const Person & p2) const {
    cout << "Operator ||" << '\n';
    cout << "Work like |" << '\n';
    return Person(this->name, this->iq | p2.iq);
}

Person Person::operator~() const {
    cout << "Operator ~" << '\n';
    cout << "it doesn't work" << '\n';
    return Person(this->name, this->iq);
}

Person Person::operator&(const Person & p2) const {
    cout << "Operator &" << '\n';
    return Person(this->name, this->iq & p2.iq);
}

Person &Person::operator&=(const Person & p2) {
    cout << "Operator &=" << '\n';
    this->iq &= p2.iq;
    return *this;
}

Person Person::operator|(const Person & p2) const {
    cout << "Operator ||" << '\n';
    return Person(this->name, this->iq | p2.iq);
}

Person &Person::operator|=(const Person & p2) {
    cout << "Operator |=" << '\n';
    this->iq |= p2.iq;
    return *this;
}

Person Person::operator^(const Person & p2) const {
    cout << "Operator ^" << '\n';
    return Person(this->name, this->iq ^ p2.iq);
}

Person &Person::operator^=(const Person & p2) {
    cout << "Operator ^=" << '\n';
    this->iq ^= p2.iq;
    return *this;
}

Person Person::operator<<(const Person & p2) const {
    cout << "Operator <<" << '\n';
    cout << "it doesn't work" << '\n';
    return Person(this->name, this->iq);
}

Person &Person::operator<<=(const Person & p2) {
    cout << "Operator <<=" << '\n';
    cout << "it doesn't work" << '\n';
    return *this;
}

Person Person::operator>>(const Person & p2) const {
    cout << "Operator >>" << '\n';
    cout << "it doesn't work" << '\n';
    return Person(this->name, this->iq);
}

Person &Person::operator>>=(const Person & p2) {
    cout << "Operator >>=" << '\n';
    cout << "it doesn't work" << '\n';
    return *this;
}

char Person::operator[](int n) const {
    cout << "Operator []" << '\n';
    if (n >= this->name.length()) return ' ';
    return this->name[n];
}

Person Person::operator*() const { 
    cout << "Operator *()" << '\n';
    cout << "it doesn't work" << '\n';
    return Person(this->name, this->iq);
}

string Person::operator&() const {
    cout << "Operator &()" << '\n';
    return this->name;
}

string Person::operator->() const {
    cout << "Operator ->()" << '\n';
    return this->name;
}

void Person::operator()() {
    cout << "Operator functor p()" << '\n';
    cout << (*this) << '\n';
}

Person Person::operator,(const Person & p2) {
    cout << "Operator ," << '\n';
    cout << "it doesn't work" << '\n';
    return Person(this->name, this->iq);
}

Person::operator int() const {
    cout << "Operator cast to (int)" << '\n';
    cout << "it doesn't work" << '\n';
    return 0;
}

std::ostream &operator<<(std::ostream &os, const Person & p2) {
    os << "name: " << p2.name;
    os << " iq: " << p2.iq;
    return os;
}

std::istream &operator>>(std::istream &is, Person &op) {
    cout << "Write name and iq: \n";
    is >> op.name >> op.iq;
    return is;
}
