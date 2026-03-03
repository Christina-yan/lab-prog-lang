#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
    double re;
    double im;

public:
    Complex();

    Complex(double x, double y);

    void SetRe(const double re);

    void SetIm(const double im);

    double GetRe() const;

    double GetIm() const;

    double Abs() const;

    double Arg() const;

    string ToString() const;

    string ToStringTrig();

    string ToStringExp();

    Complex Add(Complex z);

    Complex Sub(Complex z);

    Complex Mult(Complex z);

    Complex Div(Complex z);
};

#endif