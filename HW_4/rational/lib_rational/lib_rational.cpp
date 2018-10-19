#include "lib_rational.h"

Number::Number(): numerator(0), denominator(1) {}

Number::Number(long numerator, long denominator): numerator(numerator) {
	if (denominator == 0) throw "Suck my dick";
	this->denominator = denominator;
}

Number::~Number(){}

Number Number::add(Number n1, Number n2) {
	if (n1.denominator != n2.denominator) {
		makeCommonDenominator(n1, n2);
	}
	return Number(n1.numerator + n2.numerator, n1.denominator);
}

Number Number::substract(Number n1, Number n2) {
	if (n1.denominator != n2.denominator) {
		makeCommonDenominator(n1, n2);
	}
	return Number(n1.numerator - n2.numerator, n1.denominator);
}

Number Number::multiply(Number n1, Number n2) {
	return Number(n1.numerator * n2.numerator, n1.denominator * n2.denominator);
}

Number Number::divide(Number n1, Number n2) {
	if (n2.numerator == 0) throw "Suck my dick";
	long numerator, denominator;
	numerator = n1.numerator * n2.denominator;
	denominator = n1.denominator * n2.numerator;
	if ((numerator < 0 || numerator > 0 ) && denominator < 0) {
		numerator *= -1;
		denominator *= -1;
	}
	return Number(numerator, denominator);
}

void Number::makeCommonDenominator(Number& n1, Number& n2) {
	n1.numerator *= n2.denominator;
	n2.numerator *= n1.denominator;
	n1.denominator = n2.denominator = n2.denominator * n1.denominator;
}

Number Number::operator +(const Number &val) const {
	Number n1 = *this;
    Number n2 = val;
    return add(n1, n2);
}

Number Number::operator -(const Number &val) const {
	Number n1 = *this;
    Number n2 = val;
    return substract(n1, n2);
}

Number Number::operator-() const {
    Number res = *this;
    res.numerator= -res.numerator;
    return res;
}

Number Number::operator *(const Number &val) {
	Number n1 = *this;
    Number n2 = val;
    return multiply(n1, n2);
}

Number Number::operator /(const Number &val) {
	Number n1 = *this;
    Number n2 = val;
    return divide(n1, n2);
}	


Number& Number::operator= (const Number &val) {
    numerator = val.numerator;
    denominator = val.denominator;
    return *this;
}


bool Number::operator <(const Number &val) const {
    //Number n1(this->numerator, this->denominator);
    //Number n2(val.numerator, val.denominator);
    Number n1 = *this;
    Number n2 = val;
    makeCommonDenominator(n1, n2);
    if (n1.getNumerator() < n2.getNumerator()) return true;
    return false;
}

bool Number::operator >(const Number &val) const {
    return val < *this;
}

bool Number::operator <=(const Number &val) const {
    return !(val < *this);
}

bool Number::operator >=(const Number &val) const {
    return !(*this < val);
}

bool Number::operator ==(const Number &val) const {
    return !(*this < val) && !(val < *this);
}

bool Number::operator !=(const Number &val) const {
    return *this < val || val < *this;
}

Number Number::abs() const {
    Number res = *this;
    if (res.numerator < 0) res.numerator *= -1;
    return res;
}

void Number::reduction() {
	long gcd = 1;
	if (numerator == 0)
		{
		this->numerator = 0;
		this->denominator = 1;
		return;
	}
	if (numerator > 0)
		gcd = GCD(this->numerator, this->denominator);
	else
		gcd = GCD(-(this->numerator), this->denominator);
	this->numerator = this->numerator / gcd;
	this->denominator = this->denominator / gcd;
}

long  Number::GCD(long numerator, long denominator) {
	while (denominator) {
		numerator %= denominator;
		numerator = numerator ^ denominator;
		denominator = numerator ^ denominator;
		numerator = numerator ^ denominator;
	}
	return numerator;
}

long Number::getNumerator() const {
    return this->numerator;
}

long Number::getDenominator() const {
    return this->denominator;
}

int Number::compare(Number n1, Number n2) {
    if (n1 < n2) return 1;
    if (n1 == n2) return 0;
    return -1;
}
