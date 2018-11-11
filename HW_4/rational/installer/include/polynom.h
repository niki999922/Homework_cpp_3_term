#ifndef POLYNOM_H
#define POLYNOM_H

#include <vector>

#include "lib_rational.h"

class Polynom {
public:
	explicit Polynom();
	Polynom(std::vector<Number>*, long);
	~Polynom();
	Number count(const Number&) const;	
	long getSize() const;
	Number operator[](long) const;

private:
    std::vector<Number> coefficients;
};

#endif
