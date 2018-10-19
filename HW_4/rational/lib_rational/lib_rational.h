#ifndef LIB_RATIONAL_H
#define LIB_RATIONAL_H

class Number {
public:
	Number();
	Number(long, long);
    ~Number();
    
    static Number add(Number, Number);
	static Number divide(Number, Number); 
	static Number substract(Number, Number); 
	static Number multiply(Number, Number);
	static void makeCommonDenominator(Number&, Number&);
	static int compare(Number, Number);

	Number& operator= (const Number&);
	bool operator<(const Number&) const;
	bool operator>(const Number&) const;
	bool operator<=(const Number&) const;
	bool operator>=(const Number&) const;
	bool operator==(const Number&) const;
	bool operator!=(const Number&) const;
	Number abs() const;

	Number operator +(const Number&) const;
	Number operator -(const Number&) const;
	Number operator *(const Number&);
	Number operator /(const Number&);
	Number operator-() const;

	void reduction(); 

    long getNumerator() const;
    long getDenominator() const;

private:
	long numerator = 1, denominator = 1; 
	
	long GCD(long, long);
};

#endif