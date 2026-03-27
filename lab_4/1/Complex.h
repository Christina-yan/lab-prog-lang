#ifndef COMPLEX_H
#define COMPLEX_H
#include <sstream>
#include <string>

using namespace std;

class Complex {
    double re;
    double im;

public:
    Complex();

    Complex(double x, double y);

    Complex(const Complex& z);

    Complex& operator=(const Complex& z);

    Complex& operator+=(const Complex& z);

    Complex& operator-=(const Complex& z);

    Complex& operator*=(const Complex& z);

    Complex& operator/=(const Complex& z);

    double get_re() const;

    void set_re(const double re);

    double get_im() const;

    void set_im(const double im);

    double abs() const;

    double arg() const;

    double operator()();

    string to_string() const;

    string to_string_trig() const;

    string to_string_exp() const;

    Complex operator+(const Complex& z) const;

    Complex operator+(const double& number) const;

    friend Complex operator+(const double& number, const Complex& z) {
        return { z.re + number, z.im };
    }

    Complex operator-() const;

    Complex operator-(const Complex& z) const;

    Complex& operator++();

    Complex operator++(int);

    Complex& operator--();

    Complex operator--(int);

    Complex operator*(const Complex& z) const;

    Complex operator/(const Complex& z) const;

    bool operator==(const Complex& z) const;

    bool operator!=(const Complex& z) const;

    bool operator<(const Complex& z) const;

    bool operator>(const Complex& z) const;

    bool operator<=(const Complex& z) const;

    bool operator>=(const Complex& z) const;

    static double sign(double number) {
        return number == 0 ? 0 : number < 0 ? -1 : 1;
    }

    friend ostream& operator<<(ostream& os, const Complex& z) {
        os << z.to_string();

        return os;
    }

    friend istream& operator>>(istream& is, Complex& z) {
        is >> z.re >> z.im;

        return is;
    }
};

#endif 
