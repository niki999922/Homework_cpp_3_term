#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

#include "lib_rational.h"
#include "polynom.h"


int main(int argc, char* argv[]) {
	std::ios::sync_with_stdio(false);
	long base = 50, size_poly = 5; // long num den and  sizepoly
	long chq = 100000; // hom much polynom
	std::ofstream fou("test_mega.txt");
	fou << chq;
	for(int qw = 0; qw < chq; qw++) {
		long n, numeratorT, denominatorT;
		Number q1, q2;
		std::string s1 = "", s2 = "";

		numeratorT = (rand()%base + 1);
		numeratorT *= ((rand()%2) ? -1 : 1);
		denominatorT = (rand()%base + 1);
		fou << '\n' << numeratorT << " " << denominatorT << " ";
		q1 = Number(numeratorT, denominatorT);

		numeratorT = (rand()%base + 1);
		numeratorT *= ((rand()%2) ? -1 : 1);
		denominatorT = (rand()%base + 1);
		fou << numeratorT << " " << denominatorT << " ";
		q2 = Number(numeratorT, denominatorT);
	
		std::vector<Number> coefficients;
		n = rand()%size_poly + 1;
		fou << n << " ";

		coefficients.resize(n);
		for(size_t i = 0; i < n; ++i) {
			numeratorT = (rand()%base + 1);
			numeratorT *= ((rand()%2) ? -1 : 1);
			denominatorT = (rand()%base + 1);
			fou << numeratorT << " " << denominatorT << " ";
			fou.flush();
			Number tmp(numeratorT, denominatorT);
        	tmp.reduction();
        	coefficients[i] = tmp;
		}
		Polynom polynom(&coefficients, n);
		fou << (Number::compare(polynom.count(q1), polynom.count(q2)));
	}
   	fou.close(); 
   	return 0;
}