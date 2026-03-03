#include "Complex.h"

using namespace std;

Complex::Complex() {
    re = 0;
    im = 0;
}

Complex::Complex(double x, double y) {
    this->re = x;
    this->im = y;
}

void Complex::SetRe(const double re) {
    this->re = re;
}

void Complex::SetIm(const double im) {
    this->im = im;
}

double Complex::GetRe() const{
    return re;
}

double Complex::GetIm() const{
    return im;
}

double Complex::Abs() const{
    return sqrt(re * re + im * im);
}

double Complex::Arg() const{
    if (re > 0 && im > 0 || re > 0 && im < 0)
        return atan(im / re);
    else if (re < 0 && im > 0 || re < 0 && im < 0)
        return atan(im / re) + M_PI;
    else if (re == 0 && im > 0)
        return M_PI / 2;
    else if (re == 0 && im < 0)
        return M_PI / -2;
    else if (re > 0 && im == 0)
        return 0;
    else
        return M_PI;
    //double result;

    //if (re > 0) {
    //    result = atan(im / re);
    //}
    //else {
    //    if (re == 0) {
    //        result = M_PI / 2;

    //        result *= im > 0 ? 1 : -1;
    //    }
    //    result = atan(im / re) + M_PI;
    //}
}

string Complex::ToString() const{
    stringstream ss;

    ss << re;

    if (im != 0)
        ss << ((im > 0) ? " + " : " - ") << "i * " << fabs(im);

    return ss.str();
}

string Complex::ToStringTrig() {
    stringstream ss;

    double phi = Arg();

    ss << "cos(" << phi << ")" << " + i*sin(" << phi << ")";

    return ss.str();
}

string Complex::ToStringExp() {
    stringstream ss;

    double phi = Arg();
    double ro = Abs();

    ss << ro << "*e^" << ((phi > 0) ? "i*" : "-i*") << phi;

    return ss.str();
}

Complex Complex::Add(Complex z) {
    Complex res(re + z.GetRe(), im + z.GetIm());

    return res;
}

Complex Complex::Sub(Complex z) {
    Complex res(re - z.GetRe(), im + z.GetIm());

    return res;
}

Complex Complex::Mult(Complex z) {
    Complex res{
        re * z.re - im * z.im,
        re * z.im + im * z.re
    };

    return res;
}

Complex Complex::Div(Complex z) {
    Complex res{
        (re * z.re + im * z.im) / (z.re * z.re + z.im * z.im),
        (-re * z.im + im * z.re) / (z.re * z.re + z.im * z.im)
    };

    return res;
}