#include <vector>

#include "polynom.h"
#include "lib_rational.h"

Polynom::Polynom() {
	 coefficients.resize(1, Number());
}

Polynom::Polynom(std::vector<Number>* vec, long n) {
	this->coefficients.resize(n);
	for(long i = 0; i < n; ++i) {
		coefficients[i]=vec->at(i);
	}
}

Polynom::~Polynom() {}

long Polynom::getSize() const {
	return coefficients.size();
}

Number Polynom::count(const Number& number) const {
	if (getSize() == 0) return Number();
	Number numberT = number;
	Number res = coefficients[0]; // intermediate results
	for (long i = 0; i < coefficients.size() - 1; ++i) {
		res = numberT * res;
		res = res + coefficients[i + 1];
		res.reduction();
	}
	return res;
}

Number Polynom::operator [](long id) const {
	if (id >= getSize()) return Number();
	return coefficients[id];
}