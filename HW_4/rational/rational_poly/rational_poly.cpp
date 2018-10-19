#include <iostream>

#include "lib_rational.h"
#include "polynom.h"


int main(int argc, char* argv[]) {
	std::ios::sync_with_stdio(false);
	long n, numeratorT, denominatorT;
	Number q1, q2;
	std::cout << "Enter q1 and q2 (+-numerator +denominator)" << std::endl;
	std::cin >> numeratorT >> denominatorT;
	q1 = Number(numeratorT, denominatorT);
	std::cin >> numeratorT >> denominatorT;
	q2 = Number(numeratorT, denominatorT);
	std::vector<Number> coefficients;
	std::cout << "Enter n number of coefficients and n coefficients (+-numerator +denominator)" << std::endl;
	std::cin >> n;
	coefficients.resize(n);
	for(size_t i = 0; i < n; ++i) {
		std::cin >> numeratorT >> denominatorT;
        Number tmp(numeratorT, denominatorT);
        tmp.reduction();
        coefficients[i] = tmp;
	}
	Polynom polynom(&coefficients, n );
	
	std::cout <<"((" << coefficients[0].getNumerator() <<"/" << coefficients[0].getDenominator() << ") * q^(" << n - 1  << ")) "; 
	for(size_t i = 1; i < n; ++i) {
		std::cout <<"+ ((" << coefficients[i].getNumerator() <<"/" << coefficients[i].getDenominator() << ") * q^(" << n - i - 1<< ")) "; 
	}
	std::cout << "\n\n";

    switch (Number::compare(polynom.count(q1), polynom.count(q2))) {
        case (1):
        {
            std::cout << "Result Nuber1 < Number2" << std::endl;
            break;
        }
        case (0):
        {
            std::cout << "Result Nuber1 == Number2" << std::endl;
            break;
        }
        case (-1):
        {
            std::cout << "Result Nuber1 > Number2" << std::endl;
            break;
        }
    }
	return 0;
}