#include "Rational.h"

Rational::Rational() {
	this->num = 0;
	this->denom = 1;
}
Rational::Rational(int a, int b) {
	this->num = a;
	this->denom = b;
}
Rational::Rational(const Rational& z) {
	this->num = z.num;
	this->denom = z.denom;
}
Rational Rational::RightSign()  {
	if (denom < 0) {
		num = num * (-1);
		denom = denom * (-1);
		return { num , denom };
	}
}
Rational Rational::operator+(int a) const {
	return { num + a * denom, denom };
}
Rational Rational::operator+(const Rational& z) const {
	return { num * z.denom + z.num * denom ,denom * z.denom };
}
Rational Rational::operator-(int a) const {
	return { num - a * denom, denom };
}
Rational Rational::operator-(const Rational& z) const {
	return { num * z.denom - z.num * denom ,denom * z.denom };
}
Rational Rational::operator*(int a) const {
	return { num * a , denom };
}
Rational Rational::operator*(const Rational& z) const {
	return { num * z.num , denom * z.denom };
}
Rational Rational::operator/(int a) const {
	return { num , denom * a };
}
Rational Rational::operator/(const Rational& z) const {
	return { num * z.denom , denom * z.num };
}
Rational Rational::operator+() const {
	return { num , denom };
}
Rational Rational::operator-() const {
	return { -num , -denom };
}
Rational Rational::NumeratorDenominator () {
	int n = gcd(num, denom);
	num /= n;
	denom /= n;
	RightSign();
	return { num, denom };
}
Rational Rational::operator+=(int a) {
	return { num = num + a * denom, denom };
}
Rational Rational::operator+=(const Rational& z) {
	return { num = num * z.denom + z.num * denom ,denom = denom * z.denom };
}
Rational Rational::operator-=(int a) {
	return { num = num - a * denom, denom };
}
Rational Rational::operator-=(const Rational& z) {
	return { num = num * z.denom - z.num * denom ,denom = denom * z.denom };
}
Rational Rational::operator*=(int a) {
	return { num = num * a , denom };
}
Rational Rational::operator*=(const Rational& z) {
	return { num = num * z.num , denom = denom * z.denom };
}
Rational Rational::operator/=(int a) {
	return { num , denom = denom * a };
}
Rational Rational::operator/=(const Rational& z) {
	return { num = num * z.denom , denom = denom * z.num };
}
bool Rational::operator==(const Rational& z) const {
	Rational a(num, denom), b = z;
	a = a.NumeratorDenominator();
	b = b.NumeratorDenominator();
	return  a.num == b.num && a.denom == b.denom;
}
bool Rational::operator==(int n) const {
	Rational a(num, denom);
	a = a.NumeratorDenominator();
	return  a.num == n && a.denom == 1;
}
bool Rational::operator==(double n) const {
	Rational a(num, denom);
	a = a.NumeratorDenominator();
	return  a.num == n * a.denom;
}
bool Rational::operator!=(const Rational& z) const {
	Rational a(num, denom), b = z;
	a = a.NumeratorDenominator();
	b = b.NumeratorDenominator();
	return  a.num != b.num || a.denom != b.denom;
}
bool Rational::operator!=(int n) const {
	Rational a(num, denom);
	a = a.NumeratorDenominator();
	return a.num != n || a.denom != 1;
}
bool Rational::operator!=(double n) const {
	Rational a(num, denom);
	a = a.NumeratorDenominator();
	return  a.num != n * a.denom ;
}
string Rational::to_string() const {
	stringstream ss;

	ss << num << " / " << denom;

	return ss.str();
}