#ifndef RATIONAL_H 
#define RATIONAL_H
#include <sstream>
#include <string>
#include <numeric>

using namespace std;

class Rational {
	int num;
	int denom;

public:
	Rational();

	Rational(int a, int b);

	Rational(const Rational& z);

	Rational RightSign();

	Rational operator+(int a) const;

	Rational operator+(const Rational& z) const;

	Rational operator-(int a) const;

	Rational operator-(const Rational& z) const;

	Rational operator*(int a) const;

	Rational operator*(const Rational& z) const;

	Rational operator/(int a) const;

	Rational operator/(const Rational& z) const;

	Rational operator+() const;

	Rational operator-() const;

	Rational NumeratorDenominator();

	Rational operator+=(int a);

	Rational operator+=(const Rational& z);

	Rational operator-=(int a);

	Rational operator-=(const Rational& z);

	Rational operator*=(int a);

	Rational operator*=(const Rational& z);

	Rational operator/=(int a);

	Rational operator/=(const Rational& z);

	bool operator==(const Rational& z) const;

	bool operator==(int n) const;

	bool operator==(double n) const;

	bool operator!=(const Rational& z) const;

	bool operator!=(int n) const;

	bool operator!=(double n) const;

	string to_string() const;

	friend ostream& operator<<(ostream& os, const Rational& z) {
		os << z.to_string();
		return os;
	}

	friend istream& operator>>(istream& is, Rational& z) {
		is >> z.num >> z.denom;
		return is;
	}
};

#endif // !RATIONAL_H 

