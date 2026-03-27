#define _USE_MATH_DEFINES
#include <cmath>
#include "Complex.h"

Complex::Complex() {
    re = 0;
    im = 0;
}

Complex::Complex(double x, double y) {
    this->re = x;
    this->im = y;
}

Complex::Complex(const Complex& z) {
    this->re = z.re;
    this->im = z.im;
}

Complex& Complex::operator=(const Complex& z) {
    this->re = z.re;
    this->im = z.im;

    return *this;
}

Complex& Complex::operator+=(const Complex& z) {
    re += z.re;
    im += z.im;

    return *this;
}

Complex& Complex::operator-=(const Complex& z) {
    re -= z.re;
    im -= z.im;

    return *this;
}

Complex& Complex::operator*=(const Complex& z) { //(a + bi) * (c + di) : re = ac - bd, im = ad + bc
    double old_re = re, old_im = im;
    re = old_re * z.re - old_im * z.im;
    im = old_re * z.im + old_im * z.re;

    return *this;
}

Complex& Complex::operator/=(const Complex& z) {
    double old_re = re, old_im = im;
    re = (old_re * z.re + old_im * z.im) / (z.re * z.re + z.im * z.im);
    im = (old_im * z.re - old_re * z.im) / (z.re * z.re + z.im * z.im);

    return *this;
}

double Complex::get_re() const {
    return re;
}

void Complex::set_re(const double re) {
    this->re = re;
}

double Complex::get_im() const {
    return im;
}

void Complex::set_im(const double im) {
    this->im = im;
}

double Complex::abs() const {
    return sqrt(re * re + im * im);
}

double Complex::arg() const {
    double result;

    if (re > 0)
        result = im == 0 ? 0 : atan(im / re);
    else {
        if (re == 0)
            result = sign(im) * M_PI / 2;
        else {
            if (im == 0)
                result = M_PI;
            else
                result = atan(im / re) + M_PI;
        }
    }

    return result;
}

double Complex::operator()() {
    return arg();
}

string Complex::to_string() const {
    stringstream ss;

    ss << re;

    if (im != 0)
        ss << (im > 0 ? " + i*" : " - i*") << fabs(im);

    return ss.str();
}

string Complex::to_string_trig() const {
    stringstream ss;
    double phi = arg();

    ss << "cos(" << phi << ") + i*sin(" << phi << ")";

    return ss.str();
}

string Complex::to_string_exp() const {
    stringstream ss;
    double phi = arg();
    double ro = abs();

    ss << ro << " * e^(" << phi << "*i)";

    return ss.str();
}

Complex Complex::operator+(const Complex& z) const {
    return { re + z.re, im + z.im };
}

Complex Complex::operator+(const double& number) const {
    return { re + number, im };
}

Complex Complex::operator-() const {
    return { -re, -im };
}

Complex Complex::operator-(const Complex& z) const {
    return *this + -z;
}

Complex& Complex::operator++() {
    re++;
    im++;
    return *this;
}

Complex Complex::operator++(int) {
    Complex tmp = *this;
    ++(*this);
    return tmp;
}

Complex& Complex::operator--() {
    re--;
    im--;
    return *this;
}

Complex Complex::operator--(int) {
    Complex tmp = *this;
    --(*this);
    return tmp;
}

Complex Complex::operator*(const Complex& z) const {
    return {
        re * z.re - im * z.im,
        im * z.re + re * z.im
    };
}

Complex Complex::operator/(const Complex& z) const {
    return {
        (re * z.re + im * z.im) / (z.re * z.re + z.im * z.im),
        (im * z.re - re * z.im) / (z.re * z.re + z.im * z.im)
    };
}

bool Complex::operator==(const Complex& z) const {
    return re == z.re && im == z.im;
}

bool Complex::operator!=(const Complex& z) const {
    return !(*this == z);
}

bool Complex::operator<(const Complex& z) const {
    return arg() < z.arg();
}

bool Complex::operator>(const Complex& z) const {
    return arg() > z.arg();
}

bool Complex::operator<=(const Complex& z) const {
    return arg() <= z.arg();
}

bool Complex::operator>=(const Complex& z) const {
    return arg() >= z.arg();
}

