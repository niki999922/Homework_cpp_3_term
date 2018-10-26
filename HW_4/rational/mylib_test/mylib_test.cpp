#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "lib_rational.h"
#include "polynom.h"

int main(int argc, char* argv[]) {
	if (argc <= 1) return 0;
	std::ifstream fin(argv[1]);
	long chr;
	fin >> chr;
	for(size_t z = 0; z < chr; ++z) {
		long n, numeratorT, denominatorT, ans;
		std::vector<Number> coefficients;
		Number q1, q2;
		fin >> numeratorT >> denominatorT;
		q1 = Number(numeratorT, denominatorT);
		fin >> numeratorT >> denominatorT; 
		q2 = Number(numeratorT, denominatorT);
		fin >> n;
		coefficients.resize(n);
		std::cout << "n " << n << std::endl;
		for(size_t i = 0; i < n; ++i) {
			fin >> numeratorT >> denominatorT;
			std::cout << "n an d " << numeratorT << " " << denominatorT << std::endl;
			Number tmp(numeratorT, denominatorT);
    	    tmp.reduction();
    	    coefficients[i] = tmp;
    	}
		Polynom polynom(&coefficients, n );
		fin >> ans;
		std::cout << "Real ans " << ans << std::endl;
		std::cout << "Count " << Number::compare(polynom.count(q1), polynom.count(q2)) << std::endl;
		if (Number::compare(polynom.count(q1), polynom.count(q2)) != ans) return 1;
	}
	return 0;
}